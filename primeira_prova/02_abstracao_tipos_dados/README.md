# RESUMO DA AULA: ABSTRAÇÃO E TIPOS ABSTRATOS DE DADOS


## 1. CONCEITO DE ABSTRAÇÃO

* Definição Geral: É um mecanismo que nos permite dominar a complexidade do 
  mundo real ao modelar uma entidade ou conceito de forma simplificada.
* Foco no Contexto: Consiste em focar exclusivamente nos atributos e aspectos 
  que são interessantes e relevantes para resolver um problema particular, 
  descartando detalhes supérfluos.

## 2. TIPOS ABSTRATOS DE DADOS (TADs)

* Definição: É um modelo de estruturação de dados que encapsula e especifica 
  três elementos fundamentais:
  1. O tipo dos dados armazenados.
  2. As operações definidas sobre esses dados.
  3. Os tipos de parâmetros dessas operações.
* Formulação Básica: TAD = Encapsulamento de Dados + Operações.
* Operações Típicas: Envolvem a criação do TAD, inclusões/remoções de dados, 
  percursos (varrer os elementos) e buscas.

## 3. TAD x ESTRUTURA DE DADOS (ED)

* Tipo Abstrato de Dados (TAD):
  * É um conceito matemático básico que define o tipo de dado.
  * Estabelece apenas "O QUE" cada operação faz, e não "como" faz.
  * É independente e não se relaciona com detalhes práticos de implementação 
    (como eficiência de tempo ou espaço de memória) .
* Estrutura de Dados (ED):
  * Representa o método ou algoritmo particular utilizado para implementar um 
    TAD específico dentro de uma Linguagem de Programação.
  * Exemplo: Um TAD de lista linear pode ser implementado fisicamente tanto por 
    meio de Vetores (Arrays) quanto por Listas Encadeadas.

## 4. PROPRIEDADES FUNDAMENTAIS E ENCAPSULAMENTO

* Separação de Conceitos: Cria uma divisão clara entre o conceito (definição do 
  tipo) e a implementação física das operações.
* Encapsulamento e Proteção: A representação interna do tipo fica contida em uma 
  única unidade sintática (Módulo) e oculta das aplicações externas.
* Clientes do TAD: São as aplicações que utilizam o TAD. Os clientes 
  possuem acesso exclusivo à interface abstrata e pública exposta pelo tipo.
* Vantagens Centrais:
  * Reutilização: Possibilidade de utilizar o mesmo TAD em diferentes softwares.
  * Manutenibilidade: Capacidade de alterar a estrutura interna do TAD sem a 
    necessidade de modificar o código das aplicações clientes.
  * Segurança e Confiabilidade: Os clientes não conseguem violar a estrutura 
    ou tornar os dados internos inconsistentes de forma direta.

## 5. SUPORTE EM LINGUAGENS DE PROGRAMAÇÃO

* Linguagem C (Modular):
  * O suporte ao encapsulamento em C é limitado, pois os clientes ainda conseguem 
    forçar o acesso aos campos se conhecerem a struct.
  * Implementado via módulos divididos em dois arquivos:
    * Arquivo de Cabeçalho (.h): Contém a interface, exportando o nome do tipo 
      e os protótipos das funções.
    * Arquivo de Código (.c): Contém a implementação concreta das operações e 
      a definição da estrutura privada.
* Linguagens C++ e Java (Orientadas a Objetos):
  * Implementam TADs utilizando Classes (.cpp ou .java).
  * Oferecem controle total de visibilidade aos atributos da estrutura através 
     de modificadores de acesso privados (private:).

## 6. EXEMPLOS DE PROJETOS DE TADs DESENVOLVIDOS NA AULA


A) TAD Ponto
   * Definição: Representação geométrica de um par ordenado (x,y) de números reais.
   * Interface (ponto.h): Declara o tipo 'typedef struct ponto Ponto;' e exporta 
     funções de manipulação:
     * pto_cria(x, y): Aloca dinamicamente a memória da estrutura e a inicializa.
     * pto_libera(p): Desaloca e libera a área de memória ocupada pelo ponto.
     * pto_acessa(p, *x, *y) e pto_atribui(p, x, y): Obtêm e modificam as coordenadas.
     * pto_distancia(p1, p2): Calcula e retorna a distância euclidiana entre dois pontos.

B) TAD N_Racionais (Exercício Proposto)
   * Definição: Estruturação voltada para a manipulação matemática de números 
     fracionários (composta por numerador e denominador).
   * Conjunto de Operações Projetadas:
     * cria_rac() e libera_rac(): Gerenciamento de alocação de memória.
     * atribui_rac() e acessa_rac(): Validação e leitura de campos (retornando 
       falha caso o denominador informado seja 0).
     * Operações aritméticas: soma_rac(), subtrai_rac(), multiplica_rac() e 
       divide_rac(), calculando numeradores e denominadores resultantes.
     * simplifica_rac(): Reduz matematicamente a fração obtida para a sua forma 
       simplificada mais básica.

