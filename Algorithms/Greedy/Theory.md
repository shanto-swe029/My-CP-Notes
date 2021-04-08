# Greedy Algorithms

A **greedy algorithm** constructs a solution to the problem by always making a choice that looks the best at the moment. A greedy algorithm never takes back its choices, but directly constructs the final solution. For this reason, greedy algorithms are usually very efficient.

  The difficulty in designing greedy algorithms is to find a greedy strategy that always produces an optimal solution to the problem. The locally optimal choices in a greedy algorithm should also be globally optimal. It is often difficult to argue that a greedy algorithm works.


## Coin Problem


<details><summary>Click Me</summary>
<p>

As a first example, we consider a problem where we are given a set of coin values and our task is to form a sum of money using the coins. The values of the coins are **_{c<sub>1</sub>, c<sub>2</sub>,..., c<sub>k</sub>}_**, and each coin can be used as many times we want. What is the minimum numbers of coins needed?

  For example, if those coins are euro coins (in cents)
  
 **_{1, 2, 5, 10, 20, 50, 100, 200}_**
 
 and the sum of money is **_520_**, we need at least four coins. The optimal solution is to select coins **_200+200+100+20_** whose sum is **_520_**.
 
### Greedy Algorithm
 
A simple greedy algorithm to tge problem is to always select the largest possible coin, until we have constructed the required sum of money. This algorithm works in the example case, because we select two **_200_** cent coins, then one **_100_** cent coin and finally one **_20_** cent coin. But does this algorithm always work?
 
  It turns out that, for the set of euro coins, the gredy algorithm *always works*, i.e., it always produces a solution with the fewest possible number of coins. The correctness of the algorithm can be shown as follows: 
  
   Each coin **_1, 5, 10, 50_** and **_100_** appears at most once in an optimal solution. The reason for this is that if the solution would contain two such coins, we could replace them by one coin and obtain a better solution. For example, if the solution would contain **_5+5_**, we could replace them by coin **_10_**.
   
   In the same way, coins **_2_** and **_20_** appear at most twice in an optimal solution, because we could replace **_2+2+2_** by coins **_5+1_** and coins **_20+20+20_** by coins **_50+10_**. Moreover, an optimal solution cannot contain cions **_2+2+1_** or **_20+20+10_**, because we could replace them by coins **_5_** and **_50_**. 
   
   Using these observaions, we can show for each coin **_x_** that it is not possible to optimally construct a sum **_x_** or any larger sum by only using coins that are smaller than **_x_**. For example, if **_x=100_**, the largest optimal sum using the smaller coins is **_50+20+20+5+2+2=99_**. Thus the gredy algorithm tat always selects the largest coin produces the optimal solution.
   
   This example shows that it can be dificult to argue that a greedy algorithm always works, even if the algorithm itself is simple.
   
### General Case
   
In the general case, the coin set can contain any coins and the greedy algorithm _does not_ necessarily produce an optimal solution. 

  We can prove that a greedy algorithm does not work by showing a counterexample where the algorithm gives a wrong answer. In this problem we can easily find a counterexample: if the coins are **_{1, 3, 4}_** and the largest sum is **_6_**, the greedy algorithm produces the solution **_4+1+1_** while the optimal solution is **_3+3_**.
  
  it is not known if the general coin problem can be solved using any greedy algorithm. However, in some cases, the general problem can be efficiently solved using a dynamic programming algorithm that always gives the correct answer.

</p>
</details>
