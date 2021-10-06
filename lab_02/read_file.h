#ifndef _READ_FLAT_H
#define _READ_FLAT_H 1

#include <stdio.h>
#include <stdlib.h>

#include "struct_flats.h"

int read_table(FILE *f, char *filename, struct flats *arr_flat, size_t *count);
void print_table(struct flats *arr_flat, size_t count);
int read_flat_adress(FILE *f,struct flats *flat);
int read_flat(FILE *f,struct flats *flat);
int read_secondary(FILE *f, struct flats *flat);
void print_flat(struct flats flat);

#endif
