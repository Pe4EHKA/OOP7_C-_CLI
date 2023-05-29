#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Drawing;

public interface class Shape {

	virtual void draw(Graphics^ g);
	virtual void setColor(Color color);
	virtual void changeSize(int dsize, Point^ beginForm, Point^ endForm);
	virtual void moveX(int dx, int beginForm, int endForm);
	virtual void moveY(int dy, int beginForm, int endForm);
	virtual bool possibleMoveX(int dx, int beginForm, int endForm);
	virtual bool possibleMoveY(int dy, int beginForm, int endForm);


	virtual bool Contains(int x, int y);
	virtual void save(StreamWriter^ stream);
};