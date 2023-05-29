#pragma once
#include "CShape.h"

ref class CSquare : public CShape {
public:
	CSquare() {
		m_x = 0;
		m_y = 0;
	}
	CSquare(int x, int y) {
		m_x = x;
		m_y = y;
	}
	void draw(Graphics^ g) override;
	virtual void save(StreamWriter^ stream) override;
	virtual void load(StreamReader^ stream) override;

	bool Contains(int x, int y) override;
	virtual CShape^ clone() override;
};