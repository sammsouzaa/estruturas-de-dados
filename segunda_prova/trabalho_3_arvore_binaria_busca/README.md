# Trabalho 3: Árvore Binária de Busca (BST)

Material de Referência: Aula 4 (12-Lecture_12.pdf)

## Enunciado do Slide (Slide 61)

* Implemente uma classe NoBinario para representar a sua árvore;
* Implemente a arvore usando Templates;
* Use as melhores práticas de orientação a objetos;
* Documente todas as classes, métodos e atributos;
* Aplique os testes unitários disponíveis no moodle da disciplina para validar sua estrutura de dados;
* Entregue até a data definida no moodle.

## Estrutura Implementada (Arvore.hpp)

* Classe NoBinario<T>:
  * NoBinario(const T& dado): construtor que inicializa dado e ponteiros esquerda e direita nulos.
  * ~NoBinario(): destrutor que libera a memória alocada do dado e limpa o vetor de percorrimento.
  * inserir(const T& dado, NoBinario<T>* raiz): insere recursivamente na posição correta mantendo a propriedade BST.
  * busca(const T& dado, NoBinario<T>* ptr): busca por chave na árvore; lança exceção (-1) se não encontrada.
  * remover(NoBinario<T>* raiz, const T& dado): remove nó com 0 filhos (folha), 1 filho ou 2 filhos (substituindo pelo menor da subárvore direita).
  * minimo(NoBinario<T>* raiz): retorna o menor nó da subárvore.
  * preOrdem(NoBinario<T>* raiz): percurso raiz, esquerda, direita.
  * emOrdem(NoBinario<T>* raiz): percurso esquerda, raiz, direita (retorna elementos ordenados).
  * posOrdem(NoBinario<T>* raiz): percurso esquerda, direita, raiz.
  * getDado(), getEsquerda(), getDireita(), getElementos(), limpaElementos().
