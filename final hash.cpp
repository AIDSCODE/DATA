#include <iostream>
#include <cstring>
using namespace std;

struct record 
{
	char hashn[20];
    char name[20];   
    char cname[20];  
    char dname[20];
	int hashmo;  
    int telno;       
    int mobno;       
    int number;      
};

int main() 
{
    int n;
    record Hash[10];
    record lHash[10];
	record Qhash[10]; 
	record Dhash[10];

    cout << "How many records do you want to store? ";
    cin >> n;

    for (int i = 0; i < 10; i++) 
	{
		strcpy(Hash[i].hashn,"none");
		Hash[i].hashmo = -1;
		
        strcpy(lHash[i].name, "none");
        lHash[i].telno = -1;

        strcpy(Qhash[i].cname, "none");
        Qhash[i].mobno = -1;

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


    cout <<endl<< "Linear Probing Hash Table"<<endl;
    for (int i = 0; i < 10; i++)
        cout << lHash[i].name << "    " << lHash[i].telno << endl;

    cout <<endl<< "Quadratic Probing Hash Table"<<endl;
    for (int i = 0; i < 10; i++)
        cout << Qhash[i].cname << "    " << Qhash[i].mobno << endl;

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


    match = 0;
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

    int m;
    cout<<"enter the prime number";
    cin>>m;
    match = 0;
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

    return 0;
}

