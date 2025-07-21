# MegaDrive ROM Checker

This is a simple program written in C++ that checks the integrity of MegaDrive ROM files.
It verifies the ROM's checksum, header, and other properties to ensure that the file is a valid MegaDrive ROM.
Technically it can support any ROM file, but the implementation is focused on MegaDrive ROMs.

# Usage

To use the MegaDrive ROM Checker, simply drag the ROM file onto the executable (Windows)
or run the executable with the ROM file as an argument (Linux/Mac).

```bash
Loading D:\src\MegaDrive-ROM-Checker\tests\resources\Aladdin.md...
Target System: SEGA MEGA DRIVE
Copyright: SEGA
Release Date: AUG 1993
Domestic Title: ALADDIN
Overseas Title: ALADDIN
Serial Number: GM MK-1058 -00
Stored Checksum: 0xa5e3
Calculated Checksum: 0xa5e3


Device Support Information
===============================================================
Three Button Controller:            true
Six Button Controller:             false
Master System Controller:          false
Analog Joystick:                   false
Multitap:                          false
Light Gun:                         false
Activator:                         false
Mouse:                             false
Trackball:                         false
Tablet:                            false
Paddle:                            false
Keyboard:                          false
RS-232:                            false
Printer:                           false
CD-ROM:                            false
Floppy-Drive:                      false
Download?:                         false
Press Enter to exit...
```

# Requirements
- `CMAKE` v3.0 or newer
- `C++` compiler (e.g., `g++`, `clang++`, `MSVC`)
- `C++20` standard support

# Development
