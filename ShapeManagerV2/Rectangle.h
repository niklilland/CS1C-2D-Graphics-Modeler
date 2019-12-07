/*
 * Rectangle.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape
{
	public:
        // Constructor
        Rectangle(QPaintDevice* device = nullptr,int id = -1) : Shape{ device, id, ShapeType::Rectangle }
        { }

        // Destructor
        ~Rectangle() override
        { }

		bool isSquare() const;
		void set_rect(const QRect& rect);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
		float perimeter() override;
        float area() override;
	private:
		QRect rect;
};

bool Rectangle::isSquare() const
{
    return rect.width()==rect.height();
}

void Rectangle::set_rect(const QRect& rect)
{
	this->rect = rect;
}

void Rectangle::draw(const int translate_x, const int translate_y)
{
    qpainter.drawRect(translate_x, translate_y, rect.width(), rect.height());
}

float Rectangle::perimeter()
{
	return (rect.width()*2+rect.length()*2);
}

float Rectangle::area()
{
	return (rect.witdth()*rect.length());
}
#endif /* RECTANGLE_H_ */
