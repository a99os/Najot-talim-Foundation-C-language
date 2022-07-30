#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


void chiqar();
void spaceall();
void game();
void check();
void rando();
void cleaar(int a,int b,int c, int d);

char array[20][20];
int x=9,y=9,n,m;
int w=1,z=1,d=1,f=0;

int main(){
    srand(time(NULL));

    spaceall();
    array[x][y]='O';
    chiqar();
    game();



    return 0;
}
void chiqar(){
    system("clear");
    printf("\t \033[0;31m *** SNAKE GAME ***\033[0;37m\n");
    printf("\033[0;33mscore: %d\t O-snake\t$-frog\033[0;37m\n",d-1);
    printf("-------------------------------------------\n");
    for(int i=0;i<20;i++){
        printf("| ");
        for(int j=0;j<20;j++){
            printf("%c ",array[i][j]);
        }
        printf("|\033[0;36m-%d\n\033[0;37m",i+1);
    }
    printf("-------------------------------------------\n ");
    for(int i=0;i<20;i++)
        if(i==9 || i==19)
            printf("\033[0;36m %d\033[0;37m",0);
        else    
            printf("\033[0;36m %d\033[0;37m",i%10+1);
    puts("");
}
void spaceall(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            array[i][j]='.';
        }
    }
}
void game(){

    while(1){
        rando();
        printf("\033[0;33mQator kiriting: \033[0;3777m");
        scanf(" %d",&n);
        printf("\033[0;33mUstunni kiriting: \033[0;37m");
        scanf(" %d",&m);
        check();

            
    }
}
void check(){
    if(n-1<x){
        for(int i=x,u=y+d,t=y-d;i>=n-1;i--){
            if(array[i][y]=='$')    
                d++;
            array[i][y]='O';
            if(i+d<20)
                array[i+d][y]='.';
            if(u>0 && u<20)
                array[x][u]='.';
            if(u>0 && u<20)
                array[x][t]='.';
                t++;
                u--;
            chiqar();
            sleep(1);
            cleaar(x,y,n-1,m-1);
        }
        x=n-1;
    }
    else if(n-1>x){
        for(int i=x,u=y+d,t=y-d;i<=n-1;i++){
            if(array[i][y]=='$')
                d++;
            array[i][y]='O';
            if(i-d>=0)
                array[i-d][y]='.';
            if(u>0 && u>20)
                array[x][u]='.';
            if(t>0 && t<20)
                array[x][t]='.';
                t++;
                u--;
            chiqar();
            sleep(1);
            cleaar(x,y,n-1,m-1);
        }
        x=n-1;
    }
    if(m-1<y){
        for(int i=y,u=x+d,t=x-d;i>=m-1;i--){
            if(array[x][i]=='$')
                d++;
            array[x][i]='O';
            if(i+d<20)
            array[x][i+d]='.';
            if(u>0 && u<20)
                array[u][y]='.';
            if(t>0 && t<20)
                array[t][y]='.';
            u--;
            t++;
            chiqar();
            sleep(1);
            cleaar(x,y,n-1,m-1);
        }
        y=m-1;
    }
    else if(m-1>y){
        for(int i=y,u=x+d,t=x-d;i<=m-1;i++){
            if(array[x][i]=='$')
                d++;
            array[x][i]='O';
            if(i-d>=0)
                array[x][i-d]='.';
            if(u>0 && u<20)
                array[u][y]='.';
            if(t>0 && t<20)
                array[t][y]='.';
            u--;
            t++;
            chiqar();
            sleep(1);
            cleaar(x,y,n-1,m-1);
        }
        y=m-1;
    }
}
void rando(){

    if(array[w][z]!='$'){
        while(1){ 
            w=rand()%20;
            z=rand()%20;
            if(array[w][z]=='.'){
                array[w][z]='$';
                break;
            }
        }

        chiqar();
    }
        
}
void cleaar(int a,int b, int c, int d){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(i!=a&& j!=b && i!=c&& j!=d && array[i][j]!='.' && array[i][j]!='$')
                array[i][j]='.';
        }
    }
}
