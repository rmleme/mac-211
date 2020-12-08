#ifndef XWC
#define XWC
#include "xwc.h"
#endif

typedef enum {PONTO,RETA,ARCO,CIRC,POLIGONO,SEGMENTO} TIPO_OBJ;

typedef struct _OBJETO * ap_objeto;

struct _OBJETO
{
  TIPO_OBJ tipo;
  double Ox,
         Oy;
  int id,
      cor;
  void *descr;
  ap_objeto prox;
};

typedef struct _RETA * ap_reta;

struct _RETA
{
  double theta;
};

typedef struct _ARCO * ap_arco;

struct _ARCO
{
  double raio,
         theta_inic,
         theta_fim;
};

typedef struct _CIRC * ap_circ;

struct _CIRC
{
  double raio;
};

typedef struct _VERTICE * ap_vertice;

struct _VERTICE
{
  double x,
         y;
  ap_vertice prox;
};

typedef struct _SEGMENTO * ap_segmento;

struct _SEGMENTO
{
  double x1,
         y1,
         x2,
         y2;
};

void apaga_no(WINDOW *janela, ap_objeto *pri_objeto, int id_proc);
ap_objeto cria_ponto(double Ox, double Oy, int cor);
ap_objeto cria_reta(double Ox, double Oy, double theta, int cor);
ap_objeto cria_arco(double Ox, double Oy, double raio, double theta_inic,
                    double theta_fim, int cor);
ap_objeto cria_circ(double Ox, double Oy, double raio, int cor);
ap_objeto cria_poligono(ap_vertice pri_vertice, int cor);
ap_objeto cria_segmento(double x1, double y1, double x2, double y2, int cor);
void destroi_objeto(WINDOW *janela, ap_objeto objeto);
