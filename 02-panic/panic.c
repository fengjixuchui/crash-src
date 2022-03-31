#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void) 
{
	printk(KERN_INFO "Hello panic!\n");
	panic("nicyou trigger panic manually!");
	return 0;
}


void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye panic\n");
}

MODULE_LICENSE("GPL");
