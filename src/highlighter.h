#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QVector>

class HtmlHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit HtmlHighLighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

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
