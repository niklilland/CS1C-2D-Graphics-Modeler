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
		Text(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Text}{}
		~Text() override{}
		void set_rect(const QRect& rect);
		void draw(const int translate_x = 0, const int translate_y = 0) override;
	private:
		QRect rect;
		QString text{"Class Project 2 - 2D Graphics Modeler"};
		QColor color{Qt::blue};
		Qt::AlignmentFlag align {Qt::AlignCenter};
		int pointSize {10};
		QString family {"Comic Sans MS"};
		QFont::Style style {QFont::StyleNormal};
		QFont::Weight weight {QFont::Normal};

};

void Text::set_rect(const QRect& rect)
{
	this->rect = rect;
}

void Text::draw(const int translate_x = 0, const int translate_y = 0)
{
	//qpainter.drawText(rect,text)   //not completed
}
#endif /* TEXT_H_ */
