int solution(vector<int> &A, vector<int> &B) {
    const auto UPSTREAM = 0;
    int left = 0, fish_num = A.size();
    std::stack<int> stack;

    for(int i = 0; i < fish_num; ++i) {
        if(UPSTREAM == B[i]) {
            while(!stack.empty() && (stack.top() < fish[i])) {
                stack.pop();
            }
            if(stack.empty()) {
                left++;
            }
        }
        else {
            stack.push(fish[i]);
        }
    }
    return left + stack.size();
}
