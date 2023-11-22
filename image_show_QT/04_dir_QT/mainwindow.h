#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_pushButton_opendir_clicked();

        void on_listWidget_dir_itemDoubleClicked(QListWidgetItem *item);

        void on_pushButton_up_clicked();

        void on_pushButton_down_clicked();

    private:
        Ui::MainWindow *ui;
        QString dirPath;
        //QString path;
        QString pix_path;
        int suoyin = 0;
        QStringList filenames;
};
#endif // MAINWINDOW_H
