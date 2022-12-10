#include <stdio.h>
void convert(int width[][6],int in[],int len,int *flen);
void countCK(int in[],int len);
int main(){
    int width[25][6],in[25],length = 0,output[150];
    int finallen;
    for (int i =0;i<25;i++){
        in[i]=11;
    }
    scanf("%d",&length);
    for (int i =1;i<=length;i++){
        scanf("%d",&in[i]);
    }
    countCK(in,length);
    convert(width,in,length,&finallen);
    int now = 1;
    for (int i = 0;i<finallen;i++){
        for (int n =0;n<6;n++){
            if (i!=finallen-1||n!=5){
                printf("%d ",width[i][n]);
            }
            now++;
        }
        printf("\n");
    }
    printf("%d",now-2);
}
void countCK(int in[],int len){
    int C=0,K=0;
    for(int i = 1;i<=len;i++){
        C=C+((len-i)%10+1)*in[i];
        K=K+((len+1-i)%9+1)*in[i];
    }
    in[len+1]=C%11;
    in[len+2]=(K+C%11)%11;
    printf("C:%d K:%d\n",in[len+1],in[len+2]);
}
void convert(int width[][6],int in[],int len,int *flen){
    int final = 0;
    for (int i = 0;i<=len;i++){
        if(in[i]==0){
            final++;
            width[i][0]=20;
            width[i][1]=10;
            width[i][2]=10;
            width[i][3]=10;
            width[i][4]=20;
            width[i][5]=10;
        }else if(in[i]==1){
            final++;
            width[i][0]=20;
            width[i][1]=20;
            width[i][2]=10;
            width[i][3]=10;
            width[i][4]=10;
            width[i][5]=10;
        }else if(in[i]==2){
            final++;
            width[i][0]=10;
            width[i][1]=10;
            width[i][2]=20;
            width[i][3]=10;
            width[i][4]=20;
            width[i][5]=10;
        }else if(in[i]==3){
            final++;
            width[i][0]=10;
            width[i][1]=20;
            width[i][2]=10;
            width[i][3]=10;
            width[i][4]=20;
            width[i][5]=10;
        }else if(in[i]==4){
            final++;
            width[i][0]=10;
            width[i][1]=20;
            width[i][2]=20;
            width[i][3]=10;
            width[i][4]=10;
            width[i][5]=10;
        }else if(in[i]==5){
            final++;
            width[i][0]=20;
            width[i][1]=10;
            width[i][2]=10;
            width[i][3]=20;
            width[i][4]=10;
            width[i][5]=10;
        }else if(in[i]==6){
            final++;
            width[i][0]=10;
            width[i][1]=10;
            width[i][2]=10;
            width[i][3]=20;
            width[i][4]=20;
            width[i][5]=10;
        }else if(in[i]==7){
            final++;
            width[i][0]=20;
            width[i][1]=10;
            width[i][2]=20;
            width[i][3]=10;
            width[i][4]=10;
            width[i][5]=10;
        }else if(in[i]==8){
            final++;
            width[i][0]=20;
            width[i][1]=10;
            width[i][2]=10;
            width[i][3]=10;
            width[i][4]=10;
            width[i][5]=10;
        }else if(in[i]==9){
            final++;
            width[i][0]=10;
            width[i][1]=10;
            width[i][2]=10;
            width[i][3]=10;
            width[i][4]=20;
            width[i][5]=10;
        }else if(in[i]==10)
        {   final++;
            width[i][0]=10;
            width[i][1]=10;
            width[i][2]=20;
            width[i][3]=10;
            width[i][4]=10;
            width[i][5]=10;
        }else if(in[i]==11){
            final++;
            width[i][0]=10;
            width[i][1]=10;
            width[i][2]=20;
            width[i][3]=20;
            width[i][4]=10;
            width[i][5]=10;
        }
    }
    int now = len+1;
    for (int i=len+1;i<=len+3;i++){
        if(in[i]==0){
            final++;
            width[now][0]=20;
            width[now][1]=10;
            width[now][2]=10;
            width[now][3]=10;
            width[now][4]=20;
            width[now][5]=10;
            now++;
        }else if(in[i]==1){
            final++;
            width[now][0]=20;
            width[now][1]=20;
            width[now][2]=10;
            width[now][3]=10;
            width[now][4]=10;
            width[now][5]=10;
            now++;
        }else if(in[i]==2){
            final++;
            width[now][0]=10;
            width[now][1]=10;
            width[now][2]=20;
            width[now][3]=10;
            width[now][4]=20;
            width[now][5]=10;
            now++;
        }else if(in[i]==3){
            final++;
            width[now][0]=10;
            width[now][1]=20;
            width[now][2]=10;
            width[now][3]=10;
            width[now][4]=20;
            width[now][5]=10;
            now++;
        }else if(in[i]==4){
            final++;
            width[now][0]=10;
            width[now][1]=20;
            width[now][2]=20;
            width[now][3]=10;
            width[now][4]=10;
            width[now][5]=10;
            now++;
        }else if(in[i]==5){
            final++;
            width[now][0]=20;
            width[now][1]=10;
            width[now][2]=10;
            width[now][3]=20;
            width[now][4]=10;
            width[now][5]=10;
            now++;
        }else if(in[i]==6){
            final++;
            width[now][0]=10;
            width[now][1]=10;
            width[now][2]=10;
            width[now][3]=20;
            width[now][4]=20;
            width[now][5]=10;
            now++;
        }else if(in[i]==7){
            final++;
            width[now][0]=20;
            width[now][1]=10;
            width[now][2]=20;
            width[now][3]=10;
            width[now][4]=10;
            width[now][5]=10;
            now++;
        }else if(in[i]==8){
            final++;
            width[now][0]=20;
            width[now][1]=10;
            width[now][2]=10;
            width[now][3]=10;
            width[now][4]=10;
            width[now][5]=10;
            now++;
        }else if(in[i]==9){
            final++;
            width[now][0]=10;
            width[now][1]=10;
            width[now][2]=10;
            width[now][3]=10;
            width[now][4]=20;
            width[now][5]=10;
            now++;
        }else if(in[i]==10){
            final++;
            width[now][0]=20;
            width[now][1]=20;
            width[now][2]=10;
            width[now][3]=10;
            width[now][4]=10;
            width[now][5]=10;
            now++;
            final++;
            width[now][0]=20;
            width[now][1]=10;
            width[now][2]=10;
            width[now][3]=10;
            width[now][4]=20;
            width[now][5]=10;
            now++;
        }else if(in[i]==11){
            final++;
            width[now][0]=10;
            width[now][1]=10;
            width[now][2]=20;
            width[now][3]=20;
            width[now][4]=10;
            width[now][5]=10;
            now++;
        }
    }
    *flen = final;
}
