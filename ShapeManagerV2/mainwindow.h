#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class RenderArea;
QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // parent is null because it is a top level window
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addShapeClicked();
    void removeShapeClicked();
    void generateShapeReportClicked();
    void generateLineReportClicked();
    void generateCumulativeReportClicked();
    void submitFeedbackClicked();
    void loginClicked();
    void logoutClicked();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;

    // colors
    QColor red = QColor("red");
    QColor orange = QColor("orange");
    QColor yellow = QColor("yellow");
    QColor green = QColor("green");
    QColor blue = QColor("blue");
    QColor indigo = QColor("indigo");
    QColor violet = QColor("violet");

    bool loggedIn = false;
};

#endif // MAINWINDOW_H
