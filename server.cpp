#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_net.h"

using namespace std;


  int main(){
       // create a listening TCP socket on port 9999 (server)
    IPaddress ip, *ipClient;
    TCPsocket tcpsock,client;

    //Array de sockets para os clientes
    //30 Jogos rodando, ou seja, 60 clientes
    const int maxClients = 30;

    TCPsocket clients[maxClients][2];

    //Inicializa vetor
    for(int i = 0; i<maxClients; i++){
      for(int j = 0; j < 2; j++){
        clients[i][j] = NULL;
      }
    }

    //Monta estrutra IPaddress
    if(SDLNet_ResolveHost(&ip,NULL,9999)==-1) {
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        exit(1);
    }

    //Inicia listener
    tcpsock=SDLNet_TCP_Open(&ip);
    if(!tcpsock) {
        printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        exit(2);
    }

      cout << endl;
      cout << "Servidor Escutando na porta 9999!" << endl;
      
    while(true){
      // Verifica teclado
      // Descobrir funçao que lê teclado.

      //Espera conexão
      client = SDLNet_TCP_Accept(tcpsock);
      if(client != NULL) {  // Novo client conectou
          cout << "Conexão Iniciada!" << endl;
          //Recupera ip do client
          if(ipClient = SDLNet_TCP_GetPeerAddress(client)){
            cout << "Cliente conectado: " << SDLNet_Read32(&ipClient->host) << " " << SDLNet_Read16(&ipClient->port) << endl;
            // Verifica se existe slots disponivel
            bool achou = false;
            for(int i = 0; i<maxClients; i++){
                if(clients[i][1] == NULL) {
                   // Manda mensagem de aguardando parceiro
                  cout << "Aguarde conexao do guest" << endl;
                  if(SDLNet_TCP_Send(client,(void *) "A", 1) == 0){
                    cout << "Erro no envio de mensagem" << endl;
                    //Disconecta
                    SDLNet_TCP_Close(client);
                  }else{
                     //Primeiro do par
                    clients[i][1] = client;
                    achou = true;
                  }
                  break;
                }
                if(clients[i][2] == NULL) {
                   // Manda mensagem de parceiro conectado
                  cout << "Guest conectado" << endl;
                  if(SDLNet_TCP_Send(clients[i][1], (void *) "C", 1) == 0){
                    cout << "Host desconetado" << endl;
                    //Disconecta
                    SDLNet_TCP_Close(clients[i][1]);
                    // Faz este o primeiro do par
                    cout << "Convertendo para host" << endl;
                    if(SDLNet_TCP_Send(client,(void *) "A", 1) == 0){
                      cout << "Erro no envio de mensagem" << endl;
                      //Disconecta
                      SDLNet_TCP_Close(client);
                    }else{
                      //Host
                      clients[i][1] = client;
                      achou = true;
                    }

                  }else{
                    if(SDLNet_TCP_Send(client, (void *) "C", 1) == 0){
                      cout << "Erro no envio de mensagem" << endl;
                    }else{
                      //Guest
                      clients[i][2] = client;
                      achou = true;
                    }
                  }
                  break;
              }
            }
            if(achou == false){
              //Nenhum slot disponivel
              SDLNet_TCP_Send(client,(void *) "F", 1);
              SDLNet_TCP_Close(client);
            }
          }else{
            cout << "Erro na CONEXAO: " << SDLNet_GetError() << endl;
          }
      }

      // Verifica se tem mensagem para receber/enviar

    }
  }

