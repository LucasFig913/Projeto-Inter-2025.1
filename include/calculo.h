#ifndef CALCULO_H
#define CALCULO_H

#include "../include/cadastro.h"

// Funções de cálculo
float calculateDailyConsumption(Device device);
float calculateWeeklyConsumption(Device device);
float calculateMonthlyConsumption(Device device);
float calculateTotalConsumption(Device devices[], int totalDevices);
int getMostConsumingDeviceIndex(Device devices[], int totalDevices);

#endif
