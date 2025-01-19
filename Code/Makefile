cc = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(MYMCPU) -$(MYCORE) -std=gnu11 -Wall
##-wall ---> warning all ---> turn on all warning.

ld_FLAGS = -mcpu=$(MYMCPU) -$(MYCORE) -T STM32F446RE_Linker.ld -nostdlib -Wl,-Map=elf_file/final.map

MCPU ?= 

CORE ?=

MYMCPU=cortex-m4
MYCORE=mthumb

DirO :
	mkdir O_files

DirELF : 
	mkdir elf_file
	
DirHEX :
	mkdir hex_file

Clean :
	rm -rf O_files/*.o elf_file/*.elf elf_file/*.map hex_file/*.hex hex_file/*.bin

main.o : main.c 
	$(cc) $(CFLAGS) main.c -o O_files/$@

STM32F446RE_StartUP.o : STM32F446RE_StartUP.c
	$(cc) $(CFLAGS) STM32F446RE_StartUP.c -o O_files/$@

STM32F446RE_StartUP2.o : STM32F446RE_StartUP.c
	$(cc) $(CFLAGS) STM32F446RE_StartUP.c -o $@

GPIO_Program.o : GPIO_Program.c
	$(cc) $(CFLAGS) GPIO_Program.c -o O_files/$@

RCC_Program.o : RCC_Program.c
	$(cc) $(CFLAGS) RCC_Program.c -o O_files/$@

Syscall.o : syscalls.c
	$(cc) $(CFLAGS) RCC_Program.c -o O_files/$@

Gen_SymTab :
	arm-none-eabi-nm elf_file/final.elf > Symbol_Table/SymbolTable.txt

All.o : STM32F446RE_StartUP.o RCC_Program.o GPIO_Program.o main.o

final.elf : STM32F446RE_Linker.ld
	$(cc) $(ld_FLAGS) *.c -o elf_file/final.elf

all : final.elf  
	arm-none-eabi-objcopy -I elf32-littlearm -O ihex elf_file/final.elf hex_file/final.hex

bin : all Gen_SymTab
	arm-none-eabi-objcopy -I elf32-littlearm -O binary elf_file/final.elf hex_file/user_app.bin

openocd :
	openocd -f E:/xpack-openocd-0.12.0-4/openocd/scripts/board/st_nucleo_f4.cfg

GDB-Client :
	arm-none-eabi-gdb

target : 
	target remote localhost:3333

blue_pil:
	openocd -f D:/xpack-openocd-0.12.0-4/openocd/scripts/interface/stlink.cfg -f D:/xpack-openocd-0.12.0-4/openocd/scripts/board/stm32f103c8_blue_pill.cfg -c "transport select hla_swd"
	