#include "arbre.h"




int main(int argc,char *argv[])
{
    Tree *arbre=join_tree(join_tree(new_tree(4),new_tree(5),2),join_tree(new_tree(6),new_tree(7),3),1);

     print_postefixe_tree(arbre);
     clear_tree(arbre);



     return EXIT_SUCCESS;
}
