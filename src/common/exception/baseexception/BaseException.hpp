#ifndef IRIS_BASEEXCEPTION_HPP
#define IRIS_BASEEXCEPTION_HPP

#include <string>

class BaseException
{
    public:

        BaseException(const std::string& errorMessage = "")
        {
            _message = errorMessage;
        }

        virtual const std::string & errorMessage()
        {
            return _message;
        }

    protected:

        std::string _message;
};

#endif
