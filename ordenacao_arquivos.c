#include <stdio.h>

#define MAX 100

void criarArquivo();
int lerArquivo(int numeros[]);
void salvarArquivo(int numeros[], int quantidade, char nomeArquivo[]), mostrarNumeros(int numeros[], int quantidade), bubbleSort(int numeros[], int quantidade), 
insertionSort(int numeros[], int quantidade), selectionSort(int numeros[], int quantidade), mergeSort(int numeros[], int inicio, int fim), quickSort(int numeros[], int inicio, int fim);

void juntar(int numeros[], int inicio, int meio, int fim);

int particionar(int numeros[], int inicio, int fim);

int main() {
    int numeros[MAX], quantidade, opcao, metodo, posicao, novoValor, i;

    criarArquivo();

    do {
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("[1] Mostrar numeros do arquivo\n");
        printf("[2] Ordenar numeros\n");
        printf("[3] Alterar um numero do arquivo\n");
        printf("[4] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                quantidade = lerArquivo(numeros);

                if (quantidade > 0) {
                    printf("\nNumeros encontrados no arquivo:\n");
                    mostrarNumeros(numeros, quantidade);
                } else {
                    printf("\nNao existem numeros no arquivo.\n");
                }
                break;
            case 2:
                quantidade = lerArquivo(numeros);

                if (quantidade == 0) {
                    printf("\nNao existem numeros para ordenar.\n");
                    break;
                }
                printf("\n========== TIPOS DE ORDENACAO ==========\n");
                printf("[1] Bubble Sort\n");
                printf("[2] Insertion Sort\n");
                printf("[3] Selection Sort\n");
                printf("[4] Merge Sort\n");
                printf("[5] Quick Sort\n");
                printf("Escolha o metodo: ");
                scanf("%d", &metodo);

                switch (metodo) {
                    case 1:
                        bubbleSort(numeros, quantidade);
                        printf("\nMetodo utilizado: Bubble Sort\n");
                        break;
                    case 2:
                        insertionSort(numeros, quantidade);
                        printf("\nMetodo utilizado: Insertion Sort\n");
                        break;
                    case 3:
                        selectionSort(numeros, quantidade);
                        printf("\nMetodo utilizado: Selection Sort\n");
                        break;
                    case 4:
                        mergeSort(numeros, 0, quantidade - 1);
                        printf("\nMetodo utilizado: Merge Sort\n");
                        break;
                    case 5:
                        quickSort(numeros, 0, quantidade - 1);
                        printf("\nMetodo utilizado: Quick Sort\n");
                        break;
                    default:
                        printf("\nOpcao de ordenacao invalida!\n");
                        break;
                }

                if (metodo >= 1 && metodo <= 5) {
                    salvarArquivo(numeros, quantidade, "ordenado.txt");

                    printf("\nNumeros ordenados:\n");
                    mostrarNumeros(numeros, quantidade);

                    printf("\nResultado salvo em ordenado.txt!\n");
                }
                break;
            case 3:
                quantidade = lerArquivo(numeros);

                if (quantidade == 0) {
                    printf("\nNao existem numeros para alterar.\n");
                    break;
                }
                printf("\nNumeros atuais:\n");
                for (i = 0; i < quantidade; i++) {
                    printf("Posicao %d: %d\n", i, numeros[i]);
                }
                printf("\nDigite a posicao que deseja alterar: ");
                scanf("%d", &posicao);
                if (posicao < 0 || posicao >= quantidade) {
                    printf("\nPosicao invalida!\n");
                    break;
                }
                printf("Digite o novo valor: ");
                scanf("%d", &novoValor);

                numeros[posicao] = novoValor;

                salvarArquivo(numeros, quantidade, "dados.txt");
                printf("\nValor alterado com sucesso!\n");
                printf("\nArquivo atualizado:\n");
                mostrarNumeros(numeros, quantidade);
                printf("\nAgora voce pode ordenar novamente pelo menu.\n");
                break;
            case 4:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);
    return 0;
}

void criarArquivo() {
    FILE *arquivo;
    int quantidade, numero, i;

    arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    printf("========== CRIACAO DO ARQUIVO ==========\n");
    printf("Quantos numeros deseja cadastrar? (1 a 100): ");
    scanf("%d", &quantidade);
    if (quantidade < 1 || quantidade > MAX) {
        printf("Quantidade invalida!\n");
        fclose(arquivo);
        return;
    }
    for (i = 0; i < quantidade; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numero);

        fprintf(arquivo, "%d\n", numero);
    }
    fclose(arquivo);
    printf("\nArquivo dados.txt criado com sucesso!\n");
}

int lerArquivo(int numeros[]) {
    FILE *arquivo;
    int quantidade = 0;

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir dados.txt!\n");
        return 0;
    }
    while (quantidade < MAX &&
           fscanf(arquivo, "%d", &numeros[quantidade]) == 1) {
        quantidade++;
    }
    fclose(arquivo);
    return quantidade;
}

void salvarArquivo(int numeros[], int quantidade, char nomeArquivo[]) {
    FILE *arquivo;
    int i;

    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar o arquivo!\n");
        return;
    }
    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d\n", numeros[i]);
    }
    fclose(arquivo);
}

void mostrarNumeros(int numeros[], int quantidade) {
    int i;

    for (i = 0; i < quantidade; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

void bubbleSort(int numeros[], int quantidade) {
    int i, j, auxiliar;

    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (numeros[j] > numeros[j + 1]) {
                auxiliar = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = auxiliar;
            }
        }
    }
}

void insertionSort(int numeros[], int quantidade) {
    int i, j, auxiliar;

    for (i = 1; i < quantidade; i++) {
        auxiliar = numeros[i];
        j = i - 1;
        while (j >= 0 && numeros[j] > auxiliar) {
            numeros[j + 1] = numeros[j];
            j--;
        }
        numeros[j + 1] = auxiliar;
    }
}

void selectionSort(int numeros[], int quantidade) {
    int i, j, menor, auxiliar;

    for (i = 0; i < quantidade - 1; i++) {
        menor = i;
        for (j = i + 1; j < quantidade; j++) {
            if (numeros[j] < numeros[menor]) {
                menor = j;
            }
        }
        auxiliar = numeros[i];
        numeros[i] = numeros[menor];
        numeros[menor] = auxiliar;
    }
}

void mergeSort(int numeros[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(numeros, inicio, meio);
        mergeSort(numeros, meio + 1, fim);
        juntar(numeros, inicio, meio, fim);
    }
}

void juntar(int numeros[], int inicio, int meio, int fim) {
    int auxiliar[MAX];
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (numeros[i] <= numeros[j]) {
            auxiliar[k] = numeros[i];
            i++;
        } else {
            auxiliar[k] = numeros[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {
        auxiliar[k] = numeros[i];
        i++;
        k++;
    }
    while (j <= fim) {
        auxiliar[k] = numeros[j];
        j++;
        k++;
    }
    for (i = inicio; i <= fim; i++) {
        numeros[i] = auxiliar[i];
    }
}

void quickSort(int numeros[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(numeros, inicio, fim);
        quickSort(numeros, inicio, pivo - 1);
        quickSort(numeros, pivo + 1, fim);
    }
}

int particionar(int numeros[], int inicio, int fim) {
    int pivo = numeros[fim];
    int i = inicio - 1;
    int j, auxiliar;

    for (j = inicio; j < fim; j++) {
        if (numeros[j] <= pivo) {
            i++;
            auxiliar = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = auxiliar;
        }
    }
    auxiliar = numeros[i + 1];
    numeros[i + 1] = numeros[fim];
    numeros[fim] = auxiliar;
    return i + 1;
}