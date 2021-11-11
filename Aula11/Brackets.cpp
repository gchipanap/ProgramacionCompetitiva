int solution(string &S) {
    if (s.empty()) { return 1; }

    auto tam_arr = s.length();

    if (tam_arr % 2) { return 0; }

    std::stack<char> s_stack;

    auto no_pair = [&stack](char c) {
        if (stack.empty() || stack.top() != c) {
            return true;
        }
        stack.pop();
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
                stack.push(c);
        }
    }
    if(stack.empty())
	return 1;
    else
	return 0;
}
