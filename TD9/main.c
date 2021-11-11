#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAX_NOM 50
#define MAX_ELEVE 5

typedef struct {
    char nom[MAX_NOM+1]; float noteMath, noteInfo , notePhysique;
} etudiant;



void saisirEt(etudiant* Classe[] , int* pNbEleve) {
    int nombreEleve = *pNbEleve; // on récupère le nombre d'élèves

    if (nombreEleve < MAX_ELEVE) {
        etudiant* pEt = Classe[nombreEleve]; // pour simplifier la saisie on recup l'adresse de l'etudiant a saisir
        printf("veuillez saisir le nom de l'eleve en moins de 50 characteres : \n");
        scanf("%s", pEt->nom);
        printf("veuillez saisir la note de math \n");
        scanf("%f", pEt->noteMath);
        printf("veuillez saisir la note d'info \n");
        scanf("%f", pEt->noteInfo);
        printf("veuillez saisir la note de physique \n");
        scanf("%f", pEt->notePhysique);
        (*pNbEleve)++;
    }
        else
        {
            printf("Il n'y a plus de place dans le tableau !\n");
        }


}

void modifEt(etudiant* classe[], int* pNbEleves) {
        int marqueur = 0;
        if (*pNbEleves == 0) {
           printf("Il n'y a pas d'eleve a modifier ! \n") ;
        }
        // on demande quel étudiant va etre modifié :
        printf("Il y a %i etudiant(s) . Quel etudiant souhaitez vous modifier ?\n ", *pNbEleves);
        scanf("%i",&marqueur);
    etudiant* pEt = classe[marqueur];
    printf(" l'etudiant %i a pour nom %s ", marqueur,pEt->nom );
    printf("note de math : %.2f  || note d'info : %.2f || note de physique : %.2f",
           pEt->noteMath, pEt->noteInfo , pEt->notePhysique );
    int choix = 0;
    do {
    printf("1/Modifier le nom\n");
    printf("2/Modifier la note de math\n");
    printf("3/modifier la note d'info\n");
    printf("4/modifier la note de physique\n");
    printf("5/fin modification\n");
        scanf("%i", &choix);
        switch (choix) {
            case 1:
                printf("nouveau nom :  ");
                scanf("%s", pEt->nom);
                printf("\n");
            case 2 :
                printf("nouvelle note de math :  ");
                scanf("%f", pEt->noteMath);
                printf("\n");
                break;
            case 3 :
                printf("nouvelle note d'Info :  ");
                scanf("%f", pEt->noteInfo);
                printf("\n");
                break;
            case 4 :
                printf("nouvelle note de Physique :  ");
                scanf("%f", pEt->notePhysique);
                printf("\n");
                break;
            case 5 :
                printf("Fin Modification\n");
                break;
            default:
                printf("choix invalide, veuillez selectionner un choix valide  \n");

        }



    } while (choix != 5);

}

void affiche(){

}

void saveTxt(){}

void loadTxt(){}

void saveBin(){}

void loadBin(){}

void  Exit(){}


int main() {
   int choix = 0;
   etudiant* classe[MAX_ELEVE]; // classe est un tableau de pointeurs d'étudiants
   int nbEleves = 0;
   do {
       printf("\n");
       printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
       printf("Menu \n");
       printf("1/Saisir etudiants et notes\n");
       printf("2/Modifier 1 etudiant\n");
       printf("3/Afficher\n");
       printf("4/Save (TXT)\n");
       printf("5/Load (TXT)\n");
       printf("6/Save (BIN)\n");
       printf("7/Load (BIN)\n");
       printf("0/Exit \n");
       printf("Votre choix : ");
       scanf("%i",&choix);
       printf("\n");
       fflush(stdin);
       switch (choix) {
           case 1 :
               saisirEt(classe, &nbEleves);
               break;
           case 2 :
               modifEt(classe, &nbEleves);
               break;
           case 3 :
               affiche();
               break;
           case 4 :
               saveTxt();
               break;
           case 5 :
               loadTxt();
               break;
           case 6 :
               saveBin();
               break;
           case 7 :
               loadBin();
               break;
           case 0 :
               Exit();
               break;

           default :
               printf("Choix invalide ! reessayer...\n");
               break;

       }
   } while(choix != 0);
    printf("Au revoir !\n");
    return 0;
}



