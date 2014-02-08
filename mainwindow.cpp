#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::clearAll clears the text elements
 */
void MainWindow::clearAll()
{
    this->ui->inputText->clear();
    this->ui->outputText->clear();
}

/*!
 * \brief MainWindow::doParse This method execute the parsing of the input text to give the output text
 */
void MainWindow::doParse()
{
    /*
     * For now is only a copy
     */
    this->ui->outputText->setText(this->ui->inputText->toPlainText());
}

/*!
 * \brief MainWindow::copyToClipboard Make a copy of the output text inside the clipboard
 */
void MainWindow::copyToClipboard()
{
    QClipboard *clip = QApplication::clipboard();
    QString input = this->ui->outputText->toPlainText();
    clip->setText(input);
}

void MainWindow::on_clearAll_clicked()
{
    this->clearAll();
}

void MainWindow::on_actionExecute_triggered()
{
    this->doParse();
}

void MainWindow::on_actionCopy_to_Clipboard_triggered()
{
    this->copyToClipboard();
}

void MainWindow::on_actionClear_All_triggered()
{
    this->clearAll();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_execute_clicked()
{
    this->doParse();
}
