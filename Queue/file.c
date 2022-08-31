#include "file.h"

/*-------------------------------------------------------*/
Bool is_empty_queue(void)
{
    if (first == NULL && last == NULL)
        return true;
    return false;
}
/*-------------------------------------------------------*/
void push_queue(int x)
{
    queueElement *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL)
    {
        fprintf(stderr, "ERROR : probleme allocation \n");
        exit(EXIT_FAILURE);
    }
    nouveau->value = x;
    nouveau->next = NULL;
    if (is_empty_queue())
    {

        first = nouveau;
        last = nouveau;
    }
    else
    {
        last->next = nouveau;
        last = nouveau;
    }
    length++;
}
/*-------------------------------------------------------*/
void pop_queue(void)
{
    if (is_empty_queue())
    {
        puts("Nothing to free the queue is empty \n\n");
        exit(EXIT_FAILURE);
    }
    if (first == last)
    {
        free(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        queueElement *temp = first;
        first = first->next;
        free(temp);
        temp = NULL;
    }
    length--;
}
/*-------------------------------------------------------*/
int length_queue(void)
{

    return length;
}
/*-------------------------------------------------------*/
int first_queue(void)
{
    if (is_empty_queue())
        return 0;
    return first->value;
}
/*-------------------------------------------------------*/
int last_queue(void)
{
    if (is_empty_queue())
        return 0;
    return last->value;
}
/*-------------------------------------------------------*/
void print_queue(void)
{
    if (is_empty_queue())
    {
        printf("  Nothing to display the queue is empty \n");
        return;
    }
    queueElement *actuel = first;
    while (actuel != NULL)
    {
        printf(" (%d) --> ", actuel->value);
        actuel = actuel->next;
    }
    printf("NULL \n");
}
/*-------------------------------------------------------*/
void clear_queue(void)
{
    if (is_empty_queue())
    {
        printf("  Nothing to free the queue is empty \n\n");
        return;
    }

    while (!is_empty_queue())
        pop_queue();
}
/*-------------------------------------------------------*/
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
