import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { Employee } from 'src/app/models/employee.model';
import { EmployeesService } from 'src/app/services/employees.service';

@Component({
  selector: 'app-edit-employee',
  templateUrl: './edit-employee.component.html',
  styleUrls: ['./edit-employee.component.css']
})
export class EditEmployeeComponent implements OnInit {

  employeeDetails: Employee = new Employee();

  constructor(private route: ActivatedRoute,
              private employeeService: EmployeesService,
              private router: Router)
  {
    
  }

  ngOnInit(): void {
    this.route.paramMap.subscribe({
      next: params => {
        const id = Number(params.get("id"));
        if (id) {
          // call api
          this.employeeService.getEmployee(id).subscribe({
            next: responseEmployee => {
              this.employeeDetails = responseEmployee;
            },
            error: e => {
              console.log(e.message);
            }
          });
        }
      }
    });
  }

  updateEmployee() {
    this.employeeService.updateEmployee(this.employeeDetails.id, this.employeeDetails).subscribe({
      next: responseEmployee => {
        this.router.navigate(["employees"]);
      },
      error: e => {
        console.log(e.message);
      }
    });
  }

  deleteEmployee(id: number) {
    this.employeeService.deleteEmployee(id).subscribe({
      next: responseEmployee => {
        console.log(responseEmployee);
        this.router.navigate(["employees"]);
      },
      error: e => {
        console.log(e.message);
      }
    });
  }
}
