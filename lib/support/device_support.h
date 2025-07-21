#ifndef DEVICESUPPORT_H
#define DEVICESUPPORT_H

#include <string>

namespace support {
    class DeviceSupport {
        private:
            std::string raw_data;
        public:
            explicit DeviceSupport(std::string &raw);
            ~DeviceSupport() = default;

            [[nodiscard]] bool supportsThreeButtonController() const;
            [[nodiscard]] bool supportsSixButtonController() const;
            [[nodiscard]] bool supportMasterSystemController() const;
            [[nodiscard]] bool supportsAnalogJoystick() const;
            [[nodiscard]] bool supportsMultitap() const;
            [[nodiscard]] bool supportsLightGun() const;
            [[nodiscard]] bool supportsActivator() const;
            [[nodiscard]] bool supportsMouse() const;
            [[nodiscard]] bool supportsTrackball() const;
            [[nodiscard]] bool supportsTablet() const;
            [[nodiscard]] bool supportsPaddle() const;
            [[nodiscard]] bool supportsKeyboard() const;
            [[nodiscard]] bool supportsRS232() const;
            [[nodiscard]] bool supportsPrinter() const;
            [[nodiscard]] bool supportsCDROM() const;
            [[nodiscard]] bool supportsFloppyDrive() const;
            [[nodiscard]] bool supportsDownload() const;

            [[nodiscard]] std::string toString() const;
    };
}

#endif //DEVICESUPPORT_H
