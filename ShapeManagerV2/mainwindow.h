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
    void addShapeSubmitted();
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

    // Add shape widgets
    QComboBox* shapeComboBox;
    QComboBox* penColorComboBox;
    QSpinBox* penWidthSpinBox;
    QComboBox* penStyleComboBox;
    QComboBox* penCapComboBox;
    QComboBox* penJoinComboBox;
    QComboBox* brushColorComboBox;
    QComboBox* brushStyleComboBox;
    QLineEdit* textStringField;
    QComboBox* textColorComboBox;
    QComboBox* textAlignmentComboBox;
    QSpinBox* textPointSizeSpinBox;
    QComboBox* textFontFamilyComboBox;
    QComboBox* textFontStyleComboBox;
    QComboBox* textFontWeightComboBox;

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
