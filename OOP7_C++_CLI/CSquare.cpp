#include "CSquare.h"

void CSquare::draw(Graphics^ g)
{
	int cornerX = m_x - sideLength / 2;
	int cornerY = m_y - sideLength / 2;
	brush->Color = color_;
	g->FillRectangle(brush, cornerX, cornerY, sideLength, sideLength);
}

void CSquare::save(StreamWriter^ stream)
{
	String^ saveString = "Square\n" + "X = " + m_x.ToString() + "\nY = " + m_y.ToString() +
		"\nsideLenght = " + sideLength.ToString();
	stream->WriteLine(saveString);
	//  Cохраняем результат разделения строки цвета в массив colorParts 
	//  и получаем последний элемент с помощью colorParts->Length - 1.
	/*cli::array<String^>^ colorParts = color_.ToString()->Split(' ');
	String^ color = colorParts[colorParts->Length - 1]->Trim('[', ']');*/
	String^ color = color_.ToArgb().ToString();
	stream->WriteLine("Color = " + color);
}

void CSquare::load(StreamReader^ stream)
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


bool CSquare::Contains(int x, int y)
{
	return (m_x - sideLength / 2 < x) && (m_x + sideLength / 2 > x) && (m_y - sideLength / 2 < y) && (m_y + sideLength / 2 > y);
}

CShape^ CSquare::clone()
{
	return gcnew CSquare();
}


