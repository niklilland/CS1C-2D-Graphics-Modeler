/*
 * Rectangle.h
 *
 *  Created on: 2019Äê12ÔÂ4ÈÕ
 *      Author: Leon
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape
{
	public:
		Rectangle(QPaintDevice* device = nullptr,int id = -1) : Shape{device, id, ShapeType::Rectangle}{}
		~Rectangle() override{}
		bool isSquare() const;
		void set_rect(const QRect& rect);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
	private:
		QRect rect;
};

bool Rectangle::isSquare() const
{
	return rect.width()==rect.length();
}

void Rectangle::set_rect(const QRect& rect)
{
	this->rect = rect;
}

void Rectangle::draw(const int translate_x = 0, const int translate_y = 0)
{
	qpainter.drawRect(rect);
}
#endif /* RECTANGLE_H_ */
