#include "mainwindow.h"
#include "renderarea.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addShapeClicked()
{ }

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
