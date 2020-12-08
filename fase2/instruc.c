// Modulo: controle de instrucoes
// Descricao: define e executa cada instrucao existente na linguagem.

#include <stdio.h>
#include <stdlib.h>
#ifndef PILHAS
#define PILHAS
#include "pilhas.h"
#endif
#ifndef INSTRUC
#define INSTRUC
#include "instruc.h"
#endif
#ifndef GRAFIC
#define GRAFIC
#include "grafic.h"
#endif
#ifndef OBJETOS
#define OBJETOS
#include "objetos.h"
#endif

extern Tdado memoria[100];
extern Tdado janela_default;
extern int leitor_instrucoes;

// Funcao: push_i
// Entrada: o valor inteiro a ser empilhado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha o valor do campo "imediato" (inteiro).

int push_i(int imediato)
{
  Tdado dado;
  
  dado.tipo       = INTEIRO;
  dado.valor.ival = imediato;
  if (empilha_dad(dado).tipo != ERRO)
    return -1;
  else
    return ESTOURO_PILHA;
}

// Funcao: push_d
// Entrada: o valor real a ser empilhado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha o valor do campo "imediato" (double).

int push_d(double imediato)
{
  Tdado dado;

  dado.tipo       = REAL;
  dado.valor.dval = imediato;
  if (empilha_dad(dado).tipo != ERRO)
    return -1;
  else
    return ESTOURO_PILHA;
}

// Funcao: push_obj
// Entrada: o objeto grafico a ser empilhado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha o valor do campo "imediato" (objeto).

int push_obj(void *imediato)
{
  Tdado dado;

  dado.tipo         = OBJETO;
  dado.valor.objval = imediato;
  if (empilha_dad(dado).tipo != ERRO)
    return -1;
  else
    return ESTOURO_PILHA;
}

// Funcao: push_str
// Entrada: o valor string a ser empilhado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha o valor do campo "imediato" (string).

int push_str(char *imediato)
{
  Tdado dado;

  dado.tipo = STRING;
  strcpy(dado.valor.strval,imediato);
  if (empilha_dad(dado).tipo != ERRO)
    return -1;
  else
    return ESTOURO_PILHA;
}

// Funcao: push_pos
// Entrada: o endereco a ser empilhado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha o valor do campo "imediato" (posicao).

int push_pos(int imediato)
{
 
  
  if (empilha_end(imediato) != ERRO)
    return -1;
  else
    return ESTOURO_PILHA;
}

// Funcao: push_marc
// Entrada: o marcador a ser empilhado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha o valor do campo "imediato" (marcador).

int push_marc(char imediato)
{
  Tdado dado;

  dado.tipo          = MARCADOR;
  dado.valor.marcval = imediato;
  if (empilha_dad(dado).tipo != ERRO)
    return -1;
  else
    return ESTOURO_PILHA;
}

// Funcao: drop
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: descarta o topo da pilha.

int drop(void)
{
  if (desempilha_dad().tipo != ERRO)
    return -1;
  else
    return ESVAZIAMENTO_PILHA;
}

// Funcao: store
// Entrada: o indice da memoria onde o topo da pilha sera guardado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: armazena o topo da pilha na variavel indicada pelo campo "imedia-
//            to".

int store(int imediato) 
{
  Tdado dado;

  if (imediato < 0 || imediato > 99)     // Tentou indexar uma posicao invalida
    return FORA_DOS_LIMITES;             // da memoria
  else
  {
    dado = topo_dad();
    if (dado.tipo != ERRO)
    {
      memoria[imediato] = dado;
      return -1;
    }
    else
      return ESVAZIAMENTO_PILHA;
  }
}

// Funcao: restore
// Entrada: o indice da memoria cujo elemento sera empilhado.
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha o valor de uma variavel (onde o campo "imediato" indica o
//            indice da variavel na memoria).

int restore(int imediato)
{
  if (imediato < 0 || imediato > 99)     // Tentou indexar uma posicao invalida
    return FORA_DOS_LIMITES;             // da memoria
  else
  {
    if (empilha_dad(memoria[imediato]).tipo != ERRO)
      return -1;
    else
      return ESTOURO_PILHA;
  }
}

// Funcao: add
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: soma os elementos no topo da pilha.

int add(void)
{
  Tdado dado_a,
        dado_b,
        soma;

  dado_a = desempilha_dad();
  if (dado_a.tipo != ERRO)
  {
    dado_b = desempilha_dad();
    if (dado_b.tipo != ERRO)
    {
      if (dado_a.tipo == INTEIRO && dado_b.tipo == INTEIRO)
      {
        soma.tipo       = INTEIRO;
        soma.valor.ival = dado_a.valor.ival + dado_b.valor.ival;
        empilha_dad(soma);
        return -1;
      }
      else
        if (dado_a.tipo == INTEIRO && dado_b.tipo == REAL)
        {
          soma.tipo       = REAL;
          soma.valor.dval = (double) dado_a.valor.ival + dado_b.valor.dval;
          empilha_dad(soma);
          return -1;
        }
        else
          if (dado_a.tipo == REAL && dado_b.tipo == INTEIRO)
          {
            soma.tipo       = REAL;
            soma.valor.dval = (double) dado_a.valor.dval + dado_b.valor.ival;
            empilha_dad(soma);
            return -1;
	  }
          else
            if (dado_a.tipo == REAL && dado_b.tipo == REAL)
            {
              soma.tipo       = REAL;
              soma.valor.dval = (double) dado_a.valor.dval + dado_b.valor.dval;
              empilha_dad(soma);
              return -1;
            }
            else
              return CONFLITO_DE_TIPOS;
    }
    else      // A pilha contem apenas um operando. O mesmo e devolvido a pilha
    {
      empilha_dad(dado_a);
      return ESVAZIAMENTO_PILHA;
    }
  }
  else
    return ESVAZIAMENTO_PILHA;
}

// Funcao: sub
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: subtrai os elementos no topo da pilha.

int sub(void)
{
  Tdado dado_a,
        dado_b,
        diferenca;

  dado_a = desempilha_dad();
  if (dado_a.tipo != ERRO)
  {
    dado_b = desempilha_dad();
    if (dado_b.tipo != ERRO)
    {
      if (dado_a.tipo == INTEIRO && dado_b.tipo == INTEIRO)
      {
        diferenca.tipo       = INTEIRO;
        diferenca.valor.ival = dado_a.valor.ival - dado_b.valor.ival;
        empilha_dad(diferenca);
        return -1;
      }
      else
        if (dado_a.tipo == INTEIRO && dado_b.tipo == REAL)
        {
          diferenca.tipo       = REAL;
          diferenca.valor.dval = (double) dado_a.valor.ival -
                                 dado_b.valor.dval;
          empilha_dad(diferenca);
          return -1;
        }
        else
          if (dado_a.tipo == REAL && dado_b.tipo == INTEIRO)
          {
            diferenca.tipo       = REAL;
            diferenca.valor.dval = (double) dado_a.valor.dval -
                                   dado_b.valor.ival;
            empilha_dad(diferenca);
            return -1;
	  }
          else
            if (dado_a.tipo == REAL && dado_b.tipo == REAL)
            {
              diferenca.tipo       = REAL;
              diferenca.valor.dval = (double) dado_a.valor.dval -
                                     dado_b.valor.dval;
              empilha_dad(diferenca);
              return -1;
            }
            else
              return CONFLITO_DE_TIPOS;
    }
    else      // A pilha contem apenas um operando. O mesmo e devolvido a pilha
    {
      empilha_dad(dado_a);
      return ESVAZIAMENTO_PILHA;
    }
  }
  else
    return ESVAZIAMENTO_PILHA;
}

// Funcao: mul
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: multiplica os elementos no topo da pilha.

int mul(void)
{
  Tdado dado_a,
        dado_b,
        produto;

  dado_a = desempilha_dad();
  if (dado_a.tipo != ERRO)
  {
    dado_b = desempilha_dad();
    if (dado_b.tipo != ERRO)
    {
      if (dado_a.tipo == INTEIRO && dado_b.tipo == INTEIRO)
      {
        produto.tipo       = INTEIRO;
        produto.valor.ival = dado_a.valor.ival * dado_b.valor.ival;
        empilha_dad(produto);
        return -1;
      }
      else
        if (dado_a.tipo == INTEIRO && dado_b.tipo == REAL)
        {
          produto.tipo       = REAL;
          produto.valor.dval = (double) dado_a.valor.ival * dado_b.valor.dval;
          empilha_dad(produto);
          return -1;
        }
        else
          if (dado_a.tipo == REAL && dado_b.tipo == INTEIRO)
          {
            produto.tipo       = REAL;
            produto.valor.dval = (double) dado_a.valor.dval *
                                 dado_b.valor.ival;
            empilha_dad(produto);
            return -1;
	  }
          else
            if (dado_a.tipo == REAL && dado_b.tipo == REAL)
            {
              produto.tipo       = REAL;
              produto.valor.dval = (double) dado_a.valor.dval *
                                   dado_b.valor.dval;
              empilha_dad(produto);
              return -1;
            }
            else
              return CONFLITO_DE_TIPOS;
    }
    else      // A pilha contem apenas um operando. O mesmo e devolvido a pilha
    {
      empilha_dad(dado_a);
      return ESVAZIAMENTO_PILHA;
    }
  }
  else
    return ESVAZIAMENTO_PILHA;
}

// Funcao: div
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: divide os elementos no topo da pilha.

int Div(void)
{
  Tdado dado_a,
        dado_b,
        quociente;

  dado_a = desempilha_dad();
  if (dado_a.tipo != ERRO)
  {
    dado_b = desempilha_dad();
    if (dado_b.tipo != ERRO)
    {
      if (dado_a.tipo == INTEIRO && dado_b.tipo == INTEIRO)
      {
        if (dado_b.valor.ival != 0)
        {
          quociente.tipo       = INTEIRO;
          quociente.valor.ival = dado_a.valor.ival / dado_b.valor.ival;
          empilha_dad(quociente);
          return -1;
        }
        else
        {
          empilha_dad(dado_b);
          empilha_dad(dado_a);
          return DIVISAO_POR_ZERO;
        }          
      }
      else
        if (dado_a.tipo == INTEIRO && dado_b.tipo == REAL)
        {
          if (dado_b.valor.dval != 0)
	  {
            quociente.tipo       = REAL;
            quociente.valor.dval = (double) dado_a.valor.ival /
                                   dado_b.valor.dval;
            empilha_dad(quociente);
            return -1;
          }
          else
          {
            empilha_dad(dado_b);
            empilha_dad(dado_a);
            return DIVISAO_POR_ZERO;
          }
        }
        else
          if (dado_a.tipo == REAL && dado_b.tipo == INTEIRO)
          {
            if (dado_b.valor.ival != 0)
	    {
              quociente.tipo       = REAL;
              quociente.valor.dval = (double) dado_a.valor.dval /
                                     dado_b.valor.ival;
              empilha_dad(quociente);
              return -1;
            }
            else
            {
              empilha_dad(dado_b);
              empilha_dad(dado_a);
              return DIVISAO_POR_ZERO;
            }
          }
          else
            if (dado_a.tipo == REAL && dado_b.tipo == REAL)
            {
              if (dado_b.valor.dval != 0)
              {
                quociente.tipo       = REAL;
                quociente.valor.dval = (double) dado_a.valor.dval /
                                       dado_b.valor.dval;
                empilha_dad(quociente);
                return -1;
              }
              else
              {
                empilha_dad(dado_b);
                empilha_dad(dado_a);
                return DIVISAO_POR_ZERO;
              }
            }
            else
              return CONFLITO_DE_TIPOS;
    }
    else      // A pilha contem apenas um operando. O mesmo e devolvido a pilha
    {
      empilha_dad(dado_a);
      return ESVAZIAMENTO_PILHA;
    }
  }
  else
    return ESVAZIAMENTO_PILHA;
}

// Funcao: swap
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: troca o topo com o segundo elemento da pilha.

int swap(void)
{
  Tdado dado_a,
        dado_b;

  dado_a = desempilha_dad();
  if (dado_a.tipo != ERRO)
  {
    dado_b = desempilha_dad();
    if (dado_b.tipo != ERRO)
    {
      empilha_dad(dado_a);
      empilha_dad(dado_b);
      return -1;
    }
    else      // A pilha contem apenas um operando. O mesmo e devolvido a pilha
    {
      empilha_dad(dado_a);
      return ESVAZIAMENTO_PILHA;
    }
  }
  else
    return ESVAZIAMENTO_PILHA;
}

// Funcao: dup
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: duplica o topo da pilha.

int dup(void)
{
  Tdado dado;

  dado = topo_dad();
  if (dado.tipo != ERRO)
  {
    empilha_dad(dado);
    return -1;
  }
  else
    return ESVAZIAMENTO_PILHA;
}

// Funcao: jump
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: desvia para a posicao do vet. instrucoes apontada por "imediato".

int jump(int imediato)
{
  if(imediato < 0 || imediato > 99)
    return FORA_DOS_LIMITES;
  leitor_instrucoes = imediato;
  return -1;
}
  
// Funcao: If
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: desvia p/ a pos. indicada por imediato, se o topo da pilha
// tiver um valor verdadeiro.

int If(int imediato)
{
  Tdado teste;
  if ((teste = topo_dad()).tipo == ERRO) return ESVAZIAMENTO_PILHA;
  if ((teste.tipo == INTEIRO && teste.valor.ival != 0) || 
      (teste.tipo == REAL && teste.valor.dval != 0))
    
      return jump(imediato);
  return VALOR_N_VERDADEIRO;
}

// Funcao: call
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: empilha a proxima pos. do v_instrucoes e desvia p/ pos.
// indicada por imediato.

int call(int imediato)
{
  int temp;
  if ((temp = empilha_end(++leitor_instrucoes)) == ERRO)
    return ESTOURO_PILHA;
  return jump(imediato);
}  

// Funcao: Return
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: desvia p/ a pos. do v_instrucoes indicada pelo topo da
// pilha de enderecos.

int Return(void)
{
  int temp;
  if((temp = desempilha_end()) == ERRO)
    return ESVAZIAMENTO_PILHA;
  return jump(temp);
}

// Funcao: end
// Descricao: imprime uma msg indicando fim do programa.

void end(void)
{
  printf("Programa Encerrado.\n");
}

// Funcao: print
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: imprime o topo da pilha.

int print(void)
{
  Tdado dado;
  int cod_erro = -1;
  
  dado = topo_dad();
  
  if (dado.tipo != ERRO)
  {
    switch(dado.tipo)
    {
      case INTEIRO: printf("%d\n",dado.valor.ival);
                    break;
      case REAL: printf("%f\n",dado.valor.dval);
                 break;
      case STRING: printf("%s\n",dado.valor.strval);
                   break;
      default: cod_erro = TIPO_N_IMPRIMIVEL;
    }
    
    return cod_erro;
  }
  else
    return ESVAZIAMENTO_PILHA;
}
// Funcao: Cria_ponto
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Cria um no, pegando os parametros da pilha, e coloca-o no
// topo da pilha de dados.

int Cria_ponto(void)
{
  Tdado Ox,
    Oy,
    cor;
  
  Ox = desempilha_dad();
  Oy = desempilha_dad();
  cor = desempilha_dad();
  
  if (Ox.tipo == ERRO || Oy.tipo == ERRO || cor.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;
  
  if(Ox.tipo != REAL || Oy.tipo != REAL || cor.tipo != INTEIRO)
    return CONFLITO_DE_TIPOS;
  
  // coloca o objeto criado na pilha de dados.
  return push_obj(cria_ponto(Ox.valor.dval, Oy.valor.dval, cor.valor.ival));
  
}
  
// Funcao: Cria_reta
// Saida: -1 se deu certo; um codigo de erro caso contrario
// Descricao: Cria uma reta, com param. retirados da pilha, 
// e coloca-a no topo da pilha.

int Cria_reta (void)
{
  Tdado Ox,
    Oy,
    theta,
    cor;
  
  Oy = desempilha_dad();
  Ox = desempilha_dad();
  theta = desempilha_dad();
  cor = desempilha_dad();
  
  if (Ox.tipo == ERRO || Oy.tipo == ERRO || theta.tipo == ERRO || cor.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;
  
  if(Ox.tipo != REAL || Oy.tipo != REAL || theta.tipo != REAL || cor.tipo != INTEIRO)
    return CONFLITO_DE_TIPOS;

  // cria a reta e coloca-a no topo da pilha de dados.
  return push_obj(cria_reta(Ox.valor.dval, Oy.valor.dval, theta.valor.dval, cor.valor.ival));
	  
}

// Funcao: Cria_arco
// Saida: -1 se deu certo; um codigo de erro caso contrario
// Descricao: Cria um arco, com param. retirados da pilha, 
// e coloca-o no topo da pilha.

  
int Cria_arco (void)
{
  Tdado Ox, Oy, raio, theta_inic, theta_fin, cor;
  
  Ox = desempilha_dad();
  Oy = desempilha_dad();
  raio = desempilha_dad();
  theta_inic = desempilha_dad();
  theta_fin = desempilha_dad();
  cor = desempilha_dad();
  
  if (Ox.tipo == ERRO || Oy.tipo == ERRO || raio.tipo == ERRO || theta_inic.tipo == ERRO || theta_fin.tipo == ERRO || cor.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;
  
  if(Ox.tipo != REAL || Oy.tipo != REAL || raio.tipo != REAL || theta_inic.tipo != REAL || theta_fin.tipo != REAL || cor.tipo != INTEIRO)
    return CONFLITO_DE_TIPOS;
  
  // cria o arco e coloca-o no topo da pilha de dados.
  return push_obj(cria_arco(Ox.valor.dval, Oy.valor.dval, raio.valor.dval, theta_inic.valor.dval, theta_fin.valor.dval,  cor.valor.ival));
  
}

// Funcao: Cria_circ
// Saida: -1 se deu certo; um codigo de erro caso contrario
// Descricao: Cria um circulo, com param. retirados da pilha, 
// e coloca-o no topo da pilha.


int Cria_circ (void)
{
  Tdado Ox,
    Oy,
    raio,
    cor;
  
  Ox = desempilha_dad();
  Oy = desempilha_dad();
  raio = desempilha_dad();
  cor = desempilha_dad();
  
  if (Ox.tipo == ERRO || Oy.tipo == ERRO || raio.tipo == ERRO || cor.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;
  
  if(Ox.tipo != REAL || Oy.tipo != REAL || raio.tipo != REAL || cor.tipo != INTEIRO)
    return CONFLITO_DE_TIPOS;
  
  // cria o circulo e coloca-o no topo da pilha de dados.
  return push_obj(cria_circ(Ox.valor.dval, Oy.valor.dval, raio.valor.dval, cor.valor.ival));
  
}

// Funcao: Cria_segmento
// Saida: -1 se deu certo; um codigo de erro caso contrario
// Descricao: Cria um segmento de reta, com param. retirados da pilha, 
// e coloca-o no topo da pilha.


int Cria_segmento (void)
{
  Tdado x1, y1, x2, y2, cor;
  
  x1 = desempilha_dad();
  y1 = desempilha_dad();
  x2 = desempilha_dad();
  y2 = desempilha_dad();
  cor = desempilha_dad();
  
  if (x1.tipo == ERRO || y1.tipo == ERRO || x2.tipo == ERRO || y2.tipo == ERRO || cor.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;
  
  if(x1.tipo != REAL || y1.tipo != REAL || x2.tipo != REAL || y2.tipo != REAL ||  cor.tipo != INTEIRO)
    return CONFLITO_DE_TIPOS;
  
  // cria o segmento de reta e coloca-o no topo da pilha de dados.
  return push_obj(cria_segmento(x1.valor.dval, y1.valor.dval, x2.valor.dval, y2.valor.dval,  cor.valor.ival));
  
}

// Funcao: Cria_poligono
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: cria um poligono, e coloca-o no topo da pilha. Cria tb uma
// lista circular de vertices, com valores retirados da pilha.

int Cria_poligono (void)
{
  Tdado temp1, temp2, cor;
  ap_vertice prim_vertice, 
    atu_vertice = NULL,
    novo;

  // criacao da lista circular de vertices do poligono.
  
  while ((temp1 = desempilha_dad()).tipo != MARCADOR && (temp2 = desempilha_dad()).tipo != MARCADOR) // procura por novos vertices ate encontrar
                           // um marcador.

    {
      // a pilha precisa ter pelo menos 2 valores numericos, que serao
      // as coordenadas x e y do vertice.
      if (temp1.tipo == ERRO || temp2.tipo == ERRO)            
	return ESVAZIAMENTO_PILHA;

      if (temp1.tipo != REAL || temp2.tipo != REAL)
       	return CONFLITO_DE_TIPOS;

      if (atu_vertice == NULL) // Primeiro vertice.
	{
	  prim_vertice = (ap_vertice) malloc(sizeof(struct _VERTICE));
	  prim_vertice->y = temp1.valor.dval;
	  prim_vertice->x = temp2.valor.dval;
	  prim_vertice->prox = prim_vertice;
	  atu_vertice = prim_vertice;
	}
      else // Cria outro vertice.
	{
	  novo = (ap_vertice) malloc(sizeof(struct _VERTICE));
	  novo->y = temp1.valor.dval;
	  novo->x = temp2.valor.dval;
	  novo->prox = prim_vertice;
	  atu_vertice->prox = novo;
	  atu_vertice = novo;
	}
    }
  if (temp1.tipo != MARCADOR) return N_DADOS_INCORRETO; 

  cor = desempilha_dad();
  if(cor.tipo == ERRO) return ESVAZIAMENTO_PILHA;
  if(cor.tipo != INTEIRO) return CONFLITO_DE_TIPOS;

  // cria o poligono e coloca-o no topo da pilha de dados.
  return push_obj(cria_poligono(prim_vertice, cor.valor.ival));
 
}

// Funcao: Cria_janela
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Cria uma janela e coloca-a na pilha.

int Cria_janela (void)
{
  Tdado janela, teste;
  WINDOW *nova;
  
  nova = InitGraph(TAM_X_TELA, TAM_Y_TELA, "Manipulador de Objetos Graficos");
  janela.tipo = JANELA;
  janela.valor.objval = nova;
  teste =   empilha_dad(janela);
  if(teste.tipo == ERRO) return ESTOURO_PILHA;
  return -1;
}
// Funcao: Desenha_ponto
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Desenha um ponto, retirando a janela e o ponto a ser 
// desenhado da pilha. Os mesmos sao devolvidos a pilha no fim da funcao.

int Desenha_ponto (void) 
{
  Tdado janela, ponto;
  
  ponto = desempilha_dad();
  janela = desempilha_dad();

  if (ponto.tipo == ERRO ) 
    return ESVAZIAMENTO_PILHA;
  
  if (ponto.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;
    
  if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }
     

  if (((ap_objeto) ponto.valor.objval)->tipo != PONTO) 
    return CONFLITO_DE_TIPOS;

  WShow (janela.valor.objval);
  desenha_ponto (janela.valor.objval, ((ap_objeto) ponto.valor.objval)->Ox, ((ap_objeto) ponto.valor.objval)->Oy, ((ap_objeto) ponto.valor.objval)->cor);

  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);// nao e necessaria a verificacao de estouro da
  // pilha, pois os objetos inseridos sao os mesmos que foram retirados
  // no inicio da funcao.

  empilha_dad(ponto);

  return -1;
}

// Funcao: Desenha_reta
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Desenha uma reta, retirando a janela e a reta a ser dese-// nhada da pilha. Os mesmos sao devolvidos a pilha no fim da funcao.

int Desenha_reta (void)
{
  Tdado janela, reta;
  
  reta = desempilha_dad();
  janela = desempilha_dad();

  if (reta.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (reta.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;

  if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
      // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }

  if (((ap_objeto) reta.valor.objval)->tipo != RETA) 
    return CONFLITO_DE_TIPOS;

  WShow (janela.valor.objval);
  desenha_reta (janela.valor.objval, ((ap_objeto) reta.valor.objval)->Ox, ((ap_objeto) reta.valor.objval)->Oy, ((ap_reta) ((ap_objeto) reta.valor.objval)->descr)->theta, ((ap_objeto) reta.valor.objval)->cor);


 
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad(reta);

  return -1;
}

// Funcao: Desenha_arco
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Desenha um arco, retirando a janela e o arco a ser dese-
// nhado da pilha. Os mesmos sao devolvidos a pilha no fim da funcao.

int Desenha_arco (void)
{

  Tdado janela, arco;
  
  arco = desempilha_dad();
  janela = desempilha_dad();
  
  if (arco.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (arco.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;

 if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }

  if (((ap_objeto) arco.valor.objval)->tipo != ARCO) 
    return CONFLITO_DE_TIPOS;
  
  WShow (janela.valor.objval);
  desenha_arco (janela.valor.objval, ((ap_objeto) arco.valor.objval)->Ox, ((ap_objeto) arco.valor.objval)->Oy, ((ap_arco) ((ap_objeto) arco.valor.objval)->descr)->raio, ((ap_arco) ((ap_objeto) arco.valor.objval)->descr)->theta_inic, ((ap_arco) ((ap_objeto) arco.valor.objval)->descr)->theta_fim, ((ap_objeto) arco.valor.objval)->cor);
  
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (arco);

  empilha_dad(arco);

  return -1;
}


// Funcao: Desenha_circ
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Desenha uma circunferencia, retirando a janela e a circunferencia
// ser desenhada da pilha. Os mesmos sao devolvidos a pilha no fim da funcao.

int Desenha_circ (void)
{

  Tdado janela, circ;
  
  circ = desempilha_dad();
  janela = desempilha_dad();
  
  if (circ.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (circ.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;

  if (((ap_objeto) circ.valor.objval)->tipo != CIRC) 
    return CONFLITO_DE_TIPOS;

 if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }
  
  WShow (janela.valor.objval);
  desenha_circ (janela.valor.objval, ((ap_objeto) circ.valor.objval)->Ox, ((ap_objeto) circ.valor.objval)->Oy, ((ap_circ) ((ap_objeto) circ.valor.objval)->descr)->raio, ((ap_objeto) circ.valor.objval)->cor);
  
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad(circ);

  return -1;
}

// Funcao: Desenha_poligono
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Desenha um poligono, retirando a janela e o poligono a ser 
// desenhado da pilha. Os mesmos sao devolvidos a pilha no fim da funcao.

int Desenha_poligono (void)
{

  Tdado janela, poligono;
  
  poligono = desempilha_dad();
  janela = desempilha_dad();
  
  if (poligono.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (poligono.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;

 if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }

  if (((ap_objeto) poligono.valor.objval)->tipo != POLIGONO) 
    return CONFLITO_DE_TIPOS;
  
  WShow (janela.valor.objval);
  desenha_poligono (janela.valor.objval, ((ap_objeto) poligono.valor.objval)->descr, ((ap_objeto) poligono.valor.objval)->cor);
  
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad(poligono);

  return -1;
}
// Funcao: Desenha_segmento
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Desenha um segmento de reta, retirando a janela e o segmento
// a ser desenhado da pilha. Os mesmos sao devolvidos a pilha no fim 
// da funcao.

int Desenha_segmento (void)
{

  Tdado janela, segmento;
  
  segmento = desempilha_dad();
  janela = desempilha_dad();
  
  if (segmento.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (segmento.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;

 if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }

  if (((ap_objeto) segmento.valor.objval)->tipo != SEGMENTO) 
    return CONFLITO_DE_TIPOS;
  
  WShow (janela.valor.objval);
  desenha_segmento (janela.valor.objval, ((ap_segmento) ((ap_objeto) segmento.valor.objval)->descr)->x1, ((ap_segmento) ((ap_objeto) segmento.valor.objval)->descr)->y1, ((ap_segmento) ((ap_objeto) segmento.valor.objval)->descr)->x2, ((ap_segmento) ((ap_objeto) segmento.valor.objval)->descr)->y2, ((ap_objeto) segmento.valor.objval)->cor);
  
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad(segmento);

  return -1;
}

// Funcao: Move_ponto
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: Move um ponto, retirando os parametros necessarios da pilha.
// A janela e o ponto sao devolvidos a pilha no fim da funcao.

int Move_ponto (void)
{
  Tdado janela, ponto, novo_x, novo_y;
  
  novo_y = desempilha_dad();
  novo_x = desempilha_dad();
  ponto = desempilha_dad();
  janela = desempilha_dad();
  
  
  if (ponto.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (ponto.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;
  
  if (((ap_objeto) ponto.valor.objval)->tipo != PONTO) 
    return CONFLITO_DE_TIPOS;

  if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }
    
    
  if (novo_x.tipo == ERRO || novo_y.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;
  
  if (novo_x.tipo != REAL || novo_y.tipo != REAL)
    return CONFLITO_DE_TIPOS;
  

  WShow(janela.valor.objval);
  move_ponto(janela.valor.objval, ponto.valor.objval, novo_x.valor.dval, novo_y.valor.dval); 
  
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad (ponto);
  return -1;
}
// Funcao: Move_reta
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: Move uma reta, retirando os parametros necessarios da pilha.
// A janela e a reta sao devolvidos a pilha no fim da funcao.

int Move_reta (void)
{
  Tdado janela, reta, novo_x, novo_y;
  
  novo_y = desempilha_dad();
  novo_x = desempilha_dad();
  reta = desempilha_dad();
  janela = desempilha_dad();
  
  if (reta.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (reta.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;
  
  if (((ap_objeto) reta.valor.objval)->tipo != RETA) 
    return CONFLITO_DE_TIPOS;

  if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }

    
  if (novo_x.tipo == ERRO || novo_y.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;
  
  if (novo_x.tipo != REAL || novo_y.tipo != REAL)
    return CONFLITO_DE_TIPOS;
  
  WShow(janela.valor.objval);
  move_reta(janela.valor.objval, reta.valor.objval, novo_x.valor.dval, novo_y.valor.dval); 
  
 
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad (reta);

  return -1;
}
// Funcao: Move_arco
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: Move um arco, retirando os parametros necessarios da pilha.
// A janela e o arco sao devolvidos a pilha no fim da funcao.

int Move_arco (void)
{
  Tdado janela, arco, novo_x, novo_y;
  
  novo_y = desempilha_dad();
  novo_x = desempilha_dad();
  arco = desempilha_dad();
  janela = desempilha_dad();
  
  if (arco.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (arco.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;
  
  if (((ap_objeto) arco.valor.objval)->tipo != ARCO) 
    return CONFLITO_DE_TIPOS;
  
  if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }
  
 
  
  if (novo_x.tipo == ERRO || novo_y.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;

  if (novo_x.tipo != REAL || novo_y.tipo != REAL)
    return CONFLITO_DE_TIPOS;


  WShow(janela.valor.objval);
  move_arco(janela.valor.objval, arco.valor.objval, novo_x.valor.dval, novo_y.valor.dval); 
  
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad (arco);
  return -1;
}
// Funcao: Move_circ
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: Move uma circ, retirando os parametros necessarios da pilha.
// A janela e a circ sao devolvidos a pilha no fim da funcao.

int Move_circ (void)
{
  Tdado janela, circ, novo_x, novo_y;
  

  novo_y = desempilha_dad();
  novo_x = desempilha_dad();
  circ = desempilha_dad();
  janela = desempilha_dad();
  
    if (circ.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (circ.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;
  
 if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }

  if (((ap_objeto) circ.valor.objval)->tipo != CIRC) 
    return CONFLITO_DE_TIPOS;
  
 
  if (novo_x.tipo == ERRO || novo_y.tipo == ERRO)
    return ESVAZIAMENTO_PILHA;

  if (novo_x.tipo != REAL || novo_y.tipo != REAL)
    return CONFLITO_DE_TIPOS;

  
  WShow(janela.valor.objval);
  move_circ(janela.valor.objval, circ.valor.objval, novo_x.valor.dval, novo_y.valor.dval); 
  
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad (janela);

  empilha_dad(circ);
  return -1;
}
// Funcao: Move_poligono
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: Move uma poligono, retirando os parametros necessarios da
//  pilha. A janela e a poligono sao devolvidos a pilha no fim da funcao.

int Move_poligono (void)
{
  Tdado janela, poligono, novo_x, novo_y;
  
  novo_y = desempilha_dad();
  novo_x = desempilha_dad();
  poligono = desempilha_dad();
  janela = desempilha_dad();
  
  
  if (poligono.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (poligono.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;
  
  if (((ap_objeto) poligono.valor.objval)->tipo != POLIGONO) 
    return CONFLITO_DE_TIPOS;
  
 if(janela.tipo != JANELA)
   {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
     if(janela.tipo != ERRO) empilha_dad(janela);
     janela = janela_default; 
    }
 

 if (novo_x.tipo == ERRO || novo_y.tipo == ERRO)
   return ESVAZIAMENTO_PILHA;
 
 if (novo_x.tipo != REAL || novo_y.tipo != REAL)
   return CONFLITO_DE_TIPOS;
 

 WShow(janela.valor.objval);
 move_poligono(janela.valor.objval, poligono.valor.objval, novo_x.valor.dval, novo_y.valor.dval); 
 
 
 if (janela.tipo != janela_default.tipo)
   empilha_dad (janela);

 empilha_dad (poligono);
 return -1;
}
// Funcao: Move_segmento
// Saida: -1 se deu certo; um codigo de erro caso contrario.
// Descricao: Move uma segmento, retirando os parametros necessarios da
// pilha. A janela e a segmento sao devolvidos a pilha no fim da funcao.

int Move_segmento (void)
{
  Tdado janela, segmento, novo_x, novo_y;
  
  novo_x = desempilha_dad();
  novo_y = desempilha_dad();
  segmento = desempilha_dad();
  janela = desempilha_dad();
 
   
  if (segmento.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (segmento.tipo != OBJETO)
      return CONFLITO_DE_TIPOS;
    
  
  if (((ap_objeto) segmento.valor.objval)->tipo != SEGMENTO) 
    
    return CONFLITO_DE_TIPOS;
   

 if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }
 
 
 if (novo_x.tipo == ERRO || novo_y.tipo == ERRO)
   return ESVAZIAMENTO_PILHA;
 
 if (novo_x.tipo != REAL || novo_y.tipo != REAL)
   
   return CONFLITO_DE_TIPOS;
   
 
 WShow(janela.valor.objval);
 move_segmento(janela.valor.objval, segmento.valor.objval, novo_x.valor.dval, novo_y.valor.dval); 
 
 
 if (janela.tipo != janela_default.tipo)
   empilha_dad (janela);

 empilha_dad (segmento);
 return -1;
}

// Funcao: Destroi_objeto
// Saida: -1 se deu certo; codigo de erro caso contrario.
// Descricao: Apaga um objeto retirado da pilha de dados. A janela, que
// tambem e retirada da pilha, e devolvida a mesma no fim da funcao.

int Destroi_objeto (void)
{
   Tdado janela, objeto;
  
  objeto = desempilha_dad();
  janela = desempilha_dad();
  
  if (objeto.tipo == ERRO) 
    return ESVAZIAMENTO_PILHA;
  
  if (objeto.tipo != OBJETO)
    return CONFLITO_DE_TIPOS;

 if(janela.tipo != JANELA)
    {// Nao ha uma janela na pilha: sera desenhado na janela
     // default.
      if(janela.tipo != ERRO) empilha_dad(janela);
      janela = janela_default; 
    }


  apaga_no(janela.valor.objval, objeto.valor.objval, ((ap_objeto) objeto.valor.objval)->id);
  
  if (janela.tipo != janela_default.tipo)
    empilha_dad(janela);
  return -1;
}
