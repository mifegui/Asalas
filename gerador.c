#include<stdio.h>
#include<stdlib.h>
#include"asalas.h"
sala* sala_gerar_certos(sala *atual, int  const *codigo, int pos){
// Gera a proxima sala certa de acordo com o codigo, chama-se novamente com a proxima sala e a proxima posicao do codigo. Retorna a ultima sala
	if (codigo[pos] == ESQUERDA){
		sala_gerar(&(atual)->esquerda,atual,0);
		return sala_gerar_certos(atual->esquerda, codigo, pos+1);
	}else if(codigo[pos] == DIREITA){
		sala_gerar(&(atual)->direita,atual,0);
		return sala_gerar_certos(atual->direita,codigo,pos+1);
	}else if(codigo[pos] == MEIO){
		sala_gerar(&(atual)->meio,atual,0);
		return sala_gerar_certos(atual->meio,codigo,pos+1);
	}else{
		return atual;
	}
}
void sala_gerar(sala **atual, sala *anterior, int boolerrada){
// Gera a sala atual, coloca tras apontando pra anterior, e coloca as outras em 0. A boolerrada indica se a sala eh uma das certas(0), ou uma das erradas(1). Se for uma errada gera qual dos caminhos vai ser a sala certa aleatoriamente, a sala certa e esse caminho (que apontam pra mesma sala) apontam pra salainicial/raiz.
	*atual =  malloc(sizeof(sala));
	(*atual)->direita = 0;
	(*atual)->esquerda = 0;
	(*atual)->meio = 0;
	(*atual)->tras = anterior;
	(*atual)->errada = boolerrada;
	sala *paraRaiz = *atual;

	if (boolerrada == 1){
		int salaAleatoria = (rand() % 3) +1;
		while (paraRaiz->tras != 0){
			paraRaiz = paraRaiz->tras;
		}
		(*atual)->salaCerta = paraRaiz;
		if (salaAleatoria == ESQUERDA){
			(*atual) ->esquerda = paraRaiz;
		}
		if (salaAleatoria == DIREITA){
			(*atual)->direita = paraRaiz;
		}
		if (salaAleatoria == MEIO){
			(*atual)->meio = paraRaiz;
		}
	}
}
