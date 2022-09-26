#include <iostream>
#include <stack>

int ackermann_recursive(int m, int n)
{
    if(m == 0) return n+1;
    if(n == 0) return ackermann_recursive(m-1, 1);
    return ackermann_recursive(m-1, ackermann_recursive(m, n-1));
}

int ackermann_iterative(int m, int n)
{
    std::stack<int> st;
    st.push(m);
    while(!st.empty())
    {
        m = st.top();
        st.pop();
        if(m == 0)
        {
            n++;
            continue;
        }

        if(n == 0)
        {
            n = 1;
            st.push(m - 1);
            continue;
        }

        st.push(m-1);
        st.push(m);
        n--;
    }
    return n;
}

int main()
{
    std::cout << ackermann_recursive(3, 3) << "\n";
    std::cout << ackermann_iterative(3, 3) << "\n";
    return 0;
}
