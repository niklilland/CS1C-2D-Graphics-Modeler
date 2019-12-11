
#ifndef TEXT_H_
#define TEXT_H_

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

class Text : public Shape
{
public:
    // Note: the data members are public, because we need non class memebers to
    //       access and modify them without restrictions and so creating
    //       accessors and mutators adds no value.
    QString            String;      ///< string to display
    QColor             Color;       ///< color of string text
    Qt::AlignmentFlag  Alignment;   ///< alignment of string in bounding rectangle
    int                FontSize;    ///< font size of string
    QString            FontFamily;  ///< font family to use in rendering string
    QFont::Style       FontStyle;
    QFont::Weight      FontWeight;
    QPoint             upperleft;   ///< Upper left anchor of bounding rectangle
    QPoint             lowerright;  ///< Lower right anchor for bounding rectangle

    Text(QPaintDevice* device,
         int                xId,
         QString            xString,
         QColor             xColor,
         Qt::AlignmentFlag  xAlignment,
         int                xFontSize,
         QString            xFontFamily,
         QFont::Style       xFontStyle,
         QFont::Weight      xFontWeight,
         int                xTopLeftX,
         int                xTopLeftY,
         int                xWidth,
         int                xHeight);

    Text() = delete;
    Text& operator=(const Text&) = delete;  // Disallow copying
    Text(const Text&) = delete;
    ~Text();

    std::ostream& print(std::ostream& os) const;
   void draw(QPaintDevice* device);
    void move(QPoint &newUpperLeft);
    void update(void);
    double calcPerimeter() const;
    double calcArea() const;
};

Text::Text(QPaintDevice* device,
     int                xId,
     QString            xString,
     QColor             xColor,
     Qt::AlignmentFlag  xAlignment,
     int                xFontSize,
     QString            xFontFamily,
     QFont::Style       xFontStyle,
     QFont::Weight      xFontWeight,
     int                xTopLeftX,
     int                xTopLeftY,
     int                xWidth,
     int                xHeight)
    : Shape(device, xId, shapeType::Text), String{xString}, Color{xColor}, Alignment{xAlignment},
      FontSize{xFontSize}, FontFamily{xFontFamily}, FontStyle{xFontStyle},
      FontWeight{xFontWeight}
{
    // object specific transform from points supplied to bounding points
    QPoint ul(xTopLeftX,xTopLeftY);
    upperleft = ul;
    QPoint lr(xTopLeftX+xWidth, xTopLeftY+xHeight);
    lowerright = lr;
}

//! Destructor - simply free the object space
//!
//!
Text::~Text() {};               vector<QPoint> v;

//! print - print limited information about derived instance for debugging
//!
//!
//!
//! \param os - output stream
//!
//! \return std::ostream&amp;
std::ostream& Text::print(std::ostream& os) const
{
    return os << " Id:" << getId() << " P:" << calcPerimeter() << " A:" << calcArea();
};

//! draw - output object onto QT canvas using QPaintDevice
//!
//!
//!
//! \param device
void Text::draw(QPaintDevice* device)
{
    QPainter& tPaint = get_qPainter();
    QFont tFont(FontFamily, FontSize);
    QPen tPen(Color);
    QRect tRect(upperleft, lowerright);
    tFont.setStyle(FontStyle);
    tFont.setWeight(FontWeight);
    tPaint.begin(device);
    tPaint.setFont(tFont);
    tPaint.setPen(tPen);
    tPaint.drawText(tRect, Alignment, String);
    tPaint.setPen(QPen());
    tPaint.drawText((upperleft.x()) - 5, (upperleft.y()) - 5, QString::number(this->getId()));
    tPaint.end();
}

//! move - relocate text to new upper left coordinate
//!
//!
//!
//! \param newUpperLeft - new location of upper left of enclosing rectangle
void Text::move(QPoint &newUpperLeft)
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
void Text::update(void)
{
    draw((get_qPaintDevice()));
    return;
}

//! calcPerimeter - determine object outline length
//!
//!
//!
//! \return double
double Text::calcPerimeter() const
{
    return 0;
}

//! calcArea - determine area enclosed by object
//!
//!
//!
//! \return double
double Text::calcArea() const
{
    return 0;
}

#endif /* TEXT_H_ */
