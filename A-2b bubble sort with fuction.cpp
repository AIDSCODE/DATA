#include <iostream>
using namespace std;

float a[20];  
int n;        

void bubbleSort()
{
    int i, pass, comp, swap;
    float temp;

    cout << endl << "Bubble Sort Passes:" << endl;
    comp = n;

    for (pass = 0; pass < n - 1; pass++)
    {
        swap = 0;
        cout << "Pass " << pass + 1 << ": comparisons = " << comp - 1 << endl << "  ";

        for (i = 0; i < n - 1 - pass; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                comp = n - pass - 1;
                swap = 1;
            }
        }

        cout << "Output:  ";
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl << " ";

        if (swap == 0)
            break; 
    }
}

int main()
{
    int i;

    cout << "Enter number of elements for Bubble Sort: ";
    cin >> n;

    cout << "Enter " << n << " percentages:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    bubbleSort();

    cout << endl << "Final Sorted Bubble Sort:" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << endl << "Top 5 percentages of the students:" << endl;
    int limit = 5;
    if (n < 5)
    {
        limit = n;
    }

    for (i = n - 1; i >= n - limit; i--)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

