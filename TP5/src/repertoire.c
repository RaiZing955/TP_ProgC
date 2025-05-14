#include "repertoire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>  // pour stat
#include <unistd.h>    // pour getcwd
#include <errno.h>

void lire_dossier_recursif(const char *chemin) {
    DIR *dossier = opendir(chemin);
    if (dossier == NULL) {
        perror(chemin);
        return;
    }

    struct dirent *entree;
    while ((entree = readdir(dossier)) != NULL) {
        // Ignorer les entrées "." et ".."
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0)
            continue;

        // Construction du chemin complet
        char chemin_complet[1024];
        snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", chemin, entree->d_name);

        // Vérification si c'est un répertoire ou un fichier
        struct stat st;
        if (stat(chemin_complet, &st) == -1) {
            perror(chemin_complet);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            printf("Répertoire : %s\n", chemin_complet);
            lire_dossier_recursif(chemin_complet);  // Appel récursif
        } else {
            printf("Fichier : %s\n", chemin_complet);
        }
    }

    closedir(dossier);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    lire_dossier_recursif(argv[1]);

    return 0;
}
