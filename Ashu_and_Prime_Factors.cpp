/*
Problem
Ashu is very fond of Prime numbers and he like challenging his friends by giving them various problems based on Mathematics and Prime number. One of his friend Harshit is jealous and challenges him to solve a task. Task is :
Given a prime number X, you need to give the count of all numbers in range 1 to 106 inclusive which have minimum prime factor X.
Help Ashu in solving this task.

Input:
First line consist of numer of test cases T.
Each test case contains a single number X.

Output:
Output for each test case count of all numbers in range 1 to 106 inclusive which have minimum prime factor X.

Constraints:
1 ≤ T ≤ 105
Prime number X where 2 ≤ X ≤ 106
Sample Input
2
2
11
Sample Output
500000
20779
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
The minimum prime factor of all even numbers in the range [2, 1000000] is 2, and there are 1000000/2 = 500000 such even numbers.
The numbers with minimum prime factor as 11 are: 11, 121, 143, ...
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[1000005];
	for(int i = 2; i <= 1000000; i++)
		arr[i] = 1;
	int arr2[1000005] = {0};
	for(int i = 2; i*i <= 1000000; i++){
		if(arr[i] == 1){
		    for(int j = i*i; j <= 1000000; j+=i){
		        if(arr[j] != 0){
		            arr[j] = 0;
		            arr2[i]++;
		        }
		    }
		}
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << arr2[n]+1 << endl;
	}
}
