#include "arbre.h"

int main(int argc, char *argv[])
{
    Tree *arbre = join_tree(join_tree(new_tree(5), join_tree(new_tree(6), NULL, 4), 2), new_tree(3), 1); // arbre binaire normal

    Tree *arbre_recherche = new_tree(3); // arbre binaire de recherche
    tree_insertion_recherche(&arbre_recherche, 2);
    tree_insertion_recherche(&arbre_recherche, 5);
    tree_insertion_recherche(&arbre_recherche, 10);
    tree_insertion_recherche(&arbre_recherche, 4);

    // ARBRE DE RECHERCHE
    tree_insertion_recherche(&arbre_recherche, 7);

    printf("\n /*--------------------*/\n");
    print_tree_prefix(arbre_recherche);
    if (isEquilibre(arbre_recherche) > 0)
    {
        printf("ARBRE RECHERCE AVL \n");
    }
    else
        printf("ARBRE RECHERCE n'est pas  AVL \n");
    arbre_recherche = Equilibre_tree(arbre_recherche);
    printf("\n /*--------------------*/\n");
    print_tree_prefix(arbre_recherche);

    if (isEquilibre(arbre_recherche) > 0)
    {
        printf("ARBRE RECHERCE AVL \n");
    }
    else
        printf("ARBRE RECHERCE n'est pas  AVL \n");

    printf("\n /*--------------------*/\n");

    // ARBRE NORMAL

    print_tree_prefix(arbre);
    // pour la verification de l'equiliberage
    if (isEquilibre(arbre) > 0)
    {
        printf("ARBRE AVL \n");
    }
    else
        printf("ARBRE n'est pas  AVL \n");

    arbre = Equilibre_tree(arbre);
    print_tree_prefix(arbre);

    if (isEquilibre(arbre) > 0)
    {
        printf("ARBRE AVL \n");
    }
    else
        printf("ARBRE n'est pas  AVL \n");

    clean_tree(arbre_recherche);
    clean_tree(arbre);

    return EXIT_SUCCESS;
}