#include "formoption.h"
#include "ui_formoption.h"

FormOption::FormOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOption)
{
    ui->setupUi(this);
}

FormOption::~FormOption()
{
    delete ui;
}

void FormOption::setCheckBox()
{
    this->ui->baseCB->setChecked(this->options->base);
    this->ui->keepParCB->setChecked(this->options->keep_paragraphs);
}

void FormOption::setOptions(t_option *options)
{
    this->options = options;
    this->setCheckBox();
}

void FormOption::on_saveButton_clicked()
{
    this->options->base = (this->ui->baseCB->checkState() == Qt::Checked) ? true : false;
    this->options->keep_paragraphs = (this->ui->keepParCB->checkState() == Qt::Checked) ? true : false;
    this->close();
}
