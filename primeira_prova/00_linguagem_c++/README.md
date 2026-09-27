# RESUMO DA AULA: INTRODUÇÃO À PROGRAMAÇÃO EM C++


## 1. SINTAXE BÁSICA E SAÍDA DE DADOS

* Estrutura Mínima: Um programa básico em C++ requer a inclusão da biblioteca 
  de fluxo de entrada e saída (<iostream>) e a definição da função principal 
  main().
* Namespace: O uso de 'using namespace std;' é empregado para evitar a 
  repetição do prefixo 'std::' antes de comandos como cout e cin.
* Saída de Dados: Realizada através do objeto 'cout' combinado com o operador 
  de inserção '<<'.
  * Quebra de linha: Pode ser feita utilizando o manipulador 'endl' ou o 
    caractere especial '\n'.
  * Exemplo: cout << "Olá Mundo!" << endl;

## 2. VARIÁVEIS E TIPOS DE DADOS

* Declaração: Segue o modelo padrão 'tipo nomeDaVariavel = valor;'.
* C++ é uma linguagem fortemente tipada, exigindo a especificação do tipo de 
  dados para cada variável:
  * int: Números inteiros (ex: int meuInt = 5;).
  * float: Números de ponto flutuante de precisão simples (ex: 5.99).
  * double: Números de ponto flutuante de precisão dupla (ex: 9.98).
  * char: Um único caractere delimitado por aspas simples (ex: 'D').
  * bool: Valores lógicos/booleanos (true ou false).
  * string: Cadeias de caracteres textuais (necessita da biblioteca <string>).

## 3. ENTRADA DE DADOS

* Realizada através do objeto 'cin' combinado com o operador de extração '>>'.
* Sintaxe de leitura: cin >> num; (onde 'num' é a variável que receberá o valor 
  digitado).

## 4. MANIPULAÇÃO DE STRINGS

* Concatenação: Pode ser feita de forma direta usando o operador aritmético '+' 
  ou por meio da função nativa '.append()'.
* Tamanho da String: A função '.length()' retorna a quantidade de caracteres 
  da string.
* Leitura Completa: Para ler strings que contêm espaços (como nomes completos), 
  utiliza-se a função global 'getline(cin, variavelString);' em substituição 
  ao 'cin >>', que interrompe a leitura no primeiro espaço.

## 5. OPERAÇÕES MATEMÁTICAS AVANÇADAS

* Funções Básicas: As funções 'max(x, y)' e 'min(x, y)' determinam os valores 
  máximos e mínimos e não requerem bibliotecas adicionais.
* Biblioteca <cmath>: É necessária para a execução de operações como:
  * sqrt(x): Calcula a raiz quadrada de um número.
  * round(x): Realiza o arredondamento de valores reais.
  * log(x): Calcula o logaritmo natural.

## 6. ESTRUTURAS DE DECISÃO E REPETIÇÃO

* Decisão: Implementada através das cláusulas condicionais 'if', 'else if' e 
  else, além do operador ternário (?:) e da estrutura de seleção 'switch'.
* Repetição: Além dos laços tradicionais 'while', 'do.. while' e 'for', o 
  padrão C++11 introduziu o 'for-each'.
  * O 'for-each' facilita a iteração sobre coleções e arrays.
  * Sintaxe: for (int i : meusNumeros) { cout << i; }

## 7. FUNÇÕES, REFERÊNCIAS E PONTEIROS

* Funções: Podem ser do tipo 'void' (sem retorno) ou possuir tipos específicos 
  que exigem o comando 'return' para devolver um valor calculado.
* Referências: Funcionam como um "apelido" para uma variável existente, utilizando 
  o operador '&' na declaração. Qualquer modificação na referência 
  afeta diretamente a variável original.
  * Exemplo: string &refeicao = alimento;
* Ponteiros: Variáveis que armazenam o endereço de memória de outra variável. 
  São declarados utilizando o operador asterisco '*' e recebem o 
  endereço através do operador '&'.
  * Exemplo: string *ptr = &alimento;

