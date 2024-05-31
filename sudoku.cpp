#include<iostream>
using namespace std;
void print_sudoku_box(int box[9][9])
{
    int r,c;
    cout<<"-------------------------------------"<<endl;
    for(r=0;r<9;r++)
    {
        for(c=0;c<9;c++)
        {
        
            cout<<box[r][c]<<" | ";
        }
        cout<<endl;
        cout<<"------------------------------------"<<endl;
    }
   
}
bool check(int box[9][9],int r,int c,int n)
{
    int row=(r/3)*3;
    int col=(c/3)*3;
    for(int i=0;i<9;i++)
    {
        if(box[r][i]==n || box[i][c]==n || box[row+i/3][col+i%3]==n)
        {
            return false;
        }
    }
    return true;
}
bool solve(int box[9][9])
{
    for(int r=0;r<9;r++)
    {
        for(int c=0;c<9;c++)
        {
            if(box[r][c]==0)
            {
                for(int i=1;i<=9;i++)
                {
                    if(check(box,r,c,i))
                    {
                        box[r][c]=i;
                        if(solve(box))
                        {
                            return true;
                        }
                        box[r][c]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int box[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
        
        
        print_sudoku_box(box); 

        if(solve(box))
        {
            cout<<"\t\t ******* solved sudoku puzzle ******"<<endl;
            print_sudoku_box(box);
           
        }
       else{
            cout<<"sorry!! can't solve.."<<endl;
        }

        return 0;
}