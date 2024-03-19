#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int main(int argc, char **argv)
{
    if(argc == 3){
    char *modo = argv[1];
    char *alvo = argv[2];
    int i = strtol(modo, 0, 8);
        if(chmod(alvo,i) < 0){
            std::cerr << "Não foi possível\n";
        }
    }


    else{
        std::cerr << "Não foi possível - erro nos parâmetros\n";
        return 1;
    }
    return 0;
}