#include "greeter/greeter.hpp"
#include <fmt/core.h>

std::string greeter::greetings(const std::string& name)
{
    fmt::format("Good morning, {}!", name);
    return { "Good morning, " + name  + "!" };
}