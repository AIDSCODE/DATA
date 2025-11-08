#include <iostream>
using namespace std;

class queue 
{
public:
    int front, rare;
    int Q[20];
    int max;

    queue() 
	{
        front = 0;
        rare = -1;
        max = 5;
    }

    void Addjob();
    void Deletejob();
    void display();
    int isempty();
    int isfull();
};

int queue::isempty() 
{
    return (front == 0 && rare == -1);
}

int queue::isfull() 
{
    return (rare == max - 1);
}

void queue::Addjob() 
{
    char ch;
    int e;

    do {
        if (!isfull()) 
		{
            cout << "Enter element that you want to insert: ";
            cin >> e;
            rare++;
            Q[rare] = e;
            cout<<"Your Job is Successfully Added"<<endl;
        } 
		else 
		{
			display();
            cout << "Queue is full" << endl;
            break;
        }

        cout << "Do you want to add more? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void queue::Deletejob() 
{
    char ch;

    do {
        if (!isempty()) 
		{
            cout << "Job number " << Q[front] << " is deleted successfully." << endl;

            if (front == rare) 
			{
                front = 0;
                rare = -1;
            } 
			else 
			{
                front++;
            }
        } 
		else 
		{
			display();
            cout << "Queue is Empty" << endl;
            break;
        }

        cout << "Do you want to delete more elements? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void queue::display()
    {
    cout << "Elements of queue are: ";

    if (!isempty()) 
	{
        for (int i = front; i <= rare; i++) 
		{
            cout << Q[i] << "  ";
        }
        cout << endl;
    }
	else 
	{
        cout << "Queue is empty" << endl;
    }
}

int main() 

{
	
    queue l1;
    l1.Addjob();
    l1.Deletejob();

    return 0;
}

