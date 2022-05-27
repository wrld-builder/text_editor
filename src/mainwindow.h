#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QShortcut>
#include <QtWebEngineWidgets>
#include <QVBoxLayout>
#include <QLineEdit>

#include "highlighter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct HotKeys {
    bool isLaunchButtonAdded = false;
    bool isLaunchLineEditAdded = false;

    QShortcut *add_launch_button = nullptr;
    QShortcut *hide_launch_button = nullptr;

    QShortcut *find_words = nullptr;
    QShortcut *hide_find_words = nullptr;
};

struct Highlighter {
    HtmlHighLighter *m_htmlHightLighter = nullptr;
    SyntaxHighlighter *m_syntaxHighLighter = nullptr;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *launch_button = nullptr;
    QLineEdit *launch_finding_line_edit = nullptr;

    HotKeys hot_key;
    Highlighter highlight;

private slots:
    void addLaunchButton();
    void launchButtonClicked();
    void hideLaunchButton();

    void launchFindWords();
    void findWords();
    void hideFindWords();
};
#endif // MAINWINDOW_H
