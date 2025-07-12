# 🚀 Seminário Final: Quicksort
## Algoritmos e Estruturas de Dados I - Sistemas de Informação

### 📋 Informações Gerais
- **Data da Apresentação:** 16/07/2025
- **Duração:** 10-15 minutos
- **Tema:** Quicksort - Análise Teórica e Prática
- **Disciplina:** Algoritmos e Estruturas de Dados I

### 👥 Equipe
- **Kaio Sobral** - Fundamentos e Teoria
- **Gustavo Souza** - Implementação e Análise
- **Felipe Rangel** - Testes e Conclusões

---

## 🎯 Objetivo
Apresentar e analisar profundamente o algoritmo Quicksort de forma teórica, prática e comparativa, utilizando criatividade e clareza na apresentação através de implementação em linguagem C.

---

## 📚 Estrutura da Apresentação

### 1. **Introdução ao Algoritmo** (Kaio Sobral)
- Contexto histórico do Quicksort
- Criador: Tony Hoare (1960)
- Aplicações práticas atuais
- Importância na computação

### 2. **Funcionamento Passo a Passo** (Kaio Sobral)
- Explicação do algoritmo de divisão e conquista
- Conceito de particionamento e pivô
- Exemplo numérico detalhado
- Demonstração interativa em tempo real

### 3. **Implementação** (Gustavo Souza)
- Código funcional do Quicksort em C
- Explicação dos principais trechos
- Demonstração ao vivo no terminal
- Variações do algoritmo

### 4. **Análise de Complexidade** (Gustavo Souza)
- **Melhor caso:** O(n log n)
- **Caso médio:** O(n log n)
- **Pior caso:** O(n²)
- Comparação com outros algoritmos

### 5. **Testes Práticos** (Felipe Rangel)
- Testes com diferentes tamanhos de arrays
- Diferentes padrões de dados:
  - Arrays aleatórios
  - Arrays ordenados
  - Arrays em ordem reversa
  - Arrays com duplicatas
- Interpretação dos resultados

### 6. **Considerações Finais** (Felipe Rangel)
- Pontos fortes e fracos
- Quando utilizar o Quicksort
- Conclusões práticas

### 7. **Extra - Comparações** (Felipe Rangel)
- Quicksort vs Mergesort
- Quicksort vs Bubble Sort
- Tabela comparativa de algoritmos

---

## 🛠️ Recursos Técnicos

### **Código Implementado:**
1. **`quicksort_seminar.c`** - Programa completo com todas as funcionalidades
   - Implementação do Quicksort
   - Algoritmos de comparação (Merge Sort, Bubble Sort)
   - Testes de performance
   - Menu interativo
   - Análise de complexidade

### **Funcionalidades do Programa:**
- Demonstração passo a passo
- Testes automáticos de performance
- Geração de diferentes tipos de dados
- Contagem de operações (comparações e trocas)
- Medição de tempo de execução
- Interface de usuário intuitiva

### **Compilador e Ferramentas:**
- **Compilador:** GCC (GNU Compiler Collection)
- **Linguagem:** C (padrão C99)
- **Bibliotecas:** stdio.h, stdlib.h, time.h, string.h
- **Visualização:** [VisuAlgo](https://visualgo.net/en/sorting)

---

## 📊 Resultados Esperados

### **Análise de Performance:**
- Demonstração da eficiência O(n log n) em casos médios
- Identificação de cenários problemáticos O(n²)
- Comparação quantitativa com outros algoritmos
- Medição precisa de tempo de execução

### **Casos de Teste:**
- **Arrays pequenos:** 100-500 elementos
- **Arrays médios:** 1000-2000 elementos  
- **Arrays grandes:** 5000+ elementos

### **Métricas Avaliadas:**
- Tempo de execução (em segundos)
- Número de comparações
- Número de trocas
- Comportamento com diferentes tipos de dados

---

## 🔍 Pontos-Chave do Quicksort

### **Vantagens:**
- ✅ Eficiente na prática: O(n log n) médio
- ✅ Ordena in-place (economia de memória)
- ✅ Algoritmo de divisão e conquista
- ✅ Amplamente utilizado na indústria

### **Desvantagens:**
- ❌ Pior caso O(n²) pode ocorrer
- ❌ Performance instável (depende do pivô)
- ❌ Não é algoritmo estável
- ❌ Recursivo (limitação de stack)

### **Quando Usar:**
- Dados aleatórios ou semi-aleatórios
- Quando memória é limitada
- Performance média é mais importante que garantias
- Implementação simples é desejada

### **Quando Evitar:**
- Dados já ordenados (sem otimização)
- Quando estabilidade é crucial
- Sistemas que não podem ter O(n²)
- Arrays extremamente grandes (stack overflow)

---

## 📈 Comparação com Outros Algoritmos

| Algoritmo | Melhor Caso | Caso Médio | Pior Caso | Estável | In-place |
|-----------|-------------|------------|-----------|---------|----------|
| **Quicksort** | O(n log n) | O(n log n) | O(n²) | Não | Sim |
| **Mergesort** | O(n log n) | O(n log n) | O(n log n) | Sim | Não |
| **Heapsort** | O(n log n) | O(n log n) | O(n log n) | Não | Sim |
| **Bubble Sort** | O(n) | O(n²) | O(n²) | Sim | Sim |

---

## 🎪 Elementos Criativos

### **Analogias:**
- "Quicksort é como dividir para conquistar uma pizza gigante"
- "O pivô é como um juiz que separa elementos maiores e menores"

### **Interatividade:**
- Demonstração manual com voluntários
- Quiz sobre performance
- Escolha do pivô pelo público
- Execução ao vivo do programa

### **Recursos Visuais:**
- Resultados de performance em tempo real
- Contadores de operações
- Comparações side-by-side
- Exemplos práticos com dados reais

---

## 📚 Referências

- **Livro:** "Algoritmos: Teoria e Prática" - Cormen, Leiserson, Rivest, Stein
- **Site:** GeeksforGeeks - Quicksort
- **Visualização:** VisuAlgo.net
- **Documentação:** GCC Documentation
- **Artigo Original:** Tony Hoare - "Quicksort" (1961)

---

## 🚀 Como Compilar e Executar

### **Pré-requisitos:**
- Compilador GCC instalado
- Sistema operacional: Linux, macOS ou Windows (com MinGW)

### **Passos:**
1. **Clone ou baixe o arquivo**
   ```bash
   # Baixe o arquivo quicksort_seminar.c
   ```

2. **Compile o programa:**
   ```bash
   gcc -o quicksort_seminar quicksort_seminar.c
   ```

3. **Execute o programa:**
   ```bash
   ./quicksort_seminar
   ```

4. **No Windows:**
   ```bash
   quicksort_seminar.exe
   ```

### **Menu Interativo:**
- **Opção 1:** Demonstração passo a passo
- **Opção 2:** Testes de performance
- **Opção 3:** Análise de complexidade
- **Opção 4:** Tabela comparativa
- **Opção 5:** Executar todos os testes

---

## 🎯 Exemplo de Uso

```bash
# Compilar
gcc -o quicksort_seminar quicksort_seminar.c

# Executar
./quicksort_seminar

# Saída esperada:
🚀 SEMINÁRIO FINAL: QUICKSORT
==============================
Algoritmos e Estruturas de Dados I - Sistemas de Informação
Data: 16/07/2025
Equipe: Kaio Sobral, Gustavo Souza, Felipe Rangel

🚀 SEMINÁRIO QUICKSORT - MENU PRINCIPAL
=======================================
1. Demonstração Passo a Passo
2. Testes de Performance
3. Análise de Complexidade
4. Tabela Comparativa
5. Executar Todos os Testes
0. Sair

Escolha uma opção:
```

---

## 📁 Estrutura do Projeto

```
seminario-quicksort/
├── quicksort_seminar.c    # Código principal
├── README.md              # Este arquivo
└── Makefile              # (opcional) Para automação
```

---

## 🔧 Makefile (Opcional)

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = quicksort_seminar
SOURCE = quicksort_seminar.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
```

---

## 🎓 Conclusão

O Quicksort representa um dos algoritmos mais importantes e utilizados na computação moderna. Sua eficiência prática, simplicidade de implementação e versatilidade o tornam uma escolha excelente para a maioria dos problemas de ordenação. 

Através desta implementação em C, demonstramos tanto suas qualidades quanto suas limitações, fornecendo uma visão completa e prática deste algoritmo fundamental com medições precisas de performance e análise detalhada de comportamento.

---

## 🤝 Contribuições

Este projeto foi desenvolvido para fins educacionais como parte do seminário final da disciplina Algoritmos e Estruturas de Dados I. 

**Equipe:**
- Kaio Sobral - Teoria e Fundamentos
- Gustavo Souza - Implementação e Análise  
- Felipe Rangel - Testes e Conclusões

---

## 📄 Licença

Este projeto é de uso educacional e está disponível sob a licença MIT.

---

**Boa sorte na apresentação! 🎉**
