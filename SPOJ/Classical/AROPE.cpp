#include<cstdio>

int changes1[330],changes2[330],changes3[330];
int no_of_changes;
int link_r[100001],link_l[100001];
int n;
char text[100001],temp[100001];
bool turn;
int A,B;

int fast()
{
    int res=0;
    char c=getchar();
    while(c!=' ' && c!='\n'){
        res*=10;
        res+=(c-'0');
        c=getchar();
    }
    return res;
}

int started_from(int x,int change_start)
{
    for(int i=change_start;i>=1;i--){
        int s=changes1[i];
        int e=changes2[i];
        if(changes3[i]==1){
            if(x<=e){
                if(x<=(e-s))x=x+s;
                else x=(x+s)%(e+1);
            }
        }
        else{
            if(x>=s){
                x=x+(e-s+1);
                if(x>=n)x=x-(n-s);
            }
        }
    }
    return x;
}

int main()
{
    char c;
    c=getchar();
    while(c!='\n'){
        text[n++]=c;
        c=getchar();
    }
    for(int i=0;i<n-1;i++)link_r[i]=i+1;
    link_r[n-1]=-1;
    for(int i=1;i<n;i++)link_l[i]=i-1;
    link_l[0]=-1;

    int Q;
    Q=fast();
    for(int q=1;q<=Q;q++){
        int type;
        type=fast();
        if(type==1 || type==2){
            int a,y;
            a=fast();
            y=fast();
            changes1[++no_of_changes]=a;
            changes2[no_of_changes]=y;
            changes3[no_of_changes]=type;
            if(no_of_changes==300){
                for(int i=1;i<=no_of_changes;i++){
                    int s=changes1[i];
                    int e=changes2[i];
                    if(changes3[i]==1 && s>0){
                        A=s-1;B=e+1;
                        if(A!=-1)A=started_from(A,i-1);
                        B=started_from(B,i-1);
                        if(A!=-1)link_r[A]=B;
                        link_l[B]=A;

                        A=e;B=0;
                        A=started_from(A,i-1);
                        B=started_from(B,i-1);
                        link_r[A]=B;
                        link_l[B]=A;

                        A=-1;B=s;
                        B=started_from(B,i-1);
                        link_l[B]=A;
                    }
                    else if(changes3[i]==2 && e<n-1){
                        A=e;B=-1;
                        A=started_from(A,i-1);
                        link_r[A]=B;

                        A=n-1;B=s;
                        A=started_from(A,i-1);
                        B=started_from(B,i-1);
                        link_r[A]=B;
                        link_l[B]=A;

                        A=s-1;B=e+1;
                        if(A!=-1)A=started_from(A,i-1);
                        B=started_from(B,i-1);
                        if(A!=-1)link_r[A]=B;
                        link_l[B]=A;
                    }
                }

                int p=0;
                if(!turn){
                    for(int i=0;i<n;i++)if(link_l[i]==-1){
                        temp[p++]=text[i];
                        while(link_r[i]!=-1){
                            i=link_r[i];
                            temp[p++]=text[i];
                        }
                        break;
                    }
                }
                else{
                    for(int i=0;i<n;i++)if(link_l[i]==-1){
                        text[p++]=temp[i];
                        while(link_r[i]!=-1){
                            i=link_r[i];
                            text[p++]=temp[i];
                        }
                        break;
                    }
                }
                for(int i=0;i<n-1;i++)link_r[i]=i+1;
                link_r[n-1]=-1;
                for(int i=1;i<n;i++)link_l[i]=i-1;
                link_l[0]=-1;

                turn=!turn;
                no_of_changes=0;
            }
        }
        else{
            int x;
            x=fast();
            if(!turn)putchar(text[started_from(x,no_of_changes)]);
            else putchar(temp[started_from(x,no_of_changes)]);
            putchar('\n');
        }
    }
}
