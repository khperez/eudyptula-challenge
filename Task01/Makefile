obj-m += lkm_example.o

all:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
test:
	sudo dmesg -C
	sudo insmod lkm_example.ko
	sudo rmmod lkm_example.ko
	dmesg
