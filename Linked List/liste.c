#include "liste.h"

/*----------------------------------------------------------*/
list new_list(void)
{
    return NULL;
}
/*----------------------------------------------------------*/
Bool is_empty_list(list li)
{
    if(li==NULL)
        return true;
    return false;
}
/*----------------------------------------------------------*/
int list_lenght(list li)
{
    int size=0;
    while(!is_empty_list(li))
    {
        size++;
        li=li->next;
    }
    return size;
}
/*----------------------------------------------------------*/
void print_list(list li)
{
    if(is_empty_list(li))
    {
        puts("Rien a affiche la list est vide \n\n");
        return;
    }
    while(!is_empty_list(li))
    {
      printf(" (%d) -->",li->value);
      li=li->next;
    }
    printf("NULL\n");
}
/*----------------------------------------------------------*/
list push_back_list(list li,int x)
{

    listElement *nouveau=malloc(sizeof(*nouveau));
    if(nouveau==NULL)
    {
        fprintf(stderr,"ERROR : probleme allocation \n\n");
        exit(EXIT_FAILURE);
    }
    nouveau->value=x;
    nouveau->next=NULL;
    if(is_empty_list(li))
    {
        return nouveau;
    }
    else
    {
        listElement *temp=li;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nouveau;
        return li;
    }
}
/*----------------------------------------------------------*/
list push_front_list(list li,int x)
{

    listElement *nouveau=malloc(sizeof(*nouveau));
    if(nouveau==NULL)
    {
        fprintf(stderr,"ERROR : probleme allocation \n\n");
        exit(EXIT_FAILURE);
    }
    nouveau->value=x;

    if(is_empty_list(li))
    {
        nouveau->next=NULL;
    }
    else
    {
        nouveau->next=li;
    }
    return nouveau;
}
/*----------------------------------------------------------*/
list pop_back_list(list li)
{
    if(is_empty_list(li))
    {
        puts("Rien a vider la list est vide \n");
        return new_list();
    }
    if(li->next==NULL)
    {
        free(li);
        li=NULL;
        return new_list();
    }

    else
        {
            listElement *temp=li;
            listElement *temp2=NULL;
            while(temp->next!=NULL)
            {
                temp2=temp;
                temp=temp->next;
            }
            temp2->next=NULL;
            free(temp);
            temp=NULL;
            return li;

        }


}
/*----------------------------------------------------------*/
list pop_front_list(list li)
{
    if(is_empty_list(li))
    {
        puts("Rien a vider la list est vide \n\n");
        return new_list();
    }
    if(li->next==NULL)
    {
        free(li);
        li=NULL;
        return new_list();
    }
    else
    {
        listElement *temp=li->next;
        free(li);
        li=NULL;
        return temp;
    }
}
/*----------------------------------------------------------*/
list clear_list(list li)
{
    while(!is_empty_list(li))
    {
        li=pop_back_list(li);
    }
    return new_list();
}
/*----------------------------------------------------------*/












