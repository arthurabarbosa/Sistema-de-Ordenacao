#include <stdio.h>
#include "pokemon.h"
#include "pokelista.h"
#include "centropesquisa.h"
#include "dadosentrada.h"

int main() {
    DadosEntrada dadosbubble;
    DadosEntrada dadosquick;
    Metricas metricas;

    // Carrega duas cópias independentes para testar os dois algoritmos
    if (!carregar_dados(ARQUIVO_PADRAO, &dadosbubble) || 
        !carregar_dados(ARQUIVO_PADRAO, &dadosquick)) {
        return 1;
    }

    // Exibe entrada original
    printf("--- Pokemons Carregados ---\n");
    printf("\n");

    // Executa e exibe métricas do BubbleSort
    prepara_metricas(&metricas);
    bubbleSort(get_pokemons(&dadosbubble), &metricas, get_numpokes(&dadosbubble));

    printf("--- Pokemons Ordenados: BubbleSort ---\n");
    printf("\nNumero de comparacoes (BubbleSort): %lld\n", metricas.comparacoes);
    printf("Numero de movimentacoes (BubbleSort): %lld\n\n", metricas.movimentacoes);

    // Executa e exibe métricas do QuickSort
    prepara_metricas(&metricas);
    quickSort(get_pokemons(&dadosquick), &metricas, 0, get_numpokes(&dadosquick) - 1);

    printf("--- Pokemons Ordenados: QuickSort ---\n");
    printf("\nNumero de comparacoes (QuickSort): %lld\n", metricas.comparacoes);
    printf("Numero de movimentacoes (QuickSort): %lld\n", metricas.movimentacoes);

    // Libera memória alocada
    libera_dados(&dadosbubble);
    libera_dados(&dadosquick);

    return 0;
}