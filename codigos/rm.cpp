#include <iostream>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {   //checa se os parâmetros estão corretos
        char *alvo = argv[1];
        //pega o nome do arquivo a ser removido

        if (unlink(alvo) == -1)
        {//tenta remover o arquivo. caso dê tudo certo, encerra o programa
            std::cerr << "Falha na remoção do arquivo\n";
            return 2;
        }
    }
    else
    {   //se os parâmetros estiverem errados
        std::cerr << "Forneça apenas um nome de arquivo\n";
        return 1;
    }

    return 0;
}