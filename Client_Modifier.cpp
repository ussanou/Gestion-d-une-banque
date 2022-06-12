#include "head.h"

int Demander_choix();

int modifier(char nom[50],Client_att **C,int &n)
{
    int id_modf,k;
    for (int i = 0 ; i < 3 ; i++)cout << endl;
    for (int i = 0 ; i < 36 ; i++)cout << " ";
    cout << "Nom du fichier ou la modification va se faire : " << nom << endl << endl;
    for (int i = 0 ; i < 50 ; i++) cout << " ";
    cout << "Id de client a Modifier : ";
    cin >> id_modf;

    for(k = 0 ; k < n ; k++)
    {
        if(id_modf == (*C+k)->id_client)
            break;
    }

    if(k == n)
    {
        cout << endl;
        for(int i = 0 ;i < 55 ; i++)cout << " ";
        cout << "Client introuvable " << endl;
        cout << "      1 | retour";
        for(int i = 0 ; i < 100 ; i++)cout << " ";
        cout << "Quitter | 2      ";
        return Demander_choix ();
    }
    else
    {
        cout << endl;
        for(int i = 0 ; i < 35 ; i++)cout << " ";
        for(int i = 0 ; i < 60 ; i++) cout << "_";
        cout << endl << endl;
        for(int i = 0 ; i < 40 ; i++) cout << " ";
        cout << "Entrer les nouveaux informations du client " << k + 1 << " : \n" ;

        for(int i = 0 ; i < 45 ; i++) cout << " ";
        cout << "ID : ";
        cin >> (*C+k)->id_client;

        for(int i = 0 ; i < 45 ; i++) cout << " ";
        cout << "Nom : ";(*C+k)->nom = new char [30];
        cin >> (*C+k)->nom;

        for(int i = 0 ; i < 45 ; i++) cout << " ";
        cout << "Prenom : ";(*C+k)->prenom = new char [30];
        cin >> (*C+k)->prenom;

        for(int i = 0 ; i < 45 ; i++) cout << " ";
        cout << "profession : ";(*C+k)->profession = new char [50];
        cin >> (*C+k)->profession;

        for(int i = 0 ; i < 45 ; i++) cout << " ";
        cout << "Num_tel : ";(*C+k)->num_tel = new char [20];
        cin >> (*C+k)->num_tel;
        ofstream Ecrire(nom,ios::out);

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


    cout << endl;
    cout << "      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      ";

    return Demander_choix ();
}
