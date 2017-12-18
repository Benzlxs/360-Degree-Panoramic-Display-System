            .title  "Flash bootup utility for DM642 EVM"
            .option D,T
            .length 102
            .width  140

COPY_TABLE  .equ    0x90000400
EMIF_BASE   .equ    0x01800000

            .sect ".boot_load"
            .global _boot

_boot:      
;************************************************************************
;* Debug Loop -  Comment out B for Normal Operation
;************************************************************************

            zero B1
_myloop:  ; [!B1] B _myloop  
            nop  5
_myloopend: nop

;************************************************************************
;* Configure EMIF
;************************************************************************

        mvkl  emif_values, a3  ; load pointer to emif values
        mvkh  emif_values, a3
        
        mvkl  EMIF_BASE, a4    ; load EMIF base address
        mvkh  EMIF_BASE, a4

        mvkl  0x0009, b0       ; load number of registers to set
        mvkh  0x0000, b0

emif_loop:
        ldw   *a3++, b5        ; load register value
        sub   b0,1,b0          ; decrement counter
        nop   2
 [ b0]  b     emif_loop
        stw   b5, *a4++        ; store register value
        nop   4  

;****************************************************************************
;* Copy code sections
;****************************************************************************
        mvkl  COPY_TABLE, a3   ; load table pointer
        mvkh  COPY_TABLE, a3

        ldw   *a3++, b1        ; Load entry point

copy_section_top:
        ldw   *a3++, b0        ; byte count 
        ldw   *a3++, a4        ; ram start address
        nop   3

 [!b0]  b copy_done            ; have we copied all sections?
        nop   5

copy_loop:
        ldb   *a3++,b5
        sub   b0,1,b0          ; decrement counter
 [ b0]  b     copy_loop        ; setup branch if not done
 [!b0]  b     copy_section_top
        zero  a1
 [!b0]  and   3,a3,a1
        stb   b5,*a4++
 [!b0]  and   -4,a3,a5         ; round address up to next multiple of 4
 [ a1]  add   4,a5,a3          ; round address up to next multiple of 4

;****************************************************************************
;* Jump to entry point
;****************************************************************************
copy_done:
        b    .S2 b1
        nop   5

emif_values:
        .long 0x00052078      ; GBLCTL
        .long 0x73a28e01      ; CECTL1 (Flash/FPGA)
        .long 0xffffffd3      ; CECTL0 (SDRAM)
        .long 0x00000000      ; Reserved
        .long 0x22a28a22      ; CECTL2
        .long 0x22a28a22      ; CECTL3
        .long 0x57115000      ; SDCTL
        .long 0x0000081b      ; SDTIM (refresh period)
        .long 0x001faf4d      ; SDEXT