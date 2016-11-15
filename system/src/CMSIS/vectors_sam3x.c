//
// This file is part of the GNU ARM Eclipse Plug-ins project.
// Copyright (c) 2014 Liviu Ionescu
//

// ----------------------------------------------------------------------------

#include "cortexm/ExceptionHandlers.h"

// ----------------------------------------------------------------------------

void __attribute__((weak))
Dummy_Handler(void);

// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_Handler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//
// TODO: Rename this and add the actual routines here.

void __attribute__ ((weak, alias ("Dummy_Handler")))
DeviceInterrupt_Handler(void);
//////
/* Cortex-M3 core handlers */
void NMI_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MemManage_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BusFault_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UsageFault_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SVC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DebugMon_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void SUPC_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RSTC_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTT_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PMC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EFC0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EFC1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_SMC_INSTANCE_
void SMC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SMC_INSTANCE_ */
#ifdef _SAM3XA_SDRAMC_INSTANCE_
void SDRAMC_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SDRAMC_INSTANCE_ */
void PIOA_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOB_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOC_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOD_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_PIOE_INSTANCE_
void PIOE_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOE_INSTANCE_ */
#ifdef _SAM3XA_PIOF_INSTANCE_
void PIOF_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_PIOF_INSTANCE_ */
void USART0_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART1_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART2_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_USART3_INSTANCE_
void USART3_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_USART3_INSTANCE_ */
void HSMCI_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_SPI1_INSTANCE_
void SPI1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_SPI1_INSTANCE_ */
void SSC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC4_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC5_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_TC2_INSTANCE_
void TC6_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC7_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC8_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_TC2_INSTANCE_ */
void PWM_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DACC_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DMAC_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UOTGHS_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TRNG_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAM3XA_EMAC_INSTANCE_
void EMAC_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAM3XA_EMAC_INSTANCE_ */
void CAN0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void CAN1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
////////

// ----------------------------------------------------------------------------

extern unsigned int _estack;

typedef void
(* const pHandler)(void);

// ----------------------------------------------------------------------------

// The vector table.
// This relies on the linker script to place at correct location in memory.

__attribute__ ((section(".isr_vector")))
pHandler __isr_vectors[] =
  { //
    /* copy-paste from ATMEL's startup_sam3x.c */
  /* Configure Initial Stack Pointer, using linker-generated symbols */
	(pHandler) (&_estack),
	(void*) Reset_Handler,

	(void*) NMI_Handler,
	(void*) HardFault_Handler,
	(void*) MemManage_Handler,
	(void*) BusFault_Handler,
	(void*) UsageFault_Handler,
	(void*) (0UL),           /* Reserved */
	(void*) (0UL),           /* Reserved */
	(void*) (0UL),           /* Reserved */
	(void*) (0UL),           /* Reserved */
	(void*) SVC_Handler,
	(void*) DebugMon_Handler,
	(void*) (0UL),           /* Reserved */
	(void*) PendSV_Handler,
	(void*) SysTick_Handler,

	/* Configurable interrupts */
	(void*) SUPC_Handler,    /*  0  Supply Controller */
	(void*) RSTC_Handler,    /*  1  Reset Controller */
	(void*) RTC_Handler,     /*  2  Real Time Clock */
	(void*) RTT_Handler,     /*  3  Real Time Timer */
	(void*) WDT_Handler,     /*  4  Watchdog Timer */
	(void*) PMC_Handler,     /*  5  PMC */
	(void*) EFC0_Handler,    /*  6  EFC 0 */
	(void*) EFC1_Handler,    /*  7  EFC 1 */
	(void*) UART_Handler,    /*  8  UART */
#ifdef _SAM3XA_SMC_INSTANCE_
	(void*) SMC_Handler,     /*  9  SMC */
#else
	(void*) (0UL),           /*  9 Reserved */
#endif /* _SAM3XA_SMC_INSTANCE_ */
#ifdef _SAM3XA_SDRAMC_INSTANCE_
	(void*) SDRAMC_Handler,  /* 10  SDRAMC */
#else
	(void*) (0UL),           /* 10 Reserved */
#endif /* _SAM3XA_SDRAMC_INSTANCE_ */
	(void*) PIOA_Handler,    /* 11 Parallel IO Controller A */
	(void*) PIOB_Handler,    /* 12 Parallel IO Controller B */
	(void*) PIOC_Handler,    /* 13 Parallel IO Controller C */
	(void*) PIOD_Handler,    /* 14 Parallel IO Controller D */

#ifdef _SAM3XA_PIOE_INSTANCE_
	(void*) PIOE_Handler,    /* 15 Parallel IO Controller E */
#else
	(void*) (0UL),           /* 15 Reserved */
#endif /* _SAM3XA_PIOE_INSTANCE_ */
#ifdef _SAM3XA_PIOF_INSTANCE_
	(void*) PIOF_Handler,    /* 16 Parallel IO Controller F */
#else
	(void*) (0UL),           /* 16 Reserved */
#endif /* _SAM3XA_PIOF_INSTANCE_ */
	(void*) USART0_Handler,  /* 17 USART 0 */
	(void*) USART1_Handler,  /* 18 USART 1 */
	(void*) USART2_Handler,  /* 19 USART 2 */
#ifdef _SAM3XA_USART3_INSTANCE_
	(void*) USART3_Handler,  /* 20 USART 3 */
#else
	(void*) (0UL),           /* 20 Reserved */
#endif /* _SAM3XA_USART3_INSTANCE_ */
	(void*) HSMCI_Handler,   /* 21 MCI */
	(void*) TWI0_Handler,    /* 22 TWI 0 */
	(void*) TWI1_Handler,    /* 23 TWI 1 */
	(void*) SPI0_Handler,    /* 24 SPI 0 */
#ifdef _SAM3XA_SPI1_INSTANCE_
	(void*) SPI1_Handler,    /* 25 SPI 1 */
#else
	(void*) (0UL),           /* 25 Reserved */
#endif /* _SAM3XA_SPI1_INSTANCE_ */
	(void*) SSC_Handler,     /* 26 SSC */
	(void*) TC0_Handler,     /* 27 Timer Counter 0 */
	(void*) TC1_Handler,     /* 28 Timer Counter 1 */
	(void*) TC2_Handler,     /* 29 Timer Counter 2 */
	(void*) TC3_Handler,     /* 30 Timer Counter 3 */
	(void*) TC4_Handler,     /* 31 Timer Counter 4 */
	(void*) TC5_Handler,     /* 32 Timer Counter 5 */
#ifdef _SAM3XA_TC2_INSTANCE_
	(void*) TC6_Handler,     /* 33 Timer Counter 6 */
	(void*) TC7_Handler,     /* 34 Timer Counter 7 */
	(void*) TC8_Handler,     /* 35 Timer Counter 8 */
#else
	(void*) (0UL),           /* 33 Reserved */
	(void*) (0UL),           /* 34 Reserved */
	(void*) (0UL),           /* 35 Reserved */
#endif /* _SAM3XA_TC2_INSTANCE_ */
	(void*) PWM_Handler,     /* 36 PWM */
	(void*) ADC_Handler,     /* 37 ADC controller */
	(void*) DACC_Handler,    /* 38 DAC controller */
	(void*) DMAC_Handler,    /* 39 DMA Controller */
	(void*) UOTGHS_Handler,  /* 40 USB OTG High Speed */
	(void*) TRNG_Handler,    /* 41 True Random Number Generator */
#ifdef _SAM3XA_EMAC_INSTANCE_
	(void*) EMAC_Handler,    /* 42 Ethernet MAC */
#else
	(void*) (0UL),           /* 42 Reserved */
#endif /* _SAM3XA_EMAC_INSTANCE_ */
	(void*) CAN0_Handler,    /* 43 CAN Controller 0 */
	(void*) CAN1_Handler     /* 44 CAN Controller 1 */
    };

// ----------------------------------------------------------------------------

// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.

void __attribute__ ((section(".after_vectors")))
Dummy_Handler(void)
{
  while (1)
    {
    }
}

// ----------------------------------------------------------------------------
