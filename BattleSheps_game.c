#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

char user[5][5],comp[5][5],comphelp[5][5],game[10];
int qator,ustun,CH,scoreUser,scoreComp;


void Bprint();
void spaceall(char arr[5][5]);
void SetInfo();
void GetInfo();
int check(char arr[5][5], int qat,int ust);

int main(){
    srand(time(NULL));
    while(1){
        scoreUser=0;
        scoreComp=0;    
        spaceall(user);
        spaceall(comp);
        spaceall(comphelp);
        GetInfo();
        while(1){
            SetInfo();
            if(scoreUser==4){
                Bprint();
                puts("\t\t\t\t\tTabriklayman!!!\n\t\t\t\t      User g'alaba qozondi!!! ");
                break;
            }
            else if(scoreComp==4){
                Bprint();
                puts("\t\t\t\t\tTabriklayman!!!\n\t\t\t\t    Kompyuter g'alaba qozondi!!! ");
                break;
            }
        }
        printf("\t\t\t\t    Yana o'ynaysizmi? [ha/yo'q]:  ");
        scanf("%s",game);
        if(strcmp(game,"ha")!=0){
            puts("\t\t\t\t      Xayr, Salomat bo'ling!!!");
            break;
        }
    }
    return 0;
}

void Bprint(){
    system("clear");
    printf("\n\t\t\t\t\x1b[36m   *** KEMALAR JANGI GAME ***  \x1b[33m\n");
    printf("\n\t\t\t\t\x1b[33m        User  score: %d\n",scoreUser);
    printf("\t\t\t\t\t\x1b[34m-------------\n");
    for(int i=0;i<5;i++){
        printf("\t\t\t\t\t| ");
        for(int j=0;j<5;j++){
            printf("\x1b[32m%c ",user[i][j]);
        }
        printf("\x1b[34m| %d\n",i+1);
    }
    printf("\t\t\t\t\t------------\n");
    printf("\t\t\t\t\t  1 2 3 4 5 \n\x1b[33m");
    printf("\t\t\t\t      Computer score: %d\n",scoreComp);
    printf("\t\t\t\t\t\x1b[35m------------\n");
    for(int i=0;i<5;i++){
        printf("\t\t\t\t\t| ");
        for(int j=0;j<5;j++){
            printf("\x1b[31m%c ",comp[i][j]);
        }
        printf("\x1b[35m| %d\n",i+1);
    }
    printf("\t\t\t\t\t-------------  \n");
    printf("\t\t\t\t\t  1 2 3 4 5 \x1b[37m\n");

}
void spaceall(char arr[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j]=' ';
        }   
    }
}
void SetInfo(){
    while(1){
        printf("\t\t\t\t       Sizning galingiz:\n");
        printf("\t\t\t\t    Qator raqamini kiriting: ");
        scanf("%d",&qator);
        printf("\t\t\t\t    Ustun raqamini kiriting: ");
        scanf("%d",&ustun);
        qator--;
        ustun--;
        if(qator>4) CH=4;
        else if(ustun>4) CH=4;
        else CH=check(comphelp,qator,ustun);
        if(CH==0){
            comp[qator][ustun]='-';
            comphelp[qator][ustun]='-';
            Bprint();
            break;
        }
        else if(CH==1){
            comp[qator][ustun]='X';
            comphelp[qator][ustun]='X';
            scoreUser++;
            if(scoreUser==4)
                return;
            Bprint();
            break;
        }
        else if(CH==2 || CH==3){
            Bprint();
            puts("\t\t\t\t  Bu joyni tanlab bo'lgansiz");
        }
        else if(CH==4){
            Bprint();
            puts("\t\t\t\t  Xato koordinata tanladingiz");
        }


    }
    while(1){
        Bprint();
        printf("\t\t\t\t       Kompyuterni gali:\n");
        qator=rand()%5;
        ustun=rand()%5;
        CH=check(user,qator,ustun);
        if(CH==0){
            user[qator][ustun]='-';
            sleep(1);
            Bprint();
            break;
        }
        if(CH==1){
            user[qator][ustun]='X';
            sleep(1);
            scoreComp++;
            if(scoreUser==4)
                return;
            Bprint();
            break;
        }
        

        
    }
}
void GetInfo(){
    for(int i=4;i;i--){
        Bprint();
        while(1){
            printf("\t\t\t  Kemalarni joylashtiring!!!(%d ta kemangiz qoldi)\n",i);
            printf("\t\t\t\t   Qator raqamini kiriting: ");
            scanf("%d",&qator);
            printf("\t\t\t\t   Ustun raqamini kiriting: ");
            scanf("%d",&ustun);
            qator--; ustun--;
            CH=1;
            if(qator>4) CH=0;
            if(ustun>4) CH=0;
            if(CH){
                Bprint();
                if(user[qator][ustun]==' '){
                    user[qator][ustun]='*';
                    break;
                }
                else
                    puts("\t\t\t\tBu joyda kemangiz allaqachon bor!!!");
            }
            else{
                Bprint();
                puts("\t\t\t\t  Xato koordinata tanladingiz");
            }
        }
        while(1){
            qator=rand()%5; ustun=rand()%5;
            if(comphelp[qator][ustun]==' '){
                comphelp[qator][ustun]='*';
                //comp[qator][ustun]='*';
                Bprint();
                break;
            }
        }
    }
}
int check(char arr[5][5], int qat,int ust){
    if(arr[qat][ust]==' ')
        return 0;
    else if(arr[qat][ust]=='*')
        return 1;
    else if(arr[qat][ust]=='-')
        return 2;
    else if(arr[qat][ust]=='X')
        return 3;
}