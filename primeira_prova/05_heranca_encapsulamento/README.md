# RESUMO DA AULA: ENCAPSULAMENTO E HERANÇA


## 1. RELAÇÃO ENTRE CLASSE PAI E CLASSE FILHA

* Herança: Mecanismo que permite que uma nova classe (classe filha, derivada ou 
  subclasse) adquira os membros (atributos e métodos) de uma classe existente 
  (classe pai, base ou superclasse).
* Propósito Principal: Evitar a duplicação de código, reaproveitando a estrutura 
  geral já testada e validada na classe base.
* Modificadores de Acesso na Herança Básica:
  * Membros 'public' da classe pai continuam acessíveis externamente através da 
    instância da classe filha.
  * Membros 'private' da classe pai são herdados pela classe filha, mas tornam-se 
    estritamente inacessíveis diretamente pelo código da classe filha.

## 2. CONSTRUTORES NA HIERARQUIA DE CLASSES

* Ordem de Execução: Quando um objeto da classe filha é criado, o construtor da 
  classe pai é executado em primeiro lugar na memória, seguido pelo construtor 
  da classe filha.
* Chamada Explícita: A classe filha pode invocar um construtor parametrizado da 
  classe pai utilizando a lista de inicialização do construtor, repassando os 
  argumentos necessários para a base.


# RESUMO DA AULA: HERANÇA PROTECTED E PRIVATE


## 1. O ESPECIFICADOR DE ACESSO 'PROTECTED'

* Problema do Private: Membros privados da classe pai não podem ser manipulados 
  diretamente pelas funções da classe filha, exigindo getters/setters públicos.
* Solução com Protected: Os membros declarados como 'protected' comportam-se como 
  privados para o mundo externo (funções clientes), mas são totalmente visíveis 
  e acessíveis de forma direta dentro dos métodos das subclasses.

## 2. TIPOS DE DERIVAÇÃO DE HERANÇA EM C++

A forma como a subclasse herda da classe pai altera a visibilidade futura dos 
membros na hierarquia:

A) Derivação Pública (class Subclasse : public Base)
   * Modo tradicional e mais utilizado.
   * Mantém os níveis originais: membros públicos da base continuam públicos na 
     subclasse; membros protegidos continuam protegidos.
   * Preserva a relação lógica "é um" (Subclasse funciona como um subtipo da Base).

B) Derivação Protegida (class Subclasse : protected Base)
   * Membros públicos e protegidos da classe pai tornam-se todos 'protected' 
     dentro da subclasse.
   * Bloqueia o acesso público externo aos métodos originais da classe pai através 
     de um objeto da subclasse.

C) Derivação Privada (class Subclasse : private Base)
   * Membros públicos e protegidos da classe pai tornam-se todos 'private' 
     dentro da subclasse.
   * Rompe a relação de subtipo. Nenhum membro herdado pode ser acessado fora da 
     subclasse ou por futuras classes que herdem dela.
   * Redefinição de Visibilidade: É possível trazer um membro específico de volta 
     ao acesso público declarando seu nome com o operador de escopo na cláusula 
     public (ex: Base::metodo;).

