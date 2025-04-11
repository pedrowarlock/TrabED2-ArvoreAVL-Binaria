# 🌳 Trabalho ED2 – Árvore AVL Binária

Este projeto foi desenvolvido como parte do trabalho AV1 da disciplina de **Estrutura de Dados II (ED2)** no curso de Ciência da Computação em 2022. O objetivo principal é criar um sistema que leia um conjunto de arquivos de texto e armazene todas as palavras encontradas em uma **árvore AVL**. Cada nó da árvore contém uma lista dos arquivos onde a palavra foi encontrada, a quantidade de ocorrências em cada arquivo e as linhas específicas onde a palavra aparece.

---

## 📚 Funcionalidades

- Leitura de múltiplos arquivos de texto.
- Armazenamento de palavras em uma árvore AVL balanceada.
- Para cada palavra, registro de:
  - Arquivos onde foi encontrada.
  - Número de ocorrências por arquivo.
  - Linhas específicas de ocorrência.

---

## 🧪 Demonstração Online

Você pode testar o projeto diretamente no Replit:

🔗 [Executar no Replit](https://replit.com/@pedrowarlock/TrabED2-ArvoreAVL-Binaria#src/menu.cpp)

---

## 📁 Estrutura do Projeto

```
├── src/                  # Arquivos-fonte do projeto
│   ├── avl.cpp/hpp       # Implementação da árvore AVL
│   ├── menu.cpp/hpp      # Lógica do menu principal
│   └── utils.cpp/hpp     # Funções auxiliares
├── main                  # Executável principal
├── main-debug            # Versão debug do executável
├── Makefile              # Script de compilação
├── .replit / replit.nix  # Configurações do Replit
├── *.txt                 # Arquivos de texto para teste
└── README.md             # Documentação do projeto
```

---

## ⚙️ Requisitos

- Compilador C++ (como `g++`)
- Ambiente de desenvolvimento com suporte a C++
- (Opcional) Conta no [Replit](https://replit.com/) para execução online

---

## 🚀 Como Executar Localmente

1. Clone o repositório:

```bash
git clone https://github.com/pedrowarlock/TrabED2-ArvoreAVL-Binaria.git
cd TrabED2-ArvoreAVL-Binaria
```

2. Compile o projeto com o Makefile:

```bash
make
```

3. Execute o programa:

```bash
./main
```

---

## 🧑‍🏫 Informações Acadêmicas

- **Disciplina:** Estrutura de Dados II (ED2)  
- **Professor:** Denis  
- **Ano:** 2022  
- **Avaliação:** AV1 (4 pontos)

---

## 📄 Licença

Este projeto está licenciado sob a **Licença MIT**. Consulte o arquivo `LICENSE` para mais informações.

---

## 👨‍💻 Autor

Desenvolvido por [Pedro Warlock](https://github.com/pedrowarlock)

---

> ⚠️ **Nota:** Este repositório foi arquivado em 22 de agosto de 2022 e está disponível apenas para leitura.
