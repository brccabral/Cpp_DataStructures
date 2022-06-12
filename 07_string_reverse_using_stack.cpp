#include <iostream>
#include <string.h>
#include <stack>

void Reverse(char c[], int n)
{
    std::stack<char> s;
    for (int i = 0; i < n; i++)
    {
        s.push(c[i]);
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = s.top();
        s.pop();
    }
}

int main()
{
    char c[51];
    printf("Enter a string: \n");
    fgets(c, 50, stdin);
    Reverse(c, strlen(c));
    printf("Output = %s\n", c);
}