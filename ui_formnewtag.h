/********************************************************************************
** Form generated from reading UI file 'formnewtag.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNEWTAG_H
#define UI_FORMNEWTAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton_apply;
    QLineEdit *lineEdit;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(410, 110);
        Form->setMinimumSize(QSize(342, 92));
        Form->setMaximumSize(QSize(410, 110));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_apply = new QPushButton(Form);
        pushButton_apply->setObjectName(QStringLiteral("pushButton_apply"));
        pushButton_apply->setMinimumSize(QSize(80, 21));
        pushButton_apply->setMaximumSize(QSize(80, 21));

        gridLayout->addWidget(pushButton_apply, 2, 2, 1, 1);

        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 3);

        pushButton_cancel = new QPushButton(Form);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setMinimumSize(QSize(80, 21));
        pushButton_cancel->setMaximumSize(QSize(80, 21));

        gridLayout->addWidget(pushButton_cancel, 2, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\275\320\276\320\262\320\276\320\263\320\276 \321\202\320\265\320\263\320\260:", Q_NULLPTR));
        pushButton_apply->setText(QApplication::translate("Form", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Form", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNEWTAG_H
