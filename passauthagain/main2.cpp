#include <iostream>
#include <vector>
#include <string>
#include <fstream>
class User {
public:
    std::string name;
    int age;

    User(const std::string& username, int& userAge);

    void createEP(const std::string& email, const std::string& pass);

    std::tuple<std::string, std::string> privInfo(); 

private:
    std::string pass;
    std::string email;
};

void write(std::string user, std::string pass){
    std::ofstream outfile;
    outfile.open("userpass.txt", std::ios_base::app);
    outfile << user << ":" << pass << "\n";
    outfile.close();
}
int selectOption(){
    int option;
    std::cout << "register - 1 \n login - 2";
    std::cin >> option;
    if (option == 1){
        std::tuple<std::string, std::string> credentials = askEP();
        createEP(std::get<0>(credentials), std::get<1>(credentials));
    }else if (option == 2){
        return 0;
    }else {
        std::cout << "not valid, enter 1 or 2";
        return 1;
    };
    return 1;
}
    
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
