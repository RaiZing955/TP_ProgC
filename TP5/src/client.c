#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024];

    // Créer le socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation error");
        return -1;
    }

    // Configurer l'adresse du serveur
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "10.0.40.4", &serv_addr.sin_addr); // IP du serveur

    // Connexion
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connexion échouée");
        return -1;
    }

    printf("Connecté au serveur !\n");

    // Boucle d'envoi de messages
    while (1) {
        fgets(message, sizeof(message), stdin);
        send(sock, message, strlen(message), 0);
    }

    return 0;
}
