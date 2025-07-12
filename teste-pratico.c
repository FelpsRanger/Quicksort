#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de particionamento do Quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Pivô é o último elemento
    int i = (low - 1);        // Índice do menor elemento
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Implementação do Quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Função para gerar lista aleatória
void gerar_lista_aleatoria(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

// Função para gerar lista ordenada
void gerar_lista_ordenada(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = i + 1;
    }
}

// Função para gerar lista reversa
void gerar_lista_reversa(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }
}

// Função para gerar lista com duplicatas
void gerar_lista_duplicatas(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 10 + 1;
    }
}

// Função para verificar se array está ordenado
int verificar_ordenado(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Função para copiar array
void copiar_array(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Função para imprimir array pequeno
void imprimir_array(int arr[], int tamanho) {
    if (tamanho <= 20) {
        printf("[");
        for (int i = 0; i < tamanho; i++) {
            printf("%d", arr[i]);
            if (i < tamanho - 1) printf(", ");
        }
        printf("]\n");
    } else {
        printf("[%d, %d, %d, ... , %d, %d, %d]\n", 
               arr[0], arr[1], arr[2], 
               arr[tamanho-3], arr[tamanho-2], arr[tamanho-1]);
    }
}

// Função para medir tempo de execução
double medir_tempo_quicksort(int arr[], int tamanho) {
    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock();
    quicksort(arr, 0, tamanho - 1);
    fim = clock();
    
    tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_cpu;
}

// Função principal de testes
void executar_testes() {
    printf("=== TESTES PRÁTICOS - QUICKSORT EM C ===\n\n");
    
    // Tamanhos das listas para teste
    int tamanhos[] = {100, 500, 1000, 2000, 5000, 10000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    // Tipos de teste
    char* tipos[] = {"Aleatória", "Ordenada", "Reversa", "Duplicatas"};
    void (*geradores[])(int[], int) = {
        gerar_lista_aleatoria,
        gerar_lista_ordenada,
        gerar_lista_reversa,
        gerar_lista_duplicatas
    };
    int num_tipos = sizeof(tipos) / sizeof(tipos[0]);
    
    // Executar testes para cada tipo
    for (int t = 0; t < num_tipos; t++) {
        printf("\n--- TESTE: Lista %s ---\n", tipos[t]);
        printf("Tamanho | Tempo (s)  | Ordenada | Observações\n");
        printf("--------|------------|----------|------------\n");
        
        for (int i = 0; i < num_tamanhos; i++) {
            int tamanho = tamanhos[i];
            
            // Alocar memória
            int* arr_original = (int*)malloc(tamanho * sizeof(int));
            int* arr_teste = (int*)malloc(tamanho * sizeof(int));
            
            // Gerar dados
            geradores[t](arr_original, tamanho);
            
            // Copiar para teste
            copiar_array(arr_original, arr_teste, tamanho);
            
            // Medir tempo
            double tempo = medir_tempo_quicksort(arr_teste, tamanho);
            
            // Verificar se está ordenado
            int ordenado = verificar_ordenado(arr_teste, tamanho);
            
            // Imprimir resultado
            printf("%7d | %10.6f | %8s | ", 
                   tamanho, tempo, ordenado ? "Sim" : "Não");
            
            // Observações específicas
            if (strcmp(tipos[t], "Ordenada") == 0) {
                printf("Pode ser lento (O(n²))");
            } else if (strcmp(tipos[t], "Reversa") == 0) {
                printf("Pior caso possível");
            } else if (strcmp(tipos[t], "Duplicatas") == 0) {
                printf("Muitos elementos iguais");
            } else {
                printf("Caso médio típico");
            }
            printf("\n");
            
            // Liberar memória
            free(arr_original);
            free(arr_teste);
        }
    }
}

// Demonstração com exemplo pequeno
void demonstracao_pequena() {
    printf("\n=== DEMONSTRAÇÃO COM EXEMPLO PEQUENO ===\n");
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    imprimir_array(arr, tamanho);
    
    clock_t inicio = clock();
    quicksort(arr, 0, tamanho - 1);
    clock_t fim = clock();
    
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Array ordenado: ");
    imprimir_array(arr, tamanho);
    printf("Tempo: %.6f segundos\n", tempo);
}

// Análise dos resultados
void analise_resultados() {
    printf("\n=== ANÁLISE DOS RESULTADOS ===\n\n");
    
    printf("📊 OBSERVAÇÕES:\n");
    printf("• Lista Aleatória: Desempenho médio O(n log n)\n");
    printf("• Lista Ordenada: Pode ser lenta O(n²) com pivô fixo\n");
    printf("• Lista Reversa: Frequentemente o pior caso O(n²)\n");
    printf("• Lista Duplicatas: Boa performance com muitos iguais\n\n");
    
    printf("🎯 PONTOS FORTES DO QUICKSORT:\n");
    printf("• Muito eficiente na prática\n");
    printf("• Ordena in-place (economia de memória)\n");
    printf("• Boa performance média O(n log n)\n");
    printf("• Implementação relativamente simples\n\n");
    
    printf("⚠️ PONTOS FRACOS DO QUICKSORT:\n");
    printf("• Pior caso O(n²) pode acontecer\n");
    printf("• Performance instável (depende do pivô)\n");
    printf("• Não é estável (ordem de elementos iguais)\n");
    printf("• Recursivo (limitação de stack)\n\n");
}

// Teste específico do pior caso
void teste_pior_caso() {
    printf("=== DEMONSTRAÇÃO DO PIOR CASO ===\n");
    
    printf("Testando com listas ordenadas (pivô = último elemento):\n");
    printf("Tamanho | Tempo (s)  | Complexidade observada\n");
    printf("--------|------------|----------------------\n");
    
    int tamanhos_pequenos[] = {100, 200, 400, 800};
    int num_tamanhos = sizeof(tamanhos_pequenos) / sizeof(tamanhos_pequenos[0]);
    
    double tempo_anterior = 0;
    
    for (int i = 0; i < num_tamanhos; i++) {
        int tamanho = tamanhos_pequenos[i];
        
        int* arr = (int*)malloc(tamanho * sizeof(int));
        gerar_lista_ordenada(arr, tamanho);
        
        double tempo = medir_tempo_quicksort(arr, tamanho);
        
        printf("%7d | %10.6f | ", tamanho, tempo);
        
        if (i > 0) {
            double razao = tempo / tempo_anterior;
            printf("%.1fx mais lento", razao);
        } else {
            printf("Referência");
        }
        printf("\n");
        
        tempo_anterior = tempo;
        free(arr);
    }
    
    printf("\nNota: O(n²) deveria ser ~4x mais lento ao dobrar o tamanho\n");
}

// Função principal
int main() {
    // Inicializar gerador de números aleatórios
    srand(time(NULL));
    
    printf("QUICKSORT - ANÁLISE DE PERFORMANCE EM C\n");
    printf("=======================================\n");
    
    // Demonstração pequena
    demonstracao_pequena();
    
    // Testes principais
    executar_testes();
    
    // Análise dos resultados
    analise_resultados();
    
    // Teste do pior caso
    teste_pior_caso();
    
    printf("\n=== CONCLUSÃO ===\n");
    printf("O Quicksort implementado em C demonstra excelente performance\n");
    printf("para a maioria dos casos, mas confirma os problemas teóricos\n");
    printf("no pior caso com dados ordenados!\n");
    
    return 0;
}
