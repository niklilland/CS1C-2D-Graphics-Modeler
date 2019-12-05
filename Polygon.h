/*
 * Polygon.h
 *
 *  Created on: 2019Äê12ÔÂ4ÈÕ
 *      Author: Leon
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape
{
	public:
		Polygon(QPaintDevie* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polygon}{}
		~Polygon() override{}
		void set_point(const QPoint& point);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
	private:
		vector<QPoint> points;
};


#endif /* POLYGON_H_ */
