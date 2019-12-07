/*
 * Polygon.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape
{
	public:
        // Constructor
        Polygon(QPaintDevice* device, int id,QColor xPenColor,
                qreal              xPenWidth,
                Qt::PenStyle       xPenStyle,
                Qt::PenCapStyle    xPenCapStyle,
                Qt::PenJoinStyle   xPenJoinStyle,
                QColor             xBrushColor,
                Qt::BrushStyle     xBrushStyle) : Shape{ device, id, ShapeType::Polygon, xPenColor,xPenWidth,xPenStyle,xPenCapStyle,xPenJoinStyle,xBrushColor,xBrushStyle}
        { }

        // Destructor
        ~Polygon() override
        { }

		void set_point(const QPoint& point);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
		float perimeter() override;
        float area() override;
	private:
        vector<QPoint> points;
};

void Polygon::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Polygon::draw(const int translate_x, const int translate_y)
{
    const int size = points.size();
    QPoint convertedArray[size];

    for (int i = 0; i < points.size(); i++)
       convertedArray[i] = points.at(i);

    qpainter.drawPolygon(convertedArray, points.size());
}

float Polygon::perimeter()
{
	float p = 0;
	QPoint tem = points[0];
	for(int i = 1; i< 4;i++)
	{
		p+= sqrt(pow((tem.x()-points[i].x()),2)+pow((tem.y()-points[i].y()),2))
		tem = points[i];
	}
	return p;

}

float Polygon::area()
{
	return 0.5*(points[0].x()*points[1].y()-points[1].x()*points[0].y()+points[1].x()*points[2].y()-points[2].x()*points[1].y()+points[2].x()*points[3].y()-points[3].x()*points[2].y()+points[3].x()*points[0].y()-points[0].x()*points[3].y());


}
#endif /* POLYGON_H_ */
