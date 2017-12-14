#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItem"
#include "redis.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(3,2,this); //3 record 2 field
        model -> setHorizontalHeaderItem(0, new QStandardItem(QString("Nis")));
        model -> setHorizontalHeaderItem(1, new QStandardItem(QString("Nama")));

    ui -> tableView -> setModel(model);
    QString nisa,namaa;

        nisa = ui -> lineEdit_nis-> text();
        namaa = ui -> lineEdit_nama -> text();

    redis rds;
        QStringList rediss = rds.reqRedis("HMSET myhash Nis '"+nisa+"' Nama '"+namaa+"'  ", "127.0.0.1", 6379);

    QStandardItem *nis =  new QStandardItem(QString("")) ;
    model -> setItem(0,0,nis);
    QStandardItem *nama =  new QStandardItem(QString("")) ;
    model -> setItem(0,1,nama);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nisa,namaa;

        nisa = ui -> lineEdit_nis-> text();
        namaa = ui -> lineEdit_nama -> text();

        redis rds;
        QStringList result_nis = rds.reqRedis("SET Nis '"+nisa+"' ", "127.0.0.1", 6379);
        QStringList result_nama = rds.reqRedis("SET Nama '"+namaa+"' ", "127.0.0.1", 6379);

        QMessageBox msgBox;
        msgBox.setText("Penambahan data berhasil");
        msgBox.exec();

        QStandardItemModel *model = new QStandardItemModel(3,2,this); //3 record 2 field
        model -> setHorizontalHeaderItem(0,new QStandardItem(QString("Nis")));
        model -> setHorizontalHeaderItem(1,new QStandardItem(QString("Nama")));

        ui -> tableView -> setModel(model);

        QStandardItem *nis =  new QStandardItem(QString(nisa)) ;
        model -> setItem(0,0,nis);
        QStandardItem *nama =  new QStandardItem(QString(namaa)) ;
        model -> setItem(0,1,nama);

    }


void MainWindow::on_pushButton_3_clicked()
{
    QString nisa,namaa;

        nisa = ui -> lineEdit_nis-> text();
        namaa = ui -> lineEdit_nama -> text();

        redis rds;
        QStringList result_nis = rds.reqRedis("DEL Nis '"+nisa+"' ", "127.0.0.1", 6379);
        QStringList result_nama = rds.reqRedis("DEL Nama '"+namaa+"' ", "127.0.0.1", 6379);

        QMessageBox msgBox;
        msgBox.setText("Data berhasil dihapus");
        msgBox.exec();

        QStandardItemModel *model = new QStandardItemModel(3,2,this); //3 record 2 field
        model -> setHorizontalHeaderItem(0,new QStandardItem(QString("Nis")));
        model -> setHorizontalHeaderItem(1,new QStandardItem(QString("Nama")));

        ui -> tableView -> setModel(model);

        QStandardItem *nis =  new QStandardItem(QString("")) ;
        model -> setItem(1,0,nis);
        QStandardItem *nama =  new QStandardItem(QString("")) ;
        model -> setItem(1,1,nama);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui -> lineEdit_nama -> setText("");
    ui -> lineEdit_nis -> setText("");
}



void MainWindow::on_pushButton_2_clicked()
{
    QString nisa,namaa;

        nisa = ui -> lineEdit_nis-> text();
        namaa = ui -> lineEdit_nama -> text();

        redis rds;
        QStringList result_nis = rds.reqRedis("SET Nis '"+nisa+"' ", "127.0.0.1", 6379);
        QStringList result_nama = rds.reqRedis("SET Nama '"+namaa+"' ", "127.0.0.1", 6379);

        QMessageBox msgBox;
        msgBox.setText("Perubahan data telah berhasil");
        msgBox.exec();

        QStandardItemModel *model = new QStandardItemModel(3,2,this); //3 record 2 field
        model -> setHorizontalHeaderItem(0,new QStandardItem(QString("Nis")));
        model -> setHorizontalHeaderItem(1,new QStandardItem(QString("Nama")));

        ui -> tableView -> setModel(model);

        QStandardItem *nis =  new QStandardItem(QString(nisa)) ;
        model -> setItem(0,0,nis);
        QStandardItem *nama =  new QStandardItem(QString(namaa)) ;
        model -> setItem(0,1,nama);
}
