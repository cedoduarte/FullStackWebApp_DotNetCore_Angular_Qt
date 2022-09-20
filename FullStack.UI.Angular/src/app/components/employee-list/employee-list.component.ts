import { Component, OnInit } from '@angular/core';
import { Employee } from 'src/app/models/employee.model'
import { EmployeesService } from 'src/app/services/employees.service';

@Component({
  selector: 'app-employee-list',
  templateUrl: './employee-list.component.html',
  styleUrls: ['./employee-list.component.css']
})
export class EmployeeListComponent implements OnInit {
  employees: Employee[] = [];
  
  /*
  employees: Employee[] = [
    {
      id: 1,
      name: "John Doe",
      email: "john.doe@email.com",
      phone: "998877665",
      salary: 60000,
      department: "Human Resources"
    },
    {
      id: 2,
      name: "Sammer Saini",
      email: "sameer.saini@email.com",
      phone: "78789789",
      salary: 70000,
      department: "Information Technology"
    },
    {
      id: 3,
      name: "Samantha James",
      email: "samantha.james@email.com",
      phone: "8787878787",
      salary: 80000,
      department: "Accounts"
    }
  ];
  */
  

  constructor(private employeeService: EmployeesService) { }

  ngOnInit(): void {
    this.employeeService.getAllEmployees().subscribe({
      next: employees => {
        this.employees = employees;
        //console.log(employees);
      },
      error: e => {
        console.log(e);
      }
    });
  }
}
