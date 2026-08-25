// determinar si un numero es capicua o no
#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    int t = x; // variable temporal
    int inverso = 0;

    while (t > 0)
    {
        int c = t % 10;
        inverso *= 10; // 12 => 120; 123 => 1230
        inverso += c;  // 120 + 3 = 123; 1230 + 4 = 1234
        t /= 10;
    }

    if (x == inverso)
        cout << "Es capicua";
    else
        cout << "No es capicua";
}