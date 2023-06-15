#include <iostream>
#include <string>
#include <tuple>
#include "main.hpp"


int main() {

    std::string email = askemail();
    writeemail(email);
    std::tuple<std::string, std::string> credentials = askEP();
    std::tuple<std::string, int> info = askNA();
    //user1.createEP(std::get<0>(credentials), std::get<1>(credentials));
    //writeuserpass(std::get<0>(user1.getNA()), std::get<0>(user1.privInfo()));
    return 0;

}
