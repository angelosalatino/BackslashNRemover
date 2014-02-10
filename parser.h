#ifndef PARSER_H
#define PARSER_H

#include <QString>

typedef struct options
{
 bool base;
 bool keep_paragraphs;
} t_option;

class Parser
{
public:
    Parser();
    void initOptions();
    void setParametersOption(bool base, bool keep_paragraphs);
    QString executeParsing(QString inputText);
    int optionToNumber();

    // main methods
    QString removeAll(QString inputText);
    QString keepParagraphs(QString inputText);

    t_option *getOptions();
private:
    t_option options;
};

#endif // PARSER_H
