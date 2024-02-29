#include <stdlib.h>

#include "implementation.h"
#include "interface.h"

struct private_list_int
{
    int* list;
    unsigned int size;
    max_search f_s;
};

static void new_private_list_int(private_list_int*buffer,unsigned int list_size, max_search f_s)
{
    buffer=calloc(1, sizeof(*buffer));

    buffer->list = calloc(list_size, sizeof(*buffer->list));
    buffer->size=list_size;
    buffer->f_s=f_s;
}

//constructors
void new_list_int_default(list_int* buffer)
{
    if(!buffer){
        buffer = calloc(1, sizeof(*buffer));
    }

    new_id_obj_default(buffer->super);
    new_private_list_int(buffer->priv_part, 10,NULL);
}

void new_list_int(list_int *buffer, unsigned int size_list, max_search s_f)
{
    if(!buffer){
        buffer = calloc(1, sizeof(*buffer));
    }

    new_id_obj_default(buffer->super);
    new_private_list_int(buffer->priv_part, size_list,s_f);
}
//methods
void *get_max_list_int(const list_int* th)
{
    int *list;
    unsigned int size = th->priv_part->size;
    void *res=list;

    for(int i=1;i<size;i++){
        if(th->priv_part->f_s(res,&list[i])){
            res=&list[i];
        }
    }
    return res;
}
