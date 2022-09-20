using FullStack.API.Data;
using Microsoft.AspNetCore.Mvc;
using FullStack.API.Models;
using Microsoft.EntityFrameworkCore;

namespace FullStack.API.Controllers
{
    [ApiController]
    [Route("api/Employee")]
    public class EmployeeController : ControllerBase
    {
        private readonly FullStackDbContext context;

        public EmployeeController(FullStackDbContext context)
        {
            this.context = context;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Employee>>> Get()
        {
            try
            {
                var employees = await this.context.Employees!.ToListAsync();
                if (employees is not null)
                {
                    return Ok(employees);
                }
                return NotFound();
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [HttpGet("{id:int}")]
        public async Task<ActionResult<Employee>> Get([FromRoute] int id)
        {
            try
            {
                var employee = await this.context.Employees!.FindAsync(id);
                if (employee is not null)
                {
                    return Ok(employee);
                }
                return NotFound();
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [HttpPost]
        public async Task<ActionResult<Employee>> Post([FromBody] Employee employee)
        {
            try
            {
                if (employee is null)
                {
                    return NotFound();
                }
                using var transaction = await this.context.Database.BeginTransactionAsync();
                await this.context.AddAsync(employee);
                await this.context.SaveChangesAsync();
                await transaction.CommitAsync();
                return Ok(employee);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [HttpPut("{id:int}")]
        public async Task<ActionResult<Employee>> Put([FromRoute] int id, [FromBody] Employee employee)
        {
            try
            {
                if (id != employee.Id)
                {
                    return NotFound();
                }
                using var transaction = await this.context.Database.BeginTransactionAsync();
                this.context.Entry(employee).State = EntityState.Modified;
                await this.context.SaveChangesAsync();
                await transaction.CommitAsync();
                return Ok(employee);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [HttpDelete("{id:int}")]
        public async Task<ActionResult<Employee>> Delete([FromRoute] int id)
        {
            try
            {
                using var transaction = await this.context.Database.BeginTransactionAsync();
                var employee = await this.context.Employees!.FindAsync(id);
                if (employee is not null)
                {
                    this.context.Remove(employee);
                    await this.context.SaveChangesAsync();
                    await transaction.CommitAsync();
                    return Ok(employee);
                }
                return NotFound();
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }
    }
}
