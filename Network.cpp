#include <iostream>
#include <sstream>
#include "SDL/SDL.h"
#include "SDL/SDL_net.h"
#include "Network.h"

#define DEBUG 1

 Network::Network(){
    ipServidor = (char *) "thelastworldwar.game-host.org";
    porta = 9999;
    backspace = 8;
    //animacao[] = {'|','/','-','|','\\','-'};
    loop = 0;

    socketSet = SDLNet_AllocSocketSet(1);
    }

  void Network::initializeNetwork(){
    //Conecta com o servidor
    IPaddress ip;
    cout << "Inicializa Network" << endl;
    //Monta estrutra IPaddress
    if(SDLNet_ResolveHost(&ip,ipServidor,porta)==-1) {
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        exit(1);
    }

    //Inicia listener
    conexao = SDLNet_TCP_Open(&ip);
    if(!conexao) {
        printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        exit(2);
    }

    SDLNet_TCP_AddSocket(socketSet,conexao);
    
    cout << endl;
    cout << "Conectado no servidor " << ipServidor << " na porta " << porta << endl;

     lerComando();

    if (msg[0] == 'A'){
      cout << "Servidor solicitou para aguardar conexao do guest" << endl;
      cout << "Tecle algo para interromper" << endl;

      host = true;
      while(true){
        cout << backspace << animacao[loop] << flush;
        loop++;
        if(loop == 6){
          loop = 0;
        }
        int numReady = SDLNet_CheckSockets(socketSet, 0);
        if (numReady == -1) {
          cout << "Erro : " <<  SDLNet_GetError() << endl;
          // Finalizar
          SDLNet_TCP_Close(conexao);
          SDLNet_TCP_DelSocket(socketSet,conexao);
          exit(5);

        } else if(numReady) {
          lerComando();
          break;
        }

        // Ler teclado


        //Dar um tempo para CPU
        SDL_Delay(200);
      }

    }else if (msg[0] == 'C'){
      cout << "Servidor conectou-me como guest" << endl;
      host = false;
    }

  }

  bool Network::lerTCP(int tamanho, char* buffer){
    #if DEBUG
      cout << ">lerTCP tamanho("<<tamanho<<")"<<endl;
    #endif
    //Le o comando da mensagem
    int tamLido = SDLNet_TCP_Recv(conexao,buffer,tamanho);
    #if DEBUG
      cout << " lerTCP tamLido ("<<tamLido<<")"<<endl;
      cout << " lerTCP lido (";
      for (int i=0;i<tamLido;i++) {
        cout << buffer[i];
      }
      cout << ")" << endl;
    #endif

    if(tamLido < tamanho) {
      // An error may have occured, but sometimes you can just ignore it
      // It may be good to disconnect sock because it is likely invalid now.
      cout << "Erro na leitura: " << SDLNet_GetError() << endl;

      #if DEBUG
        cout << "<lerTCP return (false)"<<endl;
      #endif
      return false;
    }
    #if DEBUG
      cout << "<lerTCP return (true)"<<endl;
    #endif

    return true;  
  }

  bool Network::escreveTCP(int tamanho){

    #if DEBUG
      cout << ">escreveTCP tamanho("<<tamanho<<")"<<endl;
      cout << " escreveTCP msg (";
      for (int i=0;i<tamanho;i++) {
        cout << msg[i];
      }
      cout << ")" << endl;
    #endif
    int tamEscrito = SDLNet_TCP_Send(conexao,msg,tamanho);
    #if DEBUG
      cout << " escreveTCP tamEscrito (" << tamEscrito << ")" << endl;
    #endif
    if (tamEscrito < tamanho) {
      cout << "Erro na escrita: " << SDLNet_GetError() << endl;
      #if DEBUG
        cout << "<escreveTCP return (false)"<<endl;
      #endif
      return false;
    }
    #if DEBUG
      cout << "<escreveTCP return (true)"<<endl;
    #endif
    return true;
  }

   bool Network::escreveTCPString(string buffer){
      strcpy(msg,buffer.c_str());
      return escreveTCP(buffer.size());

  }  
  


  void Network::lerComando(){
    if (lerTCP(1, msg)){
      if(msg[0]=='F'){
        cout << "Servidor solicitou desconexao " << endl;
        SDLNet_TCP_Close(conexao);
        SDLNet_TCP_DelSocket(socketSet,conexao);
        exit(4);
      }
    } else {
      exit(3);
    }

  
  }

bool Network::enviaJogoInicial(int nacao, int nivel){

  cout << "Envia Jogo Inicial Nacao (" << nacao << ") Nivel (" << nivel << ")" << endl;


  stringstream sstm;
  sstm << "D0004P" << nacao << "N" << nivel;
  cout << "SSTM " << sstm.str() << endl;

  return escreveTCPString(sstm.str());

}

bool Network::recebeJogoInicial(int &nacao, int &nivel){

  cout << "Recebe Jogo Inicial ";
  lerComando();
  if (lerTCP(4,msg+1)) {
    int tamDados = 0;
    for (int i=1;i<5;i++) {
      tamDados = tamDados * 10 + (msg[i] - '0');
    }
    if (lerTCP(tamDados,msg+5)){
      if(msg[5] == 'P'){
        cout << "Nacao " << msg[6] << " NIvel : " << msg[8] << endl;
        nacao = msg[6] - '0';
        nivel = msg[8] - '0';
        return true;
      } 
    }
  }  
  return false;          

}
