#include "file.h"

int main(int argc, char *argv[])
{

  int contiue = 1, choix = 0, key = 0;
  /*--------------------------------*/

  while (contiue)
  {
    Color(9, 0);
    printf("  |------{MENU}------|\n");
    printf("  [1]-IS EMPTY STACK \n");
    printf("  [2]-PUSH QUEUE \n");
    printf("  [3]-POP QUEUE\n");
    printf("  [4]-TOP QUEUE \n");
    printf("  [5]-LAST QUEUE \n");
    printf("  [6]-PRINT QUEUE \n");
    printf("  [7]-LENGTH QUEUE \n");
    printf("  [8]-CLEAR QUEUE \n");
    printf("  [9]-EXIT PROGRAMME \n");
    Color(12, 0);
    do
    {
      printf("  enter your choice??");
      choix = lirelong();
    } while (choix < 0 || choix > 9);
    switch (choix)
    {
    case 1:
      if (is_empty_queue())
        printf("  The queue is empty!!\n");
      else
        printf("  The queue has some elements !!\n");
      break;
    /*-------------------------*/
    case 2:
      printf("  enter the node value ??");
      key = lirelong();
      push_queue(key);
      key = 0;
      break;
    /*-------------------------*/
    case 3:
      pop_queue();
      break;
    /*-------------------------*/
    case 4:
      printf("  The first element of the queue is: (%d) \n", first_queue());

      break;
    /*-------------------------*/
    case 5:
      printf("  The last element of the queue is: : (%d) \n", last_queue());
      break;
    /*-------------------------*/
    case 6:
      Color(10, 0);
      print_queue();
      break;
    /*-------------------------*/
    case 7:
      printf("  The length of the queue is (%d) !!\n", length_queue());
      break;
    /*-------------------------*/
    case 8:
      clear_queue();
      break;
    /*-------------------------*/
    case 9:
      clear_queue();
      printf("  Goodbye !!!\n");
      contiue = 0;
      break;
    /*-------------------------*/
    default:
      printf("  invalid choice !!!\n");
      break;
    }
  }

  /*
    push_queue(4);
    push_queue(5);
    push_queue(2);
    push_queue(7);
    push_queue(12);
    print_queue();
    clear_queue();
    print_queue();
 */

  return EXIT_SUCCESS;
}
