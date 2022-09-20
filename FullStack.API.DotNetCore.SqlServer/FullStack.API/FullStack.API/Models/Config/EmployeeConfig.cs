
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Builders;

namespace FullStack.API.Models.Config
{
    public class EmployeeConfig : IEntityTypeConfiguration<Employee>
    {
        public void Configure(EntityTypeBuilder<Employee> builder)
        {
            builder.HasKey(x => x.Id);
            builder.Property(x => x.Name).IsRequired(true).HasMaxLength(128);
            builder.Property(x => x.Email).IsRequired(true).HasMaxLength(128);
            builder.Property(x => x.Phone).IsRequired(true).HasMaxLength(64);
            builder.Property(x => x.Department).IsRequired(true).HasMaxLength(128);
        }
    }
}
