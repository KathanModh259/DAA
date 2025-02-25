#include <iostream>
using namespace std;

int count=0;
void fib(int num)
{
    int x = 0, y = 1, z = 0;
    count++;
    for (int i = 0; i < num; i++)
    {
        cout << x << " ";
        
        z = x + y;
        x = y;
        y = z;
        count++;
    }
}
int main()
{
    int num;
    count++;
    cout << "Enter the number : ";
    count++;
    cin >> num;
    count++;
    cout << "\nThe fibonacci series : ";
    count++;
    fib(num);
    count++;
    count++;
    count++;
    cout << "\nTotal count of operations : " << count;
    return 0;
}