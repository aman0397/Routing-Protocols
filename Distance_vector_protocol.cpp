//
//  main.cpp
//  Distance_vector_protocol
//
//  Created by Aman Khullar on 10/24/17.
//  Copyright © 2017 Aman Khullar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define inf 100000

typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<ii> adj_list[100006];
vector<int> dist(100006,inf);
vector<int> first(100006);
int main()
{
    int n,m;
    cout<<"Enter the number of nodes in the graph\n";
    cin>>n;
    cout<<"Enter the number of edges in the graph\n";
    cin>>m;
    cout<<"Enter the edges\n";
    int u,v,c;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c;
        adj_list[u].push_back(make_pair(v, c));
        adj_list[v].push_back(make_pair(u, c));
    }
    int s,t;
    cout<<"Enter the source and destination vertex\n";
    cin>>s>>t;
    dist[t]=0;
    queue<int> active;
    active.push(t);
    while(!active.empty())
    {
        int temp=active.front();
        active.pop();
        for(vector<ii>::iterator it=adj_list[temp].begin();it!=adj_list[temp].end();it++)
        {
            if(dist[it->first]>dist[temp]+it->second)
            {
                dist[it->first]=dist[temp]+it->second;
                active.push(it->first);
                first[it->first]=temp;
            }
        }
    }
    cout<<"Shortest delay in the path from source to destination is\n";
    cout<<dist[s]<<"\n";
    return 0;
}
