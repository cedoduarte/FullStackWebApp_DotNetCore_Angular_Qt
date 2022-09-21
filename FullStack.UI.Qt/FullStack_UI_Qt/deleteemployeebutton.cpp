#include "deleteemployeebutton.h"

DeleteEmployeeButton::DeleteEmployeeButton(int row, QWidget *parent)
    : QPushButton(parent)
{
    setText("Delete");
    m_row = row;
    connect(this, &DeleteEmployeeButton::clicked, this, [&]()
    {
        emit deleteClicked(m_row);
    });
}

DeleteEmployeeButton::~DeleteEmployeeButton()
{
    // nothing to do here
}
