# Custom Startup Code and Linker Script for ARM Cortex-M

## Overview
This project showcases self-written startup code and a linker script for ARM Cortex-M microcontrollers, tested on a simple LED-blinking application. It includes support files such as a Makefile and batch scripts to streamline building and debugging processes. The setup generates essential output files like `.hex`, `.bin`, `.elf`, a symbol table, and a map file, ensuring compatibility with various tools and workflows.

## Features
- **Custom Startup Code**: Implements reset and default interrupt handlers, vector table initialization, and memory section setup.
- **Linker Script**: Defines memory regions, section mappings, and aligns the layout to the ARM Cortex-M architecture.
- **Makefile**: Automates build tasks to generate binaries and debug information.
- **Debug Support**: Batch files and OpenOCD configuration for seamless debugging.

## Prerequisites
To use this project, ensure the following tools are installed:
- [GNU Make](https://www.gnu.org/software/make/)
- [OpenOCD](http://openocd.org/)
- [PuTTY](https://www.putty.org/) (or an equivalent Telnet client)
- [ARM GNU GCC Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)

## Build Instructions
### Generate All Files
To generate the `.hex`, `.bin`, `.elf`, symbol table, and map file:
1. Open Git Bash or Command Prompt in the folder containing the Makefile.
2. Run the following command:
   ```bash
   make bin
   ```

### Generate Object Files
To compile only the object files:
```bash
make all.o
```

## Debugging Instructions
### Start a Debugging Session
1. Open Command Prompt and start OpenOCD:
   ```bash
   openocd -f D:/xpack-openocd-0.12.0-4/openocd/scripts/board/st_nucleo_f4.cfg
   ```
   (Ensure the path matches your OpenOCD installation.)

2. Open PuTTY (or any Telnet client) and configure it with the following settings:
   - **IP Address**: `127.0.0.1`
   - **Port**: `4444`

3. Execute the following commands in the Telnet session:
   1. `reset init`
   2. `flash write_image erase "final.elf"` (to flash the code)
   3. `reset`


## testing 
- ![PXL_20240712_200756368](https://github.com/alfrednagy57/user-attachments/blob/main/Toolchain_repo_/Screenshot%202025-01-03%20214551.png?raw=true)
- ![PXL_20240712_200756368](https://github.com/alfrednagy57/user-attachments/blob/main/Toolchain_repo_/Screenshot%202025-01-03%20215511.png?raw=true)
- ![PXL_20240712_200756368](https://github.com/alfrednagy57/user-attachments/blob/main/Toolchain_repo_/Screenshot%202025-01-03%20215522.png?raw=true)

### Additional Debugging Commands
For more debug options, refer to the `command.txt` file included in the project.

## File Structure
- **Startup Code**: Configures the vector table, memory sections,copy .data from rom to ram, intialize .bss with zeros, and calls the application’s `main` function.
- **Linker Script**: Allocates memory sections like `.text`, `.data`, `.bss`, and `.isr_vector`.
- **Makefile**: Automates the build process for generating various output files.
- **Batch Files**: Simplify the debugging process with preconfigured steps.

## Contact
- For any inquiries, please contact the project maintainer at [linkedin](https://www.linkedin.com/in/alfred-nagy-882445224/).

## Notes
This project is optimized for ARM Cortex-M microcontrollers and has been tested on a basic LED-blinking application. It serves as a starting point for more complex embedded systems.

