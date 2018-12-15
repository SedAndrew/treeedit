/********************************************************************************
** Form generated from reading UI file 'form_newatr.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_NEWATR_H
#define UI_FORM_NEWATR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_newAtr
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *textEdit_val;
    QLineEdit *lineEdit_tag;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_apply;

    void setupUi(QWidget *Form_newAtr)
    {
        if (Form_newAtr->objectName().isEmpty())
            Form_newAtr->setObjectName(QStringLiteral("Form_newAtr"));
        Form_newAtr->resize(588, 302);
        Form_newAtr->setMinimumSize(QSize(518, 173));
        Form_newAtr->setMaximumSize(QSize(588, 302));
        verticalLayout = new QVBoxLayout(Form_newAtr);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Form_newAtr);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textEdit_val = new QTextEdit(Form_newAtr);
        textEdit_val->setObjectName(QStringLiteral("textEdit_val"));

        gridLayout->addWidget(textEdit_val, 2, 1, 1, 1);

        lineEdit_tag = new QLineEdit(Form_newAtr);
        lineEdit_tag->setObjectName(QStringLiteral("lineEdit_tag"));

        gridLayout->addWidget(lineEdit_tag, 0, 1, 1, 1);

        label_2 = new QLabel(Form_newAtr);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(Form_newAtr);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);

        pushButton_apply = new QPushButton(Form_newAtr);
        pushButton_apply->setObjectName(QStringLiteral("pushButton_apply"));

        horizontalLayout_3->addWidget(pushButton_apply);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Form_newAtr);

        QMetaObject::connectSlotsByName(Form_newAtr);
    } // setupUi

    void retranslateUi(QWidget *Form_newAtr)
    {
        Form_newAtr->setWindowTitle(QApplication::translate("Form_newAtr", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form_newAtr", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \321\202\320\265\320\263\320\260: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form_newAtr", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265: ", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Form_newAtr", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        pushButton_apply->setText(QApplication::translate("Form_newAtr", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form_newAtr: public Ui_Form_newAtr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_NEWATR_H
