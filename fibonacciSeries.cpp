#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Limit of Sequence?";
    cin >> n;

    long long a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
    }

    cout << "The sum is " << a << endl;
    return 0;
}
