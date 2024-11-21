#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVRE 100                  // declaration dune constante  MAX_LIVRE= 100
#define MAX_MEMBRES 100                // declaration dune constante  MAX_MEMBRES= 100
#define MAX 100                        // declaration dune constante  MAX= 100

static int id;
static char titre[MAX];

typedef struct {                        // declaration dune structure DATE
    int jour;
    int mois;
    int annee;
}DATE;
typedef struct {                        // declaration dune structure LIVRE
    int id;
    char titre[50];
    char auteur[50];
    char editeur [50];
    int nb_pages;
    DATE date_pub;
    DATE date_ec;
    int disponible;

} livre;
typedef struct {                       // declaration dune structure MEMBRE
    int id;
    char nom[50];
    char address[100];
    char tel[15];
    DATE date_naiss;
} membre;

livre livres [MAX_LIVRE];                        // declaration dun tableau LIVRES  de type LIVRE dune taille MAX_LIVRE= 100
int livre_count = 0;                            // declaration dun variable LIVRE_COUNT est le initialiser a 0

membre membres [MAX_MEMBRES];                   // declaration dun tableau MEMBRES de type MEMBRE dune taille MAX_MEMNRES= 100
int membre_count = 0;                           // declaration dun variable MEMBRE_COUNT est le initialiser a 0

                      // declaration dun variable TRANSACTION_COUNT est le initialiser a 0

void write_to_file(livre livre){                //declaration dune procedure WRITE_TO_FILE qui ecrivesnt les infos des livre dans un fichier qui s'appelle LIVRES.TXT
    FILE *fp;
    fp = fopen("livres.txt", "a");              //overture du fichier en mode ECRITURE A LA FIN

    fprintf(fp,"\n%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
    livre.id,livre.titre,livre.auteur,livre.editeur,livre.nb_pages,
    livre.date_ec.jour,livre.date_ec.mois,livre.date_ec.annee,
    livre.date_pub.jour,livre.date_pub.mois,livre.date_pub.annee
    );
    livres[livre_count++] = livre; // incrementer le nombre des livres enregister par 1.
    fclose(fp);             // fermeture du fichier
}


void ajouter_livre() {                                                          //FONCTION "ajouter_livre"

    system("cls");

    if (livre_count >= MAX_LIVRE) {                                             //le programme va verifier si le livre_count est superieur ou egal a max livre.
        printf("NOMBRE MAXIMUM DE LIVRES ATTEINTS.\n");
        return;
    }
    livre livre;


    printf("\t\t\t ------ L AJOUT  DUN LIVRE. ------\n\n");
    printf("Entrer le ID du livre: ");
    while(scanf ("%d", &livre.id)!= 1){
        printf("---- L ID DU LIVRE DOIT ETRE UN ENTIER!!! ---- \nEntrer livre ID:");            //une boucle WHILE pour voir si lutilisateur a entrer un crctr,
        rewind(stdin); /* nettoie le tampon de lecture*/
    }
    printf("Entrer le TITRE du livre: ");
    scanf(" %[^\n]", livre.titre);
    printf("Entrer LAUTEUR du livre: ");
    scanf(" %[^\n]", livre.auteur);
    printf("Entrer LEDITEUR du livre: ");
    scanf(" %[^\n]", livre.editeur);
    printf("Entrer LE NOMBRE DES PAGES: ");
    while(scanf ("%d", &livre.nb_pages)!= 1){
        printf("---- LE NOMBRE DES PAGES DOIT ETRE UN ENTIER!!! ---- \nEntrer LE NOMBRE DES PAGES: ");     //une boucle WHILE pour voir si lutilisateur a entrer un crctr,
        rewind(stdin); /* nettoie le tampon de lecture*/
    }

    printf("\n\nEntrer LE JOUR de la date decriture du livre: ");
    while(scanf ("%d", &livre.date_ec.jour)!= 1 || livre.date_ec.jour>31){
        printf("---- LE JOUR DOIT ETRE UN ENTIER ET NE PAS SUPERIEUR A 31!!! ---- \nEntrer LE JOUR DE LA DATE DECRITURE du livre: ");   //une boucle WHILE pour voir si lutilisateur a entrer un crctr ou le nombre qui a entrer est superieur a 31(pcq le nombre maximum des jours dans un mois est 31)
        rewind(stdin); /* nettoie le tampon de lecture*/}


    printf("Entrer LE MOIS de la date decriture du livre: ");
    while(scanf ("%d", &livre.date_ec.mois)!= 1 || livre.date_ec.mois> 12){
        printf("---- LE MOIS DOIT ETRE UN ENTIER  ET NE PAS SUPERIEUR A 12!!! ---- \nEntrer LE MOIS DE LA DATE DECRITURE du livre: "); //une boucle WHILE pour voir si lutilisateur a entrer un crctr ou le nombre qui a entrer est superieur a 12(pcq le nombre maximum des mois est 12)
        rewind(stdin); /* nettoie le tampon de lecture*/}

    printf("Entrer LANNEE de la date decriture du livre: ");
    while(scanf ("%d", &livre.date_ec.annee)!= 1 || livre.date_ec.annee>2022){
        printf("---- LANNEE DOIT ETRE UN ENTIER ET NE PAS SUPERIEUR A 2022!!! ---- \nEntrer LANNEE DE LA DATE DECRITURE du livre: "); //une boucle WHILE pour voir si lutilisateur a entrer un crctr ou le nombre qui a entrer est superieur a 2022
        rewind(stdin); /* nettoie le tampon de lecture*/}

    printf("\n\nEntrer LE JOUR de la date de publication du livre: ");
    while(scanf ("%d", &livre.date_pub.jour)!= 1 || livre.date_pub.jour>31){
        printf("---- LE JOUR DOIT ETRE UN ENTIER ET NE PAS SUPERIEUR A 31!!! ---- \nEntrer LE JOUR DE LA DATE DE PUBLICATION du livre: "); // la meme chose ici, pour controlé les entres de l'utilisateur
        rewind(stdin); /* nettoie le tampon de lecture*/}

    printf("Entrer LE MOIS de la date de publication du livre: ");
    while(scanf ("%d", &livre.date_pub.mois)!= 1 || livre.date_pub.mois> 12){
        printf("---- LE MOIS DOIT ETRE UN ENTIER  ET NE PAS SUPERIEUR A 12!!! ---- \nEntrer LE MOIS DE LA DATE DE PUBLICATION du livre: ");
        rewind(stdin); /* nettoie le tampon de lecture*/}

    printf("Entrer LANNEE de la date de publication du livre: ");

    while(scanf ("%d", &livre.date_pub.annee)!= 1 || livre.date_pub.annee>2022 || livre.date_pub.annee < livre.date_ec.annee){
        printf("---- LANNEE DOIT ETRE UN ENTIER, NE PAS SUPERIEUR A 2022 ET LA DATE DE PUBLICATION INFERIEUR A LA DATE DECRITURE!!! ");
        printf("---- \nEntrer LANNEE DE LA DATE DE PUBLICATION du livre: "); // la date de pub doit etre inferieur ou egal a la date decrivation
        rewind(stdin); /* nettoie le tampon de lecture*/}




    livre.disponible = 1;

    printf("LIVRE AJOUTE AVEC SUCCES.\n");

    write_to_file(livre); // le programme va sauter a la procedure write_to_file().


}

void writetofile(membre membre)    //procedure pour enregistrer les infos des membres dans un fichier
{
    FILE *fp;
    fp = fopen("membres.txt", "a");   //Overture du fichier en mode APPEND: ECRITURE A LA FIN
    fprintf(fp,"\n%d\n%s\n%s\n%s\n%d\n%d\n%d\n",
            membre.id, membre.nom, membre.address,membre.tel,
            membre.date_naiss.jour,membre.date_naiss.mois,membre.date_naiss.annee
            );
    fclose(fp);                     //FERMETURE DU FICHIER
}



void ajouter_membre()
{

    system("cls");
    if (membre_count >= MAX_MEMBRES){
        printf("NOMBRE MAXIMUM DES MEMBRES ATTEINTS!!!"); // le prg va verifier si le membre_count > ou egal a MAX_MEMBERES
        return;
    }
    rewind(stdin);
    membre membre;
    printf("\t\t\t------ L AJOUT DUN MEMBRE ------\n\n");
    printf("Entrer LID du membre:");
    while(scanf ("%d", &membre.id)!= 1){
        printf("---- L ID DU MEMBRE DOIT ETRE UN ENTIER!!! ---- \nEntrer Membre ID:");  // une boucle WHILE pour controler les entrées de l'utilisateur
        rewind(stdin); /* nettoie le tampon de lecture*/}

    rewind (stdin);
    printf("Entrer LE NOM COMPLET du membre:");
    scanf("%[^\n]", membre.nom); // %[^\n] lire une suite de crctr jusqua lutilisateur appuie sure entré ( et NON PAS ESPACE ou TAB )
    printf("Entrer LADRESSE du membre:");
    scanf(" %[^\n]", membre.address);
    printf("Entrer LE NUM DE TEL du membre:");
    scanf(" %[^\n]", membre.tel);
    printf("\n\nEntrer LE JOUR de la date de naissance:");
    while(scanf ("%d", &membre.date_naiss.jour)!= 1 || membre.date_naiss.jour>31){
        printf("---- LE JOUR DOIT ETRE UN ENTIER ET NE PAS SUPERIEUR A 31!!! ---- \nEntrer LE JOUR DE LA DATE DE naissance "); //Boucle de controle
        rewind(stdin); /* nettoie le tampon de lecture*/}


    printf("Entrer LE MOIS de votre date de naissance:");
    while(scanf ("%d", &membre.date_naiss.mois)!= 1 || membre.date_naiss.mois> 12){
        printf("---- LE MOIS DOIT ETRE UN ENTIER  ET NE PAS SUPERIEUR A 12!!! ---- \nEntrer LE MOIS DE LA DATE DE naissance: ");
        rewind(stdin); /* nettoie le tampon de lecture*/}


    printf("Entrer LANNEE de votre date de naissance:");
    while(scanf ("%d", &membre.date_naiss.annee)!= 1 || membre.date_naiss.annee>2014 ){
        printf("---- LANNEE DOIT ETRE UN ENTIER ET NE PAS SUPERIEUR A 2014 (le minimum age dun membre est: 8ans)!!! ---- \nEntrer LANNEE DE LA DATE DE naissance: ");
        rewind(stdin); /* nettoie le tampon de lecture*/}



    writetofile(membre);  // le programme va sauter a la procedure WRITETOFILE()
    membres[membre_count++] = membre; // Incrementer le nombre de membre_count par 1 a chaque fois un membre est ajoutée
    printf("MEMBRE AJOUTE AVEC SUCCES.\n");

}







void afficher_tout_livres() {
    system ("cls");
    printf("\t\t   --------- AFFICHAGE DE TOUS LES LIVRES QUI SE TROUVE DANS NOTRE BIBLIOTHEQUES. ---------");
    FILE *fp; //creation dun fichier nommé fp
    livre livre;



    fp = fopen("D://BTS//1ere année//PROJET//C//BIB//livres.txt", "r"); // ouvrir le fichier livres.txt en mode read ( LECTURE)

    if (fp==NULL){
        printf("\nImpossible douvrir le fichier.\n"); // le programme va verifier si le fichier est nul, si oui va afiicher le message ecrit si non, va sauter directement a la boucle while
    }


    while (fscanf(fp, "%d %[^\n] %[^\n] %[^\n] %d %d %d %d  %d %d %d \n"

                  , &livre.id, livre.titre , livre.auteur, livre.editeur, &livre.nb_pages, &livre.date_ec.jour, &livre.date_ec.mois,
                  &livre.date_ec.annee, &livre.date_pub.jour, &livre.date_pub.mois , &livre.date_pub.annee  ) != EOF) {   // verifier si la fonction fscanf a arriver a EOF ( End Of File ) si oui le programme va sortir de la boucle si non va continue a lire les infos trouver dans le fichier.
            printf("\n\nLID DU LIVRE EST: %d", livre.id);
            printf("\nLE TITRE DU LIVRE EST: %s", livre.titre);
            printf("\nLAUTEUR DU LIVRE EST: %s", livre.auteur);
            printf("\nLEDITEUR DU LIVRE EST: %s", livre.editeur);
            printf("\nLE NOMBRE DES PAGES DU LIVRE EST: %d", livre.nb_pages);
            printf("\nLA DATE DE LECRITURE DU LIVRE: %d/%d/%d.",livre.date_ec.jour, livre.date_ec.mois, livre.date_ec.annee);
            printf("\nLA DATE DE PUBLICATION DU LIVRE: %d/%d/%d.\n", livre.date_pub.jour , livre.date_pub.mois , livre.date_pub.annee );
        }
    fclose(fp);        // Fermeture du fichier
}


void afficher_tout_membres() {
    system("cls");
    printf("\t\t   --------- AFFICHAGE DE TOUS LES MEMBRES QUI SE TROUVE DANS NOTRE BIBLIOTHEQUES. ---------\n");
    FILE *fp ;
    membre membre;
    fp = fopen("membres.txt", "r");

    if (fp==NULL){
        printf("\nImpossible douvrir le fichier.\n"); // le programme va verifier si le fichier est nul, si oui va afiicher le message ecrit si non, va sauter directement a la boucle while
    }

    while (fscanf(fp,"\n\n%d \n%[^\n] \n%[^\n] \n%[^\n] \n%d\n%d\n%d"
                  , &membre.id, membre.nom ,membre.address,membre.tel, &membre.date_naiss.jour,
                  &membre.date_naiss.mois , &membre.date_naiss.annee ) != EOF) {
                printf("\nLID DU MEMBRE: %d", membre.id);
                printf("\nLE NOM COMPLET EST: %s", membre.nom);
                printf("\nLADRESS EST: %s", membre.address);
                printf("\nLE NUMERO DE TELEPHONE EST: %s", membre.tel);
                printf("\nLA DATE DE NAISSANCE EST: %d/%d/%d\n", membre.date_naiss.jour, membre.date_naiss.mois, membre.date_naiss.annee);

                  }
    fclose(fp);
}

void supprimer_membre(){
    system("cls");
                printf("\t\t\t\t ----> SUPPRESSION D'UN MEMBRE <---- \n");
                printf("ENTREZ L'ID DU MEMBRE A SUPPRIMER: ");
                while(scanf ("%d", &id)!= 1){
                printf("---- L ID DU LIVRE DOIT ETRE UN ENTIER!!! ---- \nEntrer livre ID:");            //une boucle WHILE pour voir si lutilisateur a entrer un crctr,
                rewind(stdin);}

    FILE *fp1, *fp2;
    int found = 0;
    membre currentMembre;



    // Ouvre le fichier original en mode lecture
    fp1 = fopen("membres.txt", "r");

    // Vérifie si le fichier peut être ouvert
    if (fp1 == NULL)
    {
        printf("Le fichier ne peut pas etre ouvert");
        return;
    }

    // Ouvre un nouveau fichier en mode écriture temporaire
    fp2 = fopen("TEMP.txt", "w");

    // Vérifie si le fichier peut être ouvert
    if (fp2 == NULL)
    {
        printf("Le fichier ne peut pas etre ouvert\n");
        fclose(fp1);
        return;
    }

    // Lit chaque ligne du fichier original
    while (fscanf(fp1,"\n\n%d \n%[^\n] \n%[^\n] \n%[^\n] \n%d\n%d\n%d",
                  &currentMembre.id, currentMembre.nom, currentMembre.address, currentMembre.tel,
                  &currentMembre.date_naiss.jour, &currentMembre.date_naiss.mois, &currentMembre.date_naiss.annee) != EOF)
    {
        // Si l'ID du membre correspond à celui fourni par l'utilisateur, ne l'écrit pas dans le nouveau fichier
        if (currentMembre.id == id)
        {
            found = 1;

        }
        else {

        // Sinon, écrit la ligne dans le nouveau fichier
        fprintf(fp2,"\n%d\n%s\n%s\n%s\n%d\n%d\n%d\n",
            currentMembre.id, currentMembre.nom, currentMembre.address, currentMembre.tel,
            currentMembre.date_naiss.jour, currentMembre.date_naiss.mois, currentMembre.date_naiss.annee); }
    }

    // Ferme les fichiers
    fclose(fp1);
    fclose(fp2);

    // Supprime le fichier original
    remove("membres.txt");

    // Renomme le fichier temporaire pour prendre le nom du fichier original
    rename("TEMP.txt","membres.txt");

    // Affiche un message si aucun membre correspondant à l'ID fourni n'a été trouvé
    if (found == 0)
    {
        printf("AUCUN MEMBRE TROUVE AVEC CET ID.\n");
    }
    else
    {
        printf("MEMBRE SUPPRIME AVEC SUCCES.\n");
    }
}


void supprimer_livre()
{
    system("cls");
                printf("\t\t\t\t ----> SUPPRESSION D'UN LIVRE <---- \n");
                printf("ENTREZ L'ID DU LIVRE A SUPPRIMER: ");
                while(scanf ("%d", &id)!= 1){
                    printf("---- L ID DU LIVRE DOIT ETRE UN ENTIER!!! ---- \nEntrer livre ID:");            //une boucle WHILE pour voir si lutilisateur a entrer un crctr,
                    rewind(stdin);
                }

    FILE *fp1, *fp2;
    int found = 0;
    livre currentlivre;



    // Ouvre le fichier original en mode lecture
    fp1 = fopen("livres.txt", "r");

    // Vérifie si le fichier peut être ouvert
    if (fp1 == NULL){
        printf("Le fichier ne peut pas etre ouvert");
        return;
    }

    // Ouvre un nouveau fichier en mode écriture temporaire
    fp2 = fopen("TEMP.txt", "w");

    // Vérifie si le fichier peut être ouvert
    if (fp2 == NULL)
    {
        printf("Le fichier ne peut pas etre ouvert\n");
        fclose(fp1);
        return;
    }

    // Lit chaque ligne du fichier original
    while (fscanf(fp1, "\n\n%d \n%[^\n] \n%[^\n] \n%[^\n] \n%d \n%d \n%d \n%d  \n%d \n%d \n%d \n"

                  , &currentlivre.id, currentlivre.titre , currentlivre.auteur, currentlivre.editeur, &currentlivre.nb_pages, &currentlivre.date_ec.jour,
                   &currentlivre.date_ec.mois, &currentlivre.date_ec.annee, &currentlivre.date_pub.jour,
                    &currentlivre.date_pub.mois , &currentlivre.date_pub.annee  ) != EOF)
    {
        // Si l'ID du membre correspond à celui fourni par l'utilisateur, ne l'écrit pas dans le nouveau fichier
        if (currentlivre.id == id)
        {
            found = 1;

        }
        else {

        // Sinon, écrit la ligne dans le nouveau fichier
        fprintf(fp2 ,"\n%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                    currentlivre.id, currentlivre.titre , currentlivre.auteur, currentlivre.editeur,
                     currentlivre.nb_pages, currentlivre.date_ec.jour, currentlivre.date_ec.mois,
                     currentlivre.date_ec.annee, currentlivre.date_pub.jour,
                    currentlivre.date_pub.mois , currentlivre.date_pub.annee);

    }
    }

    // Ferme les fichiers
    fclose(fp1);
    fclose(fp2);

    // Supprime le fichier original
    remove("livres.txt");

    // Renomme le fichier temporaire pour prendre le nom du fichier original
    rename("TEMP.txt","livres.txt");

    // Affiche un message si aucun membre correspondant à l'ID fourni n'a été trouvé
    if (found == 0)
    {
        printf("AUCUN LIVRE TROUVE AVEC CET ID.\n");
    }
    else
    {
        printf("LIVRE SUPPRIME AVEC SUCCES.\n");
    }
}

void afficher_membre_par_id()
{
    system("cls");

                printf("\t\t\t\t ----> AFFICHAGE DUN SEUL MEMBRE <---- \n");
                printf("ENTREZ L'ID DU MEMBRE A AFFICHER: ");
                while(scanf ("%d", &id)!= 1){
                printf("---- L ID DU LIVRE DOIT ETRE UN ENTIER!!! ---- \nEntrer livre ID:");            //une boucle WHILE pour voir si lutilisateur a entrer un crctr,
                rewind(stdin);}

    FILE *fp;
    membre currentMembre  ;


    fp = fopen("membres.txt", "r");

    if (fp==NULL)
    {
        printf("le fichier ne peut pas etre ouvert.\n");
        return;
    }
    int found = 0 ;

    while (fscanf(fp,"\n\n%d \n%[^\n] \n%[^\n] \n%[^\n] \n%d\n%d\n%d",
                  &currentMembre.id, currentMembre.nom, currentMembre.address, currentMembre.tel,
                  &currentMembre.date_naiss.jour, &currentMembre.date_naiss.mois, &currentMembre.date_naiss.annee) != EOF){
            if (currentMembre.id==id)
            {
                found = 1;
                printf("\nLID DU MEMBRE: %d", currentMembre.id);
                printf("\nLE NOM COMPLET EST: %s", currentMembre.nom);
                printf("\nLADRESS EST: %s", currentMembre.address);
                printf("\nLE NUMERO DE TELEPHONE EST: %s", currentMembre.tel);
                printf("\nLA DATE DE NAISSANCE EST: %d/%d/%d\n", currentMembre.date_naiss.jour, currentMembre.date_naiss.mois, currentMembre.date_naiss.annee);
                break;
            }
                  }
    fclose(fp);

    if (found == 0)
                    printf("\nAucun membre trouve.\n");


}

void afficher_livre_par_id()
{
    int id ;
    system("cls");
                printf("\nENTREZ L'ID DU LIVRE A AFFICHER: ");
                while(scanf ("%d", &id)!= 1){
                printf("---- L ID DU LIVRE DOIT ETRE UN ENTIER!!! ---- \nEntrer livre ID:");            //une boucle WHILE pour voir si lutilisateur a entrer un crctr,
                rewind(stdin);}
     FILE * fp;
    livre currentlivre;

    fp = fopen("livres.txt","r");

    if (fp == NULL)
    {
        printf("Le fichier ne peut pas etre ouvert.\n");
        return;
    }


    int found = 0;

        while (fscanf(fp, "%d %[^\n] %[^\n] %[^\n] %d %d %d %d  %d %d %d \n"

                  , &currentlivre.id, currentlivre.titre , currentlivre.auteur, currentlivre.editeur, &currentlivre.nb_pages, &currentlivre.date_ec.jour,
                   &currentlivre.date_ec.mois, &currentlivre.date_ec.annee, &currentlivre.date_pub.jour,
                    &currentlivre.date_pub.mois , &currentlivre.date_pub.annee  ) != EOF) {

                  if (currentlivre.id == id)
                  {
                    found = 1;
                    printf("\n\nLID DU LIVRE EST: %d", currentlivre.id);
                    printf("\nLE TITRE DU LIVRE EST: %s", currentlivre.titre);
                    printf("\nLAUTEUR DU LIVRE EST: %s", currentlivre.auteur);
                    printf("\nLEDITEUR DU LIVRE EST: %s", currentlivre.editeur);
                    printf("\nLE NOMBRE DES PAGES DU LIVRE EST: %d", currentlivre.nb_pages);
                    printf("\nLA DATE DE LECRITURE DU LIVRE: %d/%d/%d.",currentlivre.date_ec.jour, currentlivre.date_ec.mois, currentlivre.date_ec.annee);
                    printf("\nLA DATE DE PUBLICATION DU LIVRE: %d/%d/%d.\n", currentlivre.date_pub.jour , currentlivre.date_pub.mois , currentlivre.date_pub.annee );
                    break;
                  }
                  }
                  fclose(fp);
                    if (found == 0)
                        printf("\nAUCUN LIVRE TROUVER AVEC CET ID. \n");


}

void afficher_livre_par_titre()
{
    rewind(stdin);
    char titre[MAX];
    system("cls");
    printf("\nENTREZ LE TITRE DU LIVRE A AFFICHER: ");

    fgets(titre, MAX, stdin);
    titre[strcspn(titre, "\n")] = 0; // retirer le caractère de retour à la ligne à la fin de la chaîne

    FILE *fp;
    livre currentlivre;

    fp = fopen("livres.txt", "r");

    if (fp == NULL)
    {
        printf("Le fichier ne peut pas etre ouvert.\n");
        return;
    }

    int found = 0;

    while (fscanf(fp, "%d %[^\n] %[^\n] %[^\n] %d %d %d %d %d %d %d",
                  &currentlivre.id, currentlivre.titre, currentlivre.auteur, currentlivre.editeur,
                  &currentlivre.nb_pages, &currentlivre.date_ec.jour, &currentlivre.date_ec.mois,
                  &currentlivre.date_ec.annee, &currentlivre.date_pub.jour, &currentlivre.date_pub.mois,
                  &currentlivre.date_pub.annee) == 11) // vérifier que tous les champs ont été lus
    {
        if (strcmp(currentlivre.titre, titre) == 0){
            found = 1;
            printf("\n\nL'ID DU LIVRE EST : %d", currentlivre.id);
            printf("\nLE TITRE DU LIVRE EST : %s", currentlivre.titre);
            printf("\nL'AUTEUR DU LIVRE EST : %s", currentlivre.auteur);
            printf("\nL'EDITEUR DU LIVRE EST : %s", currentlivre.editeur);
            printf("\nLE NOMBRE DE PAGES DU LIVRE EST : %d", currentlivre.nb_pages);
            printf("\nLA DATE D'ECRITURE DU LIVRE EST : %d/%d/%d", currentlivre.date_ec.jour,
                   currentlivre.date_ec.mois, currentlivre.date_ec.annee);
            printf("\nLA DATE DE PUBLICATION DU LIVRE EST : %d/%d/%d.\n", currentlivre.date_pub.jour,
                   currentlivre.date_pub.mois, currentlivre.date_pub.annee);
            break;
        }
    }

    fclose(fp);

    if (found == 0)
        printf("\nAUCUN LIVRE TROUVE AVEC CE TITRE.\n");
}



void afficher_livre()
{
    system("cls");
    int choix;
    printf("\t\t\t\t ----> AFFICHAGE DUN SEUL LIVRE <---- \n");
    printf("\nRECHERCHE PAR:");
    printf("\n1. ID.");
    printf("\n2. TITRE.");
    printf("\nENTRER VOTRE CHOIX: ");
    while(scanf ("%d",&choix )!= 1 || (choix>2 || choix <1) ){
        printf("---- VOTRE CHOIX DOIT ETRE COMPRIS ENTRE 1 ET 3 !!! ---- \nENTRER VOTRE CHOIX: ");
        rewind(stdin); /* nettoie le tampon de lecture*/}

        switch (choix)
        {
        case 1:
            afficher_livre_par_id();
            break;
        case 2:
            afficher_livre_par_titre();
            break;
        }

}


void afficher_membre_par_nom()
{
    {
    rewind(stdin);
    char nom[MAX];
    system("cls");
    printf("\nENTREZ LE NOM DU MEMBRE A AFFICHER: ");

    fgets(nom, MAX, stdin);
    nom[strcspn(nom, "\n")] = 0; // retirer le caractère de retour à la ligne à la fin de la chaîne

    FILE *fp;
    membre currentMembre;

    fp = fopen("membres.txt", "r");

    if (fp == NULL)
    {
        printf("Le fichier ne peut pas etre ouvert.\n");
        return;
    }

    int found = 0;

    while (fscanf(fp, "\n\n%d \n%[^\n] \n%[^\n] \n%[^\n] \n%d\n%d\n%d",
                  &currentMembre.id, currentMembre.nom, currentMembre.address, currentMembre.tel,
                  &currentMembre.date_naiss.jour, &currentMembre.date_naiss.mois, &currentMembre.date_naiss.annee) == 7) // vérifier que tous les champs ont été lus
    {
        if (strcmp(currentMembre.nom, nom) == 0)
        {
            found = 1;
            printf("\nLID DU MEMBRE: %d", currentMembre.id);
                printf("\nLE NOM COMPLET EST: %s", currentMembre.nom);
                printf("\nLADRESS EST: %s", currentMembre.address);
                printf("\nLE NUMERO DE TELEPHONE EST: %s", currentMembre.tel);
                printf("\nLA DATE DE NAISSANCE EST: %d/%d/%d\n", currentMembre.date_naiss.jour, currentMembre.date_naiss.mois, currentMembre.date_naiss.annee);
            break;
        }
    }

    fclose(fp);

    if (found == 0)
        printf("\nAUCUN MEMBRE TROUVE AVEC CE NOM.\n");
}
}

void afficher_membre()
{
    system("cls");
    int choix;
    printf("\n\t\t\t\t ----> AFFICHAGE DUN SEUL MEMBRE <---- \n");
    printf("\nRECHERCHE PAR:");
    printf("\n1. ID.");
    printf("\n2. NOM COMPLET.");
    printf("\nENTRER VOTRE CHOIX: ");
    while(scanf ("%d",&choix )!= 1 || (choix>2 || choix <1) ){
        printf("---- VOTRE CHOIX DOIT ETRE COMPRIS ENTRE 1 ET 3 !!! ---- \nENTRER VOTRE CHOIX: ");
        rewind(stdin); /* nettoie le tampon de lecture*/}

        switch (choix)
        {
        case 1:
            afficher_membre_par_id();
            break;
        case 2:
            afficher_membre_par_nom();
            break;
        }

}

int main()              //Declaration de la fonction PRINCIPALE
{
    system("cls");
char username[20];     // declaration de deux variables USERNAME et PASSWORD de type chaine de charactere, le max est 20 crctr
    char password[20];
    int count = 0;    //Declaration dun variable count est le initialiser a 0
    printf("\t \t \t \t \t =======================================\n");
    printf("\t \t \t \t \t |SYSTEME DE GESTION DES BIBLIOTHEQUES.|\n");
    printf("\t \t \t \t \t =======================================\n");
    printf("\t \t \t \t \t     ------- AUTHENTIFICATION. -------");

    while (1) {
        printf("\nIDENTIFIANT: ");
        scanf("%s", username);

        printf("\nMOT DE PASSE: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {  // le programme va comparer USERNAME et PASSWORD qui a entrer lulisateur avec ADMIN ADMIN
            printf("\nAUTHENTIFICATION REUSSIE! BIENVENUE.\n");
            break;
        }
        else {
            count++;
            if (count == 3) {
                printf("\nVOUS AVEZ DEPASSE LE NOMBRE DE TENTATIVES PERMISES. LE PROGRAMME VA QUITTER.\n");
                exit(0);
            }
            printf("\nIDENTIFIANT OU MOT DE PASSE INCORRECT! REESSAYER.\n");

        }
    }


        int q;
        int choix;
    while (1) {

            printf("\n\t \t \t \t \t =======================================\n");
        printf("\t \t \t \t \t |SYSTEME DE GESTION DES BIBLIOTHEQUES.|\n");
        printf("\t \t \t \t \t =======================================\n");

        printf("1. AJOUTER UN LIVRE.\n");
        printf("2. AFFICHER UN SEUL LIVRE.\n");
        printf("3. SUPPRIMER UN LIVRE.\n");
        printf("4. AJOUTER UN MEMBRE.\n");
        printf("5. SUPPRIMER UN MEMBRE\n");
        printf("6. AFFICHER UN SEUL MEMBRE.\n");
        printf("7. AFFICHER TOUT LES LIVRES.\n");
        printf("8. AFFICHER TOUT LES MEMBRES.\n");
        printf("0. POUR SORTIR.\n");
        printf("\nENTRER VOTRE CHOIX: ");
        while(scanf ("%d",&choix )!= 1 || (choix>11 || choix <0) ){
        printf("---- VOTRE CHOIX DOIT ETRE COMPRIS ENTRE 0 ET 10 !!! ---- \nENTRER VOTRE CHOIX: ");
        rewind(stdin); /* nettoie le tampon de lecture*/}
        switch(choix) {
            case 0:

                printf("\nVous Voulez vraiment QUITTEZ le programme ?");
                printf("\n0. pour QUITTEZ");
                printf("\n1. pour RESTER");
                printf("\nEntrez votre CHOIX:");
                while(scanf ("%d",&q )!= 1 ){
                            printf("---- VOTRE CHOIX DOIT ETRE COMPRIS ENTRE 0 ou 1 !!! ---- \nENTRER VOTRE CHOIX: ");
                            rewind(stdin); /* nettoie le tampon de lecture*/}
                if (q==0){
                    printf("\n\t\t\t\t\t\t--------ORIVWAR!!!!--------");

                    exit(0);}
                else {
                    system("cls");
                    break; }

            case 1:
                ajouter_livre();
                break;

            case 2:
                afficher_livre();
                break;

            case 3:
                supprimer_livre();
                break;

            case 4:
                ajouter_membre();
                break;

            case 5:
                supprimer_membre(id);
                break;

            case 6:
                afficher_membre();
                break;

            case 7:
                afficher_tout_livres();
                break;
            case 8:
                afficher_tout_membres();
                break;

            default:
                printf("\nCHOIX INVALIDE! REESSAYER.\n");
                break;
        }
    }
    return 0;
}
