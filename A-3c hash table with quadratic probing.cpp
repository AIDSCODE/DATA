#include <iostream>
#include <cstring>
using namespace std;

struct record 
{
	char hashn[20];  
    char cname[20];  
	int hashmo;         
    int mobno;            
};

int main() 
{
    int n;
    record Hash[10];
	record Qhash[10]; 

    cout << "How many records do you want to store? ";
    cin >> n;

    for (int i = 0; i < 10; i++) 
	{
		strcpy(Hash[i].hashn,"none");
		Hash[i].hashmo = -1;

        strcpy(Qhash[i].cname, "none");
        Qhash[i].mobno = -1;

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


        if (Qhash[h].mobno == -1) 
		{
            strcpy(Qhash[h].cname, Tname);
            Qhash[h].mobno = tel;
        } else {
            for (int j = 1; j < 10; j++) 
			{
                int nh = (h + j * j) % 10;
                if (Qhash[nh].mobno == -1) 
				{
                    strcpy(Qhash[nh].cname, Tname);
                    Qhash[nh].mobno = tel;
                    break;
                }
            }
        }

    }

    cout <<endl<< "Quadratic Probing Hash Table"<<endl;
    for (int i = 0; i < 10; i++)
        cout << Qhash[i].cname << "    " << Qhash[i].mobno << endl;



    cout <<endl<< "Searching by Name" << endl;
    char searchName[20];
    cout << "Enter the name to search: ";
    cin >> searchName;

    int totalSearch = 0;
    for (int j = 0; searchName[j] != '\0'; j++)
        totalSearch += searchName[j];
    int h = totalSearch % 10;
    int match = 0;
    for (int i = 0; i < 10; i++) 
	{
        int nh = (h + i * i) % 10;
        if (strcmp(Qhash[nh].cname, searchName) == 0) 
		{
            cout << "Found in Quadratic Probing at index " << nh << " with Telephone No: " << Qhash[nh].mobno << endl;
            match = 1;
            break;
        }
        if (Qhash[nh].mobno == -1)
            break;
    }
    if (!match)
        cout << "Not found in Quadratic Probing Table." << endl;

}

