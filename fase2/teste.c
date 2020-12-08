// Programa: definicao da "linguagem de maquina" do interpretador
// Autores: Paulo Marcel Caldeira Yokosawa         Numero USP: 3095430
//          Rodrigo Mendes Leme                    Numero USP: 3151151
// Curso: computacao                  Data: 6/07/2000
// Professor: Marco Gubitoso
// Descricao: executa testes de controle das rotinas da linguagem de maquina do
//             interpretador da maquina virtual.

#include <stdio.h>
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
#include <stdio.h>
#ifndef PILHAS
#define PILHAS
#include "pilhas.h"
#endif
#ifndef INSTRUC
#define INSTRUC
#include "instruc.h"
#endif
#ifndef INTERP
#define INTERP
#include "interp.h"
#endif

extern Tinstrucao v_instrucoes[100];

// Funcao: main
// Descricao: executa testes de controle das rotinas de baixo nivel do inter-
//            pretador da maquina virtual.

void main (void)
{
  int i = 0;

  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 1;      // Para que o IF de verdadeiro
  v_instrucoes[i].op = JUMP;
  v_instrucoes[i++].imediato.ival = 5;
  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 1; 
  v_instrucoes[i].op = PUSH_pos;
  v_instrucoes[i++].imediato.posicval = 6;
  v_instrucoes[i++].op = RETURN;
  v_instrucoes[i].op = IF;
  v_instrucoes[i++].imediato.ival = 2;
  v_instrucoes[i].op = CALL;
  v_instrucoes[i++].imediato.ival = 8;
  v_instrucoes[i].op = JUMP;
  v_instrucoes[i++].imediato.ival = 9;
  v_instrucoes[i++].op = RETURN;
  strcpy(v_instrucoes[i].imediato.strval,"Topo da pilha de dados: ");
  v_instrucoes[i++].op = PUSH_str;
  v_instrucoes[i++].op = PRINT;
  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 211;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i].op = PUSH_i;              // Coloca os parametros do arco
  v_instrucoes[i++].imediato.ival = 255;    // Cor
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 60;     // Inclinacao final
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 10;     // Inclinacao inicial
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 7;      // Raio
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 0;      // y
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 0;      // x
  v_instrucoes[i++].op = CRIA_ARCO;
  v_instrucoes[i++].op = DESENHA_ARCO;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 6;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -10;
  v_instrucoes[i++].op = MOVE_ARCO;
  v_instrucoes[i++].op = DESTROI_OBJETO;
  v_instrucoes[i++].op = CRIA_JANELA;

  v_instrucoes[i].op = PUSH_i;              // Coloca os parametros do circulo
  v_instrucoes[i++].imediato.ival = 255;    // Cor
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 3;      // Raio
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 0;      // y
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 0;      // x
  v_instrucoes[i++].op = CRIA_CIRC;
  v_instrucoes[i++].op = DESENHA_CIRC;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 11;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -7;
  v_instrucoes[i++].op = MOVE_CIRC;
  v_instrucoes[i++].op = DESTROI_OBJETO;

  v_instrucoes[i].op = PUSH_i;              // Coloca os parametros do segmento
  v_instrucoes[i++].imediato.ival = 255;    // Cor
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 4;      // y final
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 2;      // x final
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -3;     // y inicial
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -3;     // x inicial
  v_instrucoes[i++].op = CRIA_SEGMENTO;
  v_instrucoes[i++].op = DESENHA_SEGMENTO;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -7;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -2;
  v_instrucoes[i++].op = MOVE_SEGMENTO;
  v_instrucoes[i++].op = DESTROI_OBJETO;

  v_instrucoes[i].op = PUSH_i;              // Coloca os parametros do poligono
  v_instrucoes[i++].imediato.ival = 255;    // Cor
  v_instrucoes[i++].op = PUSH_marc;         // Marcador (fim dos pontos)
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 1;      // Pontos do poligono
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 6;  
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 14;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 3; 
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 4; 
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = 11;
  v_instrucoes[i++].op = CRIA_POLIGONO;
  v_instrucoes[i++].op = DESENHA_POLIGONO;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -2;
  v_instrucoes[i].op = PUSH_d;
  v_instrucoes[i++].imediato.dval = -9;
  v_instrucoes[i++].op = MOVE_POLIGONO;
  v_instrucoes[i++].op = DESTROI_OBJETO;

  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 10;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 5;
  v_instrucoes[i++].op = PRINT;
  v_instrucoes[i++].op = ADD;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 5;
  v_instrucoes[i++].op = PRINT;
  v_instrucoes[i++].op = SUB;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 5;
  v_instrucoes[i++].op = PRINT;
  v_instrucoes[i++].op = MUL;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = -500;
  v_instrucoes[i++].op = PRINT;
  v_instrucoes[i++].op = DIV;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i].op = PUSH_i;
  v_instrucoes[i++].imediato.ival = 22;
  v_instrucoes[i++].op = PRINT;
  v_instrucoes[i++].op = SWAP;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i++].op = DROP;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i++].op = DUP;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i].op = STORE;
  v_instrucoes[i++].imediato.ival = 10;
  v_instrucoes[i].op = RESTORE;
  v_instrucoes[i++].imediato.ival = 10;
  v_instrucoes[i++].op = PRINT;

  v_instrucoes[i++].op = END;

  interpreta();
}
