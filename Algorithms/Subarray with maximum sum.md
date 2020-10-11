# CP Algorithms

---

### ALgorithm Statement

Given an array of numbers `a[1,2,...,n]`. It is required to find subarray `a[l,...,r]` with the maximal sum.

---

#### Algorithm - 01

```cpp
	int ans = ara[0], sum = 0, min_sum = 0;
	
	for(int r = 0; r < n; r++) {
		sum += ara[r];
		ans = max(ans, sum - min_sum);
		min_sum = min(min_sum, sum);
	}
```
We can also find the boundaries of the desired segment like this following way:

```cpp
	int ans = ara[0], ans_l = 0, ans_r = 0;
	int sum = 0, min_sum = 0, min_pos = 0;
	
	for(int r = 0; r < n; ++r) {
		sum += ara[r];
		int cur = sum - min_sum;
		if(cur > ans) {
			ans = cur;
			ans_l = min_pos + 1;
			ans_r = r;
		}
		if(sum < min_sum) {
			min_sum = sum;
			min_pos = r;
		}
	}
```

#### Algorithm - 02

``` cpp
	int ans = ara[0], sum = 0;
	
	for(int r = 0; r < n; ++r) {
		sum += ara[r];
		ans = max(ans, sum);
		sum = max(sum, 0);
	}
```

We can also find the boundaries of the desired segment like this following way:

```cpp
	int ans = ara[0], ans_l = 0, ans_r = 0;
	int sum = 0, minus_pos = -1;
	
	for(int r = 0; r < n; ++r) {
		sum += ara[r];
		if(sum > ans) {
			ans = sum;
			ans_l = minus_pos + 1;
			ans_r = r;
		}
		if(sum < 0) {
			sum = 0;
			minus_pos = r;
		}
	}
```

---

Thanks for reading. This page will be updated later.

*Happy Coding!*
