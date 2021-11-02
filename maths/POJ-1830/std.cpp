#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)

typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-6;
const int MAX_M=35;
const int MAX_N=35;
int aug[MAX_M][MAX_N];//增广矩阵
int m,n;//m个方程,n个未知数
void output() {
    cout << "---\n";
    rep(i,0,m-1){
        rep(j,0,n){
            cout << aug[i][j] << ' ';
        }
        cout << endl;
    }
}
int Gauss()
{
    int i,j;
    int max_r,row,col;
    for(col=0,row=0;row<m&&col<n;row++,col++){
        printf("col=%d, row=%d\n", col, row);
        max_r=row;//当前这列绝对值最大的行
        for(i=row+1;i<m;i++){//找到当前列所有行中的最大值(做除法时减小误差)
            if(aug[i][col]>aug[max_r][col])
                max_r=i;
        }
        if(max_r!=row){//将该行与当前行交换 
            for(j=row;j<n+1;j++)
                swap(aug[max_r][j],aug[row][j]);
        }
        if(aug[row][col]==0){//当前列row行以下全为0(包括row行) 
            row--;
            output();

            continue;
        }
        for(i=row+1;i<m;i++){// 枚举要删去的行，即//用当前的行当前列的值对下面所有行当前列的值进行消除，使其为0，以满足行阶梯型  
            if(aug[i][col]==0)//如果是0，则跳过
                continue;
            for(j=col;j<n+1;j++)//如果不是，则消除
                aug[i][j]^=aug[row][j];
        }
        output();
    }
    cout << row << endl;
    for(i=row;i<m;i++){
        if(aug[i][col]!=0)
            return -1;
    }
    return 1<<(n-row);//n-row个变元,只有0/1两种取值
}
int main()
{
#ifdef D
    freopen("POJ-1830.in", "r", stdin);
#endif
    int T,N,i,j;
    int Start[30],End[30];
    scanf("%d",&T);
    while(T--){
        m=n=0;
        memset(aug,0,sizeof(aug));
        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%d",&Start[i]);
        for(i=0;i<N;i++)
            scanf("%d",&End[i]);
        while(1){
            scanf("%d %d",&i,&j);
            if(i==0&&j==0) break;
            aug[j-1][i-1]=1;//每行两个数i j，表示如果操作第i个开关，第j个开关的状态也会变化”，说明j受到i的影响,a[j-1][i-1]=1  
        }
        m=n=N;
        for(i=0;i<n;i++){
            aug[i][i]=1;//自己可以改变自己 
            aug[i][n]=Start[i]^End[i];
        }
        int ans=Gauss();
        if(ans==-1)
            puts("Oh,it's impossible~!!");
        else
            printf("%d\n",ans);
    }
    return 0;
}
