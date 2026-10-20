#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateInterface(int, int, int);

private slots:

    void on_horizontalSlider_a_valueChanged(int value);
    void on_horizontalSlider_b_valueChanged(int value);
    void on_horizontalSlider_c_valueChanged(int value);
    void on_horizontalSlider_d_valueChanged(int value);
    void on_horizontalSlider_e_valueChanged(int value);
    void on_horizontalSlider_f_valueChanged(int value);
    void on_horizontalSlider_m_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    // Cria os objetos TREM's
    Trem *trem_a;
    Trem *trem_b;
    Trem *trem_c;
    Trem *trem_d;
    Trem *trem_e;
    Trem *trem_f;
};

#endif // MAINWINDOW_H
