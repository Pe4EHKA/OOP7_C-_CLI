#pragma once
#include "CShape.h"

ref class CSquare : public CShape {
private:
	int m_x;
	int m_y;
	int sideLength = 20;
	bool select;
	Color color_;
public:
	CSquare() : m_x(0), m_y(0) {}
	CSquare(int x, int y) : m_x(x), m_y(y) {}
	void draw(Pen^ penSelect, SolidBrush^ brush, Graphics^ g) override;
	void setColor(Color color) override;
	void changeSize(int dsize) override;

	void moveX(int dx, int beginForm, int endForm) override;
	void moveY(int dy, int beginForm, int endForm) override;
	void setX(int x) override;
	void setY(int y) override;

	void setSelect(bool set) override;
	bool isSelected() override;

	bool Contains(int x, int y) override;
	virtual CShape^ clone() override;
};