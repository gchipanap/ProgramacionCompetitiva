#include <iostream>
#include <vector>
using namespace std;


vector<int> readVector(string &S){
    vector<int> res;
    for (auto &&i : S){
        switch (i){
        case 'A':
            res.push_back(1);
            break;
        case 'C':
            res.push_back(2);
            break;
        case 'G':
            res.push_back(3);
            break;
        case 'T':
            res.push_back(4);
            break;
        }
    }

    return res;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){

    vector<int> VectorS = readVector(S);
    cout<<"VECTORS"<<endl;
    for (auto &&i : VectorS)
    {
        cout << i << " ";
    }
    cout << endl;
    
    vector<int> res;
    int min = 100000;
    int comp;
    for (int i = 0; i < P.size(); i++)
    {
        cout << "P: " <<P[i] << " | " << "Q:" << Q[i] << endl;
        for (int j = P[i]; j <= Q[i]; j++)
        {
            comp = VectorS[j];
            //Comparacion
            if(min > comp){
                min = comp;
            }
        }
        res.push_back(min);
        min = 100000;
        
    }
    

    return res;
}

int main(){
    cout <<"LECTURA 1" << endl;
    int N,M;
    string S="",aux;
    cin>>S;
    N = S.size();

    cout <<"LECTURA 2" << endl;
    vector<int> P,Q;
    cin>>M;
    int auxi;
    for (int i = 0; i < M; i++)
    {
        cin >> auxi;
        P.push_back(auxi);
        cin >> auxi;
        Q.push_back(auxi);   
    }
    cout <<"SOL 1" << endl;
    vector<int> res = solution(S,P,Q);

    for (auto &&i : res)
    {
        cout << i <<" ";
    }
    cout << endl;
  
    return 0;
}