#include <iostream>
#include "Patterns.cpp"
#include <string>
#include <array>
using namespace std;
#include <chrono>;
int binary[8];
int counter = 7;
string ant = "∆";
string antcurr[1];
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
// sets the values of the pattern
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
//prints the array 
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
bool Patterncompare(pattern array[3],bool p)
{
pattern ob;
int turn =0;
ob.Assignarray();
 for ( int i = 0; i < 8; i++)
{
  int c;
  c = 0;
  int y=0;
for ( int j = 0; j < 3; j++)
{
p=NULL;
if(y>2)
{
  y =0;
}
if (array[y].patternval ==ob.patternArray[i][j])
   {
    //  cout<<"The binary value is"<< binary[i]<<endl;
     c++;
    
   }
   else
   {
    // cout<<"The binary value is"<< binary[i]<<endl;

   }
   

   if(c==3 && binary[i]==1)
   {
     p = true;
     return true;
   }
   if(c==3 && binary[i]==0)
   {
     p = false;
     return false;
   }
   y++;


}
cout<<endl;
}
turn++;
}



void arrayMover(int Y , int X , pattern**b)
{
pattern patternChecker[3];
bool turn = NULL;
pattern obj;
obj.Assignarray();
int count=0;
int timer=0;
// int cn=0;
for(int i = 0; i < Y-1; ++i)
   {
    for(int j = 0; j < X; j++)
    {
      if(j < X)
      {
        if (j-1 <0)
        {
          pattern stat;
          stat.patternval="_";
          patternChecker[0]=stat;
          patternChecker[1]= b[i][j];
        }
        else
        {
        patternChecker[0]= b[i][j-1];
        cout<<"j-1 is"<<j-1<<endl;
        patternChecker[1]= b[i][j];
        cout<<"j is"<<j<<endl;
        }
        if(j+1>X)
        {
          
          pattern stat;
          stat.patternval="_";
          patternChecker[2]=stat;
          
        }
        if(j+2>X)
        {
          
          pattern stat;
          stat.patternval="_";
          patternChecker[2]=stat;
          
        }
        else
        {
        cout<<"j+1 is"<<j+1<<endl;
        patternChecker[2]= b[i][j+1];
        
        count++;
        }

        // for(int k = 0; k < 3; ++k)
        // {
        // cout<<patternChecker[k].patternval;
        // }
        cout<<endl;
        turn = Patterncompare(patternChecker,turn);
        
        if (turn == true)
        {
          
          b[i+1][j].patternval="■";
        }
        else if (turn == false)
        {
          for (int i = 0; i < 3; i++)
          {
          
          }
          b[i+1][j].patternval="_";
        }
        
      }
      
    }
    
    
   }
   
for (int i = 0; i < 3; i++)
{
  // cout<<patternChecker[i].patternval;
}
// cout << endl;
for (int i = 0; i < 8; i++)
{
  for (int j = 0; j < 3; j++)
{
  // cout<<obj.patternArray[i][j];
}
// cout <<endl;
}
}
pattern** antinit(int Y , int X , pattern** a)
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
    }
  }
  return a;
}

void  antplacer(int Y , int X , pattern**b)
{
  for(int i = 0; i < Y; ++i)
  {
    for(int j = 0; j < X; ++j)
    {
      if (i == Y/2 && j == X/2 )
      {
        antcurr[0]=b[i][j].patternval;
        b[i][j].patternval = ant;
      }
      
    }
  }
}
void antmover(int Y , int X , pattern**b)
{
int n = 0;
int Direction=0;
Arrayprinter( Y,X,b);
while(n<2000)
{
// Direction of the ant 0 is north, 1 is east, 2 is south 3 is west

for(int i = 0; i < Y; ++i)
  {
    for(int j = 0; j < X; ++j)
    {
      if (b[i][j].patternval == ant)
      {
        
        if (Direction == 0)
        {
          if (antcurr[0]=="_")
          {
          if(j+1>X)
          {
           
            b[i][j].patternval = antcurr[i];
            b[i][0].patternval =ant;
          }
          else
          {
          
          antcurr[0]=b[i][j+1].patternval;
          b[i][j+1].patternval = ant;
          b[i][j].patternval="■";
          }
          }
          else if (antcurr[0]=="■")
          {
          if(j-1<0)
          {
            
            b[i][j].patternval = antcurr[i];
            ant = b[i][X].patternval;
          }
          else
          {
          
          antcurr[0]=b[i][j-1].patternval;
          b[i][j-1].patternval = ant;
          b[i][j].patternval="_";
          }
          }
        }
        else if (Direction == 1)
        {
          
          if (antcurr[0]=="_")
          {
          if(i+1>Y)
          {
            
            b[i][j].patternval = antcurr[i];
            ant = b[i][Y].patternval;
          }
          else
          {
          antcurr[0]=b[i+1][j].patternval;
          b[i+1][j].patternval = ant;
          b[i][j].patternval="■";
          }
          }
          else if (antcurr[0]=="■")
          {
          if(j-1>Y)
          {
            
            b[i][j].patternval = antcurr[i];
            ant = b[i][0].patternval;
          }
          else
          {
          
          antcurr[0]=b[i][j+1].patternval;
          b[i][j+1].patternval = ant;
          b[i][j].patternval="_";
          }
          }
        }
        else if (Direction == 2)
        {
          if (antcurr[0]=="_")
          {
          if(i+1>Y)
          {
            
            b[i][j].patternval = antcurr[i];
            ant = b[0][j].patternval;
          }
          else
          {
          
          antcurr[0]=b[i][j-1].patternval;
          b[i][j-1].patternval = ant;
          b[i][j].patternval="■";
          }
          }
          else if (antcurr[0]=="■")
          {
          if(j-1<X)
          {
            b[i][j].patternval = antcurr[i];
            ant = b[i][X].patternval;
          }
          else
          {
          
          antcurr[0]=b[i][j-1].patternval;
          b[i][j-1].patternval = ant;
          b[i][j].patternval="_";
          }
          }
        }
        else if (Direction == 3)
        {
          if (antcurr[0]=="_")
          {
          if(i-1<0)
          {
            
            b[i][j].patternval = antcurr[i];
            ant = b[Y][j].patternval;
          }
          else
          {
          cout<<"Reached";
          antcurr[0]=b[i-1][j].patternval;
          b[i-1][j].patternval = ant;
          b[i][j].patternval="■";
          }
          }
          else if (antcurr[0]=="■")
          {
          if(i-1<0)
          {
            b[i][j].patternval = antcurr[i];
            ant = b[Y][j].patternval;
          }
          else
          {
          
          antcurr[0]=b[i-1][j].patternval;
          b[i-1][j].patternval = ant;
          b[i][j].patternval="_";
          
          }
          }
        }
        Arrayprinter(Y,X,b);
      }

    } 
  }
n++;
}
}
int turnRight(int Direction)
{
if (Direction>3)
        {
          cout<<" The current is "<<antcurr[0]<<endl;
          cout<<" reset "<<Direction<<endl;
          Direction=0;
        }
        else
        {
          cout<<" The current is "<<antcurr[0]<<endl;
          cout<<" Direction is "<<Direction<<endl;
          Direction++;
        }
  return Direction;
}
int turnLeft(int Direction)
{
 if (Direction>3)
        {
          cout<<" The current is "<<antcurr[0]<<endl;
          cout<<" reset "<<Direction<<endl;
          Direction=0;
        }
        else
        {
          cout<<" The current is "<<antcurr[0]<<endl;
          cout<<" Direction is "<<Direction<<endl;
          Direction++;
        }
  return Direction; 
}
int main()
{
// dimensions
int y;
int f;
int x;
cout<<"Enter the amount of generations you want to view";
cin>>y;
cout<<"Enter the width of the table";
cin>>x;
// cout<<"Enter the binary value ";
// cin>>f;
// binaryCalc(f,NULL,NULL);
int Y = y;
// int X = (2*Y)-1;
int X = x;
//  pattern** a = new pattern*[Y];
// for(int i = 0; i < Y; ++i)
//     a[i] = new pattern[X];
pattern** a;
// a=ArrayAllocater(Y,X,a);
// Arrayprinter( Y,X,a);
// arrayMover(Y,X,a);
a = antinit(Y,X,a);
antplacer(Y,X,a);
antmover(Y,X,a);
// Arrayprinter( Y,X,a);
// cout<<antcurr[0];
// Arrayprinter( Y,X,a);


// for (int i = 0; i < 8; i++)
// {
//   cout<<binary[i];

// }
// cout << endl;

}
