#pragma once
// this class composit with the menue class
#include "util.h"
#include "Vehicle.h"
#include "Menue.h"
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
string name;
class Map
{
	//My private Variable
private:
	static string a ;
	static string b ;
	static string c ;
	static string d ;
	static string e ;
	static string f ;
	static string g;
	static string h ;	
	static int timechekker;
	static string i ;
	static int help1;
	static int help2;
	static string j ;
	static int firecheck1;
	static int firecheck2;
	static string k ;
	static string l ;
	static int bouncecount;
	static string m ;
	static int score1;
	static int large1;
	static int medium1;
	static bool large1opener;
	static bool medium1opener;
	static bool large2opener;
	static bool medium2opener;
	static int small1;
	static int large2;
	static int medium2;
	static int small2;
	static int score2;
	static string n ;
	static bool screen;
	static Vehicle* v1;
	static Vehicle* v2;
	static Vehicle* v3;
	static Vehicle* v4;
	static int type;
	static bool change;
	static int ii;
	static int mode1;
	static int jj;
	static bool player1;
	static int kk;
	static int random;
	static int ll;
	static int aa;
	static int random1;
	static int random2;
	static int change1;
	static int change2;
	static int bb;
	static int cc;
	static int dd;
public:
	//Costractors 
	Map()
	{

	}
	Map(string aa,string bb,string cc,string dd,string ee,string ff,string gg ,string hh,string ii ,string jj,string kk,string ll,string mm,string nn,int mode,int t)
	{

		a=aa;
		b=bb;
		c=cc;
		d=dd;
		e=ee;
		f=ff;
		g=gg;
		h=hh;
		i=ii;
		j=jj;
		k=kk;
		l=ll;
		m=mm;
		n=nn;
		type = t;
		mode1 = mode;
		if (mode == 2)
		{
			 v1 = new Tank;
			 v2 = new Tank;
			 if (type == 1)
			 {
				 v3 = new Tank;
				 v4 = new Tank;
			 }
		}
		else if (mode == 0)
		{
		       v1 = new FigtherPlan;
		       v2 = new FigtherPlan;
			   if (type == 1)
			   {
				   v3 = new FigtherPlan;
				   v4 = new FigtherPlan;
			   }
		}
		else
		{
			 v1 = new Helicopter;
			 v2= new Helicopter;
			 if (type == 1)
			 {
				 v3 = new Helicopter;
				 v4 = new Helicopter;
			 }
		}
		PlaySound(TEXT("5.wav"), NULL, SND_FILENAME | SND_ASYNC);
		if (type == 1)
		{
			screen = true;
			glutTimerFunc(3000, time, 0);
			int level32 = -1;
			fstream myfile;
			myfile.open("../" + name + ".txt", ios::in);
			myfile >> level32;
			myfile >> score1;
			myfile >> score2;
			myfile >> medium1;
			myfile >> large1;
			myfile.close();
			cout << level32 << endl;
			if (level32 == 1)
			{
				screen1 =true;
				glutDisplayFunc(mapno2);
			}
			else if (level32 == 2)
			{
				screen1 = true;
				screen2 = true;
				glutDisplayFunc(mapno1);
			}
			else if (level32 == 3)
			{
				screen1 = true;
				screen2 = true;
				screen3 = true;
				glutDisplayFunc(mapno3);
			}
			else
			{
				level32 = -1;
			}
			if (type == 1  && level32==-1)
			{
				screen = false;
				glutTimerFunc(3000.0, time, 0);
				glutDisplayFunc(leveloneScreen);
			}

		}
		if (type==2)
		{
			screen1 = true;
			glutTimerFunc(3000.0, time, 0);
			glutDisplayFunc(mapno2);
		}
	
	}
	//Timer funtion
	static void time(int h) {
		change = true;
		screen = true;
		change1 = true;
		change2= true;
		timechekker--;
		firecheck1++;
		firecheck2++;
		if (boost1control == true)
		{
			if (boost1 == 4)
			{
				boost1control=false;
			}
			boost1++;
		}
		if (boost2control == true)
		{
			if (boost2 == 4)
			{
				boost2control = false;
			}
			boost2++;
		}
		if (firecheck1 == 2)
		{
			fire = false;
		}
		if (firecheck2 == 2)
		{
			fire1 = false;
		}
		if (timechekker == 0)
		{
			medium1 = 4;
			medium2 = 4;
			large1 = 2;
			large2 = 2;
			timechekker =5;
		}
		random=GetRandInRange(0, 4);
		random1 = GetRandInRange(0, 4);
		random2 = GetRandInRange(0, 4);
		glutTimerFunc(5000, time, 0);
	}
	//rematch screen
	static void rematch()
	{
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		large1opener = false;
		medium1opener = false;
		large2opener = false;
		medium2opener = false;
		large1 = 2;
		medium1 = 4;
		small1 = 0;
		large2 = 2;
		medium2 = 4;
		small2 = 0;
		mode1 = 0;
		boost1 = 1;
		boost2 = 1;
		boost1control = false;
		boost2control = false;
		glutPassiveMotionFunc(mousemove);
		glutMouseFunc(mousecontrol);
		if (player1 == true)
		{
			string print = name + " Win";
			DrawString(420, 600, print, colors[BLUE]);
		}
		else
		{
			DrawString(420, 600, "Player 2 Win", colors[BLUE]);
		}
		DrawString(400, 450, "Exit Game", colors[WHITE]);
		DrawString(400, 500, "Rematch", colors[WHITE]);
		if (help1 == 1)
		{
			DrawString(400, 450, "Exit Game", colors[RED]);
		}
		else if (help1 == 0)
		{
			DrawString(400, 500, "Rematch", colors[RED]);
		}
		if (help1 == 0)
		{

			glutPostRedisplay();
			DrawTriangle(350, 525, 350, 495, 380, 510, colors[WHITE]);


		}
		if (help1 == 1)
		{
			DrawTriangle(350, 475, 350, 445, 380, 460, colors[WHITE]);
			glutPostRedisplay();
		}
		if (help2 == 0)
		{
			score1 = 0;
			score2 = 0;
			help2 = -1;
			help1 = 0;
			if (type == 2)
			{
				glutDisplayFunc(mapno2);
			}
			
		     glutPostRedisplay();
		}
		if (help2 == 1)
		{
			exit(1);
		}
		glutSwapBuffers();
	}
	//botwin screen
	static void botwin()
	{
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		DrawString(500, 500, "Bot win the Match", colors[WHITE]);
		DrawString(500, 450, "You Lose ", colors[WHITE]);
		glutSwapBuffers();

	}
	//Player win screen
	static void youwin()
	{
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		DrawString(510, 500, "Congratulation", colors[WHITE]);
		DrawString(470, 450, "You Won ", colors[WHITE]);
		glutSwapBuffers();
	}
	//map no 1
	static void mapno1()
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glutKeyboardFunc(map1control);
		screen2 = true;
		int rad = GetRandInRange(0, 20);
		DrawRectangle(0, 0, 1020, 10, colors[BLACK]);
		DrawRectangle(0, 750, 1020, 10, colors[BLACK]);
		DrawRectangle(0, 0, 10, 760, colors[BLACK]);
		DrawRectangle(1010, 0, 10, 760, colors[BLACK]);
		DrawRectangle(500, 755, 40, -80, colors[BLACK]);
		DrawRectangle(500, 0, 40, 80, colors[BLACK]);
		DrawRectangle(100, 450, 20, -150, colors[BLACK]);
		DrawRectangle(900, 450, 20, -150, colors[BLACK]);
		DrawRectangle(60, 431, 50, 20, colors[BLACK]);
		DrawRectangle(60, 299, 50, 20, colors[BLACK]);
		DrawRectangle(900, 450, 50, 20, colors[BLACK]);
		DrawRectangle(900, 299, 50, 20, colors[BLACK]);
		DrawRectangle(350, 550, 50, 20, colors[BLACK]);
		DrawRectangle(650, 550, 50, 20, colors[BLACK]);
		DrawRectangle(350, 250, 50, 20, colors[BLACK]);
		DrawRectangle(650, 250, 50, 20, colors[BLACK]);
		DrawRectangle(332, 569, 20, -50, colors[BLACK]);
		DrawRectangle(698, 569, 20, -50, colors[BLACK]);
		DrawRectangle(332, 301, 20, -50, colors[BLACK]);
		DrawRectangle(698, 301, 20, -50, colors[BLACK]);
		DrawRectangle(250, 370, 50, 50, colors[BLACK]);
		DrawRectangle(750, 370, 50, 50, colors[BLACK]);
		DrawRectangle(170, 650, 50, 20, colors[BLACK]);
		DrawRectangle(770, 650, 50, 20, colors[BLACK]);
		DrawRectangle(170, 150, 50, 20, colors[BLACK]);
		DrawRectangle(770, 150, 50, 20, colors[BLACK]);
		mapControl();
		if (type == 1)
		{
			fstream myfile;
			myfile.open("../" + name + ".txt", ios::out);
			myfile << 2 << endl;
			myfile << score1 << endl;
			myfile << score2 << endl;
			myfile << medium1 << endl;
			myfile << large1 << endl;
			myfile.close();
		}
		if (type ==1  && (score1 >= 10 || score2 >= 10))
		{
			fstream myfile;
			myfile.open("../" + name + ".txt", ios::out);
			myfile.close();
			if (score2 >= 10)
			{
				score1 = 10+score1;
				fstream myfile;
				myfile.open("Score.txt", ios::app);
				myfile << name << endl;
				myfile << score1 << endl;
				glutDisplayFunc(botwin);
				myfile.close();
			}
			if (score1 >= 10)
			{
				score1 = 0;
				score2 = 0;
				screen = false;
				glutDisplayFunc(levelthreescreen);
			}
		}
		glutKeyboardFunc(map1control);

		glutSwapBuffers();

	}
	// level 1 screen
	static void leveloneScreen()
    {
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		DrawString(500, 500, "Level no 1", colors[RED]);
		screen1 = true;
		if (screen == true)
		{
			glutDisplayFunc(mapno2);
		}
		glutSwapBuffers();
	}
	// level 2 screen
	static void leveltwoscreen()
	{
		
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		screen2 = true;
		timechekker = 5;
		v3->changecenter(GetRandInRange(100, 900), GetRandInRange(100, 600));
		if (screen == true)
		{
			glutDisplayFunc(mapno1);
		}
		DrawString(500, 500, "Level no 2", colors[RED]);
		glutSwapBuffers();
	}
	// level 3 screen
	static void levelthreescreen()
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		screen3 = true;
		timechekker = 5;
		v3->changecenter(GetRandInRange(100, 900), GetRandInRange(100, 600));
		if (screen == true)
		{
			glutDisplayFunc(mapno3);
		}
		DrawString(500, 500, "Level no 3", colors[RED]);
		glutSwapBuffers();
	}
	// mouse  function
	static void  mousecontrol(int button, int state, int x, int y)
	{
		if (x > 400 && x < 465 && y>320 && y < 345)
		{
			help1 = 0;
			help2 = 0;

		}
		if (x > 400 && x < 480 && y>370 && y < 390)
		{
			help1 = 1;
			help2 = 1;

		}
		glutPostRedisplay();
	}
	// mouse move function
	static void mousemove(int x, int y)
	{
		if (x > 400 && x < 465 && y>320 && y < 345)
		{
			help1 = 0;
			help2 = -1;

		}
		if (x > 400 && x < 480 && y>370 && y < 390)
		{
			help1 = 1;
			help2 = -1;

		}
		glutPostRedisplay();
	}
	//map no 2 screen
	static void mapno2()
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		DrawRectangle(0, 0, 1020, 30, colors[BLACK]);
		DrawRectangle(0, 750, 1020, 30, colors[BLACK]);
		DrawRectangle(0, 0, 30, 760, colors[BLACK]);
		DrawRectangle(990, 0, 30, 760, colors[BLACK]);
		DrawRectangle(350 - 100, 500, 100, 20, colors[BLACK]);
		DrawRectangle(330 - 100, 482, 140, 20, colors[BLACK]);
		DrawRectangle(310 - 100, 464, 180, 20, colors[BLACK]);
		DrawRectangle(310 - 100, 446, 180, 20, colors[BLACK]);
		DrawRectangle(350 - 100, 410, 100, 20, colors[BLACK]);
		DrawRectangle(330 - 100, 428, 140, 20, colors[BLACK]);
		DrawRectangle(300, 100, 400, 20, colors[BLACK]);
		DrawRectangle(500, 270, 30, 200, colors[BLACK]);
		DrawRectangle(350 + 300, 500, 100, 20, colors[BLACK]);
		DrawRectangle(330 + 300, 482, 140, 20, colors[BLACK]);
		DrawRectangle(310 + 300, 464, 180, 20, colors[BLACK]);
		DrawRectangle(310 + 300, 446, 180, 20, colors[BLACK]);
		DrawRectangle(350 + 300, 410, 100, 20, colors[BLACK]);
		DrawRectangle(330 + 300, 428, 140, 20, colors[BLACK]);
		if (type == 1)
		{
			fstream myfile;
			myfile.open("../" + name + ".txt", ios::out);
			myfile << 1 << endl;
			myfile << score1 << endl;
			myfile << score2 << endl;
			myfile << medium1 << endl;
			myfile << large1 << endl;
			myfile.close();

		}

		if (mode1 == 2  )
		{
			if (ii == 10 && v1->getr1_x() > 180 && v1->getr1_x() < 395 && (v1->getr1_y() > 330 && v1->getr1_y() < 370))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 180 && v1->getr1_x() < 395 && (v1->getr1_y() > 520 && v1->getr1_y() < 565))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 470 && v1->getr1_x() < 535 && (v1->getr1_y() > 195 && v1->getr1_y() < 230))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 470 && v1->getr1_x() < 535 && (v1->getr1_y() > 470 && v1->getr1_y() < 510))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 570 && v1->getr1_x() < 800 && (v1->getr1_y() > 330 && v1->getr1_y() < 380))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 570 && v1->getr1_x() < 800 && (v1->getr1_y() > 520 && v1->getr1_y() < 560))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 270 && v1->getr1_x() < 710 && (v1->getr1_y() > 25 && v1->getr1_y() < 45))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 270 && v1->getr1_x() < 710 && (v1->getr1_y() > 135 && v1->getr1_y() < 160))
			{
				kk = 3;
			}
			else if (v1->getr1_x() > 910 && v1->getr1_x() < 940 && ll == 40)
			{
				ll = 4;
			}
			else if (v1->getr1_x() > 50 && v1->getr1_x() < 60 && jj == 20)
			{
				jj = 2;
			}
			else if (v1->getr1_y() > 40 && v1->getr1_y() < 65 && kk == 30)
			{
				kk = 3;
			}
			else if (v1->getr1_y() > 670 && v1->getr1_y() < 690 && ii == 10)
			{
				ii = 1;
			}
			else if (jj == 20 && v1->getr1_x() > 380 && v1->getr1_x() < 395 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 180 && v1->getr1_x() < 195 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 540 && v1->getr1_x() < 560 && (v1->getr1_y() > 230 && v1->getr1_y() < 470))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 420 && v1->getr1_x() < 450 && (v1->getr1_y() > 230 && v1->getr1_y() < 470))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 780&& v1->getr1_x() < 800 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 570 && v1->getr1_x() < 585 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
			     ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 680 && v1->getr1_x() < 730 && (v1->getr1_y() > 60 && v1->getr1_y() < 120))
			{
				jj = 2;
			}
			else if (ll==40 && v1->getr1_x() > 210 && v1->getr1_x() <260  && (v1->getr1_y() > 60 && v1->getr1_y() < 120))
			{
				ll = 4;
			}
		}
		else if (mode1 == 1 )
		{
			if (ii == 10 && v1->getr1_x() > 180 && v1->getr1_x() < 395 && (v1->getr1_y() > 370 && v1->getr1_y() < 400))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 180 && v1->getr1_x() < 395 && (v1->getr1_y() > 470 && v1->getr1_y() < 510))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 470 && v1->getr1_x() < 535 && (v1->getr1_y() > 225 && v1->getr1_y() < 250))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 470 && v1->getr1_x() < 535 && (v1->getr1_y() > 440 && v1->getr1_y() < 460))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 570 && v1->getr1_x() < 800 && (v1->getr1_y() > 370 && v1->getr1_y() < 400))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 570 && v1->getr1_x() < 800 && (v1->getr1_y() > 470 && v1->getr1_y() < 510))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 270 && v1->getr1_x() < 710 && (v1->getr1_y() > 50 && v1->getr1_y() < 80))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 270 && v1->getr1_x() < 710 && (v1->getr1_y() > 100 && v1->getr1_y() < 110))
			{
				kk = 3;
			}
			else if (v1->getr1_x() > 940 && v1->getr1_x() < 990 && ll == 40)
			{
				ll = 4;
			}
			else if (v1->getr1_x() > 0 && v1->getr1_x() < 20 && jj == 20)
			{
				jj = 2;
			}
			else if (v1->getr1_y() >10 && v1->getr1_y() < 30 && kk == 30)
			{
				kk = 3;
			}
			else if (v1->getr1_y() > 710 && v1->getr1_y() < 740 && ii == 10)
			{
				ii = 1;
			}
			else if (jj == 20 && v1->getr1_x() > 340 && v1->getr1_x() < 375 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 160 && v1->getr1_x() < 185 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 495 && v1->getr1_x() < 520 && (v1->getr1_y() > 230 && v1->getr1_y() < 470))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 450 && v1->getr1_x() < 475 && (v1->getr1_y() > 230 && v1->getr1_y() < 470))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 750&& v1->getr1_x() < 780 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 570 && v1->getr1_x() < 610 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
			     ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 680 && v1->getr1_x() < 700 && (v1->getr1_y() > 60 && v1->getr1_y() < 120))
			{
				jj = 2;
			}
			else if (ll==40 && v1->getr1_x() > 250 && v1->getr1_x() <280&& (v1->getr1_y() > 60 && v1->getr1_y() < 120))
			{
				ll = 4;
			}
		}
		else if (mode1 == 0)
		{
			if (ii == 10 && v1->getr1_x() > 180 && v1->getr1_x() < 395 && (v1->getr1_y() > 350 && v1->getr1_y() < 380))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 180 && v1->getr1_x() < 395 && (v1->getr1_y() > 520 && v1->getr1_y() < 585))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 470 && v1->getr1_x() < 535 && (v1->getr1_y() > 210 && v1->getr1_y() < 260))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 470 && v1->getr1_x() < 535 && (v1->getr1_y() > 470 && v1->getr1_y() < 530))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 570 && v1->getr1_x() < 800 && (v1->getr1_y() > 350 && v1->getr1_y() < 380))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 570 && v1->getr1_x() < 800 && (v1->getr1_y() > 520 && v1->getr1_y() < 585))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 270 && v1->getr1_x() < 710 && (v1->getr1_y() > 50 && v1->getr1_y() < 65))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 270 && v1->getr1_x() < 710 && (v1->getr1_y() > 145 && v1->getr1_y() < 190))
			{
				kk = 3;
			}
			else if (v1->getr1_x() > 930 && v1->getr1_x() < 950 && ll == 40)
			{
				ll = 4;
			}
			else if (v1->getr1_x() > 50 && v1->getr1_x() < 90 && jj == 20)
			{
				jj = 2;
			}
			else if (v1->getr1_y() > 40 && v1->getr1_y() < 95 && kk == 30)
			{
				kk = 3;
			}
			else if (v1->getr1_y() > 690 && v1->getr1_y() < 70 && ii == 10)
			{
				ii = 1;
			}
			else if (jj == 20 && v1->getr1_x() > 380 && v1->getr1_x() < 460 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 160 && v1->getr1_x() < 195 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 570 && v1->getr1_x() < 600 && (v1->getr1_y() > 230 && v1->getr1_y() < 470))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 440 && v1->getr1_x() < 480 && (v1->getr1_y() > 230 && v1->getr1_y() < 470))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 780 && v1->getr1_x() < 850 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 540 && v1->getr1_x() < 585 && (v1->getr1_y() > 370 && v1->getr1_y() < 520))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 680 && v1->getr1_x() < 760 && (v1->getr1_y() > 60 && v1->getr1_y() < 120))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 240 && v1->getr1_x() < 260 && (v1->getr1_y() > 60 && v1->getr1_y() < 120))
			{
				ll = 4;
			}
        }
		if (fire == true)
		{

		}
		if (type == 2)
		{
			if (mode1 == 2)
			{
				if (aa == 10 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 330 && v2->getr1_y() < 370))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 520 && v2->getr1_y() < 565))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 195 && v2->getr1_y() < 230))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 470 && v2->getr1_y() < 510))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 330 && v2->getr1_y() < 380))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 520 && v2->getr1_y() < 560))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 25 && v2->getr1_y() < 45))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 135 && v2->getr1_y() < 160))
				{
					cc = 3;
				}
				else if (v2->getr1_x() > 910 && v2->getr1_x() < 940 && dd == 40)
				{
					dd = 4;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 60 && bb == 20)
				{
					bb = 2;
				}
				else if (v2->getr1_y() > 40 && v2->getr1_y() < 65 && cc == 30)
				{
					cc = 3;
				}
				else if (v2->getr1_y() > 670 && v2->getr1_y() < 690 && aa == 10)
				{
					aa = 1;
				}
				else if (bb == 20 && v2->getr1_x() > 380 && v2->getr1_x() < 395 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 180 && v2->getr1_x() < 195 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 540 && v2->getr1_x() < 560 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 420 && v2->getr1_x() < 450 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 780 && v2->getr1_x() < 800 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 570 && v2->getr1_x() < 585 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 680 && v2->getr1_x() < 730 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 210 && v2->getr1_x() < 260 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					dd = 4;
				}
			}
			else if (mode1 == 1)
			{
				if (aa == 10 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 370 && v2->getr1_y() < 400))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 470 && v2->getr1_y() < 510))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 225 && v2->getr1_y() < 250))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 440 && v2->getr1_y() < 460))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 370 && v2->getr1_y() < 400))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 470 && v2->getr1_y() < 510))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 50 && v2->getr1_y() < 80))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 100 && v2->getr1_y() < 110))
				{
					cc = 3;
				}
				else if (v2->getr1_x() > 940 && v2->getr1_x() < 990 && dd == 40)
				{
					dd = 4;
				}
				else if (v2->getr1_x() > 0 && v2->getr1_x() < 60 && bb == 20)
				{
					bb = 2;
				}
				else if (v2->getr1_y() > 50 && v2->getr1_y() < 60 && cc == 30)
				{
					cc = 3;
				}
				else if (v2->getr1_y() > 710 && v2->getr1_y() < 740 && aa == 10)
				{
					aa = 1;
				}
				else if (bb == 20 && v2->getr1_x() > 340 && v2->getr1_x() < 375 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 160 && v2->getr1_x() < 185 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 495 && v2->getr1_x() < 520 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 450 && v2->getr1_x() < 475 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 750 && v2->getr1_x() < 780 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 570 && v2->getr1_x() < 610 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 680 && v2->getr1_x() < 700 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 250 && v2->getr1_x() < 280 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					dd = 4;
				}
			}
			else if (mode1 == 0)
			{
				if (aa == 10 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 350 && v2->getr1_y() < 380))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 520 && v2->getr1_y() < 585))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 210 && v2->getr1_y() < 260))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 470 && v2->getr1_y() < 530))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 350 && v2->getr1_y() < 380))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 520 && v2->getr1_y() < 585))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 50 && v2->getr1_y() < 65))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 145 && v2->getr1_y() < 190))
				{
					cc = 3;
				}
				else if (v2->getr1_x() > 930 && v2->getr1_x() < 950 && dd == 40)
				{
					dd = 4;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 90 && bb == 20)
				{
					bb = 2;
				}
				else if (v2->getr1_y() > 80 && v2->getr1_y() < 95 && cc == 30)
				{
					cc = 3;
				}
				else if (v2->getr1_y() > 690 && v2->getr1_y() < 70 && aa == 10)
				{
					aa = 1;
				}
				else if (bb == 20 && v2->getr1_x() > 380 && v2->getr1_x() < 460 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 160 && v2->getr1_x() < 195 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 570 && v2->getr1_x() < 600 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 440 && v2->getr1_x() < 480 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 780 && v2->getr1_x() < 850 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 540 && v2->getr1_x() < 585 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 680 && v2->getr1_x() < 760 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 240 && v2->getr1_x() < 260 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					dd = 4;
				}
			}
		}
		if (type == 1)
		{
			if (mode1 == 2)
			{
				if (random == 2 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 330 && v2->getr1_y() < 370))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 520 && v2->getr1_y() < 565))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 195 && v2->getr1_y() < 230))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 470 && v2->getr1_y() < 510))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 330 && v2->getr1_y() < 380))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 520 && v2->getr1_y() < 560))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 25 && v2->getr1_y() < 45))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 135 && v2->getr1_y() < 160))
				{
					change = true;
					random = 2;
				}
				else if (v2->getr1_x() > 910 && v2->getr1_x() < 940 && random == 0)
				{
					random = 1;
					change = true;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 60 && random == 1)
				{
					random = 0;
					change = true;
				}
				else if (v2->getr1_y() > 40 && v2->getr1_y() < 65 && random == 3)
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_y() > 670 && v2->getr1_y() < 690 && random == 2)
				{
					random = 3;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 380 && v2->getr1_x() < 395 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 180 && v2->getr1_x() < 195 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 540 && v2->getr1_x() < 560 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					change = true;
					random = 0;
				}
				else if (random == 0 && v2->getr1_x() > 420 && v2->getr1_x() < 450 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 780 && v2->getr1_x() < 800 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 570 && v2->getr1_x() < 585 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 680 && v2->getr1_x() < 730 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 210 && v2->getr1_x() < 260 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					random = 1;
					change = true;
				}
			}
			else if (mode1 == 1)
			{
				if (random == 2 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 370 && v2->getr1_y() < 400))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 470 && v2->getr1_y() < 510))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 225 && v2->getr1_y() < 250))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 440 && v2->getr1_y() < 460))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 370 && v2->getr1_y() < 400))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 470 && v2->getr1_y() < 510))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 50 && v2->getr1_y() < 80))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 100 && v2->getr1_y() < 110))
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_x() > 940 && v2->getr1_x() < 990 && random == 0)
				{
					random = 1;
					change = true;
				}
				else if (v2->getr1_x() > 0 && v2->getr1_x() < 20 && random == 1)
				{
					random = 0;
					change = true;
				}
				else if (v2->getr1_y() > 10 && v2->getr1_y() < 30 && random == 3)
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_y() > 710 && v2->getr1_y() < 740 && random == 2)
				{
					random = 3;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 340 && v2->getr1_x() < 375 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 160 && v2->getr1_x() < 185 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 495 && v2->getr1_x() < 520 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 450 && v2->getr1_x() < 475 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 750 && v2->getr1_x() < 780 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					change = true;
					random = 0;
				}
				else if (random == 0 && v2->getr1_x() > 570 && v2->getr1_x() < 610 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 680 && v2->getr1_x() < 700 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 250 && v2->getr1_x() < 280 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					random = 1;
					change = true;
				}
			}
			else if (mode1 == 0)
			{
				if (random == 2 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 350 && v2->getr1_y() < 380))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 180 && v2->getr1_x() < 395 && (v2->getr1_y() > 520 && v2->getr1_y() < 585))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 210 && v2->getr1_y() < 260))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 470 && v2->getr1_x() < 535 && (v2->getr1_y() > 470 && v2->getr1_y() < 530))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 350 && v2->getr1_y() < 380))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 570 && v2->getr1_x() < 800 && (v2->getr1_y() > 520 && v2->getr1_y() < 585))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 50 && v2->getr1_y() < 65))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 270 && v2->getr1_x() < 710 && (v2->getr1_y() > 145 && v2->getr1_y() < 190))
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_x() > 930 && v2->getr1_x() < 950 && random == 0)
				{
					random = 1;
					change = true;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 90 && random == 1)
				{
					random = 0;
					change = true;
				}
				else if (v2->getr1_y() > 40 && v2->getr1_y() < 95 && random == 3)
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_y() > 690 && v2->getr1_y() < 70 && random == 2)
				{
					random = 3;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 380 && v2->getr1_x() < 460 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 160 && v2->getr1_x() < 195 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 570 && v2->getr1_x() < 600 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 440 && v2->getr1_x() < 480 && (v2->getr1_y() > 230 && v2->getr1_y() < 470))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 780 && v2->getr1_x() < 850 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 540 && v2->getr1_x() < 585 && (v2->getr1_y() > 370 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 680 && v2->getr1_x() < 760 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 240 && v2->getr1_x() < 260 && (v2->getr1_y() > 60 && v2->getr1_y() < 120))
				{
					random = 1;
					change = true;
				}
			}
		}
		mapControl();
		if (type == 1 && (score1 >= 10 || score2 >= 10))
		{
			fstream myfile;
			myfile.open("../" + name + ".txt", ios::out);
			myfile.close();
			if (score2 >= 10)
			{
				fstream myfile;
				myfile.open("Score.txt", ios::app);
				myfile << name << endl;
				myfile << score1 << endl;
				myfile.close();
				glutDisplayFunc(botwin);
			}
			if (score1 >= 10)
			{
				score1 = 0;
				score2 = 0;
				screen = false;
				glutDisplayFunc(leveltwoscreen);
			}
		}
		glutKeyboardFunc(map2control);
		glutSwapBuffers();
	}
	//keyboard screen
	static void function(unsigned char key);
	// map no3 screen
	static void mapno3()
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		screen3 = true;
		DrawRectangle(0, 0, 1020, 30,   colors[BLACK]);
		DrawRectangle(0, 750, 1020, 30, colors[BLACK]);
		DrawRectangle(0, 0, 30, 760,    colors[BLACK]);
		DrawRectangle(990, 0, 30, 760 , colors[BLACK]);
		DrawRectangle(500, 600, 40, -80,colors[BLACK]);
		DrawRectangle(500, 200, 40, 80, colors[BLACK]);
		DrawRectangle(300, 400, 80, 40, colors[BLACK]);
		DrawRectangle(650, 400, 80, 40, colors[BLACK]);
		DrawRectangle(200, 490, 20,-150,colors[BLACK]);
		DrawRectangle(800, 490, 20,-150,colors[BLACK]);
		DrawRectangle(160, 471, 50, 20, colors[BLACK]);
		DrawRectangle(160, 339, 50, 20, colors[BLACK]);
		DrawRectangle(800, 490, 50, 20, colors[BLACK]);
		DrawRectangle(800, 339, 50, 20, colors[BLACK]);


		if (mode1 == 2)
		{
			if (ii == 10 && v1->getr1_x() > 470 && v1->getr1_x() < 540 && (v1->getr1_y() > 130 && v1->getr1_y() < 170))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 470 && v1->getr1_x() < 540 && (v1->getr1_y() > 270 && v1->getr1_y() < 310))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 270 && v1->getr1_x() < 390 && (v1->getr1_y() > 330&& v1->getr1_y() < 360))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 270 && v1->getr1_x() < 390 && (v1->getr1_y() > 430 && v1->getr1_y() < 470))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 460 && v1->getr1_x() < 560 && (v1->getr1_y() > 450 && v1->getr1_y() < 490))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 460 && v1->getr1_x() < 560 && (v1->getr1_y() > 590 && v1->getr1_y() < 630))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 620 && v1->getr1_x() < 735 && (v1->getr1_y() > 330 && v1->getr1_y() < 370))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 620 && v1->getr1_x() < 735 && (v1->getr1_y() > 420 && v1->getr1_y() < 470))
			{
				kk = 3;
			}
			else if (v1->getr1_x() > 910 && v1->getr1_x() < 940 && ll == 40)
			{
				ll = 4;
			}
			else if (v1->getr1_x() > 50 && v1->getr1_x() < 60 && jj == 20)
			{
				jj = 2;
			}
			else if (v1->getr1_y() > 40 && v1->getr1_y() < 65 && kk == 30)
			{
				kk = 3;
			}
			else if (v1->getr1_y() > 670 && v1->getr1_y() < 690 && ii == 10)
			{
				ii = 1;
			}
			else if (jj == 20 && v1->getr1_x() > 500 && v1->getr1_x() < 560 && (v1->getr1_y() > 170 && v1->getr1_y() < 280))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 420 && v1->getr1_x() < 500 && (v1->getr1_y() > 170 && v1->getr1_y() < 280))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 350 && v1->getr1_x() < 400 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 220 && v1->getr1_x() <250 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 520 && v1->getr1_x() < 580 && (v1->getr1_y() > 490 && v1->getr1_y() < 600))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 420 && v1->getr1_x() <450  && (v1->getr1_y() > 490 && v1->getr1_y() < 600))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 700 && v1->getr1_x() < 755 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 570 && v1->getr1_x() < 600 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				ll = 4;
			}

			else if (ii == 10 && v1->getr1_x() > 770 && v1->getr1_x() < 860 && (v1->getr1_y() > 265 && v1->getr1_y() < 300))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 770 && v1->getr1_x() < 860 && (v1->getr1_y() > 500 && v1->getr1_y() < 530))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 120 && v1->getr1_x() < 210 && (v1->getr1_y() > 265 && v1->getr1_y() < 300))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 120 && v1->getr1_x() < 210 && (v1->getr1_y() > 500 && v1->getr1_y() < 550))
			{
				kk = 3;
			}
			else if (jj == 20 && v1->getr1_x() > 810 && v1->getr1_x() < 880 && (v1->getr1_y() > 295 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 730 && v1->getr1_x() < 770 && (v1->getr1_y() > 295 && v1->getr1_y() < 520))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 160 && v1->getr1_x() < 250 && (v1->getr1_y() > 300 && v1->getr1_y() < 500))
			{
			jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 90 && v1->getr1_x() < 120 && (v1->getr1_y() > 300 && v1->getr1_y() < 500))
			{
			ll = 4;
			}
		}
		else if (mode1 == 1)
		{
			if (ii == 10 && v1->getr1_x() > 470 && v1->getr1_x() < 540 && (v1->getr1_y() > 170 && v1->getr1_y() < 200))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 470 && v1->getr1_x() < 540 && (v1->getr1_y() > 260 && v1->getr1_y() < 280))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 270 && v1->getr1_x() < 390 && (v1->getr1_y() > 330+30 && v1->getr1_y() < 360))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 270 && v1->getr1_x() < 390 && (v1->getr1_y() > 430-20 && v1->getr1_y() < 470-40))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 460 && v1->getr1_x() < 560 && (v1->getr1_y() > 450+30 && v1->getr1_y() < 490+20))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 460 && v1->getr1_x() < 560 && (v1->getr1_y() > 590-20 && v1->getr1_y() < 630-40))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 620 && v1->getr1_x() < 735 && (v1->getr1_y() > 330 +30&& v1->getr1_y() < 390))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 620 && v1->getr1_x() < 735 && (v1->getr1_y() > 420-20 && v1->getr1_y() < 470-40))
			{
				kk = 3;
			}
			else if (v1->getr1_x() > 940 && v1->getr1_x() < 1000 && ll == 40)
			{
				ll = 4;
			}
			else if (v1->getr1_x() > 0 && v1->getr1_x() < 20 && jj == 20)
			{
				jj = 2;
			}
			else if (v1->getr1_y() > 10 && v1->getr1_y() < 30 && kk == 30)
			{
				kk = 3;
			}
			else if (v1->getr1_y() > 690 && v1->getr1_y() < 720 && ii == 10)
			{
				ii = 1;
			}
			else if (jj == 20 && v1->getr1_x() > 500&& v1->getr1_x() < 560 - 40 && (v1->getr1_y() > 170 && v1->getr1_y() < 280))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 420+40 && v1->getr1_x() < 480 && (v1->getr1_y() > 170 && v1->getr1_y() < 280))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 350- 40 && v1->getr1_x() < 400- 40 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 220 + 40 && v1->getr1_x() < 250 + 40 && (v1->getr1_y() > 370 + 40 && v1->getr1_y() < 440))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 520- 40 && v1->getr1_x() < 580- 40 && (v1->getr1_y() > 490 && v1->getr1_y() < 600))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 420+ 40 && v1->getr1_x() < 450+ 40 && (v1->getr1_y() > 490 && v1->getr1_y() < 600))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 700 - 40 && v1->getr1_x() < 755- 40 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 570 +40 && v1->getr1_x() < 600+40  && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				ll = 4;
			}

			else if (ii == 10 && v1->getr1_x() > 770 && v1->getr1_x() < 850 && (v1->getr1_y() > 295 && v1->getr1_y() < 330))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 770 && v1->getr1_x() < 850 && (v1->getr1_y() > 470 && v1->getr1_y() < 500))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 120 && v1->getr1_x() < 210 && (v1->getr1_y() > 295 && v1->getr1_y() < 320))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 120 && v1->getr1_x() < 210 && (v1->getr1_y() > 420 && v1->getr1_y() < 480))
			{
				kk = 3;
			}
			else if (jj == 20 && v1->getr1_x() > 785 && v1->getr1_x() < 850 && (v1->getr1_y() > 295 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 750 && v1->getr1_x() < 800 && (v1->getr1_y() > 295 && v1->getr1_y() < 520))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() >  160&& v1->getr1_x() < 210 && (v1->getr1_y() > 300 && v1->getr1_y() < 500))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 120 && v1->getr1_x() < 150 && (v1->getr1_y() > 300 && v1->getr1_y() < 500))
			{
				ll = 4;
			}
		}
		else if (mode1 == 0)
		{
			if (ii == 10 && v1->getr1_x() > 470 && v1->getr1_x() < 540 && (v1->getr1_y() > 150 && v1->getr1_y() < 170))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 470 && v1->getr1_x() < 540 && (v1->getr1_y() > 200 && v1->getr1_y() < 340))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 270 && v1->getr1_x() < 390 && (v1->getr1_y() > 350 && v1->getr1_y() < 370))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 270 && v1->getr1_x() < 390 && (v1->getr1_y() > 480 && v1->getr1_y() < 510))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 460 && v1->getr1_x() < 560 && (v1->getr1_y() > 470 && v1->getr1_y() < 500))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 460 && v1->getr1_x() < 560 && (v1->getr1_y() > 640 && v1->getr1_y() < 670))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 620 && v1->getr1_x() < 735 && (v1->getr1_y() > 350 && v1->getr1_y() < 380))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 620 && v1->getr1_x() < 735 && (v1->getr1_y() > 480 && v1->getr1_y() < 510))
			{
				kk = 3;
			}
			else if (v1->getr1_x() > 930 && v1->getr1_x() < 960 && ll == 40)
			{
				ll = 4;
			}
			else if (v1->getr1_x() > 50 && v1->getr1_x() < 100 && jj == 20)
			{
				jj = 2;
			}
			else if (v1->getr1_y() > 40 && v1->getr1_y() < 105 && kk == 30)
			{
				kk = 3;
			}
			else if (v1->getr1_y() > 690 && v1->getr1_y() < 720 && ii == 10)
			{
				ii = 1;
			}
			else if (jj == 20 && v1->getr1_x() > 560 && v1->getr1_x() < 600 && (v1->getr1_y() > 170 && v1->getr1_y() < 280))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 440 && v1->getr1_x() < 500 && (v1->getr1_y() > 170 && v1->getr1_y() < 280))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 400 && v1->getr1_x() < 440 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 240 && v1->getr1_x() < 270 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 580 && v1->getr1_x() < 620 && (v1->getr1_y() > 490 && v1->getr1_y() < 600))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 440 && v1->getr1_x() < 470 && (v1->getr1_y() > 490 && v1->getr1_y() < 600))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 750 && v1->getr1_x() < 795 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 590 && v1->getr1_x() < 630 && (v1->getr1_y() > 370 && v1->getr1_y() < 440))
			{
				ll = 4;
			}

			else if (ii == 10 && v1->getr1_x() > 770 && v1->getr1_x() < 860 && (v1->getr1_y() > 285 && v1->getr1_y() < 310))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 770 && v1->getr1_x() < 860 && (v1->getr1_y() > 550 && v1->getr1_y() < 580))
			{
				kk = 3;
			}
			else if (ii == 10 && v1->getr1_x() > 120 && v1->getr1_x() < 210 && (v1->getr1_y() > 280 && v1->getr1_y() < 310))
			{
				ii = 1;
			}
			else if (kk == 30 && v1->getr1_x() > 120 && v1->getr1_x() < 210 && (v1->getr1_y() > 550 && v1->getr1_y() < 560))
			{
				kk = 3;
			}
			else if (jj == 20 && v1->getr1_x() > 880 && v1->getr1_x() < 920 && (v1->getr1_y() > 295 && v1->getr1_y() < 520))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 750 && v1->getr1_x() < 770 && (v1->getr1_y() > 295 && v1->getr1_y() < 520))
			{
				ll = 4;
			}
			else if (jj == 20 && v1->getr1_x() > 250 && v1->getr1_x() < 290 && (v1->getr1_y() > 300 && v1->getr1_y() < 500))
			{
				jj = 2;
			}
			else if (ll == 40 && v1->getr1_x() > 110 && v1->getr1_x() < 120 && (v1->getr1_y() > 300 && v1->getr1_y() < 500))
			{
				ll = 4;
			}
        }
		if (type == 2)
		{
			if (mode1 == 2)
			{
				if (aa == 10 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 130 && v2->getr1_y() < 170))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 270 && v2->getr1_y() < 310))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 330 && v2->getr1_y() < 360))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 430 && v2->getr1_y() < 470))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 450 && v2->getr1_y() < 490))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 590 && v2->getr1_y() < 630))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 330 && v2->getr1_y() < 370))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 420 && v2->getr1_y() < 470))
				{
					cc = 3;
				}
				else if (v2->getr1_x() > 910 && v2->getr1_x() < 940 && dd == 40)
				{
					dd = 4;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 60 && bb == 20)
				{
					bb = 2;
				}
				else if (v2->getr1_y() > 40 && v2->getr1_y() < 65 && cc == 30)
				{
					cc = 3;
				}
				else if (v2->getr1_y() > 670 && v2->getr1_y() < 690 && aa == 10)
				{
					aa = 1;
				}
				else if (bb == 20 && v2->getr1_x() > 500 && v2->getr1_x() < 560 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 420 && v2->getr1_x() < 500 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 350 && v2->getr1_x() < 400 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 220 && v2->getr1_x() < 250 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 520 && v2->getr1_x() < 580 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 420 && v2->getr1_x() < 450 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 700 && v2->getr1_x() < 755 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 570 && v2->getr1_x() < 600 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					dd = 4;
				}

				else if (aa == 10 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 265 && v2->getr1_y() < 300))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 500 && v2->getr1_y() < 530))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 265 && v2->getr1_y() < 300))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 500 && v2->getr1_y() < 550))
				{
					cc = 3;
				}
				else if (bb == 20 && v2->getr1_x() > 810 && v2->getr1_x() < 880 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 730 && v2->getr1_x() < 770 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 160 && v2->getr1_x() < 250 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 90 && v2->getr1_x() < 120 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					dd = 4;
				}
			}
			else if (mode1 == 1)
			{
				if (aa == 10 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 170 && v2->getr1_y() < 200))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 260 && v2->getr1_y() < 280))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 330 + 30 && v2->getr1_y() < 360))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 430 - 20 && v2->getr1_y() < 470 - 40))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 450 + 30 && v2->getr1_y() < 490 + 20))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 590 - 20 && v2->getr1_y() < 630 - 40))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 330 + 30 && v2->getr1_y() < 390))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 420 - 20 && v2->getr1_y() < 470 - 40))
				{
					cc = 3;
				}
				else if (v2->getr1_x() > 940 && v2->getr1_x() < 1000 && dd == 40)
				{
					dd = 4;
				}
				else if (v2->getr1_x() > 0 && v2->getr1_x() < 20 && bb == 20)
				{
					bb = 2;
				}
				else if (v2->getr1_y() > 10 && v2->getr1_y() < 30 && cc == 30)
				{
					cc = 3;
				}
				else if (v2->getr1_y() > 690 && v2->getr1_y() < 720 && aa == 10)
				{
					aa = 1;
				}
				else if (bb == 20 && v2->getr1_x() > 500 && v2->getr1_x() < 560 - 40 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 420 + 40 && v2->getr1_x() < 480 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 350 - 40 && v2->getr1_x() < 400 - 40 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 220 + 40 && v2->getr1_x() < 250 + 40 && (v2->getr1_y() > 370 + 40 && v2->getr1_y() < 440))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 520 - 40 && v2->getr1_x() < 580 - 40 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 420 + 40 && v2->getr1_x() < 450 + 40 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 700 - 40 && v2->getr1_x() < 755 - 40 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 570 + 40 && v2->getr1_x() < 600 + 40 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					dd = 4;
				}

				else if (aa == 10 && v2->getr1_x() > 770 && v2->getr1_x() < 850 && (v2->getr1_y() > 295 && v2->getr1_y() < 330))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 770 && v2->getr1_x() < 850 && (v2->getr1_y() > 470 && v2->getr1_y() < 500))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 295 && v2->getr1_y() < 320))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 420 && v2->getr1_y() < 480))
				{
					cc = 3;
				}
				else if (bb == 20 && v2->getr1_x() > 785 && v2->getr1_x() < 850 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 750 && v2->getr1_x() < 800 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 160 && v2->getr1_x() < 210 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 120 && v2->getr1_x() < 150 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					dd = 4;
				}
			}
			else if (mode1 == 0)
			{
				if (aa == 10 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 150 && v2->getr1_y() < 170))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 200 && v2->getr1_y() < 340))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 350 && v2->getr1_y() < 370))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 480 && v2->getr1_y() < 510))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 470 && v2->getr1_y() < 500))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 640 && v2->getr1_y() < 670))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 350 && v2->getr1_y() < 380))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 480 && v2->getr1_y() < 510))
				{
					cc = 3;
				}
				else if (v2->getr1_x() > 930 && v2->getr1_x() < 960 && dd == 40)
				{
					dd = 4;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 100 && bb == 20)
				{
					bb = 2;
				}
				else if (v2->getr1_y() > 40 && v2->getr1_y() < 105 && cc == 30)
				{
					cc = 3;
				}
				else if (v2->getr1_y() > 690 && v2->getr1_y() < 720 && aa == 10)
				{
					aa = 1;
				}
				else if (bb == 20 && v2->getr1_x() > 560 && v2->getr1_x() < 600 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 440 && v2->getr1_x() < 500 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 400 && v2->getr1_x() < 440 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 240 && v2->getr1_x() < 270 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 580 && v2->getr1_x() < 620 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 440 && v2->getr1_x() < 470 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 750 && v2->getr1_x() < 795 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 590 && v2->getr1_x() < 630 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					dd = 4;
				}

				else if (aa == 10 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 285 && v2->getr1_y() < 310))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 550 && v2->getr1_y() < 580))
				{
					cc = 3;
				}
				else if (aa == 10 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 280 && v2->getr1_y() < 310))
				{
					aa = 1;
				}
				else if (cc == 30 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 550 && v2->getr1_y() < 560))
				{
					cc = 3;
				}
				else if (bb == 20 && v2->getr1_x() > 880 && v2->getr1_x() < 920 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 750 && v2->getr1_x() < 770 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					dd = 4;
				}
				else if (bb == 20 && v2->getr1_x() > 250 && v2->getr1_x() < 290 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					bb = 2;
				}
				else if (dd == 40 && v2->getr1_x() > 110 && v2->getr1_x() < 120 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					dd = 4;
				}
			}
		}
		else if (type == 1)
		{
			if (mode1 == 2)
			{
				if (random == 2 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 130 && v2->getr1_y() < 170))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 270 && v2->getr1_y() < 310))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 330 && v2->getr1_y() < 360))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 430 && v2->getr1_y() < 470))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 450 && v2->getr1_y() < 490))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 590 && v2->getr1_y() < 630))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 330 && v2->getr1_y() < 370))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 420 && v2->getr1_y() < 470))
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_x() > 910 && v2->getr1_x() < 940 && random == 0)
				{
					random = 1;
					change = true;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 60 && random == 1)
				{
					random = 0;
					change = true;
				}
				else if (v2->getr1_y() > 40 && v2->getr1_y() < 65 && random == 3)
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_y() > 670 && v2->getr1_y() < 690 && random == 2)
				{
					random = 3;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 500 && v2->getr1_x() < 560 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 420 && v2->getr1_x() < 500 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 350 && v2->getr1_x() < 400 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 220 && v2->getr1_x() < 250 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 520 && v2->getr1_x() < 580 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 420 && v2->getr1_x() < 450 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 700 && v2->getr1_x() < 755 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 570 && v2->getr1_x() < 600 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 1;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 265 && v2->getr1_y() < 300))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 500 && v2->getr1_y() < 530))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 265 && v2->getr1_y() < 300))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 500 && v2->getr1_y() < 550))
				{
					random = 2;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 810 && v2->getr1_x() < 880 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 730 && v2->getr1_x() < 770 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 160 && v2->getr1_x() < 250 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 90 && v2->getr1_x() < 120 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					random = 1;
					change = true;
				}
			}
			else if (mode1 == 1)
			{
				if (random == 2 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 170 && v2->getr1_y() < 200))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 260 && v2->getr1_y() < 280))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 330 + 30 && v2->getr1_y() < 360))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 430 - 20 && v2->getr1_y() < 470 - 40))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 450 + 30 && v2->getr1_y() < 490 + 20))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 590 - 20 && v2->getr1_y() < 630 - 40))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 330 + 30 && v2->getr1_y() < 390))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 420 - 20 && v2->getr1_y() < 470 - 40))
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_x() > 940 && v2->getr1_x() < 1000 && random == 0)
				{
					random = 1;
					change = true;
				}
				else if (v2->getr1_x() > 0 && v2->getr1_x() < 20 && random == 1)
				{
					random = 0;
					change = true;
				}
				else if (v2->getr1_y() > 10 && v2->getr1_y() < 30 && random == 3)
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_y() > 690 && v2->getr1_y() < 720 && random == 2)
				{
					random = 3;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 500 && v2->getr1_x() < 560 - 40 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 420 + 40 && v2->getr1_x() < 480 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 350 - 40 && v2->getr1_x() < 400 - 40 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 220 + 40 && v2->getr1_x() < 250 + 40 && (v2->getr1_y() > 370 + 40 && v2->getr1_y() < 440))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 520 - 40 && v2->getr1_x() < 580 - 40 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 420 + 40 && v2->getr1_x() < 450 + 40 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 700 - 40 && v2->getr1_x() < 755 - 40 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 570 + 40 && v2->getr1_x() < 600 + 40 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 1;
					change = true;
				}

				else if (random == 2 && v2->getr1_x() > 770 && v2->getr1_x() < 850 && (v2->getr1_y() > 295 && v2->getr1_y() < 330))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 770 && v2->getr1_x() < 850 && (v2->getr1_y() > 470 && v2->getr1_y() < 500))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 295 && v2->getr1_y() < 320))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 420 && v2->getr1_y() < 480))
				{
					random = 2;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 785 && v2->getr1_x() < 850 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 750 && v2->getr1_x() < 800 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 160 && v2->getr1_x() < 210 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 120 && v2->getr1_x() < 150 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					random = 1;
					change = true;
				}
			}
			else if (mode1 == 0)
			{
				if (random == 2 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 150 && v2->getr1_y() < 170))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 470 && v2->getr1_x() < 540 && (v2->getr1_y() > 200 && v2->getr1_y() < 340))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 350 && v2->getr1_y() < 370))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 270 && v2->getr1_x() < 390 && (v2->getr1_y() > 480 && v2->getr1_y() < 510))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 470 && v2->getr1_y() < 500))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 460 && v2->getr1_x() < 560 && (v2->getr1_y() > 640 && v2->getr1_y() < 670))
				{
					random = 2;
					change = true;
				}
				else if (random == 2 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 350 && v2->getr1_y() < 380))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 620 && v2->getr1_x() < 735 && (v2->getr1_y() > 480 && v2->getr1_y() < 510))
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_x() > 930 && v2->getr1_x() < 960 && random == 0)
				{
					random = 1;
					change = true;
				}
				else if (v2->getr1_x() > 50 && v2->getr1_x() < 100 && random == 1)
				{
					random = 0;
					change = true;
				}
				else if (v2->getr1_y() > 40 && v2->getr1_y() < 105 && random == 3)
				{
					random = 2;
					change = true;
				}
				else if (v2->getr1_y() > 690 && v2->getr1_y() < 720 && random == 2)
				{
					random = 3; change = true;
				}
				else if (random == 1 && v2->getr1_x() > 560 && v2->getr1_x() < 600 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 440 && v2->getr1_x() < 500 && (v2->getr1_y() > 170 && v2->getr1_y() < 280))
				{
					random = 1;
					change = true;
				}
				else if (random == 1 && v2->getr1_x() > 400 && v2->getr1_x() < 440 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 240 && v2->getr1_x() < 270 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 1; change = true;
				}
				else if (random == 1 && v2->getr1_x() > 580 && v2->getr1_x() < 620 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					random = 0; change = true;
				}
				else if (random == 0 && v2->getr1_x() > 440 && v2->getr1_x() < 470 && (v2->getr1_y() > 490 && v2->getr1_y() < 600))
				{
					random = 1; change = true;
				}
				else if (random == 1 && v2->getr1_x() > 750 && v2->getr1_x() < 795 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 0; change = true;
				}
				else if (random == 0 && v2->getr1_x() > 590 && v2->getr1_x() < 630 && (v2->getr1_y() > 370 && v2->getr1_y() < 440))
				{
					random = 1; change = true;
				}

				else if (random == 2 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 285 && v2->getr1_y() < 310))
				{
					random = 3;
					change = true;
				}
				else if (random == 3 && v2->getr1_x() > 770 && v2->getr1_x() < 860 && (v2->getr1_y() > 550 && v2->getr1_y() < 580))
				{
					random = 2; change = true;
				}
				else if (random == 2 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 280 && v2->getr1_y() < 310))
				{
					random = 3; change = true;
				}
				else if (random == 3 && v2->getr1_x() > 120 && v2->getr1_x() < 210 && (v2->getr1_y() > 550 && v2->getr1_y() < 560))
				{
					random = 2; change = true;
				}
				else if (random == 1 && v2->getr1_x() > 880 && v2->getr1_x() < 920 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					random = 0;
					change = true;
				}
				else if (random == 0 && v2->getr1_x() > 750 && v2->getr1_x() < 770 && (v2->getr1_y() > 295 && v2->getr1_y() < 520))
				{
					random = 1; change = true;
				}
				else if (random == 1 && v2->getr1_x() > 250 && v2->getr1_x() < 290 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					random = 0; change = true;
				}
				else if (random == 0 && v2->getr1_x() > 110 && v2->getr1_x() < 120 && (v2->getr1_y() > 300 && v2->getr1_y() < 500))
				{
					random = 1; change = true;
				}
			}
			if (mode1 == 2)
			{
				if (random1 == 2 && v3->getr1_x() > 470 && v3->getr1_x() < 540 && (v3->getr1_y() > 130 && v3->getr1_y() < 170))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 470 && v3->getr1_x() < 540 && (v3->getr1_y() > 270 && v3->getr1_y() < 310))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 270 && v3->getr1_x() < 390 && (v3->getr1_y() > 330 && v3->getr1_y() < 360))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 270 && v3->getr1_x() < 390 && (v3->getr1_y() > 430 && v3->getr1_y() < 470))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 460 && v3->getr1_x() < 560 && (v3->getr1_y() > 450 && v3->getr1_y() < 490))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 460 && v3->getr1_x() < 560 && (v3->getr1_y() > 590 && v3->getr1_y() < 630))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 620 && v3->getr1_x() < 735 && (v3->getr1_y() > 330 && v3->getr1_y() < 370))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 620 && v3->getr1_x() < 735 && (v3->getr1_y() > 420 && v3->getr1_y() < 470))
				{
					random1 = 2;
					change1 = true;
				}
				else if (v3->getr1_x() > 910 && v3->getr1_x() < 940 && random1 == 0)
				{
					random1 = 1;
					change1 = true;
				}
				else if (v3->getr1_x() > 50 && v3->getr1_x() < 60 && random1 == 1)
				{
					random1 = 0;
					change1 = true;
				}
				else if (v3->getr1_y() > 40 && v3->getr1_y() < 65 && random1 == 3)
				{
					random1 = 2;
					change1 = true;
				}
				else if (v3->getr1_y() > 670 && v3->getr1_y() < 690 && random1 == 2)
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 500 && v3->getr1_x() < 560 && (v3->getr1_y() > 170 && v3->getr1_y() < 280))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 420 && v3->getr1_x() < 500 && (v3->getr1_y() > 170 && v3->getr1_y() < 280))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 350 && v3->getr1_x() < 400 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 220 && v3->getr1_x() < 250 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 520 && v3->getr1_x() < 580 && (v3->getr1_y() > 490 && v3->getr1_y() < 600))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 420 && v3->getr1_x() < 450 && (v3->getr1_y() > 490 && v3->getr1_y() < 600))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 700 && v3->getr1_x() < 755 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 570 && v3->getr1_x() < 600 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 770 && v3->getr1_x() < 860 && (v3->getr1_y() > 265 && v3->getr1_y() < 300))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 770 && v3->getr1_x() < 860 && (v3->getr1_y() > 500 && v3->getr1_y() < 530))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 120 && v3->getr1_x() < 210 && (v3->getr1_y() > 265 && v3->getr1_y() < 300))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 120 && v3->getr1_x() < 210 && (v3->getr1_y() > 500 && v3->getr1_y() < 550))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 810 && v3->getr1_x() < 880 && (v3->getr1_y() > 295 && v3->getr1_y() < 520))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 730 && v3->getr1_x() < 770 && (v3->getr1_y() > 295 && v3->getr1_y() < 520))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 160 && v3->getr1_x() < 250 && (v3->getr1_y() > 300 && v3->getr1_y() < 500))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 90 && v3->getr1_x() < 120 && (v3->getr1_y() > 300 && v3->getr1_y() < 500))
				{
					random1 = 1;
					change1 = true;
				}
			}
			else if (mode1 == 1)
			{
				if (random1 == 2 && v3->getr1_x() > 470 && v3->getr1_x() < 540 && (v3->getr1_y() > 170 && v3->getr1_y() < 200))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 470 && v3->getr1_x() < 540 && (v3->getr1_y() > 260 && v3->getr1_y() < 280))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 270 && v3->getr1_x() < 390 && (v3->getr1_y() > 330 + 30 && v3->getr1_y() < 360))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 270 && v3->getr1_x() < 390 && (v3->getr1_y() > 430 - 20 && v3->getr1_y() < 470 - 40))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 460 && v3->getr1_x() < 560 && (v3->getr1_y() > 450 + 30 && v3->getr1_y() < 490 + 20))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 460 && v3->getr1_x() < 560 && (v3->getr1_y() > 590 - 20 && v3->getr1_y() < 630 - 40))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 620 && v3->getr1_x() < 735 && (v3->getr1_y() > 330 + 30 && v3->getr1_y() < 390))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 620 && v3->getr1_x() < 735 && (v3->getr1_y() > 420 - 20 && v3->getr1_y() < 470 - 40))
				{
					random1 = 2;
					change1 = true;
				}
				else if (v3->getr1_x() > 940 && v3->getr1_x() < 1000 && random1 == 0)
				{
					random1 = 1;
					change1 = true;
				}
				else if (v3->getr1_x() > 0 && v3->getr1_x() < 20 && random1 == 1)
				{
					random1 = 0;
					change1 = true;
				}
				else if (v3->getr1_y() > 10 && v3->getr1_y() < 30 && random1 == 3)
				{
					random1 = 2;
					change1 = true;
				}
				else if (v3->getr1_y() > 690 && v3->getr1_y() < 720 && random1 == 2)
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 500 && v3->getr1_x() < 560 - 40 && (v3->getr1_y() > 170 && v3->getr1_y() < 280))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 420 + 40 && v3->getr1_x() < 480 && (v3->getr1_y() > 170 && v3->getr1_y() < 280))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 350 - 40 && v3->getr1_x() < 400 - 40 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 220 + 40 && v3->getr1_x() < 250 + 40 && (v3->getr1_y() > 370 + 40 && v3->getr1_y() < 440))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 520 - 40 && v3->getr1_x() < 580 - 40 && (v3->getr1_y() > 490 && v3->getr1_y() < 600))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 420 + 40 && v3->getr1_x() < 450 + 40 && (v3->getr1_y() > 490 && v3->getr1_y() < 600))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 700 - 40 && v3->getr1_x() < 755 - 40 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 570 + 40 && v3->getr1_x() < 600 + 40 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 1;
					change1 = true;
				}

				else if (random1 == 2 && v3->getr1_x() > 770 && v3->getr1_x() < 850 && (v3->getr1_y() > 295 && v3->getr1_y() < 330))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 770 && v3->getr1_x() < 850 && (v3->getr1_y() > 470 && v3->getr1_y() < 500))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 120 && v3->getr1_x() < 210 && (v3->getr1_y() > 295 && v3->getr1_y() < 320))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 120 && v3->getr1_x() < 210 && (v3->getr1_y() > 420 && v3->getr1_y() < 480))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 785 && v3->getr1_x() < 850 && (v3->getr1_y() > 295 && v3->getr1_y() < 520))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 750 && v3->getr1_x() < 800 && (v3->getr1_y() > 295 && v3->getr1_y() < 520))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 160 && v3->getr1_x() < 210 && (v3->getr1_y() > 300 && v3->getr1_y() < 500))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 120 && v3->getr1_x() < 150 && (v3->getr1_y() > 300 && v3->getr1_y() < 500))
				{
					random1 = 1;
					change1 = true;
				}
			}
			else if (mode1 == 0)
			{
				if (random1 == 2 && v3->getr1_x() > 470 && v3->getr1_x() < 540 && (v3->getr1_y() > 150 && v3->getr1_y() < 170))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 470 && v3->getr1_x() < 540 && (v3->getr1_y() > 200 && v3->getr1_y() < 340))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 270 && v3->getr1_x() < 390 && (v3->getr1_y() > 350 && v3->getr1_y() < 370))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 270 && v3->getr1_x() < 390 && (v3->getr1_y() > 480 && v3->getr1_y() < 510))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 460 && v3->getr1_x() < 560 && (v3->getr1_y() > 470 && v3->getr1_y() < 500))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 460 && v3->getr1_x() < 560 && (v3->getr1_y() > 640 && v3->getr1_y() < 670))
				{
					random1 = 2;
					change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 620 && v3->getr1_x() < 735 && (v3->getr1_y() > 350 && v3->getr1_y() < 380))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 620 && v3->getr1_x() < 735 && (v3->getr1_y() > 480 && v3->getr1_y() < 510))
				{
					random1 = 2;
					change1 = true;
				}
				else if (v3->getr1_x() > 930 && v3->getr1_x() < 960 && random1 == 0)
				{
					random1 = 1;
					change1 = true;
				}
				else if (v3->getr1_x() > 50 && v3->getr1_x() < 100 && random1 == 1)
				{
					random1 = 0;
					change1 = true;
				}
				else if (v3->getr1_y() > 40 && v3->getr1_y() < 105 && random1 == 3)
				{
					random1 = 2;
					change1 = true;
				}
				else if (v3->getr1_y() > 690 && v3->getr1_y() < 720 && random1 == 2)
				{
					random1 = 3; change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 560 && v3->getr1_x() < 600 && (v3->getr1_y() > 170 && v3->getr1_y() < 280))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 440 && v3->getr1_x() < 500 && (v3->getr1_y() > 170 && v3->getr1_y() < 280))
				{
					random1 = 1;
					change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 400 && v3->getr1_x() < 440 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 240 && v3->getr1_x() < 270 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 1; change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 580 && v3->getr1_x() < 620 && (v3->getr1_y() > 490 && v3->getr1_y() < 600))
				{
					random1 = 0; change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 440 && v3->getr1_x() < 470 && (v3->getr1_y() > 490 && v3->getr1_y() < 600))
				{
					random1 = 1; change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 750 && v3->getr1_x() < 795 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 0; change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 590 && v3->getr1_x() < 630 && (v3->getr1_y() > 370 && v3->getr1_y() < 440))
				{
					random1 = 1; change1 = true;
				}

				else if (random1 == 2 && v3->getr1_x() > 770 && v3->getr1_x() < 860 && (v3->getr1_y() > 285 && v3->getr1_y() < 310))
				{
					random1 = 3;
					change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 770 && v3->getr1_x() < 860 && (v3->getr1_y() > 550 && v3->getr1_y() < 580))
				{
					random1 = 2; change1 = true;
				}
				else if (random1 == 2 && v3->getr1_x() > 120 && v3->getr1_x() < 210 && (v3->getr1_y() > 280 && v3->getr1_y() < 310))
				{
					random1 = 3; change1 = true;
				}
				else if (random1 == 3 && v3->getr1_x() > 120 && v3->getr1_x() < 210 && (v3->getr1_y() > 550 && v3->getr1_y() < 560))
				{
					random1 = 2; change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 880 && v3->getr1_x() < 920 && (v3->getr1_y() > 295 && v3->getr1_y() < 520))
				{
					random1 = 0;
					change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 750 && v3->getr1_x() < 770 && (v3->getr1_y() > 295 && v3->getr1_y() < 520))
				{
					random1 = 1; change1 = true;
				}
				else if (random1 == 1 && v3->getr1_x() > 250 && v3->getr1_x() < 290 && (v3->getr1_y() > 300 && v3->getr1_y() < 500))
				{
					random1 = 0; change1 = true;
				}
				else if (random1 == 0 && v3->getr1_x() > 110 && v3->getr1_x() < 120 && (v3->getr1_y() > 300 && v3->getr1_y() < 500))
				{
					random1 = 1; change1 = true;
				}
			}
			if (mode1 == 2)
			{
				if (random2 == 2 && v4->getr1_x() > 470 && v4->getr1_x() < 540 && (v4->getr1_y() > 130 && v4->getr1_y() < 170))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 470 && v4->getr1_x() < 540 && (v4->getr1_y() > 270 && v4->getr1_y() < 310))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 270 && v4->getr1_x() < 390 && (v4->getr1_y() > 330 && v4->getr1_y() < 360))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 270 && v4->getr1_x() < 390 && (v4->getr1_y() > 430 && v4->getr1_y() < 470))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 460 && v4->getr1_x() < 560 && (v4->getr1_y() > 450 && v4->getr1_y() < 490))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 460 && v4->getr1_x() < 560 && (v4->getr1_y() > 590 && v4->getr1_y() < 630))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 620 && v4->getr1_x() < 735 && (v4->getr1_y() > 330 && v4->getr1_y() < 370))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 620 && v4->getr1_x() < 735 && (v4->getr1_y() > 420 && v4->getr1_y() < 470))
				{
					random2 = 2;
					change2 = true;
				}
				else if (v4->getr1_x() > 910 && v4->getr1_x() < 940 && random2 == 0)
				{
					random2 = 1;
					change2 = true;
				}
				else if (v4->getr1_x() > 50 && v4->getr1_x() < 60 && random2 == 1)
				{
					random2 = 0;
					change2 = true;
				}
				else if (v4->getr1_y() > 40 && v4->getr1_y() < 65 && random2 == 3)
				{
					random2 = 2;
					change2 = true;
				}
				else if (v4->getr1_y() > 670 && v4->getr1_y() < 690 && random2 == 2)
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 500 && v4->getr1_x() < 560 && (v4->getr1_y() > 170 && v4->getr1_y() < 280))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 420 && v4->getr1_x() < 500 && (v4->getr1_y() > 170 && v4->getr1_y() < 280))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 350 && v4->getr1_x() < 400 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 220 && v4->getr1_x() < 250 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 520 && v4->getr1_x() < 580 && (v4->getr1_y() > 490 && v4->getr1_y() < 600))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 420 && v4->getr1_x() < 450 && (v4->getr1_y() > 490 && v4->getr1_y() < 600))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 700 && v4->getr1_x() < 755 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 570 && v4->getr1_x() < 600 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 770 && v4->getr1_x() < 860 && (v4->getr1_y() > 265 && v4->getr1_y() < 300))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 770 && v4->getr1_x() < 860 && (v4->getr1_y() > 500 && v4->getr1_y() < 530))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 120 && v4->getr1_x() < 210 && (v4->getr1_y() > 265 && v4->getr1_y() < 300))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 120 && v4->getr1_x() < 210 && (v4->getr1_y() > 500 && v4->getr1_y() < 550))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 810 && v4->getr1_x() < 880 && (v4->getr1_y() > 295 && v4->getr1_y() < 520))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 730 && v4->getr1_x() < 770 && (v4->getr1_y() > 295 && v4->getr1_y() < 520))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 160 && v4->getr1_x() < 250 && (v4->getr1_y() > 300 && v4->getr1_y() < 500))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 90 && v4->getr1_x() < 120 && (v4->getr1_y() > 300 && v4->getr1_y() < 500))
				{
					random2 = 1;
					change2 = true;
				}
			}
			else if (mode1 == 1)
			{
				if (random2 == 2 && v4->getr1_x() > 470 && v4->getr1_x() < 540 && (v4->getr1_y() > 170 && v4->getr1_y() < 200))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 470 && v4->getr1_x() < 540 && (v4->getr1_y() > 260 && v4->getr1_y() < 280))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 270 && v4->getr1_x() < 390 && (v4->getr1_y() > 330 + 30 && v4->getr1_y() < 360))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 270 && v4->getr1_x() < 390 && (v4->getr1_y() > 430 - 20 && v4->getr1_y() < 470 - 40))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 460 && v4->getr1_x() < 560 && (v4->getr1_y() > 450 + 30 && v4->getr1_y() < 490 + 20))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 460 && v4->getr1_x() < 560 && (v4->getr1_y() > 590 - 20 && v4->getr1_y() < 630 - 40))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 620 && v4->getr1_x() < 735 && (v4->getr1_y() > 330 + 30 && v4->getr1_y() < 390))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 620 && v4->getr1_x() < 735 && (v4->getr1_y() > 420 - 20 && v4->getr1_y() < 470 - 40))
				{
					random2 = 2;
					change2 = true;
				}
				else if (v4->getr1_x() > 940 && v4->getr1_x() < 1000 && random2 == 0)
				{
					random2 = 1;
					change2 = true;
				}
				else if (v4->getr1_x() > 0 && v4->getr1_x() < 20 && random2 == 1)
				{
					random2 = 0;
					change2 = true;
				}
				else if (v4->getr1_y() > 10 && v4->getr1_y() < 30 && random2 == 3)
				{
					random2 = 2;
					change2 = true;
				}
				else if (v4->getr1_y() > 690 && v4->getr1_y() < 720 && random2 == 2)
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 500 && v4->getr1_x() < 560 - 40 && (v4->getr1_y() > 170 && v4->getr1_y() < 280))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 420 + 40 && v4->getr1_x() < 480 && (v4->getr1_y() > 170 && v4->getr1_y() < 280))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 350 - 40 && v4->getr1_x() < 400 - 40 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 220 + 40 && v4->getr1_x() < 250 + 40 && (v4->getr1_y() > 370 + 40 && v4->getr1_y() < 440))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 520 - 40 && v4->getr1_x() < 580 - 40 && (v4->getr1_y() > 490 && v4->getr1_y() < 600))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 420 + 40 && v4->getr1_x() < 450 + 40 && (v4->getr1_y() > 490 && v4->getr1_y() < 600))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 700 - 40 && v4->getr1_x() < 755 - 40 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 570 + 40 && v4->getr1_x() < 600 + 40 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 1;
					change2 = true;
				}

				else if (random2 == 2 && v4->getr1_x() > 770 && v4->getr1_x() < 850 && (v4->getr1_y() > 295 && v4->getr1_y() < 330))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 770 && v4->getr1_x() < 850 && (v4->getr1_y() > 470 && v4->getr1_y() < 500))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 120 && v4->getr1_x() < 210 && (v4->getr1_y() > 295 && v4->getr1_y() < 320))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 120 && v4->getr1_x() < 210 && (v4->getr1_y() > 420 && v4->getr1_y() < 480))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 785 && v4->getr1_x() < 850 && (v4->getr1_y() > 295 && v4->getr1_y() < 520))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 750 && v4->getr1_x() < 800 && (v4->getr1_y() > 295 && v4->getr1_y() < 520))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 160 && v4->getr1_x() < 210 && (v4->getr1_y() > 300 && v4->getr1_y() < 500))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 120 && v4->getr1_x() < 150 && (v4->getr1_y() > 300 && v4->getr1_y() < 500))
				{
					random2 = 1;
					change2 = true;
				}
			}
			else if (mode1 == 0)
			{
				if (random2 == 2 && v4->getr1_x() > 470 && v4->getr1_x() < 540 && (v4->getr1_y() > 150 && v4->getr1_y() < 170))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 470 && v4->getr1_x() < 540 && (v4->getr1_y() > 200 && v4->getr1_y() < 340))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 270 && v4->getr1_x() < 390 && (v4->getr1_y() > 350 && v4->getr1_y() < 370))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 270 && v4->getr1_x() < 390 && (v4->getr1_y() > 480 && v4->getr1_y() < 510))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 460 && v4->getr1_x() < 560 && (v4->getr1_y() > 470 && v4->getr1_y() < 500))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 460 && v4->getr1_x() < 560 && (v4->getr1_y() > 640 && v4->getr1_y() < 670))
				{
					random2 = 2;
					change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 620 && v4->getr1_x() < 735 && (v4->getr1_y() > 350 && v4->getr1_y() < 380))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 620 && v4->getr1_x() < 735 && (v4->getr1_y() > 480 && v4->getr1_y() < 510))
				{
					random2 = 2;
					change2 = true;
				}
				else if (v4->getr1_x() > 930 && v4->getr1_x() < 960 && random2 == 0)
				{
					random2 = 1;
					change2 = true;
				}
				else if (v4->getr1_x() > 50 && v4->getr1_x() < 100 && random2 == 1)
				{
					random2 = 0;
					change2 = true;
				}
				else if (v4->getr1_y() > 40 && v4->getr1_y() < 105 && random2 == 3)
				{
					random2 = 2;
					change2 = true;
				}
				else if (v4->getr1_y() > 690 && v4->getr1_y() < 720 && random2 == 2)
				{
					random2 = 3; change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 560 && v4->getr1_x() < 600 && (v4->getr1_y() > 170 && v4->getr1_y() < 280))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 440 && v4->getr1_x() < 500 && (v4->getr1_y() > 170 && v4->getr1_y() < 280))
				{
					random2 = 1;
					change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 400 && v4->getr1_x() < 440 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 240 && v4->getr1_x() < 270 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 1; change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 580 && v4->getr1_x() < 620 && (v4->getr1_y() > 490 && v4->getr1_y() < 600))
				{
					random2 = 0; change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 440 && v4->getr1_x() < 470 && (v4->getr1_y() > 490 && v4->getr1_y() < 600))
				{
					random2 = 1; change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 750 && v4->getr1_x() < 795 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 0; change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 590 && v4->getr1_x() < 630 && (v4->getr1_y() > 370 && v4->getr1_y() < 440))
				{
					random2 = 1; change2 = true;
				}

				else if (random2 == 2 && v4->getr1_x() > 770 && v4->getr1_x() < 860 && (v4->getr1_y() > 285 && v4->getr1_y() < 310))
				{
					random2 = 3;
					change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 770 && v4->getr1_x() < 860 && (v4->getr1_y() > 550 && v4->getr1_y() < 580))
				{
					random2 = 2; change2 = true;
				}
				else if (random2 == 2 && v4->getr1_x() > 120 && v4->getr1_x() < 210 && (v4->getr1_y() > 280 && v4->getr1_y() < 310))
				{
					random2 = 3; change2 = true;
				}
				else if (random2 == 3 && v4->getr1_x() > 120 && v4->getr1_x() < 210 && (v4->getr1_y() > 550 && v4->getr1_y() < 560))
				{
					random2 = 2; change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 880 && v4->getr1_x() < 920 && (v4->getr1_y() > 295 && v4->getr1_y() < 520))
				{
					random2 = 0;
					change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 750 && v4->getr1_x() < 770 && (v4->getr1_y() > 295 && v4->getr1_y() < 520))
				{
					random2 = 1; change2 = true;
				}
				else if (random2 == 1 && v4->getr1_x() > 250 && v4->getr1_x() < 290 && (v4->getr1_y() > 300 && v4->getr1_y() < 500))
				{
					random2 = 0; change2 = true;
				}
				else if (random2 == 0 && v4->getr1_x() > 110 && v4->getr1_x() < 120 && (v4->getr1_y() > 300 && v4->getr1_y() < 500))
				{
					random2 = 1; change2 = true;
				}
			}
		}














		mapControl();
		if (type == 1)
		{
			fstream myfile;
			myfile.open("../" + name + ".txt", ios::out);
			myfile << 3 << endl;
			myfile << score1 << endl;
			myfile << score2 << endl;
			myfile << medium1 << endl;
			myfile << large1 << endl;
			myfile.close();
		}
		if (type == 1 && (score1 >= 10 || score2 >= 10))
		{
			fstream myfile;
			myfile.open("../" + name + ".txt", ios::out);
			myfile.close();
			if (score2 >= 10)
			{
				int var= score1+20;
				fstream myfile;
				myfile.open("Score.txt", ios::app);
				myfile << name << endl;
				myfile << var << endl;
				myfile.close();
				glutDisplayFunc(botwin);
				myfile.close();
			}
			if (score1 >= 10)
			{
				score1 = 30;
				fstream myfile;
				myfile.open("Score.txt", ios::app);
				myfile << name << endl;
				myfile << score1 << endl;
				myfile.close();
				glutDisplayFunc(youwin);
			}
		}
		glutKeyboardFunc(map3control);
		glutSwapBuffers();
	}
	// map 1 control
	static void map1control(unsigned char , int , int );
	//map 2 control
	static void mapControl();
	static void map2control(unsigned char , int , int );
	static void map3control(unsigned char , int , int );
};
//Initilize variable
string Map::a="";
string Map::b="";
string Map::c="";
string Map::d="";
string Map::e="";
string Map::f="";
string Map::g="";
string Map::h="";
int Map::timechekker = 5;
int Map::ii = 1;
int Map::jj = 1;
int Map::kk = 1;
int Map::ll = 1;
int Map::aa = 1;
bool Map::player1 = true;
int Map::bb = 1;
int Map::help1 = 0;
int Map::help2 = -1;
int Map::cc = 1;
int Map::dd = 1;
bool Map::change = false;
int Map::type = 0;
int Map::bouncecount = 0;
int Map::score1 = 0;
int Map::score2 = 0;
bool Map::screen = false;
string Map::i="";
string Map::j="";
bool Map::large1opener = false;
bool Map::medium1opener = false;
bool Map::large2opener = false;
bool Map::medium2opener = false;
int  Map::large1	  = 2;
int  Map::medium1  = 4;
int  Map::small1	  = 0;
int  Map::large2	  = 2;
int Map::firecheck1 = 2;
int Map::firecheck2 = 2;
int  Map::medium2  = 4;
int  Map::small2   = 0;
int  Map::mode1 = 0;
int  Map::random = -1;
int Map::random1=-1;
int Map::random2=-1;
int Map::change1=false;
int Map::change2=false;
string Map::k="";
string Map::l="";
string Map::m="";
string Map::n = "";
Vehicle* Map::v1 = NULL;
Vehicle* Map::v2 = NULL;
Vehicle* Map::v3 = NULL;
Vehicle* Map::v4 = NULL;

void Map::map1control(unsigned char key, int x, int y) {

	function(key);
	glutPostRedisplay();
}
void Map::map2control(unsigned char key, int x, int y) {
	function(key);
	glutPostRedisplay();
}
void Map::map3control(unsigned char key, int x, int y) {
	function(key);
	glutPostRedisplay();
}
void Map::function(unsigned char key)
{
	if (key >= 97 && key <= 122)
	{
		key -= 32;
	}
	if (key == d[0])
	{

		ii = 10;
		jj = 0;
		ll = 0;
		kk = 0;
	}
	if (key == a[0])
	{
		jj = 20;
		ii = 0;
		kk = 0;
		ll = 0;
	}
	if (key == b[0])
	{
		kk = 30;
		ii = 0; jj = 0;
		ll = 0;
	}
	if (key == c[0])
	{
		ll = 40;
		jj = 0;
		kk = 0;
		ii = 0;
	}
	if (key == i[0])
	{
		small1 = 0;
		medium1opener = false;
		large1opener=false;
		if (ii == 1)
		{
			ii = 2;
			fire = true; firecheck1 = 0;
		}
		else if (jj == 2)
		{
			jj = 3;
			fire = true; firecheck1 = 0;
		}
		else if (kk == 3)
		{
			kk = 4;
			fire = true; firecheck1 = 0;
		}
		else if (ll == 4)
		{
			ll = 5;
			fire = true; firecheck1 = 0;
		}
	}
	
	if (key == j[0])
	{
		small1 = 1;
		medium1opener = true;
		large1opener = false;
		medium1 -= 1;
		if (ii == 1)
		{
			ii = 2;
			fire = true; firecheck1 = 0;
		}
		else if (jj == 2)
		{
			jj = 3;
			fire = true; firecheck1 = 0;
		}
		else if (kk == 3)
		{
			kk = 4;
			fire = true; firecheck1 = 0;
		}
		else if (ll == 4)
		{
			ll = 5;
			fire = true; firecheck1 = 0;
		}
	}
	if (key == 'B')
	{
		if (boost1 == 1)
		{
			boost1control = true;
		}
	}
	if (key == k[0])
	{
		small1 = 1;
		medium1opener = false;
		large1opener = true;
		large1 -= 1;
		if (ii == 1)
		{
			ii = 2;
			fire = true; firecheck1 = 0;
		}
		else if (jj == 2)
		{
			jj = 3;
			fire = true; firecheck1 = 0;
		}
		else if (kk == 3)
		{
			kk = 4;
			fire = true; firecheck1 = 0;
		}
		else if (ll == 4)
		{
			ll = 5;
			fire = true; firecheck1 = 0;
		}
	}
	if (type == 2)
	{
		if (key == h[0])
		{

			aa = 10;
			bb = 0;
			cc = 0;
			dd = 0;
		}
		if (key == e[0])
		{
			bb = 20;
			aa = 0;
			cc = 0;
			dd = 0;
		}
		if (key == f[0])
		{
			cc = 30;
			aa = 0;
			bb = 0;
			dd = 0;
		}
		if (key == g[0])
		{
			dd = 40;
			bb = 0;
			cc = 0;
			aa = 0;
		}
		if (key == 'X')
		{
			if (boost2 == 1)
			{
				boost2control = true;
			}
		}
		if (key == l[0])
		{
			small2 = 0;
			if (aa == 1)
			{
				aa = 2;
				fire1 = true; firecheck2 = 0;
			}
			else if (bb == 2)
			{
				bb = 3;
				fire1 = true; firecheck2 = 0;
			}
			else if (cc == 3)
			{
				cc = 4;
				fire1 = true; firecheck2 = 0;
			}
			else if (dd == 4)
			{
				dd = 5;
				fire1 = true; firecheck2 = 0;
			}
		}
		if (key == m[0])
		{
			small2 = 1;
			medium2opener = true;
			large2opener = false;
			medium2 -= 1;
			if (aa == 1)
			{
				aa = 2;
				fire1 = true; firecheck2 = 0;
			}
			else if (bb == 2)
			{
				bb = 3;
				fire1 = true; firecheck2 = 0;
			}
			else if (cc == 3)
			{
				cc = 4;
				fire1 = true; firecheck2 = 0;
			}
			else if (dd == 4)
			{
				dd = 5;
				fire1 = true; firecheck2 = 0;
			}
		}
		if (key == n[0])
		{
			small2 = 1;
			medium2opener = false;
			large2opener = true;
			large2 -= 1;
			if (aa == 1)
			{
				aa = 2;
				fire1 = true; firecheck2 = 0;
			}
			else if (bb == 2)
			{
				bb = 3;
				fire1 = true; firecheck2 = 0;
			}
			else if (cc == 3)
			{
				cc = 4;
				fire1 = true; firecheck2 = 0;
			}
			else if (dd == 4)
			{
				dd = 5;
				fire1 = true; firecheck2 = 0;
			}
		}
	}

}
void Map::mapControl()
{

	DrawString(40, 780, "Small = Unlimited", colors[BLACK]);
	string s;
	if (medium1 < 1)
	{
		s = to_string(0);
	}
	else
	{
		s = to_string(medium1 - 1);
	}
	DrawString(250, 780, "Medium = " + s, colors[BLACK]);
	if (large1 < 1)
	{
		s = to_string(0);
	}
	else
	{
		s = to_string(large1 - 1);
	}
	DrawString(400, 780, "Large = " + s, colors[BLACK]);
	if (medium2 < 1)
	{
		s = to_string(0);
	}
	else
	{
		s = to_string(medium2 - 1);
	}
	DrawString(750, 780, "Medium = " + s, colors[BLACK]);
	if (large2 < 1)
	{
		s = to_string(0);
	}
	else
	{
		s = to_string(large2 - 1);
	}
	DrawString(900, 780, "Large = " + s, colors[BLACK]);
	s = to_string(timechekker);
	DrawString(420, 800, "Time Boost : " + s, colors[BLACK]);
	DrawString(550, 780, "Small = Unlimited", colors[BLACK]);
	if (screen2 == false && type==1 )
	{
		v3->changecenter(10000, 10000);
	}
	if (screen3 == false && type==1)
	{
		v4->changecenter(100000, 100000);
	}
	if (type == 2)
	{
		if (ii == 10 || ii == 1 || ii == 2)
		{
			v1->top(ii);
			if (ii == 2)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLACK]);
			}
			if (fire == true && centery < 700)
			{
				if (small1 == 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centery += 10;
					}
					else if (screen2 == true)
					{
						centery += 5;
					}
					else
					{
						centery += 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if ((centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20) )
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centery += 15;
					}
					else if (screen2 == true)
					{
						centery += 10;
					}
					else
					{
						centery += 5;
					}
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20)
					{
						if (boost1control == true)
						{
							score1 += 5;
						}
						score1++;
						score1++;
						score1++;
						fire = false; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centery += 20;
					}
					else if (screen2 == true)
					{
						centery += 15;
					}
					else
					{
						centery += 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20)
					{
						score1++;
						score1++;
						score1++;
						score1++;
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false; centery = 10000;
					}
				}


			}
			else
			{
				fire = false;
			}
			ii = 1;
		}
		else if (jj == 20 || jj == 2 || jj == 3)
		{
			v1->left(jj);
			if (jj == 3)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLACK]);

			}
			if (fire == true || centerx > 0)
			{
				if (small1 == 0)
				{
					
					if (screen3 == true || boost1control==true)
					{
						centerx -= 10;
					}
					else if (screen2 == true)
					{
						centerx -= 6;
					}
					else
					{
						centerx -= 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 )
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centerx -= 15;
					}
					else if (screen2 == true)
					{
						centerx -= 10;
					}
					else
					{
						centerx -= 5;
					}
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20)
					{
						score1 += 3;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centerx -= 20;
					}
					else if (screen2 == true)
					{
						centerx -= 15;
					}
					else
					{
						centerx -= 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 )					{
						score1 += 5;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}

			}
			else
			{
				fire = false;
			}
			jj = 2;
		}
		else if (kk == 30 || kk == 3 || kk == 4)
		{
			v1->bottom(kk);
			if (kk == 4)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLACK]);

			}
			if (fire == true && centery > 0)
			{
				if (small1 == 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centery -= 10;
					}
					else if (screen2 == true)
					{
						centery -= 6;
					}
					else
					{
						centery -= 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20)
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
				  if (screen3 == true || boost1control==true)
					{
						centery -= 15;
					}
					else if (screen2 == true)
					{
						centery -= 10;
					}
					else
					{
						centery -= 5;
					}
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 )
					{
						score1 += 3;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centery -= 20;
					}
					else if (screen2 == true)
					{
						centery -= 15;
					}
					else
					{
						centery -= 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 )
					{
						score1 += 5;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
			}
			else
			{
				fire = false;
			}
			kk = 3;
		}
		else if (ll == 40 || ll == 4 || ll == 5)
		{

			if (ll == 5)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLUE]);

			}
			if (fire == true && centerx < 1020)
			{
				if (small1 == 0)
				{
					if (screen3 == true  || boost1control==true)
					{
						centerx += 10;
					}
					else if (screen2 == true)
					{
						centerx += 6;
					}
					else
					{
						centerx += 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 )
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centerx += 15;
					}
					else if (screen2 == true)
					{
						centerx += 10;
					}
					else
					{
						centerx += 5;
					}
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 )
					{
						score1 += 3;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centerx += 20;
					}
					else if (screen2 == true)
					{
						centerx += 15;
					}
					else
					{
						centerx += 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 )
					{
						score1 += 5;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
			}
			else
			{
				fire = false;
			}
			v1->right(ll);
			ll = 4;
		}
		if (aa == 10 || aa == 1 || aa == 2)
		{
			v2->top(aa);
			if (aa == 2)
			{
				centerx1 = v2->getcenterx();
				centery1 = v2->getcentery();
				DrawCircle(centerx1, centery1, 5, colors[BLACK]);
			}
			if (fire1 == true && centery1 < 700)
			{
				if (small2 == 0)
				{
					centery1 += 2;
					if (boost2control == true)
					{
						centery1 += 3;
					}
					DrawCircle(centerx1, centery1, 5, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2++;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}

				}
				if (medium2opener == true && medium2 > 0)
				{
					centery1 += 5;
					if (boost2control == true)
					{
						centery1 += 5;
					}
					DrawCircle(centerx1, centery1, 7, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2+=3;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}

				}
				if (large2opener == true && large2 > 0)
				{
					centery1 += 10;
					if (boost2control == true)
					{
						centery1 += 5;
					}
					DrawCircle(centerx1, centery1, 10 ,colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2 += 5;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}

				}
			}
			else
			{
				fire1 = false;
			}

			aa = 1;
		}
		else if (bb == 20 || bb == 2 || bb == 3)
		{
			v2->left(bb);
			if (bb == 3)
			{
				centerx1 = v2->getcenterx();
				centery1 = v2->getcentery();
				DrawCircle(centerx1, centery1, 5, colors[BLACK]);

			}
			if (fire1 == true || centerx1 > 0)
			{

				if (small2 == 0)
				{
					centerx1 -= 2;
					if (boost2control == true)
					{
						centerx1 -= 3;
					}
					DrawCircle(centerx1, centery1, 5, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2++;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
				if (medium2opener == true && medium2 > 0)
				{
					centerx1 -= 5;
					if (boost2control == true)
					{
						centerx1 -= 5;
					}
					DrawCircle(centerx1, centery1, 7, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2 += 3;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
				if (large2opener == true && large2 > 0)
				{
					centerx1 -= 10;
					if (boost2control == true)
					{
						centerx1 -= 5;
					}
					DrawCircle(centerx1, centery1, 10, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2 += 5;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
			}
			else
			{
				fire1 = false;
			}
			bb = 2;
		}
		else if (cc == 30 || cc == 3 || cc == 4)
		{
			v2->bottom(cc);

			if (cc == 4)
			{
				centerx1 = v2->getcenterx();
				centery1 = v2->getcentery();
				DrawCircle(centerx1, centery1, 5, colors[BLACK]);

			}
			if (fire1 == true && centery1 > 0)
			{
				
				if (small2 == 0)
				{
					centery1 -= 2;
					if (boost2control == true)
					{
						centery1 -= 3;
					}
					DrawCircle(centerx1, centery1, 5, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2++;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
				if (medium2opener == true && medium2 > 0)
				{
					centery1 -= 5;
					if (boost2control == true)
					{
						centery1 -= 5;
					}
					DrawCircle(centerx1, centery1, 7, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2 += 3;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
				if (large2opener == true && large2 > 0)
				{
					centery1 -= 10;
					if (boost2control == true)
					{
						centery1 -= 5;
					}
					DrawCircle(centerx1, centery1, 10, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2 += 5;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
			}
			else
			{
				fire1 = false;
			}
			cc = 3;
		}
		else if (dd == 40 || dd == 4 || dd == 5)
		{

			if (dd == 5)
			{
				centerx1 = v2->getcenterx();
				centery1 = v2->getcentery();
				DrawCircle(centerx1, centery1, 5, colors[BLACK]);

			}
			if (fire1 == true && centerx1 < 1020)
			{
				if (small2 == 0)
				{
					centerx1 += 2;
					if (boost2control == true)
					{
						centerx1 += 3;
					}
					DrawCircle(centerx1, centery1, 5, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2++;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
				if (medium2opener == true && medium2 > 0)
				{
					centerx1 += 5;
					if (boost2control == true)
					{
						centerx1 += 5;
					}
					DrawCircle(centerx1, centery1, 7, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2 += 3;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}
				if (large2opener == true && large2 > 0)
				{
					centerx1 += 10;
					if (boost2control == true)
					{
						centerx1 += 5;
					}
					DrawCircle(centerx1, centery1, 10, colors[BLACK]);
					if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
					{
						score2 += 5;
						if (boost2control == true)
						{
							score2 += 5;
						}
						fire1 = false;
						centerx1 = 10000; centery1 = 10000;
					}
				}

			}
			else
			{
				fire1 = false;
			}
			v2->right(dd);
			dd = 4;
		}
	}
	if (type == 1)
	{
		if (ii == 10 || ii == 1 || ii == 2)
		{
			v1->top(ii);
			if (ii == 2)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLACK]);
			}
			if (fire == true && centery < 700)
			{
				if (small1 == 0)
				{
					if (screen3 == true || boost1control==true)
					{
						centery += 10;
					}
					else if (screen2 == true)
					{
						centery += 6;
					}
					else
					{
						centery += 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if ((centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20) || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centery += 15;
					}
					else if (screen2 == true)
					{
						centery += 10;
					}
					else
					{
						centery += 5;
					}
					
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1++;
						score1++;
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centery += 20;
					}
					else if (screen2 == true)
					{
						centery += 15;
					}
					else
					{
						centery += 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1++;
						score1++;
						score1++;
						score1++;
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false; centery = 10000;
					}
				}


			}
			else
			{
				fire = false;
			}
			ii = 1;
		}
		else if (jj == 20 || jj == 2 || jj == 3)
		{
			v1->left(jj);
			if (jj == 3)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLACK]);

			}
			if (fire == true || centerx > 0)
			{
				if (small1 == 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centerx -= 10;
					}
					else if (screen2 == true)
					{
						centerx -= 6;
					}
					else
					{
						centerx -= 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centerx -= 15;
					}
					else if (screen2 == true)
					{
						centerx -= 10;
					}
					else
					{
						centerx -= 5;
					}
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1 += 3;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centerx -= 20;
					}
					else if (screen2 == true)
					{
						centerx -= 15;
					}
					else
					{
						centerx -= 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1 += 5;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}

			}
			else
			{
				fire = false;
			}
			jj = 2;
		}
		else if (kk == 30 || kk == 3 || kk == 4)
		{
			v1->bottom(kk);
			if (kk == 4)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLACK]);

			}
			if (fire == true && centery > 0)
			{
				if (small1 == 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centery -= 10;
					}
					else if (screen2 == true)
					{
						centery -= 6;
					}
					else
					{
						centery -= 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centery -= 15;
					}
					else if (screen2 == true)
					{
						centery -= 10;
					}
					else
					{
						centery -= 5;
					}
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1 += 3;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centery -= 20;
					}
					else if (screen2 == true)
					{
						centery -= 15;
					}
					else
					{
						centery -= 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1 += 5;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
			}
			else
			{
				fire = false;
			}
			kk = 3;
		}
		else if (ll == 40 || ll == 4 || ll == 5)
		{

			if (ll == 5)
			{
				centerx = v1->getcenterx();
				centery = v1->getcentery();
				DrawCircle(centerx, centery, 5, colors[BLUE]);

			}
			if (fire == true && centerx < 1020)
			{
				if (small1 == 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centerx += 10;
					}
					else if (screen2 == true)
					{
						centerx += 6;
					}
					else
					{
						centerx += 3;
					}
					DrawCircle(centerx, centery, 5, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1++;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (medium1opener == true && medium1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centerx += 15;
					}
					else if (screen2 == true)
					{
						centerx += 10;
					}
					else
					{
						centerx += 5;
					}
					DrawCircle(centerx, centery, 7, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1 += 3;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
				if (large1opener == true && large1 > 0)
				{
					if (screen3 == true || boost1control == true)
					{
						centerx += 20;
					}
					else if (screen2 == true)
					{
						centerx += 15;
					}
					else
					{
						centerx += 10;
					}
					DrawCircle(centerx, centery, 10, colors[BLACK]);
					if (centerx >= v2->getcenterx() - 20 && centerx <= v2->getcenterx() + 20 && centery >= v2->getcentery() - 20 && centery <= v2->getcentery() + 20 || (centerx >= v3->getcenterx() - 20 && centerx <= v3->getcenterx() + 20 && centery >= v3->getcentery() - 20 && centery <= v3->getcentery() + 20) || (centerx >= v4->getcenterx() - 20 && centerx <= v4->getcenterx() + 20 && centery >= v4->getcentery() - 20 && centery <= v4->getcentery() + 20))
					{
						score1 += 5;
						if (boost1control == true)
						{
							score1 += 5;
						}
						fire = false;
						centerx = 10000; centery = 10000;
					}
				}
			}
			else
			{
				fire = false;
			}
			v1->right(ll);
			ll = 4;
		}
		if (screen1 = true)
		{
			if (random == 0)
			{
				v2->right(80);
				if (v2->getcenterx() > 980)
				{
					v2->changecenter(30, v2->getcentery());
				}
			}
			else if (random == 1)
			{
				v2->left(60);
				if (v2->getcenterx() < 30)
				{
					v2->changecenter(990, v2->getcentery());
				}
			}
			else if (random == 2)
			{
				v2->top(50);
				if (v2->getcentery() > 750)
				{
					v2->changecenter(v2->getcenterx(), 30);
				}

			}
			else if (random == 3)
			{
				v2->bottom(70);
				if (v2->getcentery() < 30)
				{
					v2->changecenter(v2->getcenterx(), 750);
				}
			}
			if (change == true)
			{
				centerx1 = v2->getcenterx();
				centery1 = v2->getcentery();
			}
			if (random == 0)
			{
				DrawCircle(centerx1, centery1, 10, colors[BLACK]);
				if (screen3 == true)
				{
					centerx1 += 30;
				}
			    else
				centerx1 += 7;
			}
			else if (random == 1)
			{
				DrawCircle(centerx1, centery1, 10, colors[BLACK]);
				if (screen3 == true)
				{
					centerx1 -= 30;
				}
				else 
				centerx1 -= 7;
			}
			else if (random == 2)
			{
				DrawCircle(centerx1, centery1, 10, colors[BLACK]);
				if (screen3 == true)
				{
					centery1 += 30;
				}
				else
				{
					centery1 += 7;
				}
			}
			else if (random == 3)
			{
				DrawCircle(centerx1, centery1, 10, colors[BLACK]);
				if (screen3 == true)
				{
					centery1 -= 30;
				}
				else
				{
					centery1 -= 7;
				}
				
			}
			if (centerx1 >= v1->getcenterx() - 20 && centerx1 <= v1->getcenterx() + 20 && centery1 >= v1->getcentery() - 20 && centery1 <= v1->getcentery() + 20)
			{
				score2++;
				centerx1 = 10000;
				centery1 = 10000;

			}
			change = false;
		}
		if (screen2 == true)
		{
			if (random1 == 0)
			{
				v3->right(120);
				if (v3->getcenterx() > 980)
				{
					v3->changecenter(30, v3->getcentery());
				}
			}
			else if (random1 == 1)
			{
				v3->left(100);
				if (v3->getcenterx() < 30)
				{
					v3->changecenter(990, v3->getcentery());
				}
			}
			else if (random1 == 2)
			{
				v3->top(90);
				if (v3->getcentery() > 750)
				{
					v3->changecenter(v3->getcenterx(), 30);
				}

			}
			else if (random1 == 3)
			{
				v3->bottom(110);
				if (v3->getcentery() < 30)
				{
					v3->changecenter(v3->getcenterx(), 750);
				}
			}
			if (change1 == true)
			{
				centerx2 = v3->getcenterx();
				centery2 = v3->getcentery();
			}
			if (random1 == 0)
			{
				DrawCircle(centerx2, centery2, 10, colors[BLACK]);
				
				if (screen3 == true)
				{
					centerx2 += 30;
				}
				else
				{
					centerx2 += 7;
				}
			}
			else if (random1 == 1)
			{
				DrawCircle(centerx2, centery2, 10, colors[BLACK]);
				if (screen3 == true)
				{
					centerx2 -= 30;
				}
				else
				{
					centerx2 -= 7;
				}
				
			}
			else if (random1 == 2)
			{
				DrawCircle(centerx2, centery2, 10, colors[BLACK]);
				if (screen3 == true)
				{
					centery2 += 30;
				}
				else
				{
					centery2 += 7;
				}
			}
			else if (random == 3)
			{
				DrawCircle(centerx2, centery2, 10, colors[BLACK]);
				if (screen3 == true)
				{
					centery2 -= 30;
				}
				else
				{
					centery2 -= 7;
				}
			}
			if (centerx2 >= v1->getcenterx() - 20 && centerx2 <= v1->getcenterx() + 20 && centery2 >= v1->getcentery() - 20 && centery2 <= v1->getcentery() + 20)
			{
				score2++;
				centerx2 = 10000;
				centery2 = 10000;

			}
			change1 = false;
		}

		if (screen3 == true)
		{
			if (random2 == 0)
			{
				v4->right(160);
				if (v4->getcenterx() > 980)
				{
					v4->changecenter(30, v4->getcentery());
				}
			}
			else if (random2 == 1)
			{
				v4->left(140);
				if (v4->getcenterx() < 30)
				{
					v4->changecenter(990, v4->getcentery());
				}
			}
			else if (random2 == 2)
			{
				v4->top(130);
				if (v4->getcentery() > 750)
				{
					v4->changecenter(v4->getcenterx(), 30);
				}

			}
			else if (random2 == 3)
			{
				v4->bottom(150);
				if (v4->getcentery() < 30)
				{
					v4->changecenter(v4->getcenterx(), 750);
				}
			}
			if (change2 == true)
			{
				centerx3 = v4->getcenterx();
				centery3 = v4->getcentery();
			}
			if (random2 == 0)
			{
				DrawCircle(centerx3, centery3, 10, colors[BLACK]);
				centerx3 += 30;
			}
			else if (random2 == 1)
			{
				DrawCircle(centerx3, centery3, 10, colors[BLACK]);
				centerx3 -= 30;
			}
			else if (random2 == 2)
			{
				DrawCircle(centerx3, centery3, 10, colors[BLACK]);
				centery3 += 30;
			}
			else if (random2 == 3)
			{
				DrawCircle(centerx3, centery3, 10, colors[BLACK]);
				centery3 -= 30;
			}
			if (centerx3 >= v1->getcenterx() - 20 && centerx3 <= v1->getcenterx() + 20 && centery3 >= v1->getcentery() - 20 && centery3 <= v1->getcentery() + 20)
			{
				score2++;
				centerx3 = 10000;
				centery3 = 10000;

			}
			change2 = false;
		}

	}
	DrawString(100, 800, "Player 1", colors[BLUE]);
	string score11 = "Score = " + to_string(score1);
	string score22 = "Score = " + to_string(score2);
	DrawString(600, 800, "Player 2", colors[BLUE]);
	DrawString(300, 800, score11, colors[BLUE]);
	DrawString(900, 800, score22, colors[BLUE]);
	if ((score1 >= 10 || score2 >= 10) && type == 2)
	{
		help2 = -1;
		if (score1 >= 10)
		{
			player1 = true;
		}
		if (score2 >= 10)
		{
			player1 = false;
		}
		glutDisplayFunc(rematch);
	}

}