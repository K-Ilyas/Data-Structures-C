#ifndef __LISTE__H
#define __LISTE__H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*declaration de la list*/
typedef enum
{
    false, //0
    true   //1
}Bool;
typedef struct listElement
{
    int value;
    struct listElement *next;
}listElement,*list;
/*prototypes de la list */
list new_list(void);
Bool is_empty_list(list li);
int list_lenght(list li);
void print_list(list li);
list push_back_list(list li,int x);
list push_front_list(list li,int x);
list pop_back_list(list li);
list pop_front_list(list li);
list clear_list(list li);


#endif // __LISTE__H
