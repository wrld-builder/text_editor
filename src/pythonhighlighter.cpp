#include "pythonhighlighter.h"

PythonHighlighter::PythonHighlighter(QObject* parent) :
    QSyntaxHighlighter(parent) {}

void PythonHighlighter::highlightBlock(const QString &text) {
    QTextCharFormat format;

    QRegExp rx(pattern);

    if(!rx.isValid() || rx.isEmpty() || rx.exactMatch("")) {
        setFormat(0, text.length(), format);
        return;
    }

    if(!advanced_menu.getStatePythonForegroundColor().empty()) {
        format.setForeground(QColor(advanced_menu.getStatePythonForegroundColor().c_str()));
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
