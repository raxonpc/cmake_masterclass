#pragma once

#include <string>
#include "greeter/config.hpp"

namespace greeter {
    GREETER_API std::string greetings(const std::string& name);
}
