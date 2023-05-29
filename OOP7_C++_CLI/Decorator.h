#pragma once
#include "Shape.h"
#include "CShape.h"
#include "Composite.h"

// Динамическое добавление новых функциональных возможностей объектов
// без изменения их основной структуры.
ref class Decorator : public Shape {
private:
	Shape^ m_shape;
	Pen^ selectPen;
public:
	Decorator(Shape^ shape) : m_shape(shape) {
		selectPen = gcnew Pen(Color::Black, 1.0f);
	}

	virtual void draw(Graphics^ g);
	virtual void setColor(Color color);
	virtual void changeSize(int dsize, Point^ beginForm, Point^ endForm);

	virtual void moveX(int dx, int beginForm, int endForm);
	virtual void moveY(int dy, int beginForm, int endForm);
	virtual bool possibleMoveX(int dx, int beginForm, int endForm);
	virtual bool possibleMoveY(int dy, int beginForm, int endForm);

	void setSelectColor(Color color);
	Shape^ getShape();

	virtual bool Contains(int x, int y);
	virtual void save(StreamWriter^ stream);

};

