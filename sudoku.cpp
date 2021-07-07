#include<bits/stdc++.h>
using namespace std;
#define N 9
#define m 3

//function to display the sudoku matrix
void display(vector<vector<int>> v){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

//check if its valid to assign number to the given position

bool isValid(int i,int j,int x,vector<vector<int>> v){
    for(int k=0;k<N;k++){
        if((v[i][k]==x) || (v[k][j]==x) ){
            return false;
        }
    }

    int startRow = i - i % m,
            startCol = j - j % m;
   
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (v[i + startRow][j +
                            startCol] == x)
                return false;
 
    return true;
}

bool solve(vector<vector<int>> &v){
    int i,j,flag=0;
    for( i=0;i<N;i++){
        flag=0;
        for(j=0;j<N;j++){
            if(v[i][j]==0){
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
    }
    
    

    if(i==N && j==N){
        return true;
    }

    


    for(int x=1;x<=N;x++){
        if(isValid(i,j,x,v)){
            
            v[i][j]=x;
            
            if(solve(v)==true){
                return true;
            };
            v[i][j]=0;

        }
    }
    return false;

}

int main(){

    vector <vector<int>> grid={{8,3,0,1,0,0,6,0,5},{0,0,0,0,0,0,0,8,0},{0,0,0,7,0,0,9,0,0},{0,5,0,0,1,7,0,0,0},{0,0,3,0,0,0,2,0,0},{0,0,0,3,4,0,0,1,0},{0,0,4,0,0,8,0,0,0},{0,9,0,0,0,0,0,0,0},{3,0,2,0,0,6,0,4,7}};

    cout<<"Unsolved puzzle"<<endl;
    display(grid);
    cout<<endl;
    cout<<"Solved puzzle"<<endl;
    solve(grid);
    display(grid);
    
    return 0;
}
