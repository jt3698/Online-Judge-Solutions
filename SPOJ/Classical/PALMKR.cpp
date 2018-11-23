#include<stdio.h>
//#define char() char_unlocked()

int answer[100][100],store[100][100],print_stack[100],idx;
int T,len,test,i,diff;
char text[101],c;

int main()
{
    T=0;
    c=getchar();
    while(c!='\n'){
        T*=10;
        T+=c-'0';
        c=getchar();
    }
    for(test=1;test<=T;test++){
        len=0;
        text[len]=getchar();
        while(text[len]!='\n'){
            store[len][len]=0;
            len++;
            text[len]=getchar();
        }
        for(diff=1;diff<len;diff++){
            for(i=0;i+diff<len;i++){
                if(text[i]==text[i+diff]){
                    store[i][i+diff]=store[i+1][i+diff-1];
                    answer[i][i+diff]=0;
                }
                else if(text[i]<text[i+diff]){
                    if(store[i+1][i+diff]<=store[i][i+diff-1]){
                        store[i][i+diff]=1+store[i+1][i+diff];
                        answer[i][i+diff]=1;
                    }
                    else{
                        store[i][i+diff]=1+store[i][i+diff-1];
                        answer[i][i+diff]=2;
                    }
                }
                else{
                    if(store[i][i+diff-1]<=store[i+1][i+diff]){
                        store[i][i+diff]=1+store[i][i+diff-1];
                        answer[i][i+diff]=2;
                    }
                    else{
                        store[i][i+diff]=1+store[i+1][i+diff];
                        answer[i][i+diff]=1;
                    }
                }
            }
        }
        printf("Case %d: %d ",test,store[0][len-1]);

        int l=0,r=len-1;
        while(l<r){
            if(answer[l][r]==0){
                putchar(text[l]);
                print_stack[++idx]=text[r];
                l++;r--;
            }
            else if(answer[l][r]==1){
                putchar(text[l]);
                print_stack[++idx]=text[l];
                l++;
            }
            else{
                putchar(text[r]);
                print_stack[++idx]=text[r];
                r--;
            }
        }
        if(l==r)putchar(text[l]);
        for(;idx>=1;idx--)putchar(print_stack[idx]);
        putchar('\n');
    }
    return 0;
}
