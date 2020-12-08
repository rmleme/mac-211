#define ERRO -2

typedef enum          // Define os tipos de dados que podem
        {             // ser manipulados pelo programa
          INTEIRO,
          REAL,
          OBJETO,
          STRING,
          POSICAO,
          MARCADOR,
	  JANELA,
          JANELA_DEFAULT
        } TIPO_DADO;

typedef struct _DADO        // Define a pilha de dados
        {
          TIPO_DADO tipo;
          union
          {
            int ival,
	        posicval;
            double dval;
            void *objval;
            char strval[51],
                 marcval;
          } valor;
        } Tdado;

Tdado empilha_dad(Tdado dado);
Tdado desempilha_dad(void);
Tdado topo_dad(void);
void limpa_dad(void);
int cheia_dad(void);
int vazia_dad(void);
int empilha_end(int endereco);
int desempilha_end(void);
int topo_end(void);
void limpa_end(void);
int cheia_end(void);
int vazia_end(void);
