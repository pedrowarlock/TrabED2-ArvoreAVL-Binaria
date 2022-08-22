#include <iostream>
#include <vector>
#include "./menu.h"
#include "./buscaLivro.h"

//Loop principal - inicio
int main()
{  
    setlocale(LC_ALL, "Portuguese"); //necessario para verificar caracteres especiais.
    std::string iTermoNome;
    const std::string nLivros[] =    //Lista de livros a ser verificado e adicionado.
    {
      "A Revolução Portugueza.txt",
      "As Minas de Salomão.txt",
      "Flores do campo.txt"
    };


    pont arv = criaArvore();          //Cria a árvore vazia;
    std::vector <BuscaLivro> vTermos;
    std::vector <BuscaLivro> vTmp;
    std::string termo;
    bool rotacionar = false;
    int contador = 0, contaPalavras = 0;
  
    //Lê cada livro e adiciona na árvore
    for(int i= 0; i < sizeof(nLivros)/sizeof(nLivros[0]); i++)
    {
        clearConsole();
        vTmp =  procurarNome(nLivros[i]);                          //Retorna um vetor com todas palavras do livro
        vTermos.insert( vTermos.end(), vTmp.begin(), vTmp.end());  //Concatena o vetor temporario das palavras com o vetor original.
    }
  
    //Adiciona todas as palavras uma a uma na árvore, ao adicionar, balanceia a árvore.
    for (std::vector<BuscaLivro>::iterator iTermo=vTermos.begin(); iTermo!=vTermos.end(); ++iTermo)
    {
          //Exibe uma mensagem informativa
          contador++;
          if(contador % 1000 == 0){
             clearConsole();
                std::cout << "Verificando igualdade, inserindo e balanceando árvore:" << std::endl;
                std::cout << "Palavras encontradas: ["<< std::to_string(contador) << "/"<< vTermos.size() << "]" << std::endl;
                std::cout << "Palavras não repetidas: [" << contaPalavras << "]" << std::endl;
          }
  
        termo = stringCaixaAlta(iTermo->termo);  //Envia o novo termo com caixa alta para a árvore.
        rotacionar = inserir(arv, termo, iTermo->livro, iTermo->linha); //Adiciona o termo na árvore.
        if(rotacionar){            //Verifica se o termo foi adicionado ou somente incrementado, caso foi adicionado, balancear árvore.
            atualizaFB(arv);       //Atualiza o fator de balanceamento de cada item da árvore
            arv = balancear(arv);  //Balanceia a árvore.
            contaPalavras++;
        }
    }

    clearConsole();
    do
    {
        std::cout << "# ------------------------------------------------------ #" <<std::endl;
        std::cout << "# ------------------ Arvore AVL binária ---------------- #" <<std::endl;
        std::cout << "# ------------------------------------------------------ #" <<std::endl;
        std::cout << "# Livros: " <<std::endl;
        for(int i = 0; i < sizeof(nLivros)/sizeof(nLivros[0]); i++)
        {
            std::cout << "\t" << nLivros[i] <<std::endl;
        }
        std::cout << "# Termos: " << contarNos(arv) <<std::endl;

        std::cout << "# ------------------------------------------------------ #" <<std::endl;
        std::cout << " Digite um termo para verificar a existência na árvore." <<std::endl;
        std::cout << " Digite (#sair) para encerrar o programa." <<std::endl;
        std::cout << " Digite (#resultado) para listar todas as [" << contarNos(arv) << "] palavras na árvore." <<std::endl;
        std::cout << "# ------------------------------------------------------ #" <<std::endl;
        std::cout << " Termo: ";
        std::cin >> iTermoNome;
        iTermoNome = stringCaixaAlta(iTermoNome);
        if (iTermoNome == "#SAIR"){
            break;         
        }else if(iTermoNome == "#RESULTADO"){
          mostraResultado(arv); //Exibe o resultado listado na tela com todas as palavras.
        }else{
          clearConsole();          
        }
        mostraTermoMenu(arv, iTermoNome);
    }
    while (true);

    clearConsole();
    std::cout << "Programa finalizado." <<std::endl;
    return 0;
}

//Exibe o resultado com todas as palavras no console.
void funcMostraResultado(pont arv, bool *mapa, int nivel, bool esq)
{
    if (arv)
    {
        mapa[nivel] = true; // Define que a linha deste nível deve ser escrita
        if (nivel) // Vai para o nó da esquerda (e verifica se  da esquerda), então           
            mapa[nivel - 1] = (esq) ? false : true; // desbilita a linha anterior

        funcMostraResultado(arv->esq, mapa, nivel + 1, true);
        std::cout << std::left;
        // Exibe o nó
        std::cout << arv->termo << " fb(" << arv->fb << ") " << std::endl;
        funcMostraResultado(arv->dir, mapa, nivel + 1, false);
    }
}

//Menu usado para visualizar cada palavra contida na árvore;
void mostraTermoMenu(pont p, std::string nTermo, int nNivel)
{
    int info;
    std::string nNome;
    if (p)
    {
        nNome = stringCaixaAlta(p->termo);
        if(nTermo == nNome)
        {
            int vecSize = p->dadoLivro.size();
            clearConsole();
            std::cout << "# --------------- Termo encontrado!------------------ #" << std::endl;
            std::cout << " Termo: " << p->termo <<std::endl;
            std::cout << " Fator de Balanceamento: " << p->fb <<std::endl;
            std::cout << " Nivel: " << nNivel  << std::endl ;
            std::cout << " Ocorrência(s): " << vecSize <<std::endl ;
            std::cout << " ----------------------------------------------------- " << std::endl;
            std::cout << " Mostrar ocorrências? Sim(1) Não(0): ";
            std::cin  >> info;
            if(info > 0)
            {
                std::cout << "\t+--------" <<std::endl;
                for (int i = 0; i < vecSize; i++)
                {
                    std::cout << "\t Livro: ";
                    std::cout << p->dadoLivro[i].bookName <<std::endl;
                    std::cout << "\t Linha:" << p->dadoLivro[i].line <<std::endl;
                    std::cout << "\t+--------" <<std::endl;
                }
            }
            return;
        }
        mostraTermoMenu(p->esq, nTermo, nNivel + 1);
        mostraTermoMenu(p->dir, nTermo, nNivel + 1);
    }

}


void mostraResultado(pont arv)
{
    bool mapa[255] = {};
    funcMostraResultado(arv, mapa);
}


//limpa o console
void clearConsole()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif
}
