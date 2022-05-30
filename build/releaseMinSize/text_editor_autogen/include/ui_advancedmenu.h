/********************************************************************************
** Form generated from reading UI file 'advancedmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCEDMENU_H
#define UI_ADVANCEDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdvancedMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCheckBox *short_title_check_box;

    void setupUi(QMainWindow *AdvancedMenu)
    {
        if (AdvancedMenu->objectName().isEmpty())
            AdvancedMenu->setObjectName(QString::fromUtf8("AdvancedMenu"));
        AdvancedMenu->resize(733, 106);
        centralwidget = new QWidget(AdvancedMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        short_title_check_box = new QCheckBox(centralwidget);
        short_title_check_box->setObjectName(QString::fromUtf8("short_title_check_box"));

        horizontalLayout->addWidget(short_title_check_box);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        AdvancedMenu->setCentralWidget(centralwidget);

        retranslateUi(AdvancedMenu);

        QMetaObject::connectSlotsByName(AdvancedMenu);
    } // setupUi

    void retranslateUi(QMainWindow *AdvancedMenu)
    {
        AdvancedMenu->setWindowTitle(QApplication::translate("AdvancedMenu", "MainWindow", nullptr));
        label->setText(QApplication::translate("AdvancedMenu", "\320\241\320\276\320\272\321\200\320\260\321\211\320\265\320\275\320\275\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\276 \320\262\320\272\320\273\320\260\320\264\320\272\320\260\321\205", nullptr));
        short_title_check_box->setText(QApplication::translate("AdvancedMenu", "Short title", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdvancedMenu: public Ui_AdvancedMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCEDMENU_H
