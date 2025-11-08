#include <iostream>
using namespace std;

float b[20]; 
int k;       

void selectionSort()
{
    int i, j, pass, minIndex;
    float temp;

    cout << endl << "Selection Sort Passes:" << endl;
    for (pass = 0; pass < k - 1; pass++)
    {
        minIndex = pass;
        cout << "Pass " << pass + 1 << ": comparisons = " << k - pass - 1 << endl << " ";

        for (j = pass + 1; j < k; j++)
        {
            if (b[j] < b[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != pass)
        {
            temp = b[pass];
            b[pass] = b[minIndex];
            b[minIndex] = temp;
        }

        cout << "Output:  ";
        for (i = 0; i < k; i++)
            cout << b[i] << " ";
        cout << endl << " ";
    }
}

int main()
{
    int i;

    cout << "Enter number of elements for Selection Sort: ";
    cin >> k;

    cout << "Enter " << k << " percentages:" << endl;
    for (i = 0; i < k; i++)
        cin >> b[i];

    selectionSort();

    cout << endl << "Final Sorted Selection Sort:" << endl;
    for (i = 0; i < k; i++)
        cout << b[i] << " ";
    cout << endl;

    cout << endl << "Top 5 percentages of the students:" << endl;
    int limit = 5;
    if (k < 5)
    {
    limit = k;
    }
    
    for (i = k - 1; i >= k - limit; i--)
    {
    cout << b[i] << " ";
    }
}

