#ifndef EMPLOYEESERVICE_H
#define EMPLOYEESERVICE_H

#include "employee.h"

#include <QNetworkAccessManager>

class EmployeeService : public QNetworkAccessManager
{
    Q_OBJECT
public:
    enum ReplyActionEnum
    {
        Get,
        GetId,
        Post,
        Put,
        Delete
    };

    explicit EmployeeService(QObject *parent = nullptr);
    virtual ~EmployeeService();

    void getEmployees();
    void getEmployee(int id);
    void postEmployee(const Employee &employee);
    void postEmployee(const EmployeeDTO &employee);
    void putEmployee(int id, const Employee &employee);
    void deleteEmployee(int id);
signals:
    void requestError(const QString &errorMessage);

    void getEmployeesFinished(const QByteArray &data);
    void getEmployeeFinished(const QByteArray &data);
    void postEmployeeFinished(const QByteArray &data);
    void putEmployeeFinished(const QByteArray &data);
    void deleteEmployeeFinished(const QByteArray &data);
private slots:
    void onFinished(QNetworkReply *reply);
private:
    int m_replyAction;
};

#endif // EMPLOYEESERVICE_H
