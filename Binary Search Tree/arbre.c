#include "arbre.h"
/*---------------------------------------------------------------------------------------*/
Tree *new_tree(int x)
{
    Tree *tr = malloc(sizeof(*tr));
    if (tr == NULL)
    {
        fprintf(stderr, "ER : Probleme d'allocation \n ");
        exit(EXIT_FAILURE);
    }
    tr->value = x;
    tr->height = 1;
    tr->tleft = NULL;
    tr->tright = NULL;
    tr->parent = NULL;
    printf("Creation de %d .\n", tr->value);
    return tr;
}
/*---------------------------------------------------------------------------------------*/
void clean_tree(Tree *tr)
{
    if (tr == NULL)
        return;
    clean_tree(tr->tleft);
    clean_tree(tr->tright);
    printf("Suppresion de l'element %d .\n", tr->value);

    free(tr);
}
/*---------------------------------------------------------------------------------------*/
Tree *join_tree(Tree *left, Tree *right, int node)
{
    Tree *tr = new_tree(node);
    tr->tleft = left;
    tr->tright = right;
    if (left != NULL)
        left->parent = tr;
    if (right != NULL)
        right->parent = tr;

    tr->height = maxx(count_tree_nodes(tr->tleft),
                      count_tree_nodes(tr->tright)) +
                 1;
    return tr;
}
/*---------------------------------------------------------------------------------------*/
void print_tree_prefix(Tree *tr)
{
    if (tr == NULL)
        return;

    if (tr->parent != NULL)
        printf("(%d) --> (%d) \n", tr->parent->value, tr->value);
    else
        printf("(%d) \n", tr->value);
    if (tr->tleft != NULL)
        print_tree_prefix(tr->tleft);
    if (tr->tright != NULL)
        print_tree_prefix(tr->tright);
}
/*---------------------------------------------------------------------------------------*/
void print_tree_postfix(Tree *tr)
{
    if (tr == NULL)
        return;
    printf("\n /*--------------------*/\n");
    if (tr->parent != NULL)
        printf("(%d) --> (%d) \n", tr->parent->value, tr->value);
    else
        printf("(%d) \n", tr->value);
    if (tr->tright != NULL)
        print_tree_prefix(tr->tright);
    if (tr->tleft != NULL)
        print_tree_prefix(tr->tleft);
    printf("\n /*--------------------*/\n");
}
/*---------------------------------------------------------------------------------------*/
int count_tree_nodes(Tree *tr)
{
    if (tr == NULL)
        return 0;
    return (count_tree_nodes(tr->tleft) + count_tree_nodes(tr->tright) + 1);
}
/*---------------------------------------------------------------------------------------*/
// L'information de conformité se révèle plus importante que la hauteur de l'arbre puisqu'un défaut local sur un nœud induit le non-équilibre de l'arbre en entier.
int tree_is_equilibre(Tree *tr) // AVL
{

    if (tr == NULL)
        return 0;
    int left = tree_is_equilibre(tr->tleft);
    int right = tree_is_equilibre(tr->tright);

    if (left >= 0 && right >= 0)

        if (abs(left - right) < 2)
        {
            if (left >= right)
                return 1 + left;
            else
                return 1 + left;
        }

    return -1;
}
/*---------------------------------------------------------------------------------------*/
bool isEquilibre(Tree *tr)
{
    int lh;
    int rh;

    if (tr == NULL)
        return true;

    lh = count_tree_nodes(tr->tleft);
    rh = count_tree_nodes(tr->tright);

    if (abs(lh - rh) <= 1 && isEquilibre(tr->tleft) && isEquilibre(tr->tright))
        return true;

    return false;
}
/*---------------------------------------------------------------------------------------*/
int maxx(int a, int b)
{
    return (a > b) ? a : b;
}
/*---------------------------------------------------------------------------------------*/
void tree_insertion_recherche(Tree **tr, unsigned int key)
{
    Tree *tmpNode;
    Tree *tmpTree = *tr;

    Tree *elem = malloc(sizeof(*elem));
    elem->value = key;
    elem->tleft = NULL;
    elem->tright = NULL;

    if (tmpTree)
        do
        {
            tmpNode = tmpTree;
            if (key > tmpTree->value)
            {
                tmpTree = tmpTree->tright;
                if (!tmpTree)
                {
                    tmpNode->tright = elem;
                    elem->parent = tmpNode;
                }
            }
            else
            {
                tmpTree = tmpTree->tleft;
                if (!tmpTree)
                {
                    tmpNode->tleft = elem;
                    elem->parent = tmpNode;
                }
            }
        } while (tmpTree);
    else
        *tr = elem;
}
/*---------------------------------------------------------------------------------------*/
Tree *rightRotate(Tree *y)
{
    Tree *x = y->tleft;
    Tree *T2 = x->tright;

    x->tright = y;

    y->tleft = T2;

    y->parent = x;
    if (T2 != NULL)
        T2->parent = y;

    y->height = maxx(count_tree_nodes(y->tleft),
                     count_tree_nodes(y->tright)) +
                1;
    x->height = maxx(count_tree_nodes(x->tleft),
                     count_tree_nodes(x->tright)) +
                1;
    x->parent = NULL;
    return x;
}
/*---------------------------------------------------------------------------------------*/
Tree *leftRotate(Tree *x)
{
    Tree *y = x->tright;
    Tree *T2 = y->tleft;

    y->tleft = x;

    x->tright = T2;

    x->parent = y;
    if (T2 != NULL)
        T2->parent = x;

    x->height = maxx(count_tree_nodes(x->tleft),
                     count_tree_nodes(x->tright)) +
                1;
    y->height = maxx(count_tree_nodes(y->tleft),
                     count_tree_nodes(y->tright)) +
                1;
    y->parent = NULL;
    return y;
}
/*---------------------------------------------------------------------------------------*/
int getBalance(Tree *tr)
{
    if (tr == NULL)
        return 0;
    return count_tree_nodes(tr->tleft) - count_tree_nodes(tr->tright);
}
/*---------------------------------------------------------------------------------------*/
Tree *Equilibre_tree(Tree *tr)
{
    int balance = getBalance(tr);
    if (balance > 1 && getBalance(tr->tleft) > 0)
        return rightRotate(tr);

    if (balance < -1 && getBalance(tr->tright) < 0)
        return leftRotate(tr);

    if (balance > 1 && getBalance(tr->tleft) < 0)
    {

        tr->tleft = leftRotate(tr->tleft);
        return rightRotate(tr);
    }

    if (balance < -1 && getBalance(tr->tleft) > 0)
    {

        tr->tright = rightRotate(tr->tright);
        return leftRotate(tr);
    }

    return tr;
}