#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "support/addresses.h"
#include "rom.h"
#include "support/util.h"

Rom::Rom(std::string path) : path(std::move(path)) { }

std::string Rom::getSystemType() const {
    return extractString(support::Addresses::SYSTEM_TYPE, 16);
}

support::Copyright Rom::getCopyright() const {
    std::string copyrightString = extractString(support::Addresses::COPYRIGHT, 16);

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
    char buffer[length];

    ifs.seekg(address);
    ifs.read(buffer, length);
    ifs.close();

    // Convert to string and trim whitespace
    std::string string(buffer, length);
    support::Util::trim(string);

    return string;
}

std::string Rom::getDomesticTitle() const {
    return extractString(support::Addresses::DOMESTIC_TITLE, support::Addresses::TITLE_LENGTH);
}

std::string Rom::getOverseasTitle() const {
    return extractString(support::Addresses::OVERSEAS_TITLE, support::Addresses::TITLE_LENGTH);
}

support::SerialNumber Rom::getSerialNumber() const {
    std::string raw = extractString(support::Addresses::SERIAL_NUMBER, support::Addresses::SERIAL_LENGTH);

    return support::SerialNumber {raw };
}

unsigned short Rom::getChecksum() const {
    std::ifstream ifs(path);

    if (!ifs.is_open()) { throw std::runtime_error("Failed to open ROM file: " + path); }

    // Read the required bytes from the ROM header into our buffer
    char buffer[support::Addresses::CHECKSUM_LENGTH];

    ifs.seekg(support::Addresses::CHECKSUM);
    ifs.read(buffer, support::Addresses::CHECKSUM_LENGTH);
    ifs.close();

    // Convert the read bytes into an unsigned short (16 bit)
    return static_cast<unsigned short>(buffer[0]) << 8 | static_cast<unsigned char>(buffer[1]);
}

unsigned short Rom::calculateChecksum() const {
    std::ifstream ifs(path, std::ios::binary);
    std::uint16_t checksum = 0;

    if (!ifs.is_open()) { throw std::runtime_error("Failed to open ROM file: " + path); }

    // Set the stream to the beginning of the ROM data so we can calculate the checksum.
    // The checksum is calculated from the data by reading every 16-bit word (unsigned short)
    // and summing them up, then taking the lower 16 bits of the result.
    ifs.seekg(support::Addresses::ROM_DATA);

    while (!ifs.eof()) {
        std::vector<std::byte> buffer(support::Addresses::CHECKSUM_LENGTH);

        ifs.read(reinterpret_cast<char*>(buffer.data()), support::Addresses::CHECKSUM_LENGTH);

        // Convert the read bytes into an unsigned short (16 bit)
        // The order needs to be swapped to respect the endian-ness of the ROM.
        const unsigned short word = static_cast<unsigned short>(buffer[0]) << 8 | static_cast<unsigned char>(buffer[1]);
        checksum += word;
    }

    // Always close the file stream after reading.
    ifs.close();

    // Return the lower 16 bits of the checksum as per the ROM specification.
    const unsigned short lower_checksum = checksum & 0xFFFF;

    return lower_checksum;
}

support::DeviceSupport Rom::getDeviceSupport() const {
    std::string raw_data = extractString(support::Addresses::DEVICE_SUPPORT, support::Addresses::DWORD_LENGTH);

    return support::DeviceSupport(raw_data);
}
