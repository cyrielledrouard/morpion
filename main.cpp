#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int numJoueur = 1, nombreCasesRemplies = 0;
    char grille[3][3];

    // Initialisation de la grille de jeu

    for (int i(0) ; i < 3 ; i++)
    {
        for (int j(0) ; j < 3; j++)
        {
            grille[i][j] = ' ';
        }
    }

    cout << "Bienvenue dans le jeu du Morpion!" << endl << endl;

    do
    {
        afficherGrille(grille);
        remplirGrille(grille, numJoueur);
        nombreCasesRemplies += 1;
        numJoueur = choixJoueur(numJoueur);
    }
    while(!partieGagnee(grille) && nombreCasesRemplies != 9);

    afficherGrille(grille);
    numJoueur = choixJoueur(numJoueur);

    if (partieGagnee(grille))
    {
        cout << "Bravo ! Joueur " << numJoueur << " gagne !" << endl;
    }
    else
    {
        cout << "Match nul !" << endl;
    }

    return 0;
}

