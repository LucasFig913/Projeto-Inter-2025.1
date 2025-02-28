#include <stdio.h>
#include "../include/cadastro.h"

void menuCadastro() {
    int opcao;

        // Opções que o usuário pode escolher
        printf("1 - Cadastrar\n");
        printf("2 - Cadastrar equipamento\n");
        printf("3 - Voltar\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        // Switch para usuário selecionar a opção desejada, assim chamando a função correspondente
        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                cadastrarEquipamento();
                break;
            case 3:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
}

void cadastrarUsuario() {
    printf("Cadastro de usuário em desenvolvimento...\n");
}

void cadastrarEquipamento() {
    printf("Cadastro de equipamento em desenvolvimento...\n");
}

int main() {
    menuCadastro();
    return 0;
}