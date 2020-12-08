#ifndef XWC
#define XWC
#include "xwc.h"
#endif
#ifndef OBJETOS
#define OBJETOS
#include "objetos.h"
#endif

#define TAM_X_TELA 300
#define TAM_Y_TELA 300
#define TAM_X_REAL 30
#define TAM_Y_REAL 30
#define PI 3.1415927

int ajuste_x(double x);
int ajuste_y(double y);
int ajuste_raio(double raio);
void desenha_ponto(WINDOW *janela, double x, double y, int cor);
void desenha_reta(WINDOW *janela, double x, double y, double raio, int cor);
void desenha_arco(WINDOW *janela, double x, double y, double raio,
                  double theta_inic, double theta_fim, int cor);
void desenha_circ(WINDOW *janela, double x, double y, double raio, int cor);
void desenha_poligono(WINDOW *janela, ap_vertice vertices, int cor);
void desenha_segmento(WINDOW *janela, double x1, double y1, double x2,
                      double y2, int cor);
void move_ponto(WINDOW *janela, ap_objeto ponto, double novo_Ox,
                double novo_Oy);
void move_reta(WINDOW *janela, ap_objeto reta, double novo_Ox, double novo_Oy);
void move_arco(WINDOW *janela, ap_objeto arco, double novo_Ox, double novo_Oy);
void move_circ(WINDOW *janela, ap_objeto circ, double novo_Ox, double novo_Oy);
void move_poligono(WINDOW *janela, ap_objeto polig, double novo_Ox,
                   double novo_Oy);
void move_segmento(WINDOW * janela, ap_objeto seg, double novo_Ox, 
                   double novo_Oy);
