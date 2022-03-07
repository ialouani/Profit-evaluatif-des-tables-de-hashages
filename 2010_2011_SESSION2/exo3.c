#include<stdio.h>
#include<stdlib.h>
#include "./link.h"

int equals(void* ptr1, void* ptr2){
  return *(int*)ptr1-*(int*)ptr2==0;
}

int llm_nb_occurence(struct lelement *begin, struct lelement *end, void *sdata){
  int cpt=0;
  while(begin!=end){
    if(*(int*)begin->data==*(int*)sdata) cpt++;
    begin=begin->next;
  }
  return cpt;
}

typedef int(*egaux)(void*,void*);

int llm_nb_occurence2(struct lelement *begin, struct lelement *end, void *sdata,egaux test){
  int cpt=0;
  while(begin!=end){
    if(test((begin->data),sdata)) cpt++;
    begin=begin->next;
  }
  return cpt;
}


int rry_nb_occurence(void *begin, void *end, size_t esize, void *sdata){
  int cpt=0;
  while(begin!=end){
    if(*(int*)begin==*(int*)sdata) cpt++;
    begin+=esize/4;
  }
  return cpt;
}

int rry_nb_occurence2(void *begin, void *end, size_t esize, void *sdata,egaux test){
  int cpt=0;
  while(begin!=end){
    if(test(begin,sdata)) cpt++;
    begin+=esize/4;
  }
  return cpt;
}


int main(){
  int trois [] = {3 , 47 , 3 , 47};
  struct lelement q = {& trois [3] , NULL };
  struct lelement t = {& trois [2] , & q };
  struct lelement d = {& trois [1] , & t };
  struct lelement u = {& trois [0] , & d };
  int a=3;
  printf("Pour la liste chainee avec le nombre 3: %d\n",llm_nb_occurence(&u,NULL,&a));
  printf("Pour le tableau avec le nombre 3: %d\n",rry_nb_occurence(trois,trois+3,4,&a));
  printf("Pour la liste chainee avec le nombre 3(g++): %d\n",llm_nb_occurence2(&u,NULL,&a,equals));
  printf("Pour le tableau avec le nombre 3(g++): %d\n",rry_nb_occurence2(trois,trois+3,4,&a,equals));
 return 0;
}
