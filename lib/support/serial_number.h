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
