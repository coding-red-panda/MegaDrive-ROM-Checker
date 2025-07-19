//----------------------------------------------------------------------------------------------------------------------
// SerialNumber Class
// ==================
//
// This class handles the serial number information of a ROM image.
// The serial number information is typically found in the ROM header,
// at the address 0x110, and consists of 16 bytes, in the format: "(C)XXXX YYYY.ZZZ"
//
// - XX: 2 digits to indicate the software type
// - YYYYYYYY: The assigned serial by SEGA.
// - ZZ: The revision of the game.
//----------------------------------------------------------------------------------------------------------------------

#ifndef SERIALNUMBER_H
#define SERIALNUMBER_H

#include <algorithm>
#include <array>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Util.h"

namespace Support {
    class SerialNumber {
        private:
            std::string softwareType;
            std::string serialNumber;
            unsigned int revision;

        public:
            explicit SerialNumber(std::string& raw);
            ~SerialNumber() = default;

            [[nodiscard]] std::string getType() const;
            [[nodiscard]] std::string getSerial() const;
            [[nodiscard]] unsigned int getRevision() const;

            [[nodiscard]] std::string toString() const;
    };
} // Support

#endif //SERIALNUMBER_H
