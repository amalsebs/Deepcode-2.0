/*
WINNING THE RACE

Geek is organizing a race of N contestants.
This is an interesting race in which a winner is predicted after checking at every odd seconds.
If race time is 6 seconds, then we will look up who is leading at particular checktime, ie at 1st second, 3 second, and 5th second.
Participant who is leading more number of times is considered to be the winner of a race.
Note :

    At a particular timepoint, if two or more participants are at same distance, then both are considered to be leading the race.
    At the end of timepoints, if two or more participants have equal lead point, the one who comes first in input sequence is considered to be a winner.

Input
    N, integer denoting number of participants.
    T, integer denoting total time in seconds of this marathon.
    Next N line follows : We have T+1 integers seperated by space. First T lines are as follows : i th integer denotes the number of steps taken by participant at i th second. (T+1)th integer denotes distance of each step.
Output
Index of Marathon winner, index starts from 1.
*/
#include <iostream>
using namespace std;
int main ()
{
	int n, t, i, j, part[100], partt[100][100], temp = 0, tempsum = 0, max[100];
 	cin >> n >> t;
	for (i = 1; i <= n; ++i)
	{
    		part[i] = 0;
    		tempsum = 0;
    	for (j = 1; j <= t; ++j)
    	{
	    	cin >> temp;
	    	tempsum += temp;
	    	if (j % 2 != 0)
	        	partt[i][(j / 2) + 1] = tempsum;
		}
    	cin >> temp;
    	for (j = 1; j <= t / 2+1; ++j)
	    	partt[i][j] = partt[i][j] * temp;
	}
	for (i = 1; i <= t/2+1; ++i)
	{
    	temp = 0;
    	for (j = 1; j <= n; ++j)
		{
	    	if (partt[j][i] > temp)
	        	temp = partt[j][i];
		}
    	max[i] = temp;
	}
	for (i = 1; i <= t/2+1; ++i)
	{
    	for (j = 1; j <= n; ++j)
		{
	    	if (max[i] == partt[j][i])
	        	++part[j];
		}
	}
	temp = 0;
	for (i = 1; i <= n; ++i)
    	if (temp < part[i])
        	temp = part[i];
	i = 1;
	while (temp != part[i]){
    	++i;
	}
	cout << i;
	return 0;
}
