#include <unistd.h> //para encontrar o diretório atual
#include <dirent.h> //para listar os itens dentro do diretório
#include <iostream> //para saída do código

int main(int argc, char **argv){
    const char* path;
    //path é o caminho do diretório alvo.
    if(argc == 1)          //aqui o diretório alvo é o atual, encontrado com getcwd()
        path = getcwd(NULL, 0);

    else if(argc == 2) //aqui, o diretório alvo é um parâmetro do programa
        path = argv[1];
    
    
    else {              //aqui, os parâmetros foram passados errado. com mais de um diretório a listar
                        //daria sim para listar vários diretórios... mas não. 
        std::cout << "Digite corretamente os parâmetros\n";
        return 1;
    }

    DIR *dir;
    dirent *esse;
      /*dir é um ponteiro para um diretório
        "esse" é um ponteiro para uma estrutura chamada dirent
        dirent guarda informações de arquivos dentro do diretório dir 
      */
    if ((dir = opendir(path)) != NULL){
        //vai tentar abrir um diretório especificado pelo PATH 
        //caso não consiga, dá erro

        while((esse = readdir(dir)) != NULL ){
            //enquanto houver arquivos no diretório, vai imprimir o nome de cada um
            std::cout << esse->d_name << " ";
        }

    } else {
        std::cout << "Digite um nome válido de diretório" << std::endl;
        return 2;
    }

    std::cout << std::endl;
    
    return 0;
}