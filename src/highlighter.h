#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QVector>
#include <fstream>
#include <string>

#include "advancedmenu.h"

class HtmlHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit HtmlHighLighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;
    void setKeyWords(QStringList&, const char*);

private:
    enum class States {
        None,
        Tag,
        Comment,
        Quote
    };

    struct HighlightingRule {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> startTagRules;
    QVector<HighlightingRule> endTagRules;

    QRegExp openTag;
    QRegExp closeTag;
    QTextCharFormat edgeTagFormat;
    QTextCharFormat insideTagFormat;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QTextCharFormat multiLineCommentFormat;

    QRegExp quotes;
    QTextCharFormat quotationFormat;
    QTextCharFormat tagsFormat;

    AdvancedMenu advanced_menu;
};

class SyntaxHighlighter : public QSyntaxHighlighter {

public:
    SyntaxHighlighter( QTextDocument* parent );

    void highlightBlock( const QString& text );

    void setHighlightedString( const QString& str );

private:
    QString m_highlightedString;

};

#endif // HIGHLIGHTER_H
