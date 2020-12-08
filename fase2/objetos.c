// Modulo: implementacao dos objetos
// Descricao: esquematiza todos os objetos graficos, planejando e manipulando
//            suas representacoes internas.

#include <stdio.h>
#include <stdlib.h>
#ifndef OBJETOS
#define OBJETOS
#include "objetos.h"
#endif
#ifndef GRAFIC
#define GRAFIC
#include "grafic.h"
#endif

extern int cont_id;

// Funcao: apaga_no
// Entrada: o apontador inicial da lista de objetos, a identidade do objeto
//          procurado e a janela do qual sera apagado.
// Descricao: percorre a lista de objetos ate encontrar o objeto desejado ou
//            ate chegar ao final da mesma.

void apaga_no(WINDOW *janela, ap_objeto pri_objeto, int id_proc)
{
  ap_objeto ant_obj,
            atu_obj; 
  int qual_id;

  atu_obj = pri_objeto;
  
  qual_id = pri_objeto->id;
  
  while (qual_id != id_proc && atu_obj != NULL)
  {
    ant_obj = atu_obj;
    atu_obj = atu_obj->prox;
    qual_id = atu_obj->id;
  }
  if (atu_obj == pri_objeto)  // Primeiro no eh o procurado, avanca pri_objeto
    {
     pri_objeto = (pri_objeto)->prox;
     ant_obj = atu_obj;
    }
  if (atu_obj != NULL)         // Achou o no procurado
  {
    ant_obj->prox = atu_obj->prox;
    destroi_objeto(janela, atu_obj);
  }
}

// Funcao: cria_ponto
// Entrada: a posicao do ponto.
// Saida: um ponteiro para o ponto criado.
// Descricao: aloca memoria, adiciona na lista de objetos e inicializa os dados
//            do ponto recem criado.

ap_objeto cria_ponto(double Ox, double Oy, int cor)
{
  ap_objeto novo = (ap_objeto) malloc(sizeof(struct _OBJETO));

  novo->tipo  = PONTO;
  novo->Ox    = Ox;
  novo->Oy    = Oy;
  novo->id    = cont_id++;
  novo->cor   = cor;
  novo->descr = NULL;
  novo->prox  = NULL;
  return novo;
}

// Funcao: cria_reta
// Entrada: o "centro" e a direcao da reta.
// Saida: um ponteiro para a reta criada.
// Descricao: aloca memoria, adiciona na lista de objetos e inicializa os dados
//            da reta recem criada.

ap_objeto cria_reta(double Ox, double Oy, double theta, int cor)
{
  ap_objeto novo = (ap_objeto) malloc(sizeof(struct _OBJETO));
  ap_reta nova_reta = (ap_reta) malloc(sizeof(struct _RETA));

  novo->tipo       = RETA;
  novo->Ox         = Ox;
  novo->Oy         = Oy;
  novo->id         = cont_id++;
  novo->cor        = cor;
  novo->descr      = nova_reta;
  novo->prox       = NULL;
  nova_reta->theta = theta;
  return novo;
}

// Funcao: cria_arco
// Entrada: o centro, o raio e os angulos inicial e final do arco.
// Saida: um ponteiro para o arco criado.
// Descricao: aloca memoria, adiciona na lista de objetos e inicializa os dados
//            do arco recem criado.

ap_objeto cria_arco(double Ox, double Oy, double raio, double theta_inic,
                    double theta_fim, int cor)
{
  ap_objeto novo = (ap_objeto) malloc(sizeof(struct _OBJETO));
  ap_arco novo_arco = (ap_arco) malloc(sizeof(struct _ARCO));;

  novo->tipo            = ARCO;
  novo->Ox              = Ox;
  novo->Oy              = Oy;
  novo->id              = cont_id++;
  novo->cor             = cor;
  novo->descr           = novo_arco;
  novo->prox            = NULL;
  novo_arco->raio       = raio;
  novo_arco->theta_inic = theta_inic;
  novo_arco->theta_fim  = theta_fim;
  return novo;
}

// Funcao: cria_circulo
// Entrada: o centro e o raio do circulo.
// Saida: um ponteiro para o circulo criado.
// Descricao: aloca memoria, adiciona na lista de objetos e inicializa os dados
//            do circulo recem criado.

ap_objeto cria_circ(double Ox, double Oy, double raio, int cor)
{
  ap_objeto novo = (ap_objeto) malloc(sizeof(struct _OBJETO));
  ap_circ novo_circ = (ap_circ) malloc(sizeof(struct _CIRC));

  novo->tipo      = CIRC;
  novo->Ox        = Ox;
  novo->Oy        = Oy;
  novo->id        = cont_id++;
  novo->cor       = cor;
  novo->descr     = novo_circ;
  novo->prox      = NULL;
  novo_circ->raio = raio;
  return novo;
}

// Funcao: cria_poligono
// Entrada: uma lista circular de vertices do poligono.
// Saida: um ponteiro para o poligono criado.
// Descricao: aloca memoria, adiciona na lista de objetos e inicializa os dados
//            do poligono recem criado.

ap_objeto cria_poligono(ap_vertice pri_vertice, int cor)
{
  ap_objeto novo = (ap_objeto) malloc(sizeof(struct _OBJETO));
  ap_vertice atu = pri_vertice;
  double soma_x,
         soma_y;
  int qtos_vertices = 0;

  do        // Percorre a lista circular para achar o centro dos vertices
  {
    soma_x += atu->x;
    soma_y += atu->y;
    qtos_vertices++;
    atu = atu->prox;
  } while (atu != pri_vertice);

  novo->tipo  = POLIGONO;
  novo->Ox    = soma_x / qtos_vertices;
  novo->Oy    = soma_y / qtos_vertices;
  novo->id    = cont_id++;
  novo->cor   = cor;
  novo->descr = pri_vertice;
  novo->prox  = NULL;
  return novo;
}

// Funcao: cria_segmento
// Entrada: os pontos extremos do segmento.
// Saida: um ponteiro para o segmento criado.
// Descricao: aloca memoria, adiciona na lista de objetos e inicializa os dados
//            do segmento de reta recem criado.

ap_objeto cria_segmento(double x1, double y1, double x2, double y2, int cor)
{
  ap_objeto novo = (ap_objeto) malloc(sizeof(struct _OBJETO));
  ap_segmento novo_segmento = (ap_segmento) malloc(sizeof(struct _SEGMENTO));

  novo->tipo        = SEGMENTO;
  novo->Ox          = (x1 + x2) / 2;
  novo->Oy          = (y1 + y2) / 2;
  novo->id          = cont_id++;
  novo->cor         = cor;
  novo->descr       = novo_segmento;
  novo->prox        = NULL;
  novo_segmento->x1 = x1;
  novo_segmento->y1 = y1;
  novo_segmento->x2 = x2;
  novo_segmento->y2 = y2;
  return novo;
}

// Funcao: destroi_objeto
// Entrada: o tipo do objeto e a janela do qual sera destruido.
// Descricao: destroi o objeto, apagando-o da tela e liberando-o da memoria.

void destroi_objeto(WINDOW *janela, ap_objeto objeto)
{
  ap_vertice ant,
             atu;

  switch(objeto->tipo)
  {
    case PONTO: desenha_ponto(janela,objeto->Ox,objeto->Oy,0);
                break;
    case RETA: desenha_reta(janela,objeto->Ox,objeto->Oy,
                            ((ap_reta) objeto->descr)->theta,0);
               break;
    case ARCO: desenha_arco(janela,objeto->Ox,objeto->Oy,
                            ((ap_arco) objeto->descr)->raio,
                            ((ap_arco) objeto->descr)->theta_inic,
                            ((ap_arco) objeto->descr)->theta_fim,0);
               break;
    case CIRC: desenha_circ(janela,objeto->Ox,objeto->Oy,
                           ((ap_circ) objeto->descr)->raio,0);
               break;
    case POLIGONO: desenha_poligono(janela,objeto->descr,0);
                   break;
    case SEGMENTO: desenha_segmento(janela,((ap_segmento) objeto->descr)->x1,
                                    ((ap_segmento) objeto->descr)->y1,
                                    ((ap_segmento) objeto->descr)->x2,
                                    ((ap_segmento) objeto->descr)->y2,0);
                   break;
  }
  
  if (objeto->tipo == POLIGONO)
  {
    ant = objeto->descr;
    while (ant != NULL)        // Apaga a lista circular de vertices
    {
      atu = ant->prox;
      ant->prox = atu->prox;
      if (atu == ant)          // So sobrou um vertice
        ant = NULL;
      free(atu);
    }
  }
  if (objeto->tipo != PONTO)
    free(objeto->descr);
  free(objeto);
}
