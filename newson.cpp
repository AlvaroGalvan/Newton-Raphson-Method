#include "newson.h"
#include "ui_newson.h"
#include <cmath> // Library for allow mathematical functions in the program.

Newson::Newson(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Newson)
{
    ui->setupUi(this);
    setWindowTitle("Método de Newton - Raphson"); // Print the method's name at window title.
    // Connections between button's signals and slots.
    connect(ui->inicio,SIGNAL(clicked()),this,SLOT(ejecutar()));
    connect(ui->limpio,SIGNAL(clicked()),this,SLOT(limpiar()));
    // Connections between spinboxes "value changed" signal and "activar" slot.
    connect(ui->initval,SIGNAL(valueChanged(double)),this,SLOT(activar()));
    connect(ui->errorac,SIGNAL(valueChanged(double)),this,SLOT(activar()));
    connect(ui->maxiter,SIGNAL(valueChanged(int)),this,SLOT(activar()));
    ui->inicio->setDisabled(true); //The start button is disabled before run the method.
    ui->limpio->setDisabled(true); //The clear button is disabled before run the method.
}
double Newson::f(double z){// Return the value of original function.
    return (sin(5*z));
}
double Newson::df(double w){// Return the value of derivative function.
    return (5*cos(5*w));
}
void Newson::activar(){ // This slot will enable the "clear" and "start" buttons.
    x=0, ea=0; xr=0; i=0; imax=0; // All variables starts from 0.
    ui->limpio->setDisabled(false); // If the value of a spinbox changes, the clear button activates.
    x=ui->initval->value(); // Collects the initial value provided by the user and saves it on "x".
    ea=ui->errorac->value(); // Collects the accepted error provided by the user and saves it on "ea".
    imax=ui->maxiter->value(); // Collects the iterations maximum provided by the user and saves it on "imax".
    if((x!=0)&&(ea!=0)&&(imax!=0)){ // If the three spinboxes are different of zero, the start button activates.
        ui->inicio->setDisabled(false); // The start button is enabled.
    }
    else { // If the condition doesn't comply, the start button doesn't activate.
        ui->inicio->setDisabled(true); //The start button is disabled.
    }
}
void Newson::ejecutar(){ //This slot will run the method when the start button been clicked.
    ei=100;//Initial error starts with 100 percent.
    //The mehtod starts.
    while ((ei>ea)&(imax>i)) {//The method will run until found the minimum error and use the iterations maximum.
        xr=(x)-(f(x)/df(x)); //Calculates the next point to evaluate (with the initial value, the original and derivative function), and saves it on "xr".
        ei=100*std::abs((xr-x)/xr); // Calculates the new error, and saves it on "ei".
        i++; //Sums one iteration to counter.
        x=xr; //Now "x" takes the value of the next point, saved before on "xr".
    } //The method finishes.
    ui->rootplay->display(x);//Shows the found root on main display.
    ui->errmin->display(ei);//Shows the minimum error found in display.
    ui->numiter->display(i);//Shows the total iterations used in display.
}
void Newson::limpiar(){//This slot will clear all the user interface fields when the clear button been clicked
    //All sinboxes goes to 0.
    ui->initval->setValue(0.0);
    ui->errorac->setValue(0.0);
    ui->maxiter->setValue(0);
    //All displays goes to 0.
    ui->rootplay->display(0.0);
    ui->errmin->display(0.0);
    ui->numiter->display(0);
    // The "start" and "clear" buttons are disabled, for start over the method.
    ui->inicio->setDisabled(true);
    ui->limpio->setDisabled(true);
}

Newson::~Newson()
{
    delete ui;
}
