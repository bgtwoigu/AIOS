/**********************************************************************************************************
AIOS(Advanced Input Output System) - An Embedded Real Time Operating System (RTOS)
Copyright (C) 2012~2017 SenseRate.Com All rights reserved.
http://www.aios.io -- Documentation, latest information, license and contact details.
http://www.SenseRate.com -- Commercial support, development, porting, licensing and training services.
--------------------------------------------------------------------------------------------------------
Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met: 
1. Redistributions of source code must retain the above copyright notice, this list of 
conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice, this list 
of conditions and the following disclaimer in the documentation and/or other materials 
provided with the distribution. 
3. Neither the name of the copyright holder nor the names of its contributors may be used 
to endorse or promote products derived from this software without specific prior written 
permission. 
--------------------------------------------------------------------------------------------------------
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
--------------------------------------------------------------------------------------------------------
 Notice of Export Control Law 
--------------------------------------------------------------------------------------------------------
 SenseRate AIOS may be subject to applicable export control laws and regulations, which might 
 include those applicable to SenseRate AIOS of U.S. and the country in which you are located. 
 Import, export and usage of SenseRate AIOS in any manner by you shall be in compliance with such 
 applicable export control laws and regulations. 
***********************************************************************************************************/

#ifndef __AIOS_PRESET_H_
#define __AIOS_PRESET_H_

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 *----------------------------------------------------------*/

/* Ensure stdint is only used by the compiler, and not the assembler. */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
 #include <stdint.h>
 extern uint32_t SystemCoreClock;
#endif


#define SETOS_CPU_CLOCK_HZ						( SystemCoreClock ) //定义CPU运行主频 (如72000000)
#define SETOS_TICK_RATE_HZ						( 1000 )             //定义SmallRTOS系统中ticks频率

#define SETOS_MINIMAL_STACK_SIZE				( 64 ) //定义任务占用的最小Stack空间
#define SETOS_TOTAL_HEAP_SIZE					( 1024*2 ) //定义系统占用的Heap空间
#define SETOS_MAX_NAME_LEN						( 10 )  //定义任务、信号量、消息队列等变量中的名称长度
#define SETOS_MAX_PRIORITIES					( 8 )   //定义任务最大优先级
#define SETOS_USE_SEMAPHORE                     ( 1 )   //是否启用系统信号量功能 0关闭 1启用
#define SETOS_USE_MUTEX							( 1 )   //是否启用互斥信号量功能 0关闭 1启用
#define SETOS_USE_MSGQ                          ( 1 )   //是否启用系统消息队列功能 0关闭 1启用
#define SETOS_MSGQ_MAX_MSGNUM                   ( 10 )  //定义消息队列中消息的门限值
#define SETOS_PEND_FOREVER_VALUE                ( 0xFFFFFFFF ) //定义信号量及消息队列中永久等待的数值

/* !!!! SETOS_MAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!*/
#define SETOS_MAX_SYSCALL_INTERRUPT_PRIORITY 	191 /* equivalent to 0xb0, or priority 11. */

/* This is the value being used as per the ST library which permits 16
priority values, 0 to 15.  This must correspond to the FitKERNEL_INTERRUPT_PRIORITY 
setting.  Here 15 corresponds to the lowest NVIC value of 255. */
#define SETOS_LIBRARY_KERNEL_INTERRUPT_PRIORITY	15

#define FitSVCHandler           SVC_Handler
#define FitPendSVHandler        PendSV_Handler
#define FitOSTickISR            SysTick_Handler

#endif /* __AIOS_PRESET_H_ */
