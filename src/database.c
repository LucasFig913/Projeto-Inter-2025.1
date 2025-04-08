#include <stdio.h>
#include <stdlib.h>
#include "../include/database.h"

// Salva todos os usuários no arquivo binário
int saveUsers(User users[], int totalUsers) {
    FILE* file = fopen(USER_FILE, "wb");
    if (!file) return 0;

    fwrite(&totalUsers, sizeof(int), 1, file);
    fwrite(users, sizeof(User), totalUsers, file);
    fclose(file);
    return 1;
}

// Carrega todos os usuários do arquivo binário
int loadUsers(User users[], int* totalUsers) {
    FILE* file = fopen(USER_FILE, "rb");
    if (!file) return 0;

    fread(totalUsers, sizeof(int), 1, file);
    fread(users, sizeof(User), *totalUsers, file);
    fclose(file);
    return 1;
}

// Salva todos os dispositivos no arquivo binário
int saveDevices(Device devices[], int totalDevices) {
    FILE* file = fopen(DEVICE_FILE, "wb");
    if (!file) return 0;

    fwrite(&totalDevices, sizeof(int), 1, file);
    fwrite(devices, sizeof(Device), totalDevices, file);
    fclose(file);
    return 1;
}

// Carrega todos os dispositivos do arquivo binário
int loadDevices(Device devices[], int* totalDevices) {
    FILE* file = fopen(DEVICE_FILE, "rb");
    if (!file) return 0;

    fread(totalDevices, sizeof(int), 1, file);
    fread(devices, sizeof(Device), *totalDevices, file);
    fclose(file);
    return 1;
}

// Remove um usuário pelo índice (desloca os elementos e atualiza a lista)
int deleteUserByIndex(User users[], int* totalUsers, int index) {
    if (index < 0 || index >= *totalUsers) return 0;

    for (int i = index; i < *totalUsers - 1; i++) {
        users[i] = users[i + 1];
    }
    (*totalUsers)--;
    return 1;
}

// Remove um dispositivo pelo índice (desloca os elementos e atualiza a lista)
int deleteDeviceByIndex(Device devices[], int* totalDevices, int index) {
    if (index < 0 || index >= *totalDevices) return 0;

    for (int i = index; i < *totalDevices - 1; i++) {
        devices[i] = devices[i + 1];
    }
    (*totalDevices)--;
    return 1;
}
