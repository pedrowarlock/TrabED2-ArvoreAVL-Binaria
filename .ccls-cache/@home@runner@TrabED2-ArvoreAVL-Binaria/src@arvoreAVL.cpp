#include "arvoreAVL.h"
#include "buscaLivro.h"
#include "menu.h"
#include <iostream>
#include <string.h>

pont criaArvore() { return 0; }

bool inserir(pont &pNo, std::string pNome, std::string bkNome, int line) {

  if (!pNo) {
      pNo = new no;
      pNo->termo = pNome;
      pNo->count = 1;
      pNo->dadoLivro.push_back({bkNome, line});
      pNo->esq = nullptr;
      pNo->dir = nullptr; 
      return true;
  } else {
    if (pNome == pNo->termo) {
      pNo->count++;
      pNo->dadoLivro.push_back({bkNome, line}); 
      return false;
    } else if (pNome < pNo->termo){
      return inserir(pNo->esq, pNome, bkNome, line); 
    }else{
      return inserir(pNo->dir, pNome, bkNome, line);  
    }
  } 
}

bool remover(pont &p, std::string n) {
  // Caso o nó não seja encontrado
  if (!p)
    return false;

  // Percorre a árvore em busca do nó
  if (n < p->termo)
    remover(p->esq, n);
  else if (n > p->termo)
    remover(p->dir, n);

  else {
    // Guardamos o nó encontrado em aux
    pont aux = p;

    if (!p->esq && !p->dir) {

      // Remoção de um nó folha
      p = nullptr;
      delete aux;

    } else if (!p->esq || !p->dir) {

      // Caso haja só um filho
      if (p->esq)
        p = p->esq;
      else
        p = p->dir;

      delete aux;

    } else {

      // Troca a termo do nó buscado e apaga o nó que substiui

      pont paiAux = p;
      aux = paiAux->dir;

      while (aux->esq) {
        paiAux = aux;
        aux = aux->esq;
      }

      if (paiAux->termo == n)
        paiAux->dir = aux->dir;
      else
        paiAux->esq = aux->dir;

      p->termo = aux->termo;
      // p->termo = aux->termo; // Troca a termo

      delete aux; // Libera a memória do endereço do nó
    }
  }
  return true;
}

/*
    passa por todos nós da árvore de uma forma recursiva e deleta cada item da
   memória #Falta colocar o ponteiro das ocorrencias.
 */
pont limpar(pont &raiz) {
  if (!raiz)
    return nullptr;

  raiz->esq = limpar(raiz->esq);
  raiz->dir = limpar(raiz->dir);

  delete raiz;
  return nullptr;
}

int contarNos(pont raiz) {
  if (!raiz)
    return 0;

  return contarNos(raiz->esq) + 1 + contarNos(raiz->dir);
}

/*
    Compara a altura das subarvores para definiar a altura.
 */
int altura(pont raiz) {
  if (!raiz)
    return -1;

  int esq, dir;

  esq = altura(raiz->esq);
  dir = altura(raiz->dir);

  if (esq > dir)
    return 1 + esq;
  else
    return 1 + dir;
}

int fatorBalanceamento(pont raiz) {
  return altura(raiz->esq) - altura(raiz->dir);
}

void atualizaFB(pont g) {
  if (g) {
    g->fb = fatorBalanceamento(g);
    atualizaFB(g->esq);
    atualizaFB(g->dir);
  }
}

// Funcões da árvore AVL
pont rotacionarEsqEsq(pont p) {
  pont temp = p;
  pont esq = temp->esq;

  temp->esq = esq->dir;
  esq->dir = temp;

  return esq;
}

pont rotacionarEsqDir(pont p) {
  pont temp = p;
  pont esq = temp->esq;
  pont dir = esq->dir;

  temp->esq = dir->dir;
  esq->dir = dir->esq;
  dir->esq = esq;
  dir->dir = temp;

  return dir;
}

pont rotacionarDirEsq(pont p) {
  pont temp = p;
  pont dir = temp->dir;
  pont esq = dir->esq;

  temp->dir = esq->esq;
  dir->esq = esq->dir;
  esq->dir = dir;
  esq->esq = temp;

  return esq;
}

pont rotacionarDirDir(pont p) {
  pont temp = p;
  pont dir = temp->dir;

  temp->dir = dir->esq;
  dir->esq = temp;

  return dir;
}

pont balancear(pont p) {
  if (!p)
    return nullptr;

  pont balanceado = nullptr;
  if (p->esq)
    p->esq = balancear(p->esq);

  if (p->dir)
    p->dir = balancear(p->dir);

  int fator = p->fb;

  if (fator >= 2) {

    if (p->esq->fb <= -1)
      balanceado = rotacionarEsqDir(p);
    else
      balanceado = rotacionarEsqEsq(p);

  } else if (fator <= -2) {

    if (p->dir->fb >= 1)
      balanceado = rotacionarDirEsq(p);
    else
      balanceado = rotacionarDirDir(p);
  } else {
    balanceado = p;
  }

  return balanceado;
}
