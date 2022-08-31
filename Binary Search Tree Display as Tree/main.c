#include "arbre.h"

int main(int argc, char *argv[])
{
    Tree *arbre_recherche = NULL;


    int tab[] = {8, 3, 10, 1, 6,9, 7, 13,18,19,-6,8,4,5,6,7,3,4,5};
    int size = sizeof(tab) / sizeof(tab[0]);
    tree_insertion_tableaux(&arbre_recherche, tab, size);
    char **tab2 = traitement(arbre_recherche);

    size_t count = Tree_nb_elm(arbre_recherche);
    printf("\n\n\n");
    afficher_tab(tab2, count /1.8, count + (int)count / 2);
    clear_tab(tab2, count);
    printf("/*-----------------------------*/\n");
    //printf(" le max entre 1 et 10 est : %d \n", get_max(arbre_recherche, 1, 10));
    printf("/*-----------------------------*/\n");

    clean_tree(arbre_recherche);

    return EXIT_SUCCESS;
}