#ifndef AGREGARTAREAS_H
#define AGREGARTAREAS_H

#include <QDialog>

namespace Ui {
class agregartareas;
}

class agregartareas : public QDialog
{
    Q_OBJECT

public:
    explicit agregartareas(QWidget *parent = nullptr);
    ~agregartareas();

    QString nombre() const;
    QString tipo();
    int prioridad();
    QDate fecha();

private slots:
    void on_cmdBoton_accepted();

    void on_cmdBoton_rejected();

private:
    Ui::agregartareas *ui;
};

#endif // AGREGARTAREAS_H
