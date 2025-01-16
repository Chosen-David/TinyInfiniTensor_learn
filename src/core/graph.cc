#include "core/graph.h"
#include"core/allocator.h"
#include "operators/transpose.h"
#include "operators/matmul.h"
#include "utils/operator_utils.h"
#include <algorithm>
#include <numeric>
#include <queue>
#include<iostream>


namespace infini
{

    void GraphObj::addOperatorAndConnect(const Operator &op)
    {
        sorted = false;
        ops.push_back(op);
        for (auto &input : op->getInputs())
        {
            if (input)
            {
                input->addTarget(op);
                if (auto pred = input->getSource())
                {
                    pred->addSuccessors(op);
                    op->addPredecessors(pred);
                }
            }
        }
        for (auto &output : op->getOutputs())
        {
            if (output)
            {
                output->setSource(op);
                for (auto &succ : output->getTargets())
                {
                    succ->addPredecessors(op);
                    op->addSuccessors(succ);
                }
            }
        }
    }

    string GraphObj::toString() const
    {
        std::ostringstream oss;
        oss << "Graph Tensors:\n";
        for (const auto &tensor : tensors)
            oss << tensor << "\n";

        oss << "Graph operators:\n";
        for (const auto &op : ops)
        {
            vector<UidBaseType> preds, succs;
            for (auto &o : op->getPredecessors())
                preds.emplace_back(o->getGuid());
            for (auto &o : op->getSuccessors())
                succs.emplace_back(o->getGuid());
            oss << "OP " << op->getGuid();
            oss << ", pred " << vecToString(preds);
            oss << ", succ " << vecToString(succs);
            oss << ", " << op << "\n";
        }
        return oss.str();
    }

    bool GraphObj::topo_sort()
    {
        if (this->sorted)
        {
            return true;
        }
        std::vector<Operator> sorted;
        std::unordered_set<OperatorObj *> flags;
        sorted.reserve(ops.size());
        flags.reserve(ops.size());
        while (sorted.size() < ops.size())
        {
            // Any node is move to sorted in this loop.
            auto modified = false;
            for (auto const &op : ops)
            {
                if (auto const &inputs = op->getInputs();
                    flags.find(op.get()) == flags.end() &&
                    std::all_of(inputs.begin(), inputs.end(),
                                [&flags](auto const &input)
                                {
                                    auto ptr = input->getSource().get();
                                    return !ptr || flags.find(ptr) != flags.end();
                                }))
                {
                    modified = true;
                    sorted.emplace_back(op);
                    flags.insert(op.get());
                }
            }
            if (!modified)
            {
                return false;
            }
        }
        this->ops = std::move(sorted);
        return this->sorted = true;
    }
    bool isInverse(std::vector<int>& p1, std::vector<int>& p2){
        if(p1.size()!=p2.size()){
            return false;
        }
        for(size_t i=0;i<p1.size();i++){
            if(static_cast<size_t>(p1[p2[i]])!=(i)){
                return false;
            }
        }
        return true;
    }
 
    
    void GraphObj::optimize()
    {
        // =================================== 作业 ===================================
        // TODO: 设计一个算法来实现指定的图优化规则
        // 图优化规则如下：
        // 1. 去除冗余的算子（例如，两个相邻的算子都是 transpose 算子，且做的是相反的操作，可以将其全部删除）
        // 2. 合并算子（例如，矩阵乘算子中含有属性transA、transB，如果其输入存在transpose，且对最后两个维度做交换，就可以将transpose融入到矩阵乘算子的属性中去）

        //1的实现
        OpVec toRemove;
        for (auto it = ops.begin(); it != ops.end();)
        {
            auto op = *it;
            int flag=0;
            
            
            if(op->getOpType()==OpType::Transpose){
                std::cout << "识别到转置" << std::endl;

                
                auto nextOp=op->getSuccessors()[0];
                auto inputTensor=op->getInputs()[0];
                auto nextInputTensor=op->getOutputs()[0];
                auto transposeOp = std::dynamic_pointer_cast<TransposeObj>(op);
                auto permute1 =transposeOp->getPermute();
               
                if(nextOp->getOpType()==OpType::Transpose){
                    std::cout << "识别到Next转置" << std::endl;
                    
                    auto nextNextOp=nextOp->getSuccessors()[0];
                    auto nextTransposeOp = std::dynamic_pointer_cast<TransposeObj>(nextOp);
                    
                    auto nextOutputTensor=nextOp->getOutputs()[0];
                    auto permute2=nextTransposeOp->getPermute();
                    if(isInverse(permute1,permute2)==1){
                        std::cout << "删除两个转置" << std::endl;
                        nextOp->removeSuccessors(nextNextOp);
                        op->removePredecessors(op->getPredecessors()[0]);
                        
                        this->removeTensor(nextInputTensor);
                        this->removeTensor(nextOutputTensor);
                        inputTensor->removeTarget(op);
                        inputTensor->addTarget(nextNextOp);
                        
                        
                        
                        
                        auto source = inputTensor->getSource();
                        if(source){
                            nextNextOp->addPredecessors(inputTensor->getSource());
                        }
                        
                        // std::cout << "ops大小删除前" <<ops.size()<< std::endl;
                        // std::cout << "开始者信息" <<nextNextOp->toString()<< std::endl;
                        // // std::cout << "开始者信息" <<nextNextOp->getSuccessors()[0]->toString()<< std::endl;
                        // std::cout << "开始者信息" <<nextNextOp->getPredecessors()[0]->toString()<< std::endl;
                        // std::cout << "开始者信息" <<nextNextOp->getPredecessors()[1]->toString()<< std::endl;
                        nextNextOp->removePredecessor(nextOp);
                        nextNextOp->replaceInput(nextOutputTensor,inputTensor);
                        
                                              
                        it=ops.erase(it);
                        it=ops.erase(it);
                        // std::cout << "ops大小删除后" <<ops.size()<< std::endl;
                        // std::cout << "幸存者信息" <<nextNextOp->toString()<< std::endl;
                        // // std::cout << "幸存者信息" <<nextNextOp->getSuccessors()[0]->toString()<< std::endl;
                        // std::cout << "幸存者信息" <<nextNextOp->getPredecessors()[0]->toString()<< std::endl;
                        flag=1;
                        
                    }
                    

                    
                    

                }
                
            }
            if(flag==0){
                it++;
            }
           
         
        }
      
        std::cout << "ops大小删除后" <<ops.size()<< std::endl;
        for (auto it = ops.begin(); it != ops.end();)
        {
            auto op = *it;
            int flag=0;


            if(op->getOpType()==OpType::MatMul){
                std::cout << "发现乘法" << std::endl;
                auto inputTensors =op->getInputs();
                auto A=inputTensors[0];
                auto B=inputTensors[1];
                auto A_s=A->getDims();
                auto B_s=B->getDims();
                auto outputTensor = op->getOutputs()[0];
                auto op_a=A->getSource();
                auto op_b=B->getSource();
                if(op_a&&op_a->getOpType()==OpType::Transpose){
                    std::cout << "发现A转置" << std::endl;
                    auto p_a=std::dynamic_pointer_cast<TransposeObj>(op)->getPermute();
                    size_t len_a=A_s.size();
                    auto op_mat=std::dynamic_pointer_cast<MatmulObj>(op);
                    if(len_a>=2&& static_cast<int>(len_a - 1) ==p_a[len_a-2] && static_cast<int>(len_a - 2)==p_a[len_a-1])
                    {
                        std::cout << "执行删除A" << std::endl;
                        op_mat->setTransA(op_mat->getTransA()==1?0:1);
                        auto A_prev=op_a->getInputs()[0];
                        A_prev->removeTarget(op_a);
                        A_prev->addTarget(op);
                        auto source=A_prev->getSource();
                        if(source){
                            op->addPredecessors(A_prev->getSource());
                        }
                        op->removePredecessors(op_a);

                        
                

                        this->removeOperator(op_a);
                        op->replaceInput(A,A_prev);
                        it=ops.erase(std::find(ops.begin(), ops.end(), op_a));
                        
                        
                        this->removeTensor(A);  
                        flag=1;

                    }

                }
                if (op_b&&op_b->getOpType() == OpType::Transpose)
                {
                    std::cout << "发现B转置" << std::endl;
                    auto p_b = std::dynamic_pointer_cast<TransposeObj>(op_b)->getPermute();
                    size_t len_b = B_s.size();
                    auto op_mat = std::dynamic_pointer_cast<MatmulObj>(op);
                    
                    
                    if (len_b >= 2 && static_cast<int>(len_b - 1) == p_b[len_b - 2] && static_cast<int>(len_b - 2) == p_b[len_b - 1])
                    {
                        std::cout << "执行删除B" << std::endl;
                        op_mat->setTransB(op_mat->getTransB() == 1 ? 0 : 1);
                        auto B_prev = op_b->getInputs()[0];
                        

            
                        B_prev->removeTarget(op_b);
                        B_prev->addTarget(op);
                        op->removePredecessors(op_b);
                        auto source=B_prev->getSource();
                        if(source){
                            op->addPredecessors(B_prev->getSource());
                        }
                        std::cout << "开始者信息" <<op_b->toString()<< std::endl;

                        this->removeTensor(B);
                        op->replaceInput(B,B_prev);
                        it=ops.erase(std::find(ops.begin(), ops.end(), op_b));
                        
                        std::cout << "幸存者信息" <<op->toString()<< std::endl;
                        
                        flag=1;
                    }
                }
            }
            if(flag==0){
                it++;
            }
        }
    
       


        // =================================== 作业 ===================================
    }
   

    Tensor GraphObj::getTensor(int fuid) const
    {
        for (auto tensor : tensors)
        {
            if (tensor->getFuid() == fuid)
            {
                return tensor;
            }
        }
        return nullptr;
    }

    void GraphObj::shape_infer()
    {
        for (auto &op : ops)
        {
            auto ans = op->inferShape();
            IT_ASSERT(ans.has_value());
            auto oldOutputs = op->getOutputs();
            IT_ASSERT(ans.value().size() == oldOutputs.size());
            // replace the old outputshape and size with new one
            for (int i = 0; i < (int)ans.value().size(); ++i)
            {
                auto newShape = ans.value()[i];
                auto oldShape = oldOutputs[i]->getDims();
                auto fuid = oldOutputs[i]->getFuid();
                if (newShape != oldShape)
                {
                    auto tensor = this->getTensor(fuid);
                    tensor->setShape(newShape);
                }
            }
        }
    }

    void GraphObj::dataMalloc()
    {
        // topological sorting first
        IT_ASSERT(topo_sort() == true);
        std::unordered_map<int,size_t> tensorAllocations;
        size_t sum_size=0;

        // =================================== 作业 ===================================
        // TODO：利用 allocator 给计算图分配内存
        // std::cout << "大小:::"<<tensors.size() <<std::endl;
        // std::cout << "================================" <<std::endl;

        for(auto &tensor:tensors){
            
            size_t tensorSize=tensor->getBytes();
            sum_size+=tensorSize;

            // std::cout << "开始分配" <<std::endl;

           
            // std::cout << "分配成功，开始指针" <<std::endl;
            // void* RawPtr=allocator.getPtr();
            // void* ptr = static_cast<void*>(static_cast<char*>(allocator.getPtr()) + offset);
            void*ptr=runtime->alloc(tensorSize);
            // void* ptr = reinterpret_cast<void*>(offset);
           
            
       

            
            
            
            // // void* rawPtr = static_cast<void*>(static_cast<char*>(allocator.getPtr()) + offset);
            // // void* memoryPtr=static_cast<size_t*>(allocator.getPtr())+offset;
            std::cout << "Allocating tensor: " << tensor->getFuid()   
              << ", size: " << tensorSize
            //   << ", offset: " << offset
              << ", ptr: " << ptr 
            //   << ", RawPtr: " << RawPtr 
              << std::endl;
            
    
        
            // // std::cout <<"释放后 ptr: " << ptr << std::endl;
            
            Blob blob = std::make_shared<BlobObj>(tensor->getRuntime(), ptr);
            std::cout << "绑定成功！" <<std::endl;

           
            
            

            // // // // // Set Blob to the tensor
            tensor->setDataBlob(blob);
          
            std::cout <<"tensor: " << tensor->toString() << std::endl;
           
            // // // 


            // // // tensor->setDataBlob(memoryPtr);
            // tensorAllocations[tensor->getFuid()]=offset;
      

        }
        size_t offset=allocator.alloc(sum_size);

        // HINT: 获取分配好的内存指针后，可以调用 tensor 的 setDataBlob 函数给 tensor 绑定内存
        // =================================== 作业 ===================================

        allocator.info();
        
        
    }

    Tensor GraphObj::addTensor(Shape dim, DataType dtype)
    {
        return tensors.emplace_back(make_ref<TensorObj>(dim, dtype, runtime));
    }

    Tensor GraphObj::addTensor(const Tensor &tensor)
    {
        IT_ASSERT(tensor->getRuntime() == runtime,
                  std::string("Tensor runtime mismatch: cannot add a tenosr in ") +
                      tensor->getRuntime()->toString() + " to " +
                      runtime->toString());
        tensors.emplace_back(tensor);
        return tensor;
    }

    TensorVec GraphObj::addTensor(const TensorVec &tensors)
    {
        for (auto &t : tensors)
            addTensor(t);
        return tensors;
    }

    // tensor's "source" and "target" must be in "ops".
    // tensor has no "source" and no "target" must not exist.
    // "inputs" or "outputs" of operators must be in "tensors"
    // "predecessors" and "successors" of an operator of "ops" must be in "ops".
    bool GraphObj::checkValid() const
    {
        for (auto tensor : tensors)
        {
            IT_ASSERT(!(tensor->getTargets().size() == 0 &&
                        nullptr == tensor->getSource()));
            for (auto op : tensor->getTargets())
            {
                IT_ASSERT(std::find(ops.begin(), ops.end(), op) != ops.end());
            }
            auto op = tensor->getSource();
            IT_ASSERT(!(op && std::find(ops.begin(), ops.end(), op) == ops.end()));
        }
        for (auto op : ops)
        {
            for (auto tensor : op->getInputs())
            {
                IT_ASSERT(std::find(tensors.begin(), tensors.end(), tensor) !=
                          tensors.end());
            }
            for (auto tensor : op->getOutputs())
            {
                IT_ASSERT(std::find(tensors.begin(), tensors.end(), tensor) !=
                          tensors.end());
            }
            for (auto pre : op->getPredecessors())
            {
                IT_ASSERT(std::find(ops.begin(), ops.end(), pre) != ops.end());
            }
            for (auto suc : op->getSuccessors())
            {
                IT_ASSERT(std::find(ops.begin(), ops.end(), suc) != ops.end());
            }
        }
        std::set<UidBaseType> s;
        // check whether two tensors with the same FUID exist
        for (auto tensor : tensors)
        {
            int cnt = s.count(tensor->getFuid());
            IT_ASSERT(cnt == 0, std::to_string(tensor->getFuid()));
            s.insert(tensor->getFuid());
        }
        return true;
    }

} // namespace infini