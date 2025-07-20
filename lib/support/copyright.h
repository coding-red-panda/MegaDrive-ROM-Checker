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
