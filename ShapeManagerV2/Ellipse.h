/*
 * Ellipse.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

class Ellipse : public Shape
{
	public:
		Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse}{}
		~Ellipse() override{}

		bool isCircle() const;
		void set_rect(const QRect& rect);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
	private:
		QRect rect;
};

bool Ellipse::isCircle() const
{
	return rect.width()==rect.length();
}

void Ellipse::set_rect(const QRect& rect)
{
	this.rect = rect;
}

void Ellipse::draw(const int translate_x = 0, const int translate_y = 0)
{
	qpainter.drawEllipse(rect);
}
#endif /* ELLIPSE_H_ */
