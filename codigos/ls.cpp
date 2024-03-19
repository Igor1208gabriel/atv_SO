#include <unistd.h> //para encontrar o diretório atual
#include <dirent.h> //para listar os itens dentro do diretório
#include <iostream> //para saída do código

void printe(const char *path)
{ // função para printar todos os itens em um diretório
    DIR *dir;
    dirent *esse;
    /*dir é um ponteiro para um diretório
      "esse" é um ponteiro para uma estrutura chamada dirent
      dirent guarda informações de arquivos dentro do diretório dir
    */
    if ((dir = opendir(path)) != NULL)
    {
        // vai tentar abrir um diretório especificado pelo PATH
        // caso não consiga, dá erro

        while ((esse = readdir(dir)) != NULL)
        {
            // enquanto houver arquivos no diretório, vai imprimir o nome de cada um
            std::cout << esse->d_name << " ";
        }
    }
    else
    {
        std::cerr << "Digite um nome válido de diretório" << std::endl;
        return;
    }
}

int main(int argc, char **argv)
{
    const char *path;
    // path é o caminho do diretório alvo.
    if (argc == 1) // aqui o diretório alvo é o atual, encontrado com getcwd()
    {
        path = getcwd(NULL, 0);
        printe(path);
    }

    else if (argc >= 2) // aqui, o diretório alvo é um parâmetro do programa
    {                   // e os alvos são listados nos argumentos

        for (int i = 1; i < argc; i++)
        {
            // diretório por diretório passado para o programa,
            // o código passa pela função "printe" para imprimir todos os itens
            std::cout << argv[i] << ":\n";
            printe(argv[i]);
            std::cout << std::endl
                      << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
}