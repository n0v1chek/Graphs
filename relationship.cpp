#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Graph
{
    int V;  
    map<pair<string, string>, int> names;
    vector<string> names1;
    vector<string> names2;
public:
    Graph(int start_V)
    {
        V = start_V;
    }
    void addEdge(string start, string end, int wt);
    void display();
};
void Graph::addEdge(string start, string end, int wt)
{
    names[make_pair(start, end)] = wt;
}
void Graph::display()
{
    int flag = 0;
    for (auto it : names)
    {
        names1.push_back(it.first.first);
        names2.push_back(it.first.second);
    }

    sort(names1.begin(), names1.end());
    auto last = unique(names1.begin(), names1.end());
    names1.erase(last, names1.end());

    sort(names2.begin(), names2.end());
    auto last2 = unique(names2.begin(), names2.end());
    names2.erase(last2, names2.end());

    for (auto col : names2)
    {
        cout << "\t" << col;
    }
    cout << "\n";

    for (auto row : names1)
    {
        int flag = 0;   
        for (auto col : names1)
        {
            if (!flag)
                cout << row;
            cout << "\t" << names[make_pair(row, col)];
            flag = 1;
        }

        cout << "\n";
    }

}
int main()
{
    Graph g(2);

    g.addEdge("Ilya", "Vika", 1);
    g.addEdge("Ilya", "Vlad", 2);
    g.addEdge("Ilya", "Nastya", 3);
    g.addEdge("Vlad", "Ignat", 1);
    g.addEdge("Vlad", "Ilya", 2);
    g.addEdge("Vlad", "Nastya", 6);
    g.addEdge("Nastya", "Ilya", 3);
    g.addEdge("Ignat", "Vlad", 1);
    g.addEdge("Vika", "Ilya", 1);
    g.display();
    return 0;
}