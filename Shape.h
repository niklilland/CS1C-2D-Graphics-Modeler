/*
 * Shape.h
 *
 *  Created on: 2019Äê11ÔÂ7ÈÕ
 *      Author: Leon
 */

#ifndef SHAPE_H_
#define SHAPE_H_


#include <iostream>
#include <iomanip>
#include <QPainter>

using namespace std;

enum class ShapeType{
	Line, Polyline, Polygon, Rectangle, Ellipse, Text
};



class Shape
{
	public:
		Shape();//constructor
		virtual ~Shape();//destructor
		//pure virtual funstions:
		virtual void draw(const int translate_x,const int translate_y) = 0;
		virtual void move(const int x,const int y) = 0;
		virtual float perimeter() = 0;
		virtual float area() = 0; 
	private:
		int shapeID;		
		QPainter qpainter;
		ShapeType shape;
		QPen pen;
		QBrush brush;
};




#endif /* SHAPE_H_ */
