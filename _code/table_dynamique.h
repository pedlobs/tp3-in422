typedef struct table_dynamique table_dynamique;

table_dynamique*
table_dynamique_vide();

int
table_dynamique_acces(table_dynamique *t, int index);

void
table_dynamique_insere(table_dynamique *t, int index, int valeur);

void
table_dynamique_libere(table_dynamique *t);


