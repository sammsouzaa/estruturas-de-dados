# RESUMO DA AULA: TIPOS ABSTRATOS DE DADOS E CONSTRUÇÕES DE ENCAPSULAMENTO


## 1. CONCEITO E CATEGORIAS DE ABSTRAÇÃO

* Definição Geral: É uma visão ou representação de uma entidade que inclui 
  apenas os atributos mais significativos. Serve como uma 
  ferramenta contra a complexidade, visando simplificar a programação.
* Abstração de Processos: Concentra-se nos subprogramas (funções/procedimentos). 
  O algoritmo usado fica oculto do usuário (ex: uma função de ordenação 
  sortInt).
* Abstração de Dados: Concentra-se na estruturação e no encapsulamento dos dados 
  junto às suas operações.

## 2. INTRODUÇÃO À ABSTRAÇÃO DE DADOS (TAD)

Um Tipo Abstrato de Dado (TAD) é um tipo de dado que satisfaz duas condições básicas:
* Primeira Condição (Ocultação): A representação dos objetos é ocultada da unidade 
  de programa que os utiliza. As únicas operações diretas permitidas são aquelas 
  fornecidas na definição do tipo.
  * Vantagens: Confiabilidade (clientes não alteram os dados diretamente), 
    evita colisão de nomes e permite modificar a implementação interna sem 
    afetar o código do cliente.
* Segunda Condição (Unidade Sintática): A declaração do tipo e os protocolos 
  (interface) estão contidos em uma única unidade sintática, com a interface 
  independendo da implementação.
  * Vantagens: Permite compilação separada de módulos.

## 3. REQUISITOS DE PROJETO DAS LINGUAGENS

* Fornecer uma unidade sintática que encapsule o tipo e seus protótipos.
* Permitir visibilidade dos nomes dos tipos ocultando a implementação.
* Restringir operações padrões nativas, oferecendo essencialmente atribuição 
  e comparação.

## 4. EXEMPLOS DE IMPLEMENTAÇÃO POR LINGUAGEM


A) Ada
   * Utiliza o conceito de "Pacotes" (Packages).
   * Dividido em: Pacote de Especificação (define a interface pública e a parte 
     oculta 'private') e Pacote de Corpo (contém a implementação real).
   * Tipos abstratos declarados na área visível usam a marcação 'limited private' 
     para esconder a representação final detalhada na parte privada.

B) C++
   * Utiliza "Classes" e "Estruturas" como mecanismos de encapsulamento.
   * Dados são chamados de 'dados membros' e funções de 'funções membros'.
   * Instâncias compartilham funções membros, mas cada uma possui sua própria cópia 
     de dados membros. Alocação pode ser estática, na pilha ou 
     no heap (new/delete).
   * Níveis de acesso: private (oculto), public (público) e protected (visível 
     para subclasses). Possui Construtores e Destrutores.

C) Java
   * Similar ao C++, porém todos os tipos definidos por usuários são classes, todos 
     os objetos são alocados no heap e manipulados via referências.
   * Modificadores de acesso são declarados diretamente nas entidades (e não em 
     cláusulas/blocos) e a linguagem não possui destrutores.

D) C#
   * Baseado em C++ e Java, com objetos dinâmicos no heap e pouca utilização de 
     destrutores.
   * Fornece "Estruturas" alocadas na pilha (sem herança, acessadas por valor) e 
     "Propriedades" (getters e setters nativos sem chamadas explícitas de método).

E) Ruby
   * O mecanismo de encapsulamento padrão são as classes dinâmicas.
   * Variáveis de instância começam com '@' e variáveis de classe com '@@'.
   * O construtor padrão chama-se 'initialize'.

## 5. TADs PARAMETRIZADOS (GENÉRICOS)

* Permitem a criação de tipos abstratos de dados capazes de armazenar qualquer 
  tipo de dado de forma estática.
* Suporte por linguagem:
  * Ada: Implementado com a cláusula 'generic' e instanciado com 'new'.
  * C++: Utiliza 'template <class Type>'.
  * Java 5: Introduziu genéricos para evitar coerção (cast) e permitir checagem 
    de tipo em coleções. O mecanismo de 'autoboxing' resolveu a restrição 
    de tipos primitivos.
  * C# 2005: Adicionou classes genéricas cujos elementos podem ser acessados por 
    índices.

## 6. CONSTRUÇÕES DE ENCAPSULAMENTO EM LARGA ESCALA

Para grandes sistemas, o encapsulamento permite agrupar códigos logicamente 
relacionados em unidades de compilação separadas:
* Linguagem C: Divisão manual em arquivos de cabeçalho (.h) e implementação (.c), 
  unidos por #include, sem checagem de tipos entre eles pelo ligador.
* C++: Semelhante ao C, mas os cabeçalhos de templates geralmente contêm a declaração 
  e a definição juntas. Permite a palavra-chave 'friend' para liberar acesso privado.
* Ada: Os pacotes (especificação e corpo) podem ser totalmente compilados em separado.
* C#: Utiliza "Assemblies" (DLLs ou EXEs), onde o modificador 'internal' restringe 
  a visibilidade do membro apenas ao mesmo assembly.

## 7. ENCAPSULAMENTO DE NOMES (ESCOPO)

* Finalidade: Criar um novo escopo de nomes para evitar colisões e conflitos 
  acidentais entre identificadores criados por desenvolvedores independentes.
* Abordagem das linguagens: Namespaces (C++), Pacotes (Java e Ada) e Módulos (Ruby).

