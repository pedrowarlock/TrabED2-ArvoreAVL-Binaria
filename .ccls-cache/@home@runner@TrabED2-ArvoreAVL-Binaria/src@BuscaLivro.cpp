#include <fstream>
#include <algorithm>
#include <vector>
#include "./arvoreAVL.h"
#include "./BuscaLivro.h"

// Remove a extensão do arquivo.
std::string removeExtensao(const std::string &file) {
  size_t lastdot = file.find_last_of(".");
  if (lastdot == std::string::npos)
    return file;
  return file.substr(0, lastdot);
}

// Converte a std::string para caixa alta.
std::string stringCaixaAlta(std::string str) {
  transform(str.begin(), str.end(), str.begin(),
            ::toupper);
  return str;
}

// Busca o termo no arquivo indicado.
void procurarNome(pont &arv,std::string file) {
  std::ifstream nfile(file);
  std::string linha;
  int count = 1;
  std::string fName = removeExtensao(file);
  std::vector<std::string> lineTmp;

  while (getline(nfile, linha)) {
    lineTmp = dividirLinha(linha);
    for (std::vector<std::string>::iterator t=lineTmp.begin(); t!=lineTmp.end(); ++t)
    {
       //Adiciona o termo na árvore.
       inserir(arv, *t, fName, count);
    }
    count++;
  }
}

std::vector<std::string> explode(const std::string &data, const std::string &delimiters) {
  auto is_delim = [&](auto &c) {
    return delimiters.find(c) != std::string::npos;
  };
  std::vector<std::string> result;
  for (std::string::size_type i(0), len(data.length()), pos(0); i <= len; i++) {
    if (is_delim(data[i]) || i == len) {
      auto tok = data.substr(pos, i - pos);
      if (!tok.empty())
        result.push_back(tok);
      pos = i + 1;
    }
  }
  return result;
}

std::vector<std::string> dividirLinha(const std::string str) {
  auto dem_res = explode(str, " .,;:*«»/_");
  std::vector<std::string> tmp;
  for (auto word : dem_res) {
    tmp.push_back(word);
  }

  return tmp;
}


