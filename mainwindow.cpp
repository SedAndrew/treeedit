#include "mainwindow.h"
#include "../Billd_Project_EditXMLFile/ui_mainwindow.h"

#include <QDebug>
#include <QMap>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include <tree/treemodel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Редактор xml");
    setWindowIcon(QIcon(":/icon/apptree.png"));
    creatAction();
    setContextMenu();
    setCurrentFileName(QString());
    on_action_open_triggered();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::creatAction()
{
    ui->action_creat->setIcon(  QIcon(":/icon/new.png"));
    ui->action_open->setIcon(   QIcon(":/icon/open.png"));
    ui->action_save->setIcon(   QIcon(":/icon/save.png"));
    ui->action_saveAs->setIcon( QIcon(":/icon/saveAs.png"));
    ui->action_exit->setIcon(   QIcon(":/icon/exit.png"));
    ui->action_cut->setIcon(    QIcon(":/icon/cut.png"));
    ui->action_copy->setIcon(   QIcon(":/icon/copy.png"));
    ui->action_paste->setIcon(  QIcon(":/icon/paste.png"));
    ui->action_delete->setIcon( QIcon(":/icon/delete.png"));
    ui->action_addAtr->setIcon( QIcon(":/icon/addAtr.png"));
    ui->action_find->setIcon(   QIcon(":/icon/find.png"));
    ui->action_viewTree->setIcon(QIcon(":/icon/view.png"));
    ui->action_about->setIcon(  QIcon(":/icon/about.png"));
}

void MainWindow::setContextMenu()
{
    ui->tableView->addAction(ui->action_copy);
    ui->tableView->addAction(ui->action_paste);
    ui->tableView->addAction(ui->action_addAtr);
    ui->tableView->addAction(ui->action_delete);
    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::on_action_open_triggered() // Открыть файл
{
    loadFile();
}

void MainWindow::on_action_aboutQt_triggered() // Описание Qt
{
    QMessageBox* mess = new QMessageBox(this);
    mess->aboutQt(this,"Информация о программе Qt Creator");
}

void MainWindow::on_action_exit_triggered() // Завершить программу
{
    close();
}

void MainWindow::on_action_viewTree_triggered()
{
    if(!buttView) {
        buttView = true;
        ui->treeView_General->setHidden(buttView);
    }
    else {
        buttView = false;
        ui->treeView_General->setHidden(buttView);
    }
}

bool MainWindow::loadFile()
{
    QString path = QFileDialog::getOpenFileName(this,      tr("Открыть файл..."),
                                    QString(), tr("XML (*.xml);;Все файлы (*)"));
    if (path.isEmpty())
    {
        qDebug() << "No file name specified";
        ui->treeView_General->setHidden(true);
        return false;
    }

    QFile file(path);
    if (!file.exists()){
        qDebug() << "File not found!";
        ui->treeView_General->setHidden(true);
        return false;
    }
    if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Error"),
                                    tr("Access error!"),
                                     tr("Cannot read file %1:\n%2.")
                                     .arg(file.fileName())
                                     .arg(file.errorString()));
        qDebug() << "Access error!";
        ui->treeView_General->setHidden(true);
        return false;
    }
    setCurrentFileName(path);

    QTextStream stream(&file);
    QStringList fullText;
    while (!stream.atEnd()) {
        QString input = stream.readLine();
        QString indent = ""; // отступ
        while ( input[0] == "\t" ) {
            input.remove(0,1);
            indent += " ";
        }
        input = indent + input + "\n";
        fullText << input;
    }
    m_fullText.insert(path, fullText);

    ui->treeView_General->setHidden(buttView);
    ui->statusBar->showMessage(QString("Open the file: %1").arg(path));
    buttView = false;

    file.flush();
    file.close();

    QMap<QString, QStringList>::iterator iter = m_fullText.begin();
    QVariant cur = iter.value();
    QStringList str = cur.toStringList();
    initModel(str);
//    qDebug() << iter.value().at(0);

    return true;
}

void MainWindow::setCurrentFileName(const QString &fileName)
{
    QString defaultName;
    if (fileName.isEmpty())
        defaultName = "untitled.objects";
    else {
        defaultName = QFileInfo(fileName).fileName();
    }
    setWindowTitle(tr("%1%2[*]").arg("Редактор xml - ").arg(defaultName));
    setWindowModified(false);
}

void MainWindow::getFile(const QStringList &text)
{
    Q_UNUSED(text)
/*****!    Загрузка  файла в объект QStringList fullText    *****/
/*****!         Без символов табуляции в начале строки          *****/
//    fullText = text;

//    model = new TreeView(fullText, this);
//    ui->treeView_General->setModel(model);

    //    ui->treeView_General->setHidden(buttView);
}

void MainWindow::initModel(QStringList &textFile)
{
    for (int i = 0; i < textFile.size(); i++) {
        qDebug() << textFile.at(i);
    }
    m_treeModel = new TreeModel(textFile);
    ui->treeView_General->setModel(m_treeModel);
    ui->treeView_General->setHidden(buttView);


}



