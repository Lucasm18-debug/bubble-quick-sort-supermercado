# Classificador de Precos de Supermercado

## Objetivo

Desenvolver uma aplicacao em linguagem C que organize os precos de produtos de supermercado usando dois algoritmos de ordenacao: Bubble Sort e Quick Sort.

## Situacao-problema

Em um supermercado, organizar os produtos pelo preco facilita a comparacao entre os valores e ajuda o consumidor a identificar os itens mais baratos.

Esta aplicacao utiliza uma lista de dez produtos e demonstra como diferentes algoritmos podem resolver o mesmo problema de ordenacao.

## Funcionalidades

- Cadastro inicial de dez produtos com nomes e precos.
- Exibicao dos precos antes da ordenacao.
- Ordenacao crescente pelo Bubble Sort.
- Ordenacao crescente pelo Quick Sort.
- Exibicao dos resultados dos dois algoritmos.
- Comentarios explicativos no codigo-fonte.

## Tecnologias utilizadas

- Linguagem C
- Biblioteca padrao stdio.h
- Algoritmos de ordenacao

## Como executar

### Opcao 1: utilizando GCC

1. Tenha o compilador GCC instalado.
2. Baixe o arquivo main.c deste repositorio.
3. Abra um terminal na pasta onde o arquivo foi salvo.
4. Compile o programa:

```bash
gcc main.c -o classificador
```

5. Execute o programa.

No Linux ou macOS:

```bash
./classificador
```

No Windows, compile com:

```bash
gcc main.c -o classificador.exe
```

Depois, execute:

```powershell
.\classificador.exe
```

### Opcao 2: compilador online

Acesse https://www.onlinegdb.com/online_c_compiler, selecione C, cole o conteudo de main.c no editor e clique em Run.

## Explicacao dos algoritmos

### Bubble Sort

Compara os precos de elementos vizinhos. Quando dois elementos estao fora de ordem, eles sao trocados. O processo se repete ate que todos os elementos estejam ordenados.

Sua complexidade de tempo no pior caso e O(n²).

### Quick Sort

Escolhe um pivo e divide os elementos em partes menores e maiores que ele. Em seguida, aplica o mesmo processo recursivamente nas partes restantes.

Sua complexidade de tempo media e O(n log n), embora no pior caso possa chegar a O(n²).

## Comparacao

Os dois algoritmos recebem os mesmos dez produtos. Para evitar que a primeira ordenacao altere a segunda, o programa cria copias independentes da lista original.

Ambos devem apresentar os produtos em ordem crescente de preco.

## Autor

Lucas Emanuel

## Arquivo principal

- main.c
