
// Euclid's Algorithm to determine the gcd of two numbers
/*
	Time Complexity		:	O(log(max(A, B)));
*/

long long GCD (long long A, long long B)
{
	if(B==0) return A;
	else return GCD(B, A % B);
}


// Naive Approach to determine the gcd of two numbers
/*
	Time Complexity		:	O(min(A, B));
*/

long long GCD_(long long A, long long B)
{
	long long m = min(A, B);
	for( int i = m; i > 0; i--)
		if(A % i == 0 && B % i == 0)
			return i;
}
