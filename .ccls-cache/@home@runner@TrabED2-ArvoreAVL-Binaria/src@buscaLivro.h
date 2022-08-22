#ifndef BUSCALIVRO_H_INCLUDED
#define BUSCALIVRO_H_INCLUDED
#include "./arvoreAVL.h"

typedef struct BuscaLivro{
    std::string termo;
    std::string livro;
    int linha;
}BuscaLivro;

std::vector <BuscaLivro> procurarNome(std::string);
std::string removeExtensao(const std::string &file);
std::string stringCaixaAlta(std::string);
std::vector <std::string> dividirLinha(const std::string);
std::vector <std::string> explode(const std::string &data, const std::string &delimiters);
#endif // BUSCALIVRO_H_INCLUDED
