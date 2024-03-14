#include <unistd.h>   //para excusão de diretórios
#include <sys/stat.h> //para gerencimaento de diretórios
#include <iostream>   //para output

int main(int argc, char **argv)
{
    struct stat st; // checa se o diretório existe
    for (int i = 1; i < argc; i++)
    {
        if (stat(argv[i], &st) == 0)
        { // diretório existe
            if (rmdir(argv[i]) != 0)
            { // tenta remover diretório
              // diretório não está vazio ou outro código de erro
                std::cout << "Diretório " << argv[i] << " não removido\n";
            }
        }
        else
        { // diretório não existe
            std::cout << "Diretório " << argv[i] << " não existe\n";
        }
    }
    return 0;
}