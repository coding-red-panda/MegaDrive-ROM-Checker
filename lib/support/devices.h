#ifndef DEVICES_H
#define DEVICES_H

namespace support {
    class Devices {
        public:
            static constexpr char THREE_BUTTON_CONTROLLER = 'J';
            static constexpr char SIX_BUTTON_CONTROLLER = '6';
            static constexpr char MASTER_SYSTEM_CONTROLLER = '0';
            static constexpr char ANALOG_JOYSTICK = 'A';
            static constexpr char MULTITAP = '4';
            static constexpr char LIGHT_GUN = 'G';
            static constexpr char ACTIVATOR = 'L';
            static constexpr char MOUSE = 'M';
            static constexpr char TRACKBALL = 'B';
            static constexpr char TABLET = 'T';
            static constexpr char PADDLE = 'V';
            static constexpr char KEYBOARD = 'K';
            static constexpr char RS232 = 'R';
            static constexpr char PRINTER = 'P';
            static constexpr char CDROM = 'C';
            static constexpr char FLOPPY_DRIVE = 'F';
            static constexpr char DOWNLOAD = 'D';
    };
}

#endif //DEVICES_H
