/*
P3. Collatz Conjecture
https://open.kattis.com/problems/collatz
*/

#include<iostream>
#include<vector>
using namespace std;


vector<long long> sol(long long x_0){
    vector<long long> v;
    v.push_back(x_0);

    while(x_0 != 1){
        if(x_0 % 2 == 0) x_0 = x_0/2;//par
        else x_0 = (3*x_0) + 1;

        v.push_back(x_0);
    }
    return v;
}

int coincidence(vector<long long> v , long long x_0){
    for(size_t i = 0; i < v.size(); i++){
        if(v[i] == x_0){
            return i;
        }
    }
    return -1;
}

int main(){
    long long A,B;
    long long posA;
    long long posB;

    while(cin>>A>>B){
        if(A == 0 && B == 0) break;

        vector<long long> coinciA = sol(A);
        vector<long long> coinciB = sol(B);

        for(size_t i = 0 ; i < coinciA.size(); i++){
            long long same = coincidence(coinciB , coinciA[i]);
            posA = i;
            posB = same;
            if(same != -1) break;
        }

        cout<<A<<" needs "<<posA<<" steps, "<<B<<" needs "<<posB<<" steps, they meet at "<<coinciA[posA]<<endl;
    }
    return 0;
}