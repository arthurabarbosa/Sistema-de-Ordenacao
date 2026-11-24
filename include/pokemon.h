#ifndef POKEMON_H
#define POKEMON_H

#define TAMANHO_NOME 50
#define TAMANHO_TIPO 50

// Estrutura que representa um Pokémon
typedef struct {
    int id;                       // Identificador do pokemon
    int numero_pokedex;           // Número correspondente na Pokédex
    char nome[TAMANHO_NOME];      // Nome do pokemon
    char tipo[TAMANHO_TIPO];      // Tipo
    int pt_poder;                 // Pontos de poder do pokemon
} Pokemon;

// Atribui os valores aos campos do Pokémon
int set(Pokemon *pk, int id, int numero, char *name, char *type, int pt_poder);

// Funções get para acessar as propriedades do Pokémon
int get_id(Pokemon *pk);
int get_numeropokedex(Pokemon *pk);
void get_nome(Pokemon *pk, char *name);
void get_tipo(Pokemon *pk, char *type);
int get_pt_poder(Pokemon *pk);

// Imprime informações básicas sobre o Pokémon ou sobre um vetor de Pokémons
void imprime_pokemon(Pokemon *pk);
void imprime_vetor(Pokemon *vetor, int n);

#endif