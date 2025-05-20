//
// Created by David Berbecar on 20.05.2025.
//

#ifndef GUI_H
#define GUI_H

#include <QWidget>

#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
Q_OBJECT

private:
    Service& service;

public:
    explicit gui(QWidget *parent,Service& service);
    ~gui() override;

private:
    Ui::gui *ui;

private slots:
    void populateList();
    void searchChanged();
    void bestMatchClicked();
};


#endif //GUI_H
