#include "zenwriter.h"
#include "ui_zenwriter.h"

ZenWriter::ZenWriter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ZenWriter)
{
    ui->setupUi(this);
    this->typewriter = Phonon::createPlayer(Phonon::MusicCategory,
                                            Phonon::MediaSource("sounds/typewriter.wav"));
}

ZenWriter::~ZenWriter()
{
    delete ui;
}

void ZenWriter::on_actionOpen_activated()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text (*.txt)"));
    if (!fileName.isEmpty()) {
        this->file.setFileName(fileName);
        if (!this->file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        ui->plainTextEdit->setPlainText(this->file.readAll());
        this->file.close();
    }
}

void ZenWriter::on_actionSave_activated()
{
    if (!this->file.fileName().isEmpty()) {
        if (!this->file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&this->file);
        out << ui->plainTextEdit->toPlainText();
        this->file.close();
    }
    else {
        on_actionSave_as_activated();
    }
}

void ZenWriter::on_actionSave_as_activated()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text (*.txt)"));
    this->file.setFileName(fileName);
    on_actionSave_activated();
}

void ZenWriter::on_plainTextEdit_cursorPositionChanged()
{
    this->typewriter->play();
}

void ZenWriter::on_actionQuit_activated()
{
    qApp->quit();
}
