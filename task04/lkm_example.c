// SPDX-License-Identifier: GPL-2.0+

/*
 * Example driver for the Eudyptula Challenge
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

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Katherine Perez");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

static int __init lkm_example_init(void)
{
	netdev_info(netdevdev "Hello, My Neighbor!\n");
	return 0;
}
static void __exit lkm_example_exit(void)
{
	netdev_info(netdevdev "Goodbye, My Neighbor!\n");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);
