#include <stdio.h>
#define ESQUERDA 1
#define DIREITA 0

char* boatpos(int barco);
void * malloc (size_t n);

struct {
  int canibal;
  int jesuita;
  int barco;
} typedef statusAtual;

struct {
  statusAtual status;
  void * parent;
  void * proximo;
} typedef node;

struct {
  int canibalE;
  int missionarioE;
} typedef margerEsquerda;

struct {
  int canibalD;
  int missionarioD;
} typedef margerDireita;


statusAtual  suc1(statusAtual);
statusAtual  suc2(statusAtual);
statusAtual  suc3(statusAtual);
statusAtual  suc4(statusAtual);
statusAtual  suc5(statusAtual);


void push(statusAtual status, node * current);
node * solve(statusAtual init, node * parent);
node * frente;
node * volta;
node * inicio;
node * contarMargem; //////////////////////////////////////////////////////////////////////////////////////
void exibirsolucao(node * solucao);

int main() {

  statusAtual init; //Status Inicial
  init.canibal = 0;
  init.jesuita = 0;
  init.barco = DIREITA;

  margerDireita margemD;
  margerEsquerda margemE;
  margemD.canibalD = 3;
  margemD.missionarioD = 3;

  margemE.canibalE = 0;
  margemE.missionarioE = 0;


  node * solucao;

  if (solucao = solve(init,NULL))
    {
      printf("Solucao para Jesuitas e Canibais, mostra a solução passo a passo para a resolucao do problema \n");
      printf("SOLUCAO PARA O PROBLEMA DOS JESUITAS E CANIBAIS\n");

      exibirsolucao(solucao);
    }
  else
    printf("Nao ha solucao solucao.\n");

  node * cleanup = inicio;
  while (cleanup != NULL)
    {
      node * tmp;
      tmp = cleanup;
      cleanup = cleanup->proximo;
      free(tmp);
    }
}

void exibirsolucao(node * solucao) {
  int canibalESQ = 3;
  int canibalDIR = 0;
  int jesuitaESQ = 3;
  int jesuitaDIR = 0;


  if (solucao->parent != NULL)
    exibirsolucao(solucao->parent);
    int primeiraViagem = 0;
    if (((solucao->status).canibal) == primeiraViagem && ((solucao->status).jesuita) == primeiraViagem ) {
            primeiraViagem = 9;
            printf("%d canibal(is) e %d jesuita(s) BARCO: %sireita\n",(solucao->status).canibal,(solucao->status).jesuita, boatpos((solucao->status).barco));
    } else {
        if ((((solucao->status).canibal) && ((solucao->status).jesuita)) == 3) {

        } else {
        {
        if( 0 == strcmp(boatpos((solucao->status).barco), "E")) {
       printf("%d canibal(is) e %d jesuita(s) BARCO: %ssquerda\n",(solucao->status).canibal,(solucao->status).jesuita, boatpos((solucao->status).barco));

       } else {
        printf("%d canibal(is) e %d jesuita(s) BARCO: %sireita\n",(solucao->status).canibal,(solucao->status).jesuita, boatpos((solucao->status).barco));
       }
    }
    }
    }

}

char* boatpos(int barco)
{
  char * retval = (char *) malloc(2);
  retval[0] = barco ? 'E' : 'D';
  retval[1] = '\0';
  return retval;
}

int forbidden(statusAtual current) {
  if
    ((current.canibal > current.jesuita && current.jesuita != 0)
     ||
     (current.jesuita > current.canibal && current.jesuita !=3)) {

    return 1;
  }
  return 0;
}

int goal(statusAtual * current)
{
  if ((current->canibal == 3)
      &&
      (current->jesuita == 3)
      &&
      (current->barco == ESQUERDA))
    {
      return 1;
    }
  else
    return 0;
}






statusAtual suc1(statusAtual status)
{

  if (status.barco == ESQUERDA) {
    if (status.canibal > 0) {
      (status.canibal)--;
      status.barco = DIREITA;
    }
  }

  else if (status.barco == DIREITA) {
    if ((status.canibal) < 3) {
      (status.canibal)++;
      status.barco = ESQUERDA;
    }
  }
  return status;
}

statusAtual suc2(statusAtual status)
{

  if (status.barco == ESQUERDA) {
    if (status.canibal > 1) {
      (status.canibal)-=2;
      status.barco = DIREITA;

    }
  }

  else if (status.barco == DIREITA) {
    if ((status.canibal) < 2) {
      (status.canibal)+=2;
      status.barco = ESQUERDA;
    }
  }
  return status;

}

statusAtual suc3(statusAtual status)
{

  if (status.barco == ESQUERDA) {
    if (status.jesuita > 0) {
      (status.jesuita)--;
      status.barco = DIREITA;
    }
  }

  else if (status.barco == DIREITA) {
    if ((status.jesuita) < 3) {
      (status.jesuita)++;
      status.barco = ESQUERDA;
    }
  }
  return status;
}

statusAtual suc4(statusAtual status)
{
  if (status.barco == ESQUERDA) {
    if (status.jesuita > 1) {
      (status.jesuita)-=2;
      status.barco = DIREITA;
    }
  }

  else if (status.barco == DIREITA) {
    if ((status.jesuita) < 2) {
      (status.jesuita)+=2;
      status.barco = ESQUERDA;
    }
  }

  return status;
}


statusAtual suc5(statusAtual status)
{

  if (status.barco == ESQUERDA) {
    if ((status.jesuita > 0) && (status.canibal > 0)) {
      (status.jesuita)--;
      (status.canibal)--;
      status.barco = DIREITA;
    }
  }

  else if (status.barco == DIREITA) {
    if ( (status.jesuita) < 3  && (status.canibal)< 3 ) {
      (status.jesuita)++;
      (status.canibal)++;
      status.barco = ESQUERDA;
    }
  }

  return status;
}

int vazio();
node * dequeue();
node * solve(statusAtual status, node * parent)
{

  push(status , parent);
  if (goal(&(frente->status)))
      return frente;
  else
    {

      while (!vazio()){

	if (goal(&(frente->status)))
	  return frente;
	else {

	  if (!forbidden(suc1(frente->status))) push(suc1(frente->status), frente);
	  if (!forbidden(suc2(frente->status))) push(suc2(frente->status), frente);
	  if (!forbidden(suc3(frente->status))) push(suc3(frente->status), frente);
	  if (!forbidden(suc4(frente->status))) push(suc4(frente->status), frente);
	  if (!forbidden(suc5(frente->status))) push(suc5(frente->status), frente);

	}
	dequeue();
      }
    }

}


node * dequeue()
{
  frente=frente->proximo;
  return frente;
}

int vazio() {
  return (frente==NULL)?1:0;
}


int equals(statusAtual lhs, statusAtual rhs);
void push(statusAtual status, node * parent)
{

  node * t;
  for(t=inicio;t!=NULL;t=t->proximo)
    if (equals(status,t->status)) return;

  node * new = (node *) malloc(sizeof(node));
  (new->status).canibal=status.canibal;
  (new->status).jesuita=status.jesuita;

  (new->status).barco=status.barco;
  new->parent = parent;

  if (frente == NULL && volta == NULL) {

    new->proximo = NULL;
    frente = volta = inicio = new;
  }
  else
    {
      new->proximo = NULL;
      volta->proximo = new;
      volta = new;
    }

}

int equals(statusAtual lhs, statusAtual rhs)
{
  if ((lhs.canibal == rhs.canibal)
      &&
      (lhs.jesuita == rhs.jesuita)
      &&
      (lhs.barco == rhs.barco))
    {
      return 1;
    }
  else
    return 0;

}

