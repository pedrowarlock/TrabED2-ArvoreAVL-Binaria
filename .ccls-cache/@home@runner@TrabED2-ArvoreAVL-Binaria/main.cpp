#include <locale>
#include "./src/arvoreAVL.h"
#include "./src/menu.h"


int main() {
    setlocale(LC_ALL, "");
    pont arv = criaArvore();
    mainMenu(arv);
  return 0;
}
