# Resolução do Simulado de Estruturas de Dados (C++)

Este repositório contém as soluções divididas em pastas para o simulado da disciplina de Estruturas de Dados. A progressão dos exercícios foi desenhada para construir gradualmente conceitos fundamentais de **Programação Orientada a Objetos (POO)**.

Abaixo está a interpretação do que o professor exigiu em cada etapa e os conceitos técnicos de C++ aplicados nas soluções.

---

### Exercício 1
* **Interpretação:** O primeiro passo exige apenas a "planta" (o molde) da nossa primeira estrutura, separando o que é interno (privado) e o que pode ser acessado de fora (público).
* **O que foi aplicado:** 
  * Criação da classe base `OperacaoMatematica`.
  * **Encapsulamento**: Definição de atributos privados (`op1` e `op2`), garantindo que não sejam modificados indevidamente fora da classe.
  * Declaração de métodos públicos (Construtor e método `multiplicacao()`).

### Exercício 2
* **Interpretação:** Dar vida ao molde criado na primeira questão, escrevendo a lógica interna dos métodos que foram apenas declarados.
* **O que foi aplicado:** 
  * Implementação do método construtor para inicializar os atributos no momento da criação do objeto.
  * Implementação aritmética direta (utilizando o operador `*`) para retornar o produto dos atributos.

### Exercício 3
* **Interpretação:** Provar que a classe construída nos passos anteriores é funcional na prática por meio da execução de um programa.
* **O que foi aplicado:** 
  * Criação do ponto de entrada (`main.cpp`).
  * **Instanciação de Objetos**: Criação de um objeto do tipo `OperacaoMatematica` passando valores, executando seu comportamento e exibindo o resultado.

### Exercício 4
* **Interpretação:** Expandir as capacidades do nosso sistema inicial sem destruir o que já foi feito, criando uma "especialização" que faz tudo o que a classe base faz, mas com um novo recurso de soma.
* **O que foi aplicado:** 
  * **Herança**: Criação da classe `Calculadora` estendendo a classe base (`class Calculadora : public OperacaoMatematica`).
  * **Getters**: Inclusão dos métodos `getOp1()` e `getOp2()` na classe mãe para contornar a restrição dos atributos privados, permitindo que a classe filha recupere os valores armazenados de forma segura.

### Exercício 5
* **Interpretação:** Testar a nova classe `Calculadora` em um programa principal para validar se o novo método e as características herdadas funcionam juntas.
* **O que foi aplicado:** 
  * Instanciação da classe filha `Calculadora`.
  * Uso do método `soma()` exclusivo da filha junto com o reaproveitamento de código base.

### Exercício 6
* **Interpretação:** Modificar o comportamento herdado. O exercício pede para avisar o sistema que o comportamento padrão da multiplicação (que era via operador `*`) não serve mais para a filha, devendo ser recriado (sobrescrito).
* **O que foi aplicado:** 
  * **Polimorfismo**: Aplicação do modificador `virtual` no método `multiplicacao()` da classe mãe (permitindo que ele seja alterado).
  * Uso da palavra-chave `override` na classe filha para indicar explicitamente a sobrescrita desse método herdado.

### Exercício 7
* **Interpretação:** Fazer a união final dos conceitos: implementar o método que foi sobrescrito no Exercício 6, mas usando uma lógica inteiramente baseada em chamadas aos próprios métodos da classe (adição), provando que é possível fazer uma multiplicação usando apenas somas consecutivas.
* **O que foi aplicado:** 
  * **Sobrecarga de Métodos (Method Overloading)**: Criação de um segundo método `soma(double a, double b)` que recebe parâmetros, complementando o `soma()` vazio que usa os atributos internos.
  * Uso de estruturas de repetição (`for`) em conjunto com a função de `soma` para calcular o resultado.
  * **Include Guards** (`#ifndef`, `#define`): Aplicação em todos os arquivos cabeçalho (`.h`) para proteger a compilação contra importações circulares e redefinições de código no compilador C++.
