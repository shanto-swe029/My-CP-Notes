/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch( int DATA[], int LB, int UB, int ITEM )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;

	while( ( BEG <= END ) && ( DATA[MID] != ITEM ) ) {
		if( ITEM < DATA[MID] ) {
			END = MID - 1;
		} else {
			BEG = MID + 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	int LOC = -1;
	if( DATA[MID] == ITEM ) {
		LOC = MID;
	}
	
	return LOC;
}

int main()
{
	int ara[] = { 1, 3, 4, 5, 5, 7, 8, 12, 18 };
	int item = 3;
	int lowerBound = 0;
	int upperBound = 8;
	int index = BinarySearch( ara, lowerBound, upperBound, item );

	if( index == -1 ) {
		printf("Item Not Found\n");
	} else {
		printf("%d is found at index %d\n", item, index);
	}

    r0;
}

//ALHAMDULILLAH
