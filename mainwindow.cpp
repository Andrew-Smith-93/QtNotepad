#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open", "C://");
    QMessageBox::information(this,"..",fileName);
    if (!fileName.isEmpty()) {
        // Try to open the selected file
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Read the file contents and set them in QTextEdit
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());

            // Close the file
            file.close();
        } else {
            // Handle the case when the file couldn't be opened
            QMessageBox::warning(this, tr("Error"), tr("Could not open the file."));
        }
    }

}


void MainWindow::on_actionExit_triggered()
{
    close();
}

