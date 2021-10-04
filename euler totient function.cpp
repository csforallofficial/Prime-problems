//INPUT - N = 288
//OUTPUT - 96

//1st theorem - if N = prime number, phi(N) = (N-1)
//2nd theorem - if N = (p)^X, for example 32 = (2)^5 --> N = 32, p = 2, X = 5; Then phi(N) = (p)^X - (p)^(X-1) --> phi(32) = (2^5 - 2^4)

//1st approach - Time - O(sqrt(N))

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    for(int i = 2; i*i <= n; i++){
        while(n%i==0){
            n = n/i;
            mp[i]++;
        }
    }
    double count = 1;
    for(auto it:mp){
        count *= (pow(it.first,it.second)-pow(it.first,it.second-1));
    }
    if(n>=2)
        count *= (n-1);
    printf("%f",count);
    return 0;
}


//2nd approach - Direct formula - if we consider the same example 32. Prime factorization of 32 --> 2*2*3*3. So prime factors of 32 = (2,3)
//So phi(32) = 32*(1-1/2)*(1-1/3)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    double count = n;
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            n /= i;
            mp[i]++;
        }
    }
    if(n>=2)
        mp[n]++;
    for(auto it:mp)
        count *= (1.0-1.0/it.first);
    printf("%f",count);
    return 0;
}

//This can also be boiled down to

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    double count = n;
    for(int i = 2; i*i <= n; i++){
        if(n%i==0){
            while(n%i==0)
                n /= i;
            count *= (1.0-1.0/i);
        }
    }
    if(n>=2)
        count *= (1.0-1.0/n);
    printf("%f",count);
    return 0;
}
