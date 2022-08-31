#include "listed.h"

int main(int argc, char *argv[])
{

    int choix = 0, continuer = 1, key, after, before, recherche;
    dlist ma_list = new_dlist();
    while (continuer)
    {
        Color(4, 0);
        printf("  |------{MENU}--------|  \n");
        printf("  [1]- IS EMPTY LIST \n");
        printf("  [2]- PUSH FRONT \n");
        printf("  [3]- PUSH BACK \n");
        printf("  [4]- POP FRONT   \n");
        printf("  [5]- POP BACK  \n");
        printf("  [6]- TOP LIST \n");
        printf("  [7]- BACK LIST  \n");
        printf("  [8]- PRINT LIST \n");
        printf("  [9]- PUSH AFTER \n");
        printf("  [10]- PUSH BEFORE \n");
        printf("  [11]- FIND NODE \n");
        printf("  [12]- DELETE NODE \n");
        printf("  [13]- TRIEE LIST \n");
        printf("  [14]- CLEAR LIST \n");
        printf("  [15]- REVERSE LIST \n");
        printf("  [16]- DELETE NODE  \n");
        printf("  [17]- EXIT PROGRAMME \n");
        Color(5, 0);
        do
        {
            printf("  enter your choice ?? ");
            choix = lirelong();
        } while (choix < 0 && choix > 12);
        Color(1, 0);
        switch (choix)
        {
        /*----------------------------------------------------*/
        case 1:
            if (is_empty_dlist(ma_list))
                printf("  The list is empty \n");
            else
                printf(" The list have some elements \n");
            break;
        /*----------------------------------------------------*/
        case 2:
            printf("  enter the node value?? ");
            key = lirelong();
            ma_list = push_front_dlist(ma_list, key);
            break;
        /*----------------------------------------------------*/
        case 3:
            printf("  enter the node value?? ");
            key = lirelong();
            ma_list = push_back_dlist(ma_list, key);
            key = 0;
            break;
        /*----------------------------------------------------*/
        case 4:
            ma_list = pop_front_dlist(ma_list);
            break;
        /*----------------------------------------------------*/
        case 5:
            ma_list = pop_back_dlist(ma_list);
            break;
        /*----------------------------------------------------*/
        case 6:
            printf("  The first element of the list is: [%d] \n", first_dlist(ma_list));
            break;
        /*----------------------------------------------------*/
        case 7:
            printf("  The last element of the list is : [%d] \n", last_dlist(ma_list));
            break;
        /*----------------------------------------------------*/
        case 8:
            print_dlist(ma_list);
            break;
        /*----------------------------------------------------*/
        case 9:
            printf("  enter the value of the node?? ");
            key = lirelong();
            printf("  enter the value of the previous node ?? ");
            before = lirelong();
            ma_list = push_after_dlist(ma_list, before, key);
            before = 0;
            break;
        /*----------------------------------------------------*/
        case 10:
            printf("   enter the value of the node?? ");
            key = lirelong();
            printf("   enter the value of the next node ?? ");
            after = lirelong();
            ma_list = push_before_dlist(ma_list, after, key);
            after = 0;
            break;
        /*----------------------------------------------------*/
        case 11:
            printf("  enter the value of the node??");
            recherche = lirelong();
            if (find_node_dlist(ma_list, recherche))
                printf("  [%d] exist in the list \n");
            else
                printf("  [%d] not exist in the list \n");
            recherche = 0;
            break;
        /*----------------------------------------------------*/
        case 12:
            printf("  enter the value of the node to delete ??");
            key = lirelong();
            ma_list = delete_node_dlist(ma_list, key);
            key = 0;
            break;
        /*----------------------------------------------------*/
        case 13:
            ma_list = triee_dlist(ma_list);
            break;
        /*----------------------------------------------------*/
        case 14:
            ma_list = clear_dlist(ma_list);
            break;
        /*----------------------------------------------------*/
        case 15:
            ma_list = reverse_dlist(ma_list);
            break;
        /*----------------------------------------------------*/
        case 16:
            printf("   enter the value of the node to delete ??");
            key = lirelong();
            ma_list = delete_node_dlist_all(ma_list, key);
            key = 0;
            break;
        /*----------------------------------------------------*/
        case 17:
            ma_list = clear_dlist(ma_list);
            printf("  Goodbye !!! \n");
            continuer = 0;
            break;
        /*----------------------------------------------------*/
        default:
            printf("  invalid choice !!!\n");

            break;
        }
    }

    /*  int key=12;

    dlist ma_list=new_dlist();

   ma_list=push_back_dlist(ma_list,12);
   ma_list=push_front_dlist(ma_list,45);
   ma_list=push_back_dlist(ma_list,67);
   ma_list=push_front_dlist(ma_list,17);
   ma_list=push_back_dlist(ma_list,90);
   ma_list=push_front_dlist(ma_list,24);
   if(find_node_dlist(ma_list,key))
    printf("\n[%d] existe dans la list \n",key);
   else
    printf("\n[%d] nexiste pas dans la list \n",key);

   print_dlist(ma_list);
   ma_list=push_before_dlist(ma_list,90,10);
   ma_list=push_after_dlist(ma_list,17,34);
   ma_list=delete_node_dlist(ma_list,12);

   print_dlist(ma_list);
   ma_list=clear_dlist(ma_list);
   print_dlist(ma_list);
  */

    return EXIT_SUCCESS;
}
