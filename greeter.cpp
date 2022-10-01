#include "greeter.hpp"

#include <iostream>

std::string greetings(const std::string& name)
{
    return { "Good morning, " + name  + "!" };
}