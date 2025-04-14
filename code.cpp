using System;
using System.Collections.Generic;

namespace AttendanceTracker
{
    class Employee
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public bool IsPresent { get; set; }

        public Employee(int id, string name)
        {
            Id = id;
            Name = name;
            IsPresent = false;
        }

        public void MarkAttendance()
        {
            IsPresent = true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Employee> employees = new List<Employee>()
            {
                new Employee(101, "Alice"),
                new Employee(102, "Bob"),
                new Employee(103, "Charlie"),
                new Employee(104, "Diana")
            };

            Console.WriteLine("=== Cognizant Attendance Tracker ===");
            Console.WriteLine("Mark attendance for employees:\n");

            foreach (var emp in employees)
            {
                Console.Write($"Is {emp.Name} present? (y/n): ");
                string input = Console.ReadLine();
                if (input.ToLower() == "y")
                {
                    emp.MarkAttendance();
                }
            }

            Console.WriteLine("\n--- Attendance Summary ---");
            foreach (var emp in employees)
            {
                Console.WriteLine($"{emp.Name} (ID: {emp.Id}) - {(emp.IsPresent ? "Present" : "Absent")}");
            }

            Console.WriteLine("\nPress any key to exit...");
            Console.ReadKey();
        }
    }
}
