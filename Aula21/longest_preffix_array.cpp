#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<pair<string,int>> getSufx(string cad){
	vector<pair<string,int>> sufx;
	int i=0;
	while(cad.size() != 0){	
		sufx.push_back(make_pair(cad,i));
		cad.erase(cad.begin());
		i++;
	}
	
	sort(sufx.begin(), sufx.end());
	return sufx;
}

vector<int> getLCP(string txt, vector<pair<string,int>> sufx){
	
	int n = sufx.size();
	vector<int> LCP (n,0);
	
	vector<int> aux(n,0);
	
	for (int i=0; i < n; i++)
        aux[sufx[i].second] = i;
        
    int k = 0;
 
    for (int i=0; i<n; i++){
  
        if (aux[i] == n-1){
            k = 0;
            continue;
        }
 
        int j = sufx[aux[i]+1].second;
 
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
 
        LCP[aux[i]] = k;
 
        if (k>0)
            k--;
    }
 
    return LCP;
}


int main(){
	
	std::string cad;
	std::cin>>cad;
	
	std::vector<pair<string,int>> sufx = getSufx(cad);
	
	cout<<"Sufix Array:"<<endl;
	for(int i=0; i<sufx.size(); i++){
		std::cout<<sufx[i].second<<" "<<sufx[i].first<<endl;
	}
	
	std::vector<int> LCP = getLCP(cad, sufx);
	
	std::cout<<"LCP Array:"<<endl;
	for(int n:LCP){
		cout<<n<<endl;
	}
	
	return 0;
}
