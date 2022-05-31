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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdvancedMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QCheckBox *short_title_check_box;
    QLabel *label_2;
    QCheckBox *movable_tabs_check_box;
    QPushButton *submit_changes_button;

    void setupUi(QMainWindow *AdvancedMenu)
    {
        if (AdvancedMenu->objectName().isEmpty())
            AdvancedMenu->setObjectName(QString::fromUtf8("AdvancedMenu"));
        AdvancedMenu->resize(484, 121);
        centralwidget = new QWidget(AdvancedMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        short_title_check_box = new QCheckBox(centralwidget);
        short_title_check_box->setObjectName(QString::fromUtf8("short_title_check_box"));
        short_title_check_box->setChecked(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, short_title_check_box);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        movable_tabs_check_box = new QCheckBox(centralwidget);
        movable_tabs_check_box->setObjectName(QString::fromUtf8("movable_tabs_check_box"));
        movable_tabs_check_box->setChecked(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, movable_tabs_check_box);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        submit_changes_button = new QPushButton(centralwidget);
        submit_changes_button->setObjectName(QString::fromUtf8("submit_changes_button"));

        gridLayout->addWidget(submit_changes_button, 1, 0, 1, 1);

        AdvancedMenu->setCentralWidget(centralwidget);

        retranslateUi(AdvancedMenu);

        QMetaObject::connectSlotsByName(AdvancedMenu);
    } // setupUi

    void retranslateUi(QMainWindow *AdvancedMenu)
    {
        AdvancedMenu->setWindowTitle(QApplication::translate("AdvancedMenu", "MainWindow", nullptr));
        label->setText(QApplication::translate("AdvancedMenu", "\320\241\320\276\320\272\321\200\320\260\321\211\320\265\320\275\320\275\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\276 \320\262\320\272\320\273\320\260\320\264\320\272\320\260\321\205", nullptr));
        short_title_check_box->setText(QApplication::translate("AdvancedMenu", "Short title", nullptr));
        label_2->setText(QApplication::translate("AdvancedMenu", "\320\237\320\276\320\264\320\262\320\270\320\266\320\275\320\276\321\201\321\202\321\214 \320\262\320\272\320\273\320\260\320\264\320\276\320\272", nullptr));
        movable_tabs_check_box->setText(QApplication::translate("AdvancedMenu", "Movable of tabs", nullptr));
        submit_changes_button->setText(QApplication::translate("AdvancedMenu", "Submit changes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdvancedMenu: public Ui_AdvancedMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCEDMENU_H
