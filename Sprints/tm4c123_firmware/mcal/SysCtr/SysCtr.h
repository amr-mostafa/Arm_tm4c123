/*
 * SysCtr.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_
#define E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_

#include "../../utils/STD_types.h"
/************************************************************************/
/*                              DEFINES                                 */
/************************************************************************/

/**Main oscillator**/
#define MOSC                         (0)
/**Precision internal oscillator**/
#define PIOSC                        (1)
/**Precision internal oscillator/4 **/
#define PIOSC_DIVIDED_BY4            (2)
/**Low-frequency internal oscillator**/
#define LFIOSC                       (3)


#define CRYSTAL_FREQ_5MHZ               (0x09)
#define CRYSTAL_FREQ_512MHZ            (0x0A)
#define CRYSTAL_FREQ_6MHZ               (0x0B)
#define CRYSTAL_FREQ_6_144MHZ           (0x0C)
#define CRYSTAL_FREQ_7_3728MHZ          (0x0D)
#define CRYSTAL_FREQ_8MHZ               (0x0E)
#define CRYSTAL_FREQ_8_192MHZ           (0x0F)
#define CRYSTAL_FREQ_10MHZ              (0x10)
#define CRYSTAL_FREQ_12MHZ              (0x11)
#define CRYSTAL_FREQ_12_288MHZ          (0x12)
#define CRYSTAL_FREQ_13_56MHZ           (0x13)
#define CRYSTAL_FREQ_14_31818MHZ        (0x14)
#define CRYSTAL_FREQ_16MHZ              (0x15)
#define CRYSTAL_FREQ_16_384MHZ          (0x16)
#define CRYSTAL_FREQ_18MHZ              (0x17)
#define CRYSTAL_FREQ_20MHZ              (0x18)
#define CRYSTAL_FREQ_24MHZ              (0x19)
#define PSOC_FREQ_16MHZ                 (0x19)



#define SYS_CLK_FREQ_80_000         ( 4  )
#define SYS_CLK_FREQ_66_667         ( 5  )
#define SYS_CLK_FREQ_50_000         ( 7   )
#define SYS_CLK_FREQ_44_444         ( 8   )
#define SYS_CLK_FREQ_40_000         ( 9   )
#define SYS_CLK_FREQ_36_364         ( 10  )
#define SYS_CLK_FREQ_33_333         ( 11  )
#define SYS_CLK_FREQ_30_769         ( 12  )
#define SYS_CLK_FREQ_28_571         ( 13  )
#define SYS_CLK_FREQ_26_667         ( 14  )
#define SYS_CLK_FREQ_25_000         ( 15  )
#define SYS_CLK_FREQ_23_529         ( 16  )
#define SYS_CLK_FREQ_22_222         ( 17  )
#define SYS_CLK_FREQ_21_053         ( 18  )
#define SYS_CLK_FREQ_20_000         ( 19  )
#define SYS_CLK_FREQ_19_048         ( 20  )
#define SYS_CLK_FREQ_18_182         ( 21  )
#define SYS_CLK_FREQ_17_391         ( 22  )
#define SYS_CLK_FREQ_16_667         ( 23  )
#define SYS_CLK_FREQ_16_000         ( 24  )
#define SYS_CLK_FREQ_15_385         ( 25  )
#define SYS_CLK_FREQ_14_815         ( 26  )
#define SYS_CLK_FREQ_14_286         ( 27  )
#define SYS_CLK_FREQ_13_793         ( 28  )
#define SYS_CLK_FREQ_13_333         ( 29  )
#define SYS_CLK_FREQ_12_903         ( 30  )
#define SYS_CLK_FREQ_12_500         ( 31  )
#define SYS_CLK_FREQ_12_121         ( 32  )
#define SYS_CLK_FREQ_11_765         ( 33  )
#define SYS_CLK_FREQ_11_429         ( 34  )
#define SYS_CLK_FREQ_11_111         ( 35  )
#define SYS_CLK_FREQ_10_811         ( 36  )
#define SYS_CLK_FREQ_10_526         ( 37  )
#define SYS_CLK_FREQ_10_256         ( 38  )
#define SYS_CLK_FREQ_10_000         ( 39  )
#define SYS_CLK_FREQ_9_756          ( 40  )
#define SYS_CLK_FREQ_9_524          ( 41  )
#define SYS_CLK_FREQ_9_302          ( 42  )
#define SYS_CLK_FREQ_9_091          ( 43  )
#define SYS_CLK_FREQ_8_889          ( 44  )
#define SYS_CLK_FREQ_8_696          ( 45  )
#define SYS_CLK_FREQ_8_511          ( 46  )
#define SYS_CLK_FREQ_8_333          ( 47  )
#define SYS_CLK_FREQ_8_163          ( 48  )
#define SYS_CLK_FREQ_8_000          ( 49  )
#define SYS_CLK_FREQ_7_843          ( 50  )
#define SYS_CLK_FREQ_7_692          ( 51  )
#define SYS_CLK_FREQ_7_547          ( 52  )
#define SYS_CLK_FREQ_7_407          ( 53  )
#define SYS_CLK_FREQ_7_273          ( 54  )
#define SYS_CLK_FREQ_7_143          ( 55  )
#define SYS_CLK_FREQ_7_018          ( 56  )
#define SYS_CLK_FREQ_6_897          ( 57  )
#define SYS_CLK_FREQ_6_780          ( 58  )
#define SYS_CLK_FREQ_6_667          ( 59  )
#define SYS_CLK_FREQ_6_557          ( 60  )
#define SYS_CLK_FREQ_6_452          ( 61  )
#define SYS_CLK_FREQ_6_349          ( 62  )
#define SYS_CLK_FREQ_6_250          ( 63  )
#define SYS_CLK_FREQ_6_154          ( 64  )
#define SYS_CLK_FREQ_6_061          ( 65  )
#define SYS_CLK_FREQ_5_970          ( 66  )
#define SYS_CLK_FREQ_5_882          ( 67  )
#define SYS_CLK_FREQ_5_797          ( 68  )
#define SYS_CLK_FREQ_5_714          ( 69  )
#define SYS_CLK_FREQ_5_634          ( 70  )
#define SYS_CLK_FREQ_5_556          ( 71  )
#define SYS_CLK_FREQ_5_479          ( 72  )
#define SYS_CLK_FREQ_5_405          ( 73  )
#define SYS_CLK_FREQ_5_333          ( 74  )
#define SYS_CLK_FREQ_5_263          ( 75  )
#define SYS_CLK_FREQ_5_195          ( 76  )
#define SYS_CLK_FREQ_5_128          ( 77  )
#define SYS_CLK_FREQ_5_063          ( 78  )
#define SYS_CLK_FREQ_5_000          ( 79  )
#define SYS_CLK_FREQ_4_938          ( 80  )
#define SYS_CLK_FREQ_4_878          ( 81  )
#define SYS_CLK_FREQ_4_819          ( 82  )
#define SYS_CLK_FREQ_4_762          ( 83  )
#define SYS_CLK_FREQ_4_706          ( 84  )
#define SYS_CLK_FREQ_4_651          ( 85  )
#define SYS_CLK_FREQ_4_598          ( 86  )
#define SYS_CLK_FREQ_4_545          ( 87  )
#define SYS_CLK_FREQ_4_494          ( 88  )
#define SYS_CLK_FREQ_4_444          ( 89  )
#define SYS_CLK_FREQ_4_396          ( 90  )
#define SYS_CLK_FREQ_4_348          ( 91  )
#define SYS_CLK_FREQ_4_301          ( 92  )
#define SYS_CLK_FREQ_4_255          ( 93  )
#define SYS_CLK_FREQ_4_211          ( 94  )
#define SYS_CLK_FREQ_4_167          ( 95  )
#define SYS_CLK_FREQ_4_124          ( 96  )
#define SYS_CLK_FREQ_4_082          ( 97  )
#define SYS_CLK_FREQ_4_040          ( 98  )
#define SYS_CLK_FREQ_4_000          ( 99  )
#define SYS_CLK_FREQ_3_960          ( 100 )
#define SYS_CLK_FREQ_3_922          ( 101 )
#define SYS_CLK_FREQ_3_883          ( 102 )
#define SYS_CLK_FREQ_3_846          ( 103 )
#define SYS_CLK_FREQ_3_810          ( 104 )
#define SYS_CLK_FREQ_3_774          ( 105 )
#define SYS_CLK_FREQ_3_738          ( 106 )
#define SYS_CLK_FREQ_3_704          ( 107 )
#define SYS_CLK_FREQ_3_670          ( 108 )
#define SYS_CLK_FREQ_3_636          ( 109 )
#define SYS_CLK_FREQ_3_604          ( 110 )
#define SYS_CLK_FREQ_3_571          ( 111 )
#define SYS_CLK_FREQ_3_540          ( 112 )
#define SYS_CLK_FREQ_3_509          ( 113 )
#define SYS_CLK_FREQ_3_478          ( 114 )
#define SYS_CLK_FREQ_3_448          ( 115 )
#define SYS_CLK_FREQ_3_419          ( 116 )
#define SYS_CLK_FREQ_3_390          ( 117 )
#define SYS_CLK_FREQ_3_361          ( 118 )
#define SYS_CLK_FREQ_3_333          ( 119 )
#define SYS_CLK_FREQ_3_306          ( 120 )
#define SYS_CLK_FREQ_3_279          ( 121 )
#define SYS_CLK_FREQ_3_252          ( 122 )
#define SYS_CLK_FREQ_3_226          ( 123 )
#define SYS_CLK_FREQ_3_200          ( 124 )
#define SYS_CLK_FREQ_3_175          ( 125 )
#define SYS_CLK_FREQ_3_150          ( 126 )
#define SYS_CLK_FREQ_3_125          ( 127 )

#define F_OSC_16MHZ                 (0)
#define F_OSC_8MHZ                  (0x0E)
#define F_OSC_6MHZ                  (0x0B)
#define CRYSTAL_OSC_FREQ            F_OSC_16MHZ


/*peripherals clock macros  */
#define SYSCTL_PERIPH_BASE_ADDRESS      0x400FE000
#define SYSCTL_PERIPH_GPIO     0x608  // GPIO
#define SYSCTL_PERIPH_UART     0x618  // UART

#define SYSCTL_PERIPH_GPIOA     0x01  // GPIO A
#define SYSCTL_PERIPH_GPIOB     0x02  // GPIO B
#define SYSCTL_PERIPH_GPIOC     0x04  // GPIO C
#define SYSCTL_PERIPH_GPIOD     0x08  // GPIO D
#define SYSCTL_PERIPH_GPIOE     0x10  // GPIO E
#define SYSCTL_PERIPH_GPIOF     0x20  // GPIO F

#define SYSCTL_PERIPH_UART0     0x01  // UART 0
#define SYSCTL_PERIPH_UART1     0x02  // UART 1
#define SYSCTL_PERIPH_UART2     0x04  // UART 2
#define SYSCTL_PERIPH_UART3     0x08  // UART 3
#define SYSCTL_PERIPH_UART4     0x10  // UART 4
#define SYSCTL_PERIPH_UART5     0x20  // UART 5
#define SYSCTL_PERIPH_UART6     0x40  // UART 6
#define SYSCTL_PERIPH_UART7     0x80  // UART 7


void SysCtr_init(void);
uint32 SysCtr_getSysClockFreq(void);



#endif /* E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_ */
