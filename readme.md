# Sistemas Operacionais

## Atividade de chamadas de sistema

### Objetivo

Proporcionar aplicação prática dos conceitos de chamadas de sistemas, syscall, em sistemas operacionais
Unix e derivados.

### Chamada de sistema

Chamadas de sistema são funções que o Sistema Operacional disponibiliza para acessar os recursos que o mesmo gerencia. Para facilitar o uso dessas funções são desenvolvidos programas de sistemas, que permitem que o usuário realize tarefas administrativas através da execução de programas, ao invés de fazer ele mesmo um programa.

## Programas

Os programas de sistemas a serem implementados são:
date Mostra a hora atual.

- [x] [date](codigos/date.cpp)

    Mostra a data e hora atuais

- [x]  [Uptime](codigos/uptime.cpp)
    
    Mostra há quanto tempo o computador está ligado
    
- [x]  [ls](codigos/ls.cpp)
    
    Lista os arquivos localizados em um determinado diretório. Caso não seja especificado o diretório, usa o diretório de trabalho atual, que pode ser recuperado pela chamada de sistema getcwd().
    
- [ ]  [cp](codigos/cp.cpp)
    
    Copia os conteúdos de um arquivo para o outro
    
- [ ]  [rm](codigos/rm.cpp)
    
    Remove arquivos
    
- [ ]  [mv](codigos/mv.cpp)
    
    Muda um arquivo de lugar. pode mudar um conjunto de arquivos se o destino for um diretório
    
- [ ]  [cat](codigos/cat.cpp)
    
    Mostra o conteúdo de um arquivo no terminal, considerando apenas arquivos em modo texto
    
- [ ]  [mkdir](codigos/mkdir.cpp)
    
    Cria um novo diretório
    
- [ ]  [rmdir](codigos/rmdir.cpp)
    
    Remove um diretório caso o mesmo esteja vazio
    
- [ ]  [chmod](codigos/chmod.cpp)
    
    Muda as permissões de um arquivo/diretório
    
- [ ]  [chown](codigos/chown.cpp)
    
    Muda o usuário dono de um arquivo ou grupo ao qual ele pertence
