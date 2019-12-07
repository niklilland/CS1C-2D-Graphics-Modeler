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
}

void MainWindow::addShapeClicked()
{
    // declare dialog
    QDialog addShapeDialog;
    // set dialog title
    addShapeDialog.setWindowTitle("Add Shape");

    // create layout for add shape dialog
    QGridLayout* addShapeLayout = new QGridLayout;

    // Create shape options
    QComboBox* shapeComboBox = new QComboBox;
    shapeComboBox->addItem("Line", ShapeType::Line);
    shapeComboBox->addItem("Polyline", ShapeType::Polyline);
    shapeComboBox->addItem("Polygon", ShapeType::Polygon);
    shapeComboBox->addItem("Rectangle", ShapeType::Rectangle);
    shapeComboBox->addItem("Ellipse", ShapeType::Ellipse);
    shapeComboBox->addItem("Text", ShapeType::Text);
    QLabel* shapeLabel = new QLabel("Shape");
    shapeLabel->setBuddy(shapeComboBox);

    // Create pen color QComboBox
    QComboBox* penColorComboBox = new QComboBox;
    penColorComboBox->addItem("Red", red);
    penColorComboBox->addItem("Orange", orange);
    penColorComboBox->addItem("Yellow", yellow);
    penColorComboBox->addItem("Green", green);
    penColorComboBox->addItem("Blue", blue);
    penColorComboBox->addItem("Indigo", indigo);
    penColorComboBox->addItem("Violet", violet);
    QLabel* penColorLabel = new QLabel("Pen Color");
    penColorLabel->setBuddy(penColorComboBox);

    // Create pen width input
    QSpinBox* penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setValue(1);
    penWidthSpinBox->setMinimum(1);
    penWidthSpinBox->setMaximum(12);
    QLabel* penWidthLabel = new QLabel("Pen Width");
    penWidthLabel->setBuddy(penWidthSpinBox);

    // Create pen style options
    QComboBox* penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem("Solid", static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem("Dash", static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem("Dot", static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem("Dash Dot", static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem("Dash Dot Dot", static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem("None", static_cast<int>(Qt::NoPen));
    QLabel* penStyleLabel = new QLabel("Pen Style");
    penStyleLabel->setBuddy(penStyleComboBox);

    // Create pen cap options
    QComboBox* penCapComboBox = new QComboBox;
    penCapComboBox->addItem("Flat", Qt::FlatCap);
    penCapComboBox->addItem("Square", Qt::SquareCap);
    penCapComboBox->addItem("Round", Qt::RoundCap);
    QLabel* penCapLabel = new QLabel("Pen Cap");
    penCapLabel->setBuddy(penCapComboBox);

    // Create pen join options
    QComboBox* penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem("Miter", Qt::MiterJoin);
    penJoinComboBox->addItem("Bevel", Qt::BevelJoin);
    penJoinComboBox->addItem("Round", Qt::RoundJoin);
    QLabel* penJoinLabel = new QLabel("Pen Join");
    penJoinLabel->setBuddy(penJoinComboBox);

    // Create brush color QComboBox
    QComboBox* brushColorComboBox = new QComboBox;
    brushColorComboBox->addItem("Red", red);
    brushColorComboBox->addItem("Orange", orange);
    brushColorComboBox->addItem("Yellow", yellow);
    brushColorComboBox->addItem("Green", green);
    brushColorComboBox->addItem("Blue", blue);
    brushColorComboBox->addItem("Indigo", indigo);
    brushColorComboBox->addItem("Violet", violet);
    QLabel* brushColorLabel = new QLabel("Brush Color");
    brushColorLabel->setBuddy(brushColorComboBox);

    // Create brush style options
    QComboBox* brushStyleComboBox = new QComboBox;
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
    QLabel* brushStyleLabel = new QLabel("Brush Style");
    brushStyleLabel->setBuddy(brushStyleComboBox);

    // Text string field
    QLineEdit* textStringField = new QLineEdit;
    QLabel* textStringLabel = new QLabel("Text String");
    textStringLabel->setBuddy(textStringField);

    // Text color field
    QComboBox* textColorComboBox = new QComboBox;
    textColorComboBox->addItem("Red", red);
    textColorComboBox->addItem("Orange", orange);
    textColorComboBox->addItem("Yellow", yellow);
    textColorComboBox->addItem("Green", green);
    textColorComboBox->addItem("Blue", blue);
    textColorComboBox->addItem("Indigo", indigo);
    textColorComboBox->addItem("Violet", violet);
    QLabel* textColorLabel = new QLabel("Text Color");
    textColorLabel->setBuddy(textColorComboBox);

    // Text alignment
    QComboBox* textAlignmentComboBox = new QComboBox;
    textAlignmentComboBox->addItem("Top", Qt::AlignTop);
    textAlignmentComboBox->addItem("Bottom", Qt::AlignBottom);
    textAlignmentComboBox->addItem("Left", Qt::AlignLeft);
    textAlignmentComboBox->addItem("Right", Qt::AlignRight);
    textAlignmentComboBox->addItem("Center", Qt::AlignCenter);
    QLabel* textAlignmentLabel = new QLabel("Text Alignment");
    textAlignmentLabel->setBuddy(textAlignmentComboBox);

    // Text Point size
    QSpinBox* textPointSizeSpinBox = new QSpinBox;
    textPointSizeSpinBox->setValue(1);
    textPointSizeSpinBox->setMinimum(1);
    textPointSizeSpinBox->setMaximum(12);
    QLabel* textPointSizeLabel = new QLabel("Text Point Size");
    textPointSizeLabel->setBuddy(textPointSizeSpinBox);

    // Text Font Family
    QComboBox* textFontFamilyComboBox = new QComboBox;
    textFontFamilyComboBox->addItem("Times", QFont("Times"));
    textFontFamilyComboBox->addItem("Helvetica", QFont("Helvetica"));
    textFontFamilyComboBox->addItem("Arial", QFont("Arial"));
    textFontFamilyComboBox->addItem("Papyrus", QFont("Papyrus"));
    QLabel* textFontFamilyLabel = new QLabel("Text Font Family");
    textFontFamilyLabel->setBuddy(textFontFamilyComboBox);

    // Text Font Style
    QComboBox* textFontStyleComboBox = new QComboBox;
    textFontStyleComboBox->addItem("Normal", QFont::StyleNormal);
    textFontStyleComboBox->addItem("Italic", QFont::StyleItalic);
    QLabel* textFontStyleLabel = new QLabel("Text Font Style");
    textFontStyleLabel->setBuddy(textFontStyleComboBox);

    // Text Font Weight
    QComboBox* textFontWeightComboBox = new QComboBox;
    textFontWeightComboBox->addItem("Thin", QFont::Thin);
    textFontWeightComboBox->addItem("ExtraLight", QFont::ExtraLight);
    textFontWeightComboBox->addItem("Light", QFont::Light);
    textFontWeightComboBox->addItem("Normal", QFont::Normal);
    textFontWeightComboBox->addItem("Medium", QFont::Medium);
    textFontWeightComboBox->addItem("DemiBold", QFont::DemiBold);
    textFontWeightComboBox->addItem("Bold", QFont::Bold);
    textFontWeightComboBox->addItem("ExtraBold", QFont::ExtraBold);
    textFontWeightComboBox->addItem("Black", QFont::Black);
    QLabel* textFontWeightLabel = new QLabel("Text Font Weight");
    textFontStyleLabel->setBuddy(textFontWeightComboBox);

    // Add labels to column 0
    addShapeLayout->addWidget(shapeLabel, 1, 0, Qt::AlignRight);
    addShapeLayout->addWidget(penColorLabel, 2, 0, Qt::AlignRight);
    addShapeLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
    addShapeLayout->addWidget(penStyleLabel, 4, 0, Qt::AlignRight);
    addShapeLayout->addWidget(penCapLabel, 5, 0, Qt::AlignRight);
    addShapeLayout->addWidget(penJoinLabel, 6, 0, Qt::AlignRight);
    addShapeLayout->addWidget(brushColorLabel, 7, 0, Qt::AlignRight);
    addShapeLayout->addWidget(brushStyleLabel, 8, 0, Qt::AlignRight);

    // Add widgets to layout to column 1
    addShapeLayout->addWidget(shapeComboBox, 1, 1);
    addShapeLayout->addWidget(penColorComboBox, 2, 1);
    addShapeLayout->addWidget(penWidthSpinBox, 3, 1);
    addShapeLayout->addWidget(penStyleComboBox, 4, 1);
    addShapeLayout->addWidget(penCapComboBox, 5, 1);
    addShapeLayout->addWidget(penJoinComboBox, 6, 1);
    addShapeLayout->addWidget(brushColorComboBox, 7, 1);
    addShapeLayout->addWidget(brushStyleComboBox, 8, 1);

    // Add labels to column 2
    addShapeLayout->addWidget(textStringLabel, 1, 2, Qt::AlignRight);
    addShapeLayout->addWidget(textColorLabel, 2, 2, Qt::AlignRight);
    addShapeLayout->addWidget(textAlignmentLabel, 3, 2, Qt::AlignRight);
    addShapeLayout->addWidget(textPointSizeLabel, 4, 2, Qt::AlignRight);
    addShapeLayout->addWidget(textFontFamilyLabel, 5, 2, Qt::AlignRight);
    addShapeLayout->addWidget(textFontStyleLabel, 6, 2, Qt::AlignRight);
    addShapeLayout->addWidget(textFontWeightLabel, 7, 2, Qt::AlignRight);

    // Add widgets to column 3
    addShapeLayout->addWidget(textStringField, 1, 3);
    addShapeLayout->addWidget(textColorComboBox, 2, 3);
    addShapeLayout->addWidget(textAlignmentComboBox, 3, 3);
    addShapeLayout->addWidget(textPointSizeSpinBox, 4, 3);
    addShapeLayout->addWidget(textFontFamilyComboBox, 5, 3);
    addShapeLayout->addWidget(textFontStyleComboBox, 6, 3);
    addShapeLayout->addWidget(textFontWeightComboBox, 7, 3);


    // TODO: Add PushButton and connect its signal a mainwindow slot by using `connect` (See BasicDrawing example)
    QPushButton* addShapeButton = new QPushButton;
    addShapeButton->setText("Add Shape");

    // connect(addShapeButton, SIGNAL(clicked(bool)), renderArea, SLOT(setShape(Shape)));
    // button clicked


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
