#include "principal.h"
#include "ui_principal.h"
//Se agrega la ventana.
#include "agregartareas.h"
#include <QDate>
#include <QMessageBox>

principal::principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principal)
{
    ui->setupUi(this);
    QStringList titulos;
    //Poner titulo a la ventana principal.
    setWindowTitle("Gestionador de Tareas");
    //Agregar las columnas
    ui->tableWidget->setColumnCount(4);
    //Agregar respectivo nombre a cada titulo
    titulos << "Números" << "Nombre de la Tarea" << "Tipo" << "Fecha de entrega";
    //Agregar titulo a las columnas
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
}

principal::~principal()
{
    delete ui;
}


void principal::on_inAgregar_clicked()
{
    int res, fila;
    QString nombre;
    QString tipo;
    QDate fecha;

    //Para que se abra otra ventana para agregar tareas.
    agregartareas pd;
    //Poner titulo a la ventana de agregar tareas.
    pd.setWindowTitle("Agregar las Tareas");
    //Para validad cualquier dialogo rellenado.
    res = pd.exec();
    if (res == QDialog::Rejected)
        return;
    //Pedir los datos
    nombre = pd.nombre();
    tipo = pd.tipo();
    fecha = pd.fecha();
    pd.prioridad();


    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    fila = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(fila, NOMBREDELATAREA,new QTableWidgetItem(nombre));
    ui->tableWidget->setItem(fila, TIPO,new QTableWidgetItem(tipo));
    ui->tableWidget->setItem(fila, FECHADEENTREGA,new QTableWidgetItem((fecha.toString())));

}

void principal::on_actionAcerca_de_Qt_triggered()
{
    QMessageBox::aboutQt(this, "Qt");
}

void principal::on_actionAcerca_de_triggered()
{
    Ayuda *acerca_de = new Ayuda(this);
    acerca_de->setModal(true);
    acerca_de->show();
}
