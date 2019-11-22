#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape { Line, Polyline, Polygon, Rectangle, Ellipse, Text  };

    RenderArea(QWidget *parent = nullptr);

signals:

public slots:

};

#endif // RENDERAREA_H




//class RenderArea : public QWidget
//{
//    Q_OBJECT

//public:

//public slots:
//    void setShape(Shape shape);
//    void setPen(const QPen &pen);
//    void setBrush(const QBrush &brush);
//    void setAntialiased(bool antialiased);
//    void setTransformed(bool transformed);

//protected:
//    void paintEvent(QPaintEvent *event) override;

//private:
//    Shape shape;
//    QPen pen;
//    QBrush brush;
//    bool antialiased;
//    bool transformed;
//    QPixmap pixmap;
//};
