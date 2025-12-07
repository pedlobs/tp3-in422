#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tgc.h"
#include "arbre.h"
#include "fonctions_arbres.h"
#include "liste_chainee.h"
#include "fonctions_listes.h"
#include "abr.h"
#include "table_dynamique.h"
#include "arbre_implicite.h"
#include "fonctions_arbres_implicites.h"


tgc_t gc;

void test(){
  // Arbre vide  
  arbre *vide = arbre_vide();
  arbre_affiche(vide);
  
  // Arbre example
  arbre *filho_esq = arbre_constructeur(5, arbre_vide(), arbre_vide());
  
  arbre *neto_esq_dir = arbre_constructeur(15, arbre_vide(), arbre_vide());
  arbre *neto_dir_dir = arbre_constructeur(30, arbre_vide(), arbre_vide());
  arbre *filho_dir = arbre_constructeur(20, neto_esq_dir, neto_dir_dir);

  arbre *raiz = arbre_constructeur(10, filho_esq, filho_dir);
  arbre_affiche(raiz);
 
  int taille = arbre_profondeur(raiz);
  printf("Taille: %d\n", taille);

  int n_elements = arbre_nombre_elements(raiz);
  printf("Nombre de elements: %d\n", n_elements);

  printf("Inorder: ");
  liste_affiche(arbre_elements(raiz));


  printf("Traversal: ");
  liste_affiche(preorder_arbre(raiz));

  arbre_source_c(raiz);
  
  printf("\n\nÉtape 2:\n\n");

  // Binary search tree
  arbre *n1  = arbre_constructeur(1,  arbre_vide(), arbre_vide());
  arbre *n4  = arbre_constructeur(4,  arbre_vide(), arbre_vide());
  arbre *n7  = arbre_constructeur(7,  arbre_vide(), arbre_vide());
  arbre *n13 = arbre_constructeur(13, arbre_vide(), arbre_vide());
  arbre *n6  = arbre_constructeur(6, n4, n7);
  arbre *n14 = arbre_constructeur(14, n13, arbre_vide());
  arbre *n3  = arbre_constructeur(3, n1, n6);
  arbre *n10 = arbre_constructeur(10, arbre_vide(), n14);
  arbre *root_abr = arbre_constructeur(8, n3, n10);

  arbre_affiche(root_abr);

  printf("Is there a 6 in the tree? %d\n", abr_cherche(root_abr, 6));

  printf("Is there a 2 in the tree? %d\n", abr_cherche(root_abr, 2));

  printf("\n\nTeste abr_insere(): \n");
  arbre_affiche(abr_insere(root_abr, 2));

  printf("abr_max: %d\n", abr_max(root_abr));

  printf("\n\nTeste abr_retire():\n");
  arbre_affiche(abr_retire(root_abr, 6));

  printf("\n\n Étape 3:\n\n");

  srand(time(NULL));

  int num_personnes[11] = {20,21,22,23,24,25,26,27,28,29,30};
  double y_data[11];

  for (int i = 0;i<11;i++) {
    int cont = 0;
    for (int j = 0; j<10000; j++) {
      
      if (tentative(num_personnes[i])) {
        cont++;
      }

    }
    double p = cont / 10000.0;
    y_data[i] = p;
  }

  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

  if (gnuplotPipe == NULL) {
    printf("Gnuplot not found \n");
    exit(1);
  }

  fprintf(gnuplotPipe, "set terminal pngcairo size 800,600 enhanced font 'Verdana,10'\n");
  fprintf(gnuplotPipe, "set output 'plot_etape3.png'\n"); 
  
  fprintf(gnuplotPipe, "set title 'Étape 3 - TP3 IN422'\n");
  fprintf(gnuplotPipe, "set xlabel 'Nombre de Personnes (N)'\n");
  fprintf(gnuplotPipe, "set ylabel 'Probability'\n");
  
  fprintf(gnuplotPipe, "set grid\n");
  fprintf(gnuplotPipe, "set yrange [0:1]\n");
  fprintf(gnuplotPipe, "set xrange [20:30]\n");
  
  fprintf(gnuplotPipe, "plot '-' with linespoints lw 2 pt 7 ps 1.5 title 'Probability'\n");

  for (int i = 0; i < 11; i++) {
    fprintf(gnuplotPipe, "%d %f\n", num_personnes[i], y_data[i]);
  }

  fprintf(gnuplotPipe, "e\n"); 
  fflush(gnuplotPipe);
  pclose(gnuplotPipe); 

  printf("Data plotted on 'plot_etape3.png'.\n");


  printf("\n\n Étape 4:\n\n");


  table_dynamique *F = table_dynamique_vide();

  int n = 2;

  table_dynamique_insere(F, 0, 0);
  table_dynamique_insere(F, 1, 1);

  while (true) {
    table_dynamique_insere(
      F,
      n,
      table_dynamique_acces(F, n-1) + table_dynamique_acces(F, n-2)
    );

    if ((table_dynamique_acces(F,n)) > 1000000000) break;
    
    n++;
  }
  printf("Indice = %d\n", n);

  table_dynamique_libere(F);
  

  printf("\n\n Étape 5:\n\n");

  abi *arbre_i = abi_vide();

  abi_ajoute(arbre_i, 0);
  abi_ajoute(arbre_i, 1);
  abi_ajoute(arbre_i, 2);
  abi_ajoute(arbre_i, 3);

  printf("ABI: ");
  printf("{");
    
  for (int i = 0; i <= abi_index_dernier(arbre_i); i++) {
    printf("%d, ", abi_acces(arbre_i,i));  
  }
  printf("}\n");

  arbre *abi_as_an_arbre = abi_vers_arbre(arbre_i);
  printf("Arbre: \n");
  arbre_affiche(abi_as_an_arbre);

  abi_libere(arbre_i);
}

int main(int argc, char **argv) {
  tgc_start(&gc, &argc);
  
  test();
  
  tgc_stop(&gc);
  
  return 0;
}
