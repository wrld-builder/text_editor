#include "highlighter.h"

HtmlHighLighter::HtmlHighLighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    edgeTagFormat.setForeground(QBrush(QColor(advanced_menu.getStateHexEdgeTagFormatForeground().c_str())));
    insideTagFormat.setForeground(QBrush(QColor(advanced_menu.getStateHexInsideTagFormatForeground().c_str())));
    insideTagFormat.setFontWeight(QFont::Bold);
    openTag = QRegExp("<");
    closeTag = QRegExp(">");

    tagsFormat.setForeground(QBrush(QColor(advanced_menu.getStateHexTagsFormatForeground().c_str())));
    tagsFormat.setFontWeight(QFont::Bold);

    QStringList keywordPatterns;
    setKeyWords(keywordPatterns, "res/keywords_html_open");

    for (const QString &pattern : keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = tagsFormat;
        startTagRules.append(rule);
    }

    QStringList keywordPatterns_end;
    setKeyWords(keywordPatterns_end, "res/keywords_html_close");

    for (const QString &pattern : keywordPatterns_end) {
        rule.pattern = QRegExp(pattern);
        rule.format = tagsFormat;
        endTagRules.append(rule);
    }

    multiLineCommentFormat.setForeground(Qt::darkGray);
    commentStartExpression = QRegExp("<!--");
    commentEndExpression = QRegExp("-->");

    quotationFormat.setForeground(Qt::darkGreen);
    quotes = QRegExp("\"");
}

void HtmlHighLighter::highlightBlock(const QString &text) {
    setCurrentBlockState(static_cast<int>(HtmlHighLighter::States::None));

    int startIndex = 0;
    if (previousBlockState() != static_cast<int>(HtmlHighLighter::States::Tag)
            && previousBlockState() != static_cast<int>(HtmlHighLighter::States::Quote)) {
        startIndex = openTag.indexIn(text);
    }

    int subPreviousTag = previousBlockState();
    while (startIndex >= 0) {
        int endIndex = closeTag.indexIn(text, startIndex);

        int tagLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(static_cast<int>(HtmlHighLighter::States::Tag));
            tagLength = text.length() - startIndex;
        } else {
            tagLength = endIndex - startIndex + closeTag.matchedLength();
        }

        if (subPreviousTag != static_cast<int>(HtmlHighLighter::States::Tag)) {
            setFormat(startIndex, 1, edgeTagFormat);
            setFormat(startIndex + 1, tagLength - 1, insideTagFormat);
        } else {
            setFormat(startIndex, tagLength, insideTagFormat);
            subPreviousTag = static_cast<int>(HtmlHighLighter::States::None);
        }
        setFormat(endIndex, 1, edgeTagFormat);

        int startQuoteIndex = 0;
        if (previousBlockState() != static_cast<int>(HtmlHighLighter::States::Quote)) {
            startQuoteIndex = quotes.indexIn(text, startIndex);
        }

        while (startQuoteIndex >= 0 && ((startQuoteIndex < endIndex) || (endIndex == -1))) {
            int endQuoteIndex = quotes.indexIn(text, startQuoteIndex + 1);
            int quoteLength = 0;

            if (endQuoteIndex == -1) {
                setCurrentBlockState(static_cast<int>(HtmlHighLighter::States::Quote));
                quoteLength = text.length() - startQuoteIndex;
            } else {
                quoteLength = endQuoteIndex - startQuoteIndex + quotes.matchedLength();
            }

            if ((endIndex > endQuoteIndex) || endIndex == -1) {
                setFormat(startQuoteIndex, quoteLength, quotationFormat);
                startQuoteIndex = quotes.indexIn(text, startQuoteIndex + quoteLength);
            } else {
                break;
            }
        }
        startIndex = openTag.indexIn(text, startIndex + tagLength);
    }

    for (const HighlightingRule &rule : startTagRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);

        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index + 1, length - 1, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    for (const HighlightingRule &rule : endTagRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();

            setFormat(index + 1, 1, edgeTagFormat);
            setFormat(index + 2, length - 2, rule.format);

            index = expression.indexIn(text, index + length);
        }
    }

    int startCommentIndex = 0;
    if (previousBlockState() != static_cast<int>(HtmlHighLighter::States::Comment)) {
        startCommentIndex = commentStartExpression.indexIn(text);
    }

    while (startCommentIndex >= 0) {
        int endCommentIndex = commentEndExpression.indexIn(text, startCommentIndex);
        int commentLength = 0;

        if (endCommentIndex == -1) {
            setCurrentBlockState(static_cast<int>(HtmlHighLighter::States::Comment));
            commentLength = text.length() - startCommentIndex;
        } else {
            commentLength = endCommentIndex - startCommentIndex
                            + commentEndExpression.matchedLength();
        }

        setFormat(startCommentIndex, commentLength, multiLineCommentFormat);
        startCommentIndex = commentStartExpression.indexIn(text, startCommentIndex + commentLength);
    }
}

SyntaxHighlighter::SyntaxHighlighter( QTextDocument* parent ) :
    QSyntaxHighlighter( parent ) {
}

void SyntaxHighlighter::highlightBlock( const QString& text ) {
    if( m_highlightedString.isEmpty() ) {
        return;
    }

    QTextCharFormat fmt;
    fmt.setBackground( Qt::yellow );

    const int LEN = m_highlightedString.length();
    for(int index = text.indexOf( m_highlightedString ); 0 <= index; index = text.indexOf( m_highlightedString, index + LEN )) {
        setFormat( index, LEN, fmt );
    }
}

void SyntaxHighlighter::setHighlightedString( const QString& str ) {
    m_highlightedString = str;
    rehighlight();
}

void HtmlHighLighter::setKeyWords(QStringList &list, const char* path) {
    std::ifstream in(path);
    if(in.is_open()) {
        std::string line = "";
        while(getline(in, line)) {
            list << line.c_str();
        }

        in.close();
    }
}
