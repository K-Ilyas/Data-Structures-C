#ifndef __LISTED__H
#define __LISTED__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
// The defenition of the doubly linked list
typedef enum
{
    false, // 0
    true   // 1
} Bool;
typedef struct dlistNode
{
    int value;
    struct dlistNode *next;
    struct dlistNode *back;
} dlistNode;
typedef struct dlist
{
    int length;
    struct dlistNode *begin;
    struct dlistNode *end;
} * dlist;
// prototypes de la list
dlist new_dlist(void);
Bool is_empty_dlist(dlist li);
int length_dlist(dlist li);
int first_dlist(dlist li);
int last_dlist(dlist li);
dlist push_back_dlist(dlist li, int x);
dlist push_front_dlist(dlist li, int x);
dlist pop_back_dlist(dlist li);
dlist pop_front_dlist(dlist li);
void print_dlist(dlist li);
dlist clear_dlist(dlist li);
dlist push_after_dlist(dlist li, int before, int key);
dlist push_before_dlist(dlist li, int after, int key);
Bool find_node_dlist(dlist li, int key);
dlist reverse_dlist(dlist li);
dlist delete_node_dlist(dlist li, int key);
dlist delete_node_dlist_all(dlist li, int key);
int position_noeud(dlist li, int recherche);
dlist triee_dlist(dlist li);
int lire(char *chaine, int longeur);
void viderBuffer(void);
long lirelong(void);
void Color(int couleurDuTexte, int couleurDeFond);
#endif // __LISTED__H
