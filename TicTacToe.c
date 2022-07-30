#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int Tug=0;
int tekshir(char *arr){
    if  ((arr[0]==arr[1] && arr[0] == arr[2] && arr[0]!=' ')||
         (arr[3]==arr[4] && arr[3] == arr[5] && arr[3]!=' ')||
         (arr[6]==arr[7] && arr[6] == arr[8] && arr[6]!=' ')||
         (arr[3]==arr[0] && arr[3] == arr[6] && arr[3]!=' ')||
         (arr[1]==arr[4] && arr[4] == arr[7] && arr[1]!=' ')||
         (arr[2]==arr[5] && arr[5] == arr[8] && arr[2]!=' ')||
         (arr[2]==arr[4] && arr[2] == arr[6] && arr[2]!=' ')||
         (arr[0]==arr[4] && arr[0] == arr[8] && arr[0]!=' ')) return 1;
    return 0;
}
void chiqar(char *arr){
    printf("\033[0;37m");
    printf("X va O o'yini\n");
    for (int i=0;i<3;i++){
        printf("-------------\n");
        printf("| %c | %c | %c |\n",arr[i*3],arr[i*3+1],arr[i*3+2]);
    }
        printf("-------------\n");
}
int joylax(char *arr){ 
    int a;
    bool mi=true;
    for(int count=0;mi;count++){
        system("clear");
        if(count) printf("Notog'ri amal kiritdingiz\n");
        chiqar(arr);
        printf("X dagi ishtirokchi son kiriting: ");
        scanf("%d",&a);
        switch(a){
            case 1: if (arr[0]==' '){arr[0]='X';mi=false; } break;
            case 2: if (arr[1]==' '){arr[1]='X';mi=false; } break; 
            case 3: if (arr[2]==' '){arr[2]='X';mi=false; } break;
            case 4: if (arr[3]==' '){arr[3]='X';mi=false; } break;
            case 5: if (arr[4]==' '){arr[4]='X';mi=false; } break;
            case 6: if (arr[5]==' '){arr[5]='X';mi=false; } break;
            case 7: if (arr[6]==' '){arr[6]='X';mi=false; } break;
            case 8: if (arr[7]==' '){arr[7]='X';mi=false; } break;
            case 9: if (arr[8]==' '){arr[8]='X';mi=false; } break;
        }
    }
    if (tekshir(arr)){ 
        system("clear"); 
        chiqar(arr); 
        printf("X dagi o'yinchi yutdi !!!\n");  
        return 1;}
    return 0;
}
int joylao(char *arr){
    int a;
    bool mi=true;
    for(int count=0;mi==true;count++){
        system("clear");
        if(count) printf("Notog'ri amal kiritdingiz\n");
        chiqar(arr);
        if(Tug==4){printf("Hech kim yutmadi.\n"); return Tug;} 
        printf("O dagi ishtirokchi son kiriting: ");
        scanf("%d",&a);
        switch(a){
            case 1: if (arr[0]==' '){arr[0]='O'; mi=false;}   break;
            case 2: if (arr[1]==' '){arr[1]='O'; mi=false;}   break; 
            case 3: if (arr[2]==' '){arr[2]='O'; mi=false;}   break;
            case 4: if (arr[3]==' '){arr[3]='O'; mi=false;}   break;
            case 5: if (arr[4]==' '){arr[4]='O'; mi=false;}   break;
            case 6: if (arr[5]==' '){arr[5]='O'; mi=false;}   break;
            case 7: if (arr[6]==' '){arr[6]='O'; mi=false;}   break;
            case 8: if (arr[7]==' '){arr[7]='O'; mi=false;}   break;
            case 9: if (arr[8]==' '){arr[8]='O'; mi=false;}   break;
        }

    }    
    Tug++;
    if (tekshir(arr)){ 
        system("clear");
        chiqar(arr); 
        printf("O dagi o'yinchi yutdi !!!\n");  
        return 1;
    }
    return 0;
}

int main(){
    char arr[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

    while(1){
        int max=joylax(arr);
        if(max) break;
        max= joylao(arr);
        if(max) break;
        if(max==4)
            break;
    }
    return 0;
}