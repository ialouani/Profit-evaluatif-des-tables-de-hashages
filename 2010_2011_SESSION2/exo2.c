#include<stdio.h>
#include<stdlib.h>

struct tab{
  void** t;
};

int equals(void* p1, void* p2){
  return *(int*)p1-*(int*)p2==0;
}

int rry_nb_occurence(void *begin, void *end, size_t esize, void *sdata){
  void* tmp=begin;
  int compteur=0;
  while(tmp!=end){
    if(equals(tmp,sdata)) compteur++;
    tmp+=esize;
  }
  if(equals(end,sdata)) compteur++;
  return compteur;
}

int main(){
  void** t=(void**)malloc(sizeof(int*)*6);
  int a=1;int b=2;int c=1;int d=3;int e=4;int f=1;
  t[0]=&a;t[2]=&c;t[4]=&e;
  t[1]=&b;t[3]=&d;t[5]=&f;
  int g=1;
  printf("%d\n\n",rry_nb_occurence(*t,*(t+5),4,&g));
  printf("%d\n\n",rry_nb_occurence(*t,*(t+5),4,&e));
  printf("%d\n\n",rry_nb_occurence(*t,*(t+2),4,&g));
  int trois [] = {3 , 47 , 3 , 47};
  /*struct lelement q = {& trois [3] , NULL };
  struct lelement t = {& trois [2] , & q };
  struct lelement d = {& trois [1] , & t };
  struct lelement u = {& trois [0] , & d };*/
  int aa=3;
  printf("Pour le tableau avec le nombre 3: %d\n",rry_nb_occurence(trois,trois+3,4,&aa));
  free(t);
  return 0;
}
