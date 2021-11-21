int solution(vector<int> &A, vector<int> &B) {
 int ans=0;
	int n=A.size();
	stack<int> pila;
	for(int i=0; i<n; i++){
		int pez = A[i];
		int dir = B[i];
		if(dir == 0){
			bool surv = true;
			while(!pila.empty()){
				int pezAux = pila.top();
				pila.pop();
				if(pezAux > pez){
					pila.push(pezAux);
					surv = false;
					break;
				}
			}
			if(surv)
				ans++;
		}
		else
			pila.push(pez);
	}
	ans += pila.size();
	return ans;
}
