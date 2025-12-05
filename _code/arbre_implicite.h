typedef struct arbre_binaire_complet_implicite abi;

/* Structure de données implémentant les arbres binaires sous forme implicite.
   Les valeurs de l'arbre sont rangées dans un tableau, fourni ici par la structure
   table_dynamique. Les éléments de l'arbre sont repérés par leur index.
   La manipulation des indices est transparente pour l'utilisateur du module. */

abi*
abi_vide();

int
abi_est_vide(abi *a);

int
abi_acces(abi *a, int index);

void
abi_ecrase_racine(abi *a, int valeur);

// ajoute un élément "en fin"
void
abi_ajoute(abi *a, int valeur);

// retire le "dernier" élément
int
abi_retire(abi* a);

void
abi_echange_elements(abi *a, int i, int j);

int
abi_racine();

int
abi_est_racine(int index);

int
abi_index_dernier(abi *a);

int
abi_fils_gauche(int index);

int
abi_fils_droit(int index);

int
abi_parent(int index);

void
abi_libere(abi *a);

