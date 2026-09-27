### Questão 1: Definição da Classe Base (Contrato)
* **O que o enunciado pede:** Apenas a **definição** (a estrutura/esqueleto) da classe em C++, e não a lógica dos métodos de fato.
* **Como eu interpretaria para resolver:**
    1. Criaria a estrutura básica `class OperacaoMatematica { ... };`.
    2. No bloco `private:`, declararia duas variáveis (provavelmente do tipo `double` ou `float` para aceitar qualquer número) que representarão o primeiro e o segundo operando.
    3. No bloco `public:`, declararia a assinatura do **Construtor** (que serve para inicializar esses atributos quando o objeto for criado) e a assinatura do método de **Multiplicação** (que deve retornar o resultado da operação). *Dica de ouro:* Aqui na definição, você só coloca os protótipos dos métodos (ex: `double multiplicacao();`).

### Questão 2: Implementação dos Métodos da Classe Base
* **O que o enunciado pede:** Agora sim, o código com a lógica do que foi declarado na Questão 1.
* **Como eu interpretaria para resolver:**
    1. Usaria o operador de escopo de C++ (`OperacaoMatematica::`) para externalizar a lógica.
    2. **O Construtor:** Receberia dois parâmetros e os atribuiria diretamente aos atributos privados da classe.
    3. **O Método Multiplicação:** Implementaria a lógica usando o operador aritmético clássico do C++ (o asterisco `*`). Ele pegaria o primeiro atributo, multiplicaria pelo segundo e daria um `return`.

### Questão 3: Instanciação e Uso (Função Principal)
* **O que o enunciado pede:** Um programa completo (com a função `main`) que teste o que foi feito até aqui.
* **Como eu interpretaria para resolver:**
    1. Criaria a função `int main()`.
    2. Instanciaria um objeto da classe criada na Questão 1, passando dois números reais no construtor (ex: `5.0` e `4.0`).
    3. Chamaria o método de multiplicação desse objeto e colocaria um `std::cout` para exibir o resultado na tela de forma limpa.

### Questão 4: Conceito de Herança
* **O que o enunciado pede:** Criar uma **nova** classe que herda tudo da primeira, mas adiciona o método de soma.
* **Como eu interpretaria para resolver:**
    1. Usaria a sintaxe de herança do C++: `class NovaClasse : public OperacaoMatematica { ... };`.
    2. Entenderia que os atributos e o método de multiplicação já vêm "de brinde" por causa da herança (embora, se os atributos forem estritamente privados na classe pai, a classe filha não os acessa diretamente, mas o enunciado só pede para adicionar o método de adição na estrutura).
    3. Declararia o protótipo do novo método público de adição.

### Questão 5: Testando a Herança
* **O que o enunciado pede:** Outro programa (`main`) para testar a classe filha.
* **Como eu interpretaria para resolver:**
    1. Na `main`, criaria um objeto agora utilizando a **classe nova** (a filha).
    2. Passaria os valores pro construtor (que ela herda da classe pai).
    3. Chamaria especificamente o novo método de adição e imprimiria o resultado. O foco aqui é provar que o objeto da classe filha consegue executar a nova operação.

### Questão 6: Redefinição (Polimorfismo / Sobrescrita)
* **O que o enunciado pede:** Alterar a definição da classe filha (da Questão 4) para avisar o C++ que a multiplicação ali vai se comportar de um jeito diferente.
* **Como eu interpretaria para resolver:**
    1. Reescreveria a estrutura da classe filha.
    2. Na seção `public:`, além do método de adição, eu colocaria exatamente a mesma assinatura do método `multiplicacao()` que existia na classe pai. Isso indica uma **sobrescrita (override)** de método.

### Questão 7: Lógica da Multiplicação por Somas Sucessivas
* **O que o enunciado pede:** Criar a lógica dessa multiplicação redefinida. O pulo do gato aqui é: **proibido usar o operador `*`**. Você precisa multiplicar usando o método de adição que criou na Questão 4.
* **Como eu interpretaria para resolver:**
    1. Pensaria no conceito matemático: o que é `5 * 3`? É o número `5` somado `3` vezes (ou vice-versa).
    2. Como os atributos estão na classe pai, para essa lógica funcionar bem, na Questão 1 os atributos idealmente deveriam ser `protected` (ou você precisaria de métodos *getters*). Assumindo o acesso a eles, eu criaria um laço de repetição (`for` ou `while`).
    3. O laço rodaria uma quantidade de vezes igual ao valor do "Segundo operando".
    4. A cada iteração do laço, em vez de fazer uma soma aritmética comum (`+`), eu chamaria o **método de adição** da própria classe para ir acumulando o valor do "Primeiro operando".
* **Por que essa interpretação é crítica:**
    * **Questão 1:** Se você declarar os atributos como `private` **na classe filha** (sem garantir o acesso), a lógica da Questão 7 falhará catastroficamente, pois o método de soma da filha não consegue ler os valores da classe pai.
    * **Questão 7:** O erro mais comum é tentar fazer `resultado = resultado + operando1;`. O avaliador **exige** que você use o método `this->adicao()` para provar que você entendeu polimorfismo e reutilização de código (recursão de métodos).