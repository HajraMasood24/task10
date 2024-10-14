#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y);
void printMaze();
void printEnemy1();
void eraseEnemy1();
void moveEnemy1();
void printEnemy();
void eraseEnemy();
void moveEnemy();
void printEnemy2();
void eraseEnemy2();
void moveEnemy2();
void printplayer();
void eraseplayer();
void moveplayerLeft();
void moveplayerRight();
void moveplayerUp();
void moveplayerDown();
void printCoin();
void eraseCoin();
void pickcoins();


int ex2=45, ey2=2;//enemy 3
int ex1=6, ey1=2;
int ex=20, ey=2;//enemy2
int px=16, py=16;
int cx=30,cy=10; // Coin position
int score = 0;  
int d1=1;
int d2=1;
int d3=1;

main()
{


	system("cls");
	printMaze();
	printEnemy1();
	printEnemy();
	printEnemy2();
	printplayer();
	printCoin();

	
	while(true)
	{	
		if (GetAsyncKeyState(VK_LEFT))
		{
			moveplayerLeft();
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			moveplayerRight();
		}
		if (GetAsyncKeyState(VK_UP))
		{
			moveplayerUp();
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			moveplayerDown();
		}
		moveEnemy1();
		moveEnemy();
		moveEnemy2();
		pickcoins();//player picks the coin

		Sleep(300);
	}

}

void eraseplayer()
{
  	gotoxy(px,py);
	cout<<"        "<<endl;
	gotoxy(px,py+1);
        cout<<"        "<<endl;
	gotoxy(px,py+2);
	cout<<"        "<<endl;
	gotoxy(px,py+3);
	cout<<"        "<<endl;



}

void printplayer()
{	
 	gotoxy(px,py);
	cout<<"_::_::_"<<endl;
	gotoxy(px,py+1);
        cout<<"|,   ,|"<<endl;
	gotoxy(px,py+2);
	cout<<"|=| |=|"<<endl;
	gotoxy(px,py+3);
	cout<<"( ) ( )"<<endl;
}

void moveplayerLeft()
{
   if(px>1)
   {
	eraseplayer();
	px=px-1;
	printplayer();
   }
}

void moveplayerRight()
{
   if (px<70)
   {
	eraseplayer();
	px=px+1;
	printplayer();
   }

}

void moveplayerUp()
{
    if (py > 1)
    {
	eraseplayer();
	py=py-1;
	printplayer();
    }
}

void moveplayerDown()
{
    if (py < 20)
    {
	eraseplayer();
	py=py+1;
	printplayer();
    }

}

void printEnemy1()
{
	
	gotoxy(ex,ey);
         cout<<"  ____  "<<endl;
	gotoxy(ex,ey+1);
	 cout<<" : -- : "<<endl;
	gotoxy(ex,ey+2);
	 cout<<"  ....   "<<endl;
	gotoxy(ex,ey+3);
	 cout<<"  ^  ^   "<<endl;
}


void eraseEnemy1()
{
	
	gotoxy(ex,ey);
         cout<<"        "<<endl;
	gotoxy(ex,ey+1);
	 cout<<"         "<<endl;
	gotoxy(ex,ey+2);
	 cout<<"        "<<endl;
	gotoxy(ex,ey+3);
	 cout<<"         "<<endl;
}

void moveEnemy1()
{
	
	eraseEnemy1();
	ex += d1;
		
	if(ex >= 35 || ex <=20)
	{
		d1=-d1;
		ex += d1;
	}
	
	printEnemy1();


}

void eraseEnemy()
{
	gotoxy(ex1,ey1);
	cout<<"      "<<endl;
	gotoxy(ex1,ey1+1);
        cout<<"      "<<endl;
	gotoxy(ex1,ey1+2);
        cout<<"      "<<endl;

}

void printEnemy()
{
	gotoxy(ex1,ey1);
	cout<<" ___  "<<endl;
	gotoxy(ex1,ey1+1);
        cout<<"('_') "<<endl;
	gotoxy(ex1,ey1+2);
        cout<<" ^ ^  "<<endl;

}

void moveEnemy()
{
	eraseEnemy();
	ey1 += d2;
		
	if(ey1 >=13 || ey1 <=2)
	{
		d2=-d2;
		ey1 += d2;
	}
	
	printEnemy();


}

void eraseEnemy2()
{
	gotoxy(ex2,ey2);
	cout<<"         "<<endl;
	gotoxy(ex2,ey2+1);
        cout<<"         "<<endl;
	gotoxy(ex2,ey2+2);
        cout<<"         "<<endl;
	gotoxy(ex2,ey2+3);
	cout<<"         "<<endl;


}

void printEnemy2()
{
	gotoxy(ex2,ey2);
	cout<<"  ====   "<<endl;
	gotoxy(ex2,ey2+1);
        cout<<"== >< == "<<endl;
	gotoxy(ex2,ey2+2);
        cout<<"======== "<<endl;
	gotoxy(ex2,ey2+3);
	cout<<"  =  =   "<<endl;
}

void moveEnemy2()
{
	eraseEnemy2();
	ey2 += d3;
	ex2 += d3;
	
	if(ex2 >=50 || ex2<=5 ) 
	{
		d3=-d3;
	}
	 if(ey2 >= 17 || ey2 <= 2)
   	 {
       		 d3 = -d3; 
   	 }

	
	printEnemy2();


}
void printCoin()
{
    gotoxy(cx, cy);
    cout<<"o";
}


void eraseCoin()
{
    gotoxy(cx, cy);
    cout<<" ";
}

void pickcoins()
{
    if (cx >=px && cx <= px+6 && cy >= py && cy <= py+3)
    	{
         eraseCoin();
	 score += 10; 
	 cx += 10;
	 cy += 5;
	 if (cx > 70) cx=10;
	 if (cy > 20) cy=5;
	 printCoin();
       	 
        }
	 gotoxy(4,25);
    	 cout << "Score: " << score << endl; 
}


void printMaze()
{
	cout<<"######################################################################"<<endl;
	cout<<"##                                             	                    ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"##                                                                  ##"<<endl;
	cout<<"######################################################################"<<endl;
}


void gotoxy(int x,int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}