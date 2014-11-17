#include<linux/init.h>
#include<linux/module.h>
//模块许可证声明
MODULE_LICENSE("Dual BSD/GPL");
//模块加载函数
static int hello_init(void)
{
	printk("Imagination is more important than knowledge !/n");
	return 0;
}
//模块卸载函数
static void hello_exit(void)
{
	printk("hello world exit ! Congratulations!/n");
}
//这是驱动程序初始化的入口点。对于内置模块，内核在引导时调用该入口点；   对于可加载模块则在该模块插入内核时才调用。   

module_init(hello_init);   //对于可加载模块，内核在此处调用module_cleanup（）函数，而对于内置的模块， 它什么都不做。   
module_exit(hello_exit);
//可选
//  MODULE_AUTHOR("IMAGINECUP");
//  MODULE_DESCRIPTION("A simple Hello World Module");
//  MODULE_ALIAS("A simplest module");
