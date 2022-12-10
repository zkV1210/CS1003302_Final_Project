#include <stdio.h>

int arrayinput(int arrayf[][6],int arrayb[][6],int in[],int len);
int arraystandardization(int array[],int len);
int decoding(int array[][6],int len,int ans[]);
void printans(int ans[],int len,int CKlong);
int computing(int ans[],int len);
int checkCK(int ans[],int len);

int main(){
    int widthsf[25][6],widthsb[25][6],in[150],ansf[25],ansb[25];
    int length = 1, input = 0,f=0,b=0;
    for (int i = 0;i<25;i++){
        for (int n = 0;n<6;n++){
            widthsf[i][n] = -1;
            widthsb[i][n] = -1;
        }
    }
    for (int i = 0;i<25;i++){
        ansf[i] = -1;
        ansb[i] = -1;
    }
    scanf("%d",&length);
    
    input = arrayinput(widthsf,widthsb,in,length);

    if (input==0){
        f = decoding(widthsf,length,ansf);
        b = decoding(widthsb,length,ansb);
        if (f==1&&b==1){
            printf("bad code\n");
        }else{
            f = computing(ansf,length);
            b = computing(ansb,length);
            if (f==b&&f==1){
                printf("bad code\n");
            }
        }
    }else {
        printf("bad code\n");
    }
}

int arrayinput(int arrayf[][6],int arrayb[][6],int in[],int len){
    int arraystandardization(int array[],int len);
    int now = 0, stdz=0;;
    for (int i =0;i<len;i++){
        scanf("%d",&in[i]);
    }
    stdz = arraystandardization(in,len);
    if (stdz){
        return 1;
    }
    for (int i = 0 ; i<len/6+1;i++){
        for (int n =0;n<6;n++){
            if (i!=len/6||n!=5){
                arrayf[i][n]=in[now];
                now++;
            }
        }
    }
    now--;
    for (int i = 0 ; i<len/6+1;i++){
        for (int n =0;n<6;n++){
            if (i!=len/6||n!=5){
                arrayb[i][n]=in[now];
                now--;
            }
        }
    }
    return 0;
}
int arraystandardization(int array[],int len){
    float narrow = 0,a=0,b=0;
    int now =0;
    while (narrow==0){
        a = array[now];
        b = array[now+1];
        if (a*2.05>b&&a*1.95<b){
            narrow = a;
        }else if (b*2.05>a&&b*1.95<a){
            narrow = b;
        }
        now++;
        if (now==6){
            return 1;
        }
    }
    for (int i = 0;i<len;i++){
        if (array[i]<=narrow*1.05&&array[i]>=narrow*0.95){
            array[i] = 0;
        }else if(array[i]<=narrow*2.1&&array[i]>=narrow*1.9){
            array[i] = 1;
        }else{
            return 1;
        }
    }
    return 0;
}
int decoding(int array[][6],int len,int ans[]){
    for (int i = 0 ; i<len/6+1 ;i++){
        if (array[i][0]==1&&array[i][1]==0&&array[i][2]==0&&array[i][3]==0&&array[i][4]==1){
            ans[i]=0;
        }else if (array[i][0]==1&&array[i][1]==1&&array[i][2]==0&&array[i][3]==0&&array[i][4]==0){
            ans[i]=1;
        }else if (array[i][0]==0&&array[i][1]==0&&array[i][2]==1&&array[i][3]==0&&array[i][4]==1){
            ans[i]=2;
        }else if (array[i][0]==0&&array[i][1]==1&&array[i][2]==0&&array[i][3]==0&&array[i][4]==1){
            ans[i]=3;
        }else if (array[i][0]==0&&array[i][1]==1&&array[i][2]==1&&array[i][3]==0&&array[i][4]==0){
            ans[i]=4;
        }else if (array[i][0]==1&&array[i][1]==0&&array[i][2]==0&&array[i][3]==1&&array[i][4]==0){
            ans[i]=5;
        }else if (array[i][0]==0&&array[i][1]==0&&array[i][2]==0&&array[i][3]==1&&array[i][4]==1){
            ans[i]=6;
        }else if (array[i][0]==1&&array[i][1]==0&&array[i][2]==1&&array[i][3]==0&&array[i][4]==0){
            ans[i]=7;
        }else if (array[i][0]==1&&array[i][1]==0&&array[i][2]==0&&array[i][3]==0&&array[i][4]==0){
            ans[i]=8;
        }else if (array[i][0]==0&&array[i][1]==0&&array[i][2]==0&&array[i][3]==0&&array[i][4]==1){
            ans[i]=9;
        }else if (array[i][0]==0&&array[i][1]==0&&array[i][2]==1&&array[i][3]==0&&array[i][4]==0){
            ans[i]=10;
        }else if (array[i][0]==0&&array[i][1]==0&&array[i][2]==1&&array[i][3]==1&&array[i][4]==0){
            if (i!=0&&i!=len/6){
                return 1;
            }else{
                ans[i]=11;
            }
        }else {
            return 1;
        }
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
int computing(int ans[],int len){
    int checkCK(int ans[],int len);
    void printans(int ans[],int len,int CKlong);
    int CK=0;
    if(ans[0]==11&&ans[len/6]==11){
        CK = checkCK(ans,len/6);
        if (CK==0){
            printf("bad C\n");
        }else if (CK==1){
            printf("bad K\n");
        }else{
            printans(ans,len,CK);
        }
        return 0;
    }else{
        return 1;
    }
}

int checkCK(int ans[],int len){
    int C2=0,C3=0,C4=0,Clong=0,K2=0,K3c=0,K3k=0,K4=0,K3=0;
    for (int i = 1;i<len-2;i++){
        C2=C2+((len-3-i)%10+1)*ans[i];
        K2=K2+((len-2-i)%9+1)*ans[i];
        if (i<len-4){
            C4=C4+((len-5-i)%10+1)*ans[i];
            K4=K4+((len-4-i)%9+1)*ans[i];
        }
        if(i<len-3){
            C3=C3+((len-4-i)%10+1)*ans[i];
            K3=K3+((len-3-i)%9+1)*ans[i];
        }
    }
    K2=(K2+ans[len-2])%11;
    K3c=(K3+10)%11;
    K3k=(K3+ans[len-3])%11;
    K4=(K4+10)%11;
    C2=C2%11;
    C3=C3%11;
    C4=C4%11;
    printf("C:%d %d %d\n",C2,C3,C4);
    printf("K:%d %d %d %d\n",K2,K3c,K3k,K4);
    if(C2==ans[len-2]&&K2==ans[len-1]){
        return 2;
    }else if(C3==10&&ans[len-2]==0&&ans[len-3]==1&&K3c==ans[len-1]){
        return 3;
    }else if(K3k==10&&ans[len-1]==0&&ans[len-2]==1&&C3==ans[len-3]){
        return 3;
    }else if(C4==10&&K4==10&&ans[len-3]==0&&ans[len-4]==1&&ans[len-1]==0&&ans[len-2]==1){
        return 4;
    }else if(C2==ans[len-2]){
        return 1;
    }else if(C3==10&&ans[len-2]==0&&ans[len-3]==1){
        return 1;
    }else if(C3==ans[len-3]){
        return 1;
    }else{
        return 0;
    }
}
void printans(int ans[],int len,int CKlong){
    for(int i =0;i<len/6-CKlong;i++){
        switch(ans[i]) {
            case 11:
                //do nothing
                break;
            case 10:
                printf("-");
                break;
            default:
                printf("%d",ans[i]);
                break;
        }
    }
    printf("\n");
}