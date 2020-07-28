#include "agregartareas.h"
#include "ui_agregartareas.h"
#include <QDate>

agregartareas::agregartareas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregartareas)
{
    ui->setupUi(this);
}

agregartareas::~agregartareas()
{
    delete ui;
}
//Cierra el dialogo de agregar tareas
void agregartareas::on_cmdBoton_accepted()
{
    accept();
}
//Almancena los datos ingresados en agregar tarea
void agregartareas::on_cmdBoton_rejected()
{
    reject();
}

QString agregartareas::nombre() const
{
    return ui->inNombre->text();
}

QString agregartareas::tipo()
{
    return ui->inTipo->text();
}

int agregartareas::prioridad()
{
    return ui->inPrioridad->currentIndex();
}

QDate agregartareas::fecha()
{
    return ui->inFecha->date();
}

