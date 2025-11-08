#include <iostream>
#include <cstring>
using namespace std;

struct record 
{
	char hashn[20]; 
    char dname[20];
	int hashmo;        
    int number;      
};

int main() 
{
    int n;
    record Hash[10];
	record Dhash[10];

    cout << "How many records do you want to store? ";
    cin >> n;

    for (int i = 0; i < 10; i++) 
	{
		strcpy(Hash[i].hashn,"none");
		Hash[i].hashmo = -1;
		
        strcpy(Dhash[i].dname, "none");
        Dhash[i].number = -1;
    }

    cout <<endl<< "Empty Table"<<endl;
    for (int i = 0; i < 10; i++)
        cout << Hash[i].hashn << "    " << Hash[i].hashmo << endl;


    char Tname[20];
    int tel;
    for (int i = 0; i < n; i++) 
	{
        cout <<endl<< "Enter client's Name: ";
        cin >> Tname;
        cout << "Enter Telephone No.: ";
        cin >> tel;

        int total = 0;
        for (int j = 0; Tname[j] != '\0'; j++)
            total += Tname[j];
        int h = total % 10;


        if (Dhash[h].number == -1) 
		{
            strcpy(Dhash[h].dname, Tname);
            Dhash[h].number = tel;
        } else {
            int h2 = 7 - (total % 7);
            for (int j = 1; j < 10; j++) 
			{
                int nh = (h + j * h2) % 10;
                if (Dhash[nh].number == -1) 
				{
                    strcpy(Dhash[nh].dname, Tname);
                    Dhash[nh].number = tel;
                    break;
                }
            }
        }
    }

    cout <<endl<< "Double Hashing Hash Table"<<endl;
    for (int i = 0; i < 10; i++)
        cout << Dhash[i].dname << "    " << Dhash[i].number << endl;


    cout <<endl<< "Searching by Name" << endl;
    char searchName[20];
    cout << "Enter the name to search: ";
    cin >> searchName;

    int totalSearch = 0;
    for (int j = 0; searchName[j] != '\0'; j++)
        totalSearch += searchName[j];
    int h = totalSearch % 10;
    int match = 0;

    int m;
    cout<<"enter the prime number";
    cin>>m;
    int h2 = m - (totalSearch % m);
    for (int i = 0; i < 10; i++) 
	{
        int nh = (h + i * h2) % 10;
        if (strcmp(Dhash[nh].dname, searchName) == 0) 
		{
            cout << "Found in Double Hashing at index " << nh << " with Telephone No: " << Dhash[nh].number << endl;
            match = 1;
            break;
        }
        if (Dhash[nh].number == -1)
            break;
    }
    if (!match)
        cout << "Not found in Double Hashing Table." << endl;

}

