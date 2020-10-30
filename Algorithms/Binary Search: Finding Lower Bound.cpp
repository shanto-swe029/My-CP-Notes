/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

/*
	What is #Lower_Bound ?
	The Lower Bound of X is the left most index in an array
	that has a value greater than or equal to X.
	
	For example:
	Consider ara[] = { 10, 20, 20, 20, 30, 30, 40, 50 };
	Here,
		Lower Bound of 20 =  1;
		Lower Bound of 30 =  4;
		Lower Bound of 25 =  4; [ 25 is not present in the array but 25 < 30 ]
		Lower Bound of 5  =  0; [  5 is not present in the array and 5 < 10 ]
		Lower Bound of 80 =  8; [ 80 is not present in the array and 80 is greater than the element of the last index ]
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch_LowerBound( int DATA[], int LB, int UB, int ITEM )
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int LOC = UB + 1;

	while( BEG <= END ) {
		if( DATA[MID] >= ITEM ) {
			END = MID - 1;
			if( MID < LOC ) {
				LOC = MID;
			}
		} 
		else {
			BEG = MID + 1;
		}
		MID = ( int ) ( BEG + END ) / 2;
	}
	
	return LOC;
}

int main()
{
	int n, item;
	std::cin >> n;

	int ara[n];
	for( int i = 0; i < n; i++ ) {
		std::cin >> ara[i];
	}

	std::cin >> item;
	int LowerBound = BinarySearch_LowerBound( ara, 0, n-1, item );
	std::cout << "Lower bound of " << item << " = " << LowerBound << endl;
}

// ALHAMDULILLAH
