#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "parser.h"
#include "formoption.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /***Methods***/
    void clearAll();
    void doParse();
    void copyToClipboard();

private slots:
    void on_clearAll_clicked();

    void on_actionExecute_triggered();

    void on_actionCopy_to_Clipboard_triggered();

    void on_actionClear_All_triggered();

    void on_actionExit_triggered();

    void on_execute_clicked();

    void on_actionOptions_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    FormOption *optionForm;
    Parser parser;
    t_option option;
};

#endif // MAINWINDOW_H
