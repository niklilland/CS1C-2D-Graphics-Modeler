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
        Rectangle(QPaintDevice* device ,int id, QColor xPenColor,
                qreal              xPenWidth,
                Qt::PenStyle       xPenStyle,
                Qt::PenCapStyle    xPenCapStyle,
                Qt::PenJoinStyle   xPenJoinStyle,
                QColor             xBrushColor,
                Qt::BrushStyle     xBrushStyle,
				int                xTopLeftX,
				int                xTopLeftY,
				int                xWidth,
				int                xHeight) : Shape{ device, id, ShapeType::Rectangle}
   {
       pen.setColor(xPenColor);
       pen.setWidth(xPenWidth);
       pen.setStyle(xPenStyle);
       pen.setCapStyle(xPenCapStyle);
       pen.setJoinStyle(xPenJoinStyle);

       brush.setColor(xBrushColor);
       brush.setStyle(xBrushStyle);
       // object specific transform from points supplied to bounding points
       QPoint ul(xTopLeftX,xTopLeftY);
       upperleft = ul;
       QPoint lr(xTopLeftX+xWidth, xTopLeftY+xHeight);
       lowerright = lr;
       rect(upperleft, lowerright);
   }

        // Destructor
        ~Rectangle() override
        { }

		bool isSquare() const;
		void set_rect(const QRect& rect);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
		float perimeter() override;
        float area() override;
	private:
        QPoint upperleft;   ///< Lower right anchor for bounding rectangle
        QPoint lowerright;  ///< vector containing endpints and vertices of line objects
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
	qpainter.begin(device);
    qpainter.drawRect(translate_x, translate_y, rect.width(), rect.height());
    qpainter.end();
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
