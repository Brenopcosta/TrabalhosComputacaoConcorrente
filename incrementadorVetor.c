#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


#define NTHREADS 2

int vetor[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

typedef struct{
  int indexInicio, indexFinal;
}args;



void* olamundo(void *indices){
  int i;
  args *indicesParaThread = (args *) indices;

  for(i = indicesParaThread-> indexInicio ; i < indicesParaThread->indexFinal;i++){
  //vetor[i]=vetor[i]+1;
  printf("%d -> %d\n",vetor[i], vetor[i]+1);
  }
  pthread_exit(NULL);
}


int main(){
  pthread_t threadID[NTHREADS];
  int  t=0, i;
  printf("---Vetor nao alterado:");
  for(i=0; i<20; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");

  args *indicesParaThread1;
  args *indicesParaThread2;

  indicesParaThread1 = malloc(sizeof(args));
  if (indicesParaThread1 == NULL) {
    printf("--ERRO: malloc()\n"); exit(-1);
  }

  indicesParaThread2 = malloc(sizeof(args));
  if (indicesParaThread2 == NULL) {
    printf("--ERRO: malloc()\n"); exit(-1);
  }

  indicesParaThread1->indexInicio = 0;
  indicesParaThread1->indexFinal = 10;

  indicesParaThread2->indexInicio = 10;
  indicesParaThread2->indexFinal = 20;

  printf("---Criando a thread:%d\n", ++t);
  if(pthread_create(&threadID[0], NULL, olamundo, (void *)indicesParaThread1)){
    printf("errin na thread: 0 \n");
    exit(-1);      
  }
  printf("---Criando a thread:%d\n", ++t);
  if(pthread_create(&threadID[1], NULL, olamundo, (void *)indicesParaThread2)){
    printf("errin na thread: 1 \n");
    exit(-1);      
  }

  pthread_exit(NULL);

  free(indicesParaThread1);
  free(indicesParaThread2);
  return 0;
}