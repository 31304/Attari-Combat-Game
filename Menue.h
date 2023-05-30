#pragma once
//This class is the main class with this class instace we run our program
#include "util.h"
#include "Vehicle.h"
#include "Player.h"
#include "Map.h"
#include "Setting.h"
#include <string>
#include <fstream>
// Constractor
class Menue {
private:
	static int xt; 
	static int yt;
	static int help1;
	static int modehelper1;
	static int modehelper2;
	static int controlhelper1;
	static int entervalue;
	static int firstrow;
	static int secondrow;
	static int thirdrow;
	static bool modeopen;
	static bool coloropen;
	static int controlhelper2;
	static char* arr1;
	static char* arr2;
	static char* arr3;
	static string a;
	static string b;
	static string c;
	static string d;
	static string e;
	static string f;
	static string g;
	static string h;
	static string i;
	static string j;
	static string k;
	static string email;
	static string l;
	static string m;
	static string n;
	static bool controlopen;
	static int help2;
	static bool s;
	static int timer_helper;
public:
	Menue()
	{
		arr1 = new char[17];
		arr2 = new char[17];
		arr3 = new char[17];
		glutDisplayFunc(starting);
		glutSpecialFunc(updown);
		glutKeyboardFunc(dataleftright);
		glutTimerFunc(1.0, timer, 0);
		glutPostRedisplay();
		int i = 0;
		while (i < 17)
		{
			arr1[i] = NULL;
			arr2[i] = NULL;
			arr3[i] = NULL;
			i++;
		}
	}
	static void arrow(int ,int ,int);
	static void updown(int, int, int);
	static void timer(int);
	static void menue();
	static void display();
	static void dataleftright(unsigned char, int, int);
	static void HighScore();
	static void starting();
	static void MouseControl(int,int,int,int);
	static void Setting();
	static void player1();
	static void Assci(unsigned char, int, int);
	static void player2();
	static void credit();
	static void mode();
	static void control();
	static void Color(int, int);
};
string Menue::a = "A";
char* Menue::arr1 = nullptr;
char* Menue::arr2 = nullptr;
char* Menue::arr3 = nullptr;
bool Menue::modeopen = false;
bool Menue::coloropen = false;
int Menue::entervalue = 0;
int Menue::firstrow = 0;
int Menue::secondrow = -1;
int Menue::thirdrow = -1;
string Menue::b = "B";
string Menue::c = "C";
string Menue::d = "D";
string Menue::e = "E";
string Menue::f = "F";
string Menue::g = "G";
string Menue::h = "H";
string Menue::i = "I";
string Menue:: email = "";
string Menue::j = "J";
string Menue::k = "K";
string Menue::l = "L";
string Menue::m = "M";
string Menue::n = "N";
int Menue::modehelper2 = 1;
int Menue::modehelper1 = 0;
int Menue::help1 = 0;
int Menue::controlhelper1 = 0;
int Menue::controlhelper2 = -1;
bool Menue::controlopen = false;
int Menue::help2 = -1;
int Menue::xt = 0;
bool Menue::s = false;
int Menue::yt = -1;
int Menue::timer_helper = 0;
//it is keyboard key controller
void Menue::arrow(int key, int x, int y) {
	if (entervalue == 3)
	{
		if (key == GLUT_KEY_LEFT)
		{
			if (s == false && controlopen == false)
			{
				yt = -1;
			}
			if (s == true)
			{
				if (help2 == -1)
				{
					yt = -1;
					help1 = 0;
					s = false;
					controlopen = false;
				}
				help2 = -1;
			}
			if (controlopen == true)
			{
				help2 = -1;
				s = true;
				controlopen = false;
			}
			if (modehelper2 == 1 && yt != -1)
			{
				s = true;
				modehelper1 = 0;
				modeopen = false;
			}
		}
		else if (key == GLUT_KEY_RIGHT)
		{
			if (s == true)
			{
				help2 = help1;
				if (help2 == 0)
				{
					controlopen = true;
					s = false;
				}
				if (help2 == 1)
				{
					modeopen = true;
					controlopen = false;
					s = false;
				}
			}
			if (s == false && controlopen == false)
			{
				yt = xt;
				if (yt == 1) {
					s = true;
				}
			}
		}
		else if (key == GLUT_KEY_UP)
		{
			if (s == false && controlopen == false)
			{
				xt--;
				if (xt < 0)
				{
					xt = 0;
				}
			}
			if (controlopen == true)
			{
				controlhelper1--;
				if (controlhelper1 < 0)
				{
					controlhelper1 = 0;
				}
			}
			if (s == true)
			{
				help1--;
				if (help1 < 0)
				{
					help1 = 0;
				}
			}
			if (modeopen == true)
			{
				modehelper1--;
				if (modehelper1 < 0)
				{
					modehelper1 = 0;
				}
			}
		}
		else if (key == GLUT_KEY_DOWN)
		{
			if (s == false && controlopen == false && modeopen == false)
			{
				xt++;
				if (xt > 4)
				{
					xt = 4;
				}
			}
			if (s == true)
			{
				help1++;
				if (help1 > 1)
				{
					help1 = 1;
				}
			}
			if (controlopen == true)
			{
				controlhelper1++;
				if (controlhelper1 > 2)
				{
					controlhelper1 = 2;
				}
			}
			if (modeopen == true)
			{
				modehelper1++;
				if (modehelper1 > 13)
				{
					modehelper1 = 13;
				}
			}
		}
	}
	glutPostRedisplay();
}
//it is my mode screen
void Menue::mode()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); 
	DrawTriangle(70, 800, 70, 770, 40, 785, colors[WHITE]);
	DrawString(200, 600, "Player 1", colors[RED]);
	DrawString(720, 600, "Player 2", colors[RED]);
	DrawRectangle(100, 300, 100, 70, colors[WHITE]);
	DrawRectangle(200, 300, 100, 70, colors[WHITE]);
	DrawRectangle(300, 300, 100, 70, colors[WHITE]);
	DrawRectangle(200, 370, 100, 70, colors[WHITE]);
	DrawRectangle(600, 300, 100, 70, colors[WHITE]);
	DrawRectangle(700, 300, 100, 70, colors[WHITE]);
	DrawRectangle(800, 300, 100, 70, colors[WHITE]);
	DrawRectangle(700, 370, 100, 70, colors[WHITE]);
	DrawRectangle(100, 100, 100, 70, colors[WHITE]);
	DrawRectangle(200, 100, 100, 70, colors[WHITE]);
	DrawRectangle(300, 100, 100, 70, colors[WHITE]);
	DrawRectangle(600, 100, 100, 70, colors[WHITE]);
	DrawRectangle(700, 100, 100, 70, colors[WHITE]);
	DrawRectangle(800, 100, 100, 70, colors[WHITE]);
	if (modehelper1 == 0)
	{
		DrawRectangle(200, 370, 100, 70, colors[RED]);
	}
	if (modehelper1 == 1)
	{
		DrawRectangle(100, 300, 100, 70, colors[RED]);
	}
	if (modehelper1 == 2)
	{
		DrawRectangle(200, 300, 100, 70, colors[RED]);
	}
	if (modehelper1 == 3)
	{
		DrawRectangle(300, 300, 100, 70, colors[RED]);
	}
	if (modehelper1 == 4)
	{
		DrawRectangle(600, 300, 100, 70, colors[RED]);
	}
	if (modehelper1 == 5)
	{
		DrawRectangle(700, 300, 100, 70, colors[RED]);
	}
	if (modehelper1 == 6)
	{
		DrawRectangle(800, 300, 100, 70, colors[RED]);
	}
	if (modehelper1 == 7)
	{
		DrawRectangle(700, 370, 100, 70, colors[RED]);
	}
	if (modehelper1 == 8)
	{
		DrawRectangle(100, 100, 100, 70, colors[RED]);

	}
	if (modehelper1 == 9)
	{
		DrawRectangle(200, 100, 100, 70, colors[RED]);
	}
	if (modehelper1 == 10)
	{
		DrawRectangle(300, 100, 100, 70, colors[RED]);
	}
	if (modehelper1 == 11)
	{
		DrawRectangle(600, 100, 100, 70, colors[RED]);
	}
	if (modehelper1 == 12)
	{
		DrawRectangle(700, 100, 100, 70, colors[RED]);
	}
	if (modehelper1 == 13)
	{
		DrawRectangle(800, 100, 100, 70, colors[RED]);
	}
	DrawString(130, 330, a, colors[BLACK]);
	DrawString(230, 330, b, colors[BLACK]);
	DrawString(330, 330, c, colors[BLACK]);
	DrawString(230, 400, d, colors[BLACK]);
	DrawString(630, 330, e, colors[BLACK]);
	DrawString(730, 330, f, colors[BLACK]);
	DrawString(830, 330, g, colors[BLACK]);
	DrawString(730, 400, h, colors[BLACK]);
	DrawString(200, 200, "Fire Type", colors[RED]);
	DrawString(700, 200, "Fire Type", colors[RED]);
	DrawString(130, 130, i, colors[BLACK]);
	DrawString(230, 130, j, colors[BLACK]);
	DrawString(330, 130, k, colors[BLACK]);
	DrawString(630, 130, l, colors[BLACK]);
	DrawString(730, 130, m, colors[BLACK]);
	DrawString(830, 130, n, colors[BLACK]);
	DrawString(120,50,"Small",colors[RED]);
	DrawString(210, 50, "Medium", colors[RED]);
	DrawString(320, 50, "Large", colors[RED]);
	
	DrawString(620, 50, "Small", colors[RED]);
	DrawString(710, 50, "Medium", colors[RED]);
	DrawString(820, 50, "Large", colors[RED]);
	if (coloropen == true)
	{
		DrawTriangle(70, 800, 70, 770, 40, 785, colors[RED]);
	}
	if (help2 == -1)
	{

		fstream myfile;
		myfile.open(email+".txt", ios::in);
		string line;
		int iii = 0;
		string file;
		while (getline(myfile, line))
		{
			if (iii == 0)
			{
				file = line;
				myfile.close();
			}
		}
		myfile.close();
		file = file + ".txt";
		myfile.open(file, ios::out);
		myfile << a << endl;
		myfile << b << endl;
		myfile << c << endl;
		myfile << d << endl;
		myfile << e << endl;
		myfile << f << endl;
		myfile << g << endl;
		myfile << h << endl;
		myfile << i << endl;
		myfile << j << endl;
		myfile << k << endl;
		myfile << l << endl;
		myfile << m << endl;
		myfile << n << endl;
		myfile.close();
		glutDisplayFunc(Setting);
		glutPostRedisplay();
	}
	glutSwapBuffers();
}
//it is my mouse controller
void Menue::MouseControl(int button, int state, int x, int y) {

	cout << "d" << endl;
	if (entervalue == 3)
	{
		if (button == GLUT_LEFT_BUTTON) 
		{
			cout << "x" << x << "y" << y << endl;
			if (x > 400 && x < 500 && y>210 && y < 245 && s != true)
			{
				xt = 0;
				yt = 0;
			}
			if (x > 400 && x < 465 && y>265 && y < 290 && s != true)
			{
				xt = 1;
				yt = 1;
				s = true;
			}
			if (x > 400 && x < 465 && y>320 && y < 345 && s != true)
			{
				xt = 2;
				yt = 2;
			}
			if (x > 400 && x < 480 && y>370 && y < 390 && s != true)
			{
				xt = 3;
				yt = 3;

			}
			if (x > 400 && x < 480 && y>420 && y < 440 && s != true)
			{
				xt = 4;
				yt = 4;
			}
			if (x > 400 && x < 465 && y>320 && y < 345 && s == true)
			{
				help1 = 0;
				help2 = 0;

			}
			if (x > 400 && x < 480 && y>370 && y < 390 && s == true)
			{
				help1 = 1;
				help2 = 1;

			}
			if (x > 40 && x < 73 && y>43 && y < 63 && s != true)
			{
				yt = -1;
			}
			if (x > 40 && x < 73 && y>43 && y < 63 && s == true && help2 == -1)
			{
				yt = -1;
				help1 = 0;
				s = false;
				xt = 1;
			}
			if (x > 40 && x < 73 && y>43 && y < 63 && s == true && (help2 == 0 || help2 == 1))
			{
				help2 = -1;
			}
			if (help2 == 0)
			{
				controlopen = true;
			}
			if (x > 40 && x < 73 && y>43 && y < 63 && controlopen == true)
			{
				controlopen = false;
				s = true;
			}
			if (modeopen == true && x > 40 && x < 73 && y>43 && y < 63)
			{
				modehelper1 = 0;
				modeopen = false;
				help2 = -1;
				yt = 1;
				xt = 1;
				help1 = 1;
				s = true;

			}
			if (help2 == 1)
			{
				s = false;
				controlopen = false;
				modeopen = true;
				xt = 1;
			}

		}
		else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
		{

		}
	}
	glutPostRedisplay();
}
//it is my control screen
void Menue::control()
{

	    glClearColor(1, 1, 1, 0);
	    glClear(GL_COLOR_BUFFER_BIT); //Update the colors

		if (controlhelper1 == 0)
		{
			DrawTriangle(220, 430, 220, 460, 250, 445, colors[WHITE]);
			DrawRectangle(270, 412, 100, 70, colors[RED]);
		}
		if (controlhelper1== 1)
		{
			DrawTriangle(220, 360, 220, 390, 250, 375, colors[WHITE]);
			DrawRectangle(270, 341, 100, 70, colors[RED]);
		}
		if (controlhelper1==2)
		{
			DrawTriangle(220, 290, 220, 320, 250, 305, colors[WHITE]);
			DrawRectangle(270, 270, 100, 70, colors[RED]);
		}
		DrawString(100, 425, "Fighter Plan", colors[RED]);
		DrawString(100, 360, "Helicoptor", colors[RED]);
		DrawString(100, 290, "Tank", colors[RED]);
		DrawTriangle(295, 425, 295, 455,340,440, colors[GRAY]);
		DrawRectangle(335, 438, 15, 5, colors[YELLOW]);
		DrawRectangle(277, 438, 20, 5, colors[YELLOW]);
		DrawRectangle(295, 360, 40, 20, colors[GRAY]);
		DrawRectangle(320, 380, 5, 15, colors[BLUE]);
		DrawRectangle(315, 390, 15, 5, colors[BLUE]);
		DrawRectangle(315, 345, 15, 5, colors[BLUE]);
		DrawRectangle(320, 345, 5, 15, colors[BLUE]);
		DrawRectangle(285, 368, 10, 5, colors[GREEN]);
		DrawRectangle(285, 368, 5, 15, colors[GREEN]);
		DrawRectangle(295, 290, 40, 30, colors[GRAY]);
		DrawCircle(312, 305, 10, colors[RED]);
		DrawRectangle(285, 285, 60, 5, colors[YELLOW]);
		DrawRectangle(285, 320, 60, 5, colors[YELLOW]);
		DrawRectangle(322, 303, 40, 5, colors[BLUE]);
	DrawTriangle(70, 800, 70, 770, 40, 785, colors[WHITE]);
	if (coloropen == true)
	{
		DrawTriangle(70, 800, 70, 770, 40, 785, colors[RED]);
	}
	if (help2 == -1)
	{
		fstream file;
		file.open(email + ".txt", ios::app);
		if (controlhelper1 == 0)
		{
			file << "0" << endl;
		}
		else if (controlhelper1 == 1)
		{
			file << "1" << endl;
		}
		else
		{
			file << "2" << endl;
		}
		file.close();
		glutDisplayFunc(Setting);
		glutPostRedisplay();
	}
	glutSwapBuffers();
}
//it is my menue screen 
void Menue::menue()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawString(400, 600, "High Score", colors[WHITE]);
	DrawString(400, 550, "Setting", colors[WHITE]);
	DrawString(400, 500, "Credits", colors[WHITE]);
	DrawString(400, 450, "1 Player", colors[WHITE]);
	DrawString(400, 400, "2 Player ", colors[WHITE]);
	fstream myfile;
	myfile.open(email + ".txt", ios::in);
	string line;
	string mod;
	while (getline(myfile, line))
	{
		mod = line;
		myfile.close();
	}
	myfile.close();
	myfile.open(mod + ".txt", ios::in);
	myfile >> a;
	myfile >> b;
	myfile >> c;
	myfile >> d;
	myfile >> e;
	myfile >> f;
	myfile >> g;
	myfile >> h;
	myfile >> i;
	myfile >> j;
	myfile >> k;
	myfile >> l;
	myfile >> m;
	myfile >> n;
	myfile.close();
	myfile.open(email + ".txt", ios::in);
	while (getline(myfile, line))
	{
		mod = line;
	}
	if (mod == "0")
	{
		controlhelper1 = 0;
	}
	else if (mod == "1")
	{
		controlhelper1 = 1;
	}
	else
	{
		controlhelper1 = 2;
	}
	myfile.close();
	if (xt == 0)
	{
		DrawString(400, 600, "High Score", colors[RED]);
	}
	else if (xt == 1)
	{
		DrawString(400, 550, "Setting", colors[RED]);
	}
	else if (xt == 2)
	{
		DrawString(400, 500, "Credits", colors[RED]);
	}
	else if (xt == 3)
	{
		DrawString(400, 450, "1 Player", colors[RED]);
	}
	else if (xt == 4)
	{
		DrawString(400, 400, "2 Player ", colors[RED]);
	}
	cout << "\a\a\a\a\a\a";
	if (xt == 0)
	{
		glutPostRedisplay();
		DrawTriangle(350, 625, 350, 595, 380, 610, colors[WHITE]);
	}
	else if (xt == 1)
	{
		glutPostRedisplay();
		DrawTriangle(350, 575, 350, 545, 380, 560, colors[WHITE]);
	}
	else if (xt == 2)
	{
		glutPostRedisplay();
		DrawTriangle(350, 525, 350, 495, 380, 510, colors[WHITE]);
	}
	else if (xt == 3)
	{
		glutPostRedisplay();
		DrawTriangle(350, 475, 350, 445, 380, 460, colors[WHITE]);
	}
	else
	{
		glutPostRedisplay();
		DrawTriangle(350, 425, 350, 395, 380, 410, colors[WHITE]);
	}
	if (yt == 2)
	{
		glutDisplayFunc(credit);
	}
	else if (yt == 0)
	{
		glutDisplayFunc(HighScore);
	}
	else if (yt == 1)
	{
		glutDisplayFunc(Setting);
	}
	else if (yt == 3)
	{
		glutDisplayFunc(player1);
	}
	else if (yt == 4)
	{
		glutDisplayFunc(player2);
	}
	glutSwapBuffers();

}
//it is my credit screen
void Menue::credit()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawTriangle(70, 800, 70, 770, 40, 785, colors[WHITE]);
	fstream myfile;
	int y = 700;
	string line;
	myfile.open("credit.txt",ios::in);
	while(getline(myfile, line))
	{
		DrawString(100, y, line, colors[WHITE]);
		y -= 30;
	}
	myfile.close();
	if (coloropen == true)
	{
		DrawTriangle(70, 800, 70, 770, 40, 785, colors[RED]);
	}
	if (yt == -1)
	{
		glutDisplayFunc(menue);
		glutPostRedisplay();
	}
	glutSwapBuffers();

}
//it is my higscore screen
void Menue::HighScore()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawTriangle(70, 800, 70, 770, 40, 785, colors[WHITE]);
	fstream myfile;
	int iii = 0;
	int jjj = 0;
	int kkk = 0;
	int yy = 700;
	DrawString(150, 750, "TOP 10 HIGH SCORE", colors[YELLOW]);
	string pp;
	int* arr1[1000];
	string* arr2[1000];
	int y = 0;
	int z = 0;
	myfile.open("Score.txt", ios::in);
	while (getline(myfile, pp))
	{
		if (y % 2 == 0)
		{
			arr2[z] = new string;
			*arr2[z] = pp;
		}
		if (y % 2 == 1)
		{
			arr1[z] = new int;
			*arr1[z] = stoi(pp);
			z++;
		}
		y++;
	}
	myfile.close();

	for (int o = 0; o < z; o++)
	{
		for (int q = o; q < z; q++)
		{

			if (*arr1[o] < *arr1[q])
			{
				int temp1= *arr1[o];
				string temp2=*arr2[o];
				*arr1[o] = *arr1[q];
				*arr2[o] = *arr2[q];
				*arr1[q] = temp1;
				*arr2[q] = temp2;

			}
		}
	}
	int check1 = 0;
	int check2 = 0;
	myfile.open("HighScore.txt", ios::out);
	while(check2!=20)
	{
		if (y == check2)
		{
			break;
		}
		if (check2 % 2 == 0)
		{
			
			myfile << *arr2[check1] << endl;
		}
		if (check2 % 2 == 1)
		{
			myfile << *arr1[check1] << endl;
			check1++;
		}
		check2++;
	}
	myfile.close();
	myfile.open("HighScore.txt", ios::in);
	while (getline(myfile, pp))
	{
		if (iii % 2 == 0)
		{
			DrawString(100,yy,pp,colors[WHITE]);
		}
		if (iii % 2 == 1)
		{
			DrawString(400, yy, pp, colors[WHITE]);
			yy = yy - 30;
		}
		if (kkk == 19)
		{
			myfile.close();
		}
		jjj++;
		iii++;
		kkk++;
	}
	myfile.close();
	if (coloropen==true)
	{
		DrawTriangle(70, 800, 70, 770, 40, 785, colors[RED]);
	}
	if (yt == -1)
	{
		glutDisplayFunc(menue);
		glutPostRedisplay();
	}
	glutSwapBuffers();

}
//it is my starting screen
void Menue::starting()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	cout << "\a\a\a\a\a\a";
	if (timer_helper==10)
	{
		glutDisplayFunc(display);
		timer_helper = 0;
		glutPostRedisplay();
	}
	glutSwapBuffers();

}
//it is my setting screen
void Menue::Setting()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawTriangle(70, 800, 70, 770, 40, 785, colors[WHITE]);
	DrawString(400, 450, "Control", colors[WHITE]);
	DrawString(400, 500, "Mode", colors[WHITE]);
	if (help1 == 1)
	{
		DrawString(400, 450, "Control", colors[RED]);
	}
	else if (help1 == 0)
	{
		DrawString(400, 500, "Mode", colors[RED]);
	}
	if (coloropen==true)
	{
		DrawTriangle(70, 800, 70, 770, 40, 785, colors[RED]);
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
		
		glutDisplayFunc(control);
		glutPostRedisplay();
	}
	if (help2 == 1)
	{
		glutDisplayFunc(mode);
		glutPostRedisplay();
	}

	if (yt == -1)
	{
		glutDisplayFunc(menue);
		glutPostRedisplay();
	}
	glutSwapBuffers();
}
//it is my player  screen
void Menue::player1()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawTriangle(70, 800, 70, 770, 40, 785, colors[WHITE]);
	Map m1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, controlhelper1, 1);
	if (coloropen == true)
	{
		DrawTriangle(70, 800, 70, 770, 40, 785, colors[RED]);
	}
	if (yt == -1)
	{
		glutDisplayFunc(menue);
		glutPostRedisplay();
	}
	glutSwapBuffers();

}
//it is my player screen
void Menue::player2()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawTriangle(70, 800, 70, 770, 40, 785, colors[WHITE]);
	Map m1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, controlhelper1, 2);
	glutSwapBuffers();

}
//it is my timer screen
void Menue::timer(int h) {
	if (timer_helper < 11)
	{
		timer_helper++;
	}
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}
////it is keyboard key controller
void Menue::Assci(unsigned char key, int x, int y) {

	if (entervalue == 3)
	{
		if (key >= 97 && key <= 122)
		{
			key = key - 32;
		}
		if (modehelper1 == 0)
		{
			d = key;
		}
		if (modehelper1 == 1)
		{
			a = key;
		}
		if (modehelper1 == 2)
		{
			b = key;
		}
		if (modehelper1 == 3)
		{
			c = key;
		}
		if (modehelper1 == 4)
		{
			e = key;
		}
		if (modehelper1 == 5)
		{
			f = key;
		}
		if (modehelper1 == 6)
		{
			g = key;
		}
		if (modehelper1 == 7)
		{
			h = key;
		}
		if (modehelper1 == 8)
		{
			i = key;
		}
		if (modehelper1 == 9)
		{
			j = key;
		}
		if (modehelper1 == 10)
		{
			k = key;
		}
		if (modehelper1 == 11)
		{
			l = key;
		}
		if (modehelper1 == 12)
		{
			m = key;
		}
		if (modehelper1 == 13)
		{
			n = key;
		}
	}
	glutPostRedisplay();
}
//it is my basic display screen
void Menue::display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	Player p;
	DrawRectangle(100, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(150, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(200, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(250, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(300, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(350, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(400, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(450, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(500, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(550, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(600, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(650, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(700, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(750, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(800, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(850, 600, 50, 50, colors[MAGENTA]);
	DrawRectangle(900, 600, 50, 50, colors[MAGENTA]);
	DrawString(430, 500, "Enter NAME", colors[BLACK]);
	DrawRectangle(100, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(150, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(200, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(250, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(300, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(350, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(400, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(450, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(500, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(550, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(600, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(650, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(700, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(750, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(800, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(850, 400, 50, 50, colors[MAGENTA]);
	DrawRectangle(900, 400, 50, 50, colors[MAGENTA]);
	DrawString(430, 300, "Enter Password", colors[BLACK]);
	DrawRectangle(100, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(150, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(200, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(250, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(300, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(350, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(400, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(450, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(500, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(550, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(600, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(650, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(700, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(750, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(800, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(850, 200, 50, 50, colors[MAGENTA]);
	DrawRectangle(900, 200, 50, 50, colors[MAGENTA]);
	DrawString(430, 700, "Enter Email", colors[BLACK]);
	if (firstrow == 0)
	{
		DrawRectangle(100, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 1)
	{
		DrawRectangle(150, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 2)
	{
		DrawRectangle(200, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 3)
	{
		DrawRectangle(250, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 4)
	{
		DrawRectangle(300, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 5)
	{
		DrawRectangle(350, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 6)
	{
		DrawRectangle(400, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 7)
	{
		DrawRectangle(450, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 8)
	{
		DrawRectangle(500, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 9)
	{
		DrawRectangle(550, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 10)
	{
		DrawRectangle(600, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 11)
	{
		DrawRectangle(650, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 12)
	{
		DrawRectangle(700, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 13)
	{
		DrawRectangle(750, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 14)
	{
		DrawRectangle(800, 600, 50, 50, colors[DARK_RED]);
	}
	if (firstrow == 15)
	{
		DrawRectangle(850, 600, 50, 50, colors[DARK_RED]);

	}
	if (firstrow == 16)
	{
		DrawRectangle(900, 600, 50, 50, colors[DARK_RED]);
	}

	if (secondrow == 0)
	{
		DrawRectangle(100, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 1)
	{
		DrawRectangle(150, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 2)
	{
		DrawRectangle(200, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 3)
	{
		DrawRectangle(250, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 4)
	{
		DrawRectangle(300, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 5)
	{
		DrawRectangle(350, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 6)
	{
		DrawRectangle(400, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 7)
	{
		DrawRectangle(450, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 8)
	{
		DrawRectangle(500, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 9)
	{
		DrawRectangle(550, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 10)
	{
		DrawRectangle(600, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 11)
	{
		DrawRectangle(650, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 12)
	{
		DrawRectangle(700, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 13)
	{
		DrawRectangle(750, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 14)
	{
		DrawRectangle(800, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 15)
	{
		DrawRectangle(850, 400, 50, 50, colors[DARK_RED]);
	}
	if (secondrow == 16)
	{
		DrawRectangle(900, 400, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 0)
	{
		DrawRectangle(100, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 1)
	{
		DrawRectangle(150, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 2)
	{
		DrawRectangle(200, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 3)
	{
		DrawRectangle(250, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 4)
	{
		DrawRectangle(300, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 5)
	{
		DrawRectangle(350, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 6)
	{
		DrawRectangle(400, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 7)
	{
		DrawRectangle(450, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 8)
	{
		DrawRectangle(500, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 9)
	{
		DrawRectangle(550, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 10)
	{
		DrawRectangle(600, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 11)
	{
		DrawRectangle(650, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 12)
	{
		DrawRectangle(700, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 13)
	{
		DrawRectangle(750, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 14)
	{
		DrawRectangle(800, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 15)
	{
		DrawRectangle(850, 200, 50, 50, colors[DARK_RED]);
	}
	if (thirdrow == 16)
	{
		DrawRectangle(900, 200, 50, 50, colors[DARK_RED]);
	}
	string *b=new string [17];
	for (int i = 0; i < 17; i++)
	{
		b[i] = arr1[i];
	}
	string* a = new string[17];
	for (int i = 0; i < 17; i++)
	{
		a[i] = arr2[i];
	}
	string* c= new string[17];
	for (int i = 0; i < 17; i++)
	{
		c[i] = arr3[i];
	}
	DrawString(110, 610, b[0], colors[BLACK]);
	DrawString(160, 610, b[1], colors[BLACK]);
	DrawString(210, 610, b[2], colors[BLACK]);
	DrawString(260, 610, b[3], colors[BLACK]);
	DrawString(310, 610, b[4], colors[BLACK]);
	DrawString(360, 610, b[5], colors[BLACK]);
	DrawString(410, 610, b[6], colors[BLACK]);
	DrawString(460, 610, b[7], colors[BLACK]);
	DrawString(510, 610, b[8], colors[BLACK]);
	DrawString(560, 610, b[9], colors[BLACK]);
	DrawString(610, 610, b[10], colors[BLACK]);
	DrawString(660, 610, b[11], colors[BLACK]);
	DrawString(710, 610, b[12], colors[BLACK]);
	DrawString(760, 610, b[13], colors[BLACK]);
	DrawString(810, 610, b[14], colors[BLACK]);
	DrawString(860, 610, b[15], colors[BLACK]);
	DrawString(910, 610, b[16], colors[BLACK]);
	DrawString(110, 210, c[0], colors[BLACK]);
	DrawString(160, 210, c[1], colors[BLACK]);
	DrawString(210, 210, c[2], colors[BLACK]);
	DrawString(260, 210, c[3], colors[BLACK]);
	DrawString(310, 210, c[4], colors[BLACK]);
	DrawString(360, 210, c[5], colors[BLACK]);
	DrawString(410, 210, c[6], colors[BLACK]);
	DrawString(460, 210, c[7], colors[BLACK]);
	DrawString(510, 210, c[8], colors[BLACK]);
	DrawString(560, 210, c[9], colors[BLACK]);
	DrawString(610, 210, c[10], colors[BLACK]);
	DrawString(660, 210, c[11], colors[BLACK]);
	DrawString(710, 210, c[12], colors[BLACK]);
	DrawString(760, 210, c[13], colors[BLACK]);
	DrawString(810, 210, c[14], colors[BLACK]);
	DrawString(860, 210, c[15], colors[BLACK]);
	DrawString(910, 210, c[16], colors[BLACK]);
	DrawString(110, 410, a[0], colors[BLACK]);
	DrawString(160, 410, a[1], colors[BLACK]);
	DrawString(210, 410, a[2], colors[BLACK]);
	DrawString(260, 410, a[3], colors[BLACK]);
	DrawString(310, 410, a[4], colors[BLACK]);
	DrawString(360, 410, a[5], colors[BLACK]);
	DrawString(410, 410, a[6], colors[BLACK]);
	DrawString(460, 410, a[7], colors[BLACK]);
	DrawString(510, 410, a[8], colors[BLACK]);
	DrawString(560, 410, a[9], colors[BLACK]);
	DrawString(610, 410, a[10], colors[BLACK]);
	DrawString(660, 410, a[11], colors[BLACK]);
	DrawString(710, 410, a[12], colors[BLACK]);
	DrawString(760, 410, a[13], colors[BLACK]);
	DrawString(810, 410, a[14], colors[BLACK]);
	DrawString(860, 410, a[15], colors[BLACK]);
	DrawString(910, 410, a[16], colors[BLACK]);
	string d="";
	string f="";
	
	if (entervalue == 3)
	{
		for (int i = 0; i < 17; i++)
		{
			d = d + a[i];
			email = email + b[i];
			f = f + c[i];
		}
		cout<<"\n d = "<<d<<endl;
		name = d;
		cout << "\n email = " << email << endl;
		cout << "\n f = " << f << endl;
		Player p;
		p.setemail(email);
		p.setname(d);
		p.setpassword(f);
		cout<<endl << p.valideplayer() << endl;;
		if (p.valideplayer())
		{

		}
		else
		{
			p.registerplayer();
		}
			
		glutPassiveMotionFunc(Color);
		glutSpecialFunc(arrow);
		glutKeyboardFunc(Assci);
		glutMouseFunc(MouseControl);
		glutDisplayFunc(menue);
		glutPostRedisplay();
	}
	glutSwapBuffers();

}
//it is keyboard key controller
	void Menue::dataleftright(unsigned char key, int x, int y) {	
		if (entervalue < 3)
		{
			if (key >= 97 && key <= 122)
			{
				key = key - 32;
			}
			if (entervalue < 3)
			{



				if (entervalue == 2)
				{
					if (int(key) == 13)
					{
						thirdrow = -1;
						entervalue++;
					}
					else if (key == 8)
					{
						thirdrow--;
						if (thirdrow < 0)
						{
							thirdrow = 0;
						}
					}
					else
					{
						arr3[thirdrow] = key;
						thirdrow++;
						if (thirdrow > 16)
						{
							thirdrow = 16;
						}
					}
				}
				if (entervalue == 1)
				{
					if (int(key) == 13)
					{
						entervalue++;
						thirdrow = 0;
						secondrow = -1;
					}
					else if (key == 8)
					{
						secondrow--;
						if (secondrow < 0)
						{
							secondrow = 0;
						}
					}
					else
					{
						arr2[secondrow] = key;
						secondrow++;
						if (secondrow > 16)
						{
							secondrow = 16;
						}
					}

				}
				if (entervalue == 0)
				{
					if (int(key) == 13)
					{
						entervalue++;
						firstrow = -1;
						secondrow = 0;
					}
					else if (key == 8)
					{
						firstrow--;
						if (firstrow < 0)
						{
							firstrow = 0;
						}
					}
					else
					{
						arr1[firstrow] = key;
						firstrow++;
						if (firstrow > 16)
						{
							firstrow = 16;
						}

					}

				}
			}
		}
		glutPostRedisplay();
	}
	//it is keyboard key controller
	void Menue::updown(int key, int x, int y) {
		if (entervalue < 3)
		{
			if (key == GLUT_KEY_LEFT)
			{
				if (entervalue == 0)
				{
					firstrow--;
					if (firstrow < 0)
					{
						firstrow = 0;
					}
				}
				else if (entervalue == 1)
				{
					secondrow--;
					if (secondrow < 0)
					{
						secondrow = 0;
					}
				}
				else if (entervalue == 2)
				{
					thirdrow--;
					if (thirdrow < 0)
					{
						thirdrow = 0;
					}
				}
			}
			else if (key == GLUT_KEY_RIGHT)
			{
				if (entervalue == 0)
				{
					firstrow++;
					if (firstrow >16)
					{
						firstrow = 16;
					}
				}
				else if (entervalue == 1)
				{
					secondrow++;
					if (secondrow >16)
					{
						secondrow = 16;
					}
				}
				else if (entervalue == 2)
				{
					thirdrow++;
					if (thirdrow > 16)
					{
						thirdrow = 16;
					}
				}
			    
			}
			else if (key == GLUT_KEY_UP)
			{

			}
			else if (key == GLUT_KEY_DOWN)
			{

			}
		}
		glutPostRedisplay();

	}
	//it my move mouse funtion
	void Menue::Color(int x, int y) {
		coloropen = false;
		if (x > 400 && x < 500 && y>210 && y < 245 && s != true)
		{
			xt = 0;
		}
		if (x > 400 && x < 465 && y>265 && y < 290 && s != true)
		{
			xt = 1;
		}
		if (x > 400 && x < 465 && y>320 && y < 345 && s != true)
		{
			xt = 2;
		}
		if (x > 400 && x < 480 && y>370 && y < 390 && s != true)
		{
			xt = 3;

		}
		if (x > 400 && x < 480 && y>420 && y < 440 && s != true)
		{
			xt = 4;
		}
		if (x > 400 && x < 465 && y>320 && y < 345 && s == true)
		{
			help1 = 0;

		}
		if (x > 400 && x < 480 && y>370 && y < 390 && s == true)
		{
			help1 = 1;

		}
		if (x > 40 && x < 73 && y>43 && y < 63 && s != true)
		{
			coloropen = true;
		}
		if (x > 40 && x < 73 && y>43 && y < 63 && s == true && help2 == -1)
		{
			coloropen = true;
		}
		if (x > 40 && x < 73 && y>43 && y < 63 && s == true && (help2 == 0 || help2 == 1))
		{
			coloropen = true;
		}
		if (modeopen == true && x > 40 && x < 73 && y>43 && y < 63)
		{
			coloropen = true;

		}

	
		glutPostRedisplay();
	}