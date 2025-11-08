#include<iostream>
#include<algorithm>
using namespace std;
int main()     
{
	int n;
	int a[20];
	cout<<endl<<"how many students are present"; 
	cin>>n;            //to know the number that how many students are present 
	for(int i=0;i<n;i++)
	{
		cout<<"enter the roll numbers of the students";
		cin>>a[i];     //collecting the roll numbers of students
	 
	}
	cout<<endl<<"the roll numbers of students";     
	for(int i=0;i<n;i++)          //for loop for printing all the roll number of student
	{
		cout<<a[i]<<" ";       //to display the roll numbers of students
	 }
	 int k,m;
	 char ch;                //to get the input from the user in the form of y/n
	 do
	{
	m=0;                   
	 cout<<endl<<"enter roll number of the student thet we have to find out";
	 cin>>k;                    //roll no of student that present in training 
	 for(int i=0;i<n;i++)
	 {
	 	if(a[i]==k)
	 	{
	 		m=1;
	 		break;
		 }
		 
	 }
	 if(m==1)
	 {
	 	cout<<endl<<"present";        //for printing presence
	 }
	 else
	 {
	 	cout<<endl<<"absent";         //for printing absense
	 }
	 cout<<endl<<"do you want to continue? y/n";      //printing
	 cin>>ch;                                    // input in the form of y/n
	 
     }while(ch=='y');
     cout<<endl<<"binary search";
     cout<<endl<<"sorted data";
	 sort(a,a+n);
     for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";       //to display the roll numbers of students
	 } 

	 do{
	int f, l, mid, kvalue;
    cout << "Enter the key value";
    cin >> kvalue;

    int match = 0;
    f = 0;
    l = n;

    while(f <= l)
    {
        mid = (f + l) / 2;
        if(a[mid] == kvalue)
        {
            match = 1;
            break;
        }
        else if(a[mid] > kvalue)
        {
            l = mid - 1;
        }
        else
        {
            f = mid + 1;
        }
    }

    if(match == 1)
        cout << "Present";
    else
        cout << "Absent";
        cout<<endl<<"do you want to continue? y/n";      //printing
	 cin>>ch;                                    // input in the form of y/n
	 
     }while(ch=='y');
 

    return 0;
	 
}
