#include "operators/matmul.h"
#include "utils/operator_utils.h"

namespace infini
{

    MatmulObj::MatmulObj(GraphObj *graph, Tensor A, Tensor B, Tensor C, bool transA,
                         bool transB)
        : OperatorObj(OpType::MatMul, TensorVec{A, B}, {C}),
          transA(transA), transB(transB)
    {
        IT_ASSERT(checkValid(graph));
    }

    string MatmulObj::toString() const
    {
        std::ostringstream os;
        os << "Matmul([" << (transA ? "A^T" : "A") << "," << (transB ? "B^T" : "B]")
           << ",A=" << inputs[0]->getGuid()
           << ",B=" << inputs[1]->getGuid() << ",C=" << outputs[0]->getGuid()
           << ",mnk=[" << m << "," << n << "," << k << "])";
        return os.str();
    }

    optional<vector<Shape>> MatmulObj::inferShape(const TensorVec &inputs)
    {
        // =================================== 作业 ===================================
        // TODO：返回经过 matmul 操作后的 shape
        // REF: https://github.com/onnx/onnx/blob/main/docs/Operators.md#gemm
        Tensor A=inputs[0];
        Tensor B=inputs[1];
        vector<Shape> res_o;
        

        
        Shape A_dims=A->getDims();
        Shape B_dims=B->getDims();
        
        size_t len_a=A_dims.size();
        size_t len_b=B_dims.size();
        if(transA&&len_a>=2){
            std::swap(A_dims[len_a-1],A_dims[len_a-2]);

        }
        if(transB&&len_b>=2){
            std::swap(B_dims[len_b-1],B_dims[len_b-2]);

        }
     
        size_t max_len=std::max(len_a,len_b);
        Shape res=infer_broadcast(A_dims,B_dims);
        if(max_len>1){
            res[max_len-1]=B_dims[len_b-1];
            res[max_len-2]=A_dims[len_a-2];
        }
        
        
        
        
        res_o.push_back(res);



        // =================================== 作业 ===================================
        return res_o;
    }

} // namespace infini