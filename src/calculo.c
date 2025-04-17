#include <stdio.h>
#include "../include/calculo.h"

// Define o número total de equipamentos disponíveis
//#define TOTAL_EQUIPAMENTOS 7

// Estrutura que representa um equipamento
/*typedef struct {
    char nome[50];          // Nome do equipamento
    int voltagem;           // Campo mantido, mas não utilizado
    int quantidade;         // Quantidade de aparelhos do mesmo tipo
    float usoDiario;        // Horas de uso diário
    float potenciaWatts;    // Potência do aparelho (em watts)
    float consumoTotal;     // Consumo diário em kWh
} Equipamento;*/

// Lista com os nomes fixos dos equipamentos
/*const char* nomesEquipamentos[TOTAL_EQUIPAMENTOS] = {
    "TV", "Ventilador", "Ar-condicionado", "Notebook", "PC", "Máquina de lavar", "Geladeira"
};*/

// Potência média em watts de cada equipamento correspondente à lista acima
//float potenciasWatts[TOTAL_EQUIPAMENTOS] = {100, 80, 1000, 65, 250, 500, 150};

// Função que retorna o custo por kWh baseado na bandeira tarifária escolhida
/*float obterCustoPorKWh(int bandeira) {
    switch (bandeira) {
        case 1: return 0.6f;   // Bandeira verde
        case 2: return 1.0f;   // Bandeira amarela
        case 3: return 1.5f;   // Bandeira vermelha
        default: return 0.0f;
    }
}*/

// Função que retorna o nome da bandeira, a partir do número escolhido
/*const char* nomeBandeira(int bandeira) {
    switch (bandeira) {
        case 1: return "Verde";
        case 2: return "Amarela";
        case 3: return "Vermelha";
        default: return "Desconhecida";
    }
}*/

// Função que calcula o consumo total diário do equipamento
/*void calcularConsumo(Equipamento *e) {
    e->consumoTotal = (e->potenciaWatts * e->usoDiario * e->quantidade) / 1000.0;
    // Fórmula: (potência x horas x quantidade) / 1000 = kWh
}*/

/*int main() {
    int bandeira;

    // === Etapa de escolha da bandeira de energia ===
    do {
        printf("Escolha a bandeira de energia:\n");
        printf("1 - Verde\n2 - Amarela\n3 - Vermelha\nOpção: ");
        scanf("%d", &bandeira);
    } while (bandeira < 1 || bandeira > 3);

    // Calcula o valor por kWh da bandeira selecionada
    float custoKWh = obterCustoPorKWh(bandeira);

    int selecionados[TOTAL_EQUIPAMENTOS] = {0};  // Marca os equipamentos selecionados pelo usuário
    int continuar = 0;  // Controle do loop de seleção

    // === Loop de seleção de equipamentos ===
    while (!continuar) {
        printf("\nEquipamentos disponíveis:\n");
        for (int i = 0; i < TOTAL_EQUIPAMENTOS; i++)
            printf("%d - %s\n", i + 1, nomesEquipamentos[i]);

        // Lê a entrada dos equipamentos escolhidos (ex: "1 3 4")
        printf("\nDigite os números dos equipamentos separados por espaço (ex: 1 3 4): ");
        int entrada;
        char linha[100];
        getchar();  // Limpa buffer antes de usar fgets
        fgets(linha, sizeof(linha), stdin);  // Lê linha inteira
        char *token = strtok(linha, " ");  // Separa os números da linha

        // Marca os equipamentos selecionados
        while (token) {
            sscanf(token, "%d", &entrada);
            if (entrada >= 1 && entrada <= TOTAL_EQUIPAMENTOS)
                selecionados[entrada - 1] = 1;
            token = strtok(NULL, " ");
        }

        // Mostra os equipamentos já selecionados
        printf("\nEquipamentos selecionados:\n");
        for (int i = 0; i < TOTAL_EQUIPAMENTOS; i++)
            if (selecionados[i]) printf("- %s\n", nomesEquipamentos[i]);

        // Menu para o usuário continuar ou editar a seleção
        int opcao;
        printf("\n1 - Continuar\n2 - Adicionar\n3 - Remover\n4 - Cancelar\nOpção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            continuar = 1;  // Sai do loop e passa para o cadastro
        } else if (opcao == 3) {
            printf("Digite o número do equipamento para remover: ");
            scanf("%d", &entrada);
            if (entrada >= 1 && entrada <= TOTAL_EQUIPAMENTOS)
                selecionados[entrada - 1] = 0;  // Remove o equipamento da seleção
        } else if (opcao == 4) {
            printf("Operação cancelada.\n");
            return 0;  // Encerra o programa
        }
    }

    // === Cadastro de dados de uso dos equipamentos ===
    Equipamento equipamentos[TOTAL_EQUIPAMENTOS];
    float custoTotal = 0, maior = -1, menor = -1;
    int indMaior = -1, indMenor = -1;

    // Para cada equipamento selecionado, solicita os dados de uso
    for (int i = 0; i < TOTAL_EQUIPAMENTOS; i++) {
        if (!selecionados[i]) continue;  // Pula os não selecionados

        Equipamento *e = &equipamentos[i];
        strcpy(e->nome, nomesEquipamentos[i]);  // Copia nome e potência
        e->potenciaWatts = potenciasWatts[i];

        printf("\n--- %s ---\n", e->nome);

        // REMOVIDO: Pergunta sobre voltagem

        // Pergunta a quantidade de aparelhos
        printf("Quantidade: ");
        scanf("%d", &e->quantidade);

        // Pergunta as horas de uso diário
        printf("Horas de uso por dia: ");
        scanf("%f", &e->usoDiario);

        // Calcula o consumo diário
        calcularConsumo(e);

        // Calcula custo mensal para esse equipamento (30 dias)
        float custo = e->consumoTotal * custoKWh * 30;
        custoTotal += custo;  // Soma ao custo total

        // Verifica maior e menor consumo
        if (maior == -1 || e->consumoTotal > maior) {
            maior = e->consumoTotal;
            indMaior = i;
        }
        if (menor == -1 || e->consumoTotal < menor) {
            menor = e->consumoTotal;
            indMenor = i;
        }

        // Exibe o consumo e custo para o usuário
        printf("Consumo diário: %.2f kWh | Custo mensal: R$ %.2f\n", e->consumoTotal, custo);
    }

    // === Exibição do resumo final ===
    printf("\n=== RESUMO FINAL ===\n");
    printf("Bandeira: %s\n", nomeBandeira(bandeira));
    if (indMaior != -1)
        printf("Maior consumo: %s (%.2f kWh/dia)\n", nomesEquipamentos[indMaior], maior);
    if (indMenor != -1)
        printf("Menor consumo: %s (%.2f kWh/dia)\n", nomesEquipamentos[indMenor], menor);
    printf("Custo total mensal: R$ %.2f\n", custoTotal);

    return 0;
}*/

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
