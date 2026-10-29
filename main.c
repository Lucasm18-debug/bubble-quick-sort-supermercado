#include <stdio.h>

#define QUANTIDADE 10

// Cada produto possui um nome e um preco armazenado em centavos.
typedef struct {
    char nome[30];
    int precoCentavos;
} Produto;

// Exibe os produtos e seus respectivos precos.
void mostrarProdutos(Produto produtos[], int tamanho, char titulo[]) {
    printf("\n========== %s ==========\n", titulo);

    for (int i = 0; i < tamanho; i++) {
        printf("%-22s R$ %d,%02d\n",
               produtos[i].nome,
               produtos[i].precoCentavos / 100,
               produtos[i].precoCentavos % 100);
    }
}

// Bubble Sort: compara os elementos vizinhos e os troca
// quando estao fora de ordem. A cada passagem, o maior
// preco restante vai para o final da lista.
void bubbleSort(Produto produtos[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int trocou = 0;

        for (int j = 0; j < tamanho - i - 1; j++) {
            if (produtos[j].precoCentavos >
                produtos[j + 1].precoCentavos) {

                Produto temporario = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temporario;

                trocou = 1;
            }
        }

        // Se nao houve trocas, a lista ja esta ordenada.
        if (trocou == 0) {
            break;
        }
    }
}

// Quick Sort: utiliza um pivo para separar os elementos
// menores e maiores. Depois, ordena cada parte recursivamente.
void quickSort(Produto produtos[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    int i = inicio;
    int j = fim;

    // O pivo e escolhido a partir do elemento central.
    int pivo = produtos[inicio + (fim - inicio) / 2].precoCentavos;

    while (i <= j) {
        // Procura um preco que deveria ficar a direita.
        while (produtos[i].precoCentavos < pivo) {
            i++;
        }

        // Procura um preco que deveria ficar a esquerda.
        while (produtos[j].precoCentavos > pivo) {
            j--;
        }

        // Troca os elementos que estao no lado errado.
        if (i <= j) {
            Produto temporario = produtos[i];
            produtos[i] = produtos[j];
            produtos[j] = temporario;

            i++;
            j--;
        }
    }

    // Ordena recursivamente as partes restantes.
    if (inicio < j) {
        quickSort(produtos, inicio, j);
    }

    if (i < fim) {
        quickSort(produtos, i, fim);
    }
}

int main(void) {
    // Conjunto original com dez produtos de supermercado.
    Produto original[QUANTIDADE] = {
        {"Arroz (5 kg)", 2890},
        {"Leite (1 litro)", 549},
        {"Feijao (1 kg)", 899},
        {"Macarrao (500 g)", 479},
        {"Oleo (900 ml)", 699},
        {"Acucar (1 kg)", 459},
        {"Cafe (500 g)", 1590},
        {"Farinha (1 kg)", 599},
        {"Molho de tomate", 329},
        {"Biscoito", 399}
    };

    // Copias independentes para os dois algoritmos.
    Produto listaBubble[QUANTIDADE];
    Produto listaQuick[QUANTIDADE];

    for (int i = 0; i < QUANTIDADE; i++) {
        listaBubble[i] = original[i];
        listaQuick[i] = original[i];
    }

    // Apresenta os dados antes de qualquer ordenacao.
    mostrarProdutos(original, QUANTIDADE, "PRECOS ORIGINAIS");

    // Executa o Bubble Sort e exibe seu resultado.
    bubbleSort(listaBubble, QUANTIDADE);
    mostrarProdutos(listaBubble, QUANTIDADE, "RESULTADO BUBBLE SORT");

    // Executa o Quick Sort sobre a mesma lista original.
    quickSort(listaQuick, 0, QUANTIDADE - 1);
    mostrarProdutos(listaQuick, QUANTIDADE, "RESULTADO QUICK SORT");

    printf("\nOrdenacao concluida com sucesso!\n");

    return 0;
}
