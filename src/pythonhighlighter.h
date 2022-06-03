#ifndef PYTHONHIGHLIGHTER_H
#define PYTHONHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QString>
#include <QTextCharFormat>
#include <thread>

#include "advancedmenu.h"

class PythonHighlighter : public QSyntaxHighlighter {
public:
    explicit PythonHighlighter(QObject* parent = nullptr);
    ~PythonHighlighter(){};
    void highlightBlock(const QString&) override;

    inline void setPattern(QString pattern) { this->pattern = pattern; }

protected:
    AdvancedMenu advanced_menu;

private:
    QString pattern = nullptr;
};

#endif // PYTHONHIGHLIGHTER_H
