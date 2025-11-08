#include <iostream>
using namespace std;

int main()
{
    int n, k, i, j, pass, comp, swap, minIndex;
    float temp;
    float a[20];   
    float b[20];   
    cout << "Enter number of elements for Bubble Sort: ";
    cin  >> n;
   
    cout << "Enter " << n << " percentages:"<<endl;
    for (i = 0; i < n; i++) 
    cin >> a[i];
    cout <<endl<<"Bubble Sort Passes:"<<endl;
    comp = n;
    for (pass = 0; pass < n - 1; pass++) 
    {
        swap= 0;
        cout << "Pass " << pass + 1 << ": comparisons = " << comp - 1 <<endl<< "  ";
        for (i = 0; i < n - 1 - pass; i++) 
        {
            if (a[i] > a[i + 1]) 
            {
                temp = a[i];
                a[i]  = a[i + 1];
                a[i + 1] = temp;
                comp = n - pass - 1;
                swap = 1;
            }
        }
        cout << "Output:  ";
        for (i = 0; i < n; i++) 
		cout << a[i] << " ";
        cout << " "<<endl;
        if (swap == 0) 
		break;
    }
    cout <<endl<< "Final Sorted Bubblesort:"<<endl;
    for (i = 0; i < n; i++) 
	cout << a[i] << " ";
    
    cout <<endl<< "Enter number of elements for Selection Sort: ";
    cin  >> k;
    
    cout << "Enter " << k << " percentages:"<<endl;
    for (i = 0; i < k; i++) 
	cin >> b[i];

    cout <<endl<< "Selection Sort Passes:"<<endl;
    for (pass = 0; pass < k - 1; pass++) 
    {
        minIndex = pass;
        cout << "Pass " << pass + 1 << ": comparisons = " << k - pass - 1 <<endl<< " ";
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
        cout << "output:  ";
        for (i = 0; i < k; i++) 
		cout << b[i] << " ";
        cout <<endl<< " ";
    }
    cout <<endl<< "Final Sorted Selectionsort:"<<endl;
    for (i = 0; i < k; i++) 
	cout << b[i] << " ";
    cout <<endl<< " ";
}


