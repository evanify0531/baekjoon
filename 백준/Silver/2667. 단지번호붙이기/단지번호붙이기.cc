#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int y, x, ny, nx, t, num=1;
int a[51][51];
int visited[51][51];
std::vector<int> v;

void dfs(int y, int x, int * c)
{
    visited[y][x] = num;
    (*c)++;
    for(int i=0; i<4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= t || nx >= t) continue;
        if(a[ny][nx] == 1 && visited[ny][nx] == 0)
        {
            dfs(ny, nx, c);
        }
    }
}

int main(void)
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> t;

    std::fill(&a[0][0], &a[0][0] + 51 * 51, 0);
    std::fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

    for(int i=0; i<t; i++)
    {
        char str[25];
        std::scanf("%s", str);
        getchar();
        for(int j=0; j<t; j++)
        {
            a[i][j] = str[j] - '0';
        }
    }
    
    for(int i=0; i<t; i++)
    {
        for(int j=0; j<t; j++)
        {
            if(a[i][j] == 1 && visited[i][j] == 0)
            {
                int cnt = 0;
                dfs(i, j, &cnt);
                num++;
                v.push_back(cnt);
            }
        }
    }
    //std::cout << std::endl << std::endl;

    /*for(int i=0; i<t; i++)
    {
        for(int j=0; j<t; j++)
        {
            std::cout << visited[i][j];
        }
        std::cout << std::endl;
    }*/
    sort(v.begin(), v.end());

    std::cout << num-1 << '\n';
    for(int i=0; i<v.size(); i++)
    {
        std::cout << v[i] << '\n';
    }
    
    return 0;
}