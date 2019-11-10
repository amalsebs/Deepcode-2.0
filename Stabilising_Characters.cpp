/*
STABLISING CHARACTERS

A bracket may be any character between [a-z] or [A-Z].
Generally, we consider lowercase characters as opening brackets and uppercase characters as closing brackets.
Two brackets are considered to be a stable pair if the an opening bracket of the exact same type.
For instance, stable pairs of brackets: a,A | b,B | t.T .
A pair of brackets is not stable if the set of brackets it encloses are not matched.
For example, abcCBA is stable whereas BcCb is not.
A sequence of brackets is stable if the following conditions are met:
    It contains no unmatched brackets.
    The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets. You are provided with N strings, your job is to find whether it is stable or not. Print Y for yes or N for No.
Note : 1 <= N <= 10^4
Input
    Integer N, denoting number of strings.
    Each N lines, includes a string of character.
Output
    Print Y for yes or N for No for each string in new line.
*/
#include <iostream>
#include <string.h>
using namespace std;
char stack[100];
int top=-1;
void push(char val) {
      top++;
      stack[top]=val;
}
char pop() {
      top--;
      return stack[top+1];
}
int main() {
    int n,i=1,j=0,flag;
    char input[100],temp,poped,ans[100];
    cin>>n;
    while(i<=n)
    {
        flag=1;
        top=-1;
        cin>>input;
        for(j=0;input[j]!='\0' && flag==1;++j)
        {    
            temp=input[j];
            if(temp>='a' && temp<='z')
            {
                push(temp);
            }
            else if(temp>='A' && temp<='Z')
            {
                poped=pop();
                poped=poped-32;
                if(temp!=poped)
                    flag=0;
            }
        }
        if(top==-1 && flag==1)
            ans[i]='Y';
        else
            ans[i]='N';
        ++i;
    }
    for(i=1;i<=n;++i)
        cout<<ans[i]<<endl;
	return 0;
}