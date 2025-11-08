#include<iostream>
#include<string>
using namespace std;
struct node
{
	int seatno;
	int status;
	node *next,*prev;
};
node *temp,*nnode,*head,*tail;
node* a[10];
class list
{
	public:
		list()
		{
			head=tail=NULL;
		}
		void crt();
		void displayavailableseat();
		void bseat();
		void cancelseat();
		void bookedseat(); 
};
void list::crt()
{
		int p;
		for(int r=1;r<=10;r++)
		{
			a[r]=NULL;
			int count=1;
			for(int i=1;i<=7;i++)
			{
				nnode=new node;
				nnode->seatno=count;
				nnode->status=0;
				nnode->next=NULL;
				nnode->prev=NULL;
				if(a[r]==NULL)
				{
					a[r]=nnode;
					tail=nnode;
				}
				else
				{
					tail->next=nnode;
					nnode->prev=tail;
					tail=nnode;
				}
				count=count+1;
			}
			cout<<endl<<"Row is = "<<r<<" is created ";
		}
	
		displayavailableseat();
	
}
void list::displayavailableseat()
{
		cout<<endl<<"Available seats: "<<endl;
		for(int r=1;r<11;r++)
		{
			temp=a[r];
			cout<<endl<<"Row number= "<<r<<endl;
			while(temp!=NULL)
			{
				if(temp->status==0)
				
				{
					cout<<"Seatno: "<<temp->seatno<<"   "; 
				}
				temp=temp->next;
			}
		}
}
void list::bseat()
{
	string p;
	string ch;
	cout<<endl<<"Do you want to book seat?: ";
	cin>>p;
	if(p=="y")
	{
		int k,k1;
		string ch;
		do
		{
		
			cout<<endl<<"Enter the row that you want to book ";
			cin>>k1;
			temp=a[k1];
			cout<<endl<<"Enter the seatno in row "<<k1<<" that you want to book";
			cin>>k;
			while(temp->seatno!=k)
			{
				temp=temp->next;
			}
			temp->status=1;
			cout<<endl<<"Congratulations your seat "<<temp->seatno<<" in row numeber= "<<k1<<"book successfully";
			cout<<endl<<"Do you want to book more seats tickets : ";
			cin>>ch;
		}while(ch=="y");
		displayavailableseat();
	}		
}
void list::bookedseat()
{
		cout<<endl<<"Booked seats are: "<<endl;
		for(int r=1;r<11;r++)
		{
			temp=a[r];
			cout<<endl<<"Row number= "<<r<<endl;
			while(temp!=NULL)
			{
				if(temp->status==1)
				
				{
					cout<<"Seatno: "<<temp->seatno<<"   ";
				}
				temp=temp->next;
			}
		}
}
void list::cancelseat()
{
	bookedseat();
	string p;
	string ch;
	cout<<endl<<endl<<"Do you want to cancle seat?: ";
	cin>>p;
	if(p=="y")
	{
		int k,k1;
		string ch;
		do
		{
		
			cout<<endl<<"Enter the row in which you want to cancle the seat: ";
			cin>>k1;
			temp=a[k1];
			cout<<endl<<"Enter the seano in row "<<k1<<" that you want to cancle";
			cin>>k;
			while(temp->seatno!=k)
			{
				temp=temp->next;
			}
			temp->status=0;
			cout<<endl<<"You have cancled seatno "<<temp->seatno<<" in row numeber= "<<k1;
			cout<<endl<<"Do you want to cancle more seats tickets(y or n) : ";
			cin>>ch;
		}while(ch=="y");
		displayavailableseat();
	}
}
int main()
{
	cout<<endl<<"Welcome to cinemax to theater";
	list l1;
	l1.crt();
	l1.bseat();
	l1.cancelseat();
}

