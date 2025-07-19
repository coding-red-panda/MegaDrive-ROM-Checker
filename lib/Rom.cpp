#include "Rom.h"

Rom::Rom(std::string path) : path(std::move(path)) { }

std::string Rom::getSystemType() const {
    return extractString(SYSTEM_TYPE_ADDRESS, 16);
}

Support::Copyright Rom::getCopyright() const {
    std::string copyrightString = extractString(COPYRIGHT_ADDRESS, 16);

    copyrightString.erase(copyrightString.find_first_of("(C)"), 3); // Remove the "(C)" prefix

    // Construct the Copyright object from the string
    std::string publisher = copyrightString.substr(0, 4);
    unsigned int year = std::stoi(copyrightString.substr(5, 4));
    std::string month = copyrightString.substr(10, 3);

    // Erase whitespace from publisher and month
    std::erase_if(publisher, ::isspace);
    std::erase_if(month, ::isspace);

    return {publisher, year, month};
}

std::string Rom::extractString(int address, size_t length) const {
    std::ifstream ifs(path);

    if (!ifs.is_open()) { throw std::runtime_error("Failed to open ROM file: " + path); }

    // Read the required bytes from the ROM header into our buffer
    ifs.seekg(address);
    char buffer[length];
    ifs.read(buffer, sizeof(buffer));
    ifs.close();

    // Convert to string and trim whitespace
    std::string string(buffer, sizeof(buffer));
    string.erase(string.find_last_not_of(" \n\r\t") + 1);

    return string;
}
