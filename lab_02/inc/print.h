#ifndef _PRINT_H
#define _PRINT_H

#include "struct_flats.h"

#include "stdlib.h"
#include "stdio.h"

void print_table_rama();
void print_table_key(struct keys *key_arr, size_t count);
void print_table(struct flats *flat, size_t count);
void print_flat(struct flats flat, size_t count);

void print_info(void);
void print(void);
void print_rules_add(void);
void print_rules_del(void);

#endif
