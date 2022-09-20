import { EmployeeDTO } from './employee.dto.model';

export class Employee {
    id!: number;
    name!: string;
    email!: string;
    phone!: string;
    salary!: number;
    department?: string;

    constructor() {
        this.id = -1;
        this.name = "";
        this.email = "";
        this.phone = "";
        this.salary = 0.0;
        this.department = "";
    }

    convertToDTO(): EmployeeDTO {
        const employeeDto: EmployeeDTO = {
            name: this.name,
            email: this.email,
            phone: this.phone,
            salary: this.salary,
            department: this.department
        };
        return employeeDto;
    }
}