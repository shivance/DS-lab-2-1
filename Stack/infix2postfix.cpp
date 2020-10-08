#include <cstdio>  
#include <cstdlib>
#include <stack>
#include <iostream>
#include <climits>
using namespace std;  
  

int isOperator(char a)  
{  
    switch (a) {  
    case '+':  
        return 1;  
    case '-':  
        return 1;  
    case '*':  
        return 1;  
    case '%':  
        return 1;  
    case '/':  
        return 1;  
    case '(':  
        return 1;  
    }  
    return 0;  
}  
  
int isOperand(char a)  
{  
    if (a >= 65 && a <= 90  
        || a >= 97 && a <= 122)  
        return 1;  
    return 0;  
}  
  

int inPrec(char a)  
{  
    switch (a) {  
    case '+':  
    case '-':  
        return 2;  
    case '*':  
    case '%':  
    case '/':  
        return 4;  
    case '(':  
        return 0;  
    }  
}  
  

int outPrec(char a)  
{  
    switch (a) {  
    case '+':  
    case '-':  
        return 1;  
    case '*':  
    case '%':  
    case '/':  
        return 3;  
    case '(':  
        return 100;  
    }  
}  

  
void infixToPost(char* a)  
{  
    stack<char> s;  
  
    int i = 0;  
    while (a[i] != '\0') {  
        if (isOperand(a[i])) {  
            printf("%c", a[i]);  
        }  
        else if (isOperator(a[i])) {  
            if (s.empty()  
                || outPrec(a[i]) > inPrec(s.top()))  
                s.push(a[i]);  
            else {  
                while (!s.empty()  
                    && outPrec(a[i]) < inPrec(s.top())) {  
                    printf("%c", s.top());  
                    s.pop();  
                }  
                s.push(a[i]);  
            }  
        }  
  
        else if (a[i] == ')') {  
            while (s.top() != '(') {  
                printf("%c", s.top());  
                s.pop();  
  
                // if opening bracket not present  
                if (s.empty()) {  
                    printf(" INCORRECT EXPRESSION\n");  
                    exit(1);  
                }  
            }  
            s.pop();  
        }  
        i++;  
    }  
  
    
    while (!s.empty()) {  
        if (s.top() == '(') {  
            printf("\n INCORRECT EXPRESSION\n");  
            exit(1);  
        }  
        printf("%c", s.top());  
        s.pop();  
    }  
}  
  
// Driver code  
int main()  
{  
    char input[50];
    cin>>input; 
    infixToPost(input);  
    return 0;  
}  