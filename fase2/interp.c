// Modulo:    interpretador da maquina virtual
// Descricao: executa as rotinas existentes no vetor de instrucoes da 
// maquina virtual. Tambem controla a memoria.

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

#define FALSE 0
#define TRUE 1

Tdado p_dados[100],           // Pilha de dados
      memoria[100],           // Memoria acessivel pelo interpretador
      janela_default;             
Tinstrucao v_instrucoes[100]; // Vetor de instrucoes
int p_enderecos[100],         // Pilha de enderecos
    leitor_instrucoes = 0,    // Percorre o v_instrucoes 
    topo_p_dad = -1,          // Topo da pilha de dados
    topo_p_end = -1,          // Topo da pilha de enderecos
    cont_id    = 0,           // Identificacao de cada objeto criado
    fim = FALSE,              // Indica fim do programa 
    result,                   // Resultado de uma leitura de v_instrucoes
    saida_normal = FALSE;     // Indica saida normal (fim do programa)
  
// Funcao: interpreta
// Descricao: varre o vetor de instrucoes chamando as rotinas correspon-
// dentes as mesmas. Em seguida, decide se deve imprimir uma msg e encer
// rar o programa (ocorreu um erro) ou continuar a ler o v_instrucoes.

void interpreta(void)
{
  janela_default.tipo = JANELA_DEFAULT;
  (WINDOW *)janela_default.valor.objval = InitGraph(TAM_X_TELA, TAM_Y_TELA,
                                                    "Janela Default");
  while (leitor_instrucoes <= 99 && fim == FALSE)
    {
      switch (v_instrucoes[leitor_instrucoes].op)
	{
	case PUSH_i:
	  
	  result = push_i(v_instrucoes[leitor_instrucoes].imediato.ival);
	  if (result == -1 ) break;
	  fim = TRUE;
	  break;
	  
	  
	case PUSH_d:
	  
	  result = push_d(v_instrucoes[leitor_instrucoes].imediato.dval);
	    if (result == -1) break;
	    fim = TRUE;
	    break;
	    	    
	case PUSH_obj:
	  
	  result = push_obj(v_instrucoes[leitor_instrucoes].imediato.objval);
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	  
	  
	case PUSH_str:
	  
	  result = push_str(v_instrucoes[leitor_instrucoes].imediato.strval);
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	  
	  
	case PUSH_pos:
	  
	  result = push_pos(v_instrucoes[leitor_instrucoes].imediato.posicval);
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	  
	  
	case PUSH_marc:
	  
	  result = push_marc(v_instrucoes[leitor_instrucoes].imediato.marcval);
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	  	  
	case DROP:
	  
	  result = drop();
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	  	  
	case STORE:
	  
	  result = store(v_instrucoes[leitor_instrucoes].imediato.ival);
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	  	  
	case RESTORE:
	  
	  result = restore(v_instrucoes[leitor_instrucoes].imediato.ival);
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	 	  
	case ADD:
	  
	  result = add();
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	 
	  
	case SUB:
	  
	  result = sub();
	  if (result == -1) break;
	  fim = TRUE;
	  break;
	 
	  case MUL:
	    
	    result = mul();
	    if (result == -1) break;
	    fim = TRUE;
	    break;
	    
	    
	case DIV:
	  
	  result = Div();
	    if (result == -1) break;
	    fim = TRUE;
	    break;
	   
	    
	case SWAP: 
	  
	  result = swap();
	  if (result == -1) break;
	  fim = TRUE;
	  break;

        case DUP:

          result = dup();
          if (result == -1) break;
          fim = TRUE;
          break;
	  
	case JUMP:
	  
	  result = jump(v_instrucoes[leitor_instrucoes].imediato.ival);
	  if (result == -1)
	    {
	      leitor_instrucoes --; // a proxima inst. a ser lida sera
	                            // aquela indicada por "imediato"
	      break;
	    }
	  fim = TRUE;
	  break;

	case IF:

	  result = If(v_instrucoes[leitor_instrucoes].imediato.ival);
	  if (result == -1)
	    {
	      leitor_instrucoes --;
	      break;
	    }
	  fim = TRUE;
	  break;
	  
	  
	case CALL:
	  
	  result = call(v_instrucoes[leitor_instrucoes].imediato.ival);
	  if (result == -1)
	    {
	      leitor_instrucoes --;
	      break;
	    }
	  fim = TRUE;
	  break;
	  
	  
	case RETURN:
	  
	  result = Return();
	  if (result == -1)
	    {
	      leitor_instrucoes --;
	      break;
	    }
	  fim = TRUE;
	  break;
	  
	  
	case END:
	  end();
	  fim = TRUE;
	  saida_normal = TRUE;
	  break;
		  
	case PRINT:
	  result = print();
	  if(result == -1) break;
	  printf("%d\n",result);
	  fim = TRUE;
	  break;
	  
	case CRIA_PONTO:
	  result = Cria_ponto();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case CRIA_RETA:
	  result = Cria_reta();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case CRIA_ARCO:
	  result = Cria_arco();
	  if(result == -1) break;
	  fim = TRUE;
	  break;
	  
	case CRIA_CIRC:
	  result = Cria_circ();
	  if(result == -1) break;
	  fim = TRUE;
	  break;
       
	case CRIA_SEGMENTO:
	  result = Cria_segmento();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case CRIA_POLIGONO:
	  result = Cria_poligono();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case CRIA_JANELA:
	  result = Cria_janela();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  DESENHA_PONTO:
	  result =  Desenha_ponto();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  DESENHA_RETA:
	  result =  Desenha_reta();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  DESENHA_ARCO:
	  result =  Desenha_arco();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  DESENHA_CIRC:
	  result =  Desenha_circ();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  DESENHA_POLIGONO:
	  result =  Desenha_poligono();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  DESENHA_SEGMENTO:
	  result =  Desenha_segmento();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  MOVE_PONTO:
	  result =  Move_ponto();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  MOVE_RETA:
	  result =  Move_reta();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  MOVE_ARCO:
	  result =  Move_arco();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  MOVE_CIRC:
	  result =  Move_circ();
	  getchar();
	  
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  MOVE_POLIGONO:
	  result =  Move_poligono();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	case  MOVE_SEGMENTO:
	  result =  Move_segmento();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;
	  
	case  DESTROI_OBJETO:
	  result =  Destroi_objeto();
	  getchar();
	  if(result == -1) break;
	  fim = TRUE;
	  break;

	default:
	  printf("Instrucao invalida!!!\n");
	  break;
	  
	}	    
     
      leitor_instrucoes ++;
      
    }
  if (saida_normal != TRUE)
    {
      switch (result) // Imprime a msg correspondente ao tipo de erro.
	{
	case ESTOURO_PILHA:
	  printf("Erro! Estouro de pilha!!! \n");
	  break;
	case ESVAZIAMENTO_PILHA:
	  printf("Erro! A pilha esta vazia!!!\n");
	  break;
	case FORA_DOS_LIMITES:
	printf("O indice escolhido esta fora da memoria!!!\n");
	break;
	case CONFLITO_DE_TIPOS:
	  printf("Erro! Tipos de dados conflitantes!!!\n");
	  break;
	case DIVISAO_POR_ZERO:
	  printf("Tentou dividir por zero! Operacao cancelada!\n");
	  break;
	case VALOR_N_VERDADEIRO:
	printf("A pilha de dados contém um valor nao verdadeiro!!!\n");
	break;
	case TIPO_N_IMPRIMIVEL:
	  printf("Nao posso imprimir elementos do tipo solicitado.\n");
	  break;
	case N_DADOS_INCORRETO:
	  printf("Numero de dados incorreto!!!\n");
	  break;
	default:
	  printf("Tipo de erro nao definido!!!\n");
	  break;
	}
    }
}
