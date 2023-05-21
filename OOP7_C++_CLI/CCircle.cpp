#include "CCircle.h"

void CCircle::draw(Pen^ penSelect, SolidBrush^ brush, Graphics^ g)
{
	if (select == true) {
		penSelect->Color = Color::Black;
		g->DrawRectangle(penSelect, m_x - radius_, m_y - radius_, radius_ * 2, radius_ * 2);
	}
	else {
		penSelect->Color = color_;
	}
	brush->Color = color_;
	g->FillEllipse(brush, m_x - radius_, m_y - radius_, radius_ * 2, radius_ * 2);
	
}

void CCircle::setColor(Color color)
{
	if (select) {
		color_ = color;
	}
}

void CCircle::changeSize(int dsize)
{
	if (radius_ + dsize > 0) {
		radius_ += dsize;
	}
}

void CCircle::moveX(int dx, int beginForm, int endForm)
{
	if (m_x - radius_ + dx < beginForm) {
		m_x = beginForm + radius_;
	}
	else if (m_x + radius_ + dx > endForm) {
		m_x = endForm - radius_;
	}
	else {
		m_x += dx;
	}
}

void CCircle::moveY(int dy, int beginForm, int endForm)
{
	if (m_y - radius_ + dy < beginForm) {
		m_y = beginForm + radius_;
	}
	else if (m_y + radius_ + dy > endForm) {
		m_y = endForm - radius_;
	}
	else {
		m_y += dy;
	}
}

void CCircle::setX(int x)
{
	m_x = x;
}

void CCircle::setY(int y)
{
	m_y = y;
}

void CCircle::setSelect(bool set)
{
	select = set;
}

bool CCircle::isSelected()
{
	return select;
}

bool CCircle::Contains(int x, int y)
{
	return (x - m_x) * (x - m_x) + (y - m_y) * (y - m_y) <= radius_ * radius_;
}

CShape^ CCircle::clone()
{
	return gcnew CCircle();
}
