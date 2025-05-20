//
// Created by David Berbecar on 20.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"


gui::gui(QWidget *parent,Service& service) : service(service),
    QWidget(parent), ui(new Ui::gui) {
    ui->setupUi(this);
    populateList();
    connect(ui->searchLE,&QLineEdit::textChanged,this,&gui::searchChanged);
    connect(ui->bestMatchButton,&QPushButton::clicked,this,&gui::bestMatchClicked);
}

void gui::populateList() {
    ui->listWidget->clear();
    std::vector<Document> documents = service.getDocuments();
    for (auto document : documents) {
        ui->listWidget->addItem(document.toString().c_str());
    }
}

void gui::searchChanged() {
    ui->listWidget->clear();
    std::string search=ui->searchLE->text().toStdString();
    std::vector<Document> documents = service.getDocuments();
    for (auto document : documents) {
        if (document.getName().find(search)!=std::string::npos || document.getKeywords().find(search)!=std::string::npos) {
            ui->listWidget->addItem(document.toString().c_str());
        }
    }
}

void gui::bestMatchClicked() {
    ui->bestMatchLE->clear();
    std::string search=ui->searchLE->text().toStdString();
    std::string bestMatch=service.bestMatch(search);
    ui->bestMatchLE->setText(bestMatch.c_str());
}

gui::~gui() {
    delete ui;
}
