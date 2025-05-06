#ifndef STACK_H
#define STACK_H

#include "dynamic_array.h"

typedef dyn_arr_s dyn_stack_s;

dyn_stack_s *dyn_stack_create();

bool dyn_stack_push(dyn_stack_s *s, void *value);

bool dyn_stack_pop(dyn_stack_s *s);

void *dyn_stack_peak(dyn_stack_s *s);

void dyn_stack_destroy(dyn_stack_s *s);

#endif
