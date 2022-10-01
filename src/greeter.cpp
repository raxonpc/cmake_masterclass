#include "greeter/greeter.hpp"

std::string greetings(const std::string& name)
{
    return { "Good morning, " + name  + "!" };
}