#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────────
//  recursion.h  —  DSA Recursion Functions (Header)
//  Covers: Factorial, Fibonacci, Power, GCD, Sum of Digits, Binary Search,
//          Tower of Hanoi, String Reverse, Palindrome, Array Sum, Min/Max
// ─────────────────────────────────────────────────────────────────────────────

// ── 1. Factorial ─────────────────────────────────────────────────────────────
// O(n) time | O(n) space (call stack)
long long factorial(int n);

// ── 2. Fibonacci ─────────────────────────────────────────────────────────────
// Naive:     O(2^n) time | O(n) space  ← Very slow!
// Memoized:  O(n)   time | O(n) space  ← Fast
long long fibonacci(int n);
long long fibMemo(int n, vector<long long>& memo);

// ── 3. Power ─────────────────────────────────────────────────────────────────
// Simple:    O(n)     time | O(n)     space
// Fast:      O(log n) time | O(log n) space  ← Exponentiation by Squaring
double powerSimple(double x, int n);
double fastPower(double x, int n);

// ── 4. GCD — Euclidean Algorithm ─────────────────────────────────────────────
// O(log min(a,b)) time | O(log min(a,b)) space
int gcd(int a, int b);
int lcm(int a, int b);

// ── 5. Sum of Digits ─────────────────────────────────────────────────────────
// O(d) time where d = number of digits | O(d) space
int sumDigits(int n);
int countDigits(int n);

// ── 6. Reverse a Number ──────────────────────────────────────────────────────
int reverseNumber(int n, int rev = 0);

// ── 7. Binary Search ─────────────────────────────────────────────────────────
// O(log n) time | O(log n) space
// Array must be SORTED
int binarySearch(int arr[], int low, int high, int target);

// ── 8. Tower of Hanoi ────────────────────────────────────────────────────────
// O(2^n) time | O(n) space
void towerOfHanoi(int n, char src, char dest, char aux);

// ── 9. String Functions ──────────────────────────────────────────────────────
// All O(n) time | O(n) space
void reverseString(string& s, int left, int right);
bool isPalindrome(const string& s, int left, int right);
int stringLength(const char* s);

// ── 10. Array Recursion ──────────────────────────────────────────────────────
int arraySum(int arr[], int n);
int arrayMax(int arr[], int n);
int arrayMin(int arr[], int n);
bool isSorted(int arr[], int n);

// ── 11. Number Theory ────────────────────────────────────────────────────────
bool isPrime(int n, int divisor = 2);
int sumOfN(int n);            // 1 + 2 + ... + n
long long combinations(int n, int r);  // nCr

// ── 12. Print Patterns ───────────────────────────────────────────────────────
void printNto1(int n);
void print1toN(int n);

#endif // RECURSION_H
