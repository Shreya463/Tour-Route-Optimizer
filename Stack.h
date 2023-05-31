#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30
struct Stack
{
  int size;
  int top;
  int *S;
};

void create(struct Stack *st)
{
  st->size=MAX_SIZE;
  st->top=-1;
  st->S=(int*)malloc(st->size*sizeof(int));
}

void display(struct Stack st)
{
  int i;
  for(i=st.top;i>=0;i--)
    printf("%d",st.S[i]);
  printf("\n");
}

void push(struct Stack *st,int x)
{
  if(st->top==st->size-1)
    printf("Stack overflow\n");
  else
  {
    st->top++;
    st->S[st->top]=x;
  }
}

int pop(struct Stack *st)
{
  int x=-1;
  if(st->top==-1)
    printf("Stack underflow\n");
  else
  {
    x=st->S[st->top--];
  }
  return x;
}

int isEmpty(struct Stack st)
{
  if(st.top==-1)
    return 1;
  return 0;
}

int isFull(struct Stack st)
{
  return st.top==st.size-1;
}



