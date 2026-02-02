obj-m += kernelModule.o

all:
	make -C /lib/modules/$(shell unname -r)/build M=$(PWD) modules
