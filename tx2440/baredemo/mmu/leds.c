/*
 * leds.c: ѭ������4��LED
 * ���ڵڶ����ֳ��򣬴�ʱMMU�ѿ�����ʹ�������ַ
 */ 

#define GPFCON      (*(volatile unsigned long *)0xA0000050)     // �����ַ0x56000050
#define GPFDAT      (*(volatile unsigned long *)0xA0000054)     // �����ַ0x56000054

#define	GPF0_out	(1<<(0*2))
#define	GPF1_out	(1<<(1*2))
#define	GPF2_out	(1<<(2*2))
#define	GPF3_out	(1<<(3*2))

/*
 * wait�������ϡ�static inline������ԭ��ģ�
 * ��������ʹ�ñ���leds.cʱ��waitǶ��main�У���������ֻ��mainһ��������
 * ����������ʱ��main�����ĵ�ַ�����������ļ�ָ��������ʱװ�ص�ַ��
 * �������ļ�mmu.lds�У�ָ����leds.o������ʱװ�ص�ַΪ0xB4004000��
 * ������head.S�еġ�ldr pc, =0xB4004000��������ȥִ��main������
 */
static inline void wait(unsigned long dly)
{
    for(; dly > 0; dly--);
}

int main(void)
{
	unsigned long i = 0;

	GPFCON = GPF0_out|GPF1_out|GPF2_out|GPF3_out;		// ��LED1,2,3,4��Ӧ��GPF0/1/2/3�ĸ�������Ϊ���

	while(1){
		wait(30000);
		GPFDAT = (~(1<<i));	 	// ����i��ֵ������LED1,2,4
		if(++i == 5)
			i = 0;
	}
}
