#include<linux/module.h> // Needed by all modules 
#include<linux/kernel.h> // Needed for KERN_INFO
#include<linux/init.h>

#define DRIVER_AUTHOR "Uddhav Venkatesh Khatal"
#define DRIVER_DESC "Marvellous Infosystems"

MODULE_LICENSE("GPL");  // GPL-->GNU General Public License

static int no __initdata = 11;

static int __init Marvellous_Init(void) // (void)--> no parameter will be accepted
{
    printk(KERN_INFO "Marvellous module gets inserted : Jay Ganhesh..! %d\n",no);
    return 0;
}

static void __exit Marvellous_Cleanup(void)
{
    printk(KERN_INFO "Marvellous module gets removed : Jay Ganesh...!\n");
}

module_init(Marvellous_Init);  // used to insert module
module_exit(Marvellous_Cleanup);  // used to delete module

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

/*

1. make                  ---> .ko file gets created
2. ls

3. sudo dmesg > log.txt  --> information displayed
4. cat log.txt

5. sudo insmod Hello.ko  --> module gets inserted
6. sudo dmesg > logX.txt --> information displayed into txt file after insert
7. cat logX.txt

8. sudo rmmod Hello      --> module gets removed
9. sudo dmesg > logXX.txt --> information displayed into txt file after remove
10. cat logXX.txt

*/

/*
obj-m += hello.o
    Tells the kernel build system to build hello.c as a loadable module (hello.ko).

make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) modules

    -C → change directory to the kernel build directory

    uname -r → gets your current kernel version

    M=$(PWD) → tells the kernel build system to build the module in your current directory

    modules → builds the module
*/