#include<iostream>
using namespace std;

void wavePrint(int arr[][3], int row, int col)
{
    for(int j = 0; j<col; j++)
    {
        if(col&1)
        {
            //odd index
            for(int i = row-1; i >= 0; i--)
            {
                cout<<arr[i][j]<<" ";
            }

        }
        else{
            //even index
            for(int i = 0; i< row; i++)
            {
                cout<<arr[i][j]<<" ";
            }
        }

    cout<<" - ";

    }
}

int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    wavePrint(arr,3,3);
}

/*

    wave print


                                  |         
      ↑   ↓   ↑   ↓   ↑   ↓   ↑   | ←- R0   
                                  |         
      ↑   ↓   ↑   ↓   ↑   ↓   ↑   | ←- R1   
                                  |         
      ↑   ↓   ↑   ↓   ↑   ↓   ↑   | ←- R2   
     -----------------------------+         
      ↑   ↑   ↑   ↑   ↑   ↑   ↑             
      C0  C1  C2  C3  C4  C5  C6            




*/
