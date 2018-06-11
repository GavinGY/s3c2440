objs := head.o init.o leds.o

mmu.bin : $(objs)
	arm-linux-ld -Tmmu.lds -o mmu_elf $^
	arm-linux-objcopy -O binary -S mmu_elf $@
	arm-linux-objdump -D -m arm mmu_elf > mmu.dis
	
%.o:%.c
	arm-linux-gcc -Wall -O0 -c -o $@ $<

%.o:%.S
	arm-linux-gcc -Wall -O0 -c -o $@ $<

clean:
	rm -f mmu.bin mmu_elf mmu.dis *.o		
	