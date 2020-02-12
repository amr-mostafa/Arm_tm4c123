

/**
 * main.c
 */

#include "tm4c123_firmware/mcal/nvic/nvic.h"
#include "tm4c123_firmware/mcal/SysCtr/SysCtr.h"
#include "port.h"
#include "dio.h"
int main(void)
{
    uint32 u32_Delay;
    NVIC_init();
    SysCtr_init();
    PORT_init();

    while( 1 )
    {
        Dio_WriteChannel(Dio_Channel_F1 , STD_high);
        u32_Delay = 2000000;
        while( u32_Delay!= 0 )
        {
            u32_Delay--;
        }
        Dio_WriteChannel(Dio_Channel_F1 , STD_low);
        u32_Delay = 2000000;
        while( u32_Delay!= 0 )
        {
             u32_Delay--;
         }
    }
}
