#pragma once
#include "Shape.h"
using namespace System;
using namespace System::Drawing;

ref class CShape : public Shape {
protected:
	int m_x;
	int m_y;
	int sideLength = 20;
	Color color_;
	SolidBrush^ brush = gcnew SolidBrush(Color::Black);

public:

	virtual void draw(Graphics^ g) abstract;
	virtual void setColor(Color color) override;
	virtual void changeSize(int dsize, Point^ beginForm, Point^ endForm) override;
	virtual bool canChangeSizexy(int dsize, Point^ beginForm, Point^ endForm);
	virtual void moveX(int dx, int beginForm, int endForm) override;
	virtual void moveY(int dy, int beginForm, int endForm) override;
	virtual bool possibleMoveX(int dx, int beginForm, int endForm) override;
	virtual bool possibleMoveY(int dy, int beginForm, int endForm) override;


	virtual bool Contains(int x, int y) abstract;
	virtual void save(StreamWriter^ stream) abstract;
	virtual void load(StreamReader^ stream) abstract;
	virtual CShape^ clone() abstract;

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getSideLength();




};