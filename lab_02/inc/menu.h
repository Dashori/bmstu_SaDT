#ifndef _MENU_H
#define _MENU_H

#include "add_del_flat.h"
#include "read_file.h"
#include "read_file.h"
#include "find_flats.h"
#include "sort_flats.h"
#include "print.h"
#include "compare.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR_KEY 1

int check_key(int key, struct flats *flat_arr, size_t *count, struct keys *key_arr, char *filename);

#endif
