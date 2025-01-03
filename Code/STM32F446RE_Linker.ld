ENTRY(Reset_Handler)

MEMORY
{
  FLASH    (rx)     : ORIGIN = 0x08000000,   LENGTH = 16K   /* Changed from 0x08000000 */
  SRAM     (rwx)    : ORIGIN = 0x20000000,   LENGTH = 128K
}

SECTIONS
{
	.isr_vector :
	{	
		KEEP(*(.isr_vector))
	} > FLASH

	.text :
	{	
		. = ALIGN(4);
		_stext = . ;
		*(.MAIN_TEXT)
		*(.text)
		*(.startup_code)
		. = ALIGN(4);
		_etext = . ;
	} > FLASH

	.data : 
	{	
		. = ALIGN(4);
		_sdata = .; 
		*(.data)
		. = ALIGN(4);
		_edata = . ;
	} > SRAM AT > FLASH

	.bss :
	{	
		. = ALIGN(4);
		_sbss = . ;
		*(.bss)
		. = ALIGN(4);
		_ebss = . ;
	} > SRAM

	.rodata :
	{
		*(.rodata)
	} > FLASH

}
