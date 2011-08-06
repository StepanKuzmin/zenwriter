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

    void on_fontSizeLess_clicked();

    void on_fontSizeMore_clicked();

private:
    QFile file;
    bool isFullScreen;
    Ui::ZenWriter *ui;
};

#endif // ZENWRITER_H
