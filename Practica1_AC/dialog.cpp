#include "dialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QLocale>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    boton = new QPushButton;
    layout = new QVBoxLayout;
    titulo = new QLabel;
    tiempos = new QLabel;
    transformador = new QLocale;

    boton->setText("Calcular &Pi");
    titulo->setText("<h1><font color='orange' size=7 face='Lucida Console'>Pi</font><font color='red' size=7 face='Arial'>Benchmark</font></h1>");

    connect(boton,SIGNAL(clicked()),
                this,SLOT(leibnizPi()));

    layout->addWidget(titulo);
    layout->addWidget(tiempos);
    layout->addWidget(boton);

    setWindowTitle("Práctica 1 de AC");
    setLayout(layout);
}

void Dialog::setPi(long double pi){
    this->pi = pi;
}

long double Dialog::getPi(){
    return this->pi;
}

void Dialog::leibnizPi(){
    tiempo.start();
    long double pi = 1;
    unsigned long int denominador = 3;
    long double operando = 0;
    int signo = -1;
    for (int i = 0; i < 1E9; i++) {
        operando = static_cast<long double>(1) / denominador;
        pi = (pi + operando * signo);
        denominador += 2;
        signo *= -1;
    }
    pi = pi * 4;
    this->setPi(pi);
    tiempoFinal = tiempo.elapsed()/1000.0;
    tiempos->setText("<font color='dark blue' size=4>Tiempo de ejecución de "+transformador->toString(tiempoFinal)+" segundos.</font> <br>"
                     +"<font color='blue' size=4><b>MIPS</b> igual a "+transformador->toString(5E9/(tiempoFinal*1E6))+".</font> <br>"
                     +"<font color='orange' size=5 face='Lucida Console'><b>Pi</b></font> "+"<font size=4>"+transformador->toString(static_cast<float>(pi))+"</font>");
    //MIPS = Nº de instrucciones / (segundos * 10^6)
    //qDebug()<<"Se tardaron "<<tiempo.elapsed()/1000.0<<" segundos";
}

Dialog::~Dialog()
{
}

