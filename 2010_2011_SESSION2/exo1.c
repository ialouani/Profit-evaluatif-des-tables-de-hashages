#include"link.h"
#include<stdio.h>
#include<stdlib.h>

int llm_nb_occurence(struct lelement *begin, struct lelement *end, void *sdata){
  struct lelement* tmp=begin;
  int compteur=0;
  while(tmp!=end){
    if(equals(sdata,tmp->data)){
      compteur++;
      tmp=tmp->next;}
    else{
      tmp=tmp->next;
    }}
  return compteur;
}

int equals(void* p1, void* p2){
  return *(int*)p1==*(int*)p2;//stockage de valeurs pointees de type INT.
}
  
int main(){
  int b1=1;int b2=2;int b3=3;int b4=4;int b5=5;
  struct lelement elmnt1={&b1,NULL};
  struct lelement elmnt2={&b5,&elmnt1};
  struct lelement elmnt3={&b4,&elmnt2};
  struct lelement elmnt4={&b3,&elmnt3};
  struct lelement elmnt5={&b1,&elmnt4};
  struct lelement elmnt6={&b2,&elmnt5};
  struct lelement elmnt7={&b1,&elmnt6};
  int a=1;
  printf("%d\n\n",llm_nb_occurence(&elmnt7,elmnt1.next,&a));
   int trois [] = {3 , 47 , 3 , 47};
  struct lelement q = {& trois [3] , NULL };
  struct lelement t = {& trois [2] , & q };
  struct lelement d = {& trois [1] , & t };
  struct lelement u = {& trois [0] , & d };
  int aa=3;
  printf("Pour la liste chainee avec le nombre 3: %d\n",llm_nb_occurence(&u,NULL,&aa));
  return 0;
}
