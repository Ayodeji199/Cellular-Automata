#include <iostream>
#include "Patterns.cpp"
#include <string>
#include <array>
#include<vector>
#include <unistd.h>
// #include "main.cpp"
using namespace std;
int binary[8];
int counter = 7;

void Arrayprinter(int Y , int X , pattern**b )
{
for(int i = 0; i < Y; ++i)
  {
     for(int j = 0; j < X; ++j)
    {
      cout <<b[i][j].patternval << " ";
    }
        cout << endl;
  }
}

void binaryCalc(int tester,int n,int tt)
{
tt = tester;
if(tester>1)
{
if((tt %=2) !=0 )
{
n=(tt%2);
tester = tester/2;
binary[counter] = n;
counter--;
binaryCalc(tester,n,tt);
}
else 
{
n=(tt%2);
tester = tester/2;
binary[counter] = n;
counter--;
binaryCalc(tester,n,tt);
}
}
else
{
    binary[counter] = 1;
}

}

pattern** ArrayAllocater(int Y , int X , pattern** a )
{
  a = new pattern*[Y];
for(int i = 0; i < Y; ++i)
    a[i] = new pattern[X];
 
  // fill
  for(int i = 0; i < Y; ++i)
  {
    for(int j = 0; j < X; ++j)
    {
      a[i][j].patternval = "_";
      a[i][j].binValue = 0;
      if (j ==X/2 && i ==0 )
         {
             a[i][j].patternval = "■";
             a[i][j].binValue = 1;
         }
    }
  }
return a;
}

void converter(int Y, int X, pattern** a) 
{ 
    Arrayprinter(Y, X, a);
    //int* neighbour = NULL;
    //neighbour= new int[X][Y];
    
    vector <vector<int>> neighbour(Y, vector<int> (X));
    
    //for(int i = 0; i < Y; ++i) 


    //check the surroundings

    //for every cell
    for(int i = 0; i < Y-1; ++i)
    {
        for(int j = 0; j < X; j++)
        {
            // cout << j << " j value" << endl;
            // cout << i << " i value" << endl;
            usleep(1000);
            //for the top left corner
            if(i==0&&j==0)
            {
                //neighbour isnt changing is the problem
                //left
                if(a[i][X-1].binValue==1) neighbour.assign(i).assign(j)(1, neighbour[i][j]++);
                cout << neighbour[i][j]<< " ";

                //right
                if(a[i][j+1].binValue==1) (neighbour.at(i).at(j))++;
                cout << neighbour[i][j]<< " ";

                //up left
                if(a[Y-2][X-1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[Y-2][j].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[Y-2][j+1].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[i+1][X-1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //down right
                if(a[i+1][j+1].binValue==1) neighbour.at(i).at(j)++;        
            }
            
            //for the top right corner
            if(i==0&&j==X-1)
            {
                //left
                if(a[i][j-1].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][0].binValue==1) neighbour.at(i).at(j)++;
                
                //up left
                if(a[Y-2][j-1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[Y-2][j].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[Y-2][0].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[i+1][X-1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //down right
                if(a[i+1][0].binValue==1) neighbour.at(i).at(j)++;        
            }
            
            //for the bottom left corner
            if(i==Y-2&&j==0)
            {
                //left
                if(a[Y-2][j].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][j+1].binValue==1) neighbour.at(i).at(j)++;
                
                //up left
                if(a[i+1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[i+1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[0][X-1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[0][j].binValue==1) neighbour.at(i).at(j)++;

                //down right
                if(a[0][j+1].binValue==1) neighbour.at(i).at(j)++;        
            }
            
            //for the bottom right
            if(i==Y-2&&j==X-1)
            {
                //up left
                if(a[i+1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[i+1][0].binValue==1) neighbour.at(i).at(j)++;

                //left
                if(a[i][j+1].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][0].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[0][j+1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[0][j].binValue==1) neighbour.at(i).at(j)++;

                //down right
                if(a[0][0].binValue==1) neighbour.at(i).at(j)++;
            }
            
            //when i is 0 but j isn't 0 (i.e the top row but not a corner)
            if(i==0&&j!=0&&j!=X-1)
            {
                //left
                if(a[i][j-1].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][j+1].binValue==1) neighbour.at(i).at(j)++;
                
                //up left
                if(a[Y-2][j-1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[Y-1][j].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[Y-1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[i+1][j-1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //down right
                if(a[i+1][j+1].binValue==1) neighbour.at(i).at(j)++;       
            }
            
            //when j is 0 but i isnt 0 (i.e the left but not a corner)
            if(j==0&&i!=0&&i!=Y-2)
            {
                //down right
                if(a[i+1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[i+1][X-1].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][j+1].binValue==1) neighbour.at(i).at(j)++;

                //left
                if(a[i][X-1].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[i-1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[i-1][j].binValue==1) neighbour.at(i).at(j)++;

                //up left
                if(a[i-1][X-1].binValue==1) neighbour.at(i).at(j)++;       
            }
            
            //when j is X-1 (the last row) but (i.e the right but not a corner)
            if(j==X-1&&i!=0&&i!=Y-2)
            {
                //down right
                if(a[i+1][0].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[i+1][j-1].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][0].binValue==1) neighbour.at(i).at(j)++;

                //left
                if(a[i][j-1].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[i-1][0].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[i-1][j].binValue==1) neighbour.at(i).at(j)++;

                //up left
                if(a[i-1][j-1].binValue==1) neighbour.at(i).at(j)++;
            }

            //when i is Y-2 but j isnt 0 or X-1 (i.e the bottom row)
            if(i==Y-2&&j!=0&&j!=X-1)
            {
                //down right
                if(a[0][j+1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[0][j].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[0][j-1].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][j+1].binValue==1) neighbour.at(i).at(j)++;

                //left
                if(a[i][j-1].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[i-1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[i-1][j].binValue==1) neighbour.at(i).at(j)++;

                //up left
                if(a[i-1][j-1].binValue==1) neighbour.at(i).at(j)++;
            }
            
            //everything thats not an edge or a corner
            if(i!=0&&j!=0&&i!=Y-2&&j!=X-1)
            {

                //down right
                if(a[i+1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //down
                if(a[i+1][j].binValue==1) neighbour.at(i).at(j)++;

                //down left
                if(a[i+1][j-1].binValue==1) neighbour.at(i).at(j)++;

                //right
                if(a[i][j+1].binValue==1) neighbour.at(i).at(j)++;

                //left
                if(a[i][j-1].binValue==1) neighbour.at(i).at(j)++;

                //up right
                if(a[i-1][j+1].binValue==1) neighbour.at(i).at(j)++;

                //up
                if(a[i-1][j].binValue==1) neighbour.at(i).at(j)++;

                //up left
                if(a[i-1][j-1].binValue==1) neighbour.at(i).at(j)++;
            }

            
            //check if there are any live neighbours up, down, left, right, diagonals too
            //if(x=0) then check the end of the array 
            //if(x= the width X) then check the beginning of the array
            //if there is then add one to the array neightbours ? 
        }
    }

    //for every cell
    for(int i = 0; i < Y-1; i++)
    {
        for(int j = 0; j < X; j++)
        {
            //death by underpopulation (< 2) or overpopulation (> 3)
            if(neighbour[i][j] < 2 || neighbour[i][j] > 3)
            {
                 a[i][j].binValue=0;
            }

            //life by reproduction
            if(neighbour[i][j] == 3)
            {   
                if(a[i][j].binValue==0)
                {
                    a[i][j].binValue = 1;
                }
            }

            //any LIVE cell with two or three live neighbours lives
            if(neighbour[i][j] > 1 && neighbour[i][j] < 4)
            {
                if(a[i][j].binValue==1)
                {
                    a[i][j].binValue = 1;
                }     
            }
        }
    } 

    for(int i = 0; i < Y-1; ++i)
    {
        for(int j = 0; j < X; j++)
        {
            a[i][j].patternop(a[i][j].binValue);
        }
    }

    //system("CLS");
    Arrayprinter(Y, X, a);
    converter(Y,X,a);
}

void setupGameOfLife()
{

    //create an array for the thing
    //Y=generations
    //X=width of the grid

    int y;
    int f;
    int x;
    cout << "KKWKEKWKEKWKW" << endl;
    cout << "%55";
    cout<<"Enter the amount of generations you want to view";
    cin>>y;
    cout<<"Enter the width of the table";
    cin>>x;
    cout<<"Enter the rule you want to run from";
    cin>>f;

    binaryCalc(f,NULL,NULL);
    int Y = y;
    // int X = (2*Y)-1;
    int X = x;
    pattern** a = ArrayAllocater(Y,X,a);

    for(int i = 0; i < Y; ++i)
    {    
        for(int j = 0; j < X; ++j)
        {
            a[i][j].patternval = "_";
            a[i][j].binValue = 0;
            if (j ==X/2 && i ==0 )
            {
                a[i][j].patternval = "■";
                a[i][j].binValue = 1;
            }
        }
    }
    
    converter(Y,X,a);
//make it choose a (random or user chosen ?) rule and make the first (parent) generation from the rule ?
//run game of life for that continuously
}


int main(){
    setupGameOfLife();
}