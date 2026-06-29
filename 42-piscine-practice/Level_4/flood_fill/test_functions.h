#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "t_point.h"

void    ft_print_tab(char **area, t_point *size);
void    ft_freeAll(char **area, int i);
char    **ft_make_area(char **zone, t_point size);

#endif
