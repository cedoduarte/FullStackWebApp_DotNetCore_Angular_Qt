#include "employeeservice.h"
#include "QNetLib/qnetrequest.h"

#include <QNetworkReply>

EmployeeService::EmployeeService(QObject *parent)
    : QNetworkAccessManager(parent)
{
    connect(this, &EmployeeService::finished, this, &EmployeeService::onFinished);
}

EmployeeService::~EmployeeService()
{
    // nothing to do here
}

void EmployeeService::getEmployees()
{
    m_replyAction = Get;
    get(QNetRequest(QUrl("https://localhost:7028/api/Employee")));
}

void EmployeeService::getEmployee(int id)
{
    m_replyAction = GetId;
    get(QNetRequest(QUrl(QString("https://localhost:7028/api/Employee/%1").arg(id))));
}

void EmployeeService::postEmployee(const Employee &employee)
{
    m_replyAction = Post;
    post(QNetRequest(QUrl("https://localhost:7028/api/Employee")), employee.toJson());
}

void EmployeeService::postEmployee(const EmployeeDTO &employee)
{
    m_replyAction = Post;
    post(QNetRequest(QUrl("https://localhost:7028/api/Employee")), employee.toJson());
}

void EmployeeService::putEmployee(int id, const Employee &employee)
{
    m_replyAction = Put;
    post(QNetRequest(QUrl(QString("https://localhost:7028/api/Employee/%1").arg(id))), employee.toJson());
}

void EmployeeService::deleteEmployee(int id)
{
    m_replyAction = Delete;
    deleteResource(QNetRequest(QUrl(QString("https://localhost:7028/api/Employee/%1").arg(id))));
}

void EmployeeService::onFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        emit requestError(reply->errorString());
        return;
    }
    switch (m_replyAction)
    {
        case Get:
        {
            emit getEmployeesFinished(reply->readAll());
            break;
        }
        case GetId:
        {
            emit getEmployeeFinished(reply->readAll());
            break;
        }
        case Post:
        {
            emit postEmployeeFinished(reply->readAll());
            break;
        }
        case Put:
        {
            emit putEmployeeFinished(reply->readAll());
            break;
        }
        case Delete:
        {
            emit deleteEmployeeFinished(reply->readAll());
            break;
        }
    }
}
