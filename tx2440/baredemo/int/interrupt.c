#include "s3c24xx.h"

void EINT_Handle()
{
    unsigned long oft = INTOFFSET;
    unsigned long val;
    
    switch( oft )
    {
        // S5������
        case 4: 
        {   
            GPFDAT |= 0xFF;   // ����LEDϨ��
            GPFDAT &= ~(1<<0);      // LED1����
            break;
        }
        
        // S6������
        case 5:
        {   
            GPFDAT |= 0xFF;   // ����LEDϨ��
            GPFDAT &= ~(1<<1);      // LED2����
            break;
        }

        // K7������
        case 6:
        {   
            GPFDAT |= 0xFF;   // ����LEDϨ��
            GPFDAT &= ~(1<<2);      // LED4����                
            break;
        }
        // K8������
        case 7:
        {   
            GPFDAT |= 0xFF;   // ����LEDϨ��
            GPFDAT &= ~(1<<3);      // LED4����                
            break;
        }

        default:
            break;
    }

}
