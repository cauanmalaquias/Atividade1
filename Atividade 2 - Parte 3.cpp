#include <stdio.h>

#define MAX_SIZE 20

struct Conjunto {
    int elementos[MAX_SIZE];
    int tamanho;
};

void criarConjuntoVazio(struct Conjunto *conjunto) {
    conjunto->tamanho = 0;
}

void lerConjunto(struct Conjunto *conjunto) {
    printf("Digite o tamanho do conjunto (no máximo %d): ", MAX_SIZE);
    scanf("%d", &conjunto->tamanho);

    if (conjunto->tamanho > MAX_SIZE) {
        printf("Tamanho excedeu o limite. Ajustando para %d.\n", MAX_SIZE);
        conjunto->tamanho = MAX_SIZE;
    }

    printf("Digite os elementos do conjunto:\n");
    for (int i = 0; i < conjunto->tamanho; i++) {
        scanf("%d", &conjunto->elementos[i]);
    }
}

void uniaoConjuntos(const struct Conjunto *conjuntoA, const struct Conjunto *conjuntoB, struct Conjunto *uniao) {
    criarConjuntoVazio(uniao);

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        uniao->elementos[uniao->tamanho] = conjuntoA->elementos[i];
        uniao->tamanho++;
    }

    for (int i = 0; i < conjuntoB->tamanho; i++) {
        int elemento = conjuntoB->elementos[i];
        int encontrado = 0;

        for (int j = 0; j < conjuntoA->tamanho; j++) {
            if (elemento == conjuntoA->elementos[j]) {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            uniao->elementos[uniao->tamanho] = elemento;
            uniao->tamanho++;
        }
    }
}

void intersecaoConjuntos(const struct Conjunto *conjuntoA, const struct Conjunto *conjuntoB, struct Conjunto *intersecao) {
    criarConjuntoVazio(intersecao);

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        int elemento = conjuntoA->elementos[i];

        for (int j = 0; j < conjuntoB->tamanho; j++) {
            if (elemento == conjuntoB->elementos[j]) {
                intersecao->elementos[intersecao->tamanho] = elemento;
                intersecao->tamanho++;
                break;
            }
        }
    }
}

void imprimirConjunto(const struct Conjunto *conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d ", conjunto->elementos[i]);
    }
    printf("}\n");
}

int main() {
    struct Conjunto conjuntoA, conjuntoB, uniao, intersecao;

    printf("Conjunto A:\n");
    lerConjunto(&conjuntoA);

    printf("Conjunto B:\n");
    lerConjunto(&conjuntoB);

    printf("União de A e B: ");
    uniaoConjuntos(&conjuntoA, &conjuntoB, &uniao);
    imprimirConjunto(&uniao);

    printf("Interseção de A e B: ");
    intersecaoConjuntos(&conjuntoA, &conjuntoB, &intersecao);
    imprimirConjunto(&intersecao);

    return 0;
}
