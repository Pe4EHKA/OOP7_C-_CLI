#include "CSquare.h"

void CSquare::draw(Pen^ penSelect, SolidBrush^ brush, Graphics^ g)
{
	int cornerX = m_x - sideLength / 2;
	int cornerY = m_y - sideLength / 2;
	if (select == true) {
		penSelect->Color = Color::Black;
		g->DrawRectangle(penSelect, cornerX - 3, cornerY - 3, sideLength + 5, sideLength + 5);
	}
	else {
		penSelect->Color = color_;
	}
	brush->Color = color_;
	g->FillRectangle(brush, cornerX, cornerY, sideLength, sideLength);
}

void CSquare::setColor(Color color)
{
	if (select) {
		color_ = color;
	}
}

void CSquare::changeSize(int dsize)
{
	if (sideLength + dsize > 0) {
		sideLength += dsize;
	}
}

void CSquare::moveX(int dx, int beginForm, int endForm)
{
	if (m_x - sideLength / 2 + dx < beginForm) {
		m_x = beginForm + sideLength / 2;
	}
	else if (m_x + sideLength / 2 + dx > endForm) {
		m_x = endForm - sideLength / 2;
	}
	else {
		m_x += dx;
	}
}

void CSquare::moveY(int dy, int beginForm, int endForm)
{
	if (m_y - sideLength / 2 + dy < beginForm) {
		m_y = beginForm + sideLength / 2;
	}
	else if (m_y + sideLength / 2 + dy > endForm) {
		m_y = endForm - sideLength / 2;
	}
	else {
		m_y += dy;
	}
}

void CSquare::setX(int x)
{
	m_x = x;
}

void CSquare::setY(int y)
{
	m_y = y;
}

void CSquare::setSelect(bool set)
{
	select = set;
}

bool CSquare::isSelected()
{
	return select;
}

bool CSquare::Contains(int x, int y)
{
	return (m_x - sideLength / 2 < x) && (m_x + sideLength / 2 > x) && (m_y - sideLength / 2 < y) && (m_y + sideLength / 2 > y);
}

CShape^ CSquare::clone()
{
	return gcnew CSquare();
}


