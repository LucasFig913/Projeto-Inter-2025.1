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



// Função para realizar o cadastro do usuário
/*void fazerCadastro() {
    char nome[100], cpf[20], email[100], senha[50];

    printf("\n--- Cadastro ---\n");

    // Solicita o nome completo
    printf("Digite seu nome completo: ");
    limparBuffer();  // Limpa o buffer antes do fgets
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;  // Remove o \n do final

    // Solicita e valida o CPF
    do {
        printf("Digite seu CPF (somente números): ");
        scanf("%s", cpf);
        if (!validarCPF(cpf)) {
            printf("CPF inválido! Deve conter apenas números e ter 11 dígitos.\n");
        }
    } while (!validarCPF(cpf));

    // Solicita e valida o e-mail
    do {
        printf("Digite seu e-mail: ");
        scanf("%s", email);
        if (!validarEmail(email)) {
            printf("E-mail inválido! Use o formato correto (ex: exemplo@email.com).\n");
        }
    } while (!validarEmail(email));

    // Solicita uma senha
    printf("Crie uma senha: ");
    scanf("%s", senha);

    // Confirmação do cadastro
    printf("\nCadastro realizado com sucesso!\n");
} */

// Função para simular o login do usuário
/*void fazerLogin() {
    char entrada[100], senha[50];

    printf("\n--- Login ---\n");

    // Usuário pode digitar CPF ou e-mail
    printf("Digite seu CPF ou e-mail: ");
    limparBuffer();
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;

    // Solicita a senha
    printf("Digite sua senha: ");
    scanf("%s", senha);

    // Simulação de login bem-sucedido
    printf("\nLogin simulado! (validação real não implementada).\n");
}*/

// Função para validar se o CPF tem apenas números e 11 dígitos
/*int validarCPF(char cpf[]) {
    for (int i = 0; cpf[i]; i++) {
        if (!isdigit(cpf[i])) return 0;  // Se não for número, CPF inválido
    }
    return strlen(cpf) == 11;  // Deve ter exatamente 11 dígitos
}*/

// Função para validar e-mail com base na presença de @ e .
/*int validarEmail(char email[]) {
    int arroba = 0, ponto = 0;
    for (int i = 0; email[i]; i++) {
        if (email[i] == '@') arroba++;       // Conta quantos @ tem
        if (email[i] == '.' && arroba) ponto++;  // Conta ponto após @
    }
    return arroba == 1 && ponto >= 1;  // E-mail válido se tiver 1 @ e pelo menos 1 .
}*/



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

// Função para limpar o buffer do teclado (evita problemas com fgets após scanf)
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}