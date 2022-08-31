#ifndef __ARBRE__H
#define __ARBRE__H
#include <stdio.h>
#include <stdlib.h>

/* declaration d'une arbre */
typedef struct Tree
{
    int value;
    struct Tree *tleft;
    struct Tree *tright;
    struct Tree *parent;
}Tree;

/*les prototypes de l'arbre  */
Tree *new_tree(int noeud);
void clear_tree(Tree *tr);
Tree *join_tree(Tree *left,Tree *right,int noeud);
void print_prefixe_tree(Tree *tr);
void print_postefixe_tree(Tree *tr);
void print_infixe_tree(Tree *tr);
int count_tree(Tree *tr);

#endif // __ARBRE__H
