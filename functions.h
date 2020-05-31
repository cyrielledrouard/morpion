#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void afficherGrille(char grille[3][3]);
void remplirGrille(char grille[3][3], int numJoueur);
bool coordonneesValides(int ligne, int colonne, char grille[3][3]);
bool partieGagnee(char grille[3][3]);
int choixJoueur(int numJoueur);

#endif // FUNCTIONS_H_INCLUDED
