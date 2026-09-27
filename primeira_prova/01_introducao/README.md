# RESUMO DA AULA: INTRODUÇÃO À ESTRUTURA DE DADOS


## 1. O QUE É ESTRUTURA DE DADOS (ED)?

* É o ramo da Ciência da Computação focado no estudo dos diversos mecanismos de 
  organização de dados.
* O objetivo principal é dispor os dados de maneira estratégica para atender de 
  forma eficiente aos diferentes requisitos de processamento de um sistema.

## 2. A RELAÇÃO ENTRE ALGORITMOS E ESTRUTURAS DE DADOS

* Algoritmos e ED possuem uma relação íntima, dado que os algoritmos geralmente 
  operam e trabalham diretamente sobre Estruturas de Dados.
* A escolha correta e adequada de uma ED é crucial, pois ela pode simplificar 
  significativamente a implementação do algoritmo para a resolução de um 
  determinado problema.
* O foco central da disciplina consiste em analisar e definir as melhores 
  alternativas para manipular os dados computacionais com a máxima eficiência.

## 3. EXEMPLOS PRÁTICOS E APLICAÇÕES DE ESTRUTURAS DE DADOS


A) Arrays (Vetores) e Listas
   * Aplicação: Ideal para armazenar coleções lineares de dados simples.
   * Exemplo: Armazenar uma lista sequencial de clientes em um sistema.
   * Características visuais: Organização em índices sequenciais ou nós interligados 
     por ponteiros (como listas encadeadas contendo campos de dados e 'next').

B) Árvores
   * Aplicação: Perfeita para representar e armazenar dados que possuem uma 
     relação e hierarquia bem definida.
   * Exemplo: A organização de diretórios e pastas em um sistema de arquivos de 
     um computador (ex: pasta raiz '/' contendo ramificações como 'home', 'bin', 
     'etc').

C) Grafos
   * Aplicação: Utilizado para mapear redes complexas e interconexões que não 
     seguem necessariamente uma hierarquia rígida ou linear.
   * Exemplo: Estruturar o relacionamento e as conexões entre diferentes usuários 
     dentro de uma rede social.


# RESUMO DA AULA: TIPOS ESTRUTURADOS (STRUCTS)


## 1. CONCEITO E OBJETIVOS

* Compreender, declarar e empregar tipos estruturados para resolver problemas 
  computacionais.
* Diferença fundamental:
  * Tipos de dados básicos (int, char, float, etc.) armazenam apenas uma única 
    informação por variável.
  * Tipo Estrutura (struct): Permite agrupar diferentes tipos de dados que, de 
    outra forma, ficariam dispersos e sem associação clara no programa.
  * Exemplo: Armazenar nome, idade e renda de um aluno de forma unificada, em 
    vez de usar variáveis isoladas que não indicam explicitamente pertencer ao 
    mesmo registro.

## 2. DECLARAÇÃO DE TIPOS ESTRUTURADOS EM C

Existem três formas principais de declaração apresentadas:

A) Declaração Comum (Mais recomendada/comum)
   * Declara-se a estrutura globalmente (antes da função main).
   * Sintaxe:
     struct livro {
         char titulo[30];
         int paginas;
         float preco;
     }; // "livro" é o nome da estrutura e os internos são os membros
   * Para instanciar na main: struct livro livro2;

B) Declaração sem Nome da Estrutura (Variáveis locais/imediatas)
   * As variáveis são declaradas diretamente e logo após o fechamento do bloco.
   * Sintaxe:
     struct {
         char titulo[30];
         int paginas;
         float preco;
     } livro1, livro2; // Variáveis já criadas e prontas para o código

C) Declaração com 'typedef'
   * Define um sinônimo (alias) para a estrutura, facilitando a criação posterior.
   * Sintaxe:
     typedef struct {
         char titulo[30];
         int paginas;
         float preco;
     } LIVRO; // LIVRO torna-se o tipo
   * Para instanciar na main: LIVRO livro4;

## 3. INICIALIZAÇÃO E ACESSO AOS MEMBROS

* Inicialização imediata: É possível definir valores iniciais na declaração usando chaves 
  (ex: struct livro livro2 = {"Programacao", 365, 298.78};).
* Acesso aos membros (Campos/Registros): É feito utilizando o operador ponto '.' 
  (ex: fone.ddd ou fone.numero) para leitura (scanf) e saída (printf).

## 4. ESTRUTURAS ANINHADAS E COMPARAÇÃO

* Estruturas contidas em outras: Um membro de uma struct pode ser outra struct 
  previamente declarada (ex: struct aluno contendo struct telefone fone;).
  * O acesso segue a cadeia de pontos: aluno1.fone.ddd.
* Comparação de Estruturas: É INCORRETO comparar duas variáveis estruturadas 
  diretamente (ex: if (j1 == j2)).
  * Correto: Para comparar tipos estrutura, deve-se comparar individualmente cada 
    membro/elemento que compõe a estrutura 
    (ex: if (j1.altura == j2.altura && j1.largura == j2.largura)).

## 5. PONTEIROS E PASSAGEM COMO PARÂMETRO

* Estruturas e Ponteiros: Podem ser endereçadas via ponteiros (struct janela2D *j;).
  * Sintaxe de acesso: (*j).altura (os parênteses são obrigatórios para garantir a 
    precedência do operador asterisco antes do ponto).
* Passagem de Estruturas para Funções:
  * Por Valor: Passa uma cópia dos membros (ou da struct inteira), sem alterar a 
    variável original.
  * Por Referência: Passa o endereço da struct utilizando ponteiros, permitindo a 
    manipulação direta dos dados originais.

## 6. VETORES (ARRAYS) E VETORES DE ESTRUTURAS

* Passagem de Vetores normais: Passar um vetor como parâmetro para uma função consiste, 
  por padrão em C, em passar o endereço da primeira posição. Logo, a 
  passagem de um vetor é sempre por referência.
* Vetor de Estrutura: Permite criar matrizes unidimensionais onde cada índice armazena 
  uma estrutura completa.
  * Declaração: struct agendaEmail minhaAgenda[10];
  * Acesso com Índice e Ponto: minhaAgenda[i].nome.
  * Passagem para função: Passa-se o endereço inicial do vetor (&agendaPessoal), e a 
    assinatura da função recebe com colchetes vazios (struct Agenda agenda[]).

