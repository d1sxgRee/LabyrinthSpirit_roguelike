#ifndef __INTERFACE_H__
#define __INTERFACE_H__

typedef struct Interface Interface;

Interface *interface_init();
void interface_destroy(Interface *interface);
void interface_run(Interface *interface);

#endif /* __INTERFACE_H__ */
