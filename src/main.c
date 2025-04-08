#include <stdio.h>
#include <stdlib.h>

#include "../include/cadastro.h"
#include "../include/calculo.h"
#include "../include/database.h"


// Dados globais
User users[MAX_USERS];
int totalUsers = 0;

Device devices[MAX_DEVICES];
int totalDevices = 0;

// Menu principal
void showMainMenu() {
    int option;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Menu de Cadastro\n");
        printf("2. Exibir Consumo\n");
        printf("3. Dispositivo que mais consome\n");
        printf("4. Salvar e Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        getchar(); // limpar buffer

        switch (option) {
            case 1:
                showRegisterMenu();
                break;
            case 2:
                printf("\n--- CONSUMO TOTAL ---\n");
                for (int i = 0; i < totalDevices; i++) {
                    float consumo = calculateMonthlyConsumption(devices[i]);
                    printf("%s: %.2f kWh/mês\n", devices[i].name, consumo);
                }
                printf("Consumo total da residência: %.2f kWh/mês\n", calculateTotalConsumption(devices, totalDevices));
                break;
            case 3: {
                int index = getMostConsumingDeviceIndex(devices, totalDevices);
                if (index != -1) {
                    printf("\nDispositivo que mais consome: %s (%.2f kWh/mês)\n",
                           devices[index].name,
                           calculateMonthlyConsumption(devices[index]));
                } else {
                    printf("Nenhum dispositivo cadastrado.\n");
                }
                break;
            }
            case 4:
                // Salvar os dados antes de sair
                saveUsers(users, totalUsers);
                saveDevices(devices, totalDevices);
                printf("Dados salvos com sucesso. Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (option != 4);
}

int main() {
    // Carregar dados salvos
    loadUsers(users, &totalUsers);
    loadDevices(devices, &totalDevices);

    // Iniciar menu principal
    showMainMenu();

    return 0;
}
