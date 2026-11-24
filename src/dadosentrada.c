#include <stdio.h>
#include <stdlib.h>
#include "dadosentrada.h"

// Lê o arquivo texto, aloca o vetor e preenche os structs
int carregar_dados(char *caminho_arquivo, DadosEntrada *dados) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 0;
    }

    dados->poder_total = 0;
    fscanf(arquivo, "%d", &dados->N);

    dados->pokemons = (Pokemon*) malloc(dados->N * sizeof(Pokemon));
    if (dados->pokemons == NULL) {
        printf("Erro de alocação de memória!\n");
        fclose(arquivo);
        return 0;
    }

    for (int i = 0; i < dados->N; i++) {
        int num, poder;
        char nome[TAMANHO_NOME], tipo[TAMANHO_TIPO];

        fscanf(arquivo, "%d %s %s %d", &num, nome, tipo, &poder);
        set(&dados->pokemons[i], i + 1, num, nome, tipo, poder);
        dados->poder_total += poder;
    }

    fclose(arquivo);
    return 1;
}

// Libera o vetor dinâmico alocado na leitura
void libera_dados(DadosEntrada *dados) {
    if (dados->pokemons != NULL) {
        free(dados->pokemons);
        dados->pokemons = NULL;
    }
}

int get_numpokes(DadosEntrada *dados) {
    return dados->N;
}

int* get_podertotal(DadosEntrada *dados) {
    return &dados->poder_total;
}

Pokemon* get_pokemons(DadosEntrada *dados) {
    return dados->pokemons;
}