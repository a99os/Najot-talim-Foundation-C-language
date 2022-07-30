#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
char A[9][9],X;
int N,M;

void print();
void spaceall();
int scan();
int Check();
void help();
int win();

int main(){

    spaceall();
    help();
    print();        
    while(1){
        if(scan()){
            printf("\t\tSiz g'alaba qozondingiz!!!\n");
            break;
        }
    }

    return 0;
}
void print(){
    system("clear");
    printf("\x1b[33m");
    printf("\x1b[40m");
    printf("\t\t\t     *** SUDOKU game ***\n");
    printf("\t\t     ");
    for(int j=0;j<9;j++){
            printf(" %d  ",j+1);
        }
    puts(" ");
    printf("\t\t     ");
    for(int j=0;j<9;j++){
            printf(" v  ");
        }
    puts(" ");
    for(int i=0;i<9;i++){
        printf("\t\t    ------------------------------------- \n\t\t %d->|",i+1);
        for(int j=0;j<9;j++){
            printf(" %c |",A[i][j]);
        }
        puts(" ");
    }
    puts("\t\t    ------------------------------------- ");

}
int scan(){
    for(bool mi=true;mi;){
        if(Check()) mi=false;
        else{
            puts("\t\tXato son kiritdingiz!!!");
            printf("\t\t%d-qator, %d-ustunni qaytadan kiriting: ",N,M);
            scanf(" %c",&X);
            A[N-1][M-1]=X;
            print();
        }
    }
    if (win())
        return 1;
    
    printf("\t\tQator raqamini kiriting: ");
    scanf(" %d",&N);
    printf("\t\tUstun raqamini kiriting: ");
    scanf(" %d",&M);
    if(!isdigit(A[N-1][M-1])){
        printf("\t\tSon kiriting: ");
        scanf(" %c",&X);
        A[N-1][M-1]=X;
        print();
    }
    else {
        print();
        printf("\t\t%d-qator, %d-ustun band\n",N,M);
    }
    return 0;
}
void spaceall(){
     for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            A[i][j]=' ';
}
int Check(){
    
    for (int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for (int k=0;k<9;k++){
                for(int l=0;l<9;l++){
                    if(i==k || j==l) continue;
                    if(A[i][j]==A[i][l] && A[i][j]!=' ') return 0;
                    else if(A[i][j]==A[k][j] && A[i][j]!=' ') return 0; 
                }
            }
        }
    }
    for(int w=0,c=3;w<9;w+=3){
        for(int x=3,z=0;x<10;x+=3){
            for (int i=w;i<c;i++){
                for(int j=z;j<x;j++){
                    for (int k=w;k<c;k++){
                        for(int l=z;l<x;l++){
                            if(i==k && j==l) continue;
                            if(A[i][j]==A[k][l] && A[i][j]!=' ') return 0;
                        }
                    }
                }
            }
            z+=3;
        }
        c+=3;
    }    
    return 1;
}
void help(){
    A[2][0]='4';A[3][0]='9';A[6][0]='6';A[7][0]='5';A[8][0]='2';
    A[1][1]='6';A[2][1]='9';A[4][1]='4';
    A[0][2]='3';A[3][2]='7';A[5][2]='5';A[7][2]='8';A[8][2]='9';
    A[1][3]='9';A[5][3]='4';A[7][3]='1';
    A[2][4]='8';A[2][4]='3';A[4][4]='9';A[8][4]='5';
    A[2][5]='1';A[4][5]='8';A[5][5]='7';A[6][5]='3';A[8][5]='6';
    A[0][6]='2';A[3][6]='8';A[5][6]='1';A[6][6]='9';
    A[1][7]='4';A[3][7]='6';A[7][7]='7';A[8][7]='3';
    A[1][8]='3';A[2][8]='6';A[5][8]='9';A[6][8]='5';A[7][8]='2';A[8][8]='8';
}
int win(){
    int count=0;
    for (int i = 0; i < 9; i++){
        for(int j=0;j<9;j++){
            if(A[i][j]==' ')
                count++;
        }
    }
    if(!count)
        return 1;
    return 0;
    
}

