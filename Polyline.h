/*
 * PolyLine.h
 *
 *  Created on: 2019Äê12ÔÂ4ÈÕ
 *      Author: Leon
 */

#ifndef POLYLINE_H_
#define POLYLINE_H_

#include "Shape.h"
class Polyline : public Shape
{
	public:
	Polyline(QPaintDevice*device = nullptr,int id =-1) : Shape{device, id, ShapeType:: Polyline}{}
	~Polyline() override{}
	void set_point(const QPoint& point);
	void draw(const int translate_x = 0, const int translate_y = 0) override;
	private:
	vector<QPoint> points;
};


#endif /* POLYLINE_H_ */
