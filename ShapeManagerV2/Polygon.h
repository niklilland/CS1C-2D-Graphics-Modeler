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
        Polygon(QPaintDevice* device, int id) : Shape{ device, id, ShapeType::Polygon }
        { }

        // Destructor
        ~Polygon() override
        { }

		void set_point(const QPoint& point);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
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


#endif /* POLYGON_H_ */
