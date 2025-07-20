//----------------------------------------------------------------------------------------------------------------------
// Rom.h
//
// Created by Coding Red panda
//
// This class represents the actual ROM image on disc/cartridge and acts as a general class to open and read
// the ROM image. It is not specific to any particular ROM format, but attempts to follow the official ROM documentation
// for the system it is emulating, as it was designed by SEGA.
//
// ROM Header
// ==========
// 0x000 - 0x100: Motorola 68000 vectors
// 0x100: System Type (16 bytes)
// 0x110: Copyright and release date (16 bytes)
// 0x120: Game Title - domestic (48 bytes)
// 0x150: Game Title - international (48 bytes)
// 0x180: Serial Number (14 bytes)
// 0x18E: Checksum (2 bytes)
// 0x190: Device Support (16 bytes)
// 0x1A0: ROM address range (8 bytes)
// 0x1A8: RAM address range (8 bytes)
// 0x1B0: Extra memory (12 bytes)
// 0x1BC: Modem Support (12 bytes)
// 0x1C8: Reserved (40 bytes)
// 0x1F0: Region Code (3 bytes)
// 0x1F3: Reserved (13 bytes)
//----------------------------------------------------------------------------------------------------------------------
#ifndef ROM_H
#define ROM_H

#include "support/copyright.h"
#include "support/serial_number.h"

class Rom {
private:
    std::string path;
    static constexpr int SYSTEM_TYPE_ADDRESS = 0x100;
    static constexpr int COPYRIGHT_ADDRESS = 0x110;
    static constexpr int DOMESTIC_TITLE_ADDRESS = 0x120;
    static constexpr int OVERSEAS_TITLE_ADDRESS = 0x150;
    static constexpr int SERIAL_NUMBER_ADDRESS = 0x180;

    static constexpr int TITLE_LENGTH = 48;
    static constexpr int DWORD_LENGTH = 16;
    static constexpr int SERIAL_LENGTH = 14;
    static constexpr int EXTRA_LENGTH = 12;
    static constexpr int RANGE_LENGTH = 8;
    static constexpr int REGION_LENGTH = 3;
    static constexpr int CHECKSUM_LENGTH = 2;

    static constexpr int FIRST_PADDING_LENGTH = 40;
    static constexpr int SECOND_PADDING_LENGTH = 13;

    [[nodiscard]] std::string extractString(int address, size_t length) const;

public:
    explicit Rom(std::string path);
    ~Rom() = default;

    [[nodiscard]] std::string getSystemType() const;
    [[nodiscard]] support::Copyright getCopyright() const;
    [[nodiscard]] std::string getDomesticTitle() const;
    [[nodiscard]] std::string getOverseasTitle() const;
    [[nodiscard]] support::SerialNumber getSerialNumber() const;
};

#endif //ROM_H
