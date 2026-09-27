# RESUMO DA AULA: LISTAS USANDO VETORES


## 1. CONCEITO E DEFINIÇÕES DE LISTA

* Definição Geral: Uma lista é um conjunto de dados dispostos e/ou acessáveis em 
  uma sequência determinada. Ela é inspirada no conceito de uma lista "natural".
* Ordem: Pode possuir uma ordem intrínseca (Lista Ordenada - por exemplo, por 
  ordem alfabética) ou refletir a ordem cronológica de inserção dos dados.
* Disposição Física na Memória: 
  * Se os dados ocuparem espaços fisicamente consecutivos, espelhando a sua 
    ordem, temos uma implementação por Vetor.
  * Se os dados estiverem dispersos na memória, necessitam de ponteiros e 
    informações adicionais para ligá-los, caracterizando uma Lista Encadeada.

## 2. ASPECTOS ESTRUTURAIS DA LISTA EM VETOR

* Limitação: Vetores possuem um espaço físico limitado para armazenar dados. Por 
  isso, é necessário definir um tamanho máximo inicial grande o suficiente 
  (constante MAXLISTA).
* Gerenciamento: Para controlar a estrutura, necessita-se obrigatoriamente de:
  1. Um vetor de dados estático ou dinâmico (_dados) para guardar as informações.
  2. Um indicador da posição atual do último elemento ativo da lista (_ultimo).
* Estados de Controle:
  * Lista Vazia: Representada quando o indicador do topo/fim está em -1 (_ultimo = -1).
  * Lista Cheia: Ocorre quando a variável _ultimo atinge o limite máximo da 
    capacidade alocada (tamanho - 1).

## 3. ASPECTOS FUNCIONAIS E OPERAÇÕES DA LISTA

* Inicialização / Limpeza: O construtor define o tamanho e coloca _ultimo como -1. 
  A função limpaLista() apenas joga o indicador _ultimo de volta para -1, 
  invalidando os dados antigos de forma lógica sem perder tempo apagando-os.
* Adicionar Elemento (adiciona): Testa se há espaço, incrementa o _ultimo e 
  insere o novo dado diretamente no fim.
* Adicionar no Início (adicionaNoInicio): Testa se há espaço, incrementa o 
  _ultimo e empurra todos os elementos existentes uma posição para trás (da 
  direita para a esquerda) antes de colocar o novo dado na posição indexada 0.
* Adicionar na Posição (adicionaNaPosicao): Valida se a posição informada é 
  válida (entre 0 e _ultimo+1), incrementa o fim e arrasta os elementos 
  posteriores uma casa para trás para abrir o espaço correto de inserção.
* Retirar Elementos (retira / retiraDoInicio / retiraDaPosicao): Salva o valor da 
  posição a ser removida, decrementa o _ultimo e move todos os dados seguintes 
  uma casa para a frente. O elemento não é apagado fisicamente, pois o ponteiro 
  _ultimo dita que a lista encerra-se antes daquela posição sobressalente.
* Adicionar em Ordem (adicionaEmOrdem): Varre a lista a partir do índice 0 até 
  encontrar a posição correta onde o novo dado deve ser inserhado (usando a 
  função de comparação do objeto) e invoca a rotina adicionaNaPosicao.
* Sobrecarga de Operadores: Quando a lista armazena tipos complexos/objetos, os 
  mesmos precisam ter implementados os operadores de comparação (como operator> 
  ou operator<) para viabilizar as buscas e inserções ordenadas.


# RESUMO DA AULA: PILHAS E FILAS UTILIZANDO VETORES


## 1. CONCEITO E MODELAGEM DE PILHA (STACK)

* Funcionamento LIFO: Baseado no conceito de empilhamento, onde o primeiro elemento 
  a entrar é obrigatoriamente o último a ser retirado (Last In, First Out).
* Estrutura Interna: Necessita de um vetor para armazenar os dados e de uma 
  variável de controle chamada _topo. O estado de Pilha Vazia é indicado por 
  _topo = -1 e Pilha Cheia quando _topo alcança a capacidade máxima.
* Operações Primitivas:
  * empilha (push): Incrementa o indicador _topo e adiciona o elemento nesta nova 
    posição do vetor.
  * desempilha (pop): Decrementa o ponteiro _topo e devolve o item que estava 
    posicionado no topo antigo.
  * topo (top): Apenas examina e retorna o dado contido no índice _topo, sem 
    fazer nenhuma alteração ou remoção na estrutura.

## 2. CONCEITO E MODELAGEM DE FILA (QUEUE)

* Funcionamento FIFO: Inspirado em uma fila natural, determinando que o primeiro 
  elemento que entrar será o primeiro elemento a ser removido (First In, First Out).
* Aplicação Prática: Fundamental para o gerenciamento de tarefas cronológicas e 
  simulações (ex: fila de impressão, pedidos de expedição, fluxo de caixas).
* Estrutura Interna: Utiliza um vetor de dados e um indicador para a posição final 
  da estrutura, denominado _fim. O início da fila fica fixado na posição de 
  índice 0 do vetor.
* Operações Primitivas:
  * insere (enqueue): Adiciona o novo elemento estritamente no final da estrutura 
    (posição indicada pela variável de controle).
  * retira (dequeue): Remove o elemento do início (índice 0). Para isso, armazena 
    o valor do índice 0 em uma variável auxiliar, decrementa o ponteiro _fim e 
    realiza um laço para empurrar todos os elementos restantes uma casa para a 
    frente (remanejando as posições).

