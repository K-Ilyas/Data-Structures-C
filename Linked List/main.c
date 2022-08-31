#include "liste.h"

int main(int argc, char *argv[])
{
   listElement *ma_list = new_list();
   /*------------------------------------------*/
   ma_list = push_front_list(ma_list, 45);
   ma_list = push_front_list(ma_list, 4);
   ma_list = push_back_list(ma_list, 89);
   ma_list = push_front_list(ma_list, 34);
   ma_list = push_back_list(ma_list, 12);
   /*------------------------------------------*/
   print_list(ma_list);
   ma_list = pop_front_list(ma_list);
   ma_list = pop_back_list(ma_list);
   /*------------------------------------------*/
   print_list(ma_list);
   ma_list = clear_list(ma_list);
   print_list(ma_list);

   return EXIT_SUCCESS;
}
