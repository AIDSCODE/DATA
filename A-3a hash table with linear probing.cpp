#include <iostream>
#include <cstring>
using namespace std;

struct record 
{
	char hashn[20];
    char name[20];   
	int hashmo;  
    int telno;            
};

int main() 
{
    int n;
    record Hash[10];
    record lHash[10];

    cout << "How many records do you want to store? ";
    cin >> n;

    for (int i = 0; i < 10; i++) 
	{
		strcpy(Hash[i].hashn,"none");
		Hash[i].hashmo = -1;
		
        strcpy(lHash[i].name, "none");
        lHash[i].telno = -1;
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


        if (lHash[h].telno == -1) 
		{
            strcpy(lHash[h].name, Tname);
            lHash[h].telno = tel;
        } else {
            for (int j = 1; j < 10; j++) 
			{
                int nh = (h + j) % 10;
                if (lHash[nh].telno == -1) 
				{
                    strcpy(lHash[nh].name, Tname);
                    lHash[nh].telno = tel;
                    break;
                }
            }
        }
    }


    cout <<endl<< "Linear Probing Hash Table"<<endl;
    for (int i = 0; i < 10; i++)
        cout << lHash[i].name << "    " << lHash[i].telno << endl;

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
        int nh = (h + i) % 10;
        if (strcmp(lHash[nh].name, searchName) == 0) 
		{
            cout << "Found in Linear Probing at index " << nh << " with Telephone No: " << lHash[nh].telno << endl;
            match = 1;
            break;
        }
        if (lHash[nh].telno == -1)
            break;
    }
    if (!match)
        cout << "Not found in Linear Probing Table." << endl;

}

