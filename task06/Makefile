obj-m += misc_driver.o

all:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
install:
	sudo insmod misc_driver.ko
	dmesg

remove:
	sudo rmmod misc_driver.ko
	dmesg
