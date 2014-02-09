#ifndef FORMOPTION_H
#define FORMOPTION_H

#include <QWidget>
#include "parser.h"

namespace Ui {
class FormOption;
}

class FormOption : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormOption(QWidget *parent = 0);
    ~FormOption();

    void setCheckBox();
    void setOptions(t_option *options);
    
private slots:
    void on_saveButton_clicked();

private:
    Ui::FormOption *ui;
    t_option *options;

};

#endif // FORMOPTION_H
