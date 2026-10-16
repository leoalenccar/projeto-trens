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
        if (ID == 3 && x == 735 && y == 170) mutexac.lock();

        switch (ID)
        {
        case 1: // Trem 1
            if (y < 150 && x == 195)
                y += 10;
            else if (x < 735 && y == 150)
                x += 10;
            else if (x == 735 && y > 30)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 2: // Trem 2
            if (y < 270 && x == 195)
                y += 10;
            else if (x < 465 && y == 270)
                x += 10;
            else if (x == 465 && y > 150)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 3:
            if (y < 270 && x == 465)
                y += 10;
            else if (x < 735 && y == 270)
                x += 10;
            else if (x == 735 && y > 150)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 4:
            if (y < 390 && x == 60)
                y += 10;
            else if (x < 330 && y == 390)
                x += 10;
            else if (x == 330 && y > 270)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 5:
            if (y < 390 && x == 330)
                y += 10;
            else if (x < 600 && y == 390)
                x += 10;
            else if (x == 600 && y > 270)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 6:
            if (y < 390 && x == 600)
                y += 10;
            else if (x < 870 && y == 390)
                x += 10;
            else if (x == 870 && y > 270)
                y -= 10;
            else
                x -= 10;
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

        msleep(201 - velocidade);
    }
}

void Trem::setVelocidade(int value)
{
    velocidade = value;
}