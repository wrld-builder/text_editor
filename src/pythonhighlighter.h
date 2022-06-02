#ifndef PYTHONHIGHLIGHTER_H
#define PYTHONHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QString>
#include <QTextCharFormat>

#include "advancedmenu.h"

class PythonHighlighterCycle : public QSyntaxHighlighter {
public:
    explicit PythonHighlighterCycle(QObject* parent = nullptr);
    ~PythonHighlighterCycle(){};
    void highlightBlock(const QString&) override;
    inline void setPattern(QString pattern) { this->pattern = pattern; }

protected:
    AdvancedMenu advanced_menu;

private:
    QString pattern = nullptr;
};

class PythonHighlighterStatements : public QSyntaxHighlighter {
public:
    explicit PythonHighlighterStatements(QObject* parent = nullptr);
    ~PythonHighlighterStatements(){};
    void highlightBlock(const QString&) override;
    inline void setPattern(QString pattern) { this->pattern = pattern; }

protected:
    AdvancedMenu advanced_menu;

private:
    QString pattern = nullptr;
};

#endif // PYTHONHIGHLIGHTER_H
