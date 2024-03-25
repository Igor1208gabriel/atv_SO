#include <sys/stat.h>
#include <iostream>

int main(int argc, char **argv)
{

    for (int i = 1; i < argc; i++)
    { // para toda a lista argv, tenta criar diretórios com os nomes passados
        if (mkdir(argv[i], 0777) == -1)
            // comando para criar um diretório com todas as permissões
            // se este já não existir
            std::cerr << "mkdir: não pode criar diretório '" << argv[i] << std::endl;
    }

    return 0;
}