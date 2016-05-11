#ifndef IRIS_PERSON_HPP
#define IRIS_PERSON_HPP

#include <string>

class Person
{
    public:

        std::string name;
        int age;

        std::string getGreetings()
        {
            return "Hallo! Ich bin " + name + " und " + std::to_string(age) + " Jahre alt.";
        }
};

#endif //IRIS_PERSON_HPP
