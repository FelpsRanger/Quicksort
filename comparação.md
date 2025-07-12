#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// ==================== IMPLEMENTAÇÕES DOS ALGORITMOS ====================

// Função auxiliar para trocar elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// QUICKSORT
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// MERGESORT
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
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
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// HEAPSORT
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// BUBBLE SORT (para comparação)
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// ==================== FUNÇÕES AUXILIARES ====================

// Gerar lista aleatória
void gerar_lista_aleatoria(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

// Gerar lista ordenada
void gerar_lista_ordenada(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = i + 1;
    }
}

// Gerar lista reversa
void gerar_lista_reversa(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }
}

// Copiar array
void copiar_array(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Medir tempo de execução
double medir_tempo(void (*algoritmo)(int[], int), int arr[], int tamanho) {
    clock_t inicio, fim;
    
    inicio = clock();
    algoritmo(arr, tamanho);
    fim = clock();
    
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// Medir tempo para quicksort (tem assinatura diferente)
double medir_tempo_quicksort(int arr[], int tamanho) {
    clock_t inicio, fim;
    
    inicio = clock();
    quicksort(arr, 0, tamanho - 1);
    fim = clock();
    
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// Medir tempo para mergesort (tem assinatura diferente)
double medir_tempo_mergesort(int arr[], int tamanho) {
    clock_t inicio, fim;
    
    inicio = clock();
    mergesort(arr, 0, tamanho - 1);
    fim = clock();
    
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// ==================== TESTES E COMPARAÇÕES ====================

// Comparação entre todos os algoritmos
void comparar_algoritmos() {
    printf("=== COMPARAÇÃO: QUICKSORT vs OUTROS ALGORITMOS ===\n\n");
    
    int tamanhos[] = {100, 500, 1000, 2000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    printf("Comparação com listas aleatórias:\n");
    printf("Tamanho | Quicksort | Mergesort | Heapsort  | Bubble    | Mais Rápido\n");
    printf("--------|-----------|-----------|-----------|-----------|-------------\n");
    
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos[i];
        
        // Alocar arrays
        int* arr_original = (int*)malloc(tamanho * sizeof(int));
        int* arr_teste = (int*)malloc(tamanho * sizeof(int));
        
        // Gerar dados aleatórios
        gerar_lista_aleatoria(arr_original, tamanho);
        
        // Testar Quicksort
        copiar_array(arr_original, arr_teste, tamanho);
        double tempo_quick = medir_tempo_quicksort(arr_teste, tamanho);
        
        // Testar Mergesort
        copiar_array(arr_original, arr_teste, tamanho);
        double tempo_merge = medir_tempo_mergesort(arr_teste, tamanho);
        
        // Testar Heapsort
        copiar_array(arr_original, arr_teste, tamanho);
        double tempo_heap = medir_tempo(heapsort, arr_teste, tamanho);
        
        // Testar Bubble Sort (apenas para tamanhos pequenos)
        double tempo_bubble = 0;
        if (tamanho <= 1000) {
            copiar_array(arr_original, arr_teste, tamanho);
            tempo_bubble = medir_tempo(bubble_sort, arr_teste, tamanho);
        }
        
        // Determinar o mais rápido
        char* mais_rapido = "Quicksort";
        double menor_tempo = tempo_quick;
        
        if (tempo_merge < menor_tempo) {
            menor_tempo = tempo_merge;
            mais_rapido = "Mergesort";
        }
        if (tempo_heap < menor_tempo) {
            menor_tempo = tempo_heap;
            mais_rapido = "Heapsort";
        }
        if (tempo_bubble > 0 && tempo_bubble < menor_tempo) {
            menor_tempo = tempo_bubble;
            mais_rapido = "Bubble";
        }
        
        // Imprimir resultados
        printf("%7d | %9.6f | %9.6f | %9.6f | ", 
               tamanho, tempo_quick, tempo_merge, tempo_heap);
        
        if (tempo_bubble > 0) {
            printf("%9.6f | %s\n", tempo_bubble, mais_rapido);
        } else {
            printf("  LENTO   | %s\n", mais_rapido);
        }
        
        free(arr_original);
        free(arr_teste);
    }
}

// Comparação específica Quicksort vs Mergesort
void quicksort_vs_mergesort() {
    printf("\n=== QUICKSORT vs MERGESORT - ANÁLISE DETALHADA ===\n\n");
    
    char* cenarios[] = {"Lista Aleatória", "Lista Ordenada", "Lista Reversa"};
    void (*geradores[])(int[], int) = {gerar_lista_aleatoria, gerar_lista_ordenada, gerar_lista_reversa};
    int num_cenarios = sizeof(cenarios) / sizeof(cenarios[0]);
    
    int tamanho_teste = 1000;
    
    for (int c = 0; c < num_cenarios; c++) {
        printf("%s:\n", cenarios[c]);
        
        int* arr_original = (int*)malloc(tamanho_teste * sizeof(int));
        int* arr_teste = (int*)malloc(tamanho_teste * sizeof(int));
        
        // Gerar dados
        geradores[c](arr_original, tamanho_teste);
        
        // Testar Quicksort
        copiar_array(arr_original, arr_teste, tamanho_teste);
        double tempo_quick = medir_tempo_quicksort(arr_teste, tamanho_teste);
        
        // Testar Mergesort
        copiar_array(arr_original, arr_teste, tamanho_teste);
        double tempo_merge = medir_tempo_mergesort(arr_teste, tamanho_teste);
        
        printf("  Quicksort: %.6f segundos\n", tempo_quick);
        printf("  Mergesort: %.6f segundos\n", tempo_merge);
        
        if (tempo_quick < tempo_merge) {
            printf("  🏆 Quicksort é %.2fx mais rápido\n", tempo_merge / tempo_quick);
        } else {
            printf("  🏆 Mergesort é %.2fx mais rápido\n", tempo_quick / tempo_merge);
        }
        printf("\n");
        
        free(arr_original);
        free(arr_teste);
    }
}

// Tabela comparativa de características
void tabela_comparativa() {
    printf("=== TABELA COMPARATIVA DE CARACTERÍSTICAS ===\n\n");
    
    printf("Algoritmo    | Melhor Caso | Caso Médio | Pior Caso | Estável | In-place\n");
    printf("-------------|-------------|------------|-----------|---------|----------\n");
    printf("Quicksort    | O(n log n)  | O(n log n) | O(n²)     | Não     | Sim\n");
    printf("Mergesort    | O(n log n)  | O(n log n) | O(n log n)| Sim     | Não\n");
    printf("Heapsort     | O(n log n)  | O(n log n) | O(n log n)| Não     | Sim\n");
    printf("Bubble Sort  | O(n)        | O(n²)      | O(n²)     | Sim     | Sim\n");
    printf("\n");
}

// Recomendações de uso
void recomendacoes_uso() {
    printf("=== QUANDO USAR CADA ALGORITMO? ===\n\n");
    
    printf("🚀 QUICKSORT:\n");
    printf("  • Dados aleatórios ou semi-aleatórios\n");
    printf("  • Quando memória é limitada (in-place)\n");
    printf("  • Performance média é mais importante que garantias\n");
    printf("  • Implementação padrão em muitas bibliotecas\n\n");
    
    printf("🛡️ MERGESORT:\n");
    printf("  • Quando precisa de O(n log n) garantido\n");
    printf("  • Quando estabilidade é crucial\n");
    printf("  • Dados podem estar parcialmente ordenados\n");
    printf("  • Listas ligadas (não precisa de acesso aleatório)\n\n");
    
    printf("⚡ HEAPSORT:\n");
    printf("  • Sistemas em tempo real (performance garantida)\n");
    printf("  • Quando memória é muito limitada\n");
    printf("  • Seleção dos k maiores elementos\n");
    printf("  • Implementação de filas de prioridade\n\n");
    
    printf("🐌 BUBBLE SORT:\n");
    printf("  • Apenas para fins educacionais\n");
    printf("  • Listas muito pequenas (< 10 elementos)\n");
    printf("  • Quando simplicidade é mais importante que performance\n");
    printf("  • Detectar se lista já está ordenada\n\n");
}

// Análise de performance prática
void analise_performance() {
    printf("=== ANÁLISE DE PERFORMANCE PRÁTICA ===\n\n");
    
    printf("📊 OBSERVAÇÕES DOS TESTES:\n");
    printf("• Quicksort domina em listas aleatórias\n");
    printf("• Mergesort é mais consistente em diferentes cenários\n");
    printf("• Heapsort é confiável mas geralmente mais lento\n");
    printf("• Bubble Sort é impraticável para listas > 1000 elementos\n\n");
    
    printf("🔍 FATORES QUE AFETAM A PERFORMANCE:\n");
    printf("• Tamanho dos dados (crescimento assintótico)\n");
    printf("• Padrão dos dados (ordenados, aleatórios, etc.)\n");
    printf("• Localidade de memória (cache hits/misses)\n");
    printf("• Overhead de recursão vs iteração\n");
    printf("• Constantes multiplicativas na notação Big-O\n\n");
    
    printf("💡 DICAS PRÁTICAS:\n");
    printf("• Para uso geral: Quicksort com pivô aleatório\n");
    printf("• Para dados críticos: Mergesort ou Heapsort\n");
    printf("• Para listas pequenas: Insertion Sort (não implementado)\n");
    printf("• Híbridos: Introsort (Quicksort + Heapsort)\n\n");
}

// Função principal
int main() {
    // Inicializar gerador de números aleatórios
    srand(time(NULL));
    
    printf("COMPARAÇÃO DE ALGORITMOS DE ORDENAÇÃO EM C\n");
    printf("==========================================\n\n");
    
    // Executar todas as análises
    comparar_algoritmos();
    quicksort_vs_mergesort();
    tabela_comparativa();
    analise_performance();
    recomendacoes_uso();
    
    printf("=== CONCLUSÃO FINAL ===\n");
    printf("Cada algoritmo tem seu lugar! O Quicksort é excelente para\n");
    printf("a maioria dos casos práticos, mas conhecer as alternativas\n");
    printf("é fundamental para fazer a escolha certa.\n");
    printf("\nEm C, as diferenças de performance são ainda mais evidentes\n");
    printf("devido à baixa latência e controle direto de memória!\n");
    
    return 0;
}
