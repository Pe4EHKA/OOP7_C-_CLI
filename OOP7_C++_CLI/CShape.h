#pragma once
using namespace System;
using namespace System::Drawing;

ref class CShape abstract{
public:

	virtual void draw(Pen^ penSelect, SolidBrush^ brush, Graphics^ g) abstract;
	virtual void setColor(Color color) abstract;
	virtual void changeSize(int dsize) abstract;

	virtual void moveX(int dx, int beginForm, int endForm) abstract;
	virtual void moveY(int dy, int beginForm, int endForm) abstract;
	virtual void setX(int x) abstract;
	virtual void setY(int y) abstract;

	virtual void setSelect(bool set) abstract;
	virtual bool isSelected() abstract;

	virtual bool Contains(int x, int y) abstract;
	virtual CShape^ clone() abstract;
};