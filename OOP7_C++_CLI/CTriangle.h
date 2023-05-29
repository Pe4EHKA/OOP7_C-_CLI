#pragma once
#include "CShape.h"

ref class CTriangle : public CShape {
private:
	cli::array<Point>^ vertices = gcnew cli::array<Point>(3);
	void getVertices();
public:
	CTriangle() {
		m_x = 0;
		m_y = 0;
	}
	CTriangle(int x, int y) {
		m_x = x;
		m_y = y;
	}
	virtual void draw(Graphics^ g) override;
	virtual void save(StreamWriter^ stream) override;
	virtual void load(StreamReader^ stream) override;

	virtual bool Contains(int x, int y) override;
	virtual CShape^ clone() override;
	
};

