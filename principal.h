#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <ayuda.h>

QT_BEGIN_NAMESPACE
namespace Ui { class principal; }
QT_END_NAMESPACE

class principal : public QMainWindow
{
    Q_OBJECT

public:
    principal(QWidget *parent = nullptr);
    ~principal();

private slots:
    void on_inAgregar_clicked();

    void on_actionAcerca_de_Qt_triggered();

    void on_actionAcerca_de_triggered();

private:
    Ui::principal *ui;

    enum Columna
    {
        NOMBREDELATAREA, TIPO, FECHADEENTREGA
    };

};
#endif // PRINCIPAL_H
