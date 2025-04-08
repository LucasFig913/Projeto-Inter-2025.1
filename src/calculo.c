#include <stdio.h>
#include "../include/calculo.h"

// Função para calcular o consumo diário de um equipamento (em kWh)
float calculateDailyConsumption(Device device) {
    return (device.power * device.dailyUsageHours * device.quantity) / 1000.0f;
}

// Consumo semanal = consumo diário * 7
float calculateWeeklyConsumption(Device device) {
    return calculateDailyConsumption(device) * 7.0f;
}

// Consumo mensal = consumo diário * 30
float calculateMonthlyConsumption(Device device) {
    return calculateDailyConsumption(device) * 30.0f;
}

// Consumo total de uma residência (soma de todos os dispositivos)
float calculateTotalConsumption(Device devices[], int totalDevices) {
    float total = 0.0f;
    for (int i = 0; i < totalDevices; i++) {
        total += calculateMonthlyConsumption(devices[i]);
    }
    return total;
}

// Retorna o índice do dispositivo com maior consumo mensal
int getMostConsumingDeviceIndex(Device devices[], int totalDevices) {
    if (totalDevices == 0) return -1;

    int index = 0;
    float maxConsumption = calculateMonthlyConsumption(devices[0]);

    for (int i = 1; i < totalDevices; i++) {
        float consumption = calculateMonthlyConsumption(devices[i]);
        if (consumption > maxConsumption) {
            maxConsumption = consumption;
            index = i;
        }
    }

    return index;
}
