#include <stack>
#include <iostream>

template <typename T>
std::stack<T> stackSort(std::stack<T> stack)
{
    T current;
    std::stack<T> temp;
    while(!stack.empty())
    {
        current = stack.top();
        stack.pop();
        while(!temp.empty() && temp.top() > current)
        {
            stack.push(temp.top());
            temp.pop();
        }
        temp.push(current);
    }
    return temp;
}

template <typename T>
void printStack(std::stack<T> stack)
{
    std::stack<T> temp;
    while(!stack.empty())
    {
        temp.push(stack.top());
        stack.pop();
    }
    while(!temp.empty())
    {
        std::cout << temp.top() << ' ';
        temp.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::stack<int> example {{34, 25, 3, 1, 49, 2, 6, 4}};
    std::stack<int> sorted {stackSort(example)};

    printStack(example);
    printStack(sorted);

    return 0;
}
