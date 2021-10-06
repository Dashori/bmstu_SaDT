#ifndef _STRUCT_FLATS_H
#define _STRUCT_FLATS_H 1

#define MAX_OWNERS 30
#define MAX_COUNTRY 30
#define MAX_CITY 20
#define MAX_STREET 30
#define MAX_FLAT 60

struct secondary_flat
{
    int year;
    int all_owners;
    int count_last_owners;
    int animals;
};

struct adress_flat
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
    struct adress_flat adress;
    int square;
    int room_number;
    int cost_square_meter;
    int is_primary;
    union is_primary_flat primary;
};


#endif
