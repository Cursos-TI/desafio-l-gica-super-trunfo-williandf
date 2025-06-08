#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular os atributos derivados da carta
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para imprimir os dados de uma carta
void exibirCarta(struct Carta carta, int numero) {
    printf("Carta %d - %s (%s):\n", numero, carta.cidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", carta.pibPerCapita);
}

int main() {
    // Cadastro das duas cartas manualmente
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 760000.00, 20};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1182.30, 420000.00, 15};

    // Calcula indicadores derivados
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibe as cartas cadastradas
    printf("=== Cartas Cadastradas ===\n\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparação com base no atributo "População"
    printf("=== Comparação de Cartas (Atributo: População) ===\n\n");

    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    // Determina o vencedor
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
