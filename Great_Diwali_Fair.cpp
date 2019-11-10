/*
Great Diwali Fair
Welcome to the Great Diwali Fair.
Geek is all set to purchase some great gifts for his younger brother mini.
At present, Geek has n rupees with him, which he can use to purchase some great gifts for mini, in order to make him happy.
Mini will only be happy if geek purchases atleast floor(m/2) gifts, where m is the number of gifts available for a purchase in a stall.
However, mini will be really upset, if he fails to purchase him a gift.
Given m different types of gifts, each having different cost, return h, if mini gets happy else return w.
Note, geek can purchase any gifts.
Input
    t, integer denoting number of testcases. each t line contains..
    n, integer denoting money geeks has.
    m, integer denoting number of gifts.
    array denoting price of m gifts.
Output
Print 'h' if mini is happy else print 'w'.
*/
#include <iostream>
using namespace std;
void bubblesort(int a[], int size)
{
    int i,j,temp;
    for(i = 0; i<size; i++) {
        for(j = i+1; j<size; j++)
   {
            if(a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int pgifts[100000000];
char ans[100000000];
int main() {
	int i,j,k=0,t,m,n,cost=0;
	cin>>t;
	while(k<t)
	{
		cin>>n>>m;
		cost=0;
		if(m!=0)
			{
				for(i=0;i<m;++i)
				{
					cin>>pgifts[i];
				}
				bubblesort(pgifts,m);
				j=(m/2)-1;
				if(j<0)
					j=0;
				for(i=0;i<=j;++i)
				{
					cost+=pgifts[i];
				}
				if(cost<=n)
					ans[k]='h';
				else
				ans[k]='w';
		}
		else
			{
				ans[k]='w';
			}
		++k;
	}
	for(k=0;k<t;++k)
		cout<<ans[k]<<endl;
	return 0;
}