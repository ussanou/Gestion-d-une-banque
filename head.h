#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <time.h>

#define cls system("cls");
#define pause system("pause");
#define exit system("exit");

using namespace std;

///CETTE FONCTION EST PRESQUE UTILISER DANS TOUS LES FICHIERS.
int Demander_choix();

struct Client_att
{
    int id_client;
    char *nom,*prenom,*profession,*num_tel;
};

struct Compte_att
{
    int id_client,id_compte;
    float solde;
    char *Date_ouverture;
};
