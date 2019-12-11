
#ifndef SHAPE_H_
#define SHAPE_H_

/*****************************************************
 * Pre-processor directives
 *****************************************************/
// Standard directives
#include <iostream>
#include <math.h>
using namespace std;

// Qt libraries/directives that will be utilized
#include <QWidget> // This gives access to the QWidget base class, the base of all UI objects
#include <QPen>    // This gives access to the QPen class, which defines how a QPainter should draw lines and outline of shapes
#include <QBrush>  // This gives access to the QBrush class, which defines the fill pattern of shapes drawn by QPainter
#include <QFont>   // This gives access to the QFont class, which specifies a font used for drawing text
#include <QPainter>// This gives access to the QPainter class, which preforms the painting on widgets and other paint devices
#include <QPoint>  // This gives access to the QPoint class, which defines points on a plane

/*********************************************************************************************************
  * Shape Base Class (Abstract base class) -
  *
  * All shape types inherit from this base class.
  * This class uses composition for the Qt 2D graphics
  * elements such as: QPainter, QBrush, QPen.
  *
  *
  *********************************************************************************************************/


class Shape
{
public:
    // Enum with all different shape types

    //! shapeType - enumeration of all support shape types
    //!

	enum shapeType {Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};
    // Shape Constructor - using BMI list
    Shape(QPaintDevice *pDevice,
          int xId,
          shapeType s)
           : device{pDevice},
             shapeId{xId},
             typeShape{s},
             painter{pDevice} {}

    Shape() = delete;         // default constructor never used
    Shape& operator=(const Shape&) = delete;  // Disallow copying
    Shape(const Shape&) = delete;
    // Virtual Destructor
    virtual ~Shape() {}

    // Normal functions
    int getId() const;
    shapeType getShapeType() const;

    // Pure Virtual functions
    virtual void draw(QPaintDevice* pDevice) = 0;
    virtual void move(QPoint &newUpperLeft) = 0;
    virtual void update(void) = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual double calcPerimeter(void) const = 0;
    virtual double calcArea(void) const = 0;

protected:

    QPainter& get_qPainter();  // Function that returns the shape painter

    QPaintDevice *get_qPaintDevice(void) const;

private:
    QPaintDevice *device;  ///< QPainter variable - responsible for the drawing of the shapes in the viewing area
    int shapeId;           ///< A unique id number that will be attached to a shape
    shapeType typeShape;   ///< The specific type of shape, from the enum shapeType
    QPainter painter;      ///< Qpianter renderer
};

std::ostream& operator<<(std::ostream& os, const Shape& s);
std::ostream& operator<<(std::ostream& os, const Shape* s);

//! compare_shape_id - function object to facilitate sorting by shape ID
//!
//!
struct compare_shape_id {
    //! operator() - function to compare two shape IDs
    //!
    //!
    //!
    //! \param s1 - first shape to compare
    //! \param s2 - second shape to compare
    //!
    //! \return bool - true if first Shape's ID less than second Shape
    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return (s1->getId() < s2->getId()); // dereference pointer, compare ids
    }
};

//! compare_shape_perimeter - function object to facilitate sorting by shape perimeter
//!
//!
struct compare_shape_perimeter {    //! operator() - function to compare two shape perimeters
    //!
    //!
    //!
    //! \param s1 - first shape to compare
    //! \param s2 - second shape to compare
    //!
    //! \return bool - true if first Shape's perimeter less than second Shape

    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return (s1->calcPerimeter() < s2->calcPerimeter());
    }
};

//! compare_shape_perimeter - function object to facilitate sorting by shape area
//!
//!
struct compare_shape_area {
    //! operator() - function to compare two shape areas
    //!
    //!
    //!
    //! \param s1 - first shape to compare
    //! \param s2 - second shape to compare
    //!
    //! \return bool - true if first Shape's area less than second Shape

    bool operator()(const Shape* s1, const Shape* s2) const
    {
        return (s1->calcArea() < s2->calcArea());
    }
};

class Shape1D: public Shape
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.
    QPen pen;                   ///< Pen used to draw shape outline
    QPoint upperleft;           ///< Upper left anchor of bounding rectangle
    QPoint lowerright;          ///< Lower right anchor for bounding rectangle
    std::vector<QPoint> points; ///< vector containing endpints and vertices of line objects

    //! Constructor - abstract class for 1D (line) objects
    //!
    //!
    //!
    //! \param device - QPaintDevice
    //! \param xId - shape ID
    //! \param xType
    //! \param xPenColor
    //! \param xPenWidth
    //! \param xPenStyle
    //! \param xPenCapStyle
    //! \param xPenJoinStyle
    Shape1D(QPaintDevice* device,
                 int                xId,
                 shapeType          xType,
                 QColor             xPenColor,
                 qreal              xPenWidth,
                 Qt::PenStyle       xPenStyle,
                 Qt::PenCapStyle    xPenCapStyle,
                 Qt::PenJoinStyle   xPenJoinStyle)
           : Shape(device, xId, xType)
    {
        pen.setColor(xPenColor);
        pen.setWidth(xPenWidth);
        pen.setStyle(xPenStyle);
        pen.setCapStyle(xPenCapStyle);
        pen.setJoinStyle(xPenJoinStyle);
    }

    Shape1D() = delete;
    Shape1D& operator=(const Shape1D&) = delete;  // Disallow copying
    Shape1D(const Shape1D&) = delete;

    //! Destructor - simply free the object space
    //!
    //!
    virtual ~Shape1D() {}

    //! print - print limited information about derived instance for debugging
    //!
    //!
    //!
    //! \param os - output stream
    //!
    //! \return std::ostream&amp;
    virtual std::ostream& print(std::ostream& os) const = 0;
};

class Shape2D: public Shape
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.
    QPen pen;           ///< Pen used to draw shape outline
    QBrush brush;       ///< Brush used to fill 2D object interior
    QPoint upperleft;   ///< Lower right anchor for bounding rectangle
    QPoint lowerright;  ///< vector containing endpints and vertices of line objects

    //! Constructor - abstract class for 2D (circle, square, etc) objects
    //!
    //!
    //!
    //! \param device - QPaintDevice
    //! \param xId - shape ID
    //! \param xType
    //! \param xPenColor
    //! \param xPenWidth
    //! \param xPenStyle
    //! \param xPenCapStyle
    //! \param xPenJoinStyle
    //! \param xBrushColor
    //! \param xBrushStyle
    Shape2D(QPaintDevice* device,
                 int                xId,
                 shapeType          xType,
                 QColor             xPenColor,
                 qreal              xPenWidth,
                 Qt::PenStyle       xPenStyle,
                 Qt::PenCapStyle    xPenCapStyle,
                 Qt::PenJoinStyle   xPenJoinStyle,
                 QColor             xBrushColor,
                 Qt::BrushStyle     xBrushStyle)
           : Shape(device, xId, xType)
    {
        pen.setColor(xPenColor);
        pen.setWidth(xPenWidth);
        pen.setStyle(xPenStyle);
        pen.setCapStyle(xPenCapStyle);
        pen.setJoinStyle(xPenJoinStyle);

        brush.setColor(xBrushColor);
        brush.setStyle(xBrushStyle);
    }

    Shape2D() = delete;         // default constructor never used
    Shape2D& operator=(const Shape&) = delete;  // Disallow copying
    Shape2D(const Shape&) = delete;

    //! Destructor - simply free the object space
    //!
    //!
    virtual ~Shape2D() {}

    //! print - print limited information about derived instance for debugging
    //!
    //!
    //!
    //! \param os - output stream
    //!
    //! \return std::ostream&amp;
    virtual std::ostream& print(std::ostream& os) const = 0;
};


#endif /* SHAPE_H_ */

