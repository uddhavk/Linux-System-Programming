#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/device.h>

#define DEVICE_NAME "marvellous_driver"
#define CLASS_NAME "marvellous_class"

//////////////////////////////////////////////////////////////////////////////

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Uddhav Venkatesh Khatal");
MODULE_DESCRIPTION("Marvellous : character driver for kernel");
MODULE_VERSION("0.1");

//////////////////////////////////////////////////////////////////////////////

static int majorNumber; 
static char message[256] = {'0'};
static size_t size_of_message = 0;
static int numberOpens = 0;

static struct class* charClass = NULL;
static struct device* charDevice = NULL;

static int             dev_open(struct inode *,struct file *);
static int		       dev_release(struct inode *, struct file *);
static ssize_t 		   dev_read(struct file *,char __user *,size_t, loff_t *);
static ssize_t		   dev_write(struct file *,const char __user *,size_t, loff_t *);

static struct file_operations fops =
{
	.owner = THIS_MODULE,
	.open = dev_open,
	.read = dev_read,
	.write = dev_write,
	.release = dev_release,
};

//////////////////////////////////////////////////////////////////////////////

static int __init char_init(void)
{
	printk(KERN_INFO "Marvellous : Initializing driver\n");
	
	majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
	
	if(majorNumber < 0)
	{
		printk(KERN_ALERT "Marvellous : failed to register major number\n");
		return majorNumber;
	}
	
	printk(KERN_INFO "Marvellous : Register major number %d\n",majorNumber);
	
	charClass = class_create(CLASS_NAME);
	
	if(IS_ERR(charClass))
	{
		unregister_chrdev(majorNumber, DEVICE_NAME);
		printk(KERN_ALERT "Marvellous : Failed to create class\n");
		return PTR_ERR(charClass);	
	}
	
	
	charDevice = device_create(charClass, NULL,
				   MKDEV(majorNumber, 0),
				   NULL,
				   DEVICE_NAME);
				   
	if(IS_ERR(charDevice))
	{
		class_destroy(charClass);
		unregister_chrdev(majorNumber, DEVICE_NAME);
		printk(KERN_ALERT "Marvellous : Failed to create device\n");
		return PTR_ERR(charDevice);
	}
	
	printk(KERN_INFO "Marvellous : Device created successfully\n");
	return 0;
	
}

//////////////////////////////////////////////////////////////////////////////

static void __exit char_exit(void)
{
	device_destroy(charClass,MKDEV(majorNumber, 0));
	class_destroy(charClass);
	unregister_chrdev(majorNumber,DEVICE_NAME);
	
	printk(KERN_INFO "Marvellous : Driver unloaded successfully\n");
}

//////////////////////////////////////////////////////////////////////////////

static int dev_open(struct inode *inodep, struct file *filep)
{
	numberOpens++;
	printk(KERN_INFO "Marvellous : Device opened %d times(s)\n",numberOpens);
	return 0;
	
}

//////////////////////////////////////////////////////////////////////////////

static ssize_t dev_read(struct file *filep,
			char __user *buffer,
			size_t len,
			loff_t *offset)
{
 	if(*offset > 0 || size_of_message == 0)
 	{
 		return 0;
 	}
 	
 	if(len > size_of_message)
 	{
 		len = size_of_message;
 	}
 	
 	if(copy_to_user(buffer, message, len))
 	{
 		return -EFAULT;
 		
 	}
 	
 	*offset += len;
 	printk(KERN_INFO "Marvellous : Sent %zu character to user\n",len);
 	
 	return len;
 	
 }
 
//////////////////////////////////////////////////////////////////////////////
 
static ssize_t dev_write(struct file *filep,
 			 const char __user *buffer,
 			 size_t len,
 			 loff_t *offset)
{
	if(len > sizeof(message) -1)
	{
		len = sizeof(message) - 1;
	}
	
	if(copy_from_user(message, buffer, len))
	{
		return -EFAULT;
	}
	
	message[len] = '\0';
	size_of_message = len;
	
	printk(KERN_INFO "Marvellous : Received %zu characters\n",len);
	return len;
	
}

//////////////////////////////////////////////////////////////////////////////

 static int dev_release(struct inode *inode, struct file *filep)
{
 	printk(KERN_INFO "Marvellous : Device closed\n");
 	
 	return 0;
}
 
//////////////////////////////////////////////////////////////////////////////

module_init(char_init);
module_exit(char_exit);


/*


using command prompt-->
   
   1.  make
   2.  ls /dev
   3.  sudo mknod /dev/LSP c 101 0 -->character special file
   4.  ls /dev   
   5.  ls /sys/class/
   6.  ls -l /dev  -->op-->crw-r--r--   1 root root    101,     0 Feb 22 10:22 LSP
   7.  lsmod
   8.  sudo insmod MarvellousDriver.ko
   9.  lsmod > ls.txt
   10. ls -l /dev > lsdev.txt --->op-->MarvellousDriver -->crw-------   1 root root    505,     0 Feb 22 10:26 marvellous_driver
   11. sudo dmesg > log.txt
   12. sudo cat /dev/marvellous_driver  --> op Device opened 1 time(s) .. Device closed
   13. sudo dmesg > logopen.txt
   14. sudo echo "Jay Ganesh..." > /dev/marvellous_driver ---> error (Permission denied)
   15. sudo chmod 666 /dev/marvellous_driver
   16. sudo echo "Jay Ganesh..." > /dev/marvellous_driver
   17. sudo dmesg > writelog.txt              ---> op Received 14 characters...Device opened 2 time(s) ... Device closed
   18. sudo cat /dev/marvellous_driver
   19. sudo dmesg > readlog.txt
   20. cat readlog.txt --> Sent 14 characters to user  ... Device opened 3 time(s) ... Device closed
   21. ls /sys/class/  --> marvellous_class
   22. ls /dev -->  marvellous_driver
   23. sudo rmmod MarvellousDriver 

*/