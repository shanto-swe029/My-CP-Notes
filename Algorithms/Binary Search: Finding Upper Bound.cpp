

long long BinarySearch_UpperBound(long long DATA[], int LB, int UB, long long ITEM)
{
	int BEG = LB, END = UB, MID = ( int ) ( BEG + END ) / 2;
	int LOC = UB + 1;

	while( BEG <= END ) {
		if( DATA[MID] > ITEM ) {
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
