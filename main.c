#include <stdio.h>
//#include <malloc.h>
#include <mm_malloc.h>
#include <stdbool.h>
#include <ncurses.h>


// soldados tem que ter na mesma quantidade de nomes inseridos
typedef int TIPOCHAVE;
typedef struct {
    TIPOCHAVE chave;
}REGISTRO;
typedef struct tempRegistro{
    REGISTRO reg;
    struct tempRegistro*prox;
}ELEMENTO;
//typedef struct {
  //  int qnt;

  //}SOLDADOS;
typedef ELEMENTO* PONT;

typedef struct {
    PONT cabeca;
}LISTA;


// fila de nomes
//incialização fila


// soldados em circulo a partir de uma lista circular

void inicializarCirculo(LISTA * l){
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
};

PONT buscaSentinela(LISTA * l, TIPOCHAVE ch){
PONT pos = l->cabeca->prox;
l->cabeca->reg.chave =ch;
while (pos->reg.chave !=ch){
    pos= pos->prox;
}
if(pos!=l->cabeca){
    return pos;
}
    return NULL;
}

//inserção
PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant) {
    *ant = l->cabeca;
    PONT atual = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while (atual->reg.chave<ch) {
        *ant = atual;
        atual = atual->prox;
    }
    if (atual != l->cabeca && atual->reg.chave == ch) return atual;
    return NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
    PONT ant, i;
    i = buscaSeqExc(l,reg.chave,&ant);
    if (i != NULL) return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    i->prox = ant->prox;
    ant->prox = i;
    return true;
}
int main() {
 // definir numero de soldados

    int qnt ;
    char nome[30];
    // Pega o número de soldados e declara seus nomes
    printf("Escolha o número de soldados do seu círculo: ");
    scanf("%i", &qnt );
    for (int i = 0; i < qnt; ++i) {
        printf("Digite o nome do Soldado :");
        scanf ("%s",nome);
        inserirElemListaOrd();
    }


}