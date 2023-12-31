// main.hpp
#include <tuple>
#ifndef MYHEADER_H
#define MYHEADER_H

#include <string>
#include <tuple>
bool emailexists(std::string email, std::string filename);
void writeuserpass(std::string user, std::string pass);
std::string askpass();
int choicecreate();
bool isEmailValid(const std::string& email);
std::tuple<std::string, std::string> askEP();
std::string askemail();
int selectOption();
void createUser(std::string name, int age);
void writeemail(std::string email);
std::tuple<std::string, int> askNA();
class User {
public:
    User(std::string name, int age);
    std::tuple<std::string, int> getNA();
    void createEP(std::string& email, std::string& pass);

    std::tuple<std::string, std::string> privInfo(); 

private:
    std::string name;
    int age;
    std::string pass;
    std::string email;
};



#endif
