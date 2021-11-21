int solution(vector<int> &s) 
{
	stack<char> pila;
	for(char n:S){
		if(n=='(' )
			pila.push(n);
		else if(!pila.empty()){
			if(n==')' && pila.top() == '(') 
				pila.pop();
		}
		else
			pila.push(n);
	}
	
	if(pila.empty())
		return 1;
	else
		return 0;
}
