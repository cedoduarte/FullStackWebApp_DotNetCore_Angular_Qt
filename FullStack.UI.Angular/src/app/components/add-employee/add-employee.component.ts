import { Component, OnInit } from '@angular/core';
import { Employee } from 'src/app/models/employee.model';
import { EmployeeDTO } from 'src/app/models/employee.dto.model';
import { EmployeesService } from 'src/app/services/employees.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-add-employee',
  templateUrl: './add-employee.component.html',
  styleUrls: ['./add-employee.component.css']
})
export class AddEmployeeComponent implements OnInit {
  addEmployeeRequest!: Employee;

  constructor(private employeeService: EmployeesService,
              private router: Router)
  {
    this.addEmployeeRequest = new Employee();
  }

  ngOnInit(): void {
  }

  addEmployee() {
    this.employeeService.addEmployee(this.addEmployeeRequest.convertToDTO()).subscribe({
      next: responseEmployee => {
        this.router.navigate(["employees"]);
        console.log(responseEmployee);
      },
      error: e => {
        console.log("hay error: " + e.message);
      }
    });
  }
}
