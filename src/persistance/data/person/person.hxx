// file      : query/person.hxx
// copyright : not copyrighted - public domain

#ifndef PERSON_HXX
#define PERSON_HXX

#include <string>

#include <odb/core.hxx>
#include <odb/nullable.hxx>

#pragma db object
class person
{
public:
  person (const std::string& name,
          unsigned short age)
      : name_ (name), age_ (age)
  {
  }

  const std::string&
  name () const
  {
    return name_;
  }

  unsigned short
  age () const
  {
    return age_;
  }

private:
  friend class odb::access;

  person () {}

  #pragma db id auto
  unsigned long id_;

  std::string name_;
  unsigned short age_;
};

#endif // PERSON_HXX
