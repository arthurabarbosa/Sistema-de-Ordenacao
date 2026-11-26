#ifndef DADOSARQUIVO_H
#define DADOSARQUIVO_H
#define MS_POR_SEGUNDO 1000.0
#define ARQUIVO_ENTRADA_PADRAO "arquivo.txt"
#define ARQUIVO_SAIDA_PADRAO "saida.txt"

#include "pokemon.h"

// Armazena os dados manipulados nos arquivos de entrada e saída
typedef struct {
    int N;                // Quantidade total de Pokémons
    int poder_total;      // Soma dos pontos de poder
    Pokemon *pokemons;    // Vetor dinâmico de Pokémons
} DadosArquivo;

int carregar_dados(const char *caminho_arquivo, DadosArquivo *dados);
int salvar_dados(const char *caminho_arquivo, DadosArquivo *dados);
void libera_dados(DadosArquivo *dados);

int get_numpokes(DadosArquivo *dados);
int* get_podertotal(DadosArquivo *dados);
Pokemon* get_pokemons(DadosArquivo *dados);

#endif