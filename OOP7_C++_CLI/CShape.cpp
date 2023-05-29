#include "CShape.h"

void CShape::setColor(Color color)
{
	this->color_ = color;
}

void CShape::changeSize(int dsize, Point^ beginForm, Point^ endForm)
{
	/*if (sideLength + dsize > 0 && possibleMoveX(dsize, 0, endFormX) 
		&& possibleMoveY(dsize, 0, endFormY)) {
		sideLength += dsize;
	}*/
	int tmpside = sideLength + dsize;
	if (tmpside > 0 && canChangeSizexy(dsize, beginForm, endForm)) {
		sideLength += dsize;
	}
}

bool CShape::canChangeSizexy(int dsize, Point^ beginForm, Point^ endForm)
{
	if (m_x - sideLength / 2 - dsize < beginForm->X) {
		return false;
	}
	else if (m_x + sideLength / 2 + dsize > endForm->X) {
		return false;
	}
	else if (m_y - sideLength / 2 - dsize < beginForm->Y) {
		return false;
	}
	else if (m_y + sideLength / 2 + dsize > endForm->Y) {
		return false;
	}
	return true;
}


void CShape::moveX(int dx, int beginForm, int endForm)
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

void CShape::moveY(int dy, int beginForm, int endForm)
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

bool CShape::possibleMoveX(int dx, int beginForm, int endForm)
{
	if (dx > 0 && (m_x + sideLength / 2 == endForm)) {
		return false;
	}
	else if (dx < 0 && (m_x - sideLength / 2 == beginForm)) {
		return false;
	}
	else {
		return true;
	}
}

bool CShape::possibleMoveY(int dy, int beginForm, int endForm)
{
	if (dy > 0 && (m_y + sideLength / 2 == endForm)) {
		return false;
	}
	else if (dy < 0 && (m_y - sideLength / 2 == beginForm)) {
		return false;
	}
	else {
		return true;
	}
}

int CShape::getX()
{
	return m_x;
}

int CShape::getY()
{
	return m_y;
}

void CShape::setX(int x)
{
	m_x = x;
}

void CShape::setY(int y)
{
	m_y = y;
}

int CShape::getSideLength()
{
	return sideLength;
}
