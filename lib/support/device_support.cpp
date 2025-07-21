#include "device_support.h"
#include "devices.h"

namespace support {
    DeviceSupport::DeviceSupport(std::string &raw) : raw_data(std::move(raw)) {}

    bool DeviceSupport::supportsThreeButtonController() const {
        return this->raw_data.find(Devices::THREE_BUTTON_CONTROLLER) != std::string::npos;
    }

    bool DeviceSupport::supportsSixButtonController() const {
        return this->raw_data.find(Devices::SIX_BUTTON_CONTROLLER) != std::string::npos;
    }

    bool DeviceSupport::supportMasterSystemController() const {
        return this->raw_data.find(Devices::MASTER_SYSTEM_CONTROLLER) != std::string::npos;
    }

    bool DeviceSupport::supportsAnalogJoystick() const {
        return this->raw_data.find(Devices::ANALOG_JOYSTICK) != std::string::npos;
    }

    bool DeviceSupport::supportsMultitap() const {
        return this->raw_data.find(Devices::MULTITAP) != std::string::npos;
    }

    bool DeviceSupport::supportsLightGun() const {
        return this->raw_data.find(Devices::LIGHT_GUN) != std::string::npos;
    }

    bool DeviceSupport::supportsActivator() const {
        return this->raw_data.find(Devices::ACTIVATOR) != std::string::npos;
    }

    bool DeviceSupport::supportsMouse() const {
        return this->raw_data.find(Devices::MOUSE) != std::string::npos;
    }

    bool DeviceSupport::supportsTrackball() const {
        return this->raw_data.find(Devices::TRACKBALL) != std::string::npos;
    }

    bool DeviceSupport::supportsTablet() const {
        return this->raw_data.find(Devices::TABLET) != std::string::npos;
    }

    bool DeviceSupport::supportsPaddle() const {
        return this->raw_data.find(Devices::PADDLE) != std::string::npos;
    }

    bool DeviceSupport::supportsKeyboard() const {
        return this->raw_data.find(Devices::KEYBOARD) != std::string::npos;
    }

    bool DeviceSupport::supportsRS232() const {
        return this->raw_data.find(Devices::RS232) != std::string::npos;
    }

    bool DeviceSupport::supportsPrinter() const {
        return this->raw_data.find(Devices::PRINTER) != std::string::npos;
    }

    bool DeviceSupport::supportsCDROM() const {
        return this->raw_data.find(Devices::CDROM) != std::string::npos;
    }

    bool DeviceSupport::supportsFloppyDrive() const {
        return this->raw_data.find(Devices::FLOPPY_DRIVE) != std::string::npos;
    }

    bool DeviceSupport::supportsDownload() const {
        return this->raw_data.find(Devices::DOWNLOAD) != std::string::npos;
    }

    std::string DeviceSupport::toString() const {
        return this->raw_data;
    }
}
