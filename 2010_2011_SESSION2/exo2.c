#include<stdio.h>
#include<stdlib.h>

struct tab{
  void** t;
  void** curseur;//adresse de t[0] soit adresse d'ou ptr vers le 1er void*
};
typedef int(*egaux)(void*, void*);
int equals(void* p1, void* p2){
  return *(int*)p1-*(int*)p2==0;
}
void** get_cursor_started(void* begin){
  void** cursor=malloc(sizeof(void*));*cursor=begin;
  //remplacer par cursor=&begin genere 13 erreurs en using --cours
  //comme use of unizialised value of size 8...
  return cursor;
}


int equals2(void* p, void* pp){
  return (int*)p==(int*)pp;
}

int has_cursor_next(void* cursor,void* end,egaux egalite){
  return !(equals2(cursor,end));
}


void* update_cursor(void* cursor,size_t esize){
  cursor+=esize;
  return cursor;
}

void reset_cursor(void* curseur,void* begin){
  curseur=begin;
}//&begin==&curseur(void**=TYPEOF(cursor(s->cursor en struct set*))).

int nbr_occurences(void* a, void* begin, void* end, size_t esize,egaux egalite){
  int cpt=0;
  void** cursor=get_cursor_started(begin);
  void* curseur=*cursor;
  //curseur represente begin.(pointeur vers le 1er element)<=>&begin
  //c'est pour cela *cursor=*&begin=begin<=>*CURSOR===BEGIN.
  while(has_cursor_next(curseur,end,equals2)){
    if(egalite(curseur,a)) cpt++;//egalite ca sera equals avec les *(int*)(void*)ptr.//
    curseur=update_cursor(curseur,esize);
  }
  if(equals2(curseur,end) && egalite(curseur,a)) cpt++; 
  reset_cursor(curseur,begin);
  free(cursor);
  return cpt;
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
  //test avec factorisation de code.
  void** t2=(void**)malloc(sizeof(int*)*6);
  int aa2=1;int bb=2;int cc=1;int dd=3;int ee=4;int ff=1;
  t2[0]=&aa2;t2[2]=&cc;t2[4]=&ee;
  t2[1]=&bb;t2[3]=&dd;t2[5]=&ff;
  struct tab ttt;//void** curseur_ttt=malloc(sizeof(void*));curseur_ttt=ttt.t;
  ttt.t=t2;ttt.curseur=ttt.t;
  void* begin=ttt.t[0];void* end=ttt.t[5];
  size_t esize=4;
  //printf("%d %d\n",*(*(int**)ttt.curseur),*(int*)ttt.t[0]);
  printf("%d\n---------------------",nbr_occurences(ttt.t[0],begin,end,4,equals));
  //free(curseur_ttt);
  free(ttt.t);
  return 0;
}
