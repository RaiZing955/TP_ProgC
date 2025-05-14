#include "repertoire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

// ---------- Structures pour file ----------

typedef struct Noeud {
    char chemin[1024];
    struct Noeud *suivant;
} Noeud;

typedef struct {
    Noeud *debut;
    Noeud *fin;
} File;

// ---------- Fonctions de gestion de file ----------

void enfiler(File *file, const char *chemin) {
    Noeud *nouveau = malloc(sizeof(Noeud));
    if (!nouveau) {
        perror("Erreur malloc");
        exit(EXIT_FAILURE);
    }
    strncpy(nouveau->chemin, chemin, sizeof(nouveau->chemin));
    nouveau->chemin[sizeof(nouveau->chemin) - 1] = '\0';
    nouveau->suivant = NULL;
    if (file->fin)
        file->fin->suivant = nouveau;
    else
        file->debut = nouveau;
    file->fin = nouveau;
}

char *defiler(File *file) {
    if (!file->debut) return NULL;
    Noeud *tmp = file->debut;
    char *chemin = strdup(tmp->chemin);
    file->debut = tmp->suivant;
    if (!file->debut) file->fin = NULL;
    free(tmp);
    return chemin;
}

// ---------- Fonction principale de parcours itératif ----------

void lire_dossier_iteratif(const char *chemin_initial) {
    File file = {0};
    enfiler(&file, chemin_initial);

    while (file.debut) {
        char *chemin = defiler(&file);
        DIR *dossier = opendir(chemin);
        if (!dossier) {
            perror(chemin);
            free(chemin);
            continue;
        }

        struct dirent *entree;
        while ((entree = readdir(dossier)) != NULL) {
            if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0)
                continue;

            char chemin_complet[1024];
            snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", chemin, entree->d_name);

            struct stat st;
            if (stat(chemin_complet, &st) == -1) {
                perror(chemin_complet);
                continue;
            }

            if (S_ISDIR(st.st_mode)) {
                printf("Répertoire : %s\n", chemin_complet);
                enfiler(&file, chemin_complet);
            } else {
                printf("Fichier : %s\n", chemin_complet);
            }
        }

        closedir(dossier);
        free(chemin);
    }
}

// ---------- Fonction main incluse ----------

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    lire_dossier_iteratif(argv[1]);
    return 0;
}
