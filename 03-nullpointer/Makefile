MODULE_NAME := nullpointer
obj-m += $(MODULE_NAME).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

insmod:
	insmod $(MODULE_NAME).ko

rmmod:
	rmmod $(MODULE_NAME).ko
