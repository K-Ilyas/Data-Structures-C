#ifndef __CHAINE__H
#define __CHAINE__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// declaration de la pile
typedef enum
{
    false, //0
    true   //1
}Bool;
typedef struct stack
{
  char caractere;
  struct stack *next;
}stack;
// prototypes de la pile
Bool is_empty_stack(stack *st);
void push_stack(stack **st,char caractere);
char pop_stack(stack **st);
void clear_stack(stack **st);
void print_stack(stack *st);
int lire(char *chaine,int longeur);
void viderBuffer(void);
Bool is_balanced_chaine(stack **st,char *chaine);

#endif // __CHAINE__H
