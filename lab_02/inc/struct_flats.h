#ifndef _STRUCT_FLATS_H
#define _STRUCT_FLATS_H

#define MAX_COUNTRY 15
#define MAX_CITY 15
#define MAX_STREET 15
#define MAX_FLAT 200

struct secondary_flat
{
    int year;
    int all_owners;
    int count_last_owners;
    int animals;
};

struct address_flat
{
    char country[MAX_COUNTRY];
    char city[MAX_CITY];
    char street[MAX_STREET];
    int num_house;
    int num_flat;
};

union is_primary_flat
{
    int is_fishing;
    struct secondary_flat secondary;
};

struct flats
{
    struct address_flat address;
    int square;
    int room_number;
    int cost_square_meter;
    int is_primary;
    union is_primary_flat primary;
};

struct keys
{
    int index;
    int square;
};

#endif
