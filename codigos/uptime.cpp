#include <time.h>  
#include <ctime> 
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <iomanip>

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

    if(fd != -1 && s != 0){
        std::stringstream ss(buff);
        std::string segundos;
        getline(ss, segundos, ' ');

        int segs = stoi(segundos);

        int horas = segs/3600;
        int minutos = (segs/60)%60;
        int segundo = segs%60;

        std::cout << std::setfill('0') << std::setw(2) << std::fixed <<
        info->tm_hour << ":" << info->tm_min << ":" << info->tm_sec << " up " <<           
        horas << ":" << minutos << ":" << segundo << std::endl;
    }


    return 0;
}