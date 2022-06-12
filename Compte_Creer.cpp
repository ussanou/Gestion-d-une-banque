#include "head.h"

int Demander_choix();
void Ecrire(char *,Compte_att **,const int & , const int &);

void Ecrire(char nom[50],Compte_att **C,const int &n_cmpt , const int &id_clt)
{
    time_t now = time (0);
    ofstream Ecrire(nom , ios :: out);
    if(Ecrire)
    {
        for(int k = 0 ; k < n_cmpt ; k++)
        {
            cout << endl;
            for(int i = 0 ; i < 35 ; i++)cout << " ";
            for(int i = 0 ; i < 60 ; i++) cout << "_";
            cout << endl << endl;
            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "Entrer les informations du compte " << k + 1 << " : \n" ;


            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "ID COMPTE : ";
            cin >> (*C+k)->id_compte;
            Ecrire << (*C+k)->id_compte << endl;

            (*C+k)->id_client = id_clt;
            Ecrire << (*C+k)->id_client << endl;

            for(int i = 0 ; i < 45 ; i++) cout << " ";
            cout << "Solde : ";
            cin >> (*C+k)->solde;
            Ecrire << (*C+k)->solde << endl;


            if(k!=n_cmpt-1)
            {
                (*C+k)->Date_ouverture = new char [50];
                (*C+k)->Date_ouverture = ctime(&now);
                Ecrire << (*C+k)->Date_ouverture;
            }
            else
            {
                (*C+k)->Date_ouverture = new char [50];
                (*C+k)->Date_ouverture = ctime(&now);
                ///Pour prévenir le retour a la ligne.
                (*C+k)->Date_ouverture[strlen((*C+k)->Date_ouverture)-1]='\0';
                Ecrire << (*C+k)->Date_ouverture;
            }
        }
        Ecrire.close();
    }
    else
        cout << "Erreur lors d'écriture dans le fichier ";
}

int creer(char nom_fc[50],Compte_att** Cpt,Client_att *Clt,int &n_cpt,int &n_clt)
{
    int id_cl,i;
    cout << endl;
    for(int i = 0 ; i < 53 ; i++) cout << " ";
    cout << "L'Id Client : "  ;
    cin >> id_cl;

    for(i = 0 ; i < n_clt ; i++)
    {
        if(id_cl == Clt[i].id_client)
            break;
    }

    if(i!=n_clt)
        Ecrire(nom_fc,Cpt,n_cpt,Clt[i].id_client);

    else
    {
        for (int i = 0 ; i < 50 ; i++) cout << " ";
        cout << "Client introuvable.\n\n";
    }

    cout << "      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      ";

    return Demander_choix ();

}
