#include<optional>
#include<iostream>

int main(int argc, char **argv) {

    std::optional<std::string> argument;
    if (argc > 1) argument = argv[1];
    
    if(argument) {
        std::cout << "Argument has value: " << argument.value() << '\n';    
    }else {
        std::cout << "No argument value passed: \n";    
    }

    if (argument == "hello") {
        std::cout << "Check if argument is hello TRUE\n";    
    }
}
