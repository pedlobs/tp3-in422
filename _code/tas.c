#include "tas.h"
#include "arbre_implicite.h"

tas*
tas_vide()
{ return abi_vide(); }

int
tas_est_vide(tas *t)
{ return abi_est_vide(t); }

// Retourne 0 si le descendant existe, et s'il est plus petit que le noeud courant;
// retourne 1 dans tous les autres cas.
int
tas_verifie_descendant(tas *t, int courant, int enfant)
{
  if (enfant > abi_index_dernier(t))  // si l'enfant est un index hors du ras, retourner 1.
    return 1;
  return (abi_acces(t, courant) <= abi_acces(t, enfant));
}

// void
// tas_affiche(tas *t)
// { abi_affiche(t); }

void
tas_redescends(tas *t, int index)
{
  int i_fg, i_fd, v_dr, e;

  i_fg = abi_fils_gauche(index);
  i_fd = abi_fils_droit(index);

  v_dr = tas_verifie_descendant(t, index, i_fd);

  if (tas_verifie_descendant(t, index, i_fg))
  {
    if (!v_dr)
    {
      abi_echange_elements(t, index, i_fd);
      return tas_redescends(t, i_fd);
    }
  }
  else
  {
    if (v_dr)
    {
      abi_echange_elements(t, index, i_fg);
      return tas_redescends(t, i_fg);
    }
    else
    {
      if (abi_acces(t, i_fg) <= abi_acces(t, i_fd))
        e = i_fg;
      else
        e = i_fd;
      abi_echange_elements(t, index, e);
      return tas_redescends(t, e);
    }
  }
}

int
tas_min(tas *t)
{ return abi_acces(t, abi_racine()); }

void
tas_libere(tas *t)
{ abi_libere(t); }
