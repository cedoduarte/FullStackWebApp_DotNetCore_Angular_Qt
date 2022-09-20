import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { AddEmployeeComponent } from './components/add-employee/add-employee.component';
import { EditEmployeeComponent } from './components/edit-employee/edit-employee.component';
import { EmployeeListComponent } from './components/employee-list/employee-list.component'

const routes: Routes = [
  {
    path: '', // si no hay ruta, carga el componente de "Lista de Empleados"
    component: EmployeeListComponent
  },
  {
    path: 'employees', // carga el componente de "Lista de Empleados"
    component: EmployeeListComponent
  },
  {
    path: 'employees/add', // carga el componente de "Agregar Nuevo Empleado"
    component: AddEmployeeComponent
  },
  {
    path: 'employees/edit/:id',
    component: EditEmployeeComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
