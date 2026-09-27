# RESUMO DA AULA: CLASSES E OBJETOS


## 1. INTRODUÇÃO AOS CONCEITOS DA POO

* Classe: Funciona como uma planta, molde ou especificação abstrata que define os 
  atributos (dados) e os comportamentos (funções/métodos) que os objetos gerados 
  a partir dela possuirão.
* Objeto: É uma instância concreta e física de uma determinada classe. Cada objeto 
  possui seu próprio estado (valores de seus atributos) e compartilha a mesma 
  lógica de comportamento definida pela classe.
* Atributos (Dados Membros): Variáveis que armazenam as características ou o 
  estado interno do objeto.
* Métodos (Funções Membros): Funções encapsuladas dentro da classe que operam e 
  manipulam os atributos daquele objeto.

## 2. ESPECIFICADORES DE ACESSO (ENCAPSULAMENTO)

Controlam a visibilidade e o nível de exposição dos membros de uma classe para 
o mundo externo (funções clientes):
* public: Os membros declarados sob esta cláusula são totalmente acessíveis por 
  qualquer parte do programa (fora ou dentro da classe). Define a interface do objeto.
* private: Os membros são estritamente restritos e só podem ser acessados ou 
  modificados por funções membros pertencentes à própria classe. É o padrão em C++.
* protected: Os membros ficam ocultos para o público geral, mas mantêm-se visíveis 
  e herdáveis pelas subclasses (classes derivadas).

## 3. PROJETO DE ORGANIZAÇÃO EM MÓDULOS (C++)

Uma boa prática em C++ dita a separação da classe em dois arquivos distintos:
* Arquivo de Cabeçalho (.h): Contém exclusivamente a especificação e declaração 
  da estrutura da classe, seus atributos e protótipos de métodos.
* Arquivo de Implementação (.cpp): Contém a codificação real do corpo das funções. 
  * Operador de Resolução de Escopo (::): Utilizado no arquivo .cpp para indicar 
    explicitamente a qual classe aquele método pertence (ex: void Carro::acelerar()).


# RESUMO DA AULA: CONSTRUTORES


## 1. CONCEITO E COMPORTAMENTO DO CONSTRUTOR

* Definição: É um método especial da classe executado de forma automática e implícita 
  no exato momento em que um objeto é instanciado na memória.
* Propósito: Garantir que o objeto inicie seu ciclo de vida em um estado válido, 
  sendo utilizado principalmente para a inicialização de atributos e alocação de recursos.
* Regras de Sintaxe:
  * Deve obrigatoriamente possuir o mesmo nome exato da classe.
  * Não possui nenhum tipo de retorno (nem mesmo void).

## 2. TIPOS DE CONSTRUTORES

* Construtor Padrão (Default): Não recebe nenhum parâmetro de entrada. Inicializa os 
  atributos com valores predefinidos ou zerados. Se o programador não escrever nenhum 
  construtor, o compilador gera um construtor padrão vazio automaticamente.
* Construtor Parametrizado: Recebe argumentos externos que permitem configurar e 
  atribuir valores personalizados aos atributos no momento exato da criação do objeto.
* Sobrecarga de Construtores: Uma classe pode conter múltiplos construtores, desde 
  que eles se diferenciem pela quantidade ou pelos tipos de seus parâmetros de entrada.

## 3. LISTA DE INICIALIZAÇÃO EM C++

* É uma sintaxe específica e otimizada em C++ para inicializar os atributos antes mesmo 
  da execução do corpo principal do construtor.
* Realizada logo após os parênteses dos parâmetros, utilizando dois pontos ':' seguidos 
  pelos nomes dos atributos e seus respectivos valores entre parênteses.
* Exemplo: Carro(string m, int a) : marca(m), ano(a) {}


# RESUMO DA AULA: CONSTRUTORES E ESPECIFICADORES DE ACESSO


## 1. INTEGRANDO ENCAPSULAMENTO E CONSTRUTORES

* Boas Práticas de Projeto: Recomenda-se manter todos os atributos configurados 
  como privados ('private') para proteger a integridade dos dados contra corrupção externa.
* O construtor atua como a primeira barreira de segurança, validando os parâmetros 
  recebidos antes de gravá-los nos atributos privados do objeto.
* Métodos de Acesso (Getters e Setters): Funções públicas ('public') criadas para 
  permitir a leitura (get) e a modificação controlada (set) dos atributos privados de 
  forma segura após o objeto já ter sido criado.

## 2. GERENCIAMENTO DE MEMÓRIA E DESTRUTORES

* Construtores dinâmicos: Podem alocar espaço de memória no Heap utilizando o operador 
  'new' para armazenar estruturas internas do objeto.
* Destrutores: Método especial executado de forma automática quando o ciclo de vida do 
  objeto se encerra (ou quando 'delete' é chamado).
  * Possui o mesmo nome da classe precedido por um til '~' (ex: ~Carro()).
  * É fundamental para liberar manualmente a memória alocada dinamicamente no construtor 
    (via 'delete'), evitando vazamentos de memória (memory leaks).

