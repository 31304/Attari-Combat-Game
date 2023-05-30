#pragma once
#include "util.h"
int centerx;
int centery;
int centerx2;
int centery2;
int centerx3;
int boost1=1;
int boost2=1;
bool boost1control=false;
bool boost2control=false;
int centery3;
bool screen1 = false;
bool screen2 = false;
bool screen3 = false;
int centerx1;
bool match = false;
bool fire1 = false;
int centery1;
bool fire=false;
//this class agreegate with the map calss
class Vehicle
{
protected:
	int r1_l;
	int r1_w;
	int r1_x;
	int r1_y;
	int r2_l;
	int r2_w;
	int r2_x;
	int r2_y;
	int r3_l;
	int r3_w;
	int r3_x;
	int r3_y;
	int r4_l;
	int r4_w;
	int r4_x;
	int r4_y;
	int r5_l;
	int r5_w;
	int r5_x;
	int r5_y;
	int r6_l;
	int r6_w;
	int r6_x;
	int r6_y;
	int r7_l;
	int	r7_w;
	int r7_x;
	int r7_y;
public:
	virtual void left(int a)=0;
	virtual void right(int a) = 0;
	virtual void top(int a) = 0;
	virtual void bottom(int a) = 0;
	virtual int getcenterx()=0;
	virtual int getcentery()=0;
	virtual int getr4_x() = 0;
	virtual int getr4_y() = 0;
	virtual int getr1_x() = 0;
	virtual int getr1_y() = 0;
	virtual void setr4_x(int a) = 0;
	virtual void setr4_y(int a) = 0;
	virtual void changecenter(int x,int y)=0;

};
//these three classes inherited with th vechile and this classes runtime intialize and creat the concept of polymorphism
class Tank:public Vehicle
{
private:
	
	int c1_x;
    int c1_y;
public:
	Tank()
	{
		r1_l = 40;
		r1_w = 30;
		r1_x = GetRandInRange(100,600);
		r1_y = GetRandInRange(100, 500);
		r2_l = 60;
		r2_w = 5;
		r2_x = r1_x-10;
		r2_y = r1_y-5;
		r3_l = 60;
		r3_w = 5;
		r3_x = r1_x-10;
		r3_y = r1_y+30;
		r4_l = 40;
		r4_w = 5;
		r4_x = r1_x+35;
		r4_y = r1_y+12;
		c1_x = r1_x+27;
		c1_y = r1_y+13;
	}
	virtual void changecenter(int x, int y) {
		r1_x = x;
		r1_y = y;
		r1_l = 40;
		r1_w = 30;
		r2_l = 60;
		r2_w = 5;
		r2_x = r1_x - 10;
		r2_y = r1_y - 5;
		r3_l = 60;
		r3_w = 5;
		r3_x = r1_x - 10;
		r3_y = r1_y + 30;
		r4_l = 40;
		r4_w = 5;
		r4_x = r1_x + 35;
		r4_y = r1_y + 12;
		c1_x = r1_x + 27;
		c1_y = r1_y + 13;
	}
	int getr4_x()
	{
		return r4_x;
	}
	int getr4_y()
	{
		return r4_y;
		}
	int getr1_x()
	{
		return r1_x;
	}
	int getr1_y()
	{
		return r1_y;
		}

	virtual void setr4_x(int a) {
		r4_x = a;
	}
	virtual void setr4_y(int a) {
		r4_y = a;
	}
	virtual int getcenterx() {
		return c1_x;
	}
	virtual int getcentery() {
		return c1_y;
	}
	virtual void top(int a)
	{
		if (a == 10)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_y += 30;
				c1_y += 30;
				r2_y += 30;
				r3_y += 30;
				r4_y += 30;
			}
			else if (screen2 == true)
			{
				r1_y += 20;
				c1_y += 20;
				r2_y += 20;
				r3_y += 20;
				r4_y += 20;
			}
			else
			{
				r1_y += 10;
				c1_y += 10;
				r2_y += 10;
				r3_y += 10;
				r4_y += 10;
			}
		}
		if (a == 50 || a==90 || a== 130)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_y += 5;
				c1_y += 5;
				r2_y += 5;
				r3_y += 5;
				r4_y += 5;
			}
			else if (screen2 == true)
			{
				r1_y += 3;
				c1_y += 3;
				r2_y += 3;
				r3_y += 3;
				r4_y += 3;
			}
			else
			{
				r1_y += 1;
				c1_y += 1;
				r2_y += 1;
				r3_y += 1;
				r4_y += 1;
			}
		}
		
		DrawRectangle(r1_x, r1_y, r1_w, r1_l, colors[GRAY]);
		DrawCircle(c1_x-12, c1_y+12, 10, colors[RED]);
		DrawRectangle(r2_x+5, r2_y, r2_w, r2_l, colors[YELLOW]);
		DrawRectangle(r3_x+40, r3_y-35, r3_w, r3_l, colors[YELLOW]);
		DrawRectangle(r4_x-22, r4_y+22, r4_w, r4_l, colors[BLUE]);
	}
	virtual void bottom(int a)
	{
		
		if (a == 30)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_y -= 30;
				c1_y -= 30;
				r2_y -= 30;
				r3_y -= 30;
				r4_y -= 30;
			}
			else if (screen2 == true)
			{
				r1_y -= 20;
				c1_y -= 20;
				r2_y -= 20;
				r3_y -= 20;
				r4_y -= 20;
			}
			else
			{
				r1_y -= 10;
				c1_y -= 10;
				r2_y -= 10;
				r3_y -= 10;
				r4_y -= 10;
			}
		}
		if (a == 70 || a==110 || a==150)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_y -= 5;
				c1_y -= 5;
				r2_y -= 5;
				r3_y -= 5;
				r4_y -= 5;
			}
			else if (screen2 == true)
			{
				r1_y -= 3;
				c1_y -= 3;
				r2_y -= 3;
				r3_y -= 3;
				r4_y -= 3;
			}
			else
			{
				r1_y -= 1;
				c1_y -= 1;
				r2_y -= 1;
				r3_y -= 1;
				r4_y -= 1;
			}
		}
		DrawRectangle(r1_x, r1_y, r1_w, r1_l, colors[GRAY]);
		DrawCircle(c1_x-12, c1_y, 10, colors[RED]);
		DrawRectangle(r2_x + 5, r2_y, r2_w, r2_l, colors[YELLOW]);
		DrawRectangle(r3_x + 40, r3_y - 35, r3_w, r3_l, colors[YELLOW]);
		DrawRectangle(r4_x - 22, r4_y-45, r4_w, r4_l, colors[BLUE]);
	}
	virtual void right(int a)
	{
		if (a == 40)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x += 30;
				c1_x += 30;
				r2_x += 30;
				r3_x += 30;
				r4_x += 30;
			}
			else if (screen2 == true)
			{
				r1_x += 20;
				c1_x += 20;
				r2_x += 20;
				r3_x += 20;
				r4_x += 20;
			}
			else
			{
				r1_x += 10;
				c1_x += 10;
				r2_x += 10;
				r3_x += 10;
				r4_x += 10;
			}

		}
		if (a == 80 || a==160 || a==120)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x += 5;
				c1_x += 5;
				r2_x += 5;
				r3_x += 5;
				r4_x += 5;
			}
			else if (screen2==true)
			{
				r1_x += 3;
				c1_x += 3;
				r2_x += 3;
				r3_x += 3;
				r4_x += 3;
			}
			else
			{
				r1_x += 1;
				c1_x += 1;
				r2_x += 1;
				r3_x += 1;
				r4_x += 1;
			}
			
		}
		
		DrawRectangle(r1_x, r1_y, r1_l, r1_w, colors[GRAY]);
		DrawCircle(c1_x, c1_y, 10, colors[RED]);
		DrawRectangle(r2_x, r2_y, r2_l, r2_w, colors[YELLOW]);
		DrawRectangle(r3_x, r3_y, r3_l, r3_w, colors[YELLOW]);
		DrawRectangle(r4_x, r4_y, r4_l, r4_w, colors[BLUE]);
	}
	virtual void left(int a)
	{
		if (a ==20)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x -= 30;
				c1_x -= 30;
				r2_x -= 30;
				r3_x -= 30;
				r4_x -= 30;
			}
			else if (screen2 == true)
			{
				r1_x -= 20;
				c1_x -= 20;
				r2_x -= 20;
				r3_x -= 20;
				r4_x -= 20;
			}
			else
			{
				r1_x -= 10;
				c1_x -= 10;
				r2_x -= 10;
				r3_x -= 10;
				r4_x -= 10;
			}
		}
		if (a == 60 || a==100 || a==140)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x -= 1;
				c1_x -= 1;
				r2_x -= 1;
				r3_x -= 1;
				r4_x -= 1;
			}
			else if (screen2 == true)
			{
				r1_x -= 3;
				c1_x -= 3;
				r2_x -= 3;
				r3_x -= 3;
				r4_x -= 3;
			}
			else
			{
				r1_x -= 1;
				c1_x -= 1;
				r2_x -= 1;
				r3_x -= 1;
				r4_x -= 1;
			}
		}
		DrawRectangle(r1_x, r1_y, r1_l, r1_w, colors[GRAY]);
		DrawCircle(c1_x, c1_y, 10, colors[RED]);
		DrawRectangle(r2_x, r2_y, r2_l, r2_w, colors[YELLOW]);
		DrawRectangle(r3_x, r3_y, r3_l, r3_w, colors[YELLOW]);
		DrawRectangle(r4_x-57, r4_y+2, r4_l, r4_w, colors[BLUE]);
	}

};
class Helicopter : public Vehicle
{
public:

	Helicopter()
	{
		r1_l= 40;
		r1_w= 20;
		r1_x= GetRandInRange(100, 600);
		r1_y= GetRandInRange(100, 500);
		r2_l= 5;
		r2_w= 15;
		r2_x= r1_x+25;
		r2_y= r1_y+20;
		r3_l= 15;
		r3_w= 5;
		r3_x= r1_x+20;
		r3_y= r1_y+30;
		r4_l= 15;
		r4_w= 5;
		r4_x= r1_x+20;
		r4_y= r1_y-15;
		r5_l= 5;
		r5_w= 15;
		r5_x= r1_x+25;
		r5_y= r1_y-15;
		r6_l= 10;
		r6_w= 5;
		r6_x= r1_x-10;
		r6_y = r1_y+8;
	    r7_l = 5;
		r7_w = 15;
		r7_x = r1_x - 10;
		r7_y = r1_y+8;
	}
	virtual void changecenter(int x, int y) {
		r1_x = x;
		r1_y = y;
		r1_l = 40;
		r1_w = 20;
		r2_l = 5;
		r2_w = 15;
		r2_x = r1_x + 25;
		r2_y = r1_y + 20;
		r3_l = 15;
		r3_w = 5;
		r3_x = r1_x + 20;
		r3_y = r1_y + 30;
		r4_l = 15;
		r4_w = 5;
		r4_x = r1_x + 20;
		r4_y = r1_y - 15;
		r5_l = 5;
		r5_w = 15;
		r5_x = r1_x + 25;
		r5_y = r1_y - 15;
		r6_l = 10;
		r6_w = 5;
		r6_x = r1_x - 10;
		r6_y = r1_y + 8;
		r7_l = 5;
		r7_w = 15;
		r7_x = r1_x - 10;
		r7_y = r1_y + 8;
	}
	int getr4_x()
	{
		return r4_x;
	}
	int getr4_y()
	{
		return r4_y-10;
	}
	int getr1_x()
	{
		return r1_x;
	}
	int getr1_y()
	{
		return r1_y;
	}

	virtual void setr4_x(int a) {
		r4_x = a;
	}
	virtual void setr4_y(int a) {
		r4_y = a;
	}
	virtual int getcenterx() {
		return r1_x;
	}
	virtual int getcentery() {
		return r1_y;
	}
	virtual void right(int a)
	{
		if (a == 40)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x += 30;
				r2_x += 30;
				r3_x += 30;
				r4_x += 30;
				r5_x += 30;
				r6_x += 30;
				r7_x += 30;
			}
			else if (screen2 == true)
			{
				r1_x += 20;
				r2_x += 20;
				r3_x += 20;
				r4_x += 20;
				r5_x += 20;
				r6_x += 20;
				r7_x += 20;
			}
			else
			{
				r1_x += 10;
				r2_x += 10;
				r3_x += 10;
				r4_x += 10;
				r5_x += 10;
				r6_x += 10;
				r7_x += 10;
			}
		}
		if (a == 80 || a==160 || a==120)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x += 5;
				r2_x += 5;
				r3_x += 5;
				r4_x += 5;
				r5_x += 5;
				r6_x += 5;
				r7_x += 5;
			}
			else if (screen2 == true)
			{
				r1_x += 3;
				r2_x += 3;
				r3_x += 3;
				r4_x += 3;
				r5_x += 3;
				r6_x += 3;
				r7_x += 3;
			}
			else
			{
				r1_x += 1;
				r2_x += 1;
				r3_x += 1;
				r4_x += 1;
				r5_x += 1;
				r6_x += 1;
				r7_x += 1;
			}
		}
		DrawRectangle(r1_x, r1_y, r1_l, r1_w, colors[GRAY]);
		DrawRectangle(r2_x,r2_y,r2_l,r2_w, colors[BLUE]);
		DrawRectangle(r3_x,r3_y,r3_l,r3_w, colors[BLUE]);
		DrawRectangle(r4_x,r4_y,r4_l,r4_w, colors[BLUE]);
		DrawRectangle(r5_x,r5_y,r5_l,r5_w, colors[BLUE]);
		DrawRectangle(r6_x,r6_y,r6_l,r6_w, colors[GREEN]);
		DrawRectangle(r7_x,r7_y,r7_l,r7_w, colors[GREEN]);
	}
	virtual void left(int a)
	{
		if (a == 20)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x -= 30;
				r2_x -= 30;
				r3_x -= 30;
				r4_x -= 30;
				r5_x -= 30;
				r6_x -= 30;
				r7_x -= 30;
			}
			else if (screen2 == true)
			{
				r1_x -= 20;
				r2_x -= 20;
				r3_x -= 20;
				r4_x -= 20;
				r5_x -= 20;
				r6_x -= 20;
				r7_x -= 20;
			}
			else
			{
				r1_x -= 10;
				r2_x -= 10;
				r3_x -= 10;
				r4_x -= 10;
				r5_x -= 10;
				r6_x -= 10;
				r7_x -= 10;
			}
		}
		if (a == 60 || a==100 || a==140)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_x -= 5;
				r2_x -= 5;
				r3_x -= 5;
				r4_x -= 5;
				r5_x -= 5;
				r6_x -= 5;
				r7_x -= 5;
			}
			else if (screen2 == true)
			{
				r1_x -= 3;
				r2_x -= 3;
				r3_x -= 3;
				r4_x -= 3;
				r5_x -= 3;
				r6_x -= 3;
				r7_x -= 3;
			}
			else
			{
				r1_x -= 1;
				r2_x -= 1;
				r3_x -= 1;
				r4_x -= 1;
				r5_x -= 1;
				r6_x -= 1;
				r7_x -= 1;
			}
		}
		DrawRectangle(r1_x+15, r1_y, r1_l, r1_w, colors[GRAY]);
		DrawRectangle(r2_x, r2_y, r2_l, r2_w, colors[BLUE]);
		DrawRectangle(r3_x, r3_y, r3_l, r3_w, colors[BLUE]);
		DrawRectangle(r4_x, r4_y, r4_l, r4_w, colors[BLUE]);
		DrawRectangle(r5_x, r5_y, r5_l, r5_w, colors[BLUE]);
		DrawRectangle(r6_x+62, r6_y, r6_l, r6_w, colors[GREEN]);
		DrawRectangle(r7_x+70, r7_y, r7_l, r7_w, colors[GREEN]);
	}
	virtual void top(int a)
	{
		if (a == 10)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_y += 30;
				r2_y += 30;
				r3_y += 30;
				r4_y += 30;
				r5_y += 30;
				r6_y += 30;
				r7_y += 30;
			}
			else if (screen2 == true)
			{
				r1_y += 20;
				r2_y += 20;
				r3_y += 20;
				r4_y += 20;
				r5_y += 20;
				r6_y += 20;
				r7_y += 20;
			}
			else
			{
				r1_y += 10;
				r2_y += 10;
				r3_y += 10;
				r4_y += 10;
				r5_y += 10;
				r6_y += 10;
				r7_y += 10;
			}
		}
		if (a == 50 || a==90 || a==130)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_y += 5;
				r2_y += 5;
				r3_y += 5;
				r4_y += 5;
				r5_y += 5;
				r6_y += 5;
				r7_y += 5;
			}
			else if (screen2==true)
			{
				r1_y += 3;
				r2_y += 3;
				r3_y += 3;
				r4_y += 3;
				r5_y += 3;
				r6_y += 3;
				r7_y += 3;
			}
			else
			{
				r1_y += 1;
				r2_y += 1;
				r3_y += 1;
				r4_y += 1;
				r5_y += 1;
				r6_y += 1;
				r7_y += 1;
			}
		}
		DrawRectangle(r1_x, r1_y, r1_w, r1_l, colors[GRAY]);
		DrawRectangle(r2_x-37, r2_y, r2_w, r2_l, colors[BLUE]);
		DrawRectangle(r3_x-33, r3_y-15, r3_w, r3_l, colors[BLUE]);
		DrawRectangle(r4_x+10, r4_y+30, r4_w, r4_l, colors[BLUE]);
		DrawRectangle(r5_x-7, r5_y+35, r5_w, r5_l, colors[BLUE]);
		DrawRectangle(r6_x+18, r6_y-15, r6_w, r6_l, colors[GREEN]);
		DrawRectangle(r7_x+18, r7_y-15, r7_w, r7_l, colors[GREEN]);
	}
	virtual void bottom(int a)
	{
		if (a == 30)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				r1_y -= 30;
				r2_y -= 30;
				r3_y -= 30;
				r4_y -= 30;
				r5_y -= 30;
				r6_y -= 30;
				r7_y -= 30;
			}
			else if (screen2 == true)
			{
				r1_y -= 20;
				r2_y -= 20;
				r3_y -= 20;
				r4_y -= 20;
				r5_y -= 20;
				r6_y -= 20;
				r7_y -= 20;
			}
			else
			{
				r1_y -= 10;
				r2_y -= 10;
				r3_y -= 10;
				r4_y -= 10;
				r5_y -= 10;
				r6_y -= 10;
				r7_y -= 10;
			}
		}
		if (a == 70 || a==110 || a==150)
		{
			if (screen3==true)
			{
				r1_y -= 5;
				r2_y -= 5;
				r3_y -= 5;
				r4_y -= 5;
				r5_y -= 5;
				r6_y -= 5;
				r7_y -= 5;
			}
			else if (screen2 == true)
			{
				r1_y -= 3;
				r2_y -= 3;
				r3_y -= 3;
				r4_y -= 3;
				r5_y -= 3;
				r6_y -= 3;
				r7_y -= 3;
			}
			else
			{
				r1_y -= 1;
				r2_y -= 1;
				r3_y -= 1;
				r4_y -= 1;
				r5_y -= 1;
				r6_y -= 1;
				r7_y -= 1;
			}
		}
		DrawRectangle(r1_x,      r1_y+15, r1_w, r1_l, colors[GRAY]);
		DrawRectangle(r2_x - 37, r2_y, r2_w, r2_l, colors[BLUE]);
		DrawRectangle(r3_x - 33, r3_y - 15, r3_w, r3_l, colors[BLUE]);
		DrawRectangle(r4_x + 10, r4_y + 30, r4_w, r4_l, colors[BLUE]);
		DrawRectangle(r5_x - 7,  r5_y + 35, r5_w, r5_l, colors[BLUE]);
		DrawRectangle(r6_x + 18, r6_y+60 - 15, r6_w, r6_l, colors[GREEN]);
		DrawRectangle(r7_x + 18, r7_y+67- 15, r7_w, r7_l, colors[GREEN]);
	}
};
class FigtherPlan :public Vehicle
{
private:
	int tx1;
	int ty1;
	int tx2;
	int ty2;
	int tx3;
	int ty3;
public:
	FigtherPlan()
	{
		tx1 = GetRandInRange(100, 600);
		ty1 = GetRandInRange(100, 500);
		tx2 = tx1;
		ty2 = ty1 + 30;
		tx3 = tx1 + 45;
		ty3 = ty1 + 15;
		r1_x = tx1 + 40;
		r1_y = ty1 + 13;
		r1_l = 15;
		r1_w = 5;
		r2_x = tx1 - 18;
		r2_y = ty1 + 13;
		r2_l = 20;
		r2_w = 5;
	}
	virtual void changecenter(int x, int y) {
		tx1 = x;
		ty1 = y;
		tx2 = tx1;
		ty2 = ty1 + 30;
		tx3 = tx1 + 45;
		ty3 = ty1 + 15;
		r1_x = tx1 + 40;
		r1_y = ty1 + 13;
		r1_l = 15;
		r1_w = 5;
		r2_x = tx1 - 18;
		r2_y = ty1 + 13;
		r2_l = 20;
		r2_w = 5;
	}
	int getr1_x()
	{
		return tx1;
	}
	int getr1_y()
	{
		return ty1;
	}

	int getr4_x()
	{
		return r2_x + 35;
	}
	int getr4_y()
	{
		return r2_y - 20;
	}
	virtual void setr4_x(int a) {
		r2_x = a;
	}
	virtual void setr4_y(int a) {
		r2_y = a;
	}
	virtual int getcenterx() {
		return tx3 - 10;
	}
	virtual int getcentery() {


		return ty3;
	}
	virtual void left(int a)
	{
		if (a == 20)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				tx1 -= 30;
				tx2 -= 30;
				tx3 -= 30;
				r1_x -= 30;
				r2_x -= 30;
			}
			else if (screen2 == true)
			{
				tx1 -= 20;
				tx2 -= 20;
				tx3 -= 20;
				r1_x -= 20;
				r2_x -= 20;
			}
			else
			{
				tx1 -= 10;
				tx2 -= 10;
				tx3 -= 10;
				r1_x -= 10;
				r2_x -= 10;
			}
		}
		if (a == 60 || a == 100 || a == 140)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				tx1 -= 5;
				tx2 -= 5;
				tx3 -= 5;
				r1_x -= 5;
				r2_x -= 5;
			}
			else if (screen2 == true)
			{
				tx1 -= 3;
				tx2 -= 3;
				tx3 -= 3;
				r1_x -= 3;
				r2_x -= 3;
			}
			else
			{
				tx1 -= 1;
				tx2 -= 1;
				tx3 -= 1;
				r1_x -= 1;
				r2_x -= 1;
			}

		}
		DrawTriangle(tx1, ty1, tx2, ty2, tx3 - (2 * (tx3 - tx1)), ty3, colors[GRAY]);
		DrawRectangle(r1_x - 40, r1_y, r1_l, r1_w, colors[YELLOW]);
		DrawRectangle(r2_x - 40, r2_y, r2_l, r2_w, colors[YELLOW]);
	}
	virtual void right(int a)
	{
		if (a == 40)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				tx1 += 30;
				tx2 += 30;
				tx3 += 30;
				r1_x += 30;
				r2_x += 30;

			}
			else if (screen2 == true)
			{
				tx1 += 20;
				tx2 += 20;
				tx3 += 20;
				r1_x += 20;
				r2_x += 20;

			}
			else
			{
				tx1 += 10;
				tx2 += 10;
				tx3 += 10;
				r1_x += 10;
				r2_x += 10;

			}
		}
		if (a == 80 || a == 160 || a == 120)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				tx1 += 5;
				tx2 += 5;
				tx3 += 5;
				r1_x += 5;
				r2_x += 5;

			}
			else if (screen2 == true)
			{
				tx1 += 3;
				tx2 += 3;
				tx3 += 3;
				r1_x += 3;
				r2_x += 3;

			}
			else
			{
				tx1 += 1;
				tx2 += 1;
				tx3 += 1;
				r1_x += 1;
				r2_x += 1;

			}
		}
		DrawTriangle(tx1, ty1, tx2, ty2, tx3, ty3, colors[GRAY]);
		DrawRectangle(r1_x, r1_y, r1_l, r1_w, colors[YELLOW]);
		DrawRectangle(r2_x, r2_y, r2_l, r2_w, colors[YELLOW]);
	}
	virtual void top(int a)
	{

		if (a == 10)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				ty1 += 30;
				r1_y += 30;
				r2_y += 30;
				ty2 += 30;
				ty3 += 30;
			}
			else if (screen2 == true)
			{
				ty1 += 20;
				r1_y += 20;
				r2_y += 20;
				ty2 += 20;
				ty3 += 20;
			}
			else
			{
				ty1 += 10;
				r1_y += 10;
				r2_y += 10;
				ty2 += 10;
				ty3 += 10;
			}
		}
		if (a == 50 || a == 90 || a == 130)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				ty1 += 5;
				r1_y += 5;
				r2_y += 5;
				ty2 += 5;
				ty3 += 5;
			}
			else if (screen2 == true)
			{
				ty1 += 3;
				r1_y += 3;
				r2_y += 3;
				ty2 += 3;
				ty3 += 3;
			}
			else
			{
				ty1 += 1;
				r1_y += 1;
				r2_y += 1;
				ty2 += 1;
				ty3 += 1;
			}
		}
		DrawTriangle(tx1, ty1, tx2 + (ty2 - ty1), ty1, (tx1 + tx2 + (ty2 - ty1)) / 2, ty1 + (tx3 - tx2), colors[GRAY]);
		DrawRectangle(r1_x - r1_l - 12, r1_y + r2_w + 20, r1_w, r1_l, colors[YELLOW]);
		DrawRectangle(r2_x + r1_l + 15, r2_y - r2_w - 25, r2_w, r2_l, colors[YELLOW]);
	}
	virtual void bottom(int a)
	{
		if (a == 30)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				ty1 -= 30;
				r1_y -= 30;
				r2_y -= 30;
				ty2 -= 30;
				ty3 -= 30;
			}
			else if (screen2 == true)
			{
				ty1 -= 20;
				r1_y -= 20;
				r2_y -= 20;
				ty2 -= 20;
				ty3 -= 20;
			}
			else
			{
				ty1 -= 10;
				r1_y -= 10;
				r2_y -= 10;
				ty2 -= 10;
				ty3 -= 10;

			}
		}
		if (a == 70 || a == 110 || a == 150)
		{
			if (screen3 == true || boost1control==true || boost2control==true)
			{
				ty1 -= 5;
				r1_y -= 5;
				r2_y -= 5;
				ty2 -= 5;
				ty3 -= 5;
			}
			else if (screen2 == true)
			{
				ty1 -= 3;
				r1_y -= 3;
				r2_y -= 3;
				ty2 -= 3;
				ty3 -= 3;
			}
			else
			{
				ty1 -= 1;
				r1_y -= 1;
				r2_y -= 1;
				ty2 -= 1;
				ty3 -= 1;

			}
		}
		DrawTriangle(tx1, ty1, tx2 + (ty2 - ty1), ty1, (tx1 + tx2 + (ty2 - ty1)) / 2, (ty1 + (tx3 - tx2)) - (2 * ((ty1 + (tx3 - tx2)) - ty1)), colors[GRAY]);
		DrawRectangle(r1_x - r1_l - 12, r1_y + r2_w + 20 - 40, r1_w, r1_l, colors[YELLOW]);
		DrawRectangle(r2_x + r1_l + 16, r2_y - r2_w - 25 - 40, r2_w, r2_l, colors[YELLOW]);

	}
};
