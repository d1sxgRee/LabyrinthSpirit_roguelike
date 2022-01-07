#include "position.h"
#include <assert.h>

static SCM coords_type;

SCM scm_make_coords(SCM x, SCM y){
  coords *c = scm_gc_malloc(sizeof(coords), "coords");
  c->x = scm_to_int(x);
  c->y = scm_to_int(y);
  return scm_make_foreign_object_1(coord_type, c);
}

SCM scm_get_x(SCM c){
  scm_assert_foreign_object_type(coord_type, c);
  coords *c1 = scm_foreign_object_ref(c, 0);
  return scm_from_int(c1->x);
}

SCM scm_get_y(SCM c){
  scm_assert_foreign_object_type(coord_type, c);
  coords *c1 = scm_foreign_object_ref(c, 0);
  return scm_from_int(c1->y);
}

void scm_register_coords(){
  coords_type = scm_make_foreign_object_type(scm_from_utf8_symbol("coords"),
                                             scm_list_1(scm_from_utf8_symbol("data")),
                                             NULL);
  scm_c_define_gsubr("make-coords", 2, 0, 0, (scm_t_subr) scm_make_coords);
  scm_c_define_gsubr("get-x", 1, 0, 0, (scm_t_subr) scm_get_x);
  scm_c_define_gsubr("get-y", 1, 0, 0, (scm_t_subr) scm_get_y);
  return;
}

SCM scm_get_coords_type(){
  assert(coords_type);p
  return coords_type;
}
