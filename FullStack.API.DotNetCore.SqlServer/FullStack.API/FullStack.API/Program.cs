using Microsoft.EntityFrameworkCore;
using System.Text.Json.Serialization;
using FullStack.API.Data;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllers().AddJsonOptions(opt =>
{
    opt.JsonSerializerOptions.ReferenceHandler = ReferenceHandler.IgnoreCycles;
});

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

// enables Cross-Origin Requests (CORS) in ASP.NET Core
builder.Services.AddCors(options => options.AddPolicy("AllowWebApp", builder => builder.AllowAnyOrigin().AllowAnyHeader().AllowAnyMethod()));

// configures the FullStackDbContext as a service
var fullStackConnectionString = builder.Configuration.GetConnectionString("FullStackConnectionString");
builder.Services.AddDbContextFactory<FullStackDbContext>(options =>
{
    // specifies the usage of Microsoft SQL Server
    options.UseSqlServer(fullStackConnectionString);

    // disables the tracking for improving the performance
    options.UseQueryTrackingBehavior(QueryTrackingBehavior.NoTracking);
});

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

// uses Cross-Origin Requests (CORS) in ASP.NET Core
app.UseCors("AllowWebApp");
// the backend is ready to communicate with the frontend (for example Angular)

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
