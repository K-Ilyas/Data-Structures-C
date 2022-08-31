#include "listed.h"

/*------------------------------------------------------------*/
dlist new_dlist(void)
{
    return NULL;
}
/*------------------------------------------------------------*/
Bool is_empty_dlist(dlist li)
{
    if (li == NULL)

        return true;
    return false;
}
/*------------------------------------------------------------*/
int length_dlist(dlist li)
{
    if (is_empty_dlist(li))
        return 0;
    return li->length;
}
/*------------------------------------------------------------*/
int first_dlist(dlist li)
{
    if (is_empty_dlist(li))
        return 0;
    return li->begin->value;
}
/*------------------------------------------------------------*/
int last_dlist(dlist li)
{
    if (is_empty_dlist(li))
        return 0;
    return li->end->value;
}
/*------------------------------------------------------------*/
dlist push_back_dlist(dlist li, int x)
{
    dlistNode *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL)
    {
        fprintf(stderr, "  probleme allocation \n\n");
        exit(EXIT_FAILURE);
    }
    nouveau->value = x;
    nouveau->next = NULL;
    nouveau->back = NULL;
    if (is_empty_dlist(li))
    {
        li = malloc(sizeof(*li));
        if (li == NULL)
        {
            fprintf(stderr, "  probleme allocation \n\n");
            exit(EXIT_FAILURE);
        }
        li->length = 0;
        li->begin = nouveau;
        li->end = nouveau;
    }
    else
    {
        li->end->next = nouveau;
        nouveau->back = li->end;
        li->end = nouveau;
    }
    li->length++;
    return li;
}
/*------------------------------------------------------------*/
dlist push_front_dlist(dlist li, int x)
{

    dlistNode *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL)
    {
        fprintf(stderr, "  probleme allocation \n\n");
        exit(EXIT_FAILURE);
    }
    nouveau->value = x;
    nouveau->next = NULL;
    nouveau->back = NULL;
    if (is_empty_dlist(li))
    {
        li = malloc(sizeof(*li));
        if (li == NULL)
        {
            fprintf(stderr, "  probleme allocation \n\n");
            exit(EXIT_FAILURE);
        }
        li->length = 0;
        li->begin = nouveau;
        li->end = nouveau;
    }
    else
    {
        li->begin->back = nouveau;
        nouveau->next = li->begin;
        li->begin = nouveau;
    }
    li->length++;
    return li;
}
/*------------------------------------------------------------*/
dlist pop_back_dlist(dlist li)
{
    if (is_empty_dlist(li))
    {
        puts("  Rien a vider la liste est vide \n\n");
        return new_dlist();
    }
    if (li->begin == li->end)
    {
        free(li);
        li = NULL;
        return new_dlist();
    }

    dlistNode *temp = li->end;
    li->end = li->end->back;
    li->end->next = NULL;
    temp->next = NULL;
    temp->back = NULL;
    free(temp);
    temp = NULL;

    li->length--;
    return li;
}
/*------------------------------------------------------------*/
dlist pop_front_dlist(dlist li)
{
    if (is_empty_dlist(li))
    {
        puts("  Rien a vider la liste est vide \n\n");
        return new_dlist();
    }
    if (li->begin == li->end)
    {
        free(li);
        li = NULL;
        return new_dlist();
    }

    dlistNode *temp = li->begin;
    li->begin = li->begin->next;
    li->begin->back = NULL;
    temp->next = NULL;
    temp->back = NULL;
    free(temp);
    temp = NULL;

    li->length--;
    return li;
}
/*------------------------------------------------------------*/
void print_dlist(dlist li)
{
    if (is_empty_dlist(li))
    {
        puts(" Nothing to display the list is empty \n\n");
        return;
    }
    dlistNode *actuel = li->begin;
    while (actuel != NULL)
    {
        printf("  (%d) --> ", actuel->value);
        actuel = actuel->next;
    }
    printf("NULL\n");
}
/*------------------------------------------------------------*/
dlist clear_dlist(dlist li)
{
    while (!is_empty_dlist(li))
    {
        li = pop_back_dlist(li);
    }
    return new_dlist();
}
/*------------------------------------------------------------*/
dlist push_after_dlist(dlist li, int before, int key)
{
    if (is_empty_dlist(li))
    {
        li = push_front_dlist(li, key);
    }
    else
    {
        if (li->end->value == before)
        {
            li = push_back_dlist(li, key);
        }
        else
        {
            dlistNode *nouveau = malloc(sizeof(*nouveau));
            if (nouveau == NULL)
            {
                fprintf(stderr, "  ERROR : probleme allocation \n\n");
                exit(EXIT_FAILURE);
            }
            int position = 0, i = 0;
            position = position_noeud(li, before);
            nouveau->value = key;
            dlistNode *temp = li->begin;
            if (position >= 1)
            {
                while (temp != NULL && i != position)
                {
                    if (temp->value == before)
                    {
                        i++;
                    }
                    if (i != position)
                    {
                        temp = temp->next;
                    }
                }
                nouveau->next = temp->next;
                nouveau->back = temp;
                temp->next->back = nouveau;
                temp->next = nouveau;
                li->length++;
            }
            else
            {
                puts("  ERROR : The node dosen't exist!!!\n");
                return li;
            }
        }
    }
    return li;
}
/*---------------------------------------------------------------*/
dlist push_before_dlist(dlist li, int after, int key)
{

    if (is_empty_dlist(li))
    {
        li = push_front_dlist(li, key);
    }
    else
    {
        if (li->begin->value == after)
        {
            li = push_front_dlist(li, key);
        }
        else
        {

            dlistNode *nouveau = malloc(sizeof(*nouveau));
            if (nouveau == NULL)
            {
                fprintf(stderr, "  probleme allocation \n\n");
                exit(EXIT_FAILURE);
            }
            int position = 0, i = 0;
            position = position_noeud(li, after);
            nouveau->value = key;
            dlistNode *temp = li->begin;
            if (position >= 1)
            {
                while (temp != NULL && i != position)
                {
                    if (temp->value == after)
                    {
                        i++;
                    }
                    if (i != position)
                    {
                        temp = temp->next;
                    }
                }

                nouveau->next = temp;
                nouveau->back = temp->back;
                temp->back->next = nouveau;
                temp->back = nouveau;
                li->length++;
            }
            else
            {
                puts("  ERROR : The node dosen't exist !!!\n");
                return li;
            }
        }
    }
    return li;
}
/*---------------------------------------------------------------*/
Bool find_node_dlist(dlist li, int key)
{
    if (is_empty_dlist(li))
    {
        puts("  Rien a cherche la list est vide  !!!\n");
        return false;
    }
    dlistNode *temp = li->begin;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}
/*---------------------------------------------------------------*/
dlist delete_node_dlist(dlist li, int key)
{
    if (is_empty_dlist(li))
    {
        puts("  Rien a vider la list est vide !!!\n");
        return NULL;
    }
    if (li->begin->value == key)
    {
        li = pop_front_dlist(li);
    }
    else if (li->end->value == key)
    {
        li = pop_back_dlist(li);
    }
    else
    {
        dlistNode *temp = li->begin;
        while (temp != NULL && temp->value != key)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            temp->next->back = temp->back;
            temp->back->next = temp->next;

            temp->next = NULL;
            temp->back = NULL;
            free(temp);
            temp = NULL;
            li->length--;
        }
        else
        {
            printf("  [%d] nexiste pas dans la list \n\n", key);
        }
    }
    return li;
}
/*------------------------------------------------------------*/
dlist triee_dlist(dlist li)
{
    if (is_empty_dlist(li))
    {
        puts("Rien a triee la list est vide \n");
        return NULL;
    }

    int var = 0, triee = 0;
    dlistNode *temp1 = li->begin;
    dlistNode *temp2 = NULL;

    printf("  |---{TRIEE}---| \n");
    printf("  1-TRIEE ASEC \n");
    printf("  2-TRIEE DESC \n");
    do
    {
        printf("  entre le votre choix pour le triage ??");
        triee = lirelong();
    } while (triee < 1 && triee > 2);

    for (temp1 = li->begin; temp1 != NULL; temp1 = temp1->next)
    {
        for (temp2 = li->begin; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp2->value > temp1->value && triee == 1)
            {

                var = temp1->value;
                temp1->value = temp2->value;
                temp2->value = var;
            }
            else if (temp1->value > temp2->value && triee == 2)
            {
                var = temp1->value;
                temp1->value = temp2->value;
                temp2->value = var;
            }
        }
    }
    return li;
}
/*------------------------------------------------------------*/
int position_noeud(dlist li, int recherche)
{
    if (is_empty_dlist(li))
    {
        puts("  Rien a cherche la list est vide \n");
        return 0;
    }
    int count = 0, position = 0;
    dlistNode *temp = NULL;
    for (temp = li->begin; temp != NULL; temp = temp = temp->next)
    {
        if (temp->value == recherche)
        {
            count++;
        }
    }
    if (count == 1)
    {
        return 1;
    }
    else if (count > 1)
    {
        printf("  vous avez dans la list (%d) noeud ont la meme valeur !!!\n", count);
        do
        {
            printf("  entrer la position de la noeud ??");
            position = lirelong();

        } while (position < 1 || position > count);
        return position;
    }
    else
    {
        return 0;
    }
}
/*------------------------------------------------------------*/
dlist reverse_dlist(dlist li)
{
    if (is_empty_dlist(li))
    {
        puts("  Rien a reverse la list est vide \n");
        return NULL;
    }
    int reverse = 0, i = 0;
    dlistNode *temp1 = li->begin;
    dlistNode *temp2 = li->end;
    while (i != length_dlist(li) / 2)
    {
        reverse = temp1->value;
        temp1->value = temp2->value;
        temp2->value = reverse;
        temp1 = temp1->next;
        temp2 = temp2->back;
        i++;
    }

    return li;
}
/*------------------------------------------------------------*/
dlist delete_node_dlist_all(dlist li, int key)
{
    if (is_empty_dlist(li))
    {
        puts("Rien a vider la list est vide \n\n");
        return NULL;
    }
    if (find_node_dlist(li, key))
    {
        int count = 0, i = 0;
        dlistNode *temp1 = li->begin;
        while (temp1 != NULL)
        {
            if (temp1->value == key)
            {
                count++;
            }
            temp1 = temp1->next;
        }
        while (i < count)
        {
            li = delete_node_dlist(li, key);
            i++;
        }
    }
    else
    {
        printf("  [%d] nexiste pas dans la list \n", key);
    }

    return li;
}
/*------------------------------------------------------------*/
int lire(char *chaine, int longeur)
{
    char *positionEntree = NULL;
    if (fgets(chaine, longeur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }

        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}
/*------------------------------------------------------------*/
void viderBuffer(void)
{
    char C = 0;
    while (C != '\n' && C != EOF)
    {
        C = getchar();
    }
}
/*------------------------------------------------------------*/
long lirelong(void)
{
    char chaine[10] = {0};
    if (lire(chaine, 10))
    {
        return strtol(chaine, NULL, 10);
    }
    else
        return 0;
}
/*------------------------------------------------------------*/
void Color(int couleurDuTexte, int couleurDeFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}
/*------------------------------------------------------------*/
