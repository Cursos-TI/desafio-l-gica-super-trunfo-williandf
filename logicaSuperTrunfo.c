#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Calcula a densidade demográfica
void calcularDensidade(struct Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
}

// Exibe os atributos disponíveis (exceto os já escolhidos)
void exibirMenu(int excluir) {
    printf("\nEscolha um atributo:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
    printf("Escolha: ");
}

// Compara dois atributos e retorna o valor final (invertendo para densidade)
float obterValor(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return -carta.densidadeDemografica; // Menor vence → invertemos
        default: return 0;
    }
}

// Retorna o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas fixas
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868000.0, 35};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 491000.0, 20};
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int attr1 = 0, attr2 = 0;

    // Menu para primeiro atributo
    exibirMenu(0);
    scanf("%d", &attr1);

    if (attr1 < 1 || attr1 > 5) {
        printf("Atributo inválido! Encerrando.\n");
        return 1;
    }

    // Menu para segundo atributo, excluindo o primeiro
    exibirMenu(attr1);
    scanf("%d", &attr2);

    if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
        printf("Atributo inválido ou repetido! Encerrando.\n");
        return 1;
    }

    // Obtem valores dos atributos (com tratamento para densidade)
    float valor1_attr1 = obterValor(carta1, attr1);
    float valor2_attr1 = obterValor(carta2, attr1);
    float valor1_attr2 = obterValor(carta1, attr2);
    float valor2_attr2 = obterValor(carta2, attr2);

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Exibição detalhada
    printf("\n=== Comparação Final ===\n\n");
    printf("Carta 1 - %s\n", carta1.pais);
    printf("%s: %.2f\n", nomeAtributo(attr1), (attr1 == 5 ? -
