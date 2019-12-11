/*
 * PolyLine.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef POLYLINE_H_
#define POLYLINE_H_

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

class PolyLine : public Shape1D
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.

    // Constructor used in class project
    PolyLine(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             const std::vector<QPoint> &xPoints);

    PolyLine() = delete;
    PolyLine& operator=(const PolyLine&) = delete;  // Disallow copying
    PolyLine(const PolyLine&) = delete;
    ~PolyLine();

    std::ostream& print(std::ostream& os) const;
    void draw(QPaintDevice* device);
    void move(QPoint &newUpperLeft);
    void update(void);
    double calcPerimeter() const;
    double calcArea() const;
};

PolyLine::PolyLine(QPaintDevice* device,
         int                xId,
         QColor             xPenColor,
         qreal              xPenWidth,
         Qt::PenStyle       xPenStyle,
         Qt::PenCapStyle    xPenCapStyle,
         Qt::PenJoinStyle   xPenJoinStyle,
         const std::vector<QPoint> &xPoints)
   : Shape1D(device, xId, shapeType::Polyline,
                  xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle)
{
   // object specific transform from points supplied to bounding points
    qreal minX = 0.0;
    qreal maxX = 0.0;
    qreal minY = 0.0;
    qreal maxY = 0.0;

    points = xPoints;

    for(std::vector<QPoint>::iterator i=points.begin();i!=points.end()-1;++i)
    {
        if (i->x() < minX)
        {
            minX = i->x();
        }
        if (i->x() > maxX)
        {
            maxX = i->x();
        }

        if (i->y() < minY)
        {
            minY = i->y();
        }
        if (i->y() > maxY)
        {
            maxY = i->y();
        }
    }

    upperleft.setX(minX);
    upperleft.setY(minY);
    lowerright.setX(maxX);
    lowerright.setY(maxY);
}

//! Destructor - simply free the object space
//!
//! \author edt (5/13/18)
PolyLine::~PolyLine() {};

//! print - print limited information about derived instance for debugging
//!
//! \author edt (5/13/18)
//!
//! \param os - output stream
//!
//! \return std::ostream&amp;
std::ostream& PolyLine::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//! \author edt (5/13/18)
//!
//! \param device
void PolyLine::draw(QPaintDevice* device)
{
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    const QPoint *qpptr = &(*points.begin());
    paint.drawPolyline(qpptr,points.size());
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}

//! move - relocate line to new upper left coordinate
//!
//! \author edt (5/13/18)
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void PolyLine::move(QPoint &newUpperLeft)
{
    int deltaX = (newUpperLeft.x() - upperleft.x());
    int deltaY = (newUpperLeft.y() - upperleft.y());

    upperleft = newUpperLeft;
    lowerright.setX(lowerright.x() + deltaX);
    lowerright.setY(lowerright.y() + deltaY);

    for(vector<QPoint>::iterator i=points.begin();i!=points.end()-1;++i)
    {
        i->setX(i->x() + deltaX);
        i->setY(i->y() + deltaY);
    }
}

//! update - force redraw of object
//!
//! \author edt (5/13/18)
//!
//! \param void
void PolyLine::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//! \author edt (5/13/18)
//!
//! \return double
double PolyLine::calcPerimeter() const
{
    return 0;
}

//! calcArea - determine area enclosed by object
//!
//! \author edt (5/13/18)
//!
//! \return double
double PolyLine::calcArea() const
{
    return 0;
}


#endif /* POLYLINE_H_ */
