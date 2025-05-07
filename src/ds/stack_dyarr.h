#ifndef STACK_DYARR_H
#define STACK_DYARR_H

#include "dynamic_array.h"

typedef dyn_arr_s stack_dyarr_s;

stack_dyarr_s *stack_dyarr_create();

bool stack_dyarr_push(stack_dyarr_s *s, void *data);

bool stack_dyarr_pop(stack_dyarr_s *s);

void *stack_dyarr_peak(stack_dyarr_s *s);

void stack_dyarr_destroy(stack_dyarr_s *s);

#endif
