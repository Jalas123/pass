#include "test.hpp"
#include <iostream>
User::User(std::string name, int age){
    this -> name = name;
    this -> age = age;
}
int main(){
    User user("alexey", 17);
    std::cout << std::get<1>(user.getInfo());
}



