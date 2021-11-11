int solution(vector<int> &H) 
{
    std::stack<int> stack;
    int stones = 0;
    for (auto i : H) {
        while (!stack.empty() && stack.top() > i) {
            stack.pop();
        }
        if (!stack.empty() && stack.top() == i) {
            continue;
        }
        stones++;
        stack.push(i);
    }
    return stones;
}
