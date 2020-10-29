/*    BISMILLAHIR-RAHMANIR-RAHIM
 ____________________________________
|                                    |
|      SHANTO_SUST_SWE-19__029       |
|      shanto-swe029.github.io       |
|____________________________________|
*/

#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb          push_back
#define Pi          acos(-1.0)
#define r0          return 0
#define endl        "\n"
#define show(x)     cout << x << endl
#define take(x)     cin >> x
#define debug       1

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
