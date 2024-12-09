#include<iostream>
using namespace std;
  
int board[9][9] = {9,3,0,1,0,0,0,0,0,  1,2,0,0,0,0,7,3,0,  0,6,0,0,0,5,0,0,2,
					  0,0,0,3,0,2,7,6,0,  8,0,0,0,0,0,0,0,9,  0,7,6,5,0,9,0,0,0,
					  6,0,0,2,0,0,0,9,0,  0,7,1,0,0,0,0,4,8,  0,0,0,0,0,4,0,2,1};
int *pnt_board[9][9] = {};
bool clearing{};

void Show_board();
bool If_legal(int n,int x,int y);
bool If_win();
void Filling_tabpnt();

int main()
{
	Filling_tabpnt();
	
	cout << "====================\n";
	cout << "       SUDOKU       \n";
	cout << "By:Papyrus219       \n";
	cout << "====================\n\n";
	cout<<"1.Play \n2.Info \n3.Exit\n";
	
	while(true)
	{
		int wybor{};
		cout <<"\nOption: ";
		cin >> wybor;
	
		switch(wybor)
		{	
			case 1:
				Show_board();
				
				while(!If_win())
				{
					cout << endl;

					int x{},y{};

					cout << "Enter field coordinates: ";
					
					if(clearing)
					{
						cout << "(clear) ";
						cin >> y >> x;
						
						if(y==0 && x==0)
						{
							clearing = false;
							continue;
						}
						
						if(x>9 || x<1 || y>9 || y<1)
							cout << "ILEGAL MOVE: UNCORECT COORDINATE!\n";
						else
						{
							board[y-1][x-1] = 0;
							Show_board();
						}
					}
					else
					{
						cin >> y >> x;
						if(x==0 && y==0)
						{
							clearing = true;
							continue;
						}
							
						if(x>9 || x<1 || y>9 || y<1)
						{
							cout << "ILEGAL MOVE: UNCORECT COORDINATE!\n";
							continue;
						}
							
						if(*pnt_board[y-1][x-1] == 0)
						{
							int n{};
							cout << "Enter the value to enter: ";
							cin >> n;
							if( If_legal(n,x-1,y-1 ) )
							{
								*pnt_board[y-1][x-1] = n;
								Show_board();
							}
						}
						else
							cout << "ILEGAL MOVE: FIELD IS TAKEN! \n";
					}
					cout << endl;				
				}
					
				cout << endl;
				cout << "==============================\n";
				cout << "	    CONGRATULATIONS!           \n";
				cout << "==============================";
				return 0;
			case 2:
				cout << "Hey! Welcome to my first application that is not just a competition task! \nIn general, the rules are simple: \n1.The program does not think for you, it only checks whether a given move is CURRENTLY legal. Don't enter anything if you are not sure. \n2.In the coordinates, enter the row first, then the column. \n3.By entering 0 0 in the coordinates, you will turn on the clearing mode. This is used to remove numbers from the table if you make a mistake. \n4.Have fun!\n";
				break;
			case 3:
				return 0;
		}
	}
}

/*-------------------------------------------------
  NORMAL FUNCTIONS
  -------------------------------------------------*/

void Show_board()
{
	cout << endl << "-------------------------" << endl;
	
	for(int meta=0;meta<9;meta+=3) //The first time we need values ??from 0-2, the second time from 3-5 and the third time from 6-8
	{
		cout << "| ";
		for(int i=meta;i<=meta+2;i++) //Using these intervals
		{
			for(int j=0;j<3;j++)
			{
				if(board[i][j] == 0)
					cout << "- ";
				else
					cout << board[i][j] << " ";
			}
			cout << "| ";
		}
		
		cout << endl << "| ";
		
		for(int i=meta;i<=meta+2;i++) //Using these intervals
		{
			for(int k=3;k<6;k++)
			{
				if(board[i][k] == 0)
					cout << "- ";
				else
					cout << board[i][k] << " ";
			}
			cout << "| ";
		}
		
		cout << endl << "| ";
		
		for(int i=meta;i<=meta+2;i++) //Using these intervals
		{
			for(int l=6;l<9;l++)
			{
				if(board[i][l] == 0)
					cout << "- ";
				else
					cout << board[i][l] << " ";
			}
			cout << "| ";
		}
		cout << endl << "-------------------------" << endl;
	}
}

bool If_legal(int n,int x,int y)
{
	if(n>9 || n<1)
	{
		cout << "ILEGAL MOVE: INVALID VALUE!\n";
		return false;
	}
	
	for(int i=0;i<9;i++)
	{
		if(*pnt_board[y][i] == n  ||  *pnt_board[i][x] == n) //Checking whether such a value already exists in the row or column
		{
			cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
			return false;	
		}
	}
	
	if(x<3)
	{
		if(y<3)
		{
			for(int i=0;i<9;i++)
				if(board[0][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}	
		else if(y<6)
		{
			for(int i=0;i<9;i++)
				if(board[1][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}
		else
		{
			for(int i=0;i<9;i++)
				if(board[2][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}
	}
	else if(x<6)
	{
		if(y<3)
		{
			for(int i=0;i<9;i++)
				if(board[3][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}	
		else if(y<6)
		{
			for(int i=0;i<9;i++)
				if(board[4][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}
		else
		{
			for(int i=0;i<9;i++)
				if(board[5][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}
	}
	else
	{
		if(y<3)
		{
			for(int i=0;i<9;i++)
				if(board[6][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}	
		else if(y<6)
		{
			for(int i=0;i<9;i++)
				if(board[7][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}
		else
		{
			for(int i=0;i<9;i++)
				if(board[8][i] == n)
				{
					cout << "ILEGAL MOVE: VALUE IS REPEATED!\n";
					return false;
				}
		}
	}
		
	return true;
}

bool If_win()
{
	for(int i=0;i<9;i++)
		for(int j=0;i<9;j++)
			if(*pnt_board[i][j]==0)
				return false;
				
	return true;
}

/*-------------------------------------------------
  POINTERS FUNCTIONS
  -------------------------------------------------*/
  
void Filling_tabpnt() //This is needed so that, despite writing in a different order, the user can enter the coordinates as he sees them
{
	int I{},J{}; //Variables for iterating through an array of pointers
	for(int meta=0;meta<9;meta+=3)
	{
		for(int i=meta;i<meta+3;i++)
		{
			for(int j=0;j<3;j++)
			{
				pnt_board[I][J] = &board[i][j]; //Inserting game array addresses into the pointer array in the order in which they are printed on the screen
				
				J++; //We jump to the next column of the array
				if(J>=9) //Jumps to the next row of the array
				{J=0; I++;}
			}
		}
		
		for(int i=meta;i<meta+3;i++)
		{
			for(int k=3;k<6;k++)
			{
				pnt_board[I][J] = &board[i][k]; //Inserting game array addresses into the pointer array in the order in which they are printed on the screen
				
				J++; //We jump to the next column of the array
				if(J>=9) //Jumps to the next row of the array
				{J=0; I++;}
			}
		}
		
		for(int i=meta;i<meta+3;i++)
		{
			for(int l=6;l<9;l++)
			{
				pnt_board[I][J] = &board[i][l]; //Inserting game array addresses into the pointer array in the order in which they are printed on the screen
				
				J++; //We jump to the next column of the array
				if(J>=9) //Jumps to the next row of the array
				{J=0; I++;}
			}
		}
	}
}
