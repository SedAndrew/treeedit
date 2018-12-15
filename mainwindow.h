#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>


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

    bool load(const QString &f);
    void setCurrentFileName(const QString &fileName);
    void getFile(const QStringList &all_textFile);

private slots:
    void on_action_open_triggered();
    void on_action_aboutQt_triggered();
    void on_action_exit_triggered();

private:
    QString fileName;


    bool buttView;
    QString bu;
    QStringList all_textFile;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
