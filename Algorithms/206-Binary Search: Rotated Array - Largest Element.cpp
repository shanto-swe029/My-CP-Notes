/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_RotatedArray_FindLargestElement( int DATA[], int LB, int UB )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int ITEM = DATA[LB], largestElement = ITEM;

	while( BEG <= END )
	{
		if( DATA[MID] >= ITEM ) 
		{
			BEG = MID + 1;
			if( DATA[MID] > largestElement ) 
			{
				largestElement = DATA[MID];
			}
		}
		else
		{
			END = MID - 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	return largestElement;
}

int main()
{
	int ara[] = { 2, 3, 6, 7, 9, 15, 19 };
	int lowerBound = 0;
	int upperBound = 6;

	int largestElement = BinarySearch_RotatedArray_FindLargestElement( ara, lowerBound, upperBound );
	std::cout << largestElement << endl;

  return 0;
}

//ALHAMDULILLAH
