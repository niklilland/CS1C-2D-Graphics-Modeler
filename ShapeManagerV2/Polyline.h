/*
 * PolyLine.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef POLYLINE_H_
#define POLYLINE_H_

#include "Shape.h"
class Polyline : public Shape
{
	public:
    // constructor
    Polyline(QPaintDevice*device = nullptr, int id =-1) : Shape { device, id, ShapeType:: Polyline }
    { }
    // destructor
    ~Polyline() override
    { }

	void set_point(const QPoint& point);
	void draw(const int translate_x = 0, const int translate_y = 0) override;

	private:
	vector<QPoint> points;
};

void Polyline::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Polyline::draw(const int translate_x, const int translate_y)
{
    const int size = points.size();
    QPoint convertedArray[size];

    for (int i = 0; i < points.size(); i++)
       convertedArray[i] = points.at(i);

    qpainter.drawPolyline(convertedArray, points.size());
}


#endif /* POLYLINE_H_ */
