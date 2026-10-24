#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Cria o trem com seu (ID, posição X, posição Y)
    trem_a = new Trem(1, 465, 30);
    trem_b = new Trem(2, 195, 210);
    trem_c = new Trem(3, 735, 210);
    trem_d = new Trem(4, 60, 330);
    trem_e = new Trem(5, 460, 390);
    trem_f = new Trem(6, 870, 330);
    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem_a, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    connect(trem_b, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    connect(trem_c, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    connect(trem_d, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    connect(trem_e, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    connect(trem_f, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));

    // inicializa os slider
    ui->horizontalSlider_a->setRange(0, 200);
    ui->horizontalSlider_a->setValue(15);
    ui->horizontalSlider_b->setRange(0, 200);
    ui->horizontalSlider_b->setValue(15);
    ui->horizontalSlider_c->setRange(0, 200);
    ui->horizontalSlider_c->setValue(15);
    ui->horizontalSlider_d->setRange(0, 200);
    ui->horizontalSlider_d->setValue(15);
    ui->horizontalSlider_e->setRange(0, 200);
    ui->horizontalSlider_e->setValue(15);
    ui->horizontalSlider_f->setRange(0, 200);
    ui->horizontalSlider_f->setValue(15);
    ui->horizontalSlider_m->setRange(0, 200);
    ui->horizontalSlider_m->setValue(15);

    trem_a->start();
    trem_b->start();
    trem_c->start();
    trem_d->start();
    trem_e->start();
    trem_f->start();
}

// Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y)
{
    switch (id)
    {
    case 1: // Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem_a->setGeometry(x, y, 20, 15);
        break;
    case 2: // Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem_b->setGeometry(x, y, 20, 15);
        break;
    case 3:
        ui->label_trem_c->setGeometry(x, y, 20, 15);
        break;
    case 4:
        ui->label_trem_d->setGeometry(x, y, 20, 15);
        break;
    case 5:
        ui->label_trem_e->setGeometry(x, y, 20, 15);
        break;
    case 6:
        ui->label_trem_f->setGeometry(x, y, 20, 15);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_a_valueChanged(int value)
{
    trem_a->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_b_valueChanged(int value)
{
    trem_b->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_c_valueChanged(int value)
{
    trem_c->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_d_valueChanged(int value)
{
    trem_d->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_e_valueChanged(int value)
{
    trem_e->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_f_valueChanged(int value)
{
    trem_f->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_m_valueChanged(int value)
{
    trem_a->setVelocidade(value);
    trem_b->setVelocidade(value);
    trem_c->setVelocidade(value);
    trem_d->setVelocidade(value);
    trem_e->setVelocidade(value);
    trem_f->setVelocidade(value);

    ui->horizontalSlider_a->setValue(value);
    ui->horizontalSlider_b->setValue(value);
    ui->horizontalSlider_c->setValue(value);
    ui->horizontalSlider_d->setValue(value);
    ui->horizontalSlider_e->setValue(value);
    ui->horizontalSlider_f->setValue(value);
}
