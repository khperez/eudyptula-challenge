// SPDX-License-Identifier: GPL-2.0+
// 4.15.0-46-generic 

/*
 * Task05 USB Driver for the Eudpytula Challenge
 *
 * Copyright (C) 2019 Katherine Perez <perezkh@gmail.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Katherine Perez");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

static const struct usb_device_id usb_device_table[] = {
        { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
                             USB_INTERFACE_SUBCLASS_BOOT,
                             USB_INTERFACE_PROTOCOL_KEYBOARD),
        { }
};
MODULE_DEVICE_TABLE(usb, usb_device_table);

static int __init usb_driver_entry(void)
{
	printk(KERN_INFO "USB keyboard driver loaded\n");
	return 0;
}
static void __exit usb_driver_exit(void)
{
	printk(KERN_INFO "USB keyboard driver unloaded\n");
}

module_init(usb_driver_entry);
module_exit(usb_driver_exit);
