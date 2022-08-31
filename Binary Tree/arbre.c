#include "arbre.h"

/*---------------------------------------------------------------------------------------------------*/
Tree *new_tree(int noeud)
{
    Tree *tr = malloc(sizeof(*tr));
    if (tr == NULL)
    {
        fprintf(stdout, "ERROR : probleme allocation \n");
        exit(EXIT_FAILURE);
    }
    tr->value = noeud;
    tr->tleft = NULL;
    tr->tright = NULL;
    tr->parent = NULL;

    printf("creation de la noeud (%d) \n", tr->value);

    return tr;
}
/*---------------------------------------------------------------------------------------------------*/
void clear_tree(Tree *tr)
{
    if (tr == NULL)
        return;

    clear_tree(tr->tleft);
    clear_tree(tr->tright);
    printf("suppresion de noeud (%d) \n", tr->value);
    free(tr);
}
/*---------------------------------------------------------------------------------------------------*/
Tree *join_tree(Tree *left, Tree *right, int noeud)
{
    Tree *tr = new_tree(noeud);
    if (tr == NULL)
    {
        fprintf(stdout, "ERROR : probleme allocation \n");
        exit(EXIT_FAILURE);
    }
    tr->tleft = left;
    tr->tright = right;
    if (left != NULL)
        left->parent = tr;
    if (right != NULL)
        right->parent = tr;

    return tr;
}
/*---------------------------------------------------------------------------------------------------*/
void print_prefixe_tree(Tree *tr)
{
    if (tr == NULL)
        return;
    if (tr->parent != NULL)
        printf("(%d) -> (%d)\n", tr->parent->value, tr->value);
    else
        printf("(%d)\n", tr->value);
    if (tr->tleft != NULL)
        print_prefixe_tree(tr->tleft);
    if (tr->tright != NULL)
        print_prefixe_tree(tr->tright);
}
/*---------------------------------------------------------------------------------------------------*/
void print_postefixe_tree(Tree *tr)
{
    if (tr == NULL)
        return;
    if (tr->parent != NULL)
        printf("(%d) -> (%d)\n", tr->parent->value, tr->value);
    else
        printf("(%d)\n", tr->value);
    if (tr->tright != NULL)
        print_postefixe_tree(tr->tright);
    if (tr->tleft != NULL)
        print_postefixe_tree(tr->tleft);
}
/*---------------------------------------------------------------------------------------------------*/
int count_tree(Tree *tr)
{
    if (tr == NULL)
        return 0;
    return (count_tree(tr->tleft) + count_tree(tr->tright) + 1);
}
/*---------------------------------------------------------------------------------------------------*/
void print_infixe_tree(Tree *tr)
{
    if (tr == NULL)
        return;
    if (tr->tright != NULL)
        print_infixe_tree(tr->tright);
    if (tr->parent != NULL)
        printf("(%d) -> (%d)\n", tr->parent->value, tr->value);
    else
        printf("(%d)\n", tr->value);

    if (tr->tleft != NULL)
        print_infixe_tree(tr->tleft);
}
