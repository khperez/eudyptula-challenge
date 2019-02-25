# task03 -- kernel version strings && patches

## Overview

Change the kernel version string, re-compile kernel, install and reboot.
Submit a patch (but not really, because I'm not a participant :disappointed: )

### Tasks

- [x] Change version string
- [x] Read [Documentation/process/submitting-patches.rst](https://github.com/torvalds/linux/blob/master/Documentation/process/submitting-patches.rst)

### Summary

Initial kernel version string:

``` bash
$ uname -r
5.0.0-rc7-00177-gcb268d8
```

#### Steps

1. Modified the `EXTRAVERSION` variable in the Makefile
2. `sudo make -j 6`
3. `sudo make module_install -j 6`
4. `sudo make install -j 6`
5. `sudo reboot now`

### Results

![eudyptula kernel version][eudyptula-kernel-version]

___

## Notes

### Dissecting the Linux kernel version number:

`5.0.0-rc7-00177-gcb268d8`

\<base kernel version\>.\<ABI number>.\<upload number>-\<flavour>

### Special annotations

- `-rcX`: Release Candidate {X}
  - If critical bugs are found, the program is updated with a higher `rc` number
  - If no critical bugs remain, the `rc` designation is dropped
- `-dirty`: designates uncommitted modifications in the source

### Definitions
__ABI__
:   Application Binary Interface, must be defined for every instruction set

___

## Things I Learned

- More git-fu:
  - Edit `~/.gitconfig` with:

    ``` none
    [core]
            abbrev = 12
    [pretty]
            fixes = Fixes: %h (\"%s\")
    ```

  - Result

    ![pretty git](/images/task03_pretty.png)

    <img src="https://i.kym-cdn.com/entries/icons/original/000/027/475/Screen_Shot_2018-10-25_at_11.02.15_AM.png" alt="surprised pikachu" width="200"/>

    That is quite pretty...

- git email
  - `sudo apt-get install git-email`

[eudyptula-kernel-version]: /images/task03_new-kernel.png