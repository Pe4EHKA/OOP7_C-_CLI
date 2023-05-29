#include "CTriangle.h"

void CTriangle::getVertices()
{
	Point a = Point(m_x - sideLength / 2, m_y + sideLength / 2); // Левый нижний угол
	vertices[0] = a;
	Point b = Point(m_x, m_y - sideLength / 2); // Верхний угол
	vertices[1] = b;
	Point c = Point(m_x + sideLength / 2, m_y + sideLength / 2); // Правый нижний угол
	vertices[2] = c;
}

void CTriangle::draw(Graphics^ g)
{
	getVertices();
	brush->Color = color_;
	g->FillPolygon(brush, vertices);
}

void CTriangle::save(StreamWriter^ stream)
{
	String^ saveString = "Triangle\n" + "X = " + m_x.ToString() + "\nY = " + m_y.ToString() +
		"\nsideLength = " + sideLength.ToString();
	stream->WriteLine(saveString);
	//  Cохраняем результат разделения строки цвета в массив colorParts 
	//  и получаем последний элемент с помощью colorParts->Length - 1.
	/*cli::array<String^>^ colorParts = color_.ToString()->Split(' ');
	String^ color = colorParts[colorParts->Length - 1]->Trim('[', ']');*/
	String^ color = color_.ToArgb().ToString();
	stream->WriteLine("Color = " + color);
}

void CTriangle::load(StreamReader^ stream)
{
	cli::array<String^>^ stats = gcnew cli::array<String^>(4);
	for (int i = 0; i < 4; ++i) {
		cli::array<String^>^ lineStat = stream->ReadLine()->Split(' ');
		stats[i] = lineStat[lineStat->Length - 1];
	}
	m_x = Int32::Parse(stats[0]);
	m_y = Int32::Parse(stats[1]);
	sideLength = Int32::Parse(stats[2]);
	//color_ = Color::FromName(stats[3]->Trim('[', ']'));
	color_ = Color::FromArgb(Int32::Parse(stats[3]));
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
