# Trabalho 1: Pilha e Fila com Ponteiros

Material de Referência: Aula 2 (10-Lecture_8.pdf)

## Enunciados dos Slides

### Pilha Encadeada (Slide 51)
* Implemente uma classe Pilha todas as operações vistas;
* Implemente a pilha usando Templates;
* Use as melhores práticas de orientação a objetos;
* Documente todas as classes, métodos e atributos;
* Aplique os testes unitários disponíveis no moodle da disciplina para validar sua estrutura de dados;
* Entregue até a data definida no moodle.

### Fila Encadeada (Slide 92)
* Implemente uma classe Fila todas as operações vistas;
* Implemente a fila usando Templates;
* Use as melhores práticas de orientação a objetos;
* Documente todas as classes, métodos e atributos;
* Aplique os testes unitários disponíveis no moodle da disciplina para validar sua estrutura de dados;
* Entregue até a data definida no moodle.

## Estrutura Implementada

### Pilha Encadeada (Pilha.h / Pilha.cpp)
* Elemento<T>: guarda o ponteiro para a informação e o ponteiro para o próximo elemento.
* Pilha<T>:
  * Pilha(): inicializa topo como nulo e tamanho como zero.
  * ~Pilha(): destrutor que chama DestroiPilha().
  * void DestroiPilha(): desaloca todos os elementos da pilha.
  * bool PilhaVazia(): verifica se a pilha está vazia.
  * void Empilha(T dado): insere um novo elemento no topo.
  * T Desempilha(): remove e retorna o elemento do topo (lança ERRO_PILHA_VAZIA se vazia).
  * T GetTopo(): consulta o elemento do topo sem remover.
  * int GetTamanho(): retorna a quantidade de elementos.

### Fila Encadeada (Fila.h / Fila.cpp)
* Fila<T>:
  * Fila(): inicializa início e fim como nulo e tamanho como zero.
  * ~Fila(): destrutor que chama DestroiFila().
  * void DestroiFila(): desaloca todos os elementos da fila.
  * bool FilaVazia(): verifica se a fila está vazia.
  * void Inclui(T dado): insere no fim da fila (trata caso especial de fila vazia).
  * T Retira(): remove do início da fila (trata caso especial de fila unitária).
  * T GetPrimeiro(): consulta o primeiro elemento.
  * T GetUltimo(): consulta o último elemento.
  * int GetTamanho(): retorna o total de elementos.
