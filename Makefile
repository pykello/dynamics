obj-m += enable_ccr.o
 
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc -O0 mystery0.cc -o mystery0
 
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f mystery0
