#include<bits/stdc++.h>
using namespace std;
#define WHITE 1
#define GRAY 2
#define BLACK 3
int adj[100][100];
int color[100];
int parent [100];
int dis[100];
int node,edge;

void bfs(int snode)
{
    for(int i=0;i<node;i++)
    {
        color[i]=WHITE;
        dis[i]=INT_MIN;
        parent[i]=-1;
    }
    dis[snode]=0;
    parent[snode]=-1;
    queue<int>q;
    q.push(snode);
    while(!q.empty())
    {
        int x;
        x=q.front();
        q.pop();
        color[x]=GRAY;
        printf("%d ",x);
        for(int i=0;i<node;i++)
        {
            if(adj[x][i]==1)
            {
                if(color[i]==WHITE)
                {
                    q.push(i);
                    parent[i]=x;
                    dis[i]=dis[x]+1;
                }
            }

        }
        color[x]=BLACK;
    }

}

int main()
{
    freopen("bfs.txt","r",stdin);
    cin>>node>>edge;
    int n1,n2;
    for(int i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }

    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nAdjacent Node: \n";
    for(int i=0;i<node;i++)
    {
        cout<<"Node "<<i<<": ";
        for(int j=0;j<node;j++)
        {
            if(adj[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    bfs(0);

}

