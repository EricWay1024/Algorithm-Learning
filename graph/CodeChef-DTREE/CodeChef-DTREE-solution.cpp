#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
const int maxn=1e5+10,maxm=500+10;

int t,n;
int depth[maxn];//子树中最大深度
int dis1[maxn];//与自己相连的最远距离
int dis2[maxn];//子树中的最远+次远：最大子树直径
int ans[maxn];
vector<int> e[maxn];

void dfs1(int u,int fa=-1)
{
    for(auto v: e[u])
    {
        if(v==fa) continue;
        dfs1(v,u);
        depth[u]=max(depth[u],depth[v]+1);
    }
}
void dfs2(int u,int fa=-1)
{
    int mx1=-1,mx2=-1;
    for(auto v: e[u])
    {
        if(v==fa) continue;
        dis1[v]=dis1[u]+1;
        if(mx1<=depth[v])
        {
            mx2=mx1;
            mx1=depth[v];
        }
        else mx2=max(mx2,depth[v]);
    }

    for(auto v: e[u])
    {
        if(v==fa) continue;
        if(mx1==depth[v]) dis1[v]=max(dis1[v],mx2+2);
        else dis1[v]=max(dis1[v],mx1+2);
        dfs2(v,u);
        dis2[u]=max(dis2[u],dis2[v]);
    }
    dis2[u]=max(dis2[u],mx1+mx2+2);
}
void dfs3(int u,int fa=-1,int p=0)
{
    int mx1=-1,mx2=-1,mx3=-1,mxd1=0,mxd2=0;
    for(auto v: e[u])
    {
        if(v==fa) continue;
        if(mx1<=depth[v])
        {
            mx3=mx2,mx2=mx1;
            mx1=depth[v];
        }
        else if(mx2<=depth[v])
        {
            mx3=mx2;
            mx2=depth[v];
        }
        else mx3=max(mx3,depth[v]);

        if(mxd1<=dis2[v])
        {
            mxd2=mxd1;
            mxd1=dis2[v];
        }
        else mxd2=max(mxd2,dis2[v]);
    }
    ans[u]=max(ans[u],mxd1);
    for(auto v: e[u])
    {
        if(v==fa) continue;
        int mx=p;
        if(mxd1==dis2[v]) mx=max(mx,mxd2);
        else mx=max(mx,mxd1);
        if(depth[v]==mx1)
        {
            mx=max(mx,mx2+mx3+2);
            mx=max(mx,mx2+1+dis1[u]);
        }
        else if(depth[v]==mx2)
        {
            mx=max(mx,mx1+mx3+2);
            mx=max(mx,mx1+1+dis1[u]);
        }
        else
        {
            mx=max(mx,mx1+mx2+2);
            mx=max(mx,mx1+1+dis1[u]);
        }
        ans[v]=max(ans[v],mx);
        dfs3(v,u,mx);
    }
}


int main()
{
#ifdef D
    freopen("CodeChef-DTREE.in", "r", stdin);
#endif
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            depth[i]=dis1[i]=dis2[i]=ans[i]=0;
            e[i].clear();
        }
        for(int i=1;i<=n-1;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs1(1);
        dfs2(1);
        dfs3(1);
        for(int i=1; i<=n; i++) {
            printf("depth[%d]=%d, dis1[%d]=%d, dis2[%d]=%d\n", i, depth[i], i, dis1[i], i, dis2[i]);
        }
        for(int i=1;i<=n;++i)
            printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}
