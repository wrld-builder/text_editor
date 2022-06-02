#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gridLayout = new QGridLayout(ui->centralwidget);
    editor_tabs = new QTabWidget;
    editor_text = new QPlainTextEdit(editor_tabs);

    editor_tabs->addTab(editor_text, "untitled");
    editor_tabs->setTabsClosable(true);
    editor_tabs->setMovable(true);

    gridLayout->addWidget(editor_tabs);

    setRightTab(editor_text);
    setStyleMainWindowCheck();

    hot_key.add_launch_button = new QShortcut(this);
    hot_key.add_launch_button->setKey(Qt::CTRL + Qt::Key_L);

    hot_key.hide_launch_button = new QShortcut(this);
    hot_key.hide_launch_button->setKey(Qt::CTRL + Qt::ALT + Qt::Key_L);

    hot_key.find_words = new QShortcut(this);
    hot_key.find_words->setKey(Qt::CTRL + Qt::Key_F);

    hot_key.hide_find_words = new QShortcut(this);
    hot_key.hide_find_words->setKey(Qt::CTRL + Qt::ALT + Qt::Key_F);

    hot_key.save_file = new QShortcut(this);
    hot_key.save_file->setKey(Qt::CTRL + Qt::Key_S);

    hot_key.open_file = new QShortcut(this);
    hot_key.open_file->setKey(Qt::CTRL + Qt::Key_O);

    hot_key.add_new_tab = new QShortcut(this);
    hot_key.add_new_tab->setKey(Qt::CTRL + Qt::Key_T);

    connect(hot_key.add_launch_button, &QShortcut::activated, this, &MainWindow::addLaunchButton);
    connect(hot_key.hide_launch_button, &QShortcut::activated, this, &MainWindow::hideLaunchButton);
    connect(hot_key.find_words, &QShortcut::activated, this, &MainWindow::launchFindWords);
    connect(hot_key.hide_find_words, &QShortcut::activated, this, &MainWindow::hideFindWords);
    connect(hot_key.save_file, &QShortcut::activated, this, &MainWindow::saveFile);
    connect(hot_key.open_file, &QShortcut::activated, this, &MainWindow::openFile);
    connect(hot_key.add_new_tab, &QShortcut::activated, this, &MainWindow::add_new_tab);
    connect(editor_tabs, &QTabWidget::tabCloseRequested, this, &MainWindow::deleteTab);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addLaunchButton() {
    if(hot_key.isLaunchButtonAdded == false) {
        launch_button = new QPushButton(this);
        launch_button->setText("LAUNCH SITE");
        gridLayout->addWidget(launch_button);

        hot_key.isLaunchButtonAdded = true;
        connect(launch_button, SIGNAL(clicked()), this, SLOT(launchButtonClicked()));
    }
}

void MainWindow::launchButtonClicked() {
    auto htmlCode = dynamic_cast<QPlainTextEdit*>(editor_tabs->currentWidget())->toPlainText();
    auto *viewCode = new QWebEngineView();
    viewCode->setHtml(htmlCode);

    auto newViewWindow = new QWidget();
    auto *vbox = new QVBoxLayout(newViewWindow);
    vbox->addWidget(viewCode);
    newViewWindow->show();
}

void MainWindow::hideLaunchButton() {
    if(hot_key.isLaunchButtonAdded == true) {
        launch_button->close();
        delete launch_button;
        hot_key.isLaunchButtonAdded = false;
    }
}

void MainWindow::launchFindWords() {
    if(hot_key.isLaunchLineEditAdded == false) {
        launch_finding_line_edit = new QLineEdit(this);
        gridLayout->addWidget(launch_finding_line_edit);

        hot_key.isLaunchLineEditAdded = true;
        connect(launch_finding_line_edit, SIGNAL(editingFinished()), this, SLOT(findWords()));
        connect(launch_finding_line_edit, SIGNAL(returnPressed()), this, SLOT(findWords()));
    }
}

void MainWindow::findWords() {
    if( highlight.m_syntaxHighLighter ) {
        highlight.m_syntaxHighLighter->setHighlightedString(launch_finding_line_edit->text());
    }
}

void MainWindow::hideFindWords() {
    if(hot_key.isLaunchLineEditAdded == true) {
        launch_finding_line_edit->close();
        delete launch_finding_line_edit;
        hot_key.isLaunchLineEditAdded = false;
    }
}

void MainWindow::saveFile() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), QDir::currentPath(), nullptr);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QFile out(filename);

    if(out.open(QIODevice::WriteOnly)) {
       QTextStream stream( &out );
       stream << QObject::trUtf8(dynamic_cast<QPlainTextEdit*>(editor_tabs->currentWidget())->toPlainText().toStdString().c_str());
       out.close();
    }

    QFile in(filename);
    if(in.open(QIODevice::ReadOnly)) {
       QTextStream stream(&in);
       qDebug() << stream.readAll();
       in.close();
    }

    setTabsShortTitleCheck(in);
    setHighlightingCheck(in);
}

void MainWindow::openFile() {
    QString filename = QFileDialog::getOpenFileName(
                        this,
                        tr("Открыть файл"),
                        QDir::currentPath(),
                        nullptr);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QFile in(filename);
    in.open(QIODevice::ReadOnly | QIODevice::Text);
    auto text = in.readAll();

    dynamic_cast<QPlainTextEdit*>(editor_tabs->currentWidget())->setPlainText(text);

    setTabsShortTitleCheck(in);
    setHighlightingCheck(in);
}

inline void MainWindow::setRightTab(QPlainTextEdit* edit) {
    edit->setTabStopDistance(QFontMetricsF(edit->font()).horizontalAdvance(' ') * 4);
}

void MainWindow::add_new_tab() {
    auto *text_editor = new QPlainTextEdit(this);
    editor_tabs->addTab(text_editor, "untilted");
    setRightTab(text_editor);
}

void MainWindow::deleteTab(int indexToRemove) {
    auto widgetToDelete = editor_tabs->widget(indexToRemove);
    delete widgetToDelete;
}

inline void MainWindow::setTabsShortTitleCheck(QFile &in) {
    if(advanced_menu.getStateTabsShortTitle() == true) {
        QFileInfo fInfo(in.fileName());
        editor_tabs->setTabText(editor_tabs->currentIndex(), fInfo.fileName());
    } else {
        editor_tabs->setTabText(editor_tabs->currentIndex(), in.fileName());
    }
}

inline void MainWindow::setStyleMainWindowCheck() {
    if(!advanced_menu.getStateHexBackground().empty()) {
        ui->centralwidget->setStyleSheet(("background-color: " + advanced_menu.getStateHexBackground()).c_str());
    }
}

void MainWindow::setHighlightingLang_py_cycle(const char* path) {
    std::ifstream in(path);
    if(in.is_open()) {
        std::string textToWrite = "";
        in >> textToWrite;
        python_code_highlighter_cycle.setPattern(textToWrite.c_str());
        in.close();
    }
}

void MainWindow::setHighlightingLang_py_statements(const char* path) {
    std::ifstream in(path);
    if(in.is_open()) {
        std::string textToWrite = "";
        in >> textToWrite;
        python_code_highlighter_statements.setPattern(textToWrite.c_str());
        in.close();
    }
}

void MainWindow::setHighlightingCheck(QFile& in) {
    if(in.fileName().toStdString().substr(in.fileName().toStdString().length() - 5, in.fileName().toStdString().length()) == ".html") {
        highlight.m_syntaxHighLighter = new SyntaxHighlighter(dynamic_cast<QPlainTextEdit*>(editor_tabs->currentWidget())->document());
        highlight.m_htmlHightLighter = new HtmlHighLighter(dynamic_cast<QPlainTextEdit*>(editor_tabs->currentWidget())->document());
    } else if(in.fileName().toStdString().substr(in.fileName().toStdString().length() - 3, in.fileName().toStdString().length()) == ".py") {
        auto th_1 = std::async(std::launch::async, [this](){
            python_code_highlighter_cycle.setDocument(dynamic_cast<QPlainTextEdit*>(editor_tabs->currentWidget())->document());
            setHighlightingLang_py_cycle("res/py/py_cycle");
        });
        th_1.get();

        auto th = std::async(std::launch::async, [this]() {
             python_code_highlighter_statements.setDocument(dynamic_cast<QPlainTextEdit*>(editor_tabs->currentWidget())->document());
             setHighlightingLang_py_statements("res/py/py_statements");
        });

        th.get();
    }
}
