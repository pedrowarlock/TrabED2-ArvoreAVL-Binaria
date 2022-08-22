#ifndef MENU_H
#define MENU_H

#include "./arvoreAVL.h"

void funcMostraResultado(pont arv, bool *mapa, int nivel = 0, bool esq = true);
void mostraResultado(pont arv);
void mostraTermoMenu(pont, std::string, int nNivel = 0);
void clearConsole();
#endif
