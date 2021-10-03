//INPUT - 468
//OUTPUT - 2 * 2 * 3 * 3 * 13

//1st approach - Brute - O(sqrt(N))
#include<iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int i = 2;
    while(n>1){
        if(!(n%i)){
            printf("%d ",i);
            n /= i;
        }
        else
            i++;
    }
    printf("\n");
    return 0;
}

//2nd approach - Better - Time - O(log N), Space - O(2N)

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


//3rd approach - Best - Time - O(log N), Space - O(N)

#include<iostream>
using namespace std;

int sieve[1000005];
int N = 1000000;
void createsieve(){
    for(int i = 0; i <= N; i++)
        sieve[i] = i;
    
    for(int i = 2; i*i <= N; i++){
        if(sieve[i] == i){
            for(int j = i*i; j <= N; j+=i){
                if(sieve[j] == j)
                    sieve[j] = i;
            }
        }
    }
}

int main(){
    createsieve();
    int n;
    scanf("%d",&n);
    while(n>1){
        printf("%d ",sieve[n]);
        n /= sieve[n];
    }
    printf("\n");
    return 0;
}
