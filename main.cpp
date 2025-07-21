#include <iomanip>
#include <iostream>

#include "rom.h"

void printLine(const std::string& label, bool value) {
    std::cout << std::setw(30) << std::left << label << std::setw(10) << std::right << value << std::endl;
}

void printDeviceSupportTable(const support::DeviceSupport &deviceSupport) {
    std::cout << std::boolalpha << std::endl << std::endl;
    std::cout << "Device Support Information" << std::endl;
    std::cout << "===============================================================" << std::endl;
    printLine("Three Button Controller:", deviceSupport.supportsThreeButtonController());
    printLine("Six Button Controller:", deviceSupport.supportsSixButtonController());
    printLine("Master System Controller:", deviceSupport.supportMasterSystemController());
    printLine("Analog Joystick:", deviceSupport.supportsAnalogJoystick());
    printLine("Multitap:", deviceSupport.supportsMultitap());
    printLine("Light Gun:", deviceSupport.supportsLightGun());
    printLine("Activator:", deviceSupport.supportsActivator());
    printLine("Mouse:", deviceSupport.supportsMouse());
    printLine("Trackball:", deviceSupport.supportsTrackball());
    printLine("Tablet:", deviceSupport.supportsTablet());
    printLine("Paddle:", deviceSupport.supportsPaddle());
    printLine("Keyboard:", deviceSupport.supportsKeyboard());
    printLine("RS-232:", deviceSupport.supportsRS232());
    printLine("Printer:", deviceSupport.supportsPrinter());
    printLine("CD-ROM:", deviceSupport.supportsCDROM());
    printLine("Floppy-Drive:", deviceSupport.supportsFloppyDrive());
    printLine("Download?:" , deviceSupport.supportsDownload());
}

int main(int argc, char** argv) {
    if (argc > 1) {
        std::cout << "Loading " << argv[1] << "..." << std::endl;
        const auto rom = Rom(argv[1]);
        const auto copyright = rom.getCopyright();
        const auto deviceSupport = rom.getDeviceSupport();

        std::cout << "Target System: " << rom.getSystemType() << std::endl;
        std::cout << "Copyright: " << copyright.getPublisher() << std::endl;
        std::cout << "Release Date: " << copyright.getMonth() << " " << copyright.getYear() << std::endl;
        std::cout << "Domestic Title: " << rom.getDomesticTitle() << std::endl;
        std::cout << "Overseas Title: " << rom.getOverseasTitle() << std::endl;
        std::cout << "Serial Number: " << rom.getSerialNumber().toString() << std::endl;
        std::cout << "Stored Checksum: 0x" << std::hex << rom.getChecksum() << std::endl;
        std::cout << "Calculated Checksum: 0x" << std::hex << rom.calculateChecksum() << std::endl;

        printDeviceSupportTable(deviceSupport);
    }

    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();
}
