#include "head.h"

int creer(char *,Compte_att**,Client_att *,int &,int &);
int consulter(char *,int &);
int supprimer(char *,Compte_att **,int &);

int Demander_choix();

int compte(char nom_fc[50],Client_att *CLIENTS,Compte_att **COMPTES,int &n_client,int &n_compte)
{
    int choix,option;
    time_t now = time(0);
    char *temps = ctime(&now);

    setlocale(LC_CTYPE,"fra");

    do
    {
        cls;
        for (int l = 0 ; l < 11 ; l++)
        {
            switch (l)
            {

            case 0 :
                {
                    for (int i = 0 ; i < 135 ; i++)cout << "#";
                }
                break;

            case 2 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 49 ; i++)cout << " ";
                    cout << temps;
                }
                break;


            case 4 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "1 | Créer un compte";
                    for(int i = 0 ; i < 64 ; i++)cout << " ";
                    cout << "#";
                }
                break;
            case 5 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "2 | Consulter le solde ";
                    for(int i = 0 ; i < 60 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 6 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "3 | Supprimer un compte";
                    for(int i = 0 ; i < 60 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 7 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "4 | Retour";
                    for(int i = 0 ; i < 73 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 8 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "5 | Quitter";
                    for(int i = 0 ; i < 72 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 10 :
                {
                    for (int i = 0 ; i < 135 ; i++)cout << "#";
                }
                break;
            default :
                {
                    cout << "#";
                    for(int i = 0 ; i < 133 ; i++)cout << " ";
                    cout << "#";
                }
            }
        }
        option = Demander_choix();
    }while (option<=0 || option>5);


    int choixx = 1;
    switch (option)
    {
    case 1 :
        {
            cls;
            for (int i = 0 ; i < 3 ; i++)cout << endl;
            for (int i = 0 ; i < 35 ; i++)cout << " ";
            cout << "Nom du fichier ou les informations seront enregistrer : ";
            cin >> nom_fc;
            cout << endl << endl;

            for (int i = 0 ; i < 48 ; i++)cout << " ";
            cout << "Nombre des comptes a créer : ";
            cin >> n_compte;
            *COMPTES = new Compte_att [n_compte];
            choixx = creer(nom_fc,COMPTES,CLIENTS,n_compte,n_client);
        }
        break;
    case 2 :
        {
            if(n_compte==0) break;
            cls;
            choixx = consulter(nom_fc,n_compte);
        }
        break;
    case 3 :
        {
            if(n_compte==0) break;
            cls;
            choixx = supprimer(nom_fc,COMPTES,n_compte);
        }
        break;
    case 4 :
        {
            return 1;
        }
        break;
    case 5 :
        {
            return 0;
        }
    }

    if(choixx == 1)
    {
        choix = compte(nom_fc,CLIENTS,COMPTES,n_client,n_compte);
    }
    else
        choix = 0;

    return choix;
}
