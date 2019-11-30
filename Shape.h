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

using namespace std;

enum class ShapeType{
		Line, Polyline, Polygon, Rectangle, Ellipse, Text, NoShape
		};

class Shape
{
	public:
	    
		Shape(QPaintDevice* device = nullptr,int id = -1, ShapeType shape = NoShape);//constructor
		virtual ~Shape(){};//destructor
		
		ShapeType getShape() const;
		const QPen& getPen() const;
		const QBrush& getBrush() const;
		
		void setShape(ShapeType shape);
		void setPen(Qt::GlobalColor,int width,Qt::Penstyle,Qt::PenCapStyle,Qt::PenJoinStyle);
		void setPen(Qt::GlobalColor);
		void setBrush(Qt::GlobalColor,Qt::BrushStyle);
		
		
		//pure virtual funstions:
		virtual void draw(const int translate_x,const int translate_y) = 0;
		virtual void move(const int x,const int y) = 0;
		virtual float perimeter() = 0;
		virtual float area() = 0; 
	
	protected:
		QPainter& getQpainter();
		
	private:
		int shapeID;		
		QPainter qpainter;
		ShapeType shape;
		QPen qpen;
		QBrush qbrush;
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

void Shape::setBrush(Qt::GlobalColor color,Qt::BrushStyle style)
{
	qbrush.setColor(color);
	qbrush.setStyle(style);
}

void Shape::setPen(Qt::GlobalColor color,int width,Qt::Penstyle style,Qt::PenCapStyle cstyle,Qt::PenJoinStyle jstyle)
{
	qpen.setColor(color);
	qpen.setWidth(width);
	qpen.setStyle(style);
	qpen.setCapStyle(cstyle);
	qpen.setJoinStyle(jstyle);
}

void Shape::setPen(Qt::GlobalColor color)
{
	qpen.setColor(color);
}

void Shape::setShape(ShapeType s)
{
	shape = s;
}
#endif /* SHAPE_H_ */

