#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

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
    QString fn = QFileDialog::getOpenFileName(this,      tr("Открыть файл..."),
                                              QString(), tr("XML (*.xml);;Все файлы (*)"));
    if (!fn.isEmpty())
        load(fn);

    //  Исходный файл разбиваем на список строк: QStringList all_textFile;

    QFile mFile(fileName);
    if( !mFile.open(QIODevice::ReadOnly) ) {
        QMessageBox::warning(this, tr("Error"),
                             tr("Cannot read file %1:\n%2.")
                            .arg(mFile.fileName())
                            .arg(mFile.errorString()));
        buttView = true;
        return;
    }
    QTextStream stream(&mFile);
    QString buffer;
    while (!stream.atEnd()) {
        buffer = stream.readLine();
        QString tab = "";
        while ( buffer[0] == "\t" ) {
            buffer.remove(0,1);
            tab += " ";
        }
        bu += tab + buffer + "\n";

        all_textFile << tr("%1%2").arg(tab).arg(buffer);
    }

    getFile(all_textFile);
    all_textFile.clear();

    ui->statusBar->showMessage("Файл открыт");
    buttView = false;

    mFile.flush();
    mFile.close();
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

bool MainWindow::load(const QString &f)
{
    if (!QFile::exists(f))
        return false;
    QFile file(f);
    if (!file.open(QFile::ReadOnly))
        return false;

    setCurrentFileName(f);
    return true;
}

void MainWindow::setCurrentFileName(const QString &fileName)
{
    this->fileName = fileName;
    QString shownName;
    if (fileName.isEmpty())
        shownName = "untitled.objects";
    else {
        shownName = QFileInfo(fileName).fileName();
        setWindowTitle(tr("%1%2[*]").arg("Редактор xml - ").arg(shownName));
    }
    setWindowModified(false);
}

void MainWindow::getFile(const QStringList &all_textFile)
{
/*****!    Загрузка  файла в объект QStringList all_textFile    *****/
/*****!         Без символов табуляции в начале строки          *****/
    this->all_textFile = all_textFile;

//    model = new TreeView(all_textFile, this);
//    ui->treeView_General->setModel(model);

    ui->treeView_General->setHidden(buttView);
}

