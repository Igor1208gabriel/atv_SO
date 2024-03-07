#include <time.h>   //usado para pegar o tempo atual
#include <fcntl.h>  //usado para abrir arquivos
#include <iostream> //usado para imprimir as infos no terminal
#include <unistd.h> //usado para ler os arquivos
#include <string.h> //usado para transformar um const *char em uma string em um inteiro 
#include <sstream>  //usado para transformar um const *char em uma string em um inteiro 
#include <iomanip>  //usado para deixar o output bonitinho =)

int main(int argc, char **argv){
    time_t tempo_atual_inicial;
    time(&tempo_atual_inicial);
        //Usados para pegar o tempo desde Epoch, 00:00 01/01/1970

    tm *info;
    info = localtime(&tempo_atual_inicial);
        //struct com informações da data com base em tempo_atual_inicial (https://cplusplus.com/reference/ctime/tm/)

    char buff[128];
    int fd = open("/proc/uptime", O_RDONLY);
    int s = read(fd, buff, 128);
      /*Código para abrir e ler o arquivo "Uptime" presente na pasta /proc
        este arquivo contém duas informações:
        o tempo em segundos desde que o sistema foi ligado
        a soma do tempo em segundos em que cada núcleo esteve parado
        https://access.redhat.com/documentation/pt-br/red_hat_enterprise_linux/6/html/deployment_guide/s2-proc-uptime

        buff recebe essas informações abertas pelo open e read
      */

    if(fd != -1 && s != 0){ //esta rotina só acontece caso o arquivo em /proc/uptime consiga ser lido
        std::stringstream ss(buff);
        std::string segundos;
        getline(ss, segundos, ' ');
        int segs = stoi(segundos);
          /*gambiarra ao qual estou MUITO orgulhoso.
            pega os valores de Buff
            transforma numa stringstream
            passa o primeiro valor do arquivo para "segundos"
            e transforma esse valor em um inteiro

            basicamente, pega o valor que está em /proc/update
            e transforma num inteiro, independente de seu tamanho
            
            *nota: talvez com valores MUITO longos seja necessário o uso de Long Long
          */

        int horas = segs/3600;
        int minutos = (segs/60)%60;
        int segundo = segs%60;
            //aritmética básica para transformar segundos em horas, minutos e segundos

        std::cout << std::setfill('0') << std::setw(2) <<
            //formata o código de um jeito bonitinho =)
        info->tm_hour << ":" << info->tm_min << ":" << info->tm_sec << " up " <<       
            //pega as informações do tempo atual. Ver "date.cpp"
        horas << ":" << minutos << ":" << segundo << std::endl;
            //imprime as informações do uptime do sistema!
    } else {
        std::cout << "Não foi possível resgatar o Uptime\n";
            //não consigo imaginar um caso onde isto aconteceria, a não ser se o sistema não fosse UNIX
            //vou deixar isso aqui mesmo assim 
    }


    return 0;
}