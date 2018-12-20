#include<stdio.h>
#include<stdlib.h>

int balanceamento = 0;

struct no
{
 int chave;
 struct no*esquerda;
 struct no*direita;
 struct no*up;
}*raiz=NULL;


struct no*criar(int d)
{
 struct no*no_=(struct no*)malloc(sizeof(struct no));
 no_->chave=d;
 no_->esquerda=no_->direita=no_->up=NULL;
 return no_;
}


void main()
{
    int i = 0;
    do{
        printf("\n\nDigite o valor que deseja inserir na árvore. Para exibir digite 0\n");
        scanf("%i", &i);
        printf("\n");
        if(i == 0) {
            break;
        }
        inserir(i);
    } while (i != 0);
   inserir(30);

  printf("\n\nPreorder traversal of AVL tree is:");
  preordem(raiz);
  printf("\n\nINorder traversal of AVL tree is:");
  emordem(raiz);
  printf("\n\nPOSorder traversal of AVL tree is:");
  posordem(raiz);
  printf("\n");
  return;
}


void adicionar(struct no*no_,int d)
{
 struct no  *q=raiz,*r;
 if(raiz==NULL)
 {
  raiz=no_;
  printf("\nRoot no:%d is added",d);
 }
 else
 {
  while(q)
  {
   r=q;
   if(d>=q->chave)
    q=q->direita;
   else
    q=q->esquerda;
  }
  if(d>=r->chave)
  {
   r->direita=no_;
   no_->up=r;
  }
  else
  {
   r->esquerda=no_;
   no_->up=r;
  }
 }
}


struct no*obterNo(struct no*no_)
{

 while(no_)
 {
  balanceamento=obterBalanco(no_);
  if(balanceamento>1||balanceamento<-1)
  {
   return no_;

  }
  else
  no_=no_->up;
 }
 return no_;
}


int obterBalanco(struct no *no_)
{
 return obterPeso(no_->esquerda)-obterPeso(no_->direita);
}


int obterPeso(struct no*no_)
{
 int i,j;
 if(!no_)
  return 0;
 else
 {
  i=obterPeso(no_->esquerda);
  j=obterPeso(no_->direita);
  if(i>j)
   return i+1;
  else
   return j+1;
 }
}

void rotacaoDir(struct no *y)
{
    struct no *x = y->esquerda,*Temp;

    Temp = x->direita;
 if(y==raiz)
  raiz=x;
    else
    {
  if(y->up->esquerda==y)
   y->up->esquerda=x;
  else
   y->up->direita=x;
 }

    x->up = y->up;
    y->up = x;
    x->direita = y;
    y->esquerda = Temp;
    if(Temp!=NULL)
    Temp->up = x;
}


void rotacaoEsq(struct no *x)
{
    struct no *y = x->direita,*temp;

 temp = y->esquerda;

    if(x==raiz)
    {
  raiz=y;
 }else
 {
  if(x->up->esquerda==x)
   x->up->esquerda=y;
  else
   x->up->direita=y;
 }
    y->up=x->up;
    x->up=y;
    y->esquerda = x;
    x->direita = temp;
    if(temp!=NULL)
     temp->up=x;
 else
  return;
}


void balanceado(struct no*no_,int chave)
{

 if(balanceamento>1 && chave < no_->esquerda->chave)
 {
  rotacaoDir(no_);
 }else

 if(balanceamento<-1 && chave > no_->direita->chave)
 {
  rotacaoEsq(no_);
 }else

 if(balanceamento>1 && chave > no_->esquerda->chave)
 {
  rotacaoEsq(no_->esquerda);
  rotacaoDir(no_);
 }else

 if(balanceamento<-1 && chave < no_->direita->chave)
 {
  rotacaoDir(no_->direita);
  rotacaoEsq(no_);
 }
}


void inserir(int chave)
{
 struct no*no_=criar(chave),*q;
 adicionar(no_,chave);
 q=obterNo(no_);
 if(q!=NULL)
  balanceado(q,chave);
 else
  return;
}


void preordem(struct no *no_)
{
    if(no_ != NULL)
    {
        printf("%2d ", no_->chave);
        preordem(no_->esquerda);
        preordem(no_->direita);
    }
}


void emordem(struct no *no_)
{
    if(no_ != NULL)
    {
        emordem(no_->esquerda);
        printf("%2d ", no_->chave);
        emordem(no_->direita);
    }
}


void posordem(struct no *no_)
{
    if(no_ != NULL)
    {
        posordem(no_->esquerda);
        posordem(no_->direita);
        printf("%2d ", no_->chave);
    }
}

