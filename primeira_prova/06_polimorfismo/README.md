# RESUMO DA AULA: POLIMORFISMO EM C++


## 1. CONCEITO DE POLIMORFISMO E PONTEIROS DA CLASSE BASE

* Definição: Significa "muitas formas". Em POO, é a capacidade de um mesmo chamamento 
  de método se comportar de maneiras diferentes dependendo do tipo do objeto real 
  que o invoca.
* Ponteiros Polimórficos: Um ponteiro ou referência do tipo de uma classe base pode 
  apontar e guardar o endereço de objetos de qualquer uma de suas subclasses 
  (classes derivadas) de forma nativa.
* Problema da Vinculação Estática: Por padrão em C++, se você chamar um método herdado 
  através de um ponteiro da classe base, o compilador executará a versão da classe 
  base (vinculação estática/tempo de compilação), mesmo que o objeto real na memória 
  seja da classe filha.

## 2. MÉTODOS VIRTUAIS (VINCULAÇÃO DINÂMICA)

* Palavra-chave 'virtual': Para ativar o polimorfismo e a vinculação dinâmica (tempo 
  de execução), o método correspondente na classe base deve ser explicitamente 
  declarado com o modificador 'virtual'.
* Comportamento Dinâmico: Quando um método é virtual, o C++ consulta o ponteiro do 
  objeto real na execução e invoca a função sobrescrita da classe filha correta, 
  e não a da classe base.
* Propagação: Uma vez que um método é declarado como virtual na classe base, ele torna-se 
  automaticamente virtual em todas as classes derivadas seguintes, mesmo que a 
  palavra 'virtual' não seja reescrita nelas.

## 3. CLASSES ABSTRATAS E FUNÇÕES VIRTUAIS PURAS

* Função Virtual Pura: É um método virtual que não possui nenhuma implementação 
  definida na classe base. Sua sintaxe obriga a igualar a assinatura a zero no 
  cabeçalho.
  * Exemplo: virtual void desenhar() = 0;
* Classe Abstrata: Qualquer classe que contenha pelo menos uma função virtual pura 
  torna-se uma classe abstrata.
  * Restrição: Classes abstratas funcionam estritamente como interfaces e moldes; 
    elas não podem ser instanciadas (ou seja, é impossível criar um objeto direto delas).
* Classes Concretas: São as subclasses que herdam da classe abstrata e implementam 
  obrigatoriamente o corpo de todas as funções virtuais puras herdadas, permitindo a 
  criação de objetos.

