/*
DIWALI LIGHTS

Diwali is considered as Festival of Lights.
This diwali, Geek wants to decorate his house, with a bunch of 'n' led lights.
Each light has its own illuminating value.
Geek wants to arrange these led's in the increasing order of their illuminating value.
To do this, he is allowed to shuffle(interchange) a pair of any two led's.
He can perform this operating any number of times.
Find the number of operations needed to obtain the required pattern.
Note : Illuminating values are consecutive integers.
Input
    n, integer denoting number of led's in a bunch.
    led[], array of integers denoting illuminating value of 'n' led's.
Output
    Find the number of operations needed to obtain the required pattern.
*/

#include <iostream>
using namespace std;

int main() {
	int i, j, imin,temp,count=0,n,led[100];
	cin>>n;
	for(i=0;i<n;++i)
    	cin>>led[i];
	for(i = 0; i<n-1; i++)
	{
        imin = i;
        for(j = i+1; j<n; j++)
            if(led[j] < led[imin])
                imin = j;
        if(led[i]!= led[imin])
        {
            temp=led[i];
            led[i]=led[imin];
            led[imin]=temp;
            ++count;
        }    
	}
    cout<<count;
	return 0;
}
