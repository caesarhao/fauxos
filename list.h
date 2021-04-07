#ifndef __LIST__
#define __LIST__

/**
 * linked list implementation is taken from Contiki project
 * http://www.contiki-ng.org
 */
#include "fos_macro.h"

#define LIST_CONCAT(s1, s2) CONCAT2(s1, s2)

#define LIST(name) \
         static void *LIST_CONCAT(name,_list) = NULL; \
         static list_t name = (list_t)&LIST_CONCAT(name,_list)

#define LIST_STRUCT(name) \
         void *LIST_CONCAT(name,_list); \
         list_t name

#define LIST_STRUCT_INIT(struct_ptr, name)                              \
    do {                                                                \
       (struct_ptr)->name = &((struct_ptr)->LIST_CONCAT(name,_list));   \
       (struct_ptr)->LIST_CONCAT(name,_list) = NULL;                    \
       list_init((struct_ptr)->name);                                   \
    } while(0)

typedef void ** list_t;

void   list_init(list_t list);
void * list_head(list_t list);
void * list_tail(list_t list);
void * list_pop (list_t list);
void   list_push(list_t list, void *item);

void * list_chop(list_t list);

void   list_add(list_t list, void *item);
void   list_remove(list_t list, void *item);

int    list_length(list_t list);

void   list_copy(list_t dest, list_t src);

void   list_insert(list_t list, void *previtem, void *newitem);

void * list_item_next(void *item);

boolean list_contains(list_t list, void *item);


#endif
