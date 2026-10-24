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
        if (ID == 1 && x == 195 && y == 135) mutexab.lock();
        if (ID == 2 && x == 465 && y == 165) mutexab.lock();

        // trilho ac
        if (ID == 1 && x == 445 && y == 150) mutexac.lock();
        if (ID == 3 && x == 735 && y == 165) mutexac.lock();

        // trilho bc
        if (ID == 2 && x == 445 && y == 270) mutexbc.lock();
        if (ID == 3 && x == 485 && y == 150) mutexbc.lock();

        // trilho bd
        if (ID == 2 && x == 195 && y == 255) mutexbd.lock();
        if (ID == 4 && x == 330 && y == 285) mutexbd.lock();

        // trilho be
        if (ID == 2 && x == 310 && y == 270) mutexbe.lock();
        if (ID == 5 && x == 485 && y == 270) mutexbe.lock();

        // trilho ce
        if (ID == 3 && x == 465 && y == 255) mutexce.lock();
        if (ID == 5 && x == 600 && y == 285) mutexce.lock();

        // trilho cf
        if (ID == 3 && x == 580 && y == 270) mutexcf.lock();
        if (ID == 6 && x == 755 && y == 270) mutexcf.lock();

        // trilho de
        if (ID == 4 && x == 310 && y == 390) mutexde.lock();
        if (ID == 5 && x == 350 && y == 270) mutexde.lock();

        // trilho ef
        if (ID == 5 && x == 580 && y == 390) mutexef.lock();
        if (ID == 6 && x == 620 && y == 270) mutexef.lock();

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
        if (ID == 1 && x == 485 && y == 150) mutexab.unlock();
        if (ID == 2 && x == 195 && y == 165) mutexab.unlock();

        // trilho ac
        if (ID == 1 && x == 735 && y == 135) mutexac.unlock();
        if (ID == 3 && x == 465 && y == 165) mutexac.unlock();

        // trilho bc
        if (ID == 2 && x == 445 && y == 150) mutexbc.unlock();
        if (ID == 3 && x == 485 && y == 270) mutexbc.unlock();

        // trilho bd
        if (ID == 2 && x == 350 && y == 270) mutexbd.unlock();
        if (ID == 4 && x == 175 && y == 270) mutexbd.unlock();

        // trilho be
        if (ID == 2 && x == 465 && y == 255) mutexbe.unlock();
        if (ID == 5 && x == 330 && y == 285) mutexbe.unlock();

        // trilho ce
        if (ID == 3 && x == 620 && y == 270) mutexce.unlock();
        if (ID == 5 && x == 445 && y == 270) mutexce.unlock();

        // trilho cf
        if (ID == 3 && x == 735 && y == 255) mutexcf.unlock();
        if (ID == 6 && x == 600 && y == 285) mutexcf.unlock();

        // trilho de
        if (ID == 4 && x == 310 && y == 270) mutexde.unlock();
        if (ID == 5 && x == 350 && y == 390) mutexde.unlock();

        // trilho ef
        if (ID == 5 && x == 580 && y == 270) mutexef.unlock();
        if (ID == 6 && x == 620 && y == 390) mutexef.unlock();

        msleep(201 - velocidade);
    }
}

void Trem::setVelocidade(int value)
{
    velocidade = value;
}