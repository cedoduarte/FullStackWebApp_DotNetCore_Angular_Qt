#ifndef DELETEEMPLOYEEBUTTON_H
#define DELETEEMPLOYEEBUTTON_H

#include <QPushButton>

class DeleteEmployeeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit DeleteEmployeeButton(int row, QWidget *parent = nullptr);
    virtual ~DeleteEmployeeButton();
signals:
    void deleteClicked(int row);
private:
    int m_row;
};

#endif // DELETEEMPLOYEEBUTTON_H
