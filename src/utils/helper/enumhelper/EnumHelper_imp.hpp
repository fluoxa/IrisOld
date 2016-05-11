#include <definitions/enums/repository/Repository.hpp>
#include <utils/helper/enumhelper/EnumHelper.hpp>

template <> inline void
EnumHelper<Repository>::registerMap()
{
    toStringMap.insert(std::pair<Repository , std::string>(Repository::Default, "default"));
    toStringMap.insert(std::pair<Repository , std::string>(Repository::Xml, "xml"));
}
