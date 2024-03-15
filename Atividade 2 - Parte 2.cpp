#include <stdio.h>
#include <string.h>

#define maxfuncionarios 10


struct Funcionario {
    char nome[50];
    char cargo[50];
    float salarioBase;
    float beneficios;
    float descontos;
    float salarioliquido;
};


struct Loja {
    struct Funcionario funcionarios[maxfuncionarios];
    int totalFuncionarios;
};


void cadastrarFuncionario(struct Loja *loja) {
    if (loja->totalFuncionarios >= maxfuncionarios) {
        printf("Limite de funcionários atingido.\n");
        return;
    }

    struct Funcionario novoFuncionario;
    printf("Cadastro de Funcionário:\n");
    printf("Nome: ");
    scanf("%s", novoFuncionario.nome);
    printf("Cargo: ");
    scanf("%s", novoFuncionario.cargo);
    printf("Salario Base: ");
    scanf("%f", &novoFuncionario.salarioBase);
    printf("Beneficios: ");
    scanf("%f", &novoFuncionario.beneficios);
    printf("Descontos: ");
    scanf("%f", &novoFuncionario.descontos);

    novoFuncionario.salarioliquido = novoFuncionario.salarioBase + novoFuncionario.beneficios - novoFuncionario.descontos;

    loja->funcionarios[loja->totalFuncionarios] = novoFuncionario;
    loja->totalFuncionarios++;
    printf("Funcionário cadastrado com sucesso!\n");
}


void calcularSalarioLiquido(struct Loja *loja) {
    printf("Salario Liquido de Funcionarios:\n");
    for (int i = 0; i < loja->totalFuncionarios; i++) {
        printf("Nome: %-20s Salario Liquido: %.2f\n", loja->funcionarios[i].nome, loja->funcionarios[i].salarioliquido);
    }
}


void calcularMediaSalarial(struct Loja *loja) {
    float totalSalarios = 0;
    for (int i = 0; i < loja->totalFuncionarios; i++) {
        totalSalarios += loja->funcionarios[i].salarioliquido;
    }

    if (loja->totalFuncionarios > 0) {
        float mediaSalarial = totalSalarios / loja->totalFuncionarios;
        printf("Media Salarial da Loja: %.2f\n", mediaSalarial);
    } else {
        printf("Nenhum funcionario cadastrado.\n");
    }
}


void exibirMaiorSalario(struct Loja *loja) {
    if (loja->totalFuncionarios == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    float maiorSalario = loja->funcionarios[0].salarioliquido;
    int indiceMaiorSalario = 0;
    for (int i = 1; i < loja->totalFuncionarios; i++) {
        if (loja->funcionarios[i].salarioliquido > maiorSalario) {
            maiorSalario = loja->funcionarios[i].salarioliquido;
            indiceMaiorSalario = i;
        }
    }

    printf("Funcionario com Maior Salario:\n");
    printf("Nome: %-20s Salario Liquido: %.2f\n", loja->funcionarios[indiceMaiorSalario].nome, maiorSalario);
}

int main() {
    struct Loja minhaLoja;
    minhaLoja.totalFuncionarios = 0;

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Funcionario\n");
        printf("2. Calcular Salario Liquido\n");
        printf("3. Calcular Media Salarial\n");
        printf("4. Exibir Funcionario com Maior Salario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario(&minhaLoja);
                break;
            case 2:
                calcularSalarioLiquido(&minhaLoja);
                break;
            case 3:
                calcularMediaSalarial(&minhaLoja);
                break;
            case 4:
                exibirMaiorSalario(&minhaLoja);
                break;
            case 0:
                printf("Encerrando o Programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}