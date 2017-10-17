//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int mat[10][10], total=0;

void DFS(int brow, int bcol, int mrow, int mcol)
{
    //base case
    if(mat[brow][bcol]==0 || mat[mrow][mcol]==0)
        return;
    if(brow==mrow && bcol==mcol){
        int eat=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(mat[i][j]==1)
                    eat++;
            }
        }
        if(eat<=1)
            total++;
        return;
    }
    //ini
    mat[brow][bcol]=0, mat[mrow][mcol]=0;
    
    DFS(brow+1, bcol, mrow+1, mcol);
    DFS(brow-1, bcol, mrow+1, mcol);
    DFS(brow, bcol+1, mrow+1, mcol);
    DFS(brow, bcol-1, mrow+1, mcol);
    DFS(brow+1, bcol, mrow-1, mcol);
    DFS(brow-1, bcol, mrow-1, mcol);
    DFS(brow, bcol+1, mrow-1, mcol);
    DFS(brow, bcol-1, mrow-1, mcol);
    DFS(brow+1, bcol, mrow, mcol+1);
    DFS(brow-1, bcol, mrow, mcol+1);
    DFS(brow, bcol+1, mrow, mcol+1);
    DFS(brow, bcol-1, mrow, mcol+1);
    DFS(brow+1, bcol, mrow, mcol-1);
    DFS(brow-1, bcol, mrow, mcol-1);
    DFS(brow, bcol+1, mrow, mcol-1);
    DFS(brow, bcol-1, mrow, mcol-1);
    
    mat[brow][bcol]=1, mat[mrow][mcol]=1;
}

int main()
{
    int k, lox, loy;
    int i, j;
    
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            mat[i][j]=1;
    cin >> k;
    for(i=0;i<k;i++){
        cin >> lox >> loy;
        mat[lox][loy]=0;
    }
    DFS(1, 1, 5, 5);
    
    cout << total << endl;
    
    return 0;
}
