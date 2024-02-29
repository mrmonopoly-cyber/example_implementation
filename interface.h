#pragma once

typedef struct id_obj id_obj;

typedef int (*get_id) (id_obj* th);

typedef struct id_obj id_obj;

//constructors
void new_id_obj(id_obj* buffer,get_id if_fun);
void new_id_obj_default(id_obj* buffer);
//methods
int get_id_id_obj(id_obj* th);
