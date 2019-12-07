/*
 * Line.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line : public Shape
{
	public:
        // Constructor
        Line(QPaintDevice* device, int id,
        		QColor xPenColor,
                qreal              xPenWidth,
                Qt::PenStyle       xPenStyle,
                Qt::PenCapStyle    xPenCapStyle,
                Qt::PenJoinStyle   xPenJoinStyle,
                ) : Shape{ device, id, ShapeType::Line}
        {
	        pen.setColor(xPenColor);
	        pen.setWidth(xPenWidth);
	        pen.setStyle(xPenStyle);
	        pen.setCapStyle(xPenCapStyle);
	        pen.setJoinStyle(xPenJoinStyle);
        }

        // Destructor
        ~Line() override
        { }


		void set_point(const QPoint& point_begin, const QPoint& point_end);
		void draw(const int translate_x =0, const int translate_y = 0) override;
	private:
		vector<QPoint> points;

};


void Line::set_point(const QPoint& point_begin, const QPoint& point_end)
{
    points.clear();
    points.push_back(point_begin);
    points.push_back(point_end);
}

void Line::draw(const int translate_x, const int translate_y)
{
    qpainter.drawLine(points.at(0), points.at(1));
}


#endif /* LINE_H_ */
