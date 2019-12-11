

#ifndef POLYGON_H_
#define POLYGON_H_

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

class Polygon : public Shape2D
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.
    //! points - vector containing 3 or more points describing
    //!          the vertices of the polygon
    vector<QPoint> points;

    // Constructor used in class project
    Polygon(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             QColor             xBrushColor,
             Qt::BrushStyle     xBrushStyle,
             const std::vector<QPoint> &xPoints);

    Polygon() = delete;
    Polygon& operator=(const Polygon&) = delete;  // Disallow copying
    Polygon(const Polygon&) = delete;
    ~Polygon();
;
    std::ostream& print(std::ostream& os) const;
    void draw(QPaintDevice* device);
    void move(QPoint &newUpperLeft);
    void update(void);
    double calcPerimeter() const;
    double calcArea() const;
};

Polygon::Polygon(QPaintDevice* device,
        int                xId,
        QColor             xPenColor,
        qreal              xPenWidth,
        Qt::PenStyle       xPenStyle,
        Qt::PenCapStyle    xPenCapStyle,
        Qt::PenJoinStyle   xPenJoinStyle,
        QColor             xBrushColor,
        Qt::BrushStyle     xBrushStyle,
        const std::vector<QPoint> &xPoints)
  : Shape2D(device, xId, shapeType::Polygon,
                 xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle,
                 xBrushColor, xBrushStyle), points{xPoints}
{
    // object specific transform from points supplied to bounding points

    qreal minX = 0.0;
    qreal maxX = 0.0;
    qreal minY = 0.0;
    qreal maxY = 0.0;

    for(vector<QPoint>::iterator i=points.begin();i!=points.end()-1;++i)
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
//!
Polygon::~Polygon() {};

//! print - print limited information about derived instance for debugging
//!
//!
std::ostream& Polygon::print(std::ostream& os) const
{
   return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
}

//! draw - output object onto QT canvas using QPaintDevice
//!
//!
//!
//! \param device
void Polygon::draw(QPaintDevice* device)
{
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    paint.setBrush(brush);
    const QPoint *qpptr = &(*points.begin());
    paint.drawPolygon(qpptr,points.size());
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}


//! move - relocate polygon to new upper left coordinate
//!
//!
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Polygon::move(QPoint &newUpperLeft)
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
//!
//!
//! \param void
void Polygon::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//!
//!
//! \return double
double Polygon::calcPerimeter() const
{
    double perimeter = 0;
    for(std::vector<QPoint>::const_iterator i=points.begin();i<points.end()-1;++i)
    {

        perimeter += sqrt((pow((i->x()-((i+1)->x())),2)+pow((i->y()-(i+1)->y()),2)));
    }
    return perimeter;
}

//! calcArea - determine area enclosed by object
//!
//!
//!
//! \return double
double Polygon::calcArea() const
{
    std::vector<QPoint>::const_iterator i=points.begin();
    double area = ((calcPerimeter())*
                   ((sqrt((pow((i->x()-((i+1)->x())),2)+
                           pow((i->y()-(i+1)->y()),2))))/
                    (2*tan(180/points.size()))))/
                     2;
    return area;
}
#endif /* POLYGON_H_ */
