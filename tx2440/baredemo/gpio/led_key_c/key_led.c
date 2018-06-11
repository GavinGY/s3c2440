#define GPFCON      (*(volatile unsigned long *)0x56000050)
#define GPFDAT      (*(volatile unsigned long *)0x56000054)

/*
 * LED1,LED2,LED3对应GPF0、GPF1、GPF2
 */
#define	GPF0_out	(1<<(0*2))
#define	GPF1_out	(1<<(1*2))
#define	GPF2_out	(1<<(2*2))
#define GPF3_out    (1<<(3*2))

#define	GPF0_msk	(3<<(0*2))
#define	GPF1_msk	(3<<(1*2))
#define	GPF2_msk	(3<<(2*2))
#define GPF3_msk    (3<<(3*2))

/*
 * S1,S2,S3对应GPF4、GPF5、GPG6
 */
#define GPF4_in     (0<<(4*2))
#define GPF5_in     (0<<(5*2))
#define GPF6_in     (0<<(6*2))
#define GPF7_in     (0<<(7*2))

#define GPF4_msk    (3<<(4*2))
#define GPF5_msk    (3<<(5*2))
#define GPF6_msk    (3<<(6*2))
#define GPF7_msk    (3<<(7*2))

void  wait(volatile unsigned long dly)
{
    for(; dly > 0; dly--); 
}


int main()
{
        unsigned long dwDat;
        // LED1,LED2,LED3,LED4对应的引脚设为输出,先清0再设置
        GPFCON &= ~(GPF0_msk | GPF1_msk | GPF2_msk | GPF3_msk);
        GPFCON |= GPF0_out | GPF1_out | GPF2_out | GPF3_out;
        
        // S1,S2,S3,S4对应的引脚设为输入,先清0再设置
        GPFCON &= ~(GPF4_msk | GPF5_msk | GPF6_msk | GPF7_msk);
        GPFCON |= GPF4_in | GPF5_in | GPF6_in | GPF7_in;

        while(1){
            //若Kn为0(表示按下)，则令LEDn为0(表示点亮)
            dwDat = GPFDAT;             // 读取GPF管脚电平状态
        
            if (dwDat & (1<<4))         // S1没有按下
                GPFDAT |= (1<<0);       // LED1熄灭
            else                        // S1按下
                GPFDAT &= ~(1<<0);      // LED1点亮
                
            if (dwDat & (1<<5))         // S2没有按下
                GPFDAT |= (1<<1);       // LED2熄灭
            else    
                GPFDAT &= ~(1<<1);      // LED2点亮
            
            if (dwDat & (1<<6))         // S3没有按下
                GPFDAT |= (1<<2);       // LED3熄灭
            else    
                GPFDAT &= ~(1<<2);      // LED3点亮

            if (dwDat & (1<<7))         // S4没有按下
                GPFDAT |= (1<<3);       // LED4熄灭
            else    
                GPFDAT &= ~(1<<3);      // LED4点亮
        }
        return 0;
}
