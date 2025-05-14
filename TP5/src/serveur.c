#include "serveur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <signal.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int serveur_socket;

void quitter(int sig) {
    printf("\nSignal Ctrl+C capturé. Sortie du programme.\n");
    close(serveur_socket);
    exit(0);
}

void lance_serveur() {
    struct sockaddr_in serveur_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    serveur_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (serveur_socket < 0) {
        perror("Erreur socket");
        exit(EXIT_FAILURE);
    }

    serveur_addr.sin_family = AF_INET;
    serveur_addr.sin_addr.s_addr = INADDR_ANY;
    serveur_addr.sin_port = htons(PORT);

    if (bind(serveur_socket, (struct sockaddr*)&serveur_addr, sizeof(serveur_addr)) < 0) {
        perror("Erreur bind");
        exit(EXIT_FAILURE);
    }

    listen(serveur_socket, 1);
    printf("Serveur en attente de connexions...\n");

    signal(SIGINT, quitter);

    while (1) {
        int socket_client = accept(serveur_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (socket_client < 0) {
            perror("Erreur accept");
            continue;
        }

        recois_envoie_message(socket_client);
        close(socket_client);
    }
}

void recois_envoie_message(int socket_client) {
    char buffer[BUFFER_SIZE] = {0};

    int bytes_received = recv(socket_client, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Erreur recv");
        return;
    }

    printf("Message reçu: %s\n", buffer);

    printf("Entrez un message à envoyer au client : ");
    fgets(buffer, BUFFER_SIZE, stdin);

    send(socket_client, buffer, strlen(buffer), 0);
}
#include "serveur.h"

int main() {
    lance_serveur();
    return 0;
}

