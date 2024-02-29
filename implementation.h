#include "interface.h"

typedef struct list_int list_int;
typedef struct private_list_int private_list_int;
typedef int (*max_search) (void *ele1,void *ele2);

struct list_int 
{
    private_list_int* priv_part;
    id_obj* super;
};

//constructors
void new_list_int_default(list_int* buffer);
void new_list_int(list_int *buffer, unsigned int size_list, max_search s_f);
//methods
void* get_max_list_int(const list_int* th);



