#include "pile.h"

int main(int argc, char *argv[])
{
    int contiue = 1, choix = 0, key = 0;
    /*--------------------------------*/
    stackElement *ma_pile = new_stack();

    while (contiue)
    {
        Color(4, 0);
        printf("  |------{MENU}------|\n");
        printf("  [1]-IS EMPTY STACK \n");
        printf("  [2]-PUSH STACK \n");
        printf("  [3]-POP STACK \n");
        printf("  [4]-TOP STACK \n");
        printf("  [5]-PRINT STACK \n");
        printf("  [6]-LENGTH STACK \n");
        printf("  [7]-CLEAR STACK \n");
        printf("  [8]-EXIT PROGRAMME \n");
        Color(5, 0);
        do
        {
            printf(" Enter your choice ??");
            choix = lirelong();
        } while (choix < 0 || choix > 8);
        switch (choix)
        {
        case 1:
            if (is_empty_stack(ma_pile))
                printf("  The stack is empty!!\n");
            else
                printf("  The stack has some elements !!\n");
            break;
        /*-------------------------*/
        case 2:
            printf("  enter the node value ??");
            key = lirelong();
            ma_pile = push_stack(ma_pile, key);
            key = 0;
            break;
        /*-------------------------*/
        case 3:
            ma_pile = pop_stack(ma_pile);
            break;
        /*-------------------------*/
        case 4:
            printf(" The first element of the stack is : (%d) \n", top_stack(ma_pile));
            break;
        /*-------------------------*/
        case 5:
            Color(1, 0);
            print_stack(ma_pile);
            break;
        /*-------------------------*/
        case 6:
            printf("  the length of the stack is  (%d) !!\n", length_stack(ma_pile));
            break;
        /*-------------------------*/
        case 7:
            ma_pile = clear_stack(ma_pile);
            break;
        /*-------------------------*/
        case 8:
            ma_pile = clear_stack(ma_pile);
            printf("  Goodbye !!!\n");
            contiue = 0;
            break;
        /*-------------------------*/
        default:
            printf(" invalid choice !!!\n");
            break;
        }
    }
    /*
     stackElement *ma_pile=new_stack();
     ma_pile=push_stack(ma_pile,3);
     ma_pile=push_stack(ma_pile,34);
     ma_pile=push_stack(ma_pile,56);
     ma_pile=push_stack(ma_pile,89);
     printf("la somme de la pile est (%d) \n",top_stack(ma_pile));
     printf("la longeur de la pile est (%d) \n",length_stack(ma_pile));

     print_stack(ma_pile);
     ma_pile=pop_stack(ma_pile);
     ma_pile=pop_stack(ma_pile);

     print_stack(ma_pile);
     ma_pile=clear_stack(ma_pile);
     print_stack(ma_pile);
     */

    return EXIT_SUCCESS;
}
