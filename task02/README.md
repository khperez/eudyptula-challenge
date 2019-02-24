task02 -- building and booting from source
======

## Overview

#### Tasks
- [x] Download Linus's source
- [x] Build and boot on VirtualBox VM
- [ ] Build and boot on RaspberryPi (?)


#### Summary:
- Cloned Linus's source from git.kernel.org => [Linus's Source](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/)
- Updated and installed necessary packages for development
``` 
sudo apt-get install update
sudo apt-get install fakeroot build-essential ncurses-dev xz-utils libssl-dev bc libelf-dev
```
- Check the version of the source that I cloned
```
make kernelversion
```
![make kernelversion][source_kernel_version] 
- Check the current version of the kernel I had installed on the VM:

![old kernel version][pre_kernel]
- Ran `make menuconfig`
- Had no clue what to pick so I just selected "Save" and exited.
- Eudyptula Task02 instructions said to set this variable: `CONFIG_LOCALVERSION_AUTO=y` in .config
- Ran into this error where it said `flex` and `bison` were not installed, so I installed them.

```
sudo apt-get install flex bison
```
- Resized my VirtualBox disk size because I only had 10G which was probably not enough to compile Linux (see [Appendix](#Appendix))
- Changed the number of cores on my VM from 2 to 6 (#gottagofast)
- Verified the core count with: `nproc --all`
- And FINALLY, I ran:
```
make -j6
```
- Insert meme about waiting here...
- 'Tis done, it took about 6 minutes for me

![kernel done compiling][compile_complete]
- Time to INSTALL:
```
sudo make modules_install -j6
sudo make install -j6
```
- `sudo reboot now`
- Moment of Truth: 

![new kernel][new_kernel]

And that completes Task02. I think I'd like to revisit cross-compiling for ARM and perhaps looking into `make localmodconfig` as the task instructions suggested.

___

## Notes

### Questions 
1. What does `CONFIG_LOCALVERSION_AUTO` do?
2. What is the difference between vmlinuz and bzImage?
vmlinuz 
___

## Appendix

### Packages Notes
- fakeroot:
- build-essential:
- ncurses-dev:
- xz-utils:
- libssl-dev:
- bc:
- flex:
- bison:
- libelf-dev:

### Resizing VirtualBox .vmdk
```
VBoxManage clonemedium "source.vmdk" "cloned.vdi" --format vdi
VBoxManage modifymedium "cloned.vdi" --resize 51200
VBoxManage clonemedium "cloned.vdi" "resized.vmdk" --format vmdk
```

[source_kernel_version]: /images/task02_make-kernelversion.png "make kernelversion"
[pre_kernel]: /images/task02_pre-kernel.png "old kernel version"
[compile_complete]: /images/task02_tis-done-kernel-compiled.png
[new_kernel]: /images/task02_moment-of-truth.png