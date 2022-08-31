#include "chaine.h"

int main(int argc, char *argv[])
{
    char pop = 0;
    stack *st = NULL;
    char chaine[20] = {0};
    printf("  enter the string??");
    lire(chaine, 10);
    if (is_balanced_chaine(&st, chaine))
        printf("  The string is blanced !!!\n");
    else
        printf("  The string is not blanced !!!\n");
    clear_stack(&st);
    print_stack(st);
    return EXIT_SUCCESS;
}
