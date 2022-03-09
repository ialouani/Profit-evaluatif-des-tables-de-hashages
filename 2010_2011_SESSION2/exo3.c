#include<stdio.h>
#include<stdlib.h>
#include "./link.h"

typedef int(*egaux)(void*,void*);

int equals(void* p1, void* p2){
  if(p1!=NULL && p2!=NULL) return *(int*)p1-*(int*)p2==0;
  else return 0;
}
struct lelement* get_cursor_started(struct lelement* begin){
  return begin;
}


int equals2(void* p, void* pp){
  return p-pp==0;
}

int has_cursor_next(void* cursor,void* end,egaux egalite2){
  return !(egalite2(cursor,end));
}


void* update_cursor(void* cursor){
  return ((struct lelement*)cursor)->next;//attention,void*!..
}
void* data_get_cursor(void* cursor){
  if(cursor!=NULL) return ((struct lelement*)cursor)->data;
}


void reset_cursor(void* curseur,void* begin){
  curseur=begin;
}

int nbr_occurences(struct lelement* begin, struct lelement* end, void* sdata,egaux egalite){
  int cpt=0;
  struct lelement* cursor=get_cursor_started(begin);
  while(has_cursor_next(cursor,end,equals2)){//<=>cursor!=NULL.
    void* data=data_get_cursor(cursor);
    if(egalite(data,sdata)) cpt++;//ici genericite specialisee en $2=<Object>::
    //equals.
    cursor=update_cursor(cursor);
  }
  //  if(equals2(cursor,end) && egalite(data_get_cursor(cursor),sdata)) cpt++;
  //elle nous a cre des problemes de segmentation pour rien.
  //reset_cursor(cursor,begin);
  //a la sortie: cursor==end==NULL, pas d'existence d'un certain ->next champ('s).///
  //free(cursor);////cursor en get_started prend la valeur begin
  //une initialisation d'instance en prototype non retour de void
  //impose que le curseur soit une reference initialement a la 1ere capsule
  //soit begin en lui-meme de type: STRUCT LELEMENT*.
  return cpt;
} 

int llm_nb_occurence(struct lelement *begin, struct lelement *end, void *sdata){
  int cpt=0;
  while(begin!=end){
    if(*(int*)begin->data==*(int*)sdata) cpt++;
    begin=begin->next;
  }
  return cpt;
}



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
  struct link l;
  l.head=&u;l.tail=&q;//l.curseur=&u;
  int a=3;
  printf("Pour la liste chainee avec le nombre 3: %d\n",llm_nb_occurence(&u,NULL,&a));
  
  printf("Pour le tableau avec le nombre 3: %d\n",rry_nb_occurence(trois,trois+3,4,&a));
  printf("Pour la liste chainee avec le nombre 3(g++): %d\n",llm_nb_occurence2(&u,NULL,&a,equals));
  printf("Pour le tableau avec le nombre 3(g++): %d\n------------------\n\n",rry_nb_occurence2(trois,trois+3,4,&a,equals));
  printf("Pour la liste chainee avec le nombre 3: %d\n",nbr_occurences(&u,NULL,&a,equals));
  //free(l.curseur);
 return 0;
}
