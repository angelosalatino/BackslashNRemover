#include "parser.h"

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
 * \brief Parser::executeParsing Execute the parsing
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
        break;
    case(2):
        break;
    case(3):
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

t_option *Parser::getOptions()
{
    return &(options);
}
