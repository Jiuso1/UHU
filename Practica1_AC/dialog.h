#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QElapsedTimer>
#include <QLocale>

class QPushButton;
class QVBoxLayout;
class QLabel;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    void setPi(long double pi);
    long double getPi();
    ~Dialog();

private:
    QPushButton *boton;
    QVBoxLayout *layout;
    QLabel *titulo;
    long double pi;
    QLabel *tiempos;
    QElapsedTimer tiempo;
    float tiempoFinal;
    QLocale *transformador;
private slots:
    void leibnizPi();
};
#endif // DIALOG_H
