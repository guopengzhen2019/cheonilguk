#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStack>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void number_clicked(int num);
    ~MainWindow();

private slots:
    void on_pushButtonOne_clicked();

    void on_pushButtonTwo_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButtonThree_clicked();

    void on_pushButtonFour_clicked();

    void on_pushButtonFive_clicked();

    void on_pushButtonSix_clicked();

    void on_pushButtonSeven_clicked();

    void on_pushButtonEight_clicked();

    void on_pushButtonNine_clicked();

    void on_pushButtonZero_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_multi_clicked();

    void on_pushButton_division_clicked();


private:
    Ui::MainWindow *ui;
    QStack<int> m_int_stack;
    QStack<char> m_char_stack;
    bool m_last_input=true;//true is int ,false is char;
};

#endif // MAINWINDOW_H
