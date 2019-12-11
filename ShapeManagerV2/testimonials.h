

#ifndef TESTIMONIALS_H_
#define TESTIMONIALS_H_

/***********************************
 * Pre-processor directives
 ***********************************/

// Qt libraries/directives that will be utilized
#include <QWidget> // Gives access to QWidget base class, class inherits from

namespace Ui {
class testimonials;
}

//! Testimonials Class - holds information for the testimonials dialog
//!
//!
class testimonials : public QWidget
{
    Q_OBJECT

public:
    explicit testimonials(QWidget *parent = 0);

    //  Overloaded showEvent function
    void showEvent(QShowEvent *event);
    ~testimonials();

    //  Update the textBrowser with the file testimonies
    void updateTestimonies();

private slots:

    //
    void on_submit_button_clicked();

    //  First closing testimonies button
    void on_pushButton_exit_clicked();

    //  Second closing testimonies button
    void on_pushButton_exit_2_clicked();

private:
    Ui::testimonials *ui;
};



#endif /* TESTIMONIALS_H_ */
