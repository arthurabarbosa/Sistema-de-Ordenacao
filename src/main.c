#include <stdio.h>
#include <time.h>
#include "pokemon.h"
#include "pokelista.h"
#include "centropesquisa.h"
#include "dadosarquivo.h"

int main() {
    // Declaração de variáveis para acessar as estruturas
    DadosArquivo dadosbubble;
    DadosArquivo dadosquick;
    Metricas metricas;
    struct timespec iniciotempo, fimtempo;

    // Carrega duas cópias independentes para testar os dois algoritmos
    carregar_dados(ARQUIVO_ENTRADA_PADRAO, &dadosbubble);
    carregar_dados(ARQUIVO_ENTRADA_PADRAO, &dadosquick);

    int n = get_numpokes(&dadosbubble);

    // --- BubbleSort ---
    prepara_metricas(&metricas);
    timespec_get(&iniciotempo, TIME_UTC);

    bubbleSort(get_pokemons(&dadosbubble), &metricas, n);

    timespec_get(&fimtempo, TIME_UTC);
    double tempo_execucao_bubble = (fimtempo.tv_sec - iniciotempo.tv_sec) + (fimtempo.tv_nsec - iniciotempo.tv_nsec) / 1e9;

    printf("--- Pokemons Ordenados: BubbleSort (n = %d) ---\n", n);
    printf("Tempo de Execucao (BubbleSort): %.5f segundos\n", tempo_execucao_bubble);
    printf("Numero de comparacoes (BubbleSort): %lld\n", metricas.comparacoes);
    printf("Numero de movimentacoes (BubbleSort): %lld\n\n", metricas.movimentacoes);

    // --- QuickSort ---
    prepara_metricas(&metricas);
    timespec_get(&iniciotempo, TIME_UTC);

    quickSort(get_pokemons(&dadosquick), &metricas, 0, n - 1);

    timespec_get(&fimtempo, TIME_UTC);
    double tempo_execucao_quick = (fimtempo.tv_sec - iniciotempo.tv_sec) + (fimtempo.tv_nsec - iniciotempo.tv_nsec) / 1e9;

    printf("--- Pokemons Ordenados: QuickSort (n = %d) ---\n", n);
    printf("Tempo de Execucao (QuickSort): %.5f segundos\n", tempo_execucao_quick);
    printf("Numero de comparacoes (QuickSort): %lld\n", metricas.comparacoes);
    printf("Numero de movimentacoes (QuickSort): %lld\n\n", metricas.movimentacoes);

    // Salva o resultado ordenado no arquivo de saída
    if (salvar_dados(ARQUIVO_SAIDA_PADRAO, &dadosquick)) {
        printf("Arquivo '%s' gerado com sucesso\n", ARQUIVO_SAIDA_PADRAO);
    }

    // Libera memória alocada
    libera_dados(&dadosbubble);
    libera_dados(&dadosquick);

    return 0;
}