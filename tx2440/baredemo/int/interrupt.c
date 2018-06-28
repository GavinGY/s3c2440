#include "s3c24xx.h"

void EINT_Handle()
{
    unsigned long oft = INTOFFSET;
    unsigned long val;
    
    switch( oft )
    {
        // S5被按下
        case 4: 
        {   
            GPFDAT |= 0xFF;   // 所有LED熄灭
            GPFDAT &= ~(1<<0);      // LED1点亮
            break;
        }
        
        // S6被按下
        case 5:
        {   
            GPFDAT |= 0xFF;   // 所有LED熄灭
            GPFDAT &= ~(1<<1);      // LED2点亮
            break;
        }

        // K7被按下
        case 6:
        {   
            GPFDAT |= 0xFF;   // 所有LED熄灭
            GPFDAT &= ~(1<<2);      // LED4点亮                
            break;
        }
        // K8被按下
        case 7:
        {   
            GPFDAT |= 0xFF;   // 所有LED熄灭
            GPFDAT &= ~(1<<3);      // LED4点亮                
            break;
        }

        default:
            break;
    }

}
