/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_RotatedArray_FindSmallestElement( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int ITEM = DATA[UB], smallestElement = ITEM;

	while( BEG <= END )
	{
		if( DATA[MID] > ITEM ) 
		{
			BEG = MID + 1;
		}
		else
		{
			END = MID - 1;
			if( DATA[MID] < ITEM ) 
			{
				ITEM = DATA[MID];
			}
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	std::cout << ITEM << endl;
	return ITEM;
}


int main()
{
	int ara[] = { 2, 3, 6, 7, 9, 15, 19};
	int lowerBound = 0;
	int upperBound = 7;

	int smallestElement = BinarySearch_RotatedArray_FindSmallestElement( ara, lowerBound, upperBound );
	std::cout << smallestElement << endl;

    return 0;
}

//ALHAMDULILLAH
