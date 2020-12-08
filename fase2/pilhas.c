// Modulo: implementacao das pilhas
// Descricao: define e implementa as operacoes de manipulacao das pilhas de da-
//            dos e de enderecos do programa.

#ifndef PILHAS
#define PILHAS
#include "pilhas.h"
#endif

extern Tdado p_dados[100];
extern int p_enderecos[100],
           topo_p_dad,
           topo_p_end;

// Funcao: empilha_dad
// Entrada: o dado a ser empilhado.
// Saida: o dado que foi empilhado, se a pilha nao estiver cheia; um codigo de
//        erro, caso contrario.
// Descricao: coloca um dado no topo da pilha.

Tdado empilha_dad(Tdado dado)
{
  if (!cheia_dad())
    p_dados[++topo_p_dad] = dado;
  else
    dado.tipo = ERRO;
  return dado;
}

// Funcao: desempilha_dad
// Saida: o dado que estava no topo da pilha, se a mesma nao esta vazia; um co-
//        digo de erro, caso contrario.
// Descricao: retira um dado do topo da pilha.

Tdado desempilha_dad(void)
{
  Tdado dado;

  if (!vazia_dad())
    dado = p_dados[topo_p_dad--];
  else
    dado.tipo = ERRO;
  return dado;
}

// Funcao: topo_dad
// Saida: o dado que esta no topo da pilha, se a mesma nao esta vazia; um codi-
//        go de erro, caso contrario.
// Descricao: devolve o dado do topo da pilha, sem, porem, retira-lo da mesma.

Tdado topo_dad(void)
{
  Tdado dado;

  if (!vazia_dad())  
    dado = p_dados[topo_p_dad];
  else
    dado.tipo = ERRO;
  return dado;
}

// Funcao: limpa_dad
// Descricao: esvazia a pilha.

void limpa_dad(void)
{
  topo_p_dad = -1;
}

// Funcao: cheia_dad
// Saida: 1 se a pilha esta cheia; 0 caso contrario.
// Descricao: verifica se a pilha esta cheia.

int cheia_dad(void)
{
  if (topo_p_dad >= 99)
    return 1;
  else
    return 0;
}

// Funcao: vazia_dad
// Saida: 1 se a pilha esta vazia; 0 caso contrario.
// Descricao: verifica se a pilha esta vazia.

int vazia_dad(void)
{
  if (topo_p_dad <= -1)
    return 1;
  else
    return 0;
}

// Funcao: empilha_end
// Entrada: o endereco a ser empilhado.
// Saida: o endereco que foi empilhado.
// Descricao: coloca um endereco no topo da pilha.

int empilha_end(int endereco)
{
  if (!cheia_end())
  {
    p_enderecos[++topo_p_end] = endereco;
    return endereco;
  }
  else
    return ERRO;
}

// Funcao: desempilha_end
// Saida: o endereco que estava no topo da pilha.
// Descricao: retira um endereco do topo da pilha.

int desempilha_end(void)
{
  if (!vazia_end())
    return p_enderecos[topo_p_end--];
  else
    return ERRO;
}

// Funcao: topo_end
// Saida: o endereco que esta no topo da pilha.
// Descricao: devolve o endereco do topo da pilha, sem, porem, retira-lo da
//            mesma.

int topo_end(void)
{
  if (!vazia_end())  
    return p_enderecos[topo_p_end];
  else
    return ERRO;
}

// Funcao: limpa_end
// Descricao: esvazia a pilha.

void limpa_end(void)
{
  topo_p_end = -1;
}

// Funcao: cheia_end
// Saida: 1 se a pilha esta cheia; 0 caso contrario.
// Descricao: verifica se a pilha esta cheia.

int cheia_end(void)
{
  if (topo_p_end >= 99)
    return 1;
  else
    return 0;
}

// Funcao: vazia_end
// Saida: 1 se a pilha esta vazia; 0 caso contrario.
// Descricao: verifica se a pilha esta vazia.

int vazia_end(void)
{
  if (topo_p_end <= -1)
    return 1;
  else
    return 0;
}
