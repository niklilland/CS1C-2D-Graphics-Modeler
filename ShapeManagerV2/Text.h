/*
 * Text.h
 *
 *  Created on: 2019��12��4��
 *      Author: Leon
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "Shape.h"
class Text : public Shape
{
	public:
        // Constructor
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
                int                xHeight) : Shape { device, id, ShapeType::Text },String{xString}, Color{xColor}, Alignment{xAlignment},
			      FontSize{xFontSize}, FontFamily{xFontFamily}, FontStyle{xFontStyle},
			      FontWeight{xFontWeight}
        {
            // object specific transform from points supplied to bounding points
            QPoint ul(xTopLeftX,xTopLeftY);
            upperleft = ul;
            QPoint lr(xTopLeftX+xWidth, xTopLeftY+xHeight);
            lowerright = lr;
        }

        // Destructor
        ~Text() override
        { }

		void set_rect(const QRect& rect);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
	private:
			QString            String;      ///< string to display
		    QColor             Color;       ///< color of string text
		    Qt::AlignmentFlag  Alignment;   ///< alignment of string in bounding rectangle
		    int                FontSize;    ///< font size of string
		    QString            FontFamily;  ///< font family to use in rendering string
		    QFont::Style       FontStyle;
		    QFont::Weight      FontWeight;
		    QPoint             upperleft;   ///< Upper left anchor of bounding rectangle
		    QPoint             lowerright;  ///< Lower right anchor for bounding rectangle

};

void Text::set_rect(const QRect& rect)
{
	this->rect = rect;
}

void Text::draw(const int translate_x, const int translate_y)
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

void Text::setText(const QString str)
{
	text = str;
}
#endif /* TEXT_H_ */
