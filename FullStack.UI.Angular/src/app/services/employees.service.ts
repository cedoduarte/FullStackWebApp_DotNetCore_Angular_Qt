import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { environment } from 'src/environments/environment';
import { EmployeeDTO } from '../models/employee.dto.model';
import { Employee } from '../models/employee.model';

@Injectable({
  providedIn: 'root'
})
export class EmployeesService {
  baseApiUrl: string = environment.baseApiUrl;

  constructor(private http: HttpClient) { }

  // aquí recibimos una lista de "Employee" que incluye valor de "Id"
  getAllEmployees(): Observable<Employee[]> {
    return this.http.get<Employee[]>(this.baseApiUrl + "/api/Employee");
  }

  // aquí recibimos un "Employee" que incluye valor de "Id"
  getEmployee(id: number): Observable<Employee> {
    return this.http.get<Employee>(this.baseApiUrl + "/api/Employee/" + id);
  }

  // aquí usamos "EmployeeDTO" porque no debemos tener "Id" asignado en el objeto de transferencia de datos
  // para agregar el "Employee" en el backend
  addEmployee(employeeDto: EmployeeDTO): Observable<EmployeeDTO> {
    return this.http.post<EmployeeDTO>(this.baseApiUrl + "/api/Employee", employeeDto);
  }

  // aquí usamos el "Id" y los nuevos valores del "Employee" para que sean actualizados en el backend
  updateEmployee(id: number, employee: Employee): Observable<Employee> {
    return this.http.put<Employee>(this.baseApiUrl + "/api/Employee/" + id, employee);
  }

  // aquí pasamos el "Id" para eliminar el "Employee" en el backend
  deleteEmployee(id: number): Observable<Employee> {
    return this.http.delete<Employee>(this.baseApiUrl + "/api/Employee/" + id);
  }
}
