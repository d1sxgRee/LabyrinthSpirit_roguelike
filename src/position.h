#ifndef __POSITION_H__
#define __POSITION_H__

#include <libguile.h>

typedef struct Coords{
  int x;
  int y;
}Coords;

SCM scm_get_coords_type();
void scm_register_coords();

#endif /* __POSITION_H__ */
