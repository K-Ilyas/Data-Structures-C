#include "pile.h"

/*------------------------------------------------------------*/
stack new_stack(void)
{
    return NULL;
}
/*------------------------------------------------------------*/
Bool is_empty_stack(stack st)
{

    if (st == NULL)
        return true;
    return false;
}
/*------------------------------------------------------------*/
stack push_stack(stack st, int x)
{
    stackElement *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL)
    {
        fprintf(stderr, "  ERROR : probleme allocation \n");
        exit(EXIT_FAILURE);
    }
    nouveau->value = x;
    nouveau->next = st;

    return nouveau;
}
/*------------------------------------------------------------*/
stack pop_stack(stack st)
{
    if (is_empty_stack(st))
    {
        puts("  Nothing to free the stack is empty \n");
        exit(EXIT_FAILURE);
    }
    stackElement *temp = st->next;
    free(st);
    st = NULL;
    return temp;
}
/*------------------------------------------------------------*/
stack clear_stack(stack st)
{
    while (!is_empty_stack(st))
    {
        st = pop_stack(st);
    }
    return new_stack();
}
/*------------------------------------------------------------*/
void print_stack(stack st)
{
    if (is_empty_stack(st))
    {
        puts("    Nothing to free the stack is empty \n\n");
        return;
    }

    while (!is_empty_stack(st))
    {
        printf("  (%d) --> ", st->value);
        st = st->next;
    }
    printf("NULL\n");
}
/*------------------------------------------------------------*/
int top_stack(stack st)
{
    if (is_empty_stack(st))
    {
        printf("  The stack is empty \n\n");
        return -1;
    }
    return st->value;
}
/*------------------------------------------------------------*/
int length_stack(stack st)
{
    int rect = 0;
    while (!is_empty_stack(st))
    {
        rect++;
        st = st->next;
    }
    return rect;
}
/*------------------------------------------------------------*/
int lire(char *chaine, int longeur)
{
    char *pointeurEntree = NULL;
    if (fgets(chaine, longeur, stdin) != NULL)
    {
        pointeurEntree = strchr(chaine, '\n');
        if (pointeurEntree != NULL)
        {
            *pointeurEntree = '\0';
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
