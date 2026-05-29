#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCTURES
//STRUCTURE PLAT
typedef struct Plat {
    char nom[50];
    char description[100];
    char categorie[50];
    float prix;
    struct Plat *suivant;
} Plat;
//STRUCTURE RESTAURANT
typedef struct Restaurant {
    char nom[50];
    float note;
    float distance;
    Plat *listePlats;
    struct Restaurant *suivant;
} Restaurant;

//CREATION
//CREATION RESTAURANT
Restaurant* creerRestaurant() {
    Restaurant *newE = (Restaurant*)malloc(sizeof(Restaurant));
    printf("Nom du restaurant : \n");
    scanf(" %[^\n]", newE->nom);
    printf("Note : \n");
    scanf("%f", &newE->note);
    printf("Distance : \n");
    scanf("%f", &newE->distance);
    newE->listePlats = NULL;
    newE->suivant = NULL;

    return newE;
}
//CREATION PLAT
Plat* creerPlat() {
    Plat *newE = (Plat*)malloc(sizeof(Plat));
    printf("Nom du plat : \n");
    scanf(" %[^\n]", newE->nom);
    printf("Description : \n");
    scanf(" %[^\n]", newE->description);
    printf("Categorie : \n");
    scanf(" %[^\n]", newE->categorie);
    printf("Prix : \n");
    scanf("%f", &newE->prix);
    newE->suivant = NULL;
    return newE;
}

//AJOUT
//AJOUT RESTAURANT
Restaurant* ajoutRestaurant(Restaurant *liste) {
    Restaurant *newE = creerRestaurant();
    if(liste == NULL) {
        liste = newE;
    }
    else {
        Restaurant *temp = liste;
        while(temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = newE;
    }
    printf("Restaurant ajoute.\n");
    return liste;
}
//AJOUT PLAT
//AJOUT DEBUT
Plat* ajoutDebutPlat(Plat *liste) {
    Plat *newE = creerPlat();
    newE->suivant = liste;
    liste = newE;
    printf("Ajout debut effectue.\n");

    return liste;
}
//AJOUT FIN
Plat* ajoutFinPlat(Plat *liste) {
    Plat *newE = creerPlat();
    if(liste == NULL) {
        liste = newE;
    }
    else {
        Plat *temp = liste;
        while(temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = newE;
    }
    printf("Ajout fin effectue.\n");
    return liste;
}
//AJOUT APRES
Plat* ajoutApresPlat(Plat *liste) {
    char nom[50];
    printf("Ajouter apres quel plat ? ");
    scanf(" %[^\n]", nom);
    Plat *temp = liste;
    while(temp != NULL && strcmp(temp->nom, nom) != 0) {
        temp = temp->suivant;
    }
    if(temp == NULL) {
        printf("Plat introuvable.\n");
    }
    else {
        Plat *newE = creerPlat();
        newE->suivant = temp->suivant;
        temp->suivant = newE;

        printf("Ajout effectue.\n");
    }

    return liste;
}

//AFFICHAGE
//AFFICHAGE PLAT
void afficherPlats(Plat *liste) {
    if(liste == NULL) {
        printf("Aucun plat.\n");
        return;
    }
    while(liste != NULL) {
        printf("\nNom : %s\n", liste->nom);
        printf("Description : %s\n", liste->description);
        printf("Categorie : %s\n", liste->categorie);
        printf("Prix : %.2f DH\n", liste->prix);
        liste = liste->suivant;
    }
}
//AFFICHAGE CATEGORIE
void afficherParCategorie(Plat *liste) {
    char categorie[50];
    int trouve = 0;
    printf("Categorie : \n");
    scanf(" %[^\n]", categorie);
    while(liste != NULL) {
        if(strcmp(liste->categorie, categorie) == 0) {
            printf("\nNom : %s\n", liste->nom);
            printf("Prix : %.2f\n", liste->prix);
            trouve = 1;
        }
        liste = liste->suivant;
    }
    if(!trouve) {
        printf("Categorie introuvable.\n");
    }
}
//AFFICHAGE RESTAURANT
void afficherRestaurants(Restaurant *liste) {
    if(liste == NULL) {
        printf("Aucun restaurant.\n");
        return;
    }
    while(liste != NULL) {
        printf("\nNom : %s\n", liste->nom);
        printf("Note : %.1f\n", liste->note);
        printf("Distance : %.1f km\n", liste->distance);
        liste = liste->suivant;
    }
}

//CHOIX RESTAURANT
Restaurant* chercherRestaurant(Restaurant *liste, char nom[]) {
    while(liste != NULL) {
        if(strcmp(liste->nom, nom) == 0) {
            return liste;
        }
        liste = liste->suivant;
    }
    return NULL;
}
//TRI
//TRI RESTAURANT
//PAR NOM
void triRestaurantNom(Restaurant *liste) {
    Restaurant *i;
    Restaurant *j;
    Restaurant temp;
    for(i = liste; i != NULL; i = i->suivant) {
        for(j = i->suivant; j != NULL; j = j->suivant) {
            if(strcmp(i->nom, j->nom) > 0) {

                temp = *i;
                *i = *j;
                *j = temp;

                Restaurant *tmp = i->suivant;
                i->suivant = j->suivant;
                j->suivant = tmp;
            }
        }
    }

    printf("Tri par nom effectue.\n");
}
//PAR NOTE
void triRestaurantNote(Restaurant *liste) {

    Restaurant *i;
    Restaurant *j;
    Restaurant temp;

    for(i = liste; i != NULL; i = i->suivant) {

        for(j = i->suivant; j != NULL; j = j->suivant) {

            if(i->note < j->note) {

                temp = *i;
                *i = *j;
                *j = temp;

                Restaurant *tmp = i->suivant;
                i->suivant = j->suivant;
                j->suivant = tmp;
            }
        }
    }

    printf("Tri par note effectue.\n");
}
//PAR DISTANCE
void triRestaurantDistance(Restaurant *liste) {

    Restaurant *i;
    Restaurant *j;
    Restaurant temp;

    for(i = liste; i != NULL; i = i->suivant) {

        for(j = i->suivant; j != NULL; j = j->suivant) {

            if(i->distance > j->distance) {

                temp = *i;
                *i = *j;
                *j = temp;

                Restaurant *tmp = i->suivant;
                i->suivant = j->suivant;
                j->suivant = tmp;
            }
        }
    }

    printf("Tri par distance effectue.\n");
}
//TRI PLAT
//PAR NOM
void triPlatNom(Plat *liste) {

    Plat *i;
    Plat *j;
    Plat temp;

    for(i = liste; i != NULL; i = i->suivant) {

        for(j = i->suivant; j != NULL; j = j->suivant) {

            if(strcmp(i->nom, j->nom) > 0) {

                temp = *i;
                *i = *j;
                *j = temp;

                Plat *tmp = i->suivant;
                i->suivant = j->suivant;
                j->suivant = tmp;
            }
        }
    }

    printf("Tri par nom effectue.\n");
}
//PAR CATEGORIE
void triPlatCategorie(Plat *liste) {

    Plat *i;
    Plat *j;
    Plat temp;

    for(i = liste; i != NULL; i = i->suivant) {

        for(j = i->suivant; j != NULL; j = j->suivant) {

            if(strcmp(i->categorie, j->categorie) > 0) {

                temp = *i;
                *i = *j;
                *j = temp;

                Plat *tmp = i->suivant;
                i->suivant = j->suivant;
                j->suivant = tmp;
            }
        }
    }

    printf("Tri par categorie effectue.\n");
}
//PAR PRIX
void triPlatPrix(Plat *liste) {

    Plat *i;
    Plat *j;
    Plat temp;

    for(i = liste; i != NULL; i = i->suivant) {

        for(j = i->suivant; j != NULL; j = j->suivant) {

            if(i->prix > j->prix) {

                temp = *i;
                *i = *j;
                *j = temp;

                Plat *tmp = i->suivant;
                i->suivant = j->suivant;
                j->suivant = tmp;
            }
        }
    }

    printf("Tri par prix effectue.\n");
}

//MODIFICATION
void modifierPlat(Plat *liste) {
    char nom[50];
    printf("Nom du plat a modifier : ");
    scanf(" %[^\n]", nom);

    while(liste != NULL) {

        if(strcmp(liste->nom, nom) == 0) {

            printf("Nouveau nom : ");
            scanf(" %[^\n]", liste->nom);

            printf("Nouvelle description : ");
            scanf(" %[^\n]", liste->description);

            printf("Nouvelle categorie : ");
            scanf(" %[^\n]", liste->categorie);

            printf("Nouveau prix : ");
            scanf("%f", &liste->prix);

            printf("Modification effectuee.\n");

            return;
        }

        liste = liste->suivant;
    }

    printf("Plat introuvable.\n");
}
//SUPRESSION
//SUPRESSION DEBUT
Plat* supprimerDebut(Plat *liste) {
    if(liste == NULL) {
        printf("Liste vide.\n");
        return liste;
    }
    Plat *temp = liste;
    liste = liste->suivant;
    free(temp);
    printf("Suppression debut effectuee.\n");
    return liste;
}
//SUPRESSION FIN
Plat* supprimerFin(Plat *liste) {
    if(liste == NULL) {
        printf("Liste vide.\n");
        return liste;
    }
    Plat *temp = liste;
    Plat *prec = NULL;
    while(temp->suivant != NULL) {
        prec = temp;
        temp = temp->suivant;
    }
    if(prec == NULL) {
        liste = NULL;
    }
    else {
        prec->suivant = NULL;
    }
    free(temp);
    printf("Suppression fin effectuee.\n");
    return liste;
}
//SUPRESSION APRES
Plat* supprimerApresPlat(Plat *liste) {
    char nom[50];

    printf("Supprimer le plat apres : ");
    scanf(" %[^\n]", nom);

    Plat *temp = liste;

    // Chercher le plat
    while(temp != NULL && strcmp(temp->nom, nom) != 0) {
        temp = temp->suivant;
    }

    // Plat non trouve
    if(temp == NULL) {
        printf("Plat introuvable.\n");
        return liste;
    }

    // Pas de plat apres
    if(temp->suivant == NULL) {
        printf("Aucun plat apres celui-ci.\n");
        return liste;
    }

    // Suppression du plat suivant
    Plat *supprimer = temp->suivant;
    temp->suivant = supprimer->suivant;

    free(supprimer);

    printf("Suppression effectuee.\n");

    return liste;
}

//RECHERCHE
//RECHERCHE PAR NOM
void rechercheNomPlat(Plat *liste) {

    char nom[50];
    int trouve = 0;
    printf("Nom du plat : ");
    scanf(" %[^\n]", nom);
    while(liste != NULL) {
        if(strcmp(liste->nom, nom) == 0) {
            printf("\nNom : %s\n", liste->nom);
            printf("Description : %s\n", liste->description);
            printf("Categorie : %s\n", liste->categorie);
            printf("Prix : %.2f\n", liste->prix);
            trouve = 1;
        }
        liste = liste->suivant;
    }
    if(!trouve) {
        printf("Plat introuvable.\n");
    }
}
//RECHERCHE PAR CATEGORIE
void rechercheCategoriePlat(Plat *liste) {
    char categorie[50];
    int trouve = 0;
    printf("Categorie : ");
    scanf(" %[^\n]", categorie);
    while(liste != NULL) {
        if(strcmp(liste->categorie, categorie) == 0) {
            printf("\nNom : %s\n", liste->nom);
            printf("Prix : %.2f\n", liste->prix);
            trouve = 1;
        }
        liste = liste->suivant;
    }
    if(!trouve) {
        printf("Categorie introuvable.\n");
    }
}
//RECHERCHE AVANCEE
void rechercheAvancee(Plat *liste) {
    char categorie[50];
    float prixMax;
    int trouve = 0;
    printf("Categorie : ");
    scanf(" %[^\n]", categorie);
    printf("Prix maximum : ");
    scanf("%f", &prixMax);
    while(liste != NULL) {
        if(strcmp(liste->categorie, categorie) == 0 && liste->prix <= prixMax) {
            printf("\nNom : %s\n", liste->nom);
            printf("Prix : %.2f\n", liste->prix);
            trouve = 1;
        }
        liste = liste->suivant;
    }
    if(!trouve) {
        printf("Aucun resultat.\n");
    }
}

//LA FONCTION MAIN
int main() {
    Restaurant *listeRestaurants = NULL;
    int choixPrincipal;
    int choixRestaurant;
    int choixPlat;
    int choixRecherche;
    int choixSuppression;
    int choixTri;
    char nomRestaurant[50];
    Restaurant *resto;

    do {
        printf("\n========== MENU PRINCIPAL ==========\n");

        printf("1. Gestion restaurants.\n");
        printf("2. Gestion plats.\n");
        printf("3. Quitter.\n");

        printf("Choix : ");
        scanf("%d", &choixPrincipal);

        switch(choixPrincipal) {

//GESTION RESTAURANTS
        case 1:
            do {
                printf("\n===== GESTION RESTAURANTS =====\n");
                printf("1. Ajouter restaurant\n");
                printf("2. Afficher restaurants\n");
                printf("3. Tri restaurants\n");
                printf("4. Retour\n");
                printf("Choix : ");
                scanf("%d", &choixRestaurant);
                switch(choixRestaurant) {
                case 1:
                    listeRestaurants = ajoutRestaurant(listeRestaurants);
                    break;
                case 2:
                    afficherRestaurants(listeRestaurants);
                    break;
                case 3:
                    do {
                        printf("\n===== TRI RESTAURANTS =====\n");
                        printf("1. Par nom\n");
                        printf("2. Par note\n");
                        printf("3. Par distance\n");
                        printf("4. Retour\n");
                        printf("Choix : ");
                        scanf("%d", &choixTri);
                        switch(choixTri) {
                        case 1:
                            triRestaurantNom(listeRestaurants);
                            afficherRestaurants(listeRestaurants);
                            break;
                        case 2:
                            triRestaurantNote(listeRestaurants);
                            afficherRestaurants(listeRestaurants);
                            break;
                        case 3:
                            triRestaurantDistance(listeRestaurants);
                            afficherRestaurants(listeRestaurants);
                            break;
                        }

                    } while(choixTri != 4);

                    break;
                }

            } while(choixRestaurant != 4);

            break;

//GESTION DES PLATS
        case 2:
            printf("Nom du restaurant : ");
            scanf(" %[^\n]", nomRestaurant);
            resto = chercherRestaurant(listeRestaurants, nomRestaurant);
            if(resto == NULL) {
                printf("Restaurant introuvable.\n");
                break;
            }
            do {
                printf("\n===== GESTION PLATS =====\n");
                printf("1. Ajout plats\n");
                printf("2. Modification plats\n");
                printf("3. Affichage plats\n");
                printf("4. Affichage par categorie\n");
                printf("5. Suppression plats\n");
                printf("6. Tri plats\n");
                printf("7. Recherche plats\n");
                printf("8. Retour\n");
                printf("Choix : ");
                scanf("%d", &choixPlat);
                switch(choixPlat) {
                // AJOUT
                case 1:
                    do {
                        printf("\n===== AJOUT =====\n");
                        printf("1. Ajout debut\n");
                        printf("2. Ajout fin\n");
                        printf("3. Ajout apres un plat\n");
                        printf("4. Retour\n");
                        printf("Choix : ");
                        scanf("%d", &choixTri);
                        switch(choixTri) {
                        case 1:
                            resto->listePlats =
                            ajoutDebutPlat(resto->listePlats);
                            break;

                        case 2:
                            resto->listePlats =
                            ajoutFinPlat(resto->listePlats);
                            break;

                        case 3:
                            resto->listePlats =
                            ajoutApresPlat(resto->listePlats);
                            break;
                        }

                    } while(choixTri != 4);

                    break;

                // MODIFICATION
                case 2:
                    modifierPlat(resto->listePlats);
                    break;

                // AFFICHAGE
                case 3:
                    afficherPlats(resto->listePlats);
                    break;

                // AFFICHAGE PAR CATEGORIE
                case 4:
                    afficherParCategorie(resto->listePlats);
                    break;

                // SUPPRESSION
                case 5:
                    do {
                        printf("\n===== SUPPRESSION =====\n");
                        printf("1. Suppression debut\n");
                        printf("2. Suppression fin\n");
                        printf("3. Suppression plat specifique\n");
                        printf("4. Retour\n");
                        printf("Choix : ");
                        scanf("%d", &choixSuppression);

                        switch(choixSuppression) {

                        case 1:
                            resto->listePlats =
                            supprimerDebut(resto->listePlats);
                            break;

                        case 2:
                            resto->listePlats =
                            supprimerFin(resto->listePlats);
                            break;

                        case 3:
                            resto->listePlats =
                            supprimerPlatSpecifique(resto->listePlats);
                            break;
                        }

                    } while(choixSuppression != 4);

                    break;

                // TRI
                case 6:
                    do {
                        printf("\n===== TRI PLATS =====\n");

                        printf("1. Par nom\n");
                        printf("2. Par categorie\n");
                        printf("3. Par prix\n");
                        printf("4. Retour\n");

                        printf("Choix : ");
                        scanf("%d", &choixTri);

                        switch(choixTri) {

                        case 1:
                            triPlatNom(resto->listePlats);
                            afficherPlats(resto->listePlats);
                            break;

                        case 2:
                            triPlatCategorie(resto->listePlats);
                            afficherPlats(resto->listePlats);
                            break;

                        case 3:
                            triPlatPrix(resto->listePlats);
                            afficherPlats(resto->listePlats);
                            break;
                        }

                    } while(choixTri != 4);

                    break;

                // RECHERCHE
                case 7:

                    do {

                        printf("\n===== RECHERCHE =====\n");

                        printf("1. Par nom du plat\n");
                        printf("2. Par categorie\n");
                        printf("3. Recherche avancee\n");
                        printf("4. Retour\n");

                        printf("Choix : ");
                        scanf("%d", &choixRecherche);

                        switch(choixRecherche) {

                        case 1:
                            rechercheNomPlat(resto->listePlats);
                            break;

                        case 2:
                            rechercheCategoriePlat(resto->listePlats);
                            break;

                        case 3:
                            rechercheAvancee(resto->listePlats);
                            break;
                        }

                    } while(choixRecherche != 4);

                    break;
                }

            } while(choixPlat != 8);

            break;
        }

    } while(choixPrincipal != 3);

    printf("\nFin du programme.\n");

    return 0;
}
