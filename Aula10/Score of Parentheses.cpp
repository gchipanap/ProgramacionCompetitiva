int scoreOfParentheses(string S) {
        stack<int> score;
        score.push(0);
        for (auto &c : S) {
            if (c == '(')
                score.push(0);
            else {
                int t = score.top();
                score.pop();
                if (t == 0)
                    score.top() += 1;
                else
                    score.top() += 2 * t;
            }
        }
        return score.top();
    }