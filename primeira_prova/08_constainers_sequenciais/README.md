# RESUMO DA AULA: CONTAINERS SEQUENCIAIS (ARRANJOS E STRINGS)


## 1. CONCEITO DE CONTAINERS SEQUENCIAIS

* Containers são tipos de dados que fornecem armazenamento para uma coleção de 
  objetos, organizando-os de forma linear na memória.
* Problema resolvido: Evitam a necessidade de criar múltiplas variáveis com nomes 
  diferentes para armazenar grandes volumes de dados correlacionados (como a 
  nota de dezenas de estudantes).

## 2. ARRANJOS (ESTILO C, STD::ARRAY E STD::VECTOR)

A biblioteca padrão do C++ (STL) expande os arranjos tradicionais com novas 
estruturas seguras:

A) Arranjos Estilo C (Tradicionais)
   * Possuem tamanho fixo determinado em tempo de compilação.
   * Não possuem checagem nativa de limites/índices, o que pode causar corrupção 
     de memória se um índice inválido for acessado.

B) std::array (<array>)
   * É um contêiner de tamanho estático fixo que encapsula um arranjo estilo C.
   * Vantagem: Não perde o tamanho ao ser passado para funções e oferece funções 
     membros auxiliares, como o método `.at()`, que realiza checagem de limites.

C) std::vector (<vector>)
   * É um contêiner sequencial dinâmico cujo tamanho pode mudar em tempo de execução.
   * Aloca os elementos de forma contígua na memória, permitindo acesso direto eficiente.
   * Oferece métodos como `.push_back()` para adicionar elementos ao final e 
     redimensiona-se automaticamente quando a capacidade máxima é atingida.

## 3. TRATAMENTO DE TEXTO (STD::STRING E STD::STRING_VIEW)

* std::string (<string>): Substitui as strings estilo C (arrays de char terminados 
  em '\0'). Gerencia a memória dinamicamente, suporta concatenação direta 
  com '+', atribuição simples e possui métodos de busca e manipulação de texto.
* std::string_view (<string_view>): Introduzido para fornecer acesso de apenas leitura 
  (read-only) a uma sequência de caracteres existente.
  * Vantagem: Evita a criação de cópias caras de strings na memória ao passá-las 
    como parâmetros de funções, funcionando como uma "janela" ou ponteiro leve.


# RESUMO DA AULA: FILA DUPLA, LISTA E LISTA PROGRESSIVA (CONTAINERS)


## 1. CONTAINER STD::DEQUE (<deque>)

* Definição: Deque é o acrônimo para Double Ended Queue (Fila Dupla).
* Características: É um contêiner sequencial e dinâmico que permite acesso direto 
  aos elementos (assim como o vetor).
* Diferencial: É otimizado para inserções e remoções eficientes de elementos em 
  ambas as extremidades (tanto no início quanto no final).

## 2. CONTAINER STD::LIST (<list>)

* Definição: Implementa uma estrutura de lista duplamente encadeada.
* Características: Cada elemento (nó) possui ponteiros para o elemento anterior e 
  para o próximo elemento da sequência.
* Vantagem: Permite inserção e remoção de elementos em qualquer posição da lista 
  com tempo constante, sem a necessidade de deslocar outros elementos na memória.
* Desvantagem: Não oferece acesso direto por índice (não possui o operador `[]`), 
  exigindo um percurso sequencial para alcançar uma posição específica.

## 3. CONTAINER STD::FORWARD_LIST (<forward_list>)

* Definição: Implementa uma lista simplesmente encadeada (Lista Progressiva).
* Características: Cada nó armazena seu dado e um ponteiro unicamente para o 
  próximo elemento. Permite navegação apenas para frente.
* Métodos de Inserção: Como não possui controle do elemento anterior, utiliza métodos 
  específicos como `.push_front()` para inserir dados no início de forma rápida.
* Vantagem: Mais econômica em consumo de memória e ligeiramente mais rápida que a 
  `std::list` quando a navegação reversa não é necessária.


# RESUMO DA AULA: COLEÇÕES E ADAPTADORES DA STL


## 1. CONCEITO DE ADAPTADOR DE CONTAINER

* Definição: São estruturas da biblioteca padrão (STL) que não implementam um 
  armazenamento físico do zero.
* Funcionamento: Eles modificam ou "adaptam" a interface de contêineres sequenciais 
  existentes (como `std::vector`, `std::deque` ou `std::list`) para restringir e 
  fornecer comportamentos de estruturas de dados específicas.

2. ADAPTADORES ESPECÍFICOS

A) Pilha — std::stack (<stack>)
   * Implementa a lógica LIFO (Last In, First Out - Último a Entrar, Primeiro a Sair).
   * Restringe o acesso: Elementos só podem ser inseridos e removidos pelo topo.
   * Métodos principais: `.push()` (insere no topo), `.pop()` (remove do topo), 
     `.top()` (examina o elemento do topo), `.empty()` e `.size()`.

B) Fila — std::queue (<queue>)
   * Implementa a lógica FIFO (First In, First Out - Primeiro a Entrar, Primeiro a Sair).
   * Estrutura de pontas opostas: Inserções ocorrem estritamente no final (back) e 
     remoções ocorrem estritamente no início (front).
   * Métodos principais: `.push()` (insere no fim), `.pop()` (remove do início), 
     `.front()` (retorna o primeiro elemento), `.back()` (retorna o último), 
     `.empty()` e `.size()`.

C) Fila de Prioridade — std::priority_queue (<queue>)
   * É uma fila especial onde cada elemento inserido possui uma prioridade associada.
   * Comportamento: O elemento com a maior prioridade (por padrão, o maior valor 
     numérico) é organizado de forma a ficar sempre no topo da estrutura.
   * Remoção controlada: Ao efetuar um `.pop()`, remove-se o elemento de maior 
     prioridade.
   * Métodos principais: `.push()`, `.pop()`, `.top()` (retorna o elemento de maior 
     prioridade atualmente), `.empty()` e `.size()`.

