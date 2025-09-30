#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[4];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;

    
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular
void calcularAtributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder =
        (float)carta->populacao +
        carta->area +
        carta->pib +
        carta->pontos_turisticos +
        carta->pib_per_capita +
        (1.0f / carta->densidade_populacional);
}

// ler dados da carta
void lerCarta(Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Digite o estado (UF): ");
    scanf("%2s", carta->estado);

    printf("Digite o código da carta: ");
    scanf("%3s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    calcularAtributos(carta);
}

// Função para comparar atributos
void compararCartas(Carta c1, Carta c2) {
    printf("\n--- Comparação de Cartas ---\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);

    //vence quem tem menor
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional);

    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}