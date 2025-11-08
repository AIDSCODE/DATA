#include <iostream>
#include <string>
using namespace std;

class Graph 
{
    int n, p;
    string city[10];        
    int Adjmat[10][10];     
    int visited[10];         
    int startIndex;          

public:
    Graph() 
    {
        for (int i = 0; i < 10; i++) 
        {
            for (int j = 0; j < 10; j++)
                Adjmat[i][j] = (i == j) ? 0 : -1;
            visited[i] = 0;
        }
        startIndex = 0;
    }

    void initialize();      
    int cityToIndex(string);  
    void store();          
    void display();            
    void DFS();             
    void startDFS();           
    void checkConnectivity();  
};

void Graph::initialize() 
{
    cout << "Enter number of cities: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Enter name of city " << i + 1 << ": ";
        cin >> city[i];
    }
}

int Graph::cityToIndex(string ct) 
{
    for (int i = 0; i < n; i++) 
    {
        if (city[i] == ct)
            return i;
    }
    return -1;
}

void Graph::store() 
{
    cout <<endl<< "Enter number of flight paths: ";
    cin >> p;

    for (int k = 0; k < p; k++) 
    {
        string s, d;
        int cost;

        cout <<endl<< "Enter Source City: ";
        cin >> s;
        int id1 = cityToIndex(s);

        cout << "Enter Destination City: ";
        cin >> d;
        int id2 = cityToIndex(d);

        cout << "Enter flight cost: ";
        cin >> cost;

        Adjmat[id1][id2] = Adjmat[id2][id1] = cost; 
    }
}

void Graph::display() 
{
    cout <<endl<< "Adjacency Matrix Representation of Graph:"<<endl;
   
    for (int i = 0; i < n; i++)
    {
        cout << char('A' + i) << " ";
        for (int j = 0; j < n; j++)
        {
            cout << Adjmat[i][j] << " ";
        }
        cout << endl;
}
}
void Graph::DFS() 
{
    visited[startIndex] = 1;
    cout << city[startIndex] << " ";

    for (int i = 0; i < n; i++) 
    {
        if (Adjmat[startIndex][i] > 0 && visited[i] == 0 && i != startIndex) 
        {
            int temp = startIndex;
            startIndex = i;
            DFS();           
            startIndex = temp; 
        }
    }
}

void Graph::startDFS() 
{
    string startCity;
    cout <<endl<< "Enter starting city for DFS: ";
    cin >> startCity;

    startIndex = cityToIndex(startCity);
    if (startIndex == -1) 
    {
        cout <<endl<< "Invalid city name entered for DFS:"<<endl;
        return;
    }

 
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS Traversal starting from " << startCity << ":";
    cout << endl;
}

void Graph::checkConnectivity() 
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    startIndex = 0;
    DFS();
}


int main() 
{
    Graph g;
    cout << " Flight Path Connectivity System ";
    g.initialize();
    g.store();
    g.display();
    g.startDFS();       
    g.checkConnectivity(); 
}

