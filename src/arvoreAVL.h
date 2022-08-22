#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include <iostream>
#include <vector>

//using namespace std;

typedef struct nodeBook {
  std::string bookName;
  int line;
} noLivro;

typedef struct aux {
  std::string termo;
  int count;
  std::vector<noLivro> dadoLivro;

  int fb = -1;
  aux *esq, *dir;
} no;

typedef no *pont;
bool inserir(pont &pNode, std::string, std::string, int);
pont criaArvore();
bool remover(pont &p, std::string);
pont limpar(pont &raiz);
int contarNos(pont);
int altura(pont);
int fatorBalanceamento(pont);
void atualizaFB(pont);
pont rotacionarEsqEsq(pont);
pont rotacionarDirDir(pont);
pont balancear(pont);


#endif
