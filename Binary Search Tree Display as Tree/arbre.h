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
typedef struct Pos
{
    int x;
    int y;
} Pos;
typedef struct Tree
{
    /* data */
    int value;
    struct Pos pos;
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
void tree_insertion_recherche(Tree **tr, unsigned int key);
void tree_insertion_tableaux(Tree **tr, int tab[], size_t size);
int get_max(Tree *tr, const int value1, const int value2);
Tree *searchNode(Tree *tr, unsigned int key, int *height);
unsigned max(unsigned a, unsigned b);
unsigned Height(Tree *tr);
int Tree_nb_elm(Tree *tr);
void Tree_adjuster(Tree *tr, unsigned int ajoute);
void Tree_change_degre(Tree *tr, int height);
void Final_Tree_adjuster(Tree *tr, int direction);
char **intialise_tab(char **tab, size_t size_x, size_t size_y);
void clear_tab(char **tab, size_t size_x);
void afficher_tab(char **tab, size_t size_x, size_t size_y);
char **traitement(Tree *tr);

void Tree_to_Table(Tree *tr, char **tab);

#endif