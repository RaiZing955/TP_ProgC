
#include "repertoire.h"
#include <stdio.h>
#include <dirent.h>  // pour opendir, readdir, closedir
#include <errno.h>   // pour errno

void lire_dossier(const char *nom_repertoire) {
    DIR *dossier = opendir(nom_repertoire);
    if (dossier == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return;
    }

    struct dirent *entree;
    while ((entree = readdir(dossier)) != NULL) {
        // Ignore les entrées "." et ".."
        if (entree->d_name[0] != '.' || 
            (entree->d_name[1] != '\0' && (entree->d_name[1] != '.' || entree->d_name[2] != '\0'))) {
            printf("%s\n", entree->d_name);
        }
    }

    closedir(dossier);
}
