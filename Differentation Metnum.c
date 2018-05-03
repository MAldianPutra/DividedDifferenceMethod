#include <stdio.h>
#include <math.h>
double f(double x){
    return 2*x*x*x + 1;
}
double df(double x){
    return 6*x*x;
}
void fdd(){
    //(f(x+h) - f(x)) / h
    double x = 2, h = 0.25, Rte = 0.01, res = 0;
    double Tv, Te, Ae, Rae, x2, res2;
    int SD = 0;
    Tv = df(2);
    printf("h\t\tf'(x)\t\tAE\t\tRAE\t\tTE\t\tRTE\n");
    do {
        x2 = x+h;
        res2 = (f(x2) - f(x)) / h;
        Te = Tv - res2;
        Rte = fabs((Tv - res2) / Tv);
        if(res != 0){
            Ae = res - res2;
            Rae = fabs((res - res2) / res);
        }
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", h, res2, Ae, Rae, Te, Rte);
        res = res2;
        h = h/2;
    }while(Rte>0.01);
}
void cdd(){
    //(f(x+h) - f(x-h)) / 2h
    double x = 2, h = 0.25, Rte = 0.01, res = 0;
    double Tv, Te, Ae, Rae, x2, x3, res2;
    Tv = df(2);
    printf("h\t\tf'(x)\t\tAE\t\tRAE\t\tTE\t\tRTE\n");
    do {
        x2 = x+h;
        x3 = x-h;
        res2 = (f(x2) - f(x3)) / (2*h);
        Te = Tv - res2;
        Rte = fabs((Tv - res2) / Tv);
        if(res != 0){
            Ae = res - res2;
            Rae = fabs((res - res2) / res);
        }
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", h, res2, Ae, Rae, Te, Rte);
        res = res2;
        h = h/2;
    }while(Rte>0.01);
}
void bdd(){
    //(f(x) - f(x-h)) / h
    double x = 2, h = 0.25, Rte = 0.01, res = 0;
    double Tv, Te, Ae, Rae, x3, res2;
    Tv = df(2);
    printf("h\t\tf'(x)\t\tAE\t\tRAE\t\tTE\t\tRTE\n");
    do {
        x3 = x-h;
        res2 = (f(x) - f(x3)) / h;
        Te = Tv - res2;
        Rte = fabs((Tv - res2) / Tv);
        if(res != 0){
            Ae = res - res2;
            Rae = fabs((res - res2) / res);
        }
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", h, res2, Ae, Rae, Te, Rte);
        res = res2;
        h = h/2;
    }while(Rte>0.01);
}
void main(){
    int a;
    printf("=============================\n");
    printf("Tugas Metode Numeris\n");
    printf("M. Aldian Putra \n17/413906/TK/46346 \n");
    printf("=============================\n");
    printf("Select your method: \n1. Forward Divided \n2. Central Divided \n3. Backward Divided \n");
    scanf("%d", &a);
   if (a==1)/*Forward*/{
    system("cls");
    printf("=============================\n");
    printf("Forward Divided Difference\n");
    printf("=============================\n");
    fdd();
   }
   else if (a==2)/*Central*/{
    system("cls");
    printf("=============================\n");
    printf("Central Divided Difference\n");
    printf("=============================\n");
    cdd();
   }
   else if (a==3)/*Backward*/{
    system("cls");
    printf("=============================\n");
    printf("Backward Divided Difference\n");
    printf("=============================\n");
    bdd();
    }
   else {printf("Please input number between 1-3");}
}
