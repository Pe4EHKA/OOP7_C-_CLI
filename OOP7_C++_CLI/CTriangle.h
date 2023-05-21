#pragma once
#include "CShape.h"

ref class CTriangle : public CShape {
private:
	int m_x;
	int m_y;
	int sideLength = 20;
	bool select;
	Color color_;
	cli::array<Point>^ vertices = gcnew cli::array<Point>(3);

	void getVertices();
public:
	CTriangle() : m_x(0), m_y(0) {}
	CTriangle(int x, int y) : m_x(x), m_y(y) {}
	virtual void draw(Pen^ penSelect, SolidBrush^ brush, Graphics^ g) override;
	virtual void setColor(Color color) override;
	virtual void changeSize(int dsize) override;

	virtual void moveX(int dx, int beginForm, int endForm) override;
	virtual void moveY(int dy, int beginForm, int endForm) override;
	virtual void setX(int x) override;
	virtual void setY(int y) override;

	virtual void setSelect(bool set) override;
	virtual bool isSelected() override;

	virtual bool Contains(int x, int y) override;
	virtual CShape^ clone() override;
	
};

