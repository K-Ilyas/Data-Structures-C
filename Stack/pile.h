#ifndef __PILE__H
#define __PILE__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/*declatation de la pile*/
typedef enum
{
    false, // 0
    true   // 1
} Bool;
typedef struct stackElement
{
    unsigned int value;
    struct stackElement *next;
} stackElement, *stack;

/*les prototypes de la pile */
stack new_stack(void);
Bool is_empty_stack(stack st);
stack push_stack(stack st, int x);
stack pop_stack(stack st);
stack clear_stack(stack st);
void print_stack(stack st);
int top_stack(stack st);
int length_stack(stack st);
int lire(char *chaine, int longeur);
void viderBuffer(void);
long lirelong(void);
void Color(int couleurDuTexte, int couleurDeFond);

#endif // __PILE__H
