

#ifndef REPORT_H_
#define REPORT_H_

#include "vector.h"
#include "shape.h"
#include <QWidget>
#include <QTableWidget>

using namespace nserkkvector;
namespace Ui {
class reports;
}

//! reports - canvas area for reports
//!
//!
class reports : public QWidget
{
    Q_OBJECT

public:
    //! constructor - craete an area to render the reports
    //!
    //!
    //!
    //! \param parent
    //! \param sort
    explicit reports(QWidget *parent = 0, int sort = 0);

    //! setSort - set internal sorter member
    //!
    //!
    //!
    //! \param val - sorter value
    void setSort(int val);

    //! setVector - set internal pointer to appwide MyVector<Shape>*
    //!
    //!
    //!
    //! \param temp - MyVector<Shape>*
    void setVector(MyVector<Shape *> *temp);

    //! show - draw on canvas
    //!
    //!
    void show();

    //! shapeToString - convert shapeType enum to string describing shape
    //!
    //!
    //!
    //! \param shape - shape ID
    //!
    //! \return QString
    QString shapeToString(int shape);

    //! Destuctor - deallocate local members
    //!
    //!
    ~reports();

protected:
    //  Mouse events
    QPoint mousePoint; ///< current mouse location

    //! mousePressEvent - process a mouse click down event
    //!
    //!
    //!
    //! \param event
    void mousePressEvent(QMouseEvent *event);

    //! mouseReleaseEvent - process a mouse click release event
    //!
    //!
    //!
    //! \param event
    void mouseReleaseEvent(QMouseEvent *event);

    //! mousePressEvent - process a mouse move event
    //!
    //! \
    //!
    //! \param event
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    //!on_pushButton_report_exit_clicked - process exit clicked event
    //!
    //!
    void on_pushButton_report_exit_clicked();

    //! on_comboBox_report_sort_currentIndexChanged - - process event
    //!
    //!
    //!
    //! \param index
    void on_comboBox_report_sort_currentIndexChanged(int index);

private:
    Ui::reports *ui;
    int sorter;
    bool isMouseDown = false;
    MyVector<Shape*> *pShapeVector;
};



#endif /* REPORT_H_ */
