#include <stdio.h>
#include "../include/cadastro.h"

void menuCadastro() {
    int opcao;

        do {// Opções que o usuário pode escolher
        printf("Ola, bem vindo ao projeto interdisciplinar!\n\n");
        printf("1 - Nao tem cadastro? Selecione esta opcao.\n");
        printf("2 - Ja tem uma conta? Selecione esta opcao.\n");
        //printf("3 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        // Switch para usuário selecionar a opção desejada, assim chamando a função correspondente
        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                loginUsuario();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n\n");
        }
    } while (opcao != 1 && opcao != 2);
}

void cadastrarUsuario() {
    char nome[50];
    int cpf;

    printf("Digite seu nome completo: \n");
    scanf("%s", nome);

}

void loginUsuario() {
    printf("Login do usuario em desenvolvimento...\n");
}

int main() {
    menuCadastro();
    return 0;
}