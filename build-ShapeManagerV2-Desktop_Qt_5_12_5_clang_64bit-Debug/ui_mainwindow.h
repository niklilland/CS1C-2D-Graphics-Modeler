/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <renderarea.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    RenderArea *renderArea;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addShapeButton;
    QPushButton *removeShapeButton;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *shapeReportButton;
    QPushButton *lineReportButton;
    QPushButton *totalReportButton;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1268, 659);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        renderArea = new RenderArea(tab);
        renderArea->setObjectName(QString::fromUtf8("renderArea"));
        renderArea->setGeometry(QRect(10, 10, 1000, 500));
        verticalLayoutWidget_3 = new QWidget(tab);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(1030, 20, 191, 221));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        addShapeButton = new QPushButton(verticalLayoutWidget_3);
        addShapeButton->setObjectName(QString::fromUtf8("addShapeButton"));

        verticalLayout_4->addWidget(addShapeButton);

        removeShapeButton = new QPushButton(verticalLayoutWidget_3);
        removeShapeButton->setObjectName(QString::fromUtf8("removeShapeButton"));

        verticalLayout_4->addWidget(removeShapeButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 791, 531));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(900, 40, 261, 261));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        shapeReportButton = new QPushButton(verticalLayoutWidget_2);
        shapeReportButton->setObjectName(QString::fromUtf8("shapeReportButton"));

        verticalLayout_3->addWidget(shapeReportButton);

        lineReportButton = new QPushButton(verticalLayoutWidget_2);
        lineReportButton->setObjectName(QString::fromUtf8("lineReportButton"));

        verticalLayout_3->addWidget(lineReportButton);

        totalReportButton = new QPushButton(verticalLayoutWidget_2);
        totalReportButton->setObjectName(QString::fromUtf8("totalReportButton"));

        verticalLayout_3->addWidget(totalReportButton);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget_4 = new QWidget(tab_3);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(20, 10, 791, 541));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_5 = new QWidget(tab_3);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(850, 50, 381, 501));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget_5);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_6->addWidget(textEdit);

        pushButton = new QPushButton(verticalLayoutWidget_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_6->addWidget(pushButton);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1268, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(addShapeButton, SIGNAL(clicked()), MainWindow, SLOT(addShapeClicked()));
        QObject::connect(removeShapeButton, SIGNAL(clicked()), MainWindow, SLOT(removeShapeClicked()));
        QObject::connect(shapeReportButton, SIGNAL(clicked()), MainWindow, SLOT(generateShapeReportClicked()));
        QObject::connect(lineReportButton, SIGNAL(clicked()), MainWindow, SLOT(generateLineReportClicked()));
        QObject::connect(totalReportButton, SIGNAL(clicked()), MainWindow, SLOT(generateCumulativeReportClicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(submitFeedbackClicked()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        addShapeButton->setText(QApplication::translate("MainWindow", "Add Shape", nullptr));
        removeShapeButton->setText(QApplication::translate("MainWindow", "Remove Shape", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Render Area", nullptr));
        shapeReportButton->setText(QApplication::translate("MainWindow", "Generate Shape Report", nullptr));
        lineReportButton->setText(QApplication::translate("MainWindow", "Generate Line Report", nullptr));
        totalReportButton->setText(QApplication::translate("MainWindow", "Generate Cumulative Report", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Reporting", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Submit Feedback", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Feedback", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
