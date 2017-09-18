//Newton-Raphson Method Program V 1.0.0 / Programa del metodo de Newton-Raphson V 1.0.0
#ifndef NEWSON_H
#define NEWSON_H

#include <QMainWindow>

namespace Ui {
class Newson;
}

class Newson : public QMainWindow
{
    Q_OBJECT

public:
    explicit Newson(QWidget *parent = 0);
    ~Newson();
    //Variables declaration.
    double x; // This variable wiil save the initial value provided by the user.
    double xr; // This varable will save the "x+1" point.
    double ea; // This variable will save the accepted error introduced by the user.
    double ei; // Variable for the initial error.
    int i; // Iterations counter.
    int imax; // This variable will save the maximum iterations selected by the user.
    double f(double z); // Original function.
    double df(double w); // Derivative of original function.

public slots:
    //Slots declaration.
    void ejecutar(); //Slot for controll the start button.
    void limpiar(); //Slot for controll the clear button.
    void activar(); //Slot for enable or disable the start and clear buttons.
private:
    Ui::Newson *ui;
};

#endif // NEWSON_H
