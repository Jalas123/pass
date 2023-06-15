
#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <tuple>
#include <string>

class User {
public:
    User(std::string name, int age);
    std::tuple<std::string, int> getInfo(){
        return std::make_tuple(name, age);
    };
private:
    std::string name;
    int age;

};


#endif