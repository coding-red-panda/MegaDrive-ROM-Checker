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

#ifndef SERIAL_NUMBER_H
#define SERIAL_NUMBER_H

#include <string>

namespace support {
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
} // support

#endif //SERIAL_NUMBER_H
