#include <iostream>

#include "Rom.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        std::cout << "Loading " << argv[1] << "..." << std::endl;
        const auto rom = Rom(argv[1]);
        const auto copyright = rom.getCopyright();

        std::cout << "Target System: " << rom.getSystemType() << std::endl;
        std::cout << "Copyright: " << copyright.getPublisher() << std::endl;
        std::cout << "Release Date: " << copyright.getMonth() << " " << copyright.getYear() << std::endl;
        std::cout << "Domestic Title: " << rom.getDomesticTitle() << std::endl;
        std::cout << "Overseas Title: " << rom.getOverseasTitle() << std::endl;
    }

    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();
}
