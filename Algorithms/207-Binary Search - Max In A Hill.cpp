/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_MaxInAHill( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int maximumNumber = min( DATA[LB], DATA[UB] );

	while( BEG <= END )
	{
		if( DATA[MID] >= DATA[MID - 1] )
		{
			BEG = MID + 1;
			if( DATA[MID] > maximumNumber )
			{
				maximumNumber = DATA[MID];
			}
		}
		else
		{
			END = MID - 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	return maximumNumber;
}

int main()
{
	int ara[] = { 2, 3, 4, 6, 9, 12, 11, 8, 4, 1 };
	int lowerBound = 0;
	int upperBound = 9;

	int maximumNumber = BinarySearch_MaxInAHill( ara, lowerBound, upperBound );
	std::cout << maximumNumber << endl;

    return 0;
}

//ALHAMDULILLAH
