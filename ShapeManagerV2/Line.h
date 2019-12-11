

#ifndef LINE_H_
#define LINE_H_

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

// Line class, derived form the shape base class

//! Line class - derived from shape1D
//!
//!
class Line : public Shape1D
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.

    // Constructor used in class project
    Line(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             int                xTopLeftX,
             int                xTopLeftY,
             int                xBotRightX,
             int                xBotRightY);

    Line() = delete;
    Line& operator=(const Line&) = delete;  // Disallow copying
    Line(const Line&) = delete;
    ~Line();

    std::ostream& print(std::ostream& os) const;
    void draw(QPaintDevice* device);
    void move(QPoint &newUpperLeft);
    void update(void);
    double calcPerimeter() const;
    double calcArea() const;
};

Line::Line(QPaintDevice* device,
             int                xId,
             QColor             xPenColor,
             qreal              xPenWidth,
             Qt::PenStyle       xPenStyle,
             Qt::PenCapStyle    xPenCapStyle,
             Qt::PenJoinStyle   xPenJoinStyle,
             int                xTopLeftX,
             int                xTopLeftY,
             int                xBotRightX,
             int                xBotRightY)
       : Shape1D(device, xId, shapeType::Line,
                      xPenColor, xPenWidth, xPenStyle, xPenCapStyle, xPenJoinStyle)
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    points.push_back(ul);
    QPoint lr(xBotRightX, xBotRightY);
    lowerright = lr;
    points.push_back(lr);
}


//! Destructor - simply free the object space
//!
//!
Line::~Line() {};

//! print - print limited information about derived instance for debugging
//!
//!
//!
//! \param os - output stream pointer
//!
//! \return std::ostream&amp;
std::ostream& Line::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//!
//!
//! \param device
void Line::draw(QPaintDevice* device)
{
    QPainter& paint = get_qPainter();
    paint.begin(device);
    paint.setPen(pen);
    paint.drawLine(upperleft, lowerright);
    paint.setPen(QPen());
    paint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    paint.end();
}

//! move - relocate circle to new upper left coordinate
//!
//!
//!
//! \param newUpperLeft  - new location of upper left of enclosing rectangle
void Line::move(QPoint &newUpperLeft)
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
void Line::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//!
//!
//! \return double
double Line::calcPerimeter() const
{
    return 0;
}

//! calcArea - determine area enclosed by object
//!
//!
//!
//! \return double
double Line::calcArea() const
{
    return 0;
}



#endif /* LINE_H_ */
