#include <iostream>
#include <vector>
#include <queue>
#include <graphics.h>

#define inf 100006

using namespace std;

typedef pair<int,int> ii;

vector<ii> adj_list[10006];
vector<int> x_coordinate(10);
vector<int> y_coordinate(10);
void dijkstra(int,int);
void make_graph();


int main()
{
    int n,m,u,v,c;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,NULL);
    cout<<"Enter the number of nodes of the graph\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;
    make_graph();
    cout<<"Enter the edges with cost\n";
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c;
        adj_list[u].push_back(make_pair(v,c));
        adj_list[v].push_back(make_pair(u,c));
        line(x_coordinate[u],y_coordinate[u],x_coordinate[v],y_coordinate[v]);
    }
    
    for(int i=1;i<=n;i++)
        dijkstra(i,n);
    //getch();
    delay(5000);
    //cin>>n;
    closegraph();
}

//int count=0;

void dijkstra(int source,int n)
{
    vector<int> dist(100006,inf);
    priority_queue<ii,vector<ii>,greater<ii> > q;
    dist[source]=0;
    q.push(make_pair(0,source));
    while(!q.empty())
    {
        ii temp=q.top();
        q.pop();
        for(vector<ii>::iterator it=adj_list[temp.second].begin();it!=adj_list[temp.second].end();it++)
        {
            if(dist[it->first]>temp.first+it->second)
            {
                dist[it->first]=dist[temp.second]+it->second;
                q.push(make_pair(dist[it->first],it->first));
                fillellipse(x_coordinate[it->first],y_coordinate[it->first],5,5);
                delay(1000);
            }
        }
    }
    cout<<"Distances are for source"<<source<<"\n";
    cout<<"Node\tDistance\n";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"\t"<<dist[i]<<"\n";
    }
    cout<<"\n";
}

void make_graph()
{
    int x_mid=getmaxx()/2;
    int y_mid=getmaxy()/2;
    circle(x_mid,100,15);
    outtextxy(x_mid,100,"A");
    x_coordinate[1]=x_mid;
    y_coordinate[1]=100;
    circle(x_mid-100,250,15);
    outtextxy(x_mid-100,250,"B");
    x_coordinate[2]=x_mid-100;
    y_coordinate[2]=250;
    circle(x_mid+100,250,15);
    outtextxy(x_mid+100,250,"C");
    x_coordinate[3]=x_mid+100;
    y_coordinate[3]=250;
    circle(x_mid-50,400,15);
    outtextxy(x_mid-50,400,"D");
    x_coordinate[4]=x_mid-50;
    y_coordinate[4]=400;
    circle(x_mid+50,400,15);
    outtextxy(x_mid+50,400,"E");
    x_coordinate[5]=x_mid+50;
    y_coordinate[5]=400;
}
