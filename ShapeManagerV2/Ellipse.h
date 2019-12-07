/*
 * Ellipse.h
 *
 *  Created on: 2019
 *
 *  Author: Leon
 */

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

class Ellipse : public Shape
{
	public:
        // constructor
        Ellipse(QPaintDevice* device, int id) : Shape{device, id, ShapeType::Ellipse}
        { }
        ~Ellipse() override
        { }

		bool isCircle() const;
		void set_rect(const QRect& rect);
        void draw(const int translate_x = 0, const int translate_y = 0) override;
		float perimeter() override;
        float area() override;
	private:
        QRect rect;
};

bool Ellipse::isCircle() const
{
    return rect.width() == rect.height();
}

void Ellipse::set_rect(const QRect& rect)
{
    this->rect = rect;
}

void Ellipse::draw(const int translate_x, const int translate_y)
{
    qpainter.drawEllipse(translate_x, translate_y, rect.width(), rect.height());
}

float Ellipse::perimeter()
{
	return 2*3.14 * sqrt( (pow(0.5*rect.width(),2) + pow(0.5*rect.length(),2)) / 2 );
}

float Ellipse::area()
{
	return 3.14 *0.5*(rect.width()) *0.5*rect.length() ;
}
#endif /* ELLIPSE_H_ */
