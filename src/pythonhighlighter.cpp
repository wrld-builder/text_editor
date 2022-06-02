#include "pythonhighlighter.h"

PythonHighlighterCycle::PythonHighlighterCycle(QObject* parent) :
    QSyntaxHighlighter(parent) {}

void PythonHighlighterCycle::highlightBlock(const QString &text) {
    QTextCharFormat format;

    QRegExp rx(pattern);

    if(!rx.isValid() || rx.isEmpty() || rx.exactMatch("")) {
        setFormat(0, text.length(), format);
        return;
    }

    if(!advanced_menu.getStatePythonCycleForegroundColor().empty()) {
        format.setForeground(QColor(advanced_menu.getStatePythonCycleForegroundColor().c_str()));
    } else {
        format.setForeground(Qt::yellow);
    }

    int index = rx.indexIn(text);

    while(index >= 0) {
        int length = rx.matchedLength();
        setFormat(index, length, format);
        index = rx.indexIn(text, index + length);
    }
}

PythonHighlighterStatements::PythonHighlighterStatements(QObject* parent) :
    QSyntaxHighlighter(parent) {}

void PythonHighlighterStatements::highlightBlock(const QString &text) {
    QTextCharFormat format;

    QRegExp rx(pattern);

    if(!rx.isValid() || rx.isEmpty() || rx.exactMatch("")) {
        setFormat(0, text.length(), format);
        return;
    }

    if(!advanced_menu.getStatePythonStatementsForegroundColor().empty()) {
        format.setForeground(QColor(advanced_menu.getStatePythonStatementsForegroundColor().c_str()));
    } else {
        format.setForeground(Qt::green);
    }

    int index = rx.indexIn(text);

    while(index >= 0) {
        int length = rx.matchedLength();
        setFormat(index, length, format);
        index = rx.indexIn(text, index + length);
    }
}
