#include <stack>

int solution(string &s) {
    if (s.empty()) { return 1; }

    auto tam_arr = s.length();

    if (tam_arr % 2) { return 0; }

    std::stack<char> s_stack;

    auto no_pair = [&s_stack](char c) {
        if (s_stack.empty() || s_stack.top() != c) {
            return true;
        }
        s_stack.pop();
        return false;
    };

    for (auto c: s) {
        switch (c) {
            case ')':
                if (no_pair('(')) { return 0; }
                break;
            case ']':
                if (no_pair('[')) { return 0; }
                break;
            case '}':
                if (no_pair('{')) { return 0; }
                break;
            default:
                s_stack.push(c);
        }
    }
    if(s_stack.empty())
	return 1;
    else
	return 0;
}
