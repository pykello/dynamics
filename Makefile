obj-m += enable_ccr.o
 
all:
	g++ -O0 mystery0.cc -o mystery0

build-module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean-module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
 
clean:
	rm -f mystery0
