#ifndef FATXFILEDIALOG_H
#define FATXFILEDIALOG_H

//qt
#include <QDialog>
#include <QDateTime>

#include "Fatx/FatxConstants.h"
#include "IO/FatxIO.h"
#include "FATX/FatxDrive.h"
#include "Stfs/StfsDefinitions.h"

namespace Ui {
class FatxFileDialog;
}

class FatxFileDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FatxFileDialog(FatxDrive *drive, FatxFileEntry *entry, DWORD clusterSize, QString type, QWidget *parent);
    ~FatxFileDialog();
    
private slots:
    void on_btnOK_clicked();
    void on_txtName_textChanged(const QString &arg1);
    void onStateChanged();

private:
    Ui::FatxFileDialog *ui;
    FatxFileEntry *entry;
    QString type;
    FatxDrive *drive;

    QString msTimeToString(DWORD time);
    QString getFileType(QString fileName);
    void writeEntryBack();
};

#endif // FATXFILEDIALOG_H
