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
Apresentar e analisar profundamente o algoritmo Quicksort de forma teórica, prática e comparativa, utilizando criatividade e clareza na apresentação.

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
- Ilustração visual do processo

### 3. **Implementação** (Gustavo Souza)
- Código funcional do Quicksort
- Explicação dos principais trechos
- Demonstração ao vivo
- Variações do algoritmo

### 4. **Análise de Complexidade** (Gustavo Souza)
- **Melhor caso:** O(n log n)
- **Caso médio:** O(n log n)
- **Pior caso:** O(n²)
- Comparação com outros algoritmos

### 5. **Testes Práticos** (Felipe Rangel)
- Testes com diferentes tamanhos de listas
- Diferentes padrões de dados:
  - Listas aleatórias
  - Listas ordenadas
  - Listas em ordem reversa
  - Listas com duplicatas
- Interpretação dos resultados

### 6. **Considerações Finais** (Felipe Rangel)
- Pontos fortes e fracos
- Quando utilizar o Quicksort
- Conclusões práticas

### 7. **Extra - Comparações** (Felipe Rangel)
- Quicksort vs Mergesort
- Quicksort vs Heapsort
- Tabela comparativa de algoritmos

---

## 🛠️ Recursos Técnicos

### **Códigos Implementados:**
1. **`quicksort_tests.py`** - Testes práticos com diferentes cenários
2. **`quicksort_comparacao.py`** - Comparação com outros algoritmos
3. **Implementação base do Quicksort** - Código funcional demonstrativo

### **Dependências:**
```bash
pip install matplotlib numpy
```

### **Ferramentas Utilizadas:**
- **Visualização:** [VisuAlgo](https://visualgo.net/en/sorting)
- **Análise de código:** Python Tutor
- **Gráficos:** Matplotlib
- **Documentação:** Markdown

---

## 📊 Resultados Esperados

### **Análise de Performance:**
- Demonstração da eficiência O(n log n) em casos médios
- Identificação de cenários problemáticos O(n²)
- Comparação quantitativa com outros algoritmos

### **Casos de Teste:**
- **Listas pequenas:** 100-500 elementos
- **Listas médias:** 1000-2000 elementos  
- **Listas grandes:** 5000+ elementos

### **Métricas Avaliadas:**
- Tempo de execução
- Uso de memória
- Estabilidade do algoritmo
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
- Listas extremamente grandes (stack overflow)

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

### **Recursos Visuais:**
- Gráficos de performance
- Animações do algoritmo
- Exemplos práticos com cartas/papéis

---

## 📚 Referências

- **Livro:** "Algoritmos: Teoria e Prática" - Cormen, Leiserson, Rivest, Stein
- **Site:** GeeksforGeeks - Quicksort
- **Visualização:** VisuAlgo.net
- **Documentação:** Python Official Documentation
- **Artigo Original:** Tony Hoare - "Quicksort" (1961)

---

## 🚀 Como Executar os Testes

1. **Clone ou baixe os arquivos**
2. **Instale as dependências:**
   ```bash
   pip install matplotlib numpy
   ```
3. **Execute os testes:**
   ```bash
   python quicksort_tests.py
   ```
4. **Execute as comparações:**
   ```bash
   python quicksort_comparacao.py
   ```

---

## 🎓 Conclusão

O Quicksort representa um dos algoritmos mais importantes e utilizados na computação moderna. Sua eficiência prática, simplicidade de implementação e versatilidade o tornam uma escolha excelente para a maioria dos problemas de ordenação. 

Através desta apresentação, demonstramos tanto suas qualidades quanto suas limitações, fornecendo uma visão completa e prática deste algoritmo fundamental.

