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
    tr->tleft = NULL;
    tr->tright = NULL;
    tr->parent = NULL;
    printf("Creation de %d .\n", tr->value);
    return tr;
}
/*---------------------------------------------------------------------------------------*/
char **intialise_tab(char **tab, size_t size_x, size_t size_y)
{
    tab = malloc(sizeof(*tab) * size_x);
    if (tab == NULL)
    {
        fprintf(stderr, "ER : Probleme d'allocation \n ");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    for (i = 0; i < size_x; i++)
    {
        tab[i] = malloc(sizeof(**tab) * size_y);
        if (tab[i] == NULL)
        {
            fprintf(stderr, "ER : Probleme d'allocation \n ");
            exit(EXIT_FAILURE);
        }
    }
    return tab;
}
/*---------------------------------------------------------------------------------------*/
void clear_tab(char **tab, size_t size_x)
{
    int i = 0;
    for (i = 0; i < size_x; i++)
    {
        free(tab[i]);
    }
    free(tab);
    tab = NULL;
}
/*---------------------------------------------------------------------------------------*/
void afficher_tab(char **tab, size_t size_x, size_t size_y)
{
    int i = 0, j = 0;
    for (i = 0; i < size_x; i++)
    {
        for (j = 0; j < size_y; j++)
        {
            if (tab[i][j] == ' ' || tab[i][j] == '/' || tab[i][j] == '\\')
                printf("%c", tab[i][j]);
            else
                printf("%d", tab[i][j]);
        }
        printf("\n");
    }
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

    return tr;
}
/*---------------------------------------------------------------------------------------*/
void print_tree_prefix(Tree *tr)
{
    if (tr == NULL)
        return;

    printf("(%d) pos x: %d ,pos y:%d \n", tr->value, tr->pos.x, tr->pos.y);
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
int Tree_nb_elm(Tree *tr)
{
    int height = Height(tr);
    int i = 0, j = 1, nb = 1;

    for (i = 1; i < height; i++)
    {
        if (i == 1)
            nb = 1;

        j *= 2;
        nb += j;
    }
    return nb;
}
/*---------------------------------------------------------------------------------------*/
void Tree_adjuster(Tree *tr, unsigned int ajoute)
{
    if (tr == NULL)
        return;
    if (tr->parent != NULL)
    {
        tr->pos.y += ajoute;
    }

    Tree_adjuster(tr->tleft, ajoute);

    Tree_adjuster(tr->tright, ajoute);
}
/*---------------------------------------------------------------------------------------*/
void Tree_change_degre(Tree *tr, int height)
{
    if (tr == NULL)
        return;
    tr->pos.y += height;

    Tree_change_degre(tr->tleft, height);

    Tree_change_degre(tr->tright, height);
}
/*---------------------------------------------------------------------------------------*/
void Tree_to_Table(Tree *tr, char **tab)
{
    if (tr == NULL)
        return;

    tab[tr->pos.x][tr->pos.y] = tr->value;

    if (tr->tleft != NULL)
    {

        int i = 0, j = 0;
        j = tr->pos.y;
        for (i = tr->pos.x + 1; i < tr->tleft->pos.x; i++)
        {
            j--;
            tab[i][j] = '/';
        }
    }
    if (tr->tright != NULL)
    {
        int i = 0, j = 0;
        j = tr->pos.y;
        for (i = tr->pos.x + 1; i < tr->tright->pos.x; i++)
        {
            j++;
            tab[i][j] = '\\';
        }
    }

    Tree_to_Table(tr->tleft, tab);
    Tree_to_Table(tr->tright, tab);
}
/*---------------------------------------------------------------------------------------*/
void Final_Tree_adjuster(Tree *tr, int direction)
{
    if (tr == NULL)
        return;

    if (direction == -1)
    {
        if (tr->parent->parent == NULL)
        {
            tr->pos.x += (int)(Tree_nb_elm(tr->parent) / Height(tr->parent)) + 1;
            tr->pos.y -= (int)(Tree_nb_elm(tr->parent) / Height(tr->parent)) + 1;
        }
        else
        {
            int ajoute = (int)(Tree_nb_elm(tr->parent) / Height(tr->parent)) + 1;
            tr->pos.x = tr->parent->pos.x + ajoute;
            tr->pos.y = tr->parent->pos.y - ajoute;
        }
    }
    if (direction == 1)
    {
        if (tr->parent->parent == NULL)
        {
            tr->pos.x += (int)(Tree_nb_elm(tr->parent) / Height(tr->parent)) + 1;
            tr->pos.y += (int)(Tree_nb_elm(tr->parent) / Height(tr->parent)) + 1;
        }
        else
        {
            int ajoute = (int)(Tree_nb_elm(tr->parent) / Height(tr->parent)) + 1;
            tr->pos.x = tr->parent->pos.x + ajoute;
            tr->pos.y = tr->parent->pos.y + ajoute;
        }
    }
    Final_Tree_adjuster(tr->tleft, -1);
    Final_Tree_adjuster(tr->tright, 1);
}

/*---------------------------------------------------------------------------------------*/
void tree_insertion_recherche(Tree **tr, unsigned int key)
{
    Tree *tmpNode;
    Tree *tmpTree = *tr;
    int ajoute = 0;
    if (*tr != NULL)
    {
        ajoute = (*tr)->pos.y;
        (*tr)->pos.y = (int)((Tree_nb_elm(*tr)) / 2);
        ajoute -= (*tr)->pos.y;
    }
    Tree *elem = malloc(sizeof(*elem));
    if (elem == NULL)
    {
        fprintf(stderr, "ER : Probleme d'allocation \n ");
        exit(EXIT_FAILURE);
    }
    elem->value = key;
    elem->pos.x = 0;
    elem->pos.y = 0;
    elem->tleft = NULL;
    elem->tright = NULL;
    elem->parent = NULL;
    if (tmpTree)
    {
        if (fabs(ajoute) > 0)
            Tree_adjuster(*tr, fabs(ajoute));
        elem->pos.x = tmpTree->pos.x;
        elem->pos.y = tmpTree->pos.y;
        do
        {
            tmpNode = tmpTree;

            if (key > tmpTree->value)
            {
                elem->pos.y++;
                elem->pos.x++;
                tmpTree = tmpTree->tright;
                if (!tmpTree)
                {

                    tmpNode->tright = elem;
                    elem->parent = tmpNode;
                }
            }
            else
            {
                elem->pos.y--;
                elem->pos.x++;
                tmpTree = tmpTree->tleft;
                if (!tmpTree)
                {
                    tmpNode->tleft = elem;
                    elem->parent = tmpNode;
                }
            }
        } while (tmpTree);
    }
    else
        *tr = elem;
}
/*---------------------------------------------------------------------------------------*/
void tree_insertion_tableaux(Tree **tr, int tab[], size_t size)
{
    if (tab == NULL)
    {
        fprintf(stderr, "ER : tableau est vide  \n ");
        return;
    }
    int i = 0;

    for (i = 0; i < size; i++)
    {
        tree_insertion_recherche(tr, tab[i]);
    }
}
/*---------------------------------------------------------------------------------------*/
Tree *searchNode(Tree *tr, unsigned int key, int *height)
{
    while (tr)
    {
        if (key == tr->value)
            return tr;

        if (key > tr->value)
        {
            tr = tr->tright;
            (*height)++;
        }
        else
        {
            tr = tr->tleft;
            (*height)++;
        }
    }
    return NULL;
}

/*---------------------------------------------------------------------------------------*/
unsigned max(unsigned a, unsigned b)
{
    return (a > b) ? a : b;
}
/*---------------------------------------------------------------------------------------*/
unsigned Height(Tree *tr)
{
    if (tr == NULL)
        return 0;
    else
        return 1 + max(Height(tr->tleft), Height(tr->tright));
}
/*------------------------------------------------------------------*/
int get_max(Tree *tr, const int value1, const int value2)
{
    if (tr == NULL)
    {
        fprintf(stderr, "ER : Probleme d'allocation \n ");
        exit(EXIT_FAILURE);
    }
    int height1 = 0;
    int height2 = 0;
    Tree *tr1 = searchNode(tr, value1, &height1);
    Tree *tr2 = searchNode(tr, value2, &height2);
    int max = 0;

    int counter = height1 - height2;
    int i = 0;
    if (tr1 != NULL && tr2 != NULL)
    {
        while (tr1 != tr2)
        {
            if (tr1->value > max)
                max = tr1->value;
            if (tr2->value > max)
                max = tr2->value;
            if (counter == 0)
            {
                if (tr1->parent != NULL)
                    tr1 = tr1->parent;

                if (tr2->parent != NULL)
                    tr2 = tr2->parent;
            }
            else if (counter > 0)
            {
                for (i = 0; i <= (counter) && tr1->parent != NULL; i++)
                {
                    if (tr1->value > max)
                        max = tr1->value;
                    tr1 = tr1->parent;

                    if (tr2 == tr1)
                        break;
                }
                if (tr2->parent != NULL && tr1 != tr2)
                    tr2 = tr2->parent;
            }
            else if (counter < 0)
            {
                for (i = 0; i <= (int)fabs(counter) && tr2->parent != NULL; i++)
                {
                    if (tr2->value > max)
                        max = tr2->value;
                    tr2 = tr2->parent;
                    if (tr1 == tr2)
                        break;
                }
                if (tr1->parent != NULL && tr1 != tr2)
                    tr1 = tr1->parent;
            }

            if (tr1->value > max)
                max = tr1->value;
            if (tr2->value > max)
                max = tr2->value;
        }
        return max;
    }
    return 0;
}
/*---------------------------------------------------------------------------------------*/
char **traitement(Tree *tr)
{
    if (tr == NULL)
    {
        fprintf(stderr, "ER : Probleme d'allocation \n ");
        exit(EXIT_FAILURE);
    }

    Final_Tree_adjuster(tr, 0);
    Tree_change_degre(tr, (int)Tree_nb_elm(tr) / 2);
    char **tab = NULL;
    size_t count = Tree_nb_elm(tr);

    int i = 0, j = 0;

    tab = intialise_tab(tab, count + (int)count / 2, count + (int)count / 2);

    for (i = 0; i < count + (int)count / 2; i++)
    {

        for (j = 0; j < count + (int)count / 2; j++)
        {
            tab[i][j] = ' ';
        }
    }
    Tree_to_Table(tr, tab);

    return tab;
}