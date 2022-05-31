#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QShortcut>
#include <QtWebEngineWidgets>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDataStream>
#include <QTextCodec>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QPlainTextEdit>
#include <QTabWidget>
#include <QPushButton>

#include "highlighter.h"
#include "advancedmenu.h"

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

    QShortcut *save_file = nullptr;
    QShortcut *open_file = nullptr;
    QShortcut *add_new_tab = nullptr;
};

struct Highlighter {
    HtmlHighLighter *m_htmlHightLighter = nullptr;
    SyntaxHighlighter *m_syntaxHighLighter = nullptr;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    QString tab_title = nullptr;
    inline void setRightTab(QPlainTextEdit*);
    void setTabsShortTitleCheck(QFile&);

private:
    Ui::MainWindow *ui;
    QPushButton *launch_button = nullptr;
    QLineEdit *launch_finding_line_edit = nullptr;
    QPlainTextEdit *editor_text = nullptr;
    QGridLayout *gridLayout = nullptr;
    QTabWidget *editor_tabs = nullptr;

    HotKeys hot_key;
    Highlighter highlight;
    AdvancedMenu advanced_menu;

private slots:
    void addLaunchButton();
    void launchButtonClicked();
    void hideLaunchButton();

    void launchFindWords();
    void findWords();
    void hideFindWords();

    void saveFile();
    void openFile();
    void add_new_tab();
    void deleteTab(int);
};
#endif // MAINWINDOW_H
