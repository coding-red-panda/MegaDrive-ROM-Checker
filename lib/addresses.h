#ifndef ADDRESSES_H
#define ADDRESSES_H

struct Addresses {
    static constexpr int SYSTEM_TYPE = 0x100;
    static constexpr int COPYRIGHT = 0x110;
    static constexpr int DOMESTIC_TITLE = 0x120;
    static constexpr int OVERSEAS_TITLE = 0x150;
    static constexpr int SERIAL_NUMBER = 0x180;
    static constexpr int CHECKSUM = 0x18E;
    static constexpr int ROM_DATA = 0x200;

    static constexpr int TITLE_LENGTH = 48;
    static constexpr int DWORD_LENGTH = 16;
    static constexpr int SERIAL_LENGTH = 14;
    static constexpr int EXTRA_LENGTH = 12;
    static constexpr int RANGE_LENGTH = 8;
    static constexpr int REGION_LENGTH = 3;
    static constexpr int CHECKSUM_LENGTH = 2;

    static constexpr int FIRST_PADDING_LENGTH = 40;
    static constexpr int SECOND_PADDING_LENGTH = 13;
};

#endif //ADDRESSES_H
