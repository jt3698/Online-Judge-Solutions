#include<bits/stdc++.h>
using namespace std;

stack<char>answer;

int main()
{
    for(int test=1;test<=10;test++){
        answer=stack<char>();
        int N;
        scanf("%d\n",&N);
        string order;
        cin>>order;
        for(int i=0;i<N;i++){   ///Setiap Operasi harus dibuat 'reversenya' seoptimal mungkin (pop kalau bisa)
            if(answer.size()==0){
                if(order[i]=='R'){
                    i++;
                    answer.push('R');           ///Ini karena talinya belum ada loop dan dua string parallel seperti -> ||
                    while(i<N && order[i]!='R')i++;     ///Jika ini di-swap ('S'), tidak akan menyebabkan perubahan
                    if(i<N && order[i]=='R')answer.pop();
                }
                else{
                    answer.push('S');       ///Di sini hanya ada dua string yang membuat sebuah X dan bisa di luruskan dengan
                    answer.push('R');       ///memutar sekali ('R') diikutin dengan swap('S')
                }
            }
            else{
                if(answer.top()==order[i])answer.pop(); ///Kalau di stacknya sama dengan operasi selanjutnya sama aja kayak 'reverse-movement', jadi di-pop
                else if(order[i]=='S'){
                    answer.pop();   ///Karena sudah ada 'if' di atas, dipastikan di stack_top adalah 'R'. Di-pop sama seperti melakukan sebuah operasi 'R'
                    answer.push('S');   ///Untuk membuat sebuah loop hilang harus dengan sequence 'RSRS', diikuti dengan reverse-'R' untuk posisi optimal (pop sekali)
                    answer.push('R');
                    answer.push('S');
                    answer.push('R');
                }
                else answer.push('R');  ///Seperti di atas, sudah pasti operasi sebelumnya adalah 'S', jadi operasi 'R' dibalas dengan 'R'
            }
        }
        printf("%d\n",answer.size());
    }
    return 0;
}
