
#define	GPFCON		(*(volatile unsigned long *)0x56000050)
#define	GPFDAT		(*(volatile unsigned long *)0x56000054)

#define	GPF0_out	(1<<(0*2))
#define	GPF1_out	(1<<(1*2))
#define	GPF2_out	(1<<(2*2))
#define	GPF3_out	(1<<(3*2))

void  wait(volatile unsigned long dly)
{
	for(; dly > 0; dly--); 
}

int main(void)
{
	unsigned long i = 0;

	GPFCON = GPF0_out|GPF1_out|GPF2_out|GPF3_out;		// 将LED1,2,3,4对应的GPF0/1/2/3四个引脚设为输出

	while(1){
		wait(30000);
		GPFDAT = (~(1<<i));	 	// 根据i的值，点亮LED1,2,4
		if(++i == 5)
			i = 0;
	}

	return 0;
}


