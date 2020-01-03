#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<string>
#include<QtSql/QSqlDatabase>
#include<QMessageBox>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>
#include<QVariantList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_int_stack.append(0);



    ui->setupUi(this);
    ui->textBrowser->setText(QString::number(m_int_stack.top()));

    QString button_style = "QPushButton{background-color:white;color: black;}"
           "QPushButton:hover{background-color:silver; color: black;}"
          "QPushButton:pressed{background-color:gray;color:black}";



      QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");

      db.setHostName("localhost");
      db.setUserName("root");
      db.setPassword("123456");
      db.setDatabaseName("qt_test");
      if(!db.open()){
          QMessageBox::warning(this,"db open error",db.lastError().text());
          return;
      }

      // read info from db formulas;
      QString str=QString("select * from formulas;");
      QSqlQuery qsearch;
      qsearch.exec(str);
      while(qsearch.next()){
         // qDebug()<<qsearch.value("formula").toString();
          ui->textEdit->append(qsearch.value("formula").toString());
      }

//      QSqlQuery qcreate;
//      qcreate.exec("create table formulas(num integer primary key auto_increment, formula varchar(255))");

//      QSqlQuery qinsert;
//      QString str= QString(" insert into formulas(formula) values('1+2=3')");
//      qinsert.exec(str);
//      qinsert.prepare("insert into formulas(num,formula) values(?,?);");
//      //QVariantList numList;
//      QVariantList formulaList;
//      //numList<<1<<2<<3;
//      formulaList<<"1+2=3"<<"2*3=6"<<"11-1=10";
//      //qinsert.addBindValue(numList);
//      qinsert.addBindValue(formulaList);
//      qinsert.execBatch();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOne_clicked()
{
    number_clicked(1);
}

void MainWindow::on_pushButtonTwo_clicked()
{
    number_clicked(2);
}


void MainWindow::on_pushButtonThree_clicked()
{
   number_clicked(3);

}

void MainWindow::on_pushButtonFour_clicked()
{
    number_clicked(4);

}

void MainWindow::on_pushButtonFive_clicked()
{
    number_clicked(5);

}

void MainWindow::on_pushButtonSix_clicked()
{
    number_clicked(6);
}

void MainWindow::on_pushButtonSeven_clicked()
{
    number_clicked(7);

}

void MainWindow::on_pushButtonEight_clicked()
{
   number_clicked(8);
}

void MainWindow::on_pushButtonNine_clicked()
{
    number_clicked(9);
}

void MainWindow::on_pushButtonZero_clicked()
{

       number_clicked(0);
}
void MainWindow::on_pushButton_plus_clicked()
{
    if(m_last_input==true){
        if(!m_char_stack.empty()){
            int a = m_int_stack.pop();
            int b = m_int_stack.pop();
            int iresult=0;
            switch(m_char_stack.pop()){
                case '+': {
                            iresult = a+b;
                            m_int_stack.append(iresult);
                            this->ui->textBrowser->setText(QString::number(iresult));
                            break;}
                case '-': {
                iresult = b-a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '*': {
                iresult = a*b;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '/': {
                iresult = b/a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                default:break;
            }
        }
        m_char_stack.append('+');
        m_last_input =false;
    }
}

void MainWindow::on_pushButton_equal_clicked()
{
    if(m_last_input==true){
        if(!m_char_stack.empty()){
            QString myformula="";
            int a = m_int_stack.pop();
            int b = m_int_stack.pop();
            myformula+=QString::number(b);
            int iresult = 0;
            switch(m_char_stack.pop()){
            case '+': {
                        myformula+="+";

                        myformula+=QString::number(a);

                        myformula+="=";

                        iresult = a+b;
                        m_int_stack.append(iresult);
                        this->ui->textBrowser->setText(QString::number(iresult));
                        myformula+=QString::number(iresult);

                        this->ui->textEdit->append(myformula);
                        qDebug()<<myformula;
                        QString str=QString("insert into formulas(formula) values('%1');").arg(myformula);
                        QSqlQuery query;
                        query.exec(str);
                        break;
                       }
                case '-':{
                myformula+="-";

                myformula+=QString::number(a);

                myformula+="=";

                iresult = b-a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                myformula+=QString::number(iresult);

                this->ui->textEdit->append(myformula);
                qDebug()<<myformula;
                QString str=QString("insert into formulas(formula) values('%1');").arg(myformula);
                QSqlQuery query;
                query.exec(str);
                break;
               }
                case '*':{
                myformula+="*";

                myformula+=QString::number(a);

                myformula+="=";

                iresult = a*b;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                myformula+=QString::number(iresult);

                this->ui->textEdit->append(myformula);
                qDebug()<<myformula;
                QString str=QString("insert into formulas(formula) values('%1');").arg(myformula);
                QSqlQuery query;
                query.exec(str);
                break;

               }
                case '/':{
                myformula+="/";

                myformula+=QString::number(a);

                myformula+="=";

                iresult = b/a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                myformula+=QString::number(iresult);

                this->ui->textEdit->append(myformula);
                qDebug()<<myformula;
                QString str=QString("insert into formulas(formula) values('%1');").arg(myformula);
                QSqlQuery query;
                query.exec(str);
                break;
               }
                default:break;
            }
        }
        m_last_input=false;

    }
}

void MainWindow::on_pushButton_sub_clicked()
{
    if(m_last_input==true){
        if(!m_char_stack.empty()){
            int a = m_int_stack.pop();
            int b = m_int_stack.pop();
            int iresult=0;
            switch(m_char_stack.pop()){
                case '+': {
                            iresult = a+b;
                            m_int_stack.append(iresult);
                            this->ui->textBrowser->setText(QString::number(iresult));
                            break;}
                case '-': {
                iresult = b-a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '*': {
                iresult = a*b;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '/': {
                iresult = b/a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                default:break;
            }
        }
        m_char_stack.append('-');
        m_last_input =false;
    }
}

void MainWindow::on_pushButton_multi_clicked()
{
    if(m_last_input==true){
        if(!m_char_stack.empty()){
            int a = m_int_stack.pop();
            int b = m_int_stack.pop();
            int iresult=0;
            switch(m_char_stack.pop()){
                case '+': {
                            iresult = a+b;
                            m_int_stack.append(iresult);
                            this->ui->textBrowser->setText(QString::number(iresult));
                            break;}
                case '-': {
                iresult =b-a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '*': {
                iresult = a*b;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '/': {
                iresult = b/a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                default:break;
            }
        }
        m_char_stack.append('*');
        m_last_input =false;
    }
}

void MainWindow::on_pushButton_division_clicked()
{
    if(m_last_input==true){
        if(!m_char_stack.empty()){
            int a = m_int_stack.pop();
            int b = m_int_stack.pop();
            int iresult=0;
            switch(m_char_stack.pop()){
                case '+': {
                            iresult = a+b;
                            m_int_stack.append(iresult);
                            this->ui->textBrowser->setText(QString::number(iresult));
                            break;}
                case '-': {
                iresult = b-a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '*': {
                iresult = a*b;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                case '/': {
                iresult = b/a;
                m_int_stack.append(iresult);
                this->ui->textBrowser->setText(QString::number(iresult));
                break;}
                default:break;
            }
        }
        m_char_stack.append('/');
        m_last_input =false;
    }
}

void MainWindow::number_clicked(int num){
    if(m_last_input==true){
        int inum=10*m_int_stack.pop()+num;
        m_int_stack.append(inum);
        this->ui->textBrowser->setText(QString::number(inum));
    }
    else{
            m_int_stack.append(num);
            this->ui->textBrowser->setText(QString::number(num));
    }
    m_last_input=true;
}

