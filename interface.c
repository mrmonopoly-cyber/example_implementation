#include <stdlib.h>

#include "interface.h"

struct id_obj
{
    const unsigned int id;
    get_id id_fun;
};

static int get_id_default(id_obj* th)
{
    return th->id;
}

//constructors
void new_id_obj(id_obj* buffer,get_id if_fun)
{
    if(!buffer){
        buffer = calloc(1, sizeof(*buffer));
    }
    buffer->id_fun=if_fun;
}

void new_id_obj_default(id_obj* buffer)
{
    if(!buffer){
        buffer = calloc(1, sizeof(*buffer));
    }
    buffer->id_fun=get_id_default;
}

//methods
int get_id_id_obj(id_obj* th)
{
    return th->id_fun(th);
}
