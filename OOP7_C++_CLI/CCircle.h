#pragma once
#include "CShape.h"

ref class CCircle : public CShape{
public:
	CCircle() { 
		m_x = 0;
		m_y = 0; 
	}
	CCircle(int x, int y) {
		m_x = x;
		m_y = y;
	}

	virtual void draw(Graphics^ g) override;
	virtual void save(StreamWriter^ stream) override;
	virtual void load(StreamReader^ stream) override;

	virtual bool Contains(int x, int y) override;
	virtual CShape^ clone() override;

};

