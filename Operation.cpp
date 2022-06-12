#include "head.h"

int Demander_choix();

int operation(char *nom,Compte_att **C,int &n)
{
    int id_cpt;
    for(int i = 0 ; i < 3 ; i++)cout << endl;
    for(int i = 0 ; i < 55 ; i++)cout << " ";
    cout << "L'id compte : ";
    cin >> id_cpt;
    int k;
    for(k = 0 ; k < n ; k++)
    {
        if((*C+k)->id_compte==id_cpt)
            break;
    }
    cout << endl;
    if(k==n)
    {
        for(int i = 0 ; i < 55 ; i++)cout << " ";
        cout << "Compte introuvable";
    }

    else
    {
        int choix;
        float montant;
        do
        {
            for(int i = 0 ; i < 55 ; i++)cout << " " ;
            cout << "1 | Verser\n";
            for(int i = 0 ; i < 55 ; i++)cout << " ";
            cout << "2 | Tirer\n";
            cout << endl;
            for(int i = 0 ; i < 52 ; i++)cout << " ";
            cout << "Votre Choix : ";
            cin >> choix;
            cout << endl;
        }while(choix != 1 && choix !=2);
        cls;
        cout << endl << endl;
        if(choix == 1)
        {
            for (int i = 0 ; i < 46 ; i++)cout << " ";
            cout << "Montant a verser : ";
            cin >> montant;
            (*C+k)->solde += montant;
        }
        else
        {
            for (int i = 0 ; i < 46 ; i++)cout << " ";
            cout << "Montant a Tirer  : ";
            cin >> montant;
            (*C+k)->solde -= montant;
        }

        ofstream Ecrire(nom,ios::out);
        if(Ecrire)
        {
            for(int i = 0 ; i < n ; i++)
            {
                Ecrire << (*C+i)->id_compte << endl;
                Ecrire << (*C+i)->id_client << endl;
                Ecrire << (*C+i)->solde << endl;
                if(i != n-1)
                    Ecrire << (*C+i)->Date_ouverture << endl;
                else
                    Ecrire << (*C+i)->Date_ouverture;

            }
        }
        Ecrire.close();
    }
    cout << endl;

    cout << "      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      ";

    return Demander_choix ();
}
