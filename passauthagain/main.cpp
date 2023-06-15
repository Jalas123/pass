#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include "main.hpp"


int main() {
    
    std::string email = askemail();
    if (emailexists(email, "emails.txt")){
        std::cout << "you already have an account, press 1 if you'd like to login, and 0 for no: ";
        int num;
        std::cin >> num;
        if (num == 1){
            
        } else {

        };
    } else {
        auto nameage = askNA();
        createUser(std::get<0>(nameage), std::get<1>(nameage));
    }
    writeemail(email);
    std::tuple<std::string, int> info = askNA();
    //user1.createEP(std::get<0>(credentials), std::get<1>(credentials));
    //writeuserpass(std::get<0>(user1.getNA()), std::get<0>(user1.privInfo()));
    return 0;

}
