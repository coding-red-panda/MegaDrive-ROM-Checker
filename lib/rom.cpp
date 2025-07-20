#include <fstream>
#include <stdexcept>
#include "rom.h"
#include "support/util.h"

Rom::Rom(std::string path) : path(std::move(path)) { }

std::string Rom::getSystemType() const {
    return extractString(SYSTEM_TYPE_ADDRESS, 16);
}

support::Copyright Rom::getCopyright() const {
    std::string copyrightString = extractString(COPYRIGHT_ADDRESS, 16);

    copyrightString.erase(copyrightString.find_first_of("(C)"), 3); // Remove the "(C)" prefix

    // Construct the Copyright object from the string,
    // read from the back to account for special characters in the Publisher.
    std::string month = copyrightString.substr(copyrightString.length() - 3, 3);
    unsigned int year = std::stoi(copyrightString.substr(copyrightString.length() - 8, 4));
    std::string publisher = copyrightString.substr(0, copyrightString.length() - 8);

    // Erase whitespace from publisher and month
    std::erase_if(publisher, ::isspace);
    std::erase_if(month, ::isspace);

    // Erase special characters from Publisher
    std::erase_if(publisher, [](const char x) { return x == '_'; });

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
    support::Util::trim(string);

    return string;
}

std::string Rom::getDomesticTitle() const {
    return extractString(DOMESTIC_TITLE_ADDRESS, TITLE_LENGTH);
}

std::string Rom::getOverseasTitle() const {
    return extractString(OVERSEAS_TITLE_ADDRESS, TITLE_LENGTH);
}

support::SerialNumber Rom::getSerialNumber() const {
    std::string raw = extractString(SERIAL_NUMBER_ADDRESS, SERIAL_LENGTH);

    return support::SerialNumber {raw };
}