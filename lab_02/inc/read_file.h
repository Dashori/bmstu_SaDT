#ifndef _READ_FLAT_H
#define _READ_FLAT_H

#include <stdio.h>
#include <stdlib.h>

#include "struct_flats.h"

int read_table(FILE *f, char *filename, struct flats *flat, size_t *count);
void read_table_key(struct flats *flat, struct keys *key, size_t count);
int read_flat_address(FILE *f,struct flats *flat);
int read_flat(FILE *f,struct flats *flat);
int read_secondary(FILE *f, struct flats *flat);

#endif
