# Trabalho 5: Árvore Rubro-Negra (Red-Black)

Material de Referência: Aula 6 (14-arvores-rb.pdf)

## Descrição do Trabalho

Implementação da classe NoRedBlack estendendo NoBinario, garantindo as 5 propriedades da árvore rubro-negra através de rotações e recoloração na inserção e na deleção (Passo-CED).

* Implementar a árvore usando Templates;
* Usar as melhores práticas de orientação a objetos;
* Documentar classes, métodos e atributos;
* Validar com os testes unitários da disciplina.

## Propriedades da Árvore Rubro-Negra (Slide 4)

1. Todo nodo é rubro (vermelho) ou negro (preto).
2. A raiz é sempre negra.
3. Todas as folhas (nós nulos) são negras.
4. Se um nodo é rubro, os seus dois filhos são negros.
5. Para cada nodo, todos os caminhos até folhas descendentes contêm o mesmo número de nodos negros.

## Estrutura Implementada (NoRedBlack.hpp)

* Classe NoRedBlack<T> : public NoBinario<T>:
  * Atributos: info (T*), esquerda, direita, pai, cor (bool: true=rubro, false=negro).
  * Construtor NoRedBlack(const T& dado): inicializa com cor rubra e ponteiros nulos.
  * roda_esq(raiz, x): rotação à esquerda ajustando ponteiros de pai e filhos.
  * roda_dir(raiz, y): rotação à direita ajustando ponteiros de pai e filhos.
  * insereRB(raiz, dado): inserção BST seguida da correção de violações (Casos 1, 2 e 3 de tio rubro ou negro).
  * remover(raiz, dado): remoção de nó da árvore seguida de balanceamento quando nó removido for negro.
  * passoCED(raiz, x, x_pai): procedimento de Correção e Elevação da Deleção (Casos 1 a 4).
  * busca(raiz, dado): procura por valor na árvore.
  * imprimeEmOrdem(n): percurso em ordem exibindo valor e cor.
