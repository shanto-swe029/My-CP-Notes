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
