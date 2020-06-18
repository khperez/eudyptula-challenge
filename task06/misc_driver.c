// SPDX-License-Identifier: GPL-2.0+
// 4.15.0-46-generic 

/*
 * Task06 Misc Driver for the Eudyptula challenge 
 *
 * Copyright (C) 2020 Katherine Perez <perezkh@gmail.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/string.h>

#define DEV_NAME "eudyptula"
static const char *id = "khperez123";
#define ID_LEN 10

static struct device *eudyptula_dev;
static struct file_operations eudyptula_fops;

static struct miscdevice eudyptula_misc_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEV_NAME,
    .fops = &eudyptula_fops,
};

static ssize_t eudyptula_read(struct file *file,
                char __user *buf, size_t lbuf,
                loff_t *ppos) {
    return simple_read_from_buffer(buf, lbuf, ppos,
            id, strlen(id));
}

static ssize_t eudyptula_write(struct file *file,
                const char __user *buf, size_t lbuf,
                loff_t *ppos) {
    char id_buf[ID_LEN] = {0};
    int rc;

    rc = simple_write_to_buffer(
            id_buf, ID_LEN, ppos, buf, lbuf);
    if (rc < 0) {
        return rc;
    }

    if (!strncmp(id_buf, id, ID_LEN)
         && lbuf - 1 == strlen(id)) {
        return lbuf; 
    }

    return -EINVAL;
}

static struct file_operations eudyptula_fops = {
    .owner = THIS_MODULE,
    .read = eudyptula_read,
    .write = eudyptula_write,
};

static int __init misc_driver_init(void)
{
    pr_info("Registering device: %s\n", DEV_NAME);
    if (misc_register(&eudyptula_misc_device)) {
        pr_err("Unable to register device misc, %d\n",
               eudyptula_misc_device.minor);
        return -EBUSY;
    }
    eudyptula_dev = eudyptula_misc_device.this_device;
    //pr_info("Device register %s SUCCESS\n", DEV_NAME);
	return 0;
}

static void __exit misc_driver_exit(void)
{
    pr_info("Unregistering device: %s\n", DEV_NAME);
    misc_deregister(&eudyptula_misc_device);
}

module_init(misc_driver_init);
module_exit(misc_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Katherine Perez");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");
