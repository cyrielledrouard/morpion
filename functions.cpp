#include <iostream>
#include "functions.h"

using namespace std;

// Affichage grille de jeu
void afficherGrille(char grille[3][3])
{
    cout << endl;

    for (int i(0) ; i < 3 ; i++)
    {
        cout << " ";

        for (int j(0) ; j < 3 ; j++)
        {
            cout << grille[i][j];

            if (j != 2)
            {
                cout << " | ";
            }
        }
        cout << endl;

        if (i != 2)
            {
                cout << "-----------" << endl;
            }
    }
    cout << endl;
}


// Remplissage grille
void remplirGrille(char grille[3][3], int numJoueur)
{
    int numLigne = 1, numColonne = 1;
    do
    {   cout << "Joueur " << numJoueur << " a toi de jouer !" << endl;
        cout << "Veuillez entrer le numero de la ligne" << endl;
        cin >> numLigne;
        cout << "Veuillez entrer le numero de la colonne" << endl;
        cin >> numColonne;
    }
    while(!coordonneesValides(numLigne, numColonne, grille));

    if (numJoueur == 1)
    {
        grille[numLigne - 1][numColonne - 1] = 'x';
    }
    else
    {
        grille[numLigne - 1][numColonne - 1] = 'o';
    }

}


// Vérification des coordonnées entrées par le joueur
bool coordonneesValides(int ligne, int colonne, char grille[3][3])
{
    if (ligne >= 1 && ligne <= 3 && colonne >=1 && colonne <=3)
    {
        if (grille[ligne - 1][colonne - 1] != ' ')
        {
            cout << "Cette case est deja remplie !" << endl;
        }
        else
        {
            return true;
        }
    }
    else
    {
       cout << "Les valeurs entrees ne sont pas correctes. Elles doivent etres comprises entre 1 et 3." << endl;
    }
    return false;
}


// Vérification si la partie est gagnée
bool partieGagnee(char grille[3][3])
{
    for (int i(0); i < 3; i++)
    {
        if (grille[i][0] == grille[i][1] && grille[i][0] == grille[i][2] && grille[i][0] != ' ' ||
            grille[0][i] == grille [1][i] && grille[0][i] == grille[2][i] && grille[0][i] != ' ')

        {
         return true;
        }
    }

    if (grille[0][0] == grille[1][1] && grille[0][0] == grille[2][2] && grille[0][0] != ' ' ||
        grille[0][2] == grille[1][1] && grille[0][2] == grille[2][0] && grille[0][2] != ' ')
    {
        return true;
    }

    return false;
}

int choixJoueur(int numJoueur)
{
    if (numJoueur == 1)
        {
            numJoueur = 2;
        }
        else
        {
            numJoueur = 1;
        }
    return numJoueur;
}
