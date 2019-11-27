#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
};

#endif // MAINWINDOW_H
