#include "head.h"

int accueil();
int menu();
int client(char *,Client_att **, int &);
int compte(char *,Client_att *,Compte_att** ,int &, int &);
int operation(char *,Compte_att** ,int &);

int main()
{
    int check,opt,n_cl=0,n_ct = 0;
    char nom_f[50],nom_fc[50];
    Client_att *C = new Client_att[1];
    Compte_att *Ct = new Compte_att[1];

    do
    check = accueil();
    while(check!=1&&check!=2);

    ///si l'utilisateur a entrer 2 qui correspond a l'option quitter il return 0 et quit

    if (check == 2)
        {pause;return 0;}

    do
        opt = menu();
    while(opt < 0 || opt > 4);

    do
    {
        switch(opt)
        {
            case 1 :
                {
                    check = client(nom_f,&C,n_cl);
                    if(check == 1)
                        opt = menu();
                    else
                        opt = 0;
                }
                break;
            case 2 :
                {
                    if(n_cl != 0)
                    {
                        check = compte(nom_fc,C,&Ct,n_cl,n_ct);
                        if(check == 1)
                            opt = menu();
                        else
                            opt = 0;
                    }
                    else
                        opt = menu();
                }
                break;

            case 3 :
                {
                    cls;
                    if(n_ct != 0)
                    {
                        check = operation(nom_fc,&Ct,n_ct);
                        if(check == 1)
                            opt = menu();
                        else
                            opt = 0;
                    }
                    else
                        opt = menu();
                }
                break;

            case 4 :
                {
                    opt = 0;
                }
                break;
        }
    }while(opt > 0 && opt <= 4);

    cout << endl ;
    for(int i = 0 ; i < 45 ; i++) cout << " ";
    pause;
    return 0;
}
