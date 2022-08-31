#ifndef __FILE__H
#define __FILE__H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
/* defenitiom de la file*/
typedef enum
{
  false, // 0
  true   // 1
} Bool;
typedef struct queueElement
{
  int value;
  struct queueElement *next;
} queueElement, *queue;
static queueElement *first = NULL;
static queueElement *last = NULL;
static int length = 0;
/*prototypes de la file*/
Bool is_empty_queue(void);
int length_queue(void);
int first_queue(void);
int last_queue(void);
void print_queue(void);
void push_queue(int x);
void pop_queue(void);
void clear_queue(void);
int lire();
void viderBuffer();
long lirelong();
void Color(int couleurDuTexte, int couleurDeFond);

#endif // __FILE__H
