#include "CTriangle.h"

void CTriangle::getVertices()
{
	// Левый нижний угол
	Point a = Point(m_x - sideLength / 2, m_y + sideLength / 2);
	vertices[0] = a;
	// Верхний угол
	Point b = Point(m_x, m_y - sideLength / 2);
	vertices[1] = b;
	// Правый нижний угол
	Point c = Point(m_x + sideLength / 2, m_y + sideLength / 2);
	vertices[2] = c;
}

void CTriangle::draw(Pen^ penSelect, SolidBrush^ brush, Graphics^ g)
{
	getVertices();
	if (select == true) {
		penSelect->Color = Color::Black;
		g->DrawRectangle(penSelect, vertices[0].X - 3, vertices[1].Y - 3, sideLength + 5, sideLength + 5);
	}
	else {
		penSelect->Color = color_;
	}
	brush->Color = color_;
	g->FillPolygon(brush, vertices);
}

void CTriangle::setColor(Color color)
{
	if (select) {
		color_ = color;
	}
}

void CTriangle::changeSize(int dsize)
{
	if (sideLength + dsize > 0) {
		sideLength += dsize;
	}
}

void CTriangle::moveX(int dx, int beginForm, int endForm)
{
	getVertices();
	if (vertices[0].X + dx < beginForm) {
		m_x = beginForm + sideLength / 2;
	}
	else if (vertices[2].X + dx > endForm) {
		m_x = endForm - sideLength / 2;
	}
	else {
		m_x += dx;
	}
}

void CTriangle::moveY(int dy, int beginForm, int endForm)
{
	getVertices();
	if (vertices[1].Y + dy < beginForm) {
		m_y = beginForm + sideLength / 2;
	}
	else if (vertices[2].Y + dy > endForm || vertices[0].Y + dy > endForm) {
		m_y = endForm - sideLength / 2;
	}
	else {
		m_y += dy;
	}
}

void CTriangle::setX(int x)
{
	m_x = x;
}

void CTriangle::setY(int y)
{
	m_y = y;
}

void CTriangle::setSelect(bool set)
{
	select = set;
}

bool CTriangle::isSelected()
{
	return select;
}

bool CTriangle::Contains(int x, int y)
{
	getVertices();
	float x1 = vertices[0].X;
	float y1 = vertices[0].Y;
	float x2 = vertices[1].X;
	float y2 = vertices[1].Y;
	float x3 = vertices[2].X;
	float y3 = vertices[2].Y;

	// Подход, известный как "тест трех точек" или "тест барицентрических координат". 
	// Данный подход использует линейную интерполяцию 
	// между вершинами треугольника и проверяет, 
	// лежит ли точка внутри треугольника или снаружи него.
	float alpha = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) /
		((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));

	float beta = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) /
		((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));

	float gamma = 1.0f - alpha - beta;

	return (alpha > 0 && beta > 0 && gamma > 0);
}

CShape^ CTriangle::clone()
{
	return gcnew CTriangle();
}
