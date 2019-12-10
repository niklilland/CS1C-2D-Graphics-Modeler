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
        Shape(QPaintDevice* device, int id, ShapeType shape): qpainter{device}, device{device}, shape{shape}, shapeID{id} { }

        // destructor
        virtual ~Shape() = 0;
		
		ShapeType getShape() const;
		const QPen& getPen() const;
		const QBrush& getBrush() const;
		
		void setShape(ShapeType shape);
        void setPen(QColor,int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
        void setPen(QColor);
        void setBrush(QColor, Qt::BrushStyle);
		
		
        // pure virtual funstions:
        virtual void draw(const int translate_x,const int translate_y) = 0; // TODO: How are translate_x and translate_y used?
		virtual void move(const int x,const int y) = 0;
		virtual float perimeter() = 0;
        virtual float area() = 0;
	
	protected:
		QPainter& getQpainter();
        QPainter qpainter;
        QPaintDevice *device;  ///< QPainter variable - responsible for the drawing of the shapes in the viewing area

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
    return pen;
}

const QBrush& Shape::getBrush() const
{
    return brush;
}

void Shape::setShape(ShapeType s)
{
    shape = s;
}

void Shape::setPen(QColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cstyle, Qt::PenJoinStyle jstyle)
{
	pen.setColor(color);
	pen.setWidth(width);
	pen.setStyle(style);
	pen.setCapStyle(cstyle);
	pen.setJoinStyle(jstyle);
}

void Shape::setPen(QColor color)
{
    pen.setColor(color);
}

void Shape::setBrush(QColor color, Qt::BrushStyle style)
{
    brush.setColor(color);
    brush.setStyle(style);
}

#endif /* SHAPE_H_ */

