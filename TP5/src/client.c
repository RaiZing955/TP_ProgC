#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void lance_client() {
    int client_socket;
    struct sockaddr_in serveur_addr;
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Erreur socket");
        exit(EXIT_FAILURE);
    }

    serveur_addr.sin_family = AF_INET;
    serveur_addr.sin_port = htons(PORT);
    serveur_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr*)&serveur_addr, sizeof(serveur_addr)) < 0) {
        perror("Erreur connect");
        exit(EXIT_FAILURE);
    }

    printf("Votre message (max %d caractères) : ", BUFFER_SIZE - 1);
    fgets(buffer, BUFFER_SIZE, stdin);

    send(client_socket, buffer, strlen(buffer), 0);

    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    printf("Message reçu : %s\n", buffer);

    close(client_socket);
}
