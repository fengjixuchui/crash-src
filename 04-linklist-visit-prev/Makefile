MODULE_NAME := linklist
obj-m += $(MODULE_NAME).o

$(MODULE_NAME).ko:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

insmod:
	insmod $(MODULE_NAME).ko

rmmod:
	rmmod $(MODULE_NAME).ko

dis: $(MODULE_NAME).ko
	objdump -d -S $(MODULE_NAME).ko > $(MODULE_NAME).dis
	#objdump -d -S $(MODULE_NAME).ko > $(MODULE_NAME).dis -mi386:x86-64:intel
