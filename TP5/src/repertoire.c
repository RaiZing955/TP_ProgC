#include "repertoire.h"
#include <stdio.h>
#include <dirent.h>  // opendir, readdir, closedir
#include <errno.h>   // perror

void lire_dossier(const char *nom_repertoire) {
    DIR *dossier = opendir(nom_repertoire);
    if (dossier == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return;
    }

    struct dirent *entree;
    while ((entree = readdir(dossier)) != NULL) {
        // Ignore "." et ".."
        if (entree->d_name[0] != '.' || 
            (entree->d_name[1] != '\0' && (entree->d_name[1] != '.' || entree->d_name[2] != '\0'))) {
            printf("%s\n", entree->d_name);
        }
    }

    closedir(dossier);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    char *nom_repertoire = argv[1];
    lire_dossier(nom_repertoire);

    return 0;
}
