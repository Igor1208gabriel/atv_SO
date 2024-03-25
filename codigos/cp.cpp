#include <iostream>
#include <fcntl.h>  // Para as chamadas open e close
#include <unistd.h> // Para as constantes de controle de arquivo:
                    // O_RDONLY, O_WRONLY, O_CREAT, S_IRUSR e S_IWUSR

int main(int argc, char **argv)
{

    if (argc < 3)
    { // não tem exatamente dois arquivos
        std::cerr << "Digite a entrada corretamente\n";
        return 1;
    }

    if (argc == 3)
    {                                 // copiar de um arquivo para outro
        const char *fontee = argv[1]; // localização do arquivo fonte
        const char *alvoe = argv[2];  // localização do arquivo alvo
        char buff[1024];              // buffer de caracteres, para copiar DE fonte PARA alvo, 1024 caracteres por vez
        int s;

        int fonte = open(fontee, O_RDONLY);
        int alvo = open(alvoe, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        // abrindo os arquivos pelos paths

        while ((s = read(fonte, buff, 1024)) != 0)
        {                         // enquanto houverem caracteres para ler
            write(alvo, buff, s); // ler de fonte, colocar no buffer, e escrever no alvo
        }

        close(alvo); // fechar os arquivos
        close(fonte);
    }

    /*  sei o que fazer aqui, porém não deu tempo
        na pasta nova, criar um arquivo para cada arquivo a copiar

        else{

        const char *alvoe = argv[argc-1];
        int alvo = open(alvoe, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

            for(int i = 1; i < argc-1;i++){
                char *fontee = argv[i];
                char buff[1024];
                int s;

                int fonte = open(fontee, O_RDONLY);

                while((s = read(fonte, buff, 1024)) != 0){
                    write(alvo, buff, s);
                }
                close(fonte);
            }

            close(alvo);
        }
    */

    return 0;
}