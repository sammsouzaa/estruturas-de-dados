# Trabalho 2: Listas Encadeadas

Material de Referência:
* Aula 1: Lista Encadeada Simples (09-Lecture_7.pdf)
* Aula 2: Lista Duplamente Encadeada (10-Lecture_8.pdf)
* Aula 3: Listas Circulares (11-Lecture_9.pdf)

## Enunciados dos Slides

### Lista Encadeada Simples (Aula 1 - Slide 87)
* Implemente uma classe Lista todas as operações vistas;
* Implemente a lista usando Templates;
* Implemente a lista com um numero de elementos variável definido na instanciação;
* Use as melhores práticas de orientação a objetos;
* Documente todas as classes, métodos e atributos;
* Aplique os testes unitários disponíveis no moodle da disciplina para validar sua estrutura de dados;
* Entregue até a data definida no moodle.

### Lista Duplamente Encadeada (Aula 2 - Slide 132)
* Implemente uma classe ListaDupla todas as operações vistas;
* Implemente a lista usando Templates;
* Use as melhores práticas de orientação a objetos;
* Documente todas as classes, métodos e atributos;
* Aplique os testes unitários disponíveis no moodle da disciplina para validar sua estrutura de dados;
* Entregue até a data definida no moodle.

### Lista Encadeada Circular (Aula 3 - Slide 12)
* Implemente uma classe Lista todas as operações vistas;
* Implemente a lista usando Templates;
* Use as melhores práticas de orientação a objetos;
* Documente todas as classes, métodos e atributos;
* Aplique os testes unitários disponíveis no moodle da disciplina para validar sua estrutura de dados;
* Entregue até a data definida no moodle.

### Lista Duplamente Encadeada Circular (Aula 3 - Slide 14)
* Implemente uma classe Lista todas as operações vistas;
* Implemente a lista usando Templates;
* Use as melhores práticas de orientação a objetos;
* Documente todas as classes, métodos e atributos;
* Aplique os testes unitários disponíveis no moodle da disciplina para validar sua estrutura de dados;
* Entregue até a data definida no moodle.

## Estruturas Implementadas

1. Lista Encadeada Simples (Lista.h / Lista.cpp):
   * AdicionaNoInicio, AdicionaNaPosicao, AdicionaEmOrdem, Adiciona
   * RetiraDoInicio, EliminaDoInicio, RetiraDaPosicao, Retira, RetiraEspecifico
   * Posicao, Contem, ListaVazia, ListaCheia, LimpaLista, DestroiLista

2. Lista Duplamente Encadeada (ListaDupla.h / ListaDupla.cpp):
   * Nós duplos com ponteiros Proximo e Anterior
   * AdicionaNoInicioDupla, AdicionaNaPosicaoDupla, AdicionaEmOrdemDupla, AdicionaDupla
   * RetiraDoInicioDupla, RetiraDaPosicaoDupla, RetiraDupla, RetiraEspecificoDupla
   * PosicaoDupla, ContemDupla, ListaVaziaDupla, DestroiListaDupla

3. Lista Encadeada Circular (ListaCircular.h / ListaCircular.cpp):
   * Implementação utilizando nodo sentinela (Slides 10 e 11)
   * AdicionaNoInicio, AdicionaNaPosicao, Adiciona
   * RetiraDoInicio, RetiraDaPosicao, Retira
   * Posicao, Contem, ListaVazia, DestroiLista

4. Lista Duplamente Encadeada Circular (ListaDuplaCircular.h / ListaDuplaCircular.cpp):
   * Primeiro e último elemento apontam um para o outro (Slide 13)
   * AdicionaNoInicio, AdicionaNaPosicao, Adiciona
   * RetiraDoInicio, RetiraDaPosicao, Retira
   * Posicao, Contem, ListaVazia, DestroiLista
