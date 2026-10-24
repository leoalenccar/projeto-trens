#include "trem.h"
#include <QtCore>

// Construtor
Trem::Trem(int ID, int x, int y)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 200;
}

QMutex Trem::mutexab;
QMutex Trem::mutexac;
QMutex Trem::mutexbc;
QMutex Trem::mutexbd;
QMutex Trem::mutexbe;
QMutex Trem::mutexce;
QMutex Trem::mutexcf;
QMutex Trem::mutexde;
QMutex Trem::mutexef;

// Função a ser executada após executar trem->START
void Trem::run()
{
    while (true)
    {
        if (velocidade == 0)
        {
            msleep(50);
            continue;
        }

        // trilho ab
        if (ID == 1 && x == 195 && y == 130) mutexab.lock();
        if (ID == 2 && x == 465 && y == 170) mutexab.lock();

        // trilho ac
        if (ID == 1 && x == 435 && y == 150) mutexac.lock();
        if (ID == 3 && x == 735 && y == 180) mutexac.lock();

        // trilho bc
        if (ID == 2 && x == 435 && y == 270) mutexbc.lock();
        if (ID == 3 && x == 495 && y == 150) mutexbc.lock();

        // trilho bd
        if (ID == 2 && x == 195 && y == 250) mutexbd.lock();
        if (ID == 4 && x == 330 && y == 290) mutexbd.lock();

        // trilho be
        if (ID == 2 && x == 295 && y == 270) mutexbe.lock();
        if (ID == 5 && x == 500 && y == 270) mutexbe.lock();

        // trilho ce
        if (ID == 3 && x == 465 && y == 240) mutexce.lock();
        if (ID == 5 && x == 600 && y == 280) mutexce.lock();

        // trilho cf
        if (ID == 3 && x == 575 && y == 270) mutexcf.lock();
        if (ID == 6 && x == 760 && y == 270) mutexcf.lock();

        // trilho de
        if (ID == 4 && x == 300 && y == 390) mutexde.lock();
        if (ID == 5 && x == 360 && y == 270) mutexde.lock();

        // trilho ef
        if (ID == 5 && x == 570 && y == 390) mutexef.lock();
        if (ID == 6 && x == 630 && y == 270) mutexef.lock();

        switch (ID)
        {
        case 1: // Trem 1
            if (y < 150 && x == 195)
                y += 5;
            else if (x < 735 && y == 150)
                x += 5;
            else if (x == 735 && y > 30)
                y -= 5;
            else
                x -= 5;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 2: // Trem 2
            if (y < 270 && x == 195)
                y += 5;
            else if (x < 465 && y == 270)
                x += 5;
            else if (x == 465 && y > 150)
                y -= 5;
            else
                x -= 5;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 3:
            if (y < 270 && x == 465)
                y += 5;
            else if (x < 735 && y == 270)
                x += 5;
            else if (x == 735 && y > 150)
                y -= 5;
            else
                x -= 5;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 4:
            if (y < 390 && x == 60)
                y += 5;
            else if (x < 330 && y == 390)
                x += 5;
            else if (x == 330 && y > 270)
                y -= 5;
            else
                x -= 5;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 5:
            if (y < 390 && x == 330)
                y += 5;
            else if (x < 600 && y == 390)
                x += 5;
            else if (x == 600 && y > 270)
                y -= 5;
            else
                x -= 5;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 6:
            if (y < 390 && x == 600)
                y += 5;
            else if (x < 870 && y == 390)
                x += 5;
            else if (x == 870 && y > 270)
                y -= 5;
            else
                x -= 5;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        default:
            break;
        }

        // trilho ab
        if (ID == 1 && x == 505 && y == 150) mutexab.unlock();
        if (ID == 2 && x == 195 && y == 180) mutexab.unlock();

        // trilho ac
        if (ID == 1 && x == 735 && y == 130) mutexac.unlock();
        if (ID == 3 && x == 465 && y == 170) mutexac.unlock();

        // trilho bc
        if (ID == 2 && x == 435 && y == 150) mutexbc.unlock();
        if (ID == 3 && x == 495 && y == 270) mutexbc.unlock();

        // trilho bd
        if (ID == 2 && x == 365 && y == 270) mutexbd.unlock();
        if (ID == 4 && x == 160 && y == 270) mutexbd.unlock();

        // trilho be
        if (ID == 2 && x == 465 && y == 240) mutexbe.unlock();
        if (ID == 5 && x == 330 && y == 300) mutexbe.unlock();

        // trilho ce
        if (ID == 3 && x == 625 && y == 270) mutexce.unlock();
        if (ID == 5 && x == 440 && y == 270) mutexce.unlock();

        // trilho cf
        if (ID == 3 && x == 735 && y == 250) mutexcf.unlock();
        if (ID == 6 && x == 600 && y == 290) mutexcf.unlock();

        // trilho de
        if (ID == 4 && x == 300 && y == 270) mutexde.unlock();
        if (ID == 5 && x == 360 && y == 390) mutexde.unlock();

        // trilho de
        if (ID == 5 && x == 570 && y == 270) mutexef.unlock();
        if (ID == 6 && x == 630 && y == 390) mutexef.unlock();

        msleep(201 - velocidade);
    }
}

void Trem::setVelocidade(int value)
{
    velocidade = value;
}