typedef enum       // Define os comandos utilizados pelo interpretador
        {
          PUSH_i, PUSH_d, PUSH_str, PUSH_obj, PUSH_marc, PUSH_pos, DROP, STORE, RESTORE, ADD, SUB, MUL, DIV, SWAP, DUP,
          JUMP, IF, CALL, RETURN, END, PRINT, CRIA_PONTO, CRIA_RETA, CRIA_ARCO,
          CRIA_CIRC, CRIA_POLIGONO, CRIA_SEGMENTO, CRIA_JANELA, DESENHA_PONTO, DESENHA_RETA,
          DESENHA_ARCO, DESENHA_CIRC, DESENHA_POLIGONO, DESENHA_SEGMENTO,
          MOVE_PONTO, MOVE_RETA, MOVE_ARCO, MOVE_CIRC, MOVE_POLIGONO,
          MOVE_SEGMENTO, DESTROI_OBJETO
        } OPCODE;

typedef enum       // Define os tipos de erros trataveis pelo interpretador
        {
          ESTOURO_PILHA,
          ESVAZIAMENTO_PILHA,
          CONFLITO_DE_TIPOS,
          DIVISAO_POR_ZERO,
          FORA_DOS_LIMITES,
          TIPO_N_IMPRIMIVEL,
	  VALOR_N_VERDADEIRO,
	  N_DADOS_INCORRETO
        } ERROS;

typedef struct _INSTRUCAO
        {
          OPCODE op;
          union
          {
            int ival,
	        posicval;
            double dval;
            void *objval;
            char strval[51],
	         marcval;
          } imediato;
        } Tinstrucao;

int push_i(int imediato);
int push_d(double imediato);
int push_str(char *imediato);
int push_obj(void *imediato);
int push_pos(int imediato);
int push_marc(char imediato);
int drop(void);
int store(int imediato);
int restore(int imediato);
int add(void);
int sub(void);
int mul(void);
int Div(void);
int swap(void);
int dup(void);
int jump(int imediato);
int If(int imediato);
int call(int imediato);
int Return(void);
void end(void);
int print(void);
int Cria_ponto(void);
int Cria_reta(void);
int Cria_arco(void);
int Cria_circ(void);
int Cria_poligono(void);
int Cria_segmento(void);
int Cria_janela(void);
int Desenha_ponto(void);
int Desenha_reta(void);
int Desenha_arco(void);
int Desenha_circ(void);
int Desenha_poligono(void);
int Desenha_segmento(void);
int Move_ponto(void);
int Move_reta(void);
int Move_arco(void);
int Move_circ(void);
int Move_poligono(void);
int Move_segmento(void);
int Destroi_objeto(void);


