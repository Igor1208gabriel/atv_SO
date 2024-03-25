#include <sys/stat.h> //para o chmod
#include <string.h>   //para a transformação de char* em octal
#include <iostream>   //para saída

int main(int argc, char **argv)
{
    if (argc == 3)
    { // checa se os parâmetros estão certo

        char *modo = argv[1];
        char *alvo = argv[2];
        // seleciona as permissões e o arquivo ou diretório a ser mudado

        int i = strtol(modo, 0, 8); // função que transforma um char* em octal

        if (chmod(alvo, i) < 0)
        { // tenta realizar a mudança de permissão
            std::cerr << "Não foi possível\n";
        }
    }

    else
    { // permissões incorretas
        std::cerr << "Não foi possível - erro nos parâmetros\n";
        return 1;
    }
    return 0;
}