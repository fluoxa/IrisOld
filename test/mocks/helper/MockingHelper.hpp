#ifndef IRIS_MOCKINGHELPER_HPP
#define IRIS_MOCKINGHELPER_HPP

#include <memory>

template <typename PointerType> class MockingHelper
{
    public:

        void storeUniquePointer(std::unique_ptr<PointerType>& ptr);

        template <typename SignatureType> std::unique_ptr<PointerType> getStoredPointer(SignatureType);

    private:

        std::unique_ptr<PointerType> _ptr;
};

#include <mocks/helper/MockingHelper_imp.hpp>

#endif