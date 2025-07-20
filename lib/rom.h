#ifndef ROM_H
#define ROM_H

#include "support/copyright.h"
#include "support/serial_number.h"

class Rom {
private:
    std::string path;

    [[nodiscard]] std::string extractString(int address, size_t length) const;

public:
    explicit Rom(std::string path);
    ~Rom() = default;

    [[nodiscard]] std::string getSystemType() const;
    [[nodiscard]] support::Copyright getCopyright() const;
    [[nodiscard]] std::string getDomesticTitle() const;
    [[nodiscard]] std::string getOverseasTitle() const;
    [[nodiscard]] support::SerialNumber getSerialNumber() const;
    [[nodiscard]] unsigned short getChecksum() const;
    [[nodiscard]] unsigned short calculateChecksum() const;
};

#endif //ROM_H
