#include <fcntl.h>  // Para as chamadas open e close
#include <unistd.h> // Para as constantes de controle de arquivo:
                    // O_RDONLY, O_WRONLY, O_CREAT, S_IRUSR e S_IWUSR

int main(int argc, char **argv)
{

    for (int i = 1; i < argc; i++)
    {

        char *fonte = argv[i];
        char buff[1];
        int f = open(fonte, O_RDONLY), s;
        /*
        fonte é o arquivo para ler
        buff é o buffer de quantos caracteres ler por vez
            configurado para 1 para evitar erros
                *nota: sei o quão ineficiente isso é. Tenho total ciência das consequências e fiz mesmo assim

        f é o arquivo aberto
        */

        if (f >= 0)
        {
            // checa se o arquivo existe
            while ((s = read(f, buff, 1)) != 0)
                write(1, buff, 1);
            // enquanto houverem caracteres no arquivo fonte, printar um por um
        }
        else
        {
            write(1, "Arquivo não existe\n", 20);
        }

        write(1, "\n\n", 2);
    }

    return 0;
}