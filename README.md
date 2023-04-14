# My-CP-Notes

Here I will add necessary competitive programming related notes on different algorithms

---

## Linear Diophantine Equation With Positive Solution

Suppose, you are to solve this equation `ax + by = c` where `a`, `b`, and `c` are positive integers.

A solution exists iff `gcd(a,b)` divides `c`. Let `g = gcd(a,b)`.

Assuming that `c` is divisible by `g` and `l = c/g`.

Using `Extended Euclidean Algorithm`, we can find two integers `m` and `n` such that `am + bn = g`.

If we multiply both side of the previous equation with `l`, we get:

`aml + bnl = gl = c` ...........(i)

So, `(x0, y0) = (ml, nl)` is a solution. But it is not guranteed that both `x0` and `y0` are positive.

For finding positive solutions for both `x` and `y`, we dive into the general solution:

`x = x0 + k*(b/g)`

`y = y0 - k*(a/g)`

where `k` is any **Natural Number**.

Now, `x > 0` and `y > 0`

or, `x0 + k*(b/g) > 0` and `y0 - k*(a/g) > 0`

or, `k > -x0*g/b` and `k < y0*g/a`

let `p = floor(-x0*g/b)` and `q = ceil(y0*g/a)`

Now, `x` and `y` will be positive for `k ∈ (p,q)`.

#### Problem: <a href = "http://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1031"> UVa 10090 </a>
