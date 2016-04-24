#ifndef AIUNIT_ENUMHELPER_HPP
#define AIUNIT_ENUMHELPER_HPP

#include <string>
#include <map>
#include <common/exception/baseexception/BaseException.hpp>

template <class T> class EnumHelper
{
    public:

        EnumHelper()
        {
            registerMap();
        }

        std::string toString(T enums)
        {
            try
            {
                return toStringMap.at(enums);
            }
            catch( const std::out_of_range &oor )
            {
                return "unknown";
            }
        }

        T toEnum(std::string enums)
        {
            for (auto it = toStringMap.begin(); it != toStringMap.end(); ++it )
                if ( enums.compare(it->second) == 0 )
                    return it->first;

	    //TODO: EXCEPTION ueberarbeiten
            throw BaseException();
        }

    private:

        void registerMap();

        std::map<T, std::string> toStringMap;
};

#include <utils/helper/enumhelper/EnumHelper_imp.hpp>

#endif //AIUNIT_ACTIVATIONFUNCTIONHELPER_HPP