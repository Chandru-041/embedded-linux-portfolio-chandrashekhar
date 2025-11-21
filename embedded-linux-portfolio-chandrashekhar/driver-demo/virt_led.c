#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "virt_led"
#define CLASS_NAME  "virt"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chandrashekhar Y");
MODULE_DESCRIPTION("Virtual LED Linux Character Driver");
MODULE_VERSION("1.0");

static int majorNumber;
static struct class*  virtClass  = NULL;
static struct device* virtDevice = NULL;

static int led_state = 0;

static int dev_open(struct inode *inodep, struct file *filep){
    printk(KERN_INFO "virt_led: Device opened\n");
    return 0;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
    char value;

    if(copy_from_user(&value, buffer, 1))
        return -EFAULT;

    if(value == '1') {
        led_state = 1;
        printk(KERN_INFO "virt_led: LED ON\n");
    }
    else if(value == '0'){
        led_state = 0;
        printk(KERN_INFO "virt_led: LED OFF\n");
    }
    else {
        printk(KERN_INFO "virt_led: Invalid input\n");
    }

    return len;
}

static int dev_release(struct inode *inodep, struct file *filep){
    printk(KERN_INFO "virt_led: Device closed\n");
    return 0;
}

static struct file_operations fops =
{
    .open = dev_open,
    .write = dev_write,
    .release = dev_release,
};

static int __init virt_init(void){
    printk(KERN_INFO "virt_led: Initializing driver\n");

    majorNumber = register_chrdev(0, DEVICE_NAME, &fops);

    virtClass = class_create(THIS_MODULE, CLASS_NAME);
    virtDevice = device_create(virtClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);

    return 0;
}

static void __exit virt_exit(void){
    device_destroy(virtClass, MKDEV(majorNumber, 0));
    class_unregister(virtClass);
    class_destroy(virtClass);
    unregister_chrdev(majorNumber, DEVICE_NAME);

    printk(KERN_INFO "virt_led: Driver removed\n");
}

module_init(virt_init);
module_exit(virt_exit);
