#include <mocks/helper/MockingHelper.hpp>

template <typename PointerType> void
MockingHelper<PointerType>::storeUniquePointer(std::unique_ptr<PointerType> & ptr)
{
    _ptr = std::move(ptr);
}

template <typename PointerType> template<typename SignatureType> std::unique_ptr<PointerType>
MockingHelper<PointerType>::getStoredPointer(SignatureType obj)
{
    return std::move(_ptr);
}