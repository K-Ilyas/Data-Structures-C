#include "chaine.h"

/*------------------------------------------------------------*/
Bool is_empty_stack(stack *st)
{
    if(st==NULL)
        return true;
    return false;
}
/*------------------------------------------------------------*/
void push_stack(stack **st,char caractere)
{
    stack *nouveau=malloc(sizeof(*nouveau));
    if(nouveau==NULL)
    {
        fprintf(stderr,"ERROR : probleme allocation \n");
        exit(EXIT_FAILURE);
    }
    nouveau->caractere=caractere;
    if(is_empty_stack(*st))
    {
        nouveau->next=NULL;
        *st=nouveau;
    }
    else
    {
        nouveau->next=*st;
        *st=nouveau;
    }

}
/*------------------------------------------------------------*/
char pop_stack(stack **st)
{

    if(is_empty_stack(*st))
    {
        puts("Rien a depiler la pile est vide \n");
        exit(EXIT_FAILURE);
    }
    char top=0;
    stack *temp=(*st)->next;
    top=(*st)->caractere;
    free(*st);
    *st=NULL;
    *st=temp;
    return top;
}
/*------------------------------------------------------------*/
void print_stack(stack *st)
{
    if(is_empty_stack(st))
    {
        puts("\nRien  affiche la pile est vide \n");
        return;
    }
    while(st!=NULL)
    {
        printf(" [%c]-",st->caractere);
        st=st->next;
    }
    printf("[NULL]\n");
}
/*------------------------------------------------------------*/
int lire(char *chaine,int longeur)
{
    char *positionEntree=NULL;
    if(fgets(chaine,longeur,stdin)!=NULL)
    {
        positionEntree=strchr(chaine,'\n');
        if(positionEntree!=NULL)
        {
            *positionEntree='\0';
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
    char C=0;
    while(C!='\n' && C!=EOF)
    {
        C=getchar();
    }
}
/*------------------------------------------------------------*/
void clear_stack(stack **st)
{
    while(!is_empty_stack(*st))
    {
        pop_stack(st);
    }
}
/*------------------------------------------------------------*/
Bool is_balanced_chaine(stack **st,char *chaine)
{
    int compt=0;
    char pop;
    for(compt=0; compt<strlen(chaine); compt++)
    {
        if(chaine[compt]=='(' || chaine[compt]=='[')
        {
            push_stack(st,chaine[compt]);
            printf("  push : | '%c' | \n",chaine[compt]);

        }
        else
        {
            if(is_empty_stack(*st))
            {
                return false;
            }
            pop=pop_stack(st);
            printf("  pop :  | '%c' | \n",pop);

            if((  pop==')' && chaine[compt]!='(' ) || (pop==']'&& chaine[compt]!='['  ) )
            {
                clear_stack(st);
                return false;
            }
        }
    }

    clear_stack(st);
    return true;
}
/*------------------------------------------------------------------------------*/
