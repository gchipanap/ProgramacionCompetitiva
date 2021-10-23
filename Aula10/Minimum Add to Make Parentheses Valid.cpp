int minAddToMakeValid(string s) {
        stack<char> arr;
  int cont = 0;
  for (int i = 0; i < s.length(); i++) 
  {
    if (s[i] == '(')
      arr.push(s[i]);
    else 
    {
      if (arr.empty()) {
          cont++;
          continue;
      }
      else if (s[i] == ')' && arr.top() != '(')
          cont++;

      arr.pop();
    }
  }
  cont += arr.size();
    return cont;
    }