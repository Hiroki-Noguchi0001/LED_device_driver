#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/delay.h>

#define total_module 9 
#define total_LED 8

MODULE_AUTHOR("Hiroki Noguchi");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;

static unsigned int module_PIN[total_module] = {22, 5, 24, 23, 17, 27, 26, 6, 16};
static unsigned int buzzer_PIN = 16;
static unsigned int LED_PIN[total_LED] = {22, 5, 24, 23, 17, 27, 26, 6};
//1 = 22, 2 = 5, 4 = 24, 5 = 23, 6 = 17, 7 = 27, 9 = 26, 10 = 6 


static unsigned int zero_in[6] = {22, 5, 24, 17, 27, 26};
static unsigned int one_in[2] = {24, 17};
static unsigned int two_in[5] = {22, 5, 17, 27, 6};
static unsigned int three_in[5] = {5, 24, 17, 27, 6};
static unsigned int four_in[4] = {24, 17, 26, 6};
static unsigned int five_in[5] = {5, 24, 27, 26, 6};
static unsigned int six_in[6] = {22, 5, 24, 27, 26, 6};
static unsigned int seven_in[3] = {24, 17, 27};
static unsigned int eight_in[7] = {22, 5, 24, 17, 27, 26, 6};
static unsigned int nine_in[5] = {24, 17, 27, 26, 6};



static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
	char c;
	int loop;
	if(copy_from_user(&c, buf, sizeof(char)))
		return -EFAULT;
	
	if(c == 'c')
	{
		for(loop = 0; loop < total_module; loop++)
		{
			gpio_base[10] = 1 << module_PIN[loop];
		}
	}

	else if(c == 'b')
	{
			gpio_base[7] = 1 << buzzer_PIN;
	}

	else if(c == 'a')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[7] = 1 << LED_PIN[loop];
		}
	}

	else if(c == '0')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 6; loop++)
		{
			gpio_base[7] = 1 << zero_in[loop];
		}
	}

	else if(c == '1')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 2; loop++)
		{
			gpio_base[7] = 1 << one_in[loop];
		}
	}

	else if(c == '2')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 5; loop++)
		{
			gpio_base[7] = 1 << two_in[loop];
		}
	}

	else if(c == '3')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 5; loop++)
		{
			gpio_base[7] = 1 << three_in[loop];
		}
	}

	else if(c == '4')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 4; loop++)
		{
			gpio_base[7] = 1 << four_in[loop];
		}
	}

	else if(c == '5')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 5; loop++)
		{
			gpio_base[7] = 1 << five_in[loop];
		}
	}

	else if(c == '6')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 6; loop++)
		{
			gpio_base[7] = 1 << six_in[loop];
		}
	}

	else if(c == '7')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 3; loop++)
		{
			gpio_base[7] = 1 << seven_in[loop];
		}
	}

	else if(c == '8')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 7; loop++)
		{
			gpio_base[7] = 1 << eight_in[loop];
		}
	}

	else if(c == '9')
	{
		for(loop = 0; loop < total_LED; loop++)
		{
			gpio_base[10] = 1 << LED_PIN[loop];
		}
		for(loop = 0; loop < 5; loop++)
		{
			gpio_base[7] = 1 << nine_in[loop];
		}
	}

	printk(KERN_INFO "recive %c\n", c);
	return 1;
}

	static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.write = led_write,
};

static int __init init_mod(void)
{
	int retval;
	int loop;

	retval = alloc_chrdev_region(&dev, 0, 1, "myled");
	if (retval < 0)
	{
		printk(KERN_ERR "alloc_chrdev_region failed.\n");
		return retval;
	}
	printk(KERN_INFO "%s is loaded. major%d\n", __FILE__, MAJOR(dev));

	cdev_init(&cdv, &led_fops);
	retval = cdev_add(&cdv, dev, 1);
	if (retval < 0){
		printk(KERN_ERR "cdev_add failed major:%d, minor:%d\n", MAJOR(dev), MINOR(dev));
		return retval;
	}

	cls = class_create(THIS_MODULE, "myled");
	if(IS_ERR(cls)){
		printk(KERN_ERR "class_create failed.");
		return PTR_ERR(cls);
	}

	device_create(cls, NULL, dev, NULL, "myled%d", MINOR(dev));

	gpio_base = ioremap_nocache(0xfe200000, 0xA0);//物理アドレスから仮想アドレスの変換

	for(loop = 0; loop < total_module; loop++)
	{
		const u32 index = module_PIN[loop] / 10;
		const u32 shift = (module_PIN[loop] % 10)*3;
		const u32 mask = ~(0x7 << shift);
		gpio_base[index] = (gpio_base[index] & mask) | (0x1 << shift);
	}

	return 0;
}

static void __exit cleanup_mod(void)
{
	cdev_del(&cdv);
	device_destroy(cls, dev);
	class_destroy(cls);
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "%s is unloaded. major:%d\n", __FILE__, MAJOR(dev));
}

module_init(init_mod);
module_exit(cleanup_mod);
