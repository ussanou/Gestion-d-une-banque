#include "head.h"

int ajouter(char *,Client_att **,int &);
int modifier(char *,Client_att **,int &);
int chercher(char *,Client_att *,const int &);
int supprimer(char *,Client_att **,int &);
int afficher(char *,int &);

int Demander_choix();

int client(char nom_f[50],Client_att **CLIENTS,int &n_ele )
{
    ///déclaration des variables tel que temps,entier,caractère spéciale :
    int choix,option;
    //Client_att *CLIENTS;

    ///time_t is an object declared already in the ctime library :
    time_t now = time(0);//the time from 1970 to now.
    ///ctime returns a string represent the local time based on the variable now
    char *temps = ctime(&now);

    setlocale(LC_CTYPE,"fra");

    do
    {
        cls;
        for (int l = 0 ; l < 13 ; l++)
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
                    cout << "1 | Ajouter un client";
                    for(int i = 0 ; i < 62 ; i++)cout << " ";
                    cout << "#";
                }
                break;
            case 5 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "2 | Chercher un client ";
                    for(int i = 0 ; i < 60 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 6 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "3 | Modifier un client ";
                    for(int i = 0 ; i < 60 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 7 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "4 | Supprimer un client";
                    for(int i = 0 ; i < 60 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 8 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "5 | Afficher les clients";
                    for(int i = 0 ; i < 59 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 9 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "6 | Retour";
                    for(int i = 0 ; i < 73 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 10 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << "7 | Quitter";
                    for(int i = 0 ; i < 72 ; i++)cout << " ";
                    cout << "#";

                }
                break;
            case 12 :
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
    }while (option<=0 || option>7);


    int choixx = 1;
    switch (option)
    {
    case 1 :
        {
            cls;
            for (int i = 0 ; i < 3 ; i++)cout << endl;
            for (int i = 0 ; i < 35 ; i++)cout << " ";
            cout << "Nom du fichier ou les informations seront enrgistrer : ";
            cin >> nom_f;
            cout << endl << endl;

            for (int i = 0 ; i < 50 ; i++)cout << " ";
            cout << "Nombre des clients a ajouter : ";
            cin >> n_ele;
            *CLIENTS = new Client_att [n_ele];
            choixx = ajouter(nom_f,CLIENTS,n_ele);
        }
        break;
    case 2 :
        {
            if(n_ele==0) break;
            cls;
            choixx = chercher(nom_f,*CLIENTS,n_ele);
        }
        break;
    case 3 :
        {
            if(n_ele==0) break;
            cls;
            choixx = modifier(nom_f,CLIENTS,n_ele);
        }
        break;
    case 4 :
        {
            if(n_ele==0) break;
            cls;
            choixx = supprimer(nom_f,CLIENTS,n_ele);
        }
        break;
    case 5 :
        {
            if(n_ele==0) break;
            cls;
            choixx = afficher(nom_f,n_ele);
        }
        break;
    case 6 :
        {
            return 1;
        }
        break;
    case 7 :
        {
            return 0;
        }
        break;
    }

    if(choixx==1)
        choix = client(nom_f,CLIENTS,n_ele);
    else
        choix = 0;

    return choix;
}
