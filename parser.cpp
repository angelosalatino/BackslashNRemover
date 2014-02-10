#include "parser.h"
#include <QDebug>
#include <QMessageBox>

Parser::Parser()
{
    this->initOptions();
}

void Parser::initOptions()
{
    this->setParametersOption(true, false);
}

void Parser::setParametersOption(bool base, bool keep_paragraphs)
{
    this->options.base = base;
    this->options.keep_paragraphs = keep_paragraphs;
}

/*!
 * \brief Parser::executeParsing Choose the function to call. The choise is take in function of the options.
 * \param inputText The input text to analyze.
 * \return The output text parsed.
 */
QString Parser::executeParsing(QString inputText)
{
    int number = this->optionToNumber();
    switch (number)
    {
    case(0):
        return inputText;
        break;
    case(1):
        return removeAll(inputText);
        break;
    case(2):
    {
        QMessageBox msgBox;
        msgBox.setText("Check the options! It is not possible to perform the parsing with only the Keep Paragraph flag.");
        msgBox.exec();
        return inputText;
        break;
    }
    case(3):
        return keepParagraphs(inputText);
        break;
    }
}

int Parser::optionToNumber()
{
    int number = 0;
    if (this->options.base == true) number += 1; //2^1
    if (this->options.keep_paragraphs == true) number += 2; //2^2
    return number;
}

QString Parser::removeAll(QString inputText)
{
    for (int i = 0; i < inputText.size(); i++)
        if(inputText.at(i) == '\n')
        {
            if(i > 0 && inputText.at(i-1) == '-')
            {
                inputText.replace(i-1,2,"");
                i = i-2;
            }else if(i > 0 && inputText.at(i-1) == ' ')
            {
                inputText.replace(i,1,"");
                i --;
            }else{
                inputText.replace(i,1," ");
                i --;
            }
        }

    return inputText;

}

QString Parser::keepParagraphs(QString inputText)
{
    for (int i = 0; i < inputText.size(); i++)
        if(inputText.at(i) == '\n')
        {
            if(i > 0 && inputText.at(i-1) == '-')
            {
                inputText.replace(i-1,2,"");
                i = i-2;
            }else if(i > 0 && inputText.at(i-1) == ' ')
            {
                if(i > 1 && inputText.at(i-2) != '.')
                {
                    inputText.replace(i,1,"");
                    i --;
                }
            }else if(i > 0 && inputText.at(i-1) != '.')
            {
                inputText.replace(i,1," ");
                i --;
            }
        }

    return inputText;
}

t_option *Parser::getOptions()
{
    return &(options);
}


