# RESUMO DA AULA: SUPORTE À PROGRAMAÇÃO ORIENTADA A OBJETOS


## 1. INTRODUÇÃO E TRÊS CARACTERÍSTICAS BÁSICAS

* Diversas linguagens dão suporte à Programação Orientada a Objetos (POO), variando 
  de Cobol a Lisp. 
  * C++ e Ada unem o paradigma procedural ao orientado a objetos.
  * Java e C# são orientadas a objetos, mas utilizam construções imperativas.
  * Smalltalk é considerada uma linguagem orientada a objetos pura.
* Para suportar a POO, uma linguagem de programação precisa obrigatoriamente 
  fornecer três características fundamentais:
  1. Tipo Abstrato de Dados (mecanismo de encapsulamento).
  2. Herança.
  3. Vinculação Dinâmica de chamada de métodos (Polimorfismo).

## 2. CONCEITOS GERAIS DE HERANÇA E POLIMORFISMO

* Limitações dos TADs isolados: Apresentam restrições quanto ao reuso pleno (pois 
  alguma modificação sempre costuma ser necessária) e na organização lógica, 
  visto que todos os TADs ficam posicionados no mesmo nível.
* Vantagens da Herança: Permite criar novos tipos baseados em tipos existentes, 
  viabilizando o reuso de dados e funcionalidades, a adição de novos membros, a 
  modificação de comportamentos herdados (sobrescrita) e a criação de 
  hierarquias de classes.
* Desvantagem: Cria um alto grau de dependência entre as classes de uma mesma 
  hierarquia.
* Terminologias de Mercado:
  * Classes: Nome dado aos TADs dentro de linguagens OO.
  * Objeto: Uma instância física de uma classe.
  * Subclasse (ou classe derivada): Classe definida por meio de herança.
  * Superclasse (classe pai): Classe a partir da qual a subclasse é derivada.
  * Métodos: Subprogramas que definem as operações dos objetos de uma classe.
  * Mensagem: Termo sinônimo para a chamada de métodos.
* Variáveis e Métodos: Podem pertencer ao escopo da instância ou diretamente ao 
  escopo geral da classe.
* Modos de Herança: 
  * Herança Simples: Derivação de uma única classe pai.
  * Herança Múltipla: Derivação de múltiplas classes pai.
* Vinculação Dinâmica: Ocorre quando um método sobrescrito é invocado por meio de 
  uma variável polimórfica (capaz de referenciar objetos de sua própria classe 
  ou de qualquer subclasse). A definição exata de qual 
  código será executado é postergada para o tempo de execução.
* Conceito Abstrato: Um método abstrato define apenas o protocolo/assinatura, 
  carecendo de corpo. Uma classe com ao menos um método abstrato torna-se 
  uma classe abstrata e perde o direito de ser instanciada diretamente.

## 3. QUESTÕES DE PROJETO DAS LINGUAGENS

* Exclusividade de Objetos:
  * Tudo é objeto (ex: Smalltalk): Oferece elegância e uniformidade, mas acarreta 
    baixo desempenho em operações simples.
  * Sistema misto tradicional (ex: C++): Tipos tradicionais convivem com objetos, 
    provendo operações rápidas em tipos simples à custa de um sistema confuso.
  * Tipos primitivos escalares e objetos (ex: Java): Mantém tipos primitivos para 
    velocidade e objetos para o restante, complicando o sistema de tipos.
* Relação Subclasse x Subtipo: Uma subclasse é considerada um subtipo legítimo se 
  atender à relação lógico-semântica "é uma" com a superclasse. 
  Isso exige que todos os membros expostos pela classe pai permaneçam expostos 
  pela classe filha (Princípio da Substituição de Liskov).
* Herança Múltipla: É útil em cenários específicos, mas traz complexidade na 
  implementação (colisão de nomes), ineficiência operacional e dificuldades no 
  gerenciamento do projeto de classes.
* Alocação de Memória: Objetos alocados no Heap oferecem uniformidade de acesso 
  e desreferenciamento implícito, mas demandam estratégias de desalocação 
  (implícita via Garbage Collector ou explícita via ponteiros) . 
  Alocações na Pilha (Stack) geram problemas de atribuição de subtipo.
* Vinculação de Mensagens: Vinculações dinâmicas oferecem polimorfismo total, 
  porém são mais lentas que as estáticas. Algumas linguagens permitem 
  que o desenvolvedor decida o tipo de vinculação aplicável.
* Outros fatores: Suporte a classes aninhadas (melhoria de ocultação de 
  informação) e políticas explícitas ou implícitas de inicialização de objetos 
  e de construtores de classes pai.

## 4. ANÁLISE COMPARATIVA POR LINGUAGEM


A) Smalltalk
   * Modelo totalmente baseado em objetos alocados no Heap, com troca de 
     mensagens parametrizadas e desalocação inteiramente implícita.
   * Vinculação de mensagens e checagem de tipos operam de forma estritamente 
     dinâmica. Se uma mensagem não for achada na classe 
     do objeto, a busca sobe na hierarquia de herança simples até atingir a 
     classe Object.
   * Toda subclasse é obrigatoriamente um subtipo. 
   * Vantagem: Sintaxe incrivelmente simples, regular e pioneira em IDEs. 
   * Desvantagem: Desempenho visivelmente mais lento e detecção de erros tardia (em 
     tempo de execução).

B) C++
   * Mescla os sistemas de tipos imperativo e orientado a objetos, permitindo 
     alocação na pilha, estática ou no heap (com desalocação estritamente explícita 
     via delete e destrutores).
   * Controle de acesso baseado nas cláusulas private, protected e public. 
     Uma classe criada em C++ não precisa ter necessariamente uma classe pai 
     raiz.
   * Tipos de Derivação na Herança:
     * Derivação Pública: Mantém membros públicos/protegidos da classe pai com 
       o mesmo status na subclasse. Garante que a subclasse funcione 
       como um subtipo.
     * Derivação Privada: Converte todos os membros públicos/protegidos herdados 
       em membros estritamente privados na subclasse. Logo, a 
       subclasse não se comporta como um subtipo.
   * Oferece suporte a herança múltipla nativa (resolvendo colisões por meio do 
     operador de escopo ::).
   * Vinculação: Por padrão, é estática. Para usufruir de vinculação 
     dinâmica, o desenvolvedor precisa sinalizar explicitamente o método com 
     a palavra-chave 'virtual'. Métodos 'virtuais puros' (= 0) definem 
     as classes abstratas.

C) Java
   * Abordagem onde todas as classes herdam de Object. Todos os tipos 
     são objetos, com exceção exclusiva dos tipos primitivos escalares. 
     O Java 5 inseriu os conceitos de autoboxing e autounboxing para transitar 
     esses primitivos em objetos wrapper automaticamente.
   * Alocação exclusiva no heap com desalocação implícita (Garbage Collector) 
     . O método finalize() executa na desalocação, mas seu tempo imprevisível 
     obriga o uso de outras táticas de liberação de recursos.
   * Restrições de Herança: Suporta unicamente herança simples. Para compensar, 
     permite que uma classe implemente múltiplas Interfaces (mecanismo mix-in), as quais 
     só admitem declarações de métodos e constantes. Toda subclasse é 
     um subtipo.
   * Elementos Finais: Métodos marcados como 'final' não aceitam sobrescrita e classes 
     'final' não permitem herança derivados.
   * Vinculação: Dinâmica por padrão para todas as mensagens, exceto se o método 
     for explicitamente final, private ou static.

D) C#
   * Divide-se em Classes (alocadas no Heap, similares ao ecossistema Java) e 
     Estruturas (alocadas na Pilha, sem suporte a herança, manipuladas por valor) 
     . Todas as classes herdam de Object.
   * Herança e Vinculação: Utiliza sintaxe parecida com a do C++. Para 
     ocorrer vinculação dinâmica, exige-se uma marcação intencional dupla: a superclasse 
     deve classificar o método como 'virtual' e a subclasse precisa marcá-lo como 'override' 
     .
   * Se a subclasse quiser apenas substituir um método herdado sem polimorfismo dinâmico, 
     marca-o com 'new'. O método ocultado da classe pai pode ser acessado 
     via prefixo 'base'. O suporte a interfaces segue o mesmo padrão do Java.

E) Ada 95
   * Introduziu o suporte a POO estendendo o Ada 83 por meio de "Tipos Etiquetados" 
     (tagged types), que embutem uma etiqueta em tempo de execução para identificar 
     seu tipo real. Podem assumir a forma de registros ou tipos privados.
   * Novas entidades de uma subclasse são anexadas em uma nova definição de registro. 
     Oferece herança simples (gerando sempre subtipos), mitigando a ausência de herança múltipla 
     com o uso de classes genéricas. Não chama construtores/destrutores de forma implícita.
   * Vinculação Dinâmica: Restrita a variáveis polimórficas declaradas como 'classwide'. 
     Apresenta maior ortogonalidade por não limitar o polimorfismo a ponteiros ou referências.

F) Ruby
   * Linguagem puramente orientada a objetos (tudo é objeto) onde classes e métodos possuem 
     definições totalmente executáveis em tempo de execução. 
   * Variáveis são referências sem tipo e dinamicamente polimórficas.
   * Todos os dados de uma classe são obrigatoriamente privados. Métodos 
     podem variar entre públicos, privados ou protegidos. 
   * Permite herança simples, onde o controle de acesso pode ser alterado na subclasse 
     (subclasses não são necessariamente subtipos) . Módulos permitem 
     a injeção de Mixins para simular herança múltipla. Não há suporte a classes abstratas.

## 5. MECANISMOS DE IMPLEMENTAÇÃO DA POO

* Registro de Instância de Classe (RIC): Estrutura estática construída em tempo de 
  compilação responsável por armazenar o estado físico (variáveis de instância) de um 
  objeto. 
  * Em heranças simples, as variáveis da subclasse são simplesmente adicionadas/empilhadas 
    ao término da estrutura do RIC da classe pai. O acesso aos dados ocorre de 
    forma extremamente eficiente por meio de deslocamento (offset).
* Tabela de Métodos Virtuais (vtable): Mecanismo para viabilizar a vinculação dinâmica 
  sem onerar a estrutura individual de cada objeto.
  * O RIC do objeto armazena apenas um ponteiro inicial para a vtable correspondente à sua 
    classe real instanciada.
  * A vtable é uma tabela única compartilhada por todas as instâncias daquela mesma classe 
    e armazena os ponteiros para os códigos de seus respectivos métodos virtuais.
  * Cada método virtual é unicamente indexado e representado por um deslocamento fixo a partir 
    do início da vtable. Métodos com vinculação estática não passam pela vtable.
* Cenário de Múltiplos Pais: Quando ocorre herança múltipla, a estrutura do RIC torna-se mais 
  complexa e fragmentada. O objeto passa a conter múltiplos ponteiros para vtables 
  distintas, dividindo o RIC em subseções correspondentes a cada classe pai para gerenciar 
  as chamadas polimórficas de forma correta.

