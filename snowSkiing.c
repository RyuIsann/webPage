#include<stdio.h>

int n, m;
int a[100][100], memo[100][100];
int max(int a, int b, int c, int d){
    int tmp;
    if( a > b)tmp = a;
    else tmp = b;
    if(c > tmp) tmp = c;
    if(d > tmp) tmp = d;
    return tmp;
}
void skiting(int a[][100], int memo[][100], int x, int y){
    if(memo[x][y] != 0 || x == 0|| x > n || y == 0 || y > m)return;
    
    if(a[x][y] <= a[x+1][y] && a[x][y] <= a[x-1][y] && a[x][y] <= a[x][y+1] && a[x][y] <= a[x][y-1]){
        memo[x][y] = 1;
        return ;
    }
    if(a[x][y] > a[x+1][y]) skiting(a, memo, x+1, y);
    if(a[x][y] > a[x-1][y]) skiting(a, memo, x-1, y);
    if(a[x][y] > a[x][y+1]) skiting(a, memo, x, y+1);
    if(a[x][y] > a[x][y-1]) skiting(a, memo, x, y-1);
    memo[x][y] = max(memo[x+1][y]+1, memo[x-1][y]+1 , memo[x][y-1] +1,memo[x][y+1]+1 );
    return ;
}

int main(){
    for(int i = 0; i < 100; i ++){
        for(int j = 0; j < 100; j ++){
            memo[i][j] = 0;
            a[i][j] = 0;
        }
    }
    scanf("%d %d ", &n, &m);
    int min = 1000000;
    int max = -1;
    for( int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%d", &a[i][j]);
            if(a[i][j] < min)min = a[i][j];
            if(a[i][j] > max)max = a[i][j];
        }
    }
    int x, y;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(a[i][j] == min){
                x = i;
                y = j;
            }
        }
    }
    memo[x][y] = 1;
    for( int i = 1; i < n+1; i ++){
        for(int j = 1; j < m+1; j++){
            if(a[i][j] == max){
                x = i;
                y = j;
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for( int j = 1; j <= m; j ++){
            skiting(a, memo, i, j);
        }
    }
    max = -1;
    for( int i = 1; i < n+1; i ++){
        for(int j = 1; j < m +1; j ++){
            if(max < memo[i][j]) max = memo[i][j];
        }
    }
    printf("%d",max);
    return 0;
}
