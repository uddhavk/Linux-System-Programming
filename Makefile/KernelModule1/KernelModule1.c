#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

static int _init marvellous_init(void)
{
    printk(KERN_INFO "Marvellous module gets inserted : Jay Ganesh...\n");
    return 0;
}

static void _exit marvellous_exit(void)
{
    printk(KERN_INFO "Marvellous module gets removed\n");
}

module_init(marvellous_init);

module_exit(marvellous_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marvellous Infosystems");
MODULE_DESCRIPTION("Demo kernel module");

// 1.sudo dmesg -->execution
// 2.sudo dmesg > log.txt 
// uname -r kernel version


