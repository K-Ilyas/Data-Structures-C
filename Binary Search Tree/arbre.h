#ifndef __ARBRE__H__
#define __ARBRE__H__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum
{
    false,
    true
} bool;
typedef struct Tree
{
    /* data */
    int value;
    int height;
    struct Tree *tleft;
    struct Tree *tright;
    struct Tree *parent;

} Tree;

Tree *new_tree(int x);
void clean_tree(Tree *tr);
Tree *join_tree(Tree *left, Tree *right, int node);
void print_tree_prefix(Tree *tr);
void print_tree_postfix(Tree *tr);
int count_tree_nodes(Tree *tr);
int tree_is_equilibre(Tree *tr);
bool isEquilibre(Tree *tr);
void tree_insertion_recherche(Tree **tr, unsigned int key);
Tree *rightRotate(Tree *y);
Tree *leftRotate(Tree *x);
int getBalance(Tree *tr);
int maxx(int a, int b);
Tree *Equilibre_tree(Tree *tr);
#endif