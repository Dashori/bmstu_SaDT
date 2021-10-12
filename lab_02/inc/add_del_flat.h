#ifndef _ADD_DEL_FLAT_H
#define _ADD_DEL_FLAT_H

#include "struct_flats.h"
#include "read_file.h"
#include "print.h"

#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR_NO_FILE 2
#define ERROR_MAX_FLAT 9
#define ERROR_ADRESS 10
#define ERROR_FLAT_PARAM 11

int add_flat(struct flats *flat_arr, size_t *count, char *filename, struct keys *key_arr);
int add_address(struct address_flat *new_address);
int add_param_flat(struct flats *new_flat);
int add_no_primary_flat(struct flats *new_flat);
void add_file(struct flats *flat_arr, FILE *f);
void del_file(struct flats *flat_arr, size_t count, char *filename);
void del_flat(struct flats *flat_arr, size_t *count, int square, char *filename);
void swap(struct flats *flat_arr, size_t *count, size_t i);

#endif
