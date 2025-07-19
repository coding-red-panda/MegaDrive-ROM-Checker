#include "Util.h"

namespace Support {
    void Util::trim(std::string &str) {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(" \n\r\t") + 1);
        str.erase(std::unique(
            str.begin(),
            str.end(),
            [](const char a, const char b) { return a == ' ' && b == ' '; } ), str.end()
        );
    }
} // Support
