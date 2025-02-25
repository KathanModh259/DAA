
#include <iostream>
using namespace std;

int count = 0;
long long factorial(int n)
{
count++;
    if (n == 0 || n == 1)
    {
        count++;
        return 1;
    }

    count++;
    return n * factorial(n - 1);
}

int main()
{
    int num = 45;
    count++;
    cout << "Factorial of " << num << " is "
        << factorial(num) << endl;
    count++;
    count++;
    count++;
    cout << "Number of times function was called: " << count - 1 << endl;
    return 0;
}