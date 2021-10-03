//INPUT - 468
//OUTPUT - 2 * 2 * 3 * 3 * 13

#include<iostream>
using namespace std;

int sieve[1000005];
int direct[1000005];
int N = 1000000;
void createsieve(){
    for(int i = 0; i <= N; i++){
        direct[i] = i;
        sieve[i] = 1;
    }
    for(int i = 2; i*i <= N; i++){
        if(sieve[i] == 1){
            for(int j = i*i; j <= N; j+=i){
                sieve[j] = 0;
                if(i < direct[j])
                    direct[j] = i;
            }
        }
    }
}

int main(){
    createsieve();
    int n;
    scanf("%d",&n);
    while(n>1){
        printf("%d ",direct[n]);
        n /= direct[n];
    }
    printf("\n");
    return 0;
}
