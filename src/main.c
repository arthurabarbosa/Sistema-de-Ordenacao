#include <stdio.h>
#include "pokemon.h"
#include "dadosentrada.h"
#include "ordenacao.h"

int main() {
    DadosEntrada dadosbubble;
    DadosEntrada dadosquick;
    Metricas metricas;

    carregar_dados(ARQUIVO_PADRAO, &dadosbubble);
    carregar_dados(ARQUIVO_PADRAO, &dadosquick);

    // Imprime o vetor original, sem ordenação
    printf("--- Pokemons Carregados ---\n");
    imprime_vetor(get_pokemons(&dadosbubble), get_numpokes(&dadosbubble));
    printf("\n");

    // --- BUBBLE SORT ---
    printf("=== Executando Ordenação dos Pokemons (BubbleSort) ===\n\n");
    prepara_metricas(&metricas);
    bubbleSort(get_pokemons(&dadosbubble), &metricas, get_numpokes(&dadosbubble));

    printf("--- Pokemons Ordenados: BubbleSort ---\n");
    imprime_vetor(get_pokemons(&dadosbubble), get_numpokes(&dadosbubble));
    printf("\n");
    printf("Número de comparações (BubbleSort): %lld\n", metricas.comparacoes);
    printf("Número de movimentações (BubbleSort): %lld\n\n", metricas.movimentacoes);

    // --- QUICK SORT ---
    printf("=== Executando Ordenação dos Pokemons (QuickSort) ===\n\n");
    prepara_metricas(&metricas);
    quickSort(get_pokemons(&dadosquick), &metricas, 0, get_numpokes(&dadosquick) - 1);

    printf("--- Pokemons Ordenados: QuickSort ---\n");
    imprime_vetor(get_pokemons(&dadosquick), get_numpokes(&dadosquick));
    printf("\n");
    printf("Número de comparações (QuickSort): %lld\n", metricas.comparacoes);
    printf("Número de movimentações (QuickSort): %lld\n", metricas.movimentacoes);

    // Libera a memória alocada
    libera_dados(&dadosbubble);
    libera_dados(&dadosquick);

    return 0;
}