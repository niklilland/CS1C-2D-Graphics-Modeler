/*
 * Square.h
 *
 *  Created on: 2019Äê12ÔÂ10ÈÕ
 *      Author: Leon
 */

#ifndef SQUARE_H_
#define SQUARE_H_

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


class Square : public Shape2D
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Square(QPaintDevice* device,
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
             int                xSide);

    Square() = delete;
    Square& operator=(const Square&) = delete;  // Disallow copying
    Square(const Square&) = delete;
    ~Square();

    std::ostream& print(std::ostream& os) const;
    void draw(QPaintDevice* device);
    void move(QPoint &newUpperLeft);
    void update(void);
    double calcPerimeter() const;
    double calcArea() const;
};

Square::Square(QPaintDevice* device,
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
         int                xSide)
   : Shape2D(device, xId, shapeType::Square,
                  xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                  xBrushColor, xBrushStyle)
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    QPoint lr(xTopLeftX+xSide, xTopLeftY+xSide);
    lowerright = lr;
}

//! Destructor - simply free the object space
//!
//!
Square::~Square() {};

//! print - print limited information about derived instance for debugging
//!
//!
//!
//! \param os - output stream
//!
//! \return std::ostream&amp;
std::ostream& Square::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//!
//!
//! \param device
void Square::draw(QPaintDevice* device)
{
    QRect rect1(upperleft, lowerright);
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    paint.setBrush(brush);
    paint.drawRect(rect1);
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}

//! move - relocate square to new upper left coordinate
//!
//!
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Square::move(QPoint &newUpperLeft)
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
void Square::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//!
//!
//! \return double
double Square::calcPerimeter() const
{
    return ( ((lowerright.x()-upperleft.x()) * 2) + ((lowerright.y()-upperleft.y()) * 2));
}

//! calcArea - determine area enclosed by object
//!
//!
//!
//! \return double
double Square::calcArea() const
{
    return ( (lowerright.x()-upperleft.x()) * (lowerright.y()-upperleft.y()));
}

#endif /* SQUARE_H_ */
