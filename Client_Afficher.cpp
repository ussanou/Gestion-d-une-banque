#include "head.h"

void affichage_char();

int afficher(char nom[50],int &n_client)
{
    for(int i = 0 ; i < 3 ; i++)cout << endl;
    for(int i = 0 ; i < 48 ; i++)cout << " ";
    cout << "Les informations des clients : \n\n";

    affichage_char();

    cout << "      | Id |         Nom          |        Prenom        |";
    cout << "          Profession            |             Num_tel            |";
    cout << endl;

    affichage_char();

    ifstream Lire(nom,ios :: in);
    if(Lire)
    {
        int id;
        char Nom[50],Prenom[50],Prof[50],Num[50];
        for(int i = 0 ; i < n_client ; i++)
        {
            Lire >> id;
            Lire >> Nom;
            Lire >> Prenom;
            Lire >> Prof;
            Lire >> Num;
            printf("      |%4d|%22s|%22s|%32s|%32s|",id,Nom,Prenom,Prof,Num);
            cout <<endl;
        }
    }
    Lire.close();


    affichage_char();

    cout << endl << endl;
    cout << "      1 | retour";
    for(int i = 0 ; i < 97 ; i++)cout << " ";
    cout << "Quitter | 2      ";

    return Demander_choix ();

}
void affichage_char()
{
    cout << "      +----+";
    for (int i = 0 ; i < 22 ; i++)cout <<"-";
    cout << "+";
    for (int i = 0 ; i < 22 ; i++)cout <<"-";
    cout << "+";
    for (int i = 0 ; i < 32 ; i++)cout <<"-";
    cout << "+";
    for (int i = 0 ; i < 32 ; i++)cout <<"-";
    cout << "+";
    cout << endl;
}
