#include "mainwindow.h"
#include "renderarea.h"
#include "ui_mainwindow.h"
#include "shape.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderArea = findChild<RenderArea*>("renderArea");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderArea;
    delete addShapeLayout;
    delete shapeComboBox;
    delete penStyleComboBox;
    delete penCapComboBox;
    delete penJoinComboBox;
    delete brushStyleComboBox;
    delete penWidthSpinBox;
}

void MainWindow::addShapeClicked()
{
    // declare dialog
    QDialog addShapeDialog;
    // set dialog title
    addShapeDialog.setWindowTitle("Add Shape");

    // create layout for add shape dialog
    addShapeLayout = new QGridLayout;

    // Shape Type - done

    // IF SHAPE:
    // Pen Color
    // Pen Width - done
    // Pen Style - done
    // Pen Cap Style - done
    // Pen Join Style - done
    // Brush Color
    // Brush Style - done

    // IF TEXT
    // Text String
    // Text Color
    // Text Alignment
    // Text Point Size
    // Text Font Family
    // Text Font Style
    // Text Font Weight

    // Create shape options
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem("Line", ShapeType::Line);
    shapeComboBox->addItem("Polyline", ShapeType::Polyline);
    shapeComboBox->addItem("Polygon", ShapeType::Polygon);
    shapeComboBox->addItem("Rectangle", ShapeType::Rectangle);
    shapeComboBox->addItem("Ellipse", ShapeType::Ellipse);
    shapeComboBox->addItem("Text", ShapeType::Text);

    // TODO: Create pen color input using QColorDialog

    // Create pen width input
    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setValue(1);
    penWidthSpinBox->setMinimum(1);
    penWidthSpinBox->setMaximum(12);

    // Create pen style options
    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem("Solid", static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem("Dash", static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem("Dot", static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem("Dash Dot", static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem("Dash Dot Dot", static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem("None", static_cast<int>(Qt::NoPen));

    // Create pen cap options
    penCapComboBox = new QComboBox;
    penCapComboBox->addItem("Flat", Qt::FlatCap);
    penCapComboBox->addItem("Square", Qt::SquareCap);
    penCapComboBox->addItem("Round", Qt::RoundCap);

    // Create pen join options
    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem("Miter", Qt::MiterJoin);
    penJoinComboBox->addItem("Bevel", Qt::BevelJoin);
    penJoinComboBox->addItem("Round", Qt::RoundJoin);

    // TODO: Create brush color input using QColorDialog

    // Create brush style options
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("Linear Gradient"), static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr("Radial Gradient"), static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr("Conical Gradient"), static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
    brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));




    // Add widgets to layout to row, column
    addShapeLayout->addWidget(shapeComboBox, 1, 1);
    // TODO: Add pen color widget at 2, 1
    addShapeLayout->addWidget(penWidthSpinBox, 3, 1);
    addShapeLayout->addWidget(penStyleComboBox, 4, 1);
    addShapeLayout->addWidget(penCapComboBox, 5, 1);
    addShapeLayout->addWidget(penJoinComboBox, 6, 1);
    // TODO: Add brush color widget at 7, 1
    addShapeLayout->addWidget(brushStyleComboBox, 8, 1);


    // add layout to dialog
    addShapeDialog.setLayout(addShapeLayout);
    // show the dialog
    addShapeDialog.exec();
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
