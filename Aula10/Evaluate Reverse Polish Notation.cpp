int evalRPN(vector<string>& tokens) {
    stack<int> stack;
      for(auto i : tokens)
      {
        if( i == "+" || i == "-" || i == "*" || i == "/")
        {
          int val1 = stack.top(); stack.pop();
          int val2 = stack.top(); stack.pop();
          if (i == "+") 
            stack.push(val1 + val2);
          else if (i == "-") 
            stack.push(val1 - val2);
          else if (i == "*") 
            stack.push(val1 * val2);
          else 
            stack.push(val1 / val2);
        }
        else 
          stack.push(stoi(i));
      }
      return stack.top();
    }