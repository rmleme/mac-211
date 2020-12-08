// Programa: manipulacao de objetos geometricos (modulo de testes).
// Autores: Paulo Marcel Caldeira Yokosawa         Numero USP: 3095430
//          Rodrigo Mendes Leme                    Numero USP: 3151151
// Curso: computacao                  Data: 7/04/2000
// Professor: Marco Gubitoso
// Descricao: executa testes de controle das rotinas graficas e dos objetos.

#include <stdio.h>
#include <stdlib.h>
#ifndef XWC
#define XWC
#include "xwc.h"
#endif
#ifndef OBJETOS
#define OBJETOS
#include "objetos.h"
#endif
#ifndef GRAFIC
#define GRAFIC
#include "grafic.h"
#endif

int cont_id = 0;      // Controla a identificacao de cada objeto criado

// Funcao: main
// Descricao: inicializa a janela grafica e executa testes com os objetos
//            graficos.

void main(void)
{
  WINDOW *janela;
  int tipo,
      modo = 0,
      cor  = 0xFFFFFF;
  ap_vertice vertice1,
             vertice2,
             vertice3,
             vertice4;
  ap_objeto pri_objeto = NULL,
            atu_objeto = NULL,
            aux_objeto;

  janela = InitGraph(TAM_X_TELA,TAM_Y_TELA,"Manipulador de objetos graficos");
  WShow(janela);

  // Desenha os eixos cartesianos.
  desenha_segmento(janela,-TAM_X_REAL / 2,0,TAM_X_REAL / 2,0,0x00FF00);
  desenha_segmento(janela,0,-TAM_Y_REAL / 2,0,TAM_Y_REAL / 2,0x00FF00);
 
  // O "for" externo cobre as 4 funcoes (criar, desenhar, mover e destruir). O
  // "for" interno cobre os 6 tipos de objeto. Dessa forma todas as combinacoes
  // entre funcoes e objetos serao realizadas, e cada objeto sera criado,
  // desenhado, movido e destruido, respectivamente.

  for(modo = 0; modo <= 3; modo++){
    for(tipo = PONTO; tipo <= SEGMENTO; tipo++){
      switch(tipo){
        case 0:
	  switch(modo){
	    case 0:
	      pri_objeto = cria_ponto(-11, -11, cor);
	      atu_objeto = pri_objeto;
	      break;
	    case 1:
	      desenha_ponto(janela, atu_objeto->Ox, atu_objeto->Oy,
                            atu_objeto->cor);
              atu_objeto = atu_objeto->prox;
	      break;
	    case 2:
	      move_ponto(janela, atu_objeto, -10, 13);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 3:
              aux_objeto = atu_objeto->prox;
              apaga_no(janela, &pri_objeto, atu_objeto->id);
              atu_objeto = aux_objeto;
              break;
	  }
	  break;
        case 1:
	  switch(modo){
	    case 0:
	      atu_objeto->prox = cria_reta(0, 0, 45, cor);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 1:
	      desenha_reta(janela, atu_objeto->Ox, atu_objeto->Oy,
	                   ((ap_reta) atu_objeto->descr)->theta,
	                   atu_objeto->cor);
              atu_objeto = atu_objeto->prox;
	      break;
	    case 2:
	      move_reta(janela, atu_objeto, -20, -1);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 3:
              aux_objeto = atu_objeto->prox;
              apaga_no(janela, &pri_objeto, atu_objeto->id);
              atu_objeto = aux_objeto;
              break;
	  }
	  break;
	case 2:
	  switch(modo){
	    case 0:
	      atu_objeto->prox = cria_arco(-10, -10, 5, 30, 60, cor);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 1:
	      desenha_arco(janela, atu_objeto->Ox, atu_objeto->Oy,
                          ((ap_arco) atu_objeto->descr)->raio,
                          ((ap_arco) atu_objeto->descr)->theta_inic,
                          ((ap_arco) atu_objeto->descr)->theta_fim,
                          atu_objeto->cor);
              atu_objeto = atu_objeto->prox;
	      break;
	    case 2:
	      move_arco(janela, atu_objeto, 8, -13);
	      atu_objeto = atu_objeto->prox;
	      break;
            case 3:
              aux_objeto = atu_objeto->prox;
              apaga_no(janela, &pri_objeto, atu_objeto->id);
              atu_objeto = aux_objeto;
              break;
	  }
	  break;
        case 3:
	  switch(modo){
	    case 0:
	      atu_objeto->prox = cria_circ(0, 0, 5, cor);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 1:
	      desenha_circ(janela, atu_objeto->Ox, atu_objeto->Oy,
                          ((ap_circ) atu_objeto->descr)->raio,atu_objeto->cor);
              atu_objeto = atu_objeto->prox;
	      break;
	    case 2:
	      move_circ(janela, atu_objeto, -7, -7);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 3:
              aux_objeto = atu_objeto->prox;
              apaga_no(janela, &pri_objeto, atu_objeto->id);
              atu_objeto = aux_objeto;
              break;
	  }
	  break;
        case 4:
	  switch(modo){
	  case 0:
              vertice1       = (ap_vertice) malloc(sizeof(struct _VERTICE));
              vertice2       = (ap_vertice) malloc(sizeof(struct _VERTICE));
              vertice3       = (ap_vertice) malloc(sizeof(struct _VERTICE));
              vertice4       = (ap_vertice) malloc(sizeof(struct _VERTICE));
              vertice1->x    = 3;
              vertice1->y    = 2;
              vertice1->prox = vertice2;
              vertice2->x    = 11;
              vertice2->y    = 10;
              vertice2->prox = vertice3;
              vertice3->x    = 12;
              vertice3->y    = -5;
              vertice3->prox = vertice4;
              vertice4->x    = -7;
              vertice4->y    = -13;
              vertice4->prox = vertice1;
	      atu_objeto->prox = cria_poligono(vertice1, cor);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 1:
	      desenha_poligono(janela, atu_objeto->descr, atu_objeto->cor);
              atu_objeto = atu_objeto->prox;
	      break;
	    case 2:
              move_poligono(janela, atu_objeto, 0, 0);
	      atu_objeto = atu_objeto->prox;
	      break;
            case 3:
              aux_objeto = atu_objeto->prox;
              apaga_no(janela, &pri_objeto, atu_objeto->id);
              atu_objeto = aux_objeto;
              break;
	  }
	  break;
        case 5:
	  switch(modo){
	    case 0:
	      atu_objeto->prox = cria_segmento(-10, 5, -5, 10, cor);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 1:
	      desenha_segmento(janela, ((ap_segmento) atu_objeto->descr)->x1,
                               ((ap_segmento) atu_objeto->descr)->y1,
                               ((ap_segmento) atu_objeto->descr)->x2,
                               ((ap_segmento) atu_objeto->descr)->y2,
                               atu_objeto->cor);
              atu_objeto = atu_objeto->prox;
	      break;
	    case 2:
	      move_segmento(janela, atu_objeto, 0, 0);
	      atu_objeto = atu_objeto->prox;
	      break;
	    case 3:
              aux_objeto = atu_objeto->prox;
              apaga_no(janela, &pri_objeto, atu_objeto->id);
              atu_objeto = aux_objeto;
              break;
	  }
	  break;
      }
    }
    atu_objeto = pri_objeto;
    getchar();
  }
  CloseGraph();
}
