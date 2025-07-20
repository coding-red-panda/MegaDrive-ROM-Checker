//----------------------------------------------------------------------------------------------------------------------
// Copyright Class
// ===============
//
// This class handles the copyright information of a ROM image.
// The copyright information is typically found in the ROM header,
// at the address 0x110, and consists of 16 bytes, in the format: "(C)XXXX YYYY.ZZZ"
//
// - XXXX: four character abbreviation of the publisher.
// - YYYY: four digits of the year the game was released.
// - ZZZ: three character abbreviation of the month the game was released.
//----------------------------------------------------------------------------------------------------------------------
#ifndef COPYRIGHT_H
#define COPYRIGHT_H

#include <string>

namespace support {
    class Copyright {
        private:
            std::string publisher;
            unsigned int year;
            std::string month;
        public:
            Copyright(std::string publisher, unsigned int year, std::string month);
            ~Copyright() = default;

            [[nodiscard]] std::string getPublisher() const;
            [[nodiscard]] unsigned int getYear() const;
            [[nodiscard]] std::string getMonth() const;
            [[nodiscard]] std::string toString() const;
    };
} // support

#endif //COPYRIGHT_H
