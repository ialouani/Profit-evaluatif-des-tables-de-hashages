#include<stdio.h>
#include<stdlib.h>

struct point{
  float x,y;
};
struct segment {
struct point * debut ;
struct point * fin ;
};


struct segment2{
  struct point* debut;
  struct point* fin;
};
struct segment2 sgm_init ( float fx , float fy ) {
struct point d = {0.0 , 0.0};
struct point f = { fx , fy };
 struct point* dd=malloc(sizeof(*dd));
 struct point* ff=malloc(sizeof(*ff));
 //*dd=d;*dd=f;<=>relatives aux champs..///
 //affectation entre deux entites des le depart non suite a un & ou *+++%||cas>>> pour avoir le meme type.
 dd->x=d.x;dd->y=d.y;
 ff->x=f.x;ff->y=f.y;
 //il FAUT REMPLIR A LA DURE LES CHAMPS!!///
struct segment2 s = {dd , ff };
return s ;
}



//exo4: allocation automatique
//exo5: dynamique=>contrainte de soi meme faire une fonction free adaptee a un ensemble de segments par exemple pour un quadrilatere par exemple ce qui est pas le cas absent a 200% dans l'approche de l'exercice4.

//le complet sera une fonction free qui par exemple pour un struct quuadri{struct segment segments[4];] fait un free pour tous les segments entrant en jeu: for(int i=3;i=0;i--) free(segments[i]) et pas de free pour les autres car struct point est donnee par les parametres et ce qui englobe tout le struct quuadri n'est pas declaree en pointeur.
//On peut ajouter le fait qu'elle renvoie un pointeur comme ca ca serait plus facile:
//la fonction de free servirait pour decossier un carre par exemple donc dans procedure decossier(Q: quuadri): ; on aura un free des que la DONNEE A STOCKER ; ON EN A PLUS BESOIN.
//exemple~-++:
struct segment* sgm_init2(float fx, float fy){
  struct segment* sgm=(struct segment*)malloc(sizeof(struct segment));
  //sgm->debut est de type point donc pour acceder aux proprietes
    // (sgm->debut est NULL au debut)
    //il faut faure une allocation
    // =>sgm->debut:::::
    sgm->debut=malloc(sizeof(struct point));
    sgm->debut->x=0.0;
    sgm->debut->y=7.2;
 sgm->fin=malloc(sizeof(struct point));
 sgm->fin->x=9.5;
    sgm->fin->y=0.0;
    return sgm;}


    int main(){
  struct segment2 s = sgm_init(420.0, -67.3);
  //sa structure est de type {struct point* d;struct point*f};;
  printf("%.2f %.2f\n",s.debut->y,s.fin->y);
 printf("%.2f %.2f\n",s.debut->x,s.fin->x);
 printf("%.2f %.2f\n",s.fin->x,s.fin->y);
 free(s.fin);free(s.debut);
 struct segment *ss = sgm_init2(420.0, -67.3);
  //sa structure est de type {struct point* d;struct point*f};;
  printf("%.2f %.2f\n",ss->debut->y,ss->fin->y);
 printf("%.2f %.2f\n",ss->debut->x,ss->fin->x);
 printf("%.2f %.2f\n",ss->fin->x,ss->fin->y);
 free(ss->fin);free(ss->debut);free(ss);
 //inconvenient: gerer la memoire
 //i.e. une *instances de type struct segment (objet)
 //va remplir le tas donc il faut bien gerer la memoire;cest dynamique..
 //l'autre approche pourrait exploser la pile comme dans le cas de quelques
 //chainages non faites d'une facon concise et precise.
 return 0;
}
