#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ============================================================================
// 🚀 SEMINÁRIO FINAL: QUICKSORT
// Algoritmos e Estruturas de Dados I - Sistemas de Informação
// Data: 16/07/2025
// Equipe: Kaio Sobral, Gustavo Souza, Felipe Rangel
// ============================================================================

// Estrutura para armazenar resultados dos testes
typedef struct {
    char nome[50];
    double tempo_execucao;
    int comparacoes;
    int trocas;
} ResultadoTeste;

// Estrutura para diferentes tipos de dados de teste
typedef struct {
    int *dados;
    int tamanho;
    char tipo[30];
} DadosTeste;

// Variáveis globais para contagem de operações
int contador_comparacoes = 0;
int contador_trocas = 0;

// ============================================================================
// 📚 IMPLEMENTAÇÃO DO QUICKSORT
// ============================================================================

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    contador_trocas++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de particionamento (núcleo do Quicksort)
int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];    // Escolhe o último elemento como pivô
    int i = (baixo - 1);     // Índice do menor elemento
    
    for (int j = baixo; j <= alto - 1; j++) {
        contador_comparacoes++;
        
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++;    // incrementa índice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Função principal do Quicksort
void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // pi é o índice de particionamento
        int pi = particionar(arr, baixo, alto);
        
        // Ordena elementos separadamente antes e depois da partição
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

// ============================================================================
// 🛠️ ALGORITMOS DE COMPARAÇÃO
// ============================================================================

// Bubble Sort para comparação
void bubbleSort(int arr[], int n) {
    contador_comparacoes = 0;
    contador_trocas = 0;
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            contador_comparacoes++;
            if (arr[j] > arr[j+1]) {
                trocar(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Merge Sort para comparação
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0; j = 0; k = l;
    
    while (i < n1 && j < n2) {
        contador_comparacoes++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ============================================================================
// 🔧 FUNÇÕES AUXILIARES
// ============================================================================

// Função para imprimir array
void imprimir_array(int arr[], int tamanho, char *nome) {
    printf("%s: ", nome);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para copiar array
void copiar_array(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Função para gerar dados aleatórios
void gerar_dados_aleatorios(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000;
    }
}

// Função para gerar dados ordenados
void gerar_dados_ordenados(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = i + 1;
    }
}

// Função para gerar dados em ordem reversa
void gerar_dados_reversos(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }
}

// Função para gerar dados com duplicatas
void gerar_dados_duplicatas(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 10;  // Valores entre 0-9 para muitas duplicatas
    }
}

// ============================================================================
// 📊 FUNÇÃO DE TESTE E ANÁLISE
// ============================================================================

double testar_algoritmo(void (*algoritmo)(int[], int), int arr[], int tamanho, char *nome) {
    contador_comparacoes = 0;
    contador_trocas = 0;
    
    clock_t inicio = clock();
    
    if (algoritmo == quicksort) {
        quicksort(arr, 0, tamanho - 1);
    } else {
        algoritmo(arr, tamanho);
    }
    
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("%-15s | Tempo: %.6f s | Comparações: %d | Trocas: %d\n", 
           nome, tempo, contador_comparacoes, contador_trocas);
    
    return tempo;
}

// ============================================================================
// 🎯 DEMONSTRAÇÃO PASSO A PASSO
// ============================================================================

void demonstracao_passo_a_passo() {
    printf("\n🎯 DEMONSTRAÇÃO PASSO A PASSO DO QUICKSORT\n");
    printf("===========================================\n");
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    imprimir_array(arr, n, "");
    
    printf("\n📍 Executando Quicksort...\n");
    quicksort(arr, 0, n - 1);
    
    printf("Array ordenado: ");
    imprimir_array(arr, n, "");
    printf("\n");
}

// ============================================================================
// 📈 TESTES DE PERFORMANCE
// ============================================================================

void executar_testes_performance() {
    printf("\n📈 TESTES DE PERFORMANCE\n");
    printf("========================\n");
    
    int tamanhos[] = {100, 500, 1000, 2000, 5000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        printf("\n--- Teste com %d elementos ---\n", tamanho);
        
        int *dados_originais = (int*)malloc(tamanho * sizeof(int));
        int *dados_teste = (int*)malloc(tamanho * sizeof(int));
        
        // Teste com dados aleatórios
        printf("\n🎲 Dados Aleatórios:\n");
        gerar_dados_aleatorios(dados_originais, tamanho);
        
        copiar_array(dados_originais, dados_teste, tamanho);
        testar_algoritmo(quicksort, dados_teste, tamanho, "Quicksort");
        
        copiar_array(dados_originais, dados_teste, tamanho);
        testar_algoritmo(mergeSort, dados_teste, tamanho, "Merge Sort");
        
        if (tamanho <= 1000) {  // Bubble sort apenas para arrays pequenos
            copiar_array(dados_originais, dados_teste, tamanho);
            testar_algoritmo(bubbleSort, dados_teste, tamanho, "Bubble Sort");
        }
        
        // Teste com dados ordenados
        printf("\n📊 Dados Ordenados:\n");
        gerar_dados_ordenados(dados_originais, tamanho);
        
        copiar_array(dados_originais, dados_teste, tamanho);
        testar_algoritmo(quicksort, dados_teste, tamanho, "Quicksort");
        
        copiar_array(dados_originais, dados_teste, tamanho);
        testar_algoritmo(mergeSort, dados_teste, tamanho, "Merge Sort");
        
        // Teste com dados em ordem reversa
        printf("\n🔄 Dados Reversos:\n");
        gerar_dados_reversos(dados_originais, tamanho);
        
        copiar_array(dados_originais, dados_teste, tamanho);
        testar_algoritmo(quicksort, dados_teste, tamanho, "Quicksort");
        
        copiar_array(dados_originais, dados_teste, tamanho);
        testar_algoritmo(mergeSort, dados_teste, tamanho, "Merge Sort");
        
        free(dados_originais);
        free(dados_teste);
    }
}

// ============================================================================
// 📋 ANÁLISE DE COMPLEXIDADE
// ============================================================================

void analise_complexidade() {
    printf("\n📋 ANÁLISE DE COMPLEXIDADE DO QUICKSORT\n");
    printf("=======================================\n");
    printf("🟢 Melhor Caso:  O(n log n) - Pivô sempre divide array pela metade\n");
    printf("🟡 Caso Médio:   O(n log n) - Comportamento típico com dados aleatórios\n");
    printf("🔴 Pior Caso:    O(n²)      - Array já ordenado (sem otimização)\n");
    printf("\n");
    
    printf("✅ VANTAGENS:\n");
    printf("   • Eficiente na prática: O(n log n) médio\n");
    printf("   • Ordena in-place (economia de memória)\n");
    printf("   • Algoritmo de divisão e conquista\n");
    printf("   • Amplamente utilizado na indústria\n");
    printf("\n");
    
    printf("❌ DESVANTAGENS:\n");
    printf("   • Pior caso O(n²) pode ocorrer\n");
    printf("   • Performance instável (depende do pivô)\n");
    printf("   • Não é algoritmo estável\n");
    printf("   • Recursivo (limitação de stack)\n");
    printf("\n");
}

// ============================================================================
// 📊 TABELA COMPARATIVA
// ============================================================================

void tabela_comparativa() {
    printf("\n📊 TABELA COMPARATIVA DE ALGORITMOS\n");
    printf("====================================\n");
    printf("%-12s | %-11s | %-11s | %-11s | %-8s | %-8s\n", 
           "Algoritmo", "Melhor", "Médio", "Pior", "Estável", "In-place");
    printf("-------------|-------------|-------------|-------------|----------|----------\n");
    printf("%-12s | %-11s | %-11s | %-11s | %-8s | %-8s\n", 
           "Quicksort", "O(n log n)", "O(n log n)", "O(n²)", "Não", "Sim");
    printf("%-12s | %-11s | %-11s | %-11s | %-8s | %-8s\n", 
           "Merge Sort", "O(n log n)", "O(n log n)", "O(n log n)", "Sim", "Não");
    printf("%-12s | %-11s | %-11s | %-11s | %-8s | %-8s\n", 
           "Heap Sort", "O(n log n)", "O(n log n)", "O(n log n)", "Não", "Sim");
    printf("%-12s | %-11s | %-11s | %-11s | %-8s | %-8s\n", 
           "Bubble Sort", "O(n)", "O(n²)", "O(n²)", "Sim", "Sim");
    printf("\n");
}

// ============================================================================
// 🎪 MENU PRINCIPAL
// ============================================================================

void menu_principal() {
    printf("\n🚀 SEMINÁRIO QUICKSORT - MENU PRINCIPAL\n");
    printf("=======================================\n");
    printf("1. Demonstração Passo a Passo\n");
    printf("2. Testes de Performance\n");
    printf("3. Análise de Complexidade\n");
    printf("4. Tabela Comparativa\n");
    printf("5. Executar Todos os Testes\n");
    printf("0. Sair\n");
    printf("\nEscolha uma opção: ");
}

// ============================================================================
// 🎓 FUNÇÃO MAIN
// ============================================================================

int main() {
    srand(time(NULL));  // Inicializa gerador de números aleatórios
    
    printf("🚀 SEMINÁRIO FINAL: QUICKSORT\n");
    printf("==============================\n");
    printf("Algoritmos e Estruturas de Dados I - Sistemas de Informação\n");
    printf("Data: 14/07/2025\n");
    printf("Equipe: Kaio Sobral, Gustavo Souza, Felipe Rangel\n");
    
    int opcao;
    do {
        menu_principal();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                demonstracao_passo_a_passo();
                break;
            case 2:
                executar_testes_performance();
                break;
            case 3:
                analise_complexidade();
                break;
            case 4:
                tabela_comparativa();
                break;
            case 5:
                demonstracao_passo_a_passo();
                executar_testes_performance();
                analise_complexidade();
                tabela_comparativa();
                break;
            case 0:
                printf("\n🎓 Obrigado por usar o simulador Quicksort!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
            getchar();
        }
        
    } while(opcao != 0);
    
    return 0;
}

// ============================================================================
// 📚 COMO COMPILAR E EXECUTAR
// ============================================================================
/*
Para compilar:
gcc -o quicksort_seminar quicksort_seminar.c

Para executar:
./quicksort_seminar

Ou no Windows:
quicksort_seminar.exe
*/

// ============================================================================
// 🎯 CONCLUSÃO
// ============================================================================
/*
O Quicksort representa um dos algoritmos mais importantes e utilizados na 
computação moderna. Sua eficiência prática, simplicidade de implementação e 
versatilidade o tornam uma escolha excelente para a maioria dos problemas de 
ordenação.

Através desta implementação, demonstramos tanto suas qualidades quanto suas 
limitações, fornecendo uma visão completa e prática deste algoritmo fundamental.
*/
