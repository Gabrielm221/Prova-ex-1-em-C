#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define tam 4

typedef struct info {
    int cod_aplicacao;
    int num_transacao;
    int cod_sql;
    int cod_priori;
} info;

typedef struct Tfila {
    info dados;
    struct Tfila *prox;
} Tfila;

typedef struct fila {
    Tfila *inicio;
    Tfila *fim;
}fila;
//---------------------------------------------------------------------------
void insere_fila_ordenado(fila *f, info x){

    Tfila *novo = (Tfila*) malloc(sizeof(Tfila));
    novo->dados.cod_aplicacao = x.cod_aplicacao;
    novo->dados.cod_priori = x.cod_priori;
    novo->dados.cod_sql = x.cod_sql;
    novo->dados.num_transacao = x.num_transacao;
    novo->prox = NULL;

    if (x.cod_priori == 2) { // se for prioridade 2, insere no início da fila
        if (f->inicio == NULL) {
            f->inicio = novo;
            f->fim = novo;
        } else {
            novo->prox = f->inicio;
            f->inicio = novo;
        }
        return;
    }

    Tfila *p = f->inicio;
    Tfila *ant = NULL;

     if (f->inicio == NULL) {
            f->inicio = novo;
            f->fim = novo;
            return;
     }
     else{

        while(p != NULL && p->dados.cod_priori != 1){
            ant = p;
            p = p->prox;

        }

        while (p != NULL && p->dados.num_transacao <= x.num_transacao){
            ant = p;
            p = p->prox;
        }
        if (p == NULL) { // insere no fim da fila
            printf("\nfim");
            f->fim->prox = novo;
            f->fim = novo;
        } else if (ant == NULL) { // insere no início da fila
            printf("\nini");
            novo->prox = p;
            f->inicio = novo;
        } else { // insere no meio da fila
            printf("\nmeio");
            ant->prox = novo;
            novo->prox = p;
        }
     }
}
//--------------------------------------------------------------
void createfila(fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}
//---------------------------------------------------------------
int fila_vazia(fila *f) {
    if (f->inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}
//--------------------------------------------------------------
int inserir_prioridade(fila *f, info axx) {
    if (axx.cod_priori == 2){
    Tfila *novo = (Tfila*) malloc(sizeof(Tfila));
    novo->dados.cod_aplicacao = axx.cod_aplicacao;
    novo->dados.cod_priori = axx.cod_priori;
    novo->dados.cod_sql = axx.cod_sql;
    novo->dados.num_transacao = axx.num_transacao;
    novo->prox = NULL;

    Tfila *aux = f->inicio;
    Tfila *ant = NULL;

    if (fila_vazia(f) == 1) { // primeira vez
        f->inicio = novo; // inicio aponta para novo
        f->fim = novo; // Ajusta-se o fim
    return;
    }

    if (f->inicio->dados.cod_priori != 2){ // insere o novo nó como prioridade no inicio da fila
        novo->prox = f->inicio;
        f->inicio = novo;
        return;
    }

    while (aux != NULL && aux->dados.cod_priori == 2) {
        ant = aux;
        aux = aux->prox;
    }
    novo->prox = aux;
    ant->prox = novo;

    return;
    }
    else {

        insere_fila_ordenado(f, axx);
    }
}
//-------------------------------------------------------------
info remove_fila(fila *f){
    Tfila *aux=(Tfila*)malloc(sizeof(Tfila));
    info ddv;
    aux=f->inicio;
    ddv =aux->dados;


    f->inicio = aux->prox;

    aux->prox=NULL;

    if(f->inicio==NULL){

       f->fim=NULL;
    }else{
       free(aux);
    }
    return(ddv);
}
//---------------------------------------------------------------------
/*void scanfilaa(f, f2);
{
    Tfila ini malloc(sizeof(Tfila));

    while(ini != NULL)
    {
        inserir_fila(f2,ini->dados);
        ini = ini->prox;
    }
      if(fila_vazia(p)==1)
    {
        printf("\n Impossivel remover ");
        printf(" ------>Fila vazia!! \n");
        getch( );
    }
    else
    {
        apagarfila(f);
    }
    free(aux);
}
//---------------------------------------------------------------------
void apagarfila(fila *f)
{
    Tfila *aux = malloc(sizeof(Tfila));
    info ;
    aux = f->inicio;
    while(aux != NULL)
    {
        aux=aux->prox;
        elemento = remove_fila(f);
    }

    free(aux);
}*/
//-------------------------------------------------------------------
void mostra_fila(fila *f){
    Tfila *aux=(Tfila*)malloc(sizeof(Tfila));
    aux =f->inicio;

	//printf("\n Fila : ");
	while(aux != NULL)
	{
        printf(" |Codigo de aplicacao : %d ", aux->dados.cod_aplicacao);
        printf(" |Codigo de prioridade : %d ", aux->dados.cod_priori);
        printf(" |Codigo SQL : %d ", aux->dados.cod_sql);
        printf(" |Codigo de transacao : %d ", aux->dados.num_transacao);
        printf("\n\n\n\n\n");
        aux = aux->prox; //incrementa o ponteiro
	}
}
//---------------------------------------------------------------------
int inserir_fila(fila *f, info dado){

    //cria um novo novo
    Tfila *novo=(Tfila*)malloc(sizeof(Tfila));
    novo->dados = dado;
    novo->prox=NULL;

    if(fila_vazia(f)){    //primeira vez
        f->inicio=novo; //inicio aponta para o novo
        f->fim=novo; //Ajusta-se o fim
        return;
    }
    //se não está vazia, insere no fim da fila
    f->fim->prox=novo; //ultimo elemento aponta para o novo
    f->fim=novo; // novo elemento é o último
    return;
}

void menu()
{
    int op = 0, x = 0;
    info axx;
    info exc;
    fila *f = (fila*)malloc(sizeof(fila));
    createfila(f);
    fila *f2 = (fila*)malloc(sizeof(fila));
    createfila(f);

    do{
    system("cls");
    printf("\n Fila: \n");
    mostra_fila(f);

    printf("\n\n");
    printf("Digite uma opcao: \n");
    printf("1 - Inserir \n");
    printf("2 - Remover \n");
    printf("0 - Sair \n");
    printf("\n\n");

    scanf("%d", &op);

    switch(op){

       case 1:{

                printf("\n\t Digite o codigo da aplicacao: ");
                scanf("%d",&axx.cod_aplicacao);

                printf("\n\t Digite o codigo de prioridade: ");
                scanf("%d",&axx.cod_priori);

                printf("\n\t Digite o codigo da transacao: ");
                scanf("%d",&axx.num_transacao);

                printf("\n\t Digite o codigo SQL: ");
                scanf("%d",&axx.cod_sql);

                printf("\n\n\n");

                //insere o elemento na fila de acordo com sua prioridade
                inserir_prioridade(f, axx);

           printf("\n\n\tLimite excedido, aperte qualquer tecla para voltar ao menu e selecione a opcao numero 2...");
           getch();
           break;
       }
       case 2:{
           if(fila_vazia(f)){
              printf("\n Fila vazia!");
              getch();
           }else{
                x = 0;
                while(x < tam)
                {
                    //Remove o elemento do início da fila
                    //scanfilaa(f, f2);

                    //Insere o elemento na segunda fila

                    printf("\n Dados removidos com sucesso! ");
                    printf("\n------------------------------------");
                    printf("\nCodigo da aplicacao: %d ", exc.cod_aplicacao);
                    printf("\nCodigo da transacao: %d ", exc.num_transacao);
                    printf("\nCodigo SQL: %d ", exc.cod_sql);
                    printf("\nCodigo de prioridade: %d ", exc.cod_priori);
                    printf("\n\n\n\n\n\n");
                    fflush(stdin);
                    x = x+1;
                }
                system("cls");
                mostra_fila(f2);
           }
           break;
       }
       case 0:{
           exit(0);
       }
       default:{
            printf("\nOpcao invalida!");
            getch();
            break;
       }
     }
    }while(op!=0);
}

        int main(){
        menu();
        return 0;
        }
