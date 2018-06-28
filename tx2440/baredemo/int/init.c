/*
 * init.c: ����һЩ��ʼ��
 */ 

#include "s3c24xx.h"

/*
 * LED1,LED2,LED4��ӦGPF4��GPF5��GPF6
 */
#define GPF0_out    (1<<(0*2))
#define GPF1_out    (1<<(1*2))
#define GPF2_out    (1<<(2*2))
#define GPF3_out    (1<<(3*2))

#define GPF0_msk    (3<<(0*2))
#define GPF1_msk    (3<<(1*2))
#define GPF2_msk    (3<<(2*2))
#define GPF3_msk    (3<<(3*2))

/*
 * S2,S3,S4��ӦGPF0��GPF2��GPG3
 */
#define GPF4_eint     (0x2<<(4*2))
#define GPF5_eint     (0x2<<(5*2))
#define GPF6_eint     (0x2<<(6*2))
#define GPF7_eint     (0x2<<(7*2))

#define GPF4_msk    (3<<(4*2))
#define GPF5_msk    (3<<(5*2))
#define GPF6_msk    (3<<(6*2))
#define GPF7_msk    (3<<(7*2))
/*
 * �ر�WATCHDOG������CPU�᲻������
 */
void disable_watch_dog(void)
{
    WTCON = 0;  // �ر�WATCHDOG�ܼ򵥣�������Ĵ���д0����
}

void init_led(void)
{
    // LED1,LED2,LED3,LED4��Ӧ��������Ϊ���,����0������
    GPFCON &= ~(GPF0_msk | GPF1_msk | GPF2_msk | GPF3_msk);
    GPFCON |= GPF0_out | GPF1_out | GPF2_out | GPF3_out;
}

/*
 * ��ʼ��GPIO����Ϊ�ⲿ�ж�
 * GPIO���������ⲿ�ж�ʱ��Ĭ��Ϊ�͵�ƽ������IRQ��ʽ(��������INTMOD)
 */ 
void init_irq( )
{
    // S1,S2,S3,S4��Ӧ��������Ϊ�ж�,����0������ EINT4,ENT5��EINT6,EINT7
    GPFCON &= ~(GPF4_msk | GPF5_msk | GPF6_msk | GPF7_msk);
    GPFCON |= GPF4_eint | GPF5_eint | GPF6_eint | GPF7_eint;

        
    /*
     * �趨���ȼ���
     * ARB_SEL0 = 00b, ARB_MODE0 = 0: REQ1 > REQ3����EINT0 > EINT2
     * �ٲ���1��6��������
     * ���գ�
     * EINT0 > EINT2 > EINT11��K2 > K3 > K4
     */
    PRIORITY = (PRIORITY & ((~0x01) | (0x3<<7))) | (0x0 << 7) ;

    // EINT4-7ʹ��
    INTMSK   &= (~(1<<4));
}




