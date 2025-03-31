// C++ program to find factorial of a number using iteration
#include <iostream>
using namespace std;

int main()
{
    int count=0;
    // number n whose factorial needs to be find
    int n = 9;
    count++;
    // initialize fact variable with 1
    double fact = 1;
    count++;

    // loop calculating factorial
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
        count++;
    }
    // print the factorial of n
    cout << "Factorial of " << n << " is " << fact << endl;
    count++;
    count++;
    cout << "Number of iterations: " << count << endl;

    return 0;
}