obj-m += usb_driver.o

all:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
install:
	sudo insmod usb_driver.ko
	dmesg

remove:
	sudo rmmod usb_driver.ko
	dmesg
