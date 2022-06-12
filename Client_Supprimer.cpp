#include "head.h"

int Demander_choix();
int ajouter (char *,Client_att *,int &);
void Ecrire(char *,Client_att **,int &);

int supprimer(char nom[50],Client_att **C,int &n)
{
    int id_supp,k;

    for (int i = 0 ; i < 3 ; i++)cout << endl;
    for (int i = 0 ; i < 35 ; i++) cout << " ";
    cout << "Nom du fichier ou la suppression va t étre effectuer : " << nom << endl << endl;
    for (int i = 0 ; i < 45 ; i++) cout << " ";
    cout << "Id de client a supprimer : ";
    cin >> id_supp;

    for(k = 0 ; k < n ; k++)
    {
        if(id_supp == (*C+k)->id_client)
            break;
    }


    if(k == n)
    {
        for(int i = 0 ; i  < 50 ; i++)cout << " ";
        cout << "Client introuvable.";
    }
    else
    {
        delete [](*C+k)->nom;
        delete [](*C+k)->prenom;
        delete [](*C+k)->profession;
        delete [](*C+k)->num_tel;

        if(n!=1)
        {
            for(int i = k ; i < n - 1 ; i++)
            {
                (*C+i)->id_client = (*C+i+1)->id_client;
                strcpy((*C+i)->nom,(*C+i+1)->nom);
                strcpy((*C+i)->prenom,(*C+i+1)->prenom);
                strcpy((*C+i)->profession,(*C+i+1)->profession);
                strcpy((*C+i)->num_tel,(*C+i+1)->num_tel);
            }
            n--;

            ofstream Ecrire(nom , ios :: out);
            for(int i = 0 ; i < n ; i++)
            {
                Ecrire << (*C+i)->id_client << endl;
                Ecrire << (*C+i)->nom << endl;
                Ecrire << (*C+i)->prenom << endl;
                Ecrire << (*C+i)->profession << endl;
                if(i!=n-1)
                    Ecrire << (*C+i)->num_tel << endl;
                else
                    Ecrire << (*C+i)->num_tel;
            }
            Ecrire.close();
        }
        else
        {
            n--;
            ofstream Ecrire(nom,ios::out);
            Ecrire << "Les infos ont été supprimer.";
            Ecrire.close();
        }
    }



    cout << "#      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      #";

    return Demander_choix ();
}
