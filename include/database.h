#ifndef DATABASE_H
#define DATABASE_H

#include "../include/cadastro.h"

// Caminhos dos arquivos usados para armazenamento
#define USER_FILE "users.dat"
#define DEVICE_FILE "devices.dat"

// Funções para usuários
int saveUsers(User users[], int totalUsers);
int loadUsers(User users[], int* totalUsers);

// Funções para equipamentos
int saveDevices(Device devices[], int totalDevices);
int loadDevices(Device devices[], int* totalDevices);

// Funções utilitárias (opcional)
int deleteDeviceByIndex(Device devices[], int* totalDevices, int index);
int deleteUserByIndex(User users[], int* totalUsers, int index);

#endif
