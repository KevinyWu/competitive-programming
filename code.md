# Code Snippets for CP

- [Code Snippets for CP](#code-snippets-for-cp)
  - [Tips](#tips)
    - [CPP Template](#cpp-template)
    - [Python Template](#python-template)
    - [Time Complexity](#time-complexity)
    - [Commonly Missed Techniques](#commonly-missed-techniques)
    - [Common Problems](#common-problems)
  - [Problem Types](#problem-types)
  - [Code Snippets](#code-snippets)
    - [Array](#array)
    - [String](#string)
    - [Characters](#characters)
    - [Set](#set)
    - [Map](#map)
    - [Double-ended Queue](#double-ended-queue)
    - [Stack](#stack)
    - [Priority Queue](#priority-queue)
    - [Sorting and Searching](#sorting-and-searching)
    - [Bitwise Operators](#bitwise-operators)
    - [Math](#math)
    - [Ternary Operator](#ternary-operator)
    - [Array Manipulation](#array-manipulation)
    - [Fenwick Tree](#fenwick-tree)
  - [Functions](#functions)
    - [pow\_mod](#pow_mod)
    - [get\_sum](#get_sum)
    - [max\_subarray\_sum](#max_subarray_sum)
    - [add\_edge](#add_edge)
    - [dfs](#dfs)
    - [num\_nodes](#num_nodes)
    - [divup](#divup)
    - [dec\_to\_binary](#dec_to_binary)
    - [prime\_factors](#prime_factors)
    - [get\_primes](#get_primes)
    - [is\_prime](#is_prime)
    - [next\_prime](#next_prime)
    - [choose](#choose)

## Tips

### CPP Template

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << -1 << "\n";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
```

- Command line tools: [link](https://codeforces.com/blog/entry/102287)
- Compile code: `g++ -std=c++20 -O2 -Wall main.cpp -o main`
- Run code:  `./main < input > output`
- Comparing floats: `abs(a-b) < 1e-9`
- Print float x with 9 decimals: `printf("%.9f\n", x);`

### Python Template

```python
import sys
input = sys.stdin.readline

def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

def main():
    n = inp()
    a = inlt()

main()
```

Run code:  `python3 main.py < input > output`

1. inp — For taking integer inputs.
2. inlt — For taking List inputs.
3. insr — For taking string inputs. Actually it returns a List of Characters, instead of a string, which is easier to use in Python, because in Python, Strings are Immutable.
4. invr — For taking space seperated integer variable inputs.

The input = sys.stdin.readline is actually for Faster Inputs, because line reading through System STDIN (Standard Input) is faster in Python.

### Time Complexity

- n <= 10: O(n!)
- n <= 20: O(2^n)
- n <= 500: O(n^3)
- n <= 5000: O(n^2)
- n <= 1e6: O(nlogn) or O(n)
- n is large: O(1) or O(logn)

### Commonly Missed Techniques

- Binary search over the answer
- Prefix or suffix sums
- Modular arithmetic
- Bash all solutions

### Common Problems

- Nested for loops don't use `int i` twice
- Use of `ll` for big numbers (or python)
- `ll` and `int` don't match
- Use `else if` not just `if`
- Watch for division by 0
- Make sure not to use `vector.size()` in for loop because it will update every loop
- Priority queue sorts largest to smallest
- Use char array for chars
- When doing `(a + n) % n`, ensure no negatives
  
## Problem Types

- Bitwise - [82545243](https://codeforces.com/contest/1362/submission/82545243), [82878420](https://codeforces.com/contest/1365/submission/82878420), [84268924](https://codeforces.com/contest/1368/submission/84268924), [86929529](https://codeforces.com/contest/1325/submission/86929529)
- Constructive - [76199232](https://codeforces.com/contest/1334/submission/76199232), [80717175](https://codeforces.com/contest/1353/submission/80717175), [79595554](https://codeforces.com/contest/1352/submission/79595554), [79590010](https://codeforces.com/contest/1352/submission/79590010)
- Dynamic Programming - [89965525](https://codeforces.com/contest/1398/submission/89965525), [161135815](https://codeforces.com/contest/1695/submission/161135815), [211064452](https://codeforces.com/contest/1842/submission/211064452), [175665258](https://codeforces.com/contest/1741/submission/175665258), [226104810](https://codeforces.com/contest/1875/submission/226104810), [244612424](https://codeforces.com/contest/1920/submission/244612424)
- Graphs - [84826067](https://codeforces.com/contest/1369/submission/84826067), [73287755](https://codeforces.com/contest/1325/submission/73287755), [76905410](https://codeforces.com/contest/1337/submission/76905410)
- Interactive - [92291812](https://codeforces.com/contest/1407/submission/92291812), [167314286](https://codeforces.com/contest/1713/submission/167314286)
- Math - [78770193](https://codeforces.com/contest/1348/submission/78770193), [86600542](https://codeforces.com/contest/1372/submission/86600542), [90490144](https://codeforces.com/contest/1311/submission/90490144), [171954881](https://codeforces.com/contest/1729/submission/171954881)
  - Geometry - [81622965](https://codeforces.com/contest/1358/submission/81622965), [80792639](https://codeforces.com/contest/1355/submission/80792639), [80518148](https://codeforces.com/contest/1354/submission/80518148)
  - Combinatorics - [74151444](https://codeforces.com/contest/1327/submission/74151444)
  - Number Theory - [83549725](https://codeforces.com/contest/1366/submission/83549725), [84025299](https://codeforces.com/contest/1367/submission/84025299), [80619339](https://codeforces.com/contest/1350/submission/80619339)
  - Modular Arithmetic - [81916822](https://codeforces.com/contest/1359/submission/81916822), [79208433](https://codeforces.com/contest/1345/submission/79208433), [78229280](https://codeforces.com/contest/1342/submission/78229280)
  - Algebra - [74230900](https://codeforces.com/contest/1313/submission/74230900)
- Matrix - [85501454](https://codeforces.com/contest/1374/submission/85501454), [91004976](https://codeforces.com/contest/1400/submission/91004976), [102726588](https://codeforces.com/contest/1443/submission/102726588)
- MEX - [86005100](https://codeforces.com/contest/1375/submission/86005100), [215653739](https://codeforces.com/contest/1851/submission/215653739)
- Recursion - [80167092](https://codeforces.com/contest/1353/submission/80167092), [87171495](https://codeforces.com/contest/1385/submission/87171495), [215592664](https://codeforces.com/contest/1851/submission/215592664)
- Sorting and Searching
  - Lambda Sort - [80167092](https://codeforces.com/contest/1353/submission/80167092)
  - Binary Search - [84529203](https://codeforces.com/contest/1370/submission/84529203)
  - Subarray Sums - [85053431](https://codeforces.com/contest/1373/submission/85053431), [89961907](https://codeforces.com/contest/1398/submission/89961907)
- Strings - [84117006](https://codeforces.com/contest/1367/submission/84117006), [87601872](https://codeforces.com/contest/1382/submission/87601872)
- Fenwick Tree - [239415708](https://codeforces.com/contest/1915/submission/239415708)

## Code Snippets

### Array

```cpp
int a[n] = {0}; // array of zeros
int a[n][m] = {0}; // matrix of zeros
```

### String

```cpp
s(n, c) // create a string length n of char c

str1.compare(str2);
// 0 : if both strings are equal.
// < 0 : if shorter than str or first char that doesn't match is smaller
// > 0 : if longer than str or first char that doesn't match is greater

s.insert(i, n, c) // insert n copies of char c at index i
s.erase(s.begin() + i); // erases character at i
str.find(substr); // returns index of first character of first match

sort(s.begin(), s.end()); // sort in alphabetic order
string(s.rbegin(), s.rend()) // reverse string

count(str.begin(), str.end(), 'e'); // count occurences of 'e' for arrays, vectors
```

### Characters

```cpp
isalnum(c) // checks whether a character is 'a'-'z', 'A'-'Z', or '0'-'9'

tolower(c) // converts letter to lowercase
toupper(c) // converts letter to uppercase
```

### Set

```cpp
set.insert(i);
set.erase(i);
set.clear()
set.count(i); // 1 if i is in set, 0 if i not in set

*set.begin(); *set.rbegin(); // accesses first/last term

for (auto it = myset.begin(); it != myset.end(); ++it) { //print out set
    cout << *it << ' ';
}
```

### Map

```cpp
unordered_map<int, int> umap; // same as map but unordered

for (auto i : map) {
    // loop through the map
    i.first // key
    i.second // value
}

map.count(i); // 1 if i is in map, 0 if i not in map
map.find(i)->second; // element at key i
map.erase(i);

map.begin(); map.rbegin(); // accesses first/last term based on the key
x = map.begin()->first; // sets x as key of first term
x = map.begin()->second; // sets x as value of first term
```

### Double-ended Queue

```cpp
deque<int> d;

d.push_front(i); // add elements to front of deque
d.pop_front(); // remove elements from front of deque
// other functions same as vector
```

### Stack

```cpp
stack<int> stk;

stk.empty(); // empty or not
stk.size(); // length of stack
stk.top(); // references top element
stk.push(x); // adds to top of stack
stk.pop(); // deletes topmost element
```

### Priority Queue

```cpp
priority_queue<int> pq; //orders largest to smallest
priority_queue <int, vector<int>, greater<int>> pq; //orders smallest to largest

pq.push(i); // add elements to back
pq.pop(); // remove elements from front
pq.top(); // accesses highest priority, largest value
pq.empty(); // checks if pq is empty
```

### Sorting and Searching

```cpp
sort(v.rbegin(), v.rend());

// sort n x m matrix by column
vector<array<long long,m>> a(n);
sort(a.begin(), a.end()); 

int ind = lower_bound(arr, arr+n, val) - arr; // returns ind of first element >= val
int ind = lower_bound(v.begin(), v.end(), val) - v.begin();
int ind = upper_bound(arr, arr+n, val) - arr; // returns ind of first element > val
int ind = upper_bound(v.begin(), v.end(), val) - v.begin();

// max and min
*max_element(arr, arr + n); // arrays
*min_element(arr, arr + n);
*max_element(vec.begin(), vec.end()); // vectors
*min_element(vec.begin(), vec.end());
```

### Bitwise Operators

```cpp
a & b // (AND) if both digits are 1, result is 1, else 0
a | b // (OR) if any of the digits are 1, result is 1, else 0 - 82878420
a ^ b // (XOR) if the digits are different, result is 1, else 0
~a // inverts all bits

if (num & 1) //odd
else //even

// check if x is a power of two
bool is_power_of_two = x && (!(x&(x-1)))

a << b //a*2^b, left bitshift by b
a >> b //a/2^b, right bitshift by b

//count how many ones in binary representation - 82545243
long long count = 0;
while(n != 0) {
    n = n&(n-1);
    count++;
}
```

### Math

```cpp
a = log2(x)
a = log10(x)

double x, y; // use int or ll for integer only powers
double ans = pow(x, y);
double ans = pow(x, 1.0/n); // take the nth root of x

int n = __gcd(x, y); // greatest common denominator

// rounding
ceil(x)
floor(x)
int n = floor(log10(a)) + 1; // number of digits in a
int ans = ceil(pow(x, 1.0/n)); // nth root of x, rounded up

//precision
cout << fixed;
cout << setprecision(n); //n decimal places
cout << ans << "\n";
```

### Ternary Operator

```cpp
variable = Expression1 ? Expression2 : Expression3;
// example
int n1 = 5, n2 = 10, max;
max = (n1 > n2) ? n1 : n2;
```

### Array Manipulation

```cpp
// iota
int a[5] = {0};
iota(a, a+5, 10); // changes a to {10, 11, 12, 13, 14}
char c[3] = {0};
iota(c, c+3, 'a'); // changes c to {'a', 'b', 'c'}

// copy
int source[n];
int target[n];
// copy first x elements from source to target
copy_n(source, x, target);

//checking if any element is negative
any_of(arr, arr+n, [](int x){return x < 0;})?
cout << "There exists a negative element" : cout << "All are positive elements";
//checking if no element is negative
none_of(arr, arr+n, [](int x){return x < 0;})?
cout << "No negative elements" : cout << "There are negative elements";
//checking if all elements are positive
all_of(arr, arr+n, [](int x) { return x>0; })?
cout << "All are positive elements" : cout << "All are not positive elements";
```

### Fenwick Tree

```cpp
// 0-indexed
template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    void modify(int x, T v) {
        while (x < n) {
        fenw[x] += v;
        x |= (x + 1);
        }
    }
    T get(int x) {
        T v{};
        while (x >= 0) {
        v += fenw[x];
        x = (x & (x + 1)) - 1;
        }
        return v;
    }
};
```

## Functions

### pow_mod

Compute large exponents a^e
  
```cpp
long long mod = 9223372036854775807;

long long pow_mod(long long a, long long e) {
    long long p = 1;
    while(e) {
        if (e & 1) {p = (p * a) % mod;}
        e >>= 1;
        a = (a * a) % mod;
    }
    return p;
}
```

### get_sum

Return sum of digits
  
```cpp
int get_sum(long long num) {
    int sum = 0;
    while (num != 0) {
        sum += num%10;
        num /= 10;
    }
    return sum;
}
```

### max_subarray_sum

Find max sum of contiguous subarray
  
```cpp
int max_subarray_sum(int a[], int size) {
    int max_so_far = a[0];
    int curr_max = a[0];
    for (int i = 1; i < size; i++) {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}
```

### add_edge

Create a tree
  
```cpp
const int N = 1e6;
vector<int> tree[N];
vector<vector<int>> node(N);

void add_edge(int a, int b) {
    node[a].push_back(b);
    node[b].push_back(a);
}
```

### dfs

Depth first search to find the length of each path from the root
  
```cpp
const int N = 1e6; //change depending on bounds of problem
vector<int> tree[N], used(N, 0);
map<int,int> dist;

//v is the root, d is typically 1 (starting distance)
void dfs(int v, int d) { 
    used[v] = 1;
    for (int vert : tree[v])
    {
        if(used[vert] != 1)
        {
            dist[vert] = d;
            dfs(vert, d+1);
        }
    }
}
```

### num_nodes

Find number of children in each subtree (including the parent, do -1 to get children)

```cpp
const int N = 1e6; //change depending on bounds of problem
int children[N];
vector<int> tree[N];

void num_nodes(int s, int e) { 
    //s is the root (current node), e is typically 0 (starting amount of children)
    vector<int>::iterator u;
    children[s] = 1;
    for (u = tree[s].begin(); u != tree[s].end(); u++) {
        if (*u == e) {continue;}
        num_nodes(*u, s);
        children[s] += children[*u];
    }
}
```

### divup

Round up when dividing a/b
  
```cpp
int divup(int a, int b) {
    if (a%b == 0) {return a/b;}
    else {return (a/b) + 1;}
}
```

### dec_to_binary

Find binary expression of decimal
  
```cpp
void dec_to_binary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
}
```

### prime_factors

Find prime factors in increasing order
  
```cpp
vector<int> prime_factors(long long n) {
    vector<int> primes;
    while (n % 2 == 0) {
        primes.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            primes.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) {primes.push_back(n);}
    return primes;
}
```

### get_primes

Return vector of largest prime divisor of all integers 2 - MX

```cpp
vector<int> get_primes(long long MX) {
    vector<int> primes(MX, 0);
    for (int i = 2; i < MX; i++) {
        if (primes[i]) {continue;}
        for (int j = i; j < MX; j += i) {primes[j] = i;}
    }
    return primes;
}
// primes[i] = largest prime divisor of i
// works faster than getting them one by one in int main()
```

### is_prime

Check if number is prime
  
```cpp
bool is_prime(int n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
```

### next_prime

Find next prime number, using the method `is_prime`
  
```cpp
int next_prime(int N) {
    if (N <= 1)
        return 2;
    int prime = N;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}
```

### choose

Compute find $nCk$ %MOD efficiently
  
```cpp
const long long MOD = 998244353, MAXN = 500005; //MAXN is the upper bound
long long fact[MAXN];

void calcFacts() { //run this in the first line of main() or solve()
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
long long powMod(long long a, long long e) {
    int r = 1;
    while (e) {
        if (e & 1)
            r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
long long invMod(long long a) {
    return powMod(a, MOD - 2);
}
long long choose(long long n, long long k) {
    if (k > n)
        return 0;
    return (fact[n] * invMod((fact[k] * fact[n - k]) % MOD)) % MOD;
}
```
