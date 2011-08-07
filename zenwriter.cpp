#include "zenwriter.h"
#include "ui_zenwriter.h"

ZenWriter::ZenWriter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZenWriter)
{
    ui->setupUi(this);
    this->isModified = false;
    this->isWriteMode = false;
    this->isFullScreen = false;
}

ZenWriter::~ZenWriter()
{
    delete ui;
}

void ZenWriter::on_switchFullScreenButton_clicked()
{
    if (this->isFullScreen) {
        ZenWriter::showNormal();
        this->isFullScreen = false;
        //this->ui->switchFullScreenButton->setIcon(QIcon("icons/fullscreen.svg"));
    }
    else {
        ZenWriter::showFullScreen();
        this->isFullScreen = true;
        //this->ui->switchFullScreenButton->setIcon(QIcon("icons/unfullscreen.svg"));
    }
}

void ZenWriter::on_newButton_clicked()
{
    this->file.setFileName(NULL);
    this->ui->plainTextEdit->setPlainText(NULL);
    this->isModified = false;
}

void ZenWriter::on_saveButton_clicked()
{
    if (this->file.fileName().isEmpty()) {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text (*.txt)"));
        this->file.setFileName(fileName);
    }
    else {
        if (!this->file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        else {
            QTextStream out(&this->file);
            out << ui->plainTextEdit->toPlainText();
            this->file.close();
            this->isModified = false;
        }
    }
}

void ZenWriter::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text (*.txt)"));
    if (!fileName.isEmpty()) {
        this->file.setFileName(fileName);
        if (!this->file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        ui->plainTextEdit->setPlainText(this->file.readAll());
        this->file.close();
        this->isModified = false;
    }
}

void ZenWriter::on_fontSizeLessButton_clicked()
{
    QFont font = ui->plainTextEdit->font();
    if (font.pointSize() > 8) {
        font.setPointSize(font.pointSize() - 2);
        ui->plainTextEdit->setFont(font);
    }
}

void ZenWriter::on_fontSizeMoreButton_clicked()
{
    QFont font = ui->plainTextEdit->font();
    if (font.pointSize() < 72) {
        font.setPointSize(font.pointSize() + 2);
        ui->plainTextEdit->setFont(font);
    }
}

void ZenWriter::on_plainTextEdit_textChanged()
{
    if (!this->isWriteMode) {
        ui->frame->setVisible(false);
        this->isWriteMode = true;
    }
    this->isModified = true;
}

void ZenWriter::mouseMoveEvent(QMouseEvent *event)
{
    if (this->isWriteMode) {
        ui->frame->setVisible(true);
        this->isWriteMode = false;
    }
}

void ZenWriter::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape && this->isModified) {
        QMessageBox messageBox;
        messageBox.setText(tr("The ZenWriter contains unsaved changes."));
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setInformativeText(tr("Do you want to save them before exiting?"));
        messageBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Save);
        int ret = messageBox.exec();

        switch (ret) {
            case QMessageBox::Save:
                on_saveButton_clicked();
                qApp->quit();
            break;
            case QMessageBox::Cancel:
                qApp->quit();
            break;
            default: break;
        }
    }
}
