#include <iostream>
#include <string>
#include <tuple>
#include <regex>
#include <unordered_map>

#include <fstream>
#include "main.hpp"
std::tuple<std::string, int> askNA(){
    std::cout << "what is the name" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "what is the age" << std::endl;
    int age;
    std::cin >> age;
    return std::make_tuple(name, age);
}

bool emailexists(std::string email, std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line == email) {
                file.close();
                return true;
            }
        }
        file.close();
    return false;    
    } else {
        std::cout << "failed to open file \n" << std::endl;
    }

}
User::User(std::string name, int age) : name(name), age(age) {
}
void createUser(std::string name, int age){
    User name(name, age);
}
std::string askemail(){
    std::cout << "enter your email\n";
    std::string email;
    std::cin >> email;
    return email;
}

void User::createEP(std::string& email, std::string& pass) {
    if (isEmailValid(email) == true) {
    this->pass = pass;
    this->email = email;
    };
}
std::tuple<std::string, std::string> User::privInfo() {
    return std::make_tuple(email, pass);
}


User::User(std::string name, int age){
    this -> name = name;
    this -> age = age;
}

std::tuple<std::string, int> User::getNA(){
    return std::make_tuple(name, age);
};

void writeuserpass(std::string user, std::string pass){
    std::ofstream outfile;
    outfile.open("userpass.txt", std::ios_base::app);
    outfile << user << ":" << pass << "\n";
    outfile.close();
}
std::string askpass(){
    std::cout << "what is the password";
};
int choicecreate(){
    std::cout << "If you would like to make an account, enter 1, if not press 0\n";
    int num;
    std::cin >> num;
    return num;
}

void writeemail(std::string email){
    std::ofstream outfile;
    outfile.open("emails.txt", std::ios_base::app);
    outfile << email << "\n";
    outfile.close();
}

int selectOption(){
    int option;
    std::cout << "register - 1 \n login - 2";
    std::cin >> option;
    if (option == 1){
        std::tuple<std::string, std::string> credentials = askEP();
        User user("alexey2", 172);
        user.createEP(std::get<0>(credentials), std::get<1>(credentials));
    }else if (option == 2){
        return 0;
    }else {
        std::cout << "not valid, enter 1 or 2";
        return 1;
    };
    return 1;
}
    
bool isEmailValid(const std::string& email) {
    std::regex pattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");
    return std::regex_match(email, pattern);
};
std::tuple<std::string, std::string> askEP() {
    std::string email;
    std::string pass;
m:  std::cout << "What is the email? \n";
    std::cin >> email;
    while (isEmailValid(email) != true){
        goto m;
    };
    std::cout << "What is the pass? \n";
    std::cin >> pass;
    return std::make_tuple(email, pass);
};
