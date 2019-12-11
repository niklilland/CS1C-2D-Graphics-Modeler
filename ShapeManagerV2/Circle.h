/*
 * Circle.h
 *
 *  Created on: 2019Äê12ÔÂ10ÈÕ
 *      Author: Leon
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
#include "Shape.h"
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

class Circle : public Shape2D
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Circle(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             QColor             xBrushColor,
             Qt::BrushStyle     xBrushStyle,
             int                xTopLeftX,
             int                xTopLeftY,
             int                xDiameter);

    Circle() = delete;         // default constructor never used
    Circle& operator=(const Circle&) = delete;  // Disallow copying
    Circle(const Circle&) = delete;
    ~Circle();

    std::ostream& print(std::ostream& os) const;

    void draw(QPaintDevice* device) override;
    void move(QPoint &newUpperLeft) override;
    void update(void) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};

Circle::Circle(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             QColor             xBrushColor,
             Qt::BrushStyle     xBrushStyle,
             int                xTopLeftX,
             int                xTopLeftY,
             int                xDiameter)
       : Shape2D(device, xId, shapeType::Circle,
                      xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                      xBrushColor, xBrushStyle)
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    QPoint lr(xTopLeftX+xDiameter, xTopLeftY+xDiameter);
    lowerright = lr;
}

//! Destructor - simply free the object space
//!
//!
Circle::~Circle() {};

//! print - print limited information about derived instance for debugging
//!
//!
//!
//! \param os - output stream
//!
//! \return std::ostream&amp;
std::ostream& Circle::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//!
//!
//! \param device
void Circle::draw(QPaintDevice* device)
{
    QRect rect1(upperleft, lowerright);
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    paint.setBrush(brush);
    paint.drawEllipse(rect1);
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}

//! move - relocate circle to new upper left coordinate
//!
//!
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Circle::move(QPoint &newUpperLeft)
{
    int deltaX = (newUpperLeft.x() - upperleft.x());
    int deltaY = (newUpperLeft.y() - upperleft.y());

    upperleft = newUpperLeft;
    lowerright.setX(lowerright.x() + deltaX);
    lowerright.setY(lowerright.y() + deltaY);
}

//! update - force redraw of object
//!
//!
//!
//! \param void
void Circle::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//!
//!
//! \return double
double Circle::calcPerimeter() const
{
    return ( (M_PI) * (lowerright.x()-upperleft.x()) );
}

//! calcArea - determine area enclosed by object
//!
//!
//!
//! \return double
double Circle::calcArea() const
{
    return ( pow( ( (lowerright.x()-upperleft.x()) /2) ,2 ) * M_PI);
}

#endif /* CIRCLE_H_ */
