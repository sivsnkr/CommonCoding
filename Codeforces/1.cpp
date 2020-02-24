#include<stdio.h>
int k[8],a,b,c,r;
void f(int n){
    if(n==8){
        int h=0,A=0,B=0,C=0;
        for(int i=1;i<8;i++){
            h+=k[i];
            A+=k[i]*(i&1);
            B+=k[i]*((i&2)>>1);
            C+=k[i]*((i&4)>>2);
        }
        if(A<=a&&B<=b&&C<=c&&r<h)r=h;
        return;
    }
    k[n]=0;
    f(n+1);
    k[n]=1;
    f(n+1);
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        r=0;
        f(1);
        printf("%d\n",r);
    }
}