CC=clang -Wall -g
TARGETS=tp3_teste

all: $(TARGETS)

###
# Compilation
###

# Modules ressources
fonctions_arbres_implicites.o: fonctions_arbres_implicites.h fonctions_arbres_implicites.c arbre.h
	$(CC) -c fonctions_arbres_implicites.c

tgc.o: tgc.h tgc.c
	$(CC) -c tgc.c

liste_chainee.o: liste_chainee.h liste_chainee.c tgc.h
	$(CC) -c liste_chainee.c

fonctions_listes.o: liste_chainee.h fonctions_listes.h fonctions_listes.c tgc.h
	$(CC) -c fonctions_listes.c

arbre.o: arbre.h arbre.c tgc.h
	$(CC) -c arbre.c

fonctions_arbres.o: arbre.h fonctions_arbres.h fonctions_arbres.c tgc.h
	$(CC) -c fonctions_arbres.c

abr.o: abr.h abr.c tgc.h arbre.h fonctions_arbres.h
	$(CC) -c abr.c

utilitaires.o: utilitaires.h utilitaires.c
	$(CC) -c utilitaires.c

table_dynamique.o: table_dynamique.h table_dynamique.c utilitaires.h
	$(CC) -c table_dynamique.c

arbre_implicite.o: arbre_implicite.h arbre_implicite.c table_dynamique.h utilitaires.h
	$(CC) -c arbre_implicite.c

tas.o: tas.h tas.c arbre_implicite.h table_dynamique.h utilitaires.h
	$(CC) -c tas.c

main.o: main.c tgc.h arbre.h fonctions_arbres.h liste_chainee.h fonctions_listes.h
	$(CC) -c main.c

###
# Edition de liens
###

tp3_teste: main.o tgc.o liste_chainee.o fonctions_listes.o arbre.o fonctions_arbres.o abr.o utilitaires.o table_dynamique.o arbre_implicite.o tas.o fonctions_arbres_implicites.o
	$(CC) -o tp3_teste main.o tgc.o liste_chainee.o fonctions_listes.o arbre.o fonctions_arbres.o abr.o utilitaires.o table_dynamique.o arbre_implicite.o tas.o fonctions_arbres_implicites.o

clean:
	rm -f $(TARGETS) *.o
