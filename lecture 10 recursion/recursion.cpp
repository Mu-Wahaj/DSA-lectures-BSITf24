#include "recursion.h"
#include <climits>

// ─────────────────────────────────────────────────────────────────────────────
//  recursion.cpp  —  Implementations of all recursive functions
// ─────────────────────────────────────────────────────────────────────────────


// ═══════════════════════════════════════════════════════════════════════════
//  1. FACTORIAL
//  Base Case : n == 0  →  return 1
//  Rec. Case : n * factorial(n-1)
//  Time  : O(n)  |  Space : O(n)
// ═══════════════════════════════════════════════════════════════════════════
long long factorial(int n) {
    // Base Case: 0! = 1
    if (n == 0) return 1;
    // Recursive Case
    return (long long)n * factorial(n - 1);
}


// ═══════════════════════════════════════════════════════════════════════════
//  2a. FIBONACCI — Naive (DO NOT use for large n)
//  Base Cases : n==0 → 0, n==1 → 1
//  Rec. Case  : fib(n-1) + fib(n-2)
//  Time  : O(2^n)  |  Space : O(n)
// ═══════════════════════════════════════════════════════════════════════════
long long fibonacci(int n) {
    if (n == 0) return 0;   // Base Case 1
    if (n == 1) return 1;   // Base Case 2
    return fibonacci(n - 1) + fibonacci(n - 2); // Two recursive calls = exponential!
}

// ═══════════════════════════════════════════════════════════════════════════
//  2b. FIBONACCI — Memoized (Dynamic Programming top-down)
//  Stores already-computed values to avoid recomputation
//  Time  : O(n)  |  Space : O(n)
//  Usage : vector<long long> dp(n+1, -1); fibMemo(n, dp);
// ═══════════════════════════════════════════════════════════════════════════
long long fibMemo(int n, vector<long long>& memo) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];  // Already computed — return cached
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}


// ═══════════════════════════════════════════════════════════════════════════
//  3a. POWER — Simple Recursive
//  Base Case : n == 0  →  return 1
//  Rec. Case : x * power(x, n-1)
//  Time  : O(n)  |  Space : O(n)
// ═══════════════════════════════════════════════════════════════════════════
double powerSimple(double x, int n) {
    if (n == 0) return 1.0;             // Base Case: x^0 = 1
    return x * powerSimple(x, n - 1);  // x^n = x * x^(n-1)
}

// ═══════════════════════════════════════════════════════════════════════════
//  3b. FAST POWER — Exponentiation by Squaring
//  x^n = (x^(n/2))^2      if n is even
//  x^n = x * (x^(n/2))^2  if n is odd
//  Time  : O(log n)  |  Space : O(log n)
//  This is a Divide & Conquer approach!
// ═══════════════════════════════════════════════════════════════════════════
double fastPower(double x, int n) {
    if (n == 0) return 1.0;              // Base Case
    double half = fastPower(x, n / 2);  // Solve half the problem
    if (n % 2 == 0)
        return half * half;              // Even: square the half
    else
        return x * half * half;          // Odd: multiply one extra x
}


// ═══════════════════════════════════════════════════════════════════════════
//  4. GCD — Euclidean Algorithm
//  Base Case : b == 0  →  return a
//  Rec. Case : gcd(b, a % b)
//  Time  : O(log min(a,b))  |  Space : O(log min(a,b))
// ═══════════════════════════════════════════════════════════════════════════
int gcd(int a, int b) {
    if (b == 0) return a;       // Base Case
    return gcd(b, a % b);       // Recursive: replace a with b, b with a%b
}

// LCM using GCD: LCM(a,b) = (a*b) / GCD(a,b)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // Divide first to avoid overflow
}


// ═══════════════════════════════════════════════════════════════════════════
//  5. SUM OF DIGITS
//  Base Case : n == 0  →  return 0
//  Rec. Case : (n % 10) + sumDigits(n / 10)
//  Time  : O(d)  |  Space : O(d)  where d = number of digits
// ═══════════════════════════════════════════════════════════════════════════
int sumDigits(int n) {
    if (n == 0) return 0;               // Base Case
    return (n % 10) + sumDigits(n / 10); // Last digit + sum of rest
}

// Count number of digits in n
int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}


// ═══════════════════════════════════════════════════════════════════════════
//  6. REVERSE A NUMBER
//  Uses accumulator pattern (tail recursion friendly)
//  Time  : O(d)  |  Space : O(d)
// ═══════════════════════════════════════════════════════════════════════════
int reverseNumber(int n, int rev) {
    if (n == 0) return rev;             // Base Case
    return reverseNumber(n / 10, rev * 10 + n % 10);
}


// ═══════════════════════════════════════════════════════════════════════════
//  7. BINARY SEARCH (Recursive)
//  Precondition: array must be SORTED in ascending order
//  Base Cases : low > high → not found (-1)
//               arr[mid] == target → found (mid)
//  Rec. Case  : search left or right half
//  Time  : O(log n)  |  Space : O(log n)
// ═══════════════════════════════════════════════════════════════════════════
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1;                      // Base Case: not found
    int mid = low + (high - low) / 2;               // Avoid overflow vs (low+high)/2
    if (arr[mid] == target) return mid;             // Found!
    if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target); // Target in right half
    else
        return binarySearch(arr, low, mid - 1, target);  // Target in left half
}


// ═══════════════════════════════════════════════════════════════════════════
//  8. TOWER OF HANOI
//  Move n disks from src → dest using aux
//  Base Case : n == 1  →  move directly
//  Rec. Case : move n-1 to aux, move disk n, move n-1 from aux to dest
//  Time  : O(2^n)  |  Space : O(n)  |  Minimum moves = 2^n - 1
// ═══════════════════════════════════════════════════════════════════════════
void towerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        cout << "  Move disk 1 from " << src << " → " << dest << "\n";
        return;
    }
    towerOfHanoi(n - 1, src, aux, dest);    // Step 1: Move n-1 disks to aux
    cout << "  Move disk " << n << " from " << src << " → " << dest << "\n";
    towerOfHanoi(n - 1, aux, dest, src);    // Step 3: Move n-1 disks from aux to dest
}


// ═══════════════════════════════════════════════════════════════════════════
//  9a. REVERSE A STRING (in-place using two pointers)
//  Base Case : left >= right  →  stop
//  Rec. Case : swap s[left] and s[right], recurse inward
//  Time  : O(n)  |  Space : O(n)
// ═══════════════════════════════════════════════════════════════════════════
void reverseString(string& s, int left, int right) {
    if (left >= right) return;          // Base Case
    swap(s[left], s[right]);            // Swap outer characters
    reverseString(s, left + 1, right - 1); // Recurse inward
}

// ═══════════════════════════════════════════════════════════════════════════
//  9b. CHECK PALINDROME
//  Base Case : left >= right  →  true (all matched)
//              s[left] != s[right]  →  false (mismatch)
//  Rec. Case : check inner substring
//  Time  : O(n)  |  Space : O(n)
// ═══════════════════════════════════════════════════════════════════════════
bool isPalindrome(const string& s, int left, int right) {
    if (left >= right) return true;         // Base Case: all chars matched
    if (s[left] != s[right]) return false;  // Mismatch found
    return isPalindrome(s, left + 1, right - 1);
}

// ═══════════════════════════════════════════════════════════════════════════
//  9c. STRING LENGTH (counting null terminator)
//  Time  : O(n)  |  Space : O(n)
// ═══════════════════════════════════════════════════════════════════════════
int stringLength(const char* s) {
    if (*s == '\0') return 0;       // Base Case: end of string
    return 1 + stringLength(s + 1); // Count this char + rest
}


// ═══════════════════════════════════════════════════════════════════════════
//  10. ARRAY RECURSION
//  Sum, Max, Min — all O(n) time and space
// ═══════════════════════════════════════════════════════════════════════════
int arraySum(int arr[], int n) {
    if (n == 0) return 0;                       // Base Case: empty array
    return arr[n - 1] + arraySum(arr, n - 1);  // Last + sum of rest
}

int arrayMax(int arr[], int n) {
    if (n == 1) return arr[0];                  // Base Case: one element
    int restMax = arrayMax(arr, n - 1);
    return max(arr[n - 1], restMax);            // Compare last with max of rest
}

int arrayMin(int arr[], int n) {
    if (n == 1) return arr[0];
    int restMin = arrayMin(arr, n - 1);
    return min(arr[n - 1], restMin);
}

bool isSorted(int arr[], int n) {
    if (n <= 1) return true;                    // Base Case: 0 or 1 elements
    if (arr[n - 2] > arr[n - 1]) return false; // Out of order
    return isSorted(arr, n - 1);               // Check rest
}


// ═══════════════════════════════════════════════════════════════════════════
//  11. NUMBER THEORY
// ═══════════════════════════════════════════════════════════════════════════

// Check if n is prime (trial division, recursive)
// Start divisor at 2; if no divisor found up to sqrt(n), it's prime
bool isPrime(int n, int divisor) {
    if (n < 2) return false;
    if (divisor * divisor > n) return true;     // Base Case: checked enough
    if (n % divisor == 0) return false;         // Divisible → not prime
    return isPrime(n, divisor + 1);             // Check next divisor
}

// Sum 1 + 2 + ... + n
int sumOfN(int n) {
    if (n == 0) return 0;
    return n + sumOfN(n - 1);
}

// nCr = n! / (r! * (n-r)!)  using Pascal's Triangle recursion
// nCr = nC(r-1) + (n-1)C(r-1)  →  NOT standard, use: nCr = (n-1)C(r) + (n-1)C(r-1)
long long combinations(int n, int r) {
    if (r == 0 || r == n) return 1;             // Base Cases
    return combinations(n - 1, r - 1) + combinations(n - 1, r); // Pascal's Identity
}


// ═══════════════════════════════════════════════════════════════════════════
//  12. PRINT PATTERNS
// ═══════════════════════════════════════════════════════════════════════════
void printNto1(int n) {
    if (n == 0) return;     // Base Case
    cout << n << " ";
    printNto1(n - 1);       // Print rest AFTER printing n
}

void print1toN(int n) {
    if (n == 0) return;     // Base Case
    print1toN(n - 1);       // Print smaller numbers FIRST
    cout << n << " ";
}
