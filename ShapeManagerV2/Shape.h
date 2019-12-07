/*
 * Shape.h
 *
 *  Created on: 2019��11��7��
 *      Author: Leon
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <iomanip>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>

using namespace std;

enum ShapeType{ Line, Polyline, Polygon, Rectangle, Ellipse, Text };

class Shape
{
	public:
        // constructor
        Shape(QPaintDevice* device, int id, ShapeType shape, QColor xPenColor,
                qreal              xPenWidth,
                Qt::PenStyle       xPenStyle,
                Qt::PenCapStyle    xPenCapStyle,
                Qt::PenJoinStyle   xPenJoinStyle,
                QColor             xBrushColor,
                Qt::BrushStyle     xBrushStyle): device{device}, shapeId{xId}, typeShape{s}, painter{device} {


	        pen.setColor(xPenColor);
	        pen.setWidth(xPenWidth);
	        pen.setStyle(xPenStyle);
	        pen.setCapStyle(xPenCapStyle);
	        pen.setJoinStyle(xPenJoinStyle);

	        brush.setColor(xBrushColor);
	        brush.setStyle(xBrushStyle);
        }
        // destructor
        virtual ~Shape() = 0;
		
		ShapeType getShape() const;
		const QPen& getPen() const;
		const QBrush& getBrush() const;
		
		void setShape(ShapeType shape);
        void setPen(Qt::GlobalColor,int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
		void setPen(Qt::GlobalColor);
        void setBrush(Qt::GlobalColor, Qt::BrushStyle);
		
		
        // pure virtual funstions:
        virtual void draw(const int translate_x,const int translate_y) = 0; // TODO: How are translate_x and translate_y used?
		virtual void move(const int x,const int y) = 0;
		virtual float perimeter() = 0;
        virtual float area() = 0;
	
	protected:
		QPainter& getQpainter();
        QPainter qpainter;
		
	private:
        ShapeType shape;
        int shapeID;
		QPen pen;
		QBrush brush;
};

ShapeType Shape::getShape() const
{
	return shape;
}

const QPen& Shape::getPen() const
{
	return qpen;
}

const QBrush& Shape::getBrush() const
{
	return qbrush;
}

void Shape::setShape(ShapeType s)
{
    shape = s;
}

void Shape::setPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cstyle, Qt::PenJoinStyle jstyle)
{
	pen.setColor(color);
	pen.setWidth(width);
	pen.setStyle(style);
	pen.setCapStyle(cstyle);
	pen.setJoinStyle(jstyle);
}

void Shape::setPen(Qt::GlobalColor color)
{
    pen.setColor(color);
}

void Shape::setBrush(Qt::GlobalColor color, Qt::BrushStyle style)
{
    brush.setColor(color);
    brush.setStyle(style);
}

#endif /* SHAPE_H_ */

