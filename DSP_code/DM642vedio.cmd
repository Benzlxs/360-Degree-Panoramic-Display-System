

MEMORY
{
    boot: o = 00000000h l = 000400h /* all SRAM*/
    L2 :  o = 00000400h l = 0003fb00h /* all SRAM   	*/

	CE01: o = 80000000h l = 000CEB80h /* external memory   输入1*/
	CE02: o = 800CEB80h l = 000CEB80h /* external memory   输入2*/
	CE03: o = 8019D700h l = 000CEB80h /* external memory   输入3*/
	CE04: o = 8026C280h l = 000CEB80h /* external memory   输入4*/

	CE05: o = 8033AE00h l = 000CEC80h /* external memory   输出*/
	CE11: o = 80813300h l = 00654000h /* external memory   moulding*/

	CE00: o = 80E67300h l = 00f000000h /* external memory   */
}

SECTIONS
{
    .boot_load  >       boot
    .cinit      >       L2
    .text       >       L2
    .stack      >       L2
    .bss        >       L2
    .const      >       L2
    .data       >       L2
    .far        >       L2
    .switch     >       L2
    .sysmem     >       L2
    .tables     >       L2
    .cio        >       L2
    
	.capChaAYSpace1>    CE01
    .capChaACbSpace1>   CE01
    .capChaACrSpace1>   CE01

	.capChaAYSpace2>    CE02
    .capChaACbSpace2>   CE02
    .capChaACrSpace2>   CE02

    .capChaAYSpace3>    CE03
    .capChaACbSpace3>   CE03
    .capChaACrSpace3>   CE03

	.capChaAYSpace4>    CE04
    .capChaACbSpace4>   CE04
    .capChaACrSpace4>   CE04
    
    .disChaAYSpace>    CE05
    .disChaACbSpace>   CE05
    .disChaACrSpace>   CE05
    .tempSpace  >      CE11

    
    .external   >      CE00
	.allview_Y  >      CE00
	.allview_U  >      CE00 
	.allview_V  >      CE00	

//	.cinit      >      CE00
	.front_Y_X  >      CE00
	.front_Y_Y  >      CE00
 
	
	.left_Y_X   >      CE00
	.left_Y_Y   >      CE00

	.right_Y_X   >      CE00
	.right_Y_Y   >      CE00 
     
	.back_Y_X   >      CE00
	.back_Y_Y   >      CE00 

	.carYdata   >      CE00
	.carUdata   >      CE00
	.carVdata   >      CE00
}                           
