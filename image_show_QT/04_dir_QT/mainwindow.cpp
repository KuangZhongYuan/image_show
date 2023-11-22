#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>//消息提示弹窗
#include <QShortcut>//创建和管理键盘快捷键


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建一个新的QShortcut对象，设置其父窗口为当前窗口，设置其快捷键为向上箭头键
    QShortcut *shortcut1 = new QShortcut(QKeySequence(Qt::Key_Up), this);
    // 当快捷键被触发时，调用on_pushButton_up_clicked函数
    connect(shortcut1, &QShortcut::activated, this, &MainWindow::on_pushButton_up_clicked);

    // 创建一个新的QShortcut对象，设置其父窗口为当前窗口，设置其快捷键为向上箭头键
    QShortcut *shortcut2 = new QShortcut(QKeySequence(Qt::Key_Down), this);
    // 当快捷键被触发时，调用on_pushButton_up_clicked函数
    connect(shortcut2, &QShortcut::activated, this, &MainWindow::on_pushButton_down_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

#if 1//优化后的代码

void MainWindow::on_pushButton_opendir_clicked()
{
    dirPath = QFileDialog::getExistingDirectory(this);
    if (dirPath.isEmpty()) {
        // 用户取消了对话框或者没有选择任何目录，给出提示并返回
        QMessageBox::information(this, tr("提示"), tr("请选择一个目录"));
        return;
    }

    QDir dir(dirPath);
    QStringList filters;
    filters << "*.jpg"
            << "*.png"
            << "*.bmp"
            << "*.gif";
    dir.setNameFilters(filters);
    filenames = dir.entryList();

    if (filenames.isEmpty()) {
        // 没有找到任何图片文件，给出提示并返回
        QMessageBox::information(this, tr("提示"), tr("该目录下没有图片文件"));
        return;
    }

    ui->listWidget_dir->addItems(filenames);

    //默认从第一张开始显示
    pix_path = QString("%1/%2").arg(dirPath).arg(filenames[0]);
    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);
    ui->lineEdit->setText(pix_path);
}

//双击
void MainWindow::on_listWidget_dir_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->listWidget_dir->row(item);
    if (index < 0 || index >= ui->listWidget_dir->count()) {
        // 索引超出了范围，给出提示并返回
        QMessageBox::information(this, tr("提示"), tr("选中的项目无效"));
        return;
    }
    //显示图片并且打印信息
    pix_path = QString("%1/%2").arg(dirPath).arg(item->text());
    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);
    ui->lineEdit->setText(pix_path);
}

void MainWindow::on_pushButton_up_clicked() // 当点击"向上"按钮时，会调用此函数
{
    int currentRow = ui->listWidget_dir->currentRow(); // 获取当前选中的项目的行号

    //特殊情况的处理
    if (currentRow <= 0) { // 如果当前选中的项目是第一个项目
        // 将选中的项目切换到最后一个项目
        ui->listWidget_dir->setCurrentRow(ui->listWidget_dir->count() - 1);
    } else { // 如果当前选中的项目不是第一个项目
        // 将选中的项目切换到上一个项目
        ui->listWidget_dir->setCurrentRow(currentRow - 1);
    }

    // 获取当前选中的项目的文本，即文件名
    pix_path = QString("%1/%2").arg(dirPath).arg(ui->listWidget_dir->currentItem()->text());
    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);//显示图片并且打印信息
    ui->lineEdit->setText(pix_path);
}

void MainWindow::on_pushButton_down_clicked()
{
    int currentRow = ui->listWidget_dir->currentRow();//获取当前行
    //特殊情况
    if (currentRow >= ui->listWidget_dir->count() - 1) {
        // 已经是最后一个项目，将选中的项目切换到第一个项目
        ui->listWidget_dir->setCurrentRow(0);
    } else {
        ui->listWidget_dir->setCurrentRow(currentRow + 1);
    }

    // 获取当前选中的项目的文本，即文件名
    pix_path = QString("%1/%2").arg(dirPath).arg(ui->listWidget_dir->currentItem()->text());
    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);//显示图片并且打印信息
    ui->lineEdit->setText(pix_path);
}

#endif

#if 0 //之前的代码
void MainWindow::on_pushButton_opendir_clicked()
{
    //通过文件对话框，获取一个目录的绝对路径
    path = QFileDialog::getExistingDirectory(this);

    //构造目录对象
    QDir dir(path);

    //过滤器，只显示图片类
    QStringList filters;
    filters << "*.jpg" << "*.png" << "*.bmp" << "*.gif";
    dir.setNameFilters(filters);

    //调用接口 ，获取该目录下所有的文件名
    filenames = dir.entryList();
    qDebug() << filenames;//输出所有的文件名

    //移除当前目录和上一级目录
    filenames.removeOne(".");
    filenames.removeOne("..");


    //把文件名称显示到界面的列表控件
    ui->listWidget_dir->addItems(filenames);
    //默认从第一张开始显示
    QString pix_path = QString("%1/%2").arg(path).arg(filenames[0]);
    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);


}

void MainWindow::on_listWidget_dir_itemDoubleClicked(QListWidgetItem *item)
{
    //拼接图片路径
    QString pix_path = QString("%1/%2").arg(path).arg(item->text());
    ui->lineEdit->setText(pix_path);
    for(int i = 0; i < filenames.size() - 1; i++) {
        if(filenames[i] == item->text()) {
            suoyin = i;
            break;
        }
    }

    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);
}


void MainWindow::on_pushButton_up_clicked()
{
    if(suoyin == 0) {
        suoyin = filenames.size() - 1;
    }
    //拼接图片路径
    QString pix_path = QString("%1/%2").arg(path).arg(filenames[suoyin--]);
    ui->lineEdit->setText(pix_path);

    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);
}


void MainWindow::on_pushButton_down_clicked()
{
    //拼接图片路径
    QString pix_path = QString("%1/%2").arg(path).arg(filenames[suoyin++]);
    ui->lineEdit->setText(pix_path);

    QPixmap pix(pix_path);
    ui->label_pix->setPixmap(pix);
}

#endif

