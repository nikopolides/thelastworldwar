#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_net.h"
#define MAXLEN 10240

using namespace std;
class Network
{
  public:
    char *ipServidor;
    short porta;
    char backspace;

    //Flag de atuação...
    bool host;
    char msg[MAXLEN],animacao[6];
    int loop;

    TCPsocket conexao;
    SDLNet_SocketSet socketSet;

  Network();
  void initializeNetwork();
  void lerComando();
  bool lerTCP(int, char*);
  bool escreveTCP(int);
  bool escreveTCPString(string);

  bool enviaJogoInicial(int, int);
  bool recebeJogoInicial(int&, int&);

};
#endif