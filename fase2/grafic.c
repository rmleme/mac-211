// Modulo: parte grafica
// Descricao: implementa as rotinas da parte grafica do objeto, usando as
//            funcoes da biblioteca xwc para manipular os objetos graficos na
//            janela.

#include <stdio.h>
#include <math.h>
#ifndef GRAFIC
#define GRAFIC
#include "grafic.h"
#endif

// Funcao: ajuste_x
// Entrada: coordenadas reais x a serem convertidas para coordenadas da janela.
// Descricao: converte coordenadas reais x em coordenadas da janela.

int ajuste_x(double x)
{
  return (int) (x + TAM_X_REAL / 2) * TAM_X_TELA / TAM_X_REAL;
}

// Funcao: ajuste_y
// Entrada: coordenadas reais y a serem convertidas para coordenadas da janela.
// Descricao: converte coordenadas reais y em coordenadas da janela.

int ajuste_y(double y)
{
  return (int) abs(y - TAM_Y_REAL / 2) * TAM_Y_TELA / TAM_Y_REAL;
}

// Funcao: ajuste_raio
// Entrada: coordenadas reais a serem convertidas para coordenadas da janela.
// Descricao: converte coordenadas reais em coordenadas da janela.

int ajuste_raio(double raio)
{
  return (int) raio * TAM_X_TELA / TAM_X_REAL;
}

// Funcao: desenha_ponto
// Entrada: a posicao do ponto.
// Descricao: apresenta um ponto na janela.

void desenha_ponto(WINDOW *janela, double x, double y, int cor)
{
  WPlot (janela, ajuste_x(x), ajuste_y(y), cor);
}

// Funcao: desenha_reta
// Entrada: o "centro" e a direcao da reta.
// Descricao: apresenta uma reta na janela, seguindo a equacao y - y0 = a (x -
//            x0), onde a = tan(theta)

void desenha_reta(WINDOW *janela, double x, double y, double theta, int cor)
{
  int y_aux, p1_x, p1_y, p2_x, p2_y;
  
  if ((int) theta % 180 == 90) 
    WLine(janela, ajuste_x(0), ajuste_y(TAM_Y_REAL / 2), ajuste_x(0),
          ajuste_y(-TAM_Y_REAL / 2), cor);
  else
  {
    if(tan(PI * theta / 180) > 0)   // Coeficiente angular da reta e positivo
    {
      y_aux = ((tan(PI * theta / 180)) * (TAM_X_REAL / 2 - x) + y);
      if (y > TAM_Y_REAL / 2)       // Corta a janela no extremo superior
      {
        p1_x = (TAM_Y_REAL / 2 - y) / (tan(PI * theta / 180)) + x;
        p1_y = TAM_Y_REAL / 2;
      }
      else       // Corta a janela na extrema direita
      {
        p1_x = TAM_X_REAL / 2;
        p1_y = (tan(PI * theta / 180)) * (TAM_X_REAL / 2 - x) + y;
      }
      y_aux = ((tan(PI * theta / 180)) * (-TAM_X_REAL / 2 - x) + y);
      if (y < -TAM_Y_REAL / 2)      // Corta a janela no extremo inferior
      {
        p2_x = (-TAM_Y_REAL / 2 - y) / (tan(PI * theta / 180)) + x;
        p2_y = -TAM_Y_REAL / 2;
      }
      else       // Corta a janela na extrema esquerda
      {
        p2_x = -TAM_X_REAL / 2;
        p2_y = (tan(PI * theta / 180)) * (-TAM_X_REAL / 2 - x) + y;
      }
      WLine(janela, ajuste_x(p1_x), ajuste_y(p1_y), ajuste_x(p2_x),
            ajuste_y(p2_y), cor);
    }
    else         // Coeficiente angular da reta e negativo
    {
      y_aux = ((tan(PI * theta / 180)) * (TAM_X_REAL / 2 - x) + y);
      if (y > -TAM_Y_REAL / 2)      // Corta a janela na extremo direita
      {
        p1_x = TAM_X_REAL / 2;
        p1_y = (tan(PI * theta / 180)) * (TAM_X_REAL / 2 - x) + y;
      }
      else       // Corta a janela no extremo inferior
      {
        p1_x = (-TAM_Y_REAL / 2 - y) / (tan(PI * theta / 180)) + x;
        p1_y = -TAM_Y_REAL / 2;
      }
      y_aux = ((tan(PI * theta / 180)) * (-TAM_X_REAL / 2 - x) + y);
      if (y > TAM_Y_REAL / 2)       // Corta a janela no extremo superior
      {
        p2_x = (TAM_Y_REAL / 2 - y) / (tan(PI * theta / 180)) + x;
        p2_y = TAM_Y_REAL / 2;
      }
      else       // Corta a janela na extremo esquerdo
      {
        p2_x = -TAM_X_REAL / 2;
        p2_y = (tan(PI * theta / 180)) * (-TAM_X_REAL / 2 - x) + y;
      }
      WLine(janela, ajuste_x(p1_x), ajuste_y(p1_y), ajuste_x(p2_x),
            ajuste_y(p2_y), cor);
    }
  }
}

// Funcao: desenha_arco
// Entrada: o centro, o raio e os angulos inicial e final do arco.
// Descricao: apresenta um arco na janela.

void desenha_arco(WINDOW *janela, double x, double y, double raio,
                  double theta_inic, double theta_fim, int cor)
{
  WArc(janela, ajuste_x(x - raio), ajuste_y(y + raio), theta_inic*64,
       (theta_fim - theta_inic)*64, ajuste_raio(2 * raio),
       ajuste_raio(2 * raio), cor);
}

// Funcao: desenha_circ
// Entrada: o centro e o raio do circulo.
// Descricao: apresenta um circulo na janela, com a mesma chamando a mesma fun-
//            cao de desenha_arco, com angulo inicial = 0 e angulo final = 360.

void desenha_circ(WINDOW *janela, double x, double y, double raio, int cor)
{
  WArc(janela, ajuste_x(x - raio), ajuste_y(y + raio), 0, 360*64,
       ajuste_raio(2 * raio), ajuste_raio(2 * raio), cor);
}

// Funcao: desenha_poligono
// Entrada: uma lista circular de vertices do poligono.
// Descricao: apresenta um poligono na janela.

void desenha_poligono(WINDOW *janela, ap_vertice vertices, int cor)
{
  ap_vertice inicio = vertices, fim = vertices->prox;

  // desenha uma reta entre dois dos vertices do poligono, atualizando os 
  // vertices logo em seguida.
  do
    {
      WLine(janela, ajuste_x(inicio->x), ajuste_y(inicio->y), ajuste_x(fim->x),
            ajuste_y(fim->y), cor);
      inicio = fim;
      fim = fim->prox;
    }
  while(fim != vertices->prox);
}

// Funcao: desenha_segmento
// Entrada: os pontos extremos do segmento.
// Descricao: apresenta um segmento de reta na janela.

void desenha_segmento(WINDOW *janela, double x1, double y1, double x2,
                      double y2, int cor)
{
  WLine(janela, ajuste_x(x1), ajuste_y(y1), ajuste_x(x2), ajuste_y(y2), cor);
}

// Funcao: move_ponto
// Entrada: as novas coordenadas do centro do ponto.
// Descricao: desenha um ponto no mesmo lugar do ponto a ser movido com a cor
//            da janela (simulando um apagamento). Isso e feito em todas as
//            funcoes move_xxxxx

void move_ponto(WINDOW *janela, ap_objeto ponto, double novo_Ox,
                double novo_Oy)
{
  desenha_ponto(janela, ponto->Ox, ponto->Oy, 0);
  ponto->Ox = novo_Ox;
  ponto->Oy = novo_Oy;
  desenha_ponto(janela, ponto->Ox, ponto->Oy, ponto->cor);
}

// Funcao: move_reta
// Entrada: as novas coordenadas do "centro" da reta.
// Descricao: translada a reta.

void move_reta(WINDOW *janela, ap_objeto reta, double novo_Ox, double novo_Oy)
{

  
  desenha_reta(janela, reta->Ox, reta->Oy, ((ap_reta) reta->descr)->theta, 0);
  reta->Ox = novo_Ox;
  reta->Oy = novo_Oy;
  desenha_reta(janela, reta->Ox, reta->Oy, ((ap_reta) reta->descr)->theta, reta->cor);
}

// Funcao: move_arco
// Entrada: as novas coordenadas do centro do arco.
// Descricao: translada o arco.

void move_arco(WINDOW *janela, ap_objeto arco, double novo_Ox, double novo_Oy)
{
  desenha_arco(janela, arco->Ox, arco->Oy, ((ap_arco) arco->descr)->raio,
               ((ap_arco) arco->descr)->theta_inic,
               ((ap_arco) arco->descr)->theta_fim, 0);
  arco->Ox = novo_Ox;
  arco->Oy = novo_Oy;
  desenha_arco(janela, arco->Ox, arco->Oy, ((ap_arco) arco->descr)->raio,
               ((ap_arco) arco->descr)->theta_inic,
               ((ap_arco) arco->descr)->theta_fim, arco->cor);
}

// Funcao: move_circ
// Entrada: as novas coordenadas do centro do circulo.
// Descricao: translada o circulo.

void move_circ(WINDOW *janela, ap_objeto circ, double novo_Ox, double novo_Oy)
{
  desenha_arco(janela, circ->Ox, circ->Oy, ((ap_arco) circ->descr)->raio, 0,
               360, 0);
  circ->Ox = novo_Ox;
  circ->Oy = novo_Oy;
  desenha_arco(janela, circ->Ox, circ->Oy, ((ap_arco) circ->descr)->raio, 0,
               360, circ->cor);
}

// Funcao: move_poligono
// Entrada: as novas coordenadas do centro do poligono.
// Descricao: translada o poligono.

void move_poligono(WINDOW *janela, ap_objeto polig, double novo_Ox,
                   double novo_Oy)
{
  double move_x = fabs(polig->Ox - novo_Ox), 
         move_y = fabs(polig->Oy - novo_Oy);
  
  ap_vertice adiciona = polig->descr;

  if (novo_Ox < 0) move_x = -move_x;
  if (novo_Oy < 0) move_y = -move_y;

  desenha_poligono(janela, polig->descr, 0);
  do       // Atualiza a posicao dos vertices
  {
    adiciona->x += move_x;
    adiciona->y += move_y;
    adiciona = adiciona->prox;
  } while (adiciona != polig->descr);
  polig->Ox = novo_Ox;
  polig->Oy = novo_Oy;
  desenha_poligono(janela, polig->descr, polig->cor);
}

// Funcao: move_segmento
// Entrada: as novas coordenadas do centro do segmento.
// Descricao: translada o segmento.

void move_segmento(WINDOW * janela, ap_objeto seg, double novo_Ox, 
                   double novo_Oy)
{
  double move_Ox = fabs (seg->Ox - novo_Ox),
         move_Oy = fabs (seg->Oy - novo_Oy);

  if (novo_Ox < 0) move_Ox = -move_Ox;
  if (novo_Oy < 0) move_Oy = -move_Oy;

  desenha_segmento(janela, ((ap_segmento) seg->descr)->x1,
                   ((ap_segmento) seg->descr)->y1,
                   ((ap_segmento) seg->descr)->x2,
                   ((ap_segmento) seg->descr)->y2, 0);
  seg->Ox = novo_Ox;
  seg->Oy = novo_Oy;
  ((ap_segmento) seg->descr)->x1 += move_Ox;
  ((ap_segmento) seg->descr)->y1 += move_Oy;
  ((ap_segmento) seg->descr)->x2 += move_Ox;
  ((ap_segmento) seg->descr)->y2 += move_Oy;
  desenha_segmento(janela, ((ap_segmento) seg->descr)->x1,
                   ((ap_segmento) seg->descr)->y1,
                   ((ap_segmento) seg->descr)->x2,
                   ((ap_segmento) seg->descr)->y2, seg->cor);
}
