#define GPFCON      (*(volatile unsigned long *)0x56000050)
#define GPFDAT      (*(volatile unsigned long *)0x56000054)

int main()
{
    GPFCON = 0x00000005;    // ����GPF0Ϊ�����, λ[1:0]=0b01 λ[3:2]=0b01  0x05
    GPFDAT = 0x00000000;    // GPF1���0��LED1����

    return 0;
}
