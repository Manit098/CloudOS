ENTRY(start)  /* Entry point: bootloader start */

SECTIONS {
    . = 0x1000;  /* Load kernel at 1MB */

    .text : {
        *(.text)  /* Code section */
    }

    .data : {
        *(.data)  /* Data section */
    }

    .bss : {
        *(.bss)   /* Uninitialized data */
    }
}
