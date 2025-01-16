#include "core/allocator.h"
#include <utility>

namespace infini
{
    Allocator::Allocator(Runtime runtime) : runtime(runtime)
    {
        used = 0;
        peak = 0;
        ptr = nullptr;

        // 'alignment' defaults to sizeof(uint64_t), because it is the length of
        // the longest data type currently supported by the DataType field of
        // the tensor
        alignment = sizeof(uint64_t);
        //自己加的：
        size_t memoryPoolSize = 1024 * 1024; // 1MB
        freeBlocks[0] = memoryPoolSize;     // 将整个内存池作为一个空闲块
        std::cout << "Allocator 创建" << std::endl;
    }

    Allocator::~Allocator()
    {
        std::cout << "开始析构" << std::endl;
        if (this->ptr != nullptr)
        {
            runtime->dealloc(this->ptr);
           
        }
         std::cout << "Allocator destroyed" << std::endl;
        
    }
    size_t Allocator::getUsedMemory(){
        return used;

    }

    size_t Allocator::alloc(size_t size)
    {
        IT_ASSERT(this->ptr == nullptr);
        // pad the size to the multiple of alignment
        if(this->ptr == nullptr){
            printf("开始是空指针\n");

        }
        size = this->getAlignedSize(size);

        // =================================== 作业 ===================================
        // TODO: 设计一个算法来分配内存，返回起始地址偏移量
        for(auto it=freeBlocks.begin(); it!=freeBlocks.end();it++){
            size_t addr=it->first;
            if(it->second>=size){
                
                freeBlocks[addr+size]=it->second-size;
                freeBlocks.erase(it);
                used+=size;
                peak=std::max(peak,used);
                return addr;

            }
        }
        
        // =================================== 作业 ===================================
        return 0;

    }
     void*Allocator::getBasePtr() {
        return ptr;
    }
    
    

    void Allocator::free(size_t addr, size_t size)
    {
        //IT_ASSERT(this->ptr == nullptr);
        size = getAlignedSize(size);

        // =================================== 作业 ===================================
        // TODO: 设计一个算法来回收内存
        freeBlocks[addr]=size;
        
        auto it=freeBlocks.find(addr);
        if(it->second>=size){
            auto next=std::next(it);
            if(next!=freeBlocks.end() && it->first+it->second>=next->first){
                it->second=next->second+next->first-addr;
                freeBlocks.erase(next);
                used-=next->first-addr;
                peak=std::max(peak,used);
            }
            else{
                used-=size;
                peak=std::max(peak,used);
            }

        }
        if(it!=freeBlocks.begin()){
            auto prev=std::prev(it);
            if(prev!=freeBlocks.begin() && prev->first+prev->second==addr){
                prev->second+=freeBlocks[addr];
                freeBlocks.erase(it);
            }
          

        }



        // =================================== 作业 ===================================
    }

    void *Allocator::getPtr()
    {
        if (this->ptr == nullptr)
        {
            this->ptr = runtime->alloc(this->peak);
            printf("Allocator really alloc: %p %lu bytes\n", this->ptr, peak);
        }
        return this->ptr;
    }

    size_t Allocator::getAlignedSize(size_t size)
    {
        return ((size - 1) / this->alignment + 1) * this->alignment;
    }

    void Allocator::info()
    {
        std::cout << "Used memory: " << this->used
                  << ", peak memory: " << this->peak << std::endl;
    }
}
