*
* Copyright (C) 2003 Texas Instruments Incorporated
* All Rights Reserved
*
*
*---------vecs_edma1.asm---------
*
* Assembly file to set up interrupt service table (IST)
*

*------------------------------------------------------------------------------
* Global symbols defined here and exported out of this file
*------------------------------------------------------------------------------
   .global _vectors
   .global _c_int00
   .global _vector1
   .global _vector2
   .global _vector3
   .global _vector4
   .global _vector5
   .global _vector6
   .global _vector7
   .global _vector8  
   .global _vector9	  
   .global _vector10 
   .global _VPCapChaAIsr0 ; Hookup the c_int08 ISR in main()  
   .global _VPDispIsr    ; Hookup the c_int08 ISR in main()
   .global _VPCapChaAIsr2   
   .global _vector14   
   .global _vector15   

*------------------------------------------------------------------------------
* Global symbols referenced in this file but defined somewhere else. 
* Remember that your interrupt service routines need to be referenced here.
*------------------------------------------------------------------------------
   .ref _c_int00

*------------------------------------------------------------------------------
* This is a macro that instantiates one entry in the interrupt service table.
*------------------------------------------------------------------------------
VEC_ENTRY .macro addr
    STW   B0,*--B15
    MVKL  addr,B0
    MVKH  addr,B0
    B     B0
    LDW   *B15++,B0
    NOP   2
    NOP   
    NOP   
   .endm


*------------------------------------------------------------------------------
* This is a dummy interrupt service routine used to initialize the IST.
*------------------------------------------------------------------------------
_vec_dummy:
  B    B3
  NOP  5

*------------------------------------------------------------------------------
* This is the actual interrupt service table (IST). It is properly aligned and
* is located in the subsection .text:vecs. This means if you don't explicitly
* specify this section in your linker command file, it will default and link
* into the .text section. Remember to set the ISTP register to point to this
* table.
*------------------------------------------------------------------------------
 .sect ".text:vecs"
 .align 1024

_vectors:
_vector0:   VEC_ENTRY _c_int00    ;RESET
_vector1:   VEC_ENTRY _vec_dummy  ;NMI
_vector2:   VEC_ENTRY _vec_dummy  ;RSVD
_vector3:   VEC_ENTRY _vec_dummy
_vector4:   VEC_ENTRY _vec_dummy
_vector5:   VEC_ENTRY _vec_dummy
_vector6:   VEC_ENTRY _vec_dummy
_vector7:   VEC_ENTRY _vec_dummy
_vector8:   VEC_ENTRY _vec_dummy   
_vector9:   VEC_ENTRY _vec_dummy
_vector10:  VEC_ENTRY _vec_dummy
_vector11:  VEC_ENTRY _VPCapChaAIsr0 ; Hookup the c_int08 ISR in main()
_vector12:  VEC_ENTRY _VPDispIsr    ; Hookup the c_int08 ISR in main()
_vector13:  VEC_ENTRY _VPCapChaAIsr2
_vector14:  VEC_ENTRY _vec_dummy
_vector15:  VEC_ENTRY _vec_dummy

*------------------------------------------------------------------------------
