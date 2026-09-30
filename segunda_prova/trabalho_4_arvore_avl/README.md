# Trabalho 4: Árvore AVL

Material de Referência: Aula 5 (arvores-avl.pdf)

## Descrição do Trabalho

Implementação da classe ArvoreAVL estendendo a classe base NoBinario, garantindo o balanceamento por altura (|h_esq - h_dir| <= 1) através de rotações simples e duplas nas operações de inserção e remoção.

* Implementar a árvore usando Templates;
* Usar as melhores práticas de orientação a objetos;
* Documentar classes, métodos e atributos;
* Validar com os testes unitários da disciplina.

## Estrutura Implementada (ArvoreAVL.hpp)

* Classe ArvoreAVL<T> : public NoBinario<T>:
  * Construtor ArvoreAVL(const T& dado): inicializa altura como zero e chama NoBinario.
  * int getAltura(): retorna a altura do nó.
  * int fator(ArvoreAVL<T>* raiz): calcula o fator de desbalanceamento (h_esq - h_dir).
  * void atualiza(ArvoreAVL<T>* arv): atualiza a altura do nó com base nos filhos.
  * ArvoreAVL<T>* simp_roda_esq(ArvoreAVL<T>* raiz): rotação simples à esquerda.
  * ArvoreAVL<T>* simp_roda_dir(ArvoreAVL<T>* raiz): rotação simples à direita.
  * ArvoreAVL<T>* dup_roda_esq(ArvoreAVL<T>* raiz): rotação dupla à esquerda.
  * ArvoreAVL<T>* dup_roda_dir(ArvoreAVL<T>* raiz): rotação dupla à direita.
  * ArvoreAVL<T>* balanco_insere(NoBinario<T>* arv): verifica fator e aplica rotação necessária após inserção.
  * ArvoreAVL<T>* balanco_remove(NoBinario<T>* arv): verifica fator e aplica rotação necessária após remoção (regra do zigue-zague).
  * ArvoreAVL<T>* inserir(const T& info, ArvoreAVL<T>* raiz): insere nó e rebalanceia.
  * ArvoreAVL<T>* remover(NoBinario<T>* raiz, const T& info): remove nó e rebalanceia.
