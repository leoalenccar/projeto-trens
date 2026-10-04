#include "trem.h"
#include <QtCore>

// Construtor
Trem::Trem(int ID, int x, int y)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

// Função a ser executada após executar trem->START
void Trem::run()
{
    while (true)
    {
        switch (ID)
        {
        case 1: // Trem 1
            if (y < 150 && x == 60)
                y += 10;
            else if (x < 330 && y == 150)
                x += 10;
            else if (x == 330 && y > 30)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 2: // Trem 2
            if (y < 150 && x == 330)
                y += 10;
            else if (x < 600 && y == 150)
                x += 10;
            else if (x == 600 && y > 30)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        case 3:
            if (y < 270 && x == 60)
                y += 10;
            else if (x < 600 && y == 270)
                x += 10;
            else if (x == 600 && y > 150)
                y -= 10;
            else
                x -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;           
        default:
            break;
        }
        msleep(velocidade);
    }
}
