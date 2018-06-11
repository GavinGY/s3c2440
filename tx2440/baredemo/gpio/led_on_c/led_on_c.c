#define GPFCON      (*(volatile unsigned long *)0x56000050)
#define GPFDAT      (*(volatile unsigned long *)0x56000054)

int main()
{
    GPFCON = 0x00000005;    // 设置GPF0为输出口, 位[1:0]=0b01 位[3:2]=0b01  0x05
    GPFDAT = 0x00000000;    // GPF1输出0，LED1点亮

    return 0;
}
