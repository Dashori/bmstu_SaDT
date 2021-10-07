#ifndef _MENU_H
#define _MENU_H 1

#include "add_del_flat.h"
#include "read_file.h"
#include "read_file.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR_KEY 1

int check_key(int key, struct flats *flat_arr, size_t *count);
void print(void);
void print_rules_add(void);
void print_rules_del(void);

#endif
