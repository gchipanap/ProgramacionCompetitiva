#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<pair<string,int>> getSufijo(string cad){
	vector<pair<string,int>> sufijos;
	int i=0;
	while(cad.size() != 0){					
		sufijos.push_back(make_pair(cad,i));
		cad.erase(cad.begin());
		i++;
	}
	
	sort(sufijos.begin(), sufijos.end());
	
	return sufijos;
}

int main(){
	
	string cad;
	cin>>cad;
	
	vector<pair<string,int>> sufijos = getSufijo(cad);
	
	for(int i=0; i<sufijos.size(); i++){
		cout<<sufijos[i].second<<" "<<sufijos[i].first<<endl;
	}
	
	return 0;
}