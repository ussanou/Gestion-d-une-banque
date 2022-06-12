#include "head.h"

int supprimer(char nom[50],Compte_att **C ,int &n)
{

    int id_supp,k;

    for (int i = 0 ; i < 3 ; i++)cout << endl;
    for (int i = 0 ; i < 35 ; i++) cout << " ";
    cout << "Nom du fichier ou la suppression va t étre effectuer : " << nom << endl << endl;
    for (int i = 0 ; i < 45 ; i++) cout << " ";
    cout << "Id de compte a fermer : ";
    cin >> id_supp;

    for(k = 0 ; k < n ; k++)
    {
        if(id_supp == (*C+k)->id_compte)
            break;
    }


    if(n==1)
    {
        ofstream Ecrire(nom , ios :: out);
        Ecrire << "Aucun compte n'est ouvert.";
        Ecrire.close();
        n--;
    }
    else
    {
        for(int i = k ; i < n - 1 ; i++)
        {
            (*C+i)->id_client = (*C+i+1)->id_client;
            (*C+i)->id_compte = (*C+i+1)->id_compte;
            (*C+i)->solde = (*C+i+1)->solde;
            strcpy((*C+i)->Date_ouverture,(*C+i+1)->Date_ouverture);
        }
        n--;

        ofstream Ecrire(nom , ios :: out);
        for(int i = 0 ; i < n ; i++)
        {
            Ecrire << (*C+i)->id_compte << endl;
            Ecrire << (*C+i)->id_client << endl;
            Ecrire << (*C+i)->solde << endl;

            if(i!=n-1)
                Ecrire << (*C+i)->Date_ouverture << endl;
            else
                Ecrire << (*C+i)->Date_ouverture ;
        }
        Ecrire.close();
    }



    cout << "#      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      #";

    return Demander_choix ();

}
