#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cadastro.h"


// Definições das variáveis globais
User users[MAX_USERS];
extern int totalUsers;

Device devices[MAX_DEVICES];
extern int totalDevices;

// Menu de Cadastro
void showRegisterMenu() {
    int option;
    do {
        printf("\n--- MENU DE CADASTRO ---\n");
        printf("1. Cadastrar Usuário\n");
        printf("2. Cadastrar Equipamento\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        getchar(); // limpar buffer

        switch (option) {
            case 1:
                registerUser();
                break;
            case 2:
                registerDevice();
                break;
            case 3:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (option != 3);
}

// Cadastro de Usuário
void registerUser() {
    if (totalUsers >= MAX_USERS) {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }

    User newUser;

    printf("\n--- CADASTRO DE USUÁRIO ---\n");
    printf("Nome: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';

    printf("E-mail: ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0';

    printf("Senha: ");
    fgets(newUser.password, sizeof(newUser.password), stdin);
    newUser.password[strcspn(newUser.password, "\n")] = '\0';

    printf("Endereço (opcional): ");
    fgets(newUser.address, sizeof(newUser.address), stdin);
    newUser.address[strcspn(newUser.address, "\n")] = '\0';

    users[totalUsers++] = newUser;
    printf("Usuário cadastrado com sucesso!\n");
}

// Cadastro de Equipamento
void registerDevice() {
    if (totalDevices >= MAX_DEVICES) {
        printf("Limite máximo de equipamentos atingido.\n");
        return;
    }

    Device newDevice;

    printf("\n--- CADASTRO DE EQUIPAMENTO ---\n");
    printf("Nome do aparelho: ");
    fgets(newDevice.name, sizeof(newDevice.name), stdin);
    newDevice.name[strcspn(newDevice.name, "\n")] = '\0';

    printf("Potência (Watts): ");
    scanf("%f", &newDevice.power);

    printf("Tempo médio de uso por dia (horas): ");
    scanf("%f", &newDevice.dailyUsageHours);

    printf("Quantidade de aparelhos iguais: ");
    scanf("%d", &newDevice.quantity);
    getchar(); // limpar buffer

    devices[totalDevices++] = newDevice;
    printf("Equipamento cadastrado com sucesso!\n");
}
