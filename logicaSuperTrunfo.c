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

// Calcula densidade demográfica
void calcularDensidade(struct Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
}

// Exibe dados de uma carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\nCarta %d - %s\n", numero, carta.pais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidadeDemografica);
}

int main() {
    // Cadastro fixo das duas cartas
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868000.0, 35};
    struct Carta carta2 = {"Argentina", 45380000, 2780400.0, 491000.0, 20};

    // Calcula densidade
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    // Mostra cartas
    printf("=== Cartas Cadastradas ===");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu interativo
    int opcao;
    printf("\n=== Escolha o atributo para comparar ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n=== Resultado da Comparação ===\n");

    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.pais, carta1.populacao);
            printf("%s: %d\n", carta2.pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.pais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.pais, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.pais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.pais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.pais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (menor vence)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.pais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.pais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf
