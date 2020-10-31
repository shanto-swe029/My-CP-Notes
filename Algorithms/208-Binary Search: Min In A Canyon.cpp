/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_MinInACanyon( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int minimumNumber = max( DATA[LB], DATA[UB] );

	while( BEG <= END )
	{
		if( DATA[MID] <= DATA[MID - 1] )
		{
			BEG = MID + 1;
			if( DATA[MID] < minimumNumber )
			{
				minimumNumber = DATA[MID];
			}
		}
		else
		{
			END = MID - 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	return minimumNumber;
}

int main()
{
	int ara[] = { 12, 9, 7, 6, 2, 1, 4, 8, 10 };
	int lowerBound = 0;
	int upperBound = 8;

	int minimumNumber = BinarySearch_MinInACanyon( ara, lowerBound, upperBound );
	std::cout << minimumNumber << endl;

    return 0;
}

//ALHAMDULILLAH
