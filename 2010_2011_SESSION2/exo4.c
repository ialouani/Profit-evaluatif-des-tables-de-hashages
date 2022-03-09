#include<stdio.h>

struct point {
float x , y ;
};
struct segment {
struct point debut ;
struct point fin ;
};
struct segment sgm_init ( float fx , float fy ) {
struct point d = {0.0 , 0.0};
struct point f = { fx , fy };
struct segment s = {d , f };
return s ;
}
 int main(){

struct segment s = sgm_init(420.0, -67.3);
 printf("%.2f %.2f\n",s.debut.y,s.fin.y);
 printf("%.2f %.2f\n",s.debut.x,s.fin.x);
 printf("%.2f %.2f\n",s.fin.x,s.fin.y);
 return 0;
 }
