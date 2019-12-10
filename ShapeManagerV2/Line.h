/*
 * Line.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class MyLine : public Shape
{
	public:
        // Constructor
        MyLine(QPaintDevice* paintDevice,
             int id,
             QColor xPenColor,
             qreal xPenWidth,
             Qt::PenStyle xPenStyle,
             Qt::PenCapStyle xPenCapStyle,
             Qt::PenJoinStyle xPenJoinStyle) : Shape{ paintDevice, id, ShapeType::Line}
        {
            setPen(xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle);
        }

        // Destructor
        ~MyLine() override
        { }


		void set_point(const QPoint& point_begin, const QPoint& point_end);
		void draw(const int translate_x =0, const int translate_y = 0) override;
        void move(const int x, const int y) override;
        float perimeter() override { return 0; }
        float area() override { return 0; }
	private:
		vector<QPoint> points;

};


void MyLine::set_point(const QPoint& point_begin, const QPoint& point_end)
{
    points.clear();
    points.push_back(point_begin);
    points.push_back(point_end);
}

void MyLine::draw(const int translate_x, const int translate_y)
{
    qpainter.drawLine(points.at(0), points.at(1));
}

void MyLine::move(const int x, const int y)
{
    // TODO: implementation
}


#endif /* LINE_H_ */
