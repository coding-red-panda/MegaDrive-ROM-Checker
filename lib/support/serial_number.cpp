#include <iomanip>
#include "serial_number.h"
#include "util.h"

namespace support {
    SerialNumber::SerialNumber(std::string& raw) {
        Util::trim(raw);

        this->softwareType = raw.substr(0, raw.find(' '));
        this->serialNumber = raw.substr(raw.find(' '), raw.find_last_of('-') - raw.find(' '));
        this->revision =  std::stoi(raw.substr(raw.find_last_of('-') + 1, raw.length() - raw.find_last_of('-') + 1));

        // Cleanup
        Util::trim(this->serialNumber);
    }

    std::string SerialNumber::getType() const {
        return this->softwareType;
    }

    std::string SerialNumber::getSerial() const {
        return this->serialNumber;
    }

    unsigned int SerialNumber::getRevision() const {
        return this->revision;
    }

    std::string SerialNumber::toString() const {
        std::stringstream ss;

        ss << this->softwareType << " "
           << this->serialNumber << " -"
           << std::setfill('0') << std::setw(2) << this->revision;

        return ss.str();
    }
} // support
