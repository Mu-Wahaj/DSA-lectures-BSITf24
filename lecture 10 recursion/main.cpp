#include "recursion.h"
#include <iomanip>
#include <vector>

// ─────────────────────────────────────────────────────────────────────────────
//  main.cpp  —  Driver: Demonstrates and tests all recursive functions
//  Compile: g++ main.cpp recursion.cpp -o recursion_demo
//  Run    : ./recursion_demo
// ─────────────────────────────────────────────────────────────────────────────

void printBanner(const string& title) {
    cout << "\n";
    cout << "╔══════════════════════════════════════════════════╗\n";
    cout << "║  " << left << setw(47) << title << "║\n";
    cout << "╚══════════════════════════════════════════════════╝\n";
}

void printSubHeader(const string& title) {
    cout << "\n  ── " << title << " ──\n";
}

int main() {
    cout << "================================================\n";
    cout << "   DSA RECURSION — COMPLETE DEMO & TEST\n";
    cout << "================================================\n";

    // ─────────────────────────────────────────────────────
    //  1. FACTORIAL
    // ─────────────────────────────────────────────────────
    printBanner("1. FACTORIAL  [O(n) time | O(n) space]");
    for (int i = 0; i <= 10; i++) {
        cout << "  factorial(" << i << ") = " << factorial(i) << "\n";
    }
    cout << "\n  Edge Cases:\n";
    cout << "  factorial(0) = " << factorial(0) << "  (0! = 1 by definition)\n";
    cout << "  factorial(12) = " << factorial(12) << "\n";

    // ─────────────────────────────────────────────────────
    //  2. FIBONACCI
    // ─────────────────────────────────────────────────────
    printBanner("2. FIBONACCI  [Naive: O(2^n) | Memo: O(n)]");
    printSubHeader("Naive Fibonacci (first 12 values)");
    cout << "  Fib: ";
    for (int i = 0; i <= 12; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << "\n";

    printSubHeader("Memoized Fibonacci (first 20 values)");
    cout << "  Fib: ";
    for (int i = 0; i <= 20; i++) {
        vector<long long> dp(i + 2, -1);
        cout << fibMemo(i, dp) << " ";
    }
    cout << "\n";

    printSubHeader("Large Fibonacci (with Memoization)");
    for (int n : {30, 40, 50}) {
        vector<long long> dp(n + 1, -1);
        cout << "  fib(" << n << ") = " << fibMemo(n, dp) << "\n";
    }

    // ─────────────────────────────────────────────────────
    //  3. POWER
    // ─────────────────────────────────────────────────────
    printBanner("3. POWER  [Simple: O(n) | Fast: O(log n)]");
    printSubHeader("Simple Power");
    cout << "  powerSimple(2, 10) = " << powerSimple(2, 10) << "\n";
    cout << "  powerSimple(3,  5) = " << powerSimple(3,  5) << "\n";
    cout << "  powerSimple(5,  0) = " << powerSimple(5,  0) << "  (anything^0 = 1)\n";

    printSubHeader("Fast Power — Exponentiation by Squaring");
    cout << "  fastPower(2, 10) = " << fastPower(2, 10) << "\n";
    cout << "  fastPower(2, 32) = " << fastPower(2, 32) << "\n";
    cout << "  fastPower(3,  7) = " << fastPower(3,  7) << "\n";
    cout << "  fastPower(1.5, 4) = " << fastPower(1.5, 4) << "\n";

    // ─────────────────────────────────────────────────────
    //  4. GCD & LCM
    // ─────────────────────────────────────────────────────
    printBanner("4. GCD & LCM  [O(log min(a,b))]");
    int pairs[][2] = {{48, 18}, {100, 75}, {17, 13}, {36, 24}, {0, 5}};
    for (auto& p : pairs) {
        cout << "  GCD(" << p[0] << ", " << p[1] << ") = " << gcd(p[0], p[1]);
        if (p[0] > 0 && p[1] > 0)
            cout << "  |  LCM = " << lcm(p[0], p[1]);
        cout << "\n";
    }

    // ─────────────────────────────────────────────────────
    //  5. SUM OF DIGITS
    // ─────────────────────────────────────────────────────
    printBanner("5. SUM OF DIGITS  [O(log10 n)]");
    for (int n : {0, 5, 123, 9999, 12345678}) {
        cout << "  sumDigits(" << n << ") = " << sumDigits(n)
             << "  |  digits: " << countDigits(n) << "\n";
    }

    // ─────────────────────────────────────────────────────
    //  6. REVERSE NUMBER
    // ─────────────────────────────────────────────────────
    printBanner("6. REVERSE NUMBER  [O(d)]");
    for (int n : {123, 1000, 98765, 1}) {
        cout << "  reverseNumber(" << n << ") = " << reverseNumber(n) << "\n";
    }

    // ─────────────────────────────────────────────────────
    //  7. BINARY SEARCH
    // ─────────────────────────────────────────────────────
    printBanner("7. BINARY SEARCH  [O(log n)]");
    int sortedArr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int sz = sizeof(sortedArr) / sizeof(sortedArr[0]);
    cout << "  Array: ";
    for (int x : sortedArr) cout << x << " ";
    cout << "\n";
    for (int target : {23, 91, 2, 50, 38}) {
        int idx = binarySearch(sortedArr, 0, sz - 1, target);
        if (idx != -1)
            cout << "  Search(" << target << ") → Found at index " << idx << "\n";
        else
            cout << "  Search(" << target << ") → Not found\n";
    }

    // ─────────────────────────────────────────────────────
    //  8. TOWER OF HANOI
    // ─────────────────────────────────────────────────────
    printBanner("8. TOWER OF HANOI  [O(2^n) moves]");
    for (int disks = 1; disks <= 3; disks++) {
        cout << "\n  Tower of Hanoi with " << disks << " disk(s):\n";
        cout << "  (Minimum moves = 2^" << disks << " - 1 = " << ((1 << disks) - 1) << ")\n";
        towerOfHanoi(disks, 'A', 'C', 'B');
    }

    // ─────────────────────────────────────────────────────
    //  9. STRING FUNCTIONS
    // ─────────────────────────────────────────────────────
    printBanner("9. STRING FUNCTIONS  [O(n)]");

    printSubHeader("Reverse String");
    string words[] = {"hello", "recursion", "DSA", "abcde"};
    for (auto& w : words) {
        string orig = w;
        reverseString(w, 0, (int)w.size() - 1);
        cout << "  \"" << orig << "\" → \"" << w << "\"\n";
    }

    printSubHeader("Palindrome Check");
    vector<string> tests = {"racecar", "hello", "madam", "level", "world", "abcba"};
    for (auto& s : tests) {
        cout << "  isPalindrome(\"" << s << "\") = "
             << (isPalindrome(s, 0, (int)s.size() - 1) ? "true" : "false") << "\n";
    }

    printSubHeader("String Length");
    const char* strs[] = {"hello", "", "recursion", "DSA lecture"};
    for (auto s : strs) {
        cout << "  length(\"" << s << "\") = " << stringLength(s) << "\n";
    }

    // ─────────────────────────────────────────────────────
    //  10. ARRAY RECURSION
    // ─────────────────────────────────────────────────────
    printBanner("10. ARRAY RECURSION  [O(n)]");
    int arr1[] = {3, 7, 1, 9, 4, 6, 2, 8, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "  Array: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";
    cout << "  Sum    = " << arraySum(arr1, n1) << "\n";
    cout << "  Max    = " << arrayMax(arr1, n1) << "\n";
    cout << "  Min    = " << arrayMin(arr1, n1) << "\n";
    cout << "  Sorted = " << (isSorted(arr1, n1) ? "yes" : "no") << "\n";

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\n  Sorted array: 1 2 3 4 5 6 7\n";
    cout << "  Sorted = " << (isSorted(arr2, n2) ? "yes" : "no") << "\n";

    // ─────────────────────────────────────────────────────
    //  11. NUMBER THEORY
    // ─────────────────────────────────────────────────────
    printBanner("11. NUMBER THEORY");

    printSubHeader("isPrime");
    for (int n : {2, 3, 4, 7, 13, 17, 20, 29, 49}) {
        cout << "  isPrime(" << n << ") = " << (isPrime(n) ? "true" : "false") << "\n";
    }

    printSubHeader("Sum 1 to N");
    for (int n : {5, 10, 100}) {
        cout << "  sumOfN(" << n << ") = " << sumOfN(n)
             << "  [formula: n*(n+1)/2 = " << n*(n+1)/2 << "]\n";
    }

    printSubHeader("Combinations nCr");
    cout << "  C(5,2) = " << combinations(5,2) << "  (expect 10)\n";
    cout << "  C(6,3) = " << combinations(6,3) << "  (expect 20)\n";
    cout << "  C(10,4) = " << combinations(10,4) << "  (expect 210)\n";

    // ─────────────────────────────────────────────────────
    //  12. PRINT PATTERNS
    // ─────────────────────────────────────────────────────
    printBanner("12. PRINT PATTERNS  [O(n)]");
    cout << "  N to 1 (n=8): ";  printNto1(8);  cout << "\n";
    cout << "  1 to N (n=8): ";  print1toN(8);  cout << "\n";

    // ─────────────────────────────────────────────────────
    //  SUMMARY TABLE
    // ─────────────────────────────────────────────────────
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║           COMPLEXITY CHEAT SHEET (EXAM READY)                ║\n";
    cout << "╠════════════════════════╦══════════════╦═══════════════════════╣\n";
    cout << "║ Function               ║ Time         ║ Space                 ║\n";
    cout << "╠════════════════════════╬══════════════╬═══════════════════════╣\n";
    cout << "║ factorial(n)           ║ O(n)         ║ O(n)                  ║\n";
    cout << "║ fibonacci naive        ║ O(2^n)       ║ O(n)                  ║\n";
    cout << "║ fibonacci memoized     ║ O(n)         ║ O(n)                  ║\n";
    cout << "║ powerSimple(x,n)       ║ O(n)         ║ O(n)                  ║\n";
    cout << "║ fastPower(x,n)         ║ O(log n)     ║ O(log n)              ║\n";
    cout << "║ gcd(a,b)               ║ O(log n)     ║ O(log n)              ║\n";
    cout << "║ sumDigits(n)           ║ O(log10 n)   ║ O(log10 n)            ║\n";
    cout << "║ binarySearch           ║ O(log n)     ║ O(log n)              ║\n";
    cout << "║ towerOfHanoi(n)        ║ O(2^n)       ║ O(n)                  ║\n";
    cout << "║ reverseString/Palindrome║ O(n)        ║ O(n)                  ║\n";
    cout << "║ arraySum/Max/Min       ║ O(n)         ║ O(n)                  ║\n";
    cout << "║ combinations(n,r)      ║ O(2^n)       ║ O(n)                  ║\n";
    cout << "╚════════════════════════╩══════════════╩═══════════════════════╝\n";

    cout << "\n  All tests completed!\n\n";
    return 0;
}
