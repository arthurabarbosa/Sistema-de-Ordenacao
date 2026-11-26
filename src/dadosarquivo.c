#include <stdio.h>
#include <stdlib.h>
#include "dadosarquivo.h"

// Lê o arquivo texto, aloca o vetor e preenche os structs
int carregar_dados(const char *caminho_arquivo, DadosArquivo *dados) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 0;
    }

    dados->poder_total = 0;
    fscanf(arquivo, "%d", &dados->N);

    dados->pokemons = (Pokemon*) malloc(dados->N * sizeof(Pokemon));
    if (dados->pokemons == NULL) {
        printf("Erro de alocacao de memoria!\n");
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

// Salva o vetor de Pokémons e seus atributos no arquivo de saída
int salvar_dados(const char *caminho_arquivo, DadosArquivo *dados) {
    FILE *arquivo = fopen(caminho_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de saida\n");
        return 0;
    }

    fprintf(arquivo, "%d\n", dados->N);
    for (int i = 0; i < dados->N; i++) {
        fprintf(arquivo, "ID: %d | Pokedex: %d | Nome: %s | Tipo: %s | Poder: %d\n",
                dados->pokemons[i].id,
                dados->pokemons[i].numero_pokedex,
                dados->pokemons[i].nome,
                dados->pokemons[i].tipo,
                dados->pokemons[i].pt_poder);
    }

    fclose(arquivo);
    return 1;
}

// Libera o vetor dinâmico alocado na leitura
void libera_dados(DadosArquivo *dados) {
    if (dados->pokemons != NULL) {
        free(dados->pokemons);
        dados->pokemons = NULL;
    }
}

int get_numpokes(DadosArquivo *dados) {
    return dados->N;
}

int* get_podertotal(DadosArquivo *dados) {
    return &dados->poder_total;
}

Pokemon* get_pokemons(DadosArquivo *dados) {
    return dados->pokemons;
}