/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *action_saveAs;
    QAction *action_creat;
    QAction *action_exit;
    QAction *action_cut;
    QAction *action_copy;
    QAction *action_paste;
    QAction *action_find;
    QAction *action_delete;
    QAction *action_selectAll;
    QAction *action_about;
    QAction *action_aboutQt;
    QAction *action_viewTree;
    QAction *action_addAtr;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QTreeView *treeView_General;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_edit;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(964, 442);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QStringLiteral("action_save"));
        action_saveAs = new QAction(MainWindow);
        action_saveAs->setObjectName(QStringLiteral("action_saveAs"));
        action_creat = new QAction(MainWindow);
        action_creat->setObjectName(QStringLiteral("action_creat"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_cut = new QAction(MainWindow);
        action_cut->setObjectName(QStringLiteral("action_cut"));
        action_copy = new QAction(MainWindow);
        action_copy->setObjectName(QStringLiteral("action_copy"));
        action_paste = new QAction(MainWindow);
        action_paste->setObjectName(QStringLiteral("action_paste"));
        action_find = new QAction(MainWindow);
        action_find->setObjectName(QStringLiteral("action_find"));
        action_delete = new QAction(MainWindow);
        action_delete->setObjectName(QStringLiteral("action_delete"));
        action_selectAll = new QAction(MainWindow);
        action_selectAll->setObjectName(QStringLiteral("action_selectAll"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_aboutQt = new QAction(MainWindow);
        action_aboutQt->setObjectName(QStringLiteral("action_aboutQt"));
        action_viewTree = new QAction(MainWindow);
        action_viewTree->setObjectName(QStringLiteral("action_viewTree"));
        action_addAtr = new QAction(MainWindow);
        action_addAtr->setObjectName(QStringLiteral("action_addAtr"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(521, 0));

        gridLayout->addWidget(tableView, 0, 1, 2, 1);

        treeView_General = new QTreeView(centralWidget);
        treeView_General->setObjectName(QStringLiteral("treeView_General"));
        treeView_General->setMaximumSize(QSize(256, 16777215));

        gridLayout->addWidget(treeView_General, 0, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 964, 20));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_edit = new QMenu(menuBar);
        menu_edit->setObjectName(QStringLiteral("menu_edit"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_edit->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu_file->addAction(action_creat);
        menu_file->addAction(action_open);
        menu_file->addAction(action_saveAs);
        menu_file->addAction(action_save);
        menu_file->addSeparator();
        menu_file->addAction(action_exit);
        menu_edit->addAction(action_cut);
        menu_edit->addAction(action_copy);
        menu_edit->addAction(action_paste);
        menu_edit->addAction(action_delete);
        menu_edit->addAction(action_selectAll);
        menu_edit->addSeparator();
        menu_edit->addAction(action_addAtr);
        menu_edit->addSeparator();
        menu_edit->addAction(action_find);
        menu->addAction(action_about);
        menu->addAction(action_aboutQt);
        menu_2->addAction(action_viewTree);
        mainToolBar->addAction(action_viewTree);
        mainToolBar->addAction(action_open);
        mainToolBar->addAction(action_addAtr);
        mainToolBar->addAction(action_find);
        mainToolBar->addAction(action_delete);
        mainToolBar->addAction(action_exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214. . .", Q_NULLPTR));
        action_open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        action_save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        action_save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        action_saveAs->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272. . .", Q_NULLPTR));
        action_saveAs->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", Q_NULLPTR));
        action_creat->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        action_creat->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
        action_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        action_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        action_cut->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\200\320\265\320\267\320\260\321\202\321\214", Q_NULLPTR));
        action_cut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
        action_copy->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        action_copy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
        action_paste->setText(QApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        action_paste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
        action_find->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
        action_find->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
        action_delete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        action_selectAll->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", Q_NULLPTR));
        action_about->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        action_aboutQt->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265 Qt Creator", Q_NULLPTR));
        action_viewTree->setText(QApplication::translate("MainWindow", "&\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214 \320\264\320\265\321\200\320\265\320\262\320\260", Q_NULLPTR));
        action_addAtr->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\260\321\202\321\200\320\270\320\261\321\203\321\202", Q_NULLPTR));
        menu_file->setTitle(QApplication::translate("MainWindow", "&\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menu_edit->setTitle(QApplication::translate("MainWindow", "&\320\237\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262&\320\272\320\260", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "&\320\222\320\270\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
