#include "head.h"

int Demander_choix();
void affichage_char();
int chercher(char nom[50],Client_att *C,const int &n)
{
    int id_cher,k;
    for (int i = 0 ; i < 3 ; i++)cout << endl;
    for (int i = 0 ; i < 40 ; i++) cout << " ";
    cout << "Nom du fichier ou la recherche va se faire : " << nom << endl << endl;
    for (int i = 0 ; i < 50 ; i++) cout << " ";
    cout << "Id de client a Chercher : ";
    cin >> id_cher;
    cout << endl;
    for(k = 0 ; k < n ; k++)
    {
        if(C[k].id_client==id_cher)
            break;
    }

    if(k==n)
    {
        for(int i = 0 ; i < 50 ; i++)
        cout << "Client introuvable.";
    }
    else
    {
        affichage_char();

        cout << "      | Id |         Nom          |        Prenom        |";
        cout << "          Profession            |             Num_tel            |";
        cout << endl;

        affichage_char();

        printf("      |%4d|%22s|%22s|%32s|%32s|",C[k].id_client,C[k].nom,C[k].prenom,C[k].profession,C[k].num_tel);
        affichage_char();

        cout << endl << endl;
        for(int i = 0 ; i<50 ; )
        cout << "Ces infos sont dans la ligne : " << (k*5)+1 << endl;
    }

    cout << "#      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      #";

    return Demander_choix ();
}
