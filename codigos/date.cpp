#include <time.h>   //biblioteca das informações do tempo
#include <iostream> //biblioteca para input/output

char* dia(int d){
    static char* dias[7] = {"DOM ", "SEG ", "TER ", "QUA ", "QUI ", "SEX ", "SAB "};
    return dias[d];
        //tm_wday retorna um valor entre 0-6, o dia da semana. 
        //A função "dia" retorna a "tradução" deste valor numérico em um dia da semana
}

char* mes(int m){
    static char* meses[12] = {"JAN ", "FEV ", "MAR ", "ABR ", "MAI ", "JUN ", "JUL ", "AGO ", "SET ", "OUT ", "NOV ", "DEZ "};
    return meses[m];
        //tm_mon retorna um valor de 0-11, o mês do ano.
        //A função "mes" retorna a "tradução" desse valor em um mês do ano
}

int main(int argc, char **argv){
    time_t tempo_atual_inicial;
    time(&tempo_atual_inicial);
        //Usados para pegar o tempo desde Epoch, 00:00 01/01/1970

    tm *info;
    info = localtime(&tempo_atual_inicial);
        //struct com informações da data com base em tempo_atual_inicial (https://cplusplus.com/reference/ctime/tm/)
    
    std::cout
    << dia(info->tm_wday) << mes(info->tm_mon) << info->tm_mday << " " 
    << info->tm_hour << ":" << info->tm_min << ":" << info->tm_sec << " " 
    << info->tm_year+1900 << "\n";
        //tm_wday retorna o dia da semana entre 0-6
        //tm_mon retorna o mês do ano entre 0-11
        //tm_mday retorna o dia do mês entre 1-31
        //tm_hour retorna a hora entre 0-23
        //tm_min retorna o minuto entre 0-59
        //tm_sec retorna o segundo entre 0-59
        //tm_year retorna quantos anos se passaram desde 1900
        //Para mais informações, https://cplusplus.com/reference/ctime/tm/
    

    return 0;
}



