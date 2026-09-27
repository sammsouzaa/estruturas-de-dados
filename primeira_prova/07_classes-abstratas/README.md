# RESUMO DA AULA: CLASSES ABSTRATAS E ESTRUTURAS DE PROGRAMAÇÃO


## 1. CONCEITO E REGRAS DE CLASSES ABSTRATAS

* Definição: Classes abstratas são estruturas de modelagem úteis quando uma 
  superclasse define assinaturas de métodos que devem ser obrigatoriamente 
  implementados pelas suas subclasses.
* Método Abstrato (Função Virtual Pura): É um método que não possui corpo (código), 
  definindo estritamente o seu protótipo/assinatura. Em C++, é declarado utilizando a palavra-chave 
  'virtual' e igualando a assinatura a zero (ex: virtual void debitar(double v) = 0;).
* Regras de Restrição:
  * Toda classe que contiver pelo menos um método abstrato é automaticamente 
    classificada como classe abstrata.
  * Uma classe abstrata funciona como um molde e não pode ser instanciada diretamente 
    no programa (isto é, não é possível criar um objeto dela).
* Classes Concretas: Uma subclasse de uma classe abstrata só poderá ser instanciada 
  e gerar objetos se ela sobrescrever individualmente e fornecer uma implementação 
  concreta para cada um dos métodos abstratos herdados.

## 2. RESOLUÇÃO DE PROBLEMAS DE DESIGN: HERANÇA x COMPOSIÇÃO

A aula aborda um problema de modelagem clássico sobre como adicionar responsabilidades 
a objetos de forma maleável (Estudo de caso: Mesas):
* Cenário: Modelar uma mesa pura, mesa com rodinhas, mesa de tênis com rodinhas, 
  mesa de jantar, etc.
* Abordagem por Herança (Estática): 
  * É a solução mais "natural", porém gera uma adição estática de responsabilidades.
  * Desvantagem: A responsabilidade é atribuída rigidamente à classe e não a cada 
    objeto individual. O cliente não possui controle dinâmico sobre 
    como e quando adicionar características (como as rodinhas), tornando o sistema 
    pouco extensível.
* Abordagem por Composição (Dinâmica - Decorator Pattern):
  * Solução indicada para obter extensibilidade.
  * Conceito: Em vez de criar subclasses rígidas, "decora-se" a mesa básica envolvendo-a 
    com um objeto que adiciona as rodinhas, ou outro que adiciona a rede de tênis.
  * Cada objeto que embeleza ou adiciona uma função à mesa atua como um 'decorator' 
    com base na composição de objetos em tempo de execução.

