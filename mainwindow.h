#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

class TreeModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void creatAction();
//    void creatToolBar();
    void setContextMenu();
    void form_editing();

    bool loadFile();
    void setCurrentFileName(const QString &fileName);
    void getFile(const QStringList &text);
    void initModel(QStringList &textFile);

private slots:
    void on_action_open_triggered();
    void on_action_aboutQt_triggered();
    void on_action_exit_triggered();

    void on_action_viewTree_triggered();

private:
    QMap<QString, QStringList> m_fullText;

    TreeModel *m_treeModel;
    bool buttView;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
