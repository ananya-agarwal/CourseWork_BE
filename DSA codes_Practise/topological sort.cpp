#include<bits/stdc++.h>
using namespace std;

void add_Edge(int graph[][10], int i, int j)
{
    graph[i][j] = 1;
}

void remove_Edge(int graph[][10], int i, int j)
{
    graph[i][j] = 0;
}

int count_Edges(int graph[][10], int v)
{
    int i, j;
    int count = 0;
    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            if(graph[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}


int calculate_In_Degree(int graph[][10], int v, int j)
{
    int i;
    int count = 0;
    for(i=0; i<v; i++)
    {
        if(graph[i][j] == 1)
        {
            count++;
        }
    }
    return count;
}

bool search_List(list <int> l, int key)
{
    list <int> :: iterator it;
    for(it=l.begin(); it!=l.end(); it++)
    {
        if(*it == key)
        {
            return true;
        }
    }
    return false;
}

bool search_Queue(queue <int> s, int key)
{
    queue <int> q = s;
    while(!q.empty())
    {
        if(q.front() == key)
        {
            return true;
        }
        q.pop();
    }
    return false;
}

void display_List(list <int> l)
{
    list <int> :: iterator it;
    for(it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void topological_Sort(int graph[][10], int v, list <int> l, queue <int> s)
{
    int i, j, k;
    for(i=0; i<v; i++)
    {
        if(calculate_In_Degree(graph, v, i) == 0)
        {
            s.push(i);
        }
    }
    while(s.size() != 0)
    {
        k = s.front();
        s.pop();
        l.push_back(k);
        for(j=0; j<v; j++)
        {
            if(search_List(l, j) == false && search_Queue(s, j) == false)
            {
                remove_Edge(graph, k, j);
                if(calculate_In_Degree(graph, v, j) == 0)
                {
                    s.push(j);
                }
            }
        }
    }
    if(count_Edges(graph, v) != 0)
    {
        cout<<"\nCycle Exists in graph!"<<endl;
    }
    else
    {
        cout<<"Required Topological Sort : \n";
        display_List(l);
    }
}

int main()
{
    int v, i, j;
    int graph[10][10] = {0};
    char ch;
    list <int> l;
    queue <int> s;
    cout<<"Enter the no of vertices in graph : ";
    cin>>v;
    do
    {
        system("cls");
        cout<<"Enter the details of edge : \n";
        cout<<"\nEnter start vertex : ";
        cin>>i;
        while(i<0 || i>=v)
        {
            cout<<"\nEnter a vaild start vertex : ";
            cin>>i;
        }
        cout<<"\nEnter destination vertex : ";
        cin>>j;
        while(j<0 || j>=v)
        {
            cout<<"\nEnter a valid destination vertex : ";
            cin>>j;
        }
        add_Edge(graph, i, j);
        cout<<"\nDo you want to add more edges? (y/n) : ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    system("cls");
    topological_Sort(graph, v, l, s);
    return 0;
}
