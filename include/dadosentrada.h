#ifndef DADOSENTRADA_H
#define DADOSENTRADA_H
#define ARQUIVO_PADRAO "arquivo.txt"

#include "pokemon.h"

typedef struct {
    int N;
    int poder_total;
    Pokemon *pokemons;
} DadosEntrada;

int carregar_dados(char *caminho_arquivo, DadosEntrada *dados);
void libera_dados(DadosEntrada *dados);

int get_numpokes(DadosEntrada *dados);
int* get_podertotal(DadosEntrada *dados);
Pokemon* get_pokemons(DadosEntrada *dados);

#endif