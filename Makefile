obj-m := myled.o

myled.ko:myled.c
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 modules
	gcc led_control.c -o led_control

clean:
	make -C /usr/src/linux-headers-`uname -r` M=`pwd` V=1 clean
	rm led_control

