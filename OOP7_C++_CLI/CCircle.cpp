#include "CCircle.h"

void CCircle::draw(Graphics^ g)
{
	brush->Color = color_;
	g->FillEllipse(brush, m_x - sideLength / 2, m_y - sideLength / 2, sideLength, sideLength);
	
}

void CCircle::save(StreamWriter^ stream)
{
	String^ saveString = "Circle\n" + "X = " + m_x.ToString() + "\nY = " + m_y.ToString() +
		"\nRadius = " + (sideLength / 2).ToString();
	stream->WriteLine(saveString);
	//  Cохраняем результат разделения строки цвета в массив colorParts 
	//  и получаем последний элемент с помощью colorParts->Length - 1.
	
	/*cli::array<String^>^ colorParts = color_.ToString()->Split(' ');
	String^ color = colorParts[colorParts->Length - 1]->Trim('[', ']');*/
	String^ color = color_.ToArgb().ToString();
	stream->WriteLine("Color = " + color);
}

void CCircle::load(StreamReader^ stream)
{
	cli::array<String^>^ stats = gcnew cli::array<String^>(4);
	for (int i = 0; i < 4; ++i) {
		cli::array<String^>^ lineStat = stream->ReadLine()->Split(' ');
		stats[i] = lineStat[lineStat->Length - 1];
	}
	m_x = Int32::Parse(stats[0]);
	m_y = Int32::Parse(stats[1]);
	sideLength = Int32::Parse(stats[2]) * 2;
	//color_ = Color::FromName(stats[3]->Trim('[', ']'));
	color_ = Color::FromArgb(Int32::Parse(stats[3]));
}

bool CCircle::Contains(int x, int y)
{
	return (x - m_x) * (x - m_x) + (y - m_y) * (y - m_y) <= sideLength / 2 * sideLength / 2;
}

CShape^ CCircle::clone()
{
	return gcnew CCircle();
}
