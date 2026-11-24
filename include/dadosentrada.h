#ifndef DADOSENTRADA_H
#define DADOSENTRADA_H

#define ARQUIVO_PADRAO "arquivo.txt"
#include "pokemon.h"

// Armazena os dados lidos do arquivo de entrada
typedef struct {
    int N;                // Quantidade total de Pokémons
    int poder_total;      // Soma dos pontos de poder
    Pokemon *pokemons;    // Vetor dinâmico de Pokémons
} DadosEntrada;

int carregar_dados(char *caminho_arquivo, DadosEntrada *dados);
void libera_dados(DadosEntrada *dados);

int get_numpokes(DadosEntrada *dados);
int* get_podertotal(DadosEntrada *dados);
Pokemon* get_pokemons(DadosEntrada *dados);

#endif