#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define maxclientes 50

struct Data {
    int dia, mes, ano;
};


struct Cliente {
    char nome[50];
    struct Data dataNascimento;
    int idade;
    char sexo;
};


int calcularIdade(struct Data nascimento, struct Data atual) {
    int idade = atual.ano - nascimento.ano;
    if (atual.mes < nascimento.mes || (atual.mes == nascimento.mes && atual.dia < nascimento.dia)) {
        idade--;
    }
    return idade;
}


void exibirCliente(struct Cliente cliente) {
    printf("Nome: %s\n", cliente.nome);
    printf("Data de Nascimento: %02d/%02d/%d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
    printf("Idade: %d\n", cliente.idade);
    printf("Sexo: %c\n", cliente.sexo);
}

int main() {
    struct Cliente clientes[maxclientes];
    int numClientes = 0;
    struct Data dataAtual;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    dataAtual.dia = tm.tm_mday;
    dataAtual.mes = tm.tm_mon + 1;
    dataAtual.ano = tm.tm_year + 1900;

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                if (numClientes < maxclientes) {
                    struct Cliente novoCliente;
                    printf("\nNome: ");
                    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
                    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = 0;
                    printf("Data de Nascimento (DD MM AAAA): ");
                    scanf("%d %d %d", &novoCliente.dataNascimento.dia, &novoCliente.dataNascimento.mes, &novoCliente.dataNascimento.ano);
                    getchar();
                    printf("Sexo (M/F): ");
                    scanf(" %c", &novoCliente.sexo);
                    novoCliente.idade = calcularIdade(novoCliente.dataNascimento, dataAtual);
                    clientes[numClientes++] = novoCliente;
                    printf("Cliente cadastrado com sucesso!\n");
                } else {
                    printf("Limite de clientes atingido!\n");
                }
                break;
            }
            case 2: {
                if (numClientes > 0) {
                    printf("\nClientes cadastrados:\n");
                    for (int i = 0; i < numClientes; i++) {
                        printf("Cliente %d:\n", i + 1);
                        exibirCliente(clientes[i]);
                    }
                } else {
                    printf("\nNenhum cliente cadastrado.\n");
                }
                break;
            }
            case 3:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Por favor, escolha novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
