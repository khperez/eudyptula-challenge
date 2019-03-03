# Linux Device Drivers - Chapter 14 Notes

## Kobject Basics

### Kobject Initialization (p.365)

- Set the entire kobject to 0, with a call to **memset**

- [Required] Set up the internal fields of kobject -> `kobject_init()`

  - `void kobject_init(struct kobject *kobj)`

- `kobj_init()` sets the kobject's reference count to one

- [Required] Set the name of the kobject

  - `int kobject_set_name(struct kobject *kobj, const char *format, ...);`

