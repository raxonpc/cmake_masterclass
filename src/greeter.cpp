#include "greeter/greeter.hpp"

std::string greeter::greetings(const std::string& name)
{
    return { "Good morning, " + name  + "!" };
}