# Sistema de Ordenação

Implementação em C para análise comparativa de desempenho entre os algoritmos de ordenação **Bubble Sort** e **Quick Sort**, aplicados a um conjunto de registros estruturados (Pokémons) ordenados pelos seus pontos de poder.

## Estrutura do Projeto

- `include/`: Arquivos de cabeçalho (`.h`) com as definições das estruturas e protótipos das funções.
  - `pokemon.h`: TAD que representa o registro `Pokemon` e suas operações básicas.
  - `dadosentrada.h`: Leitura e armazenamento dinâmico dos dados a partir do arquivo de entrada.
  - `ordenacao.h`: Implementação dos algoritmos Bubble Sort, Quick Sort e da estrutura `Metricas`.
  - `centropesquisa.h`: Estrutura auxiliar para gerenciamento de registros recuperados.
- `src/`: Arquivos de código-fonte (`.c`) com as implementações dos módulos e da função `main`.
- `bin/`: Diretório de saída para o executável compilado.
- `arquivo.txt`: Arquivo de entrada contendo a quantidade $N$ de registros seguida pelos dados de cada elemento.
- `Makefile`: Script de automação para compilação, execução e limpeza do projeto.

## Métricas Avaliadas

Para cada algoritmo executado sobre o mesmo conjunto de dados, o programa contabiliza:
- **Comparações:** Número de vezes em que as chaves (`pt_poder`) de dois registros são comparadas.
- **Movimentações:** Número de atribuições de registros realizadas durante as trocas (3 movimentações por operação de troca entre elementos distintos).

## Como Compilar e Executar

Certifique-se de ter o compilador `gcc` e o utilitário `make` (ou `mingw32-make` no Windows) instalados.

1. **Compilar o projeto:**
   ```bash
   mingw32-make compile