#ifndef _ADD_DEL_FLAT_H
#define _ADD_DEL_FLAT_H 1

#include "struct_flats.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR_NO_FILE 2
#define ERROR_ADRESS 10
#define ERROR_FLAT_PARAM 11

int add_flat(FILE *f);
int add_no_primary_flat(struct flats *new_flat);
#endif
