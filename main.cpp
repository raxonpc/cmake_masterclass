#include "greeter/greeter.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if(argc > 1) {
        std::cout << greeter::greetings(argv[1]) << '\n';
    }

    return 0;
}
