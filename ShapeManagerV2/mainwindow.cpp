#include "mainwindow.h"
#include "renderarea.h"
#include "ui_mainwindow.h"
#include "shape.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderArea = findChild<RenderArea*>("renderArea");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete shapeComboBox;
}

void MainWindow::addShapeClicked()
{
    // declare dialog
    QDialog addShapeDialog;
    // set dialog title
    addShapeDialog.setWindowTitle("Add Shape");

    // create layout for dialog
    QGridLayout* layout = new QGridLayout;
    // create label
    QLabel *label = new QLabel("Hello, world!");

    // IF SHAPE:
    // Pen Color
    // Pen Width
    // Pen Style
    // Pen Cap Style
    // Pen Join Style
    // Brush Color
    // Brush Style

    // IF TEXT
    // Text String
    // Text Color
    // Text Alignment
    // Text Point Size
    // Text Font Family
    // Text Font Style
    // Text Font Weight

    // Create shape options
    shapeComboBox = new QComboBox();
    shapeComboBox->addItem("Line", ShapeType::Line);
    shapeComboBox->addItem("Polyline", ShapeType::Polyline);
    shapeComboBox->addItem("Polygon", ShapeType::Polygon);
    shapeComboBox->addItem("Rectangle", ShapeType::Rectangle);
    shapeComboBox->addItem("Ellipse", ShapeType::Ellipse);
    shapeComboBox->addItem("Text", ShapeType::Text);


    layout->addWidget(shapeComboBox, 2, 1);




    // add label to layout
    layout->addWidget(label);
    // add layout to dialog
    addShapeDialog.setLayout(layout);

    // create the dialog?
    addShapeDialog.exec();
    // show the dialog
    addShapeDialog.show();
    qInfo("The wizard should appear!");
}

void MainWindow::removeShapeClicked()
{ }

void MainWindow::generateShapeReportClicked()
{ }

void MainWindow::generateLineReportClicked()
{ }

void MainWindow::generateCumulativeReportClicked()
{ }

void MainWindow::submitFeedbackClicked()
{ }

void MainWindow::loginClicked()
{ }

void MainWindow::logoutClicked()
{ }
