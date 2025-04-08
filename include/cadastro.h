#ifndef CADASTRO_H
#define CADASTRO_H

#define MAX_USERS 100
#define MAX_DEVICES 100

// Estrutura de Usuário
typedef struct {
    char name[100];
    char email[100];
    char password[50];
    char address[150];
} User;

// Estrutura de Equipamento
typedef struct {
    char name[100];
    float power;
    float dailyUsageHours;
    int quantity;
} Device;

// Variáveis globais compartilhadas
extern User users[MAX_USERS];
extern int totalUsers;

extern Device devices[MAX_DEVICES];
extern int totalDevices;

// Protótipos das funções de cadastro
void showRegisterMenu();
void registerUser();
void registerDevice();

#endif
