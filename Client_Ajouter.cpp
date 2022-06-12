#include "head.h"

int Demander_choix();
void Ecrire(char *,Client_att **,int &);

void Ecrire(char nom[50],Client_att **C,int &n)
{
    ofstream Ecrire(nom , ios :: out);
    if(Ecrire)
    {
        int k;
        for(k = 0 ; k < n ; k++)
        {
            cout << endl;
            for(int i = 0 ; i < 35 ; i++)cout << " ";
            for(int i = 0 ; i < 60 ; i++) cout << "_";
            cout << endl << endl;
            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "Entrer les informations du client " << k + 1 << " : \n" ;

            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "ID         : ";
            cin >> (*C+k)->id_client;
            Ecrire << (*C+k)->id_client << endl;

            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "Nom        : ";(*C+k)->nom = new char [30];
            cin >> (*C+k)->nom;
            Ecrire << (*C+k)->nom << endl;

            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "Prenom     : ";(*C+k)->prenom = new char [30];
            cin >> (*C+k)->prenom;
            Ecrire << (*C+k)->prenom << endl;

            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "profession : ";(*C+k)->profession = new char [50];
            cin >> (*C+k)->profession;
            Ecrire << (*C+k)->profession << endl;

            if(k!=n-1)
            {
                for(int i = 0 ; i < 45 ; i++) cout << " ";
                cout << "Num_tel    : ";(*C+k)->num_tel = new char [20];
                cin >> (*C+k)->num_tel;
                Ecrire << (*C+k)->num_tel << endl;
            }
            else
            {
                for(int i = 0 ; i < 45 ; i++) cout << " ";
                cout << "Num_tel    : ";(*C+k)->num_tel = new char [20];
                cin >> (*C+k)->num_tel;
                Ecrire << (*C+k)->num_tel;
            }
        }
        Ecrire.close();
    }
    else
        cout << "Erreur lors d'écriture dans le fichier ";

}

int ajouter(char nom[50],Client_att **C,int &n)
{

    Ecrire(nom,C,n);
    cout << "      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      ";

    return Demander_choix ();
}
