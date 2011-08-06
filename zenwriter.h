#ifndef ZENWRITER_H
#define ZENWRITER_H

#include <QFile>
#include <QWidget>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
    class ZenWriter;
}

class ZenWriter : public QWidget
{
    Q_OBJECT

public:
    explicit ZenWriter(QWidget *parent = 0);
    ~ZenWriter();

private slots:

    void on_newButton_clicked();

    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_switchFullScreenButton_clicked();

    void on_plainTextEdit_textChanged();

    void on_fontSizeLessButton_clicked();

    void on_fontSizeMoreButton_clicked();

    void mouseMoveEvent(QMouseEvent *event);

private:
    QFile file;
    bool isWriteMode;
    bool isFullScreen;
    Ui::ZenWriter *ui;
};

#endif // ZENWRITER_H
