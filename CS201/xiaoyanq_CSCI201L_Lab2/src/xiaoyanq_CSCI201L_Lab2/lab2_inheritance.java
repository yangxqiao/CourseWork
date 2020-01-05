package xiaoyanq_CSCI201L_Lab2;

class Person{
	private String firstname;
	private String lastname;
	private String birthdate;
	
	public Person(String fname, String lname, String bdate)
	{
		this.firstname = fname;
		this.lastname = lname;
		this.birthdate = bdate;
	}
	
	public String getFirstName() {
		return this.firstname;
	}
	
	public String getLastName() {
		return this.lastname;
	}
	
	public String getBirthdate() {
		return this.birthdate;
	}
}

abstract class Employee extends Person{
	private int employeeID;
	private String jobTitle;
	private String company;
	
	public Employee(String fname, String lname, String bdate, int ID, String jTitle, String comp)
	{
		super(fname, lname, bdate);
		this.employeeID = ID;
		this.jobTitle = jTitle;
		this.company = comp;
	}
	
	public String getJobTitle()
	{
		return this.jobTitle;
	}
	
	public String getCompany()
	{
		return this.company;
	}
	
	public int getEmployeeID() {
		return this.employeeID;
	}
	
	public abstract double getAnnualSalary();
	
}

class HourlyEmployee extends Employee{
	protected double hourlyRate;
	protected double numberHoursPerWeek;
	
	public HourlyEmployee(String fname, String lname, String bdate, int ID, String jTitle, String comp, double hourlyRate, double numberHoursPerWeek)
	{
		super(fname, lname, bdate, ID, jTitle, comp);
		this.hourlyRate = hourlyRate;
		this.numberHoursPerWeek = numberHoursPerWeek;
	}
	
	public double getAnnualSalary(){
		double annualSalary = this.hourlyRate * this.numberHoursPerWeek * 52;
		return annualSalary;
	}
}

class SalariedEmployee extends Employee{
	private double annualSalary;
	
	public SalariedEmployee(String fname, String lname, String bdate, int ID, String jTitle, String comp, double annualSalary)
	{
		super(fname, lname, bdate, ID, jTitle, comp);
		this.annualSalary = annualSalary;
	}
	
	public double getAnnualSalary(){
		return this.annualSalary;
	}
}

class CommissionEmployee extends HourlyEmployee{
	private double salesTotal;
	private double commissionPercentage;
	
	public CommissionEmployee(String fname, String lname, String bdate, int ID, String jTitle, String comp, double hourlyRate, double numberHoursPerWeek, double salesTotal, double commissionPercentage)
	{
		super(fname, lname, bdate, ID, jTitle, comp, hourlyRate, numberHoursPerWeek);
		this.salesTotal = salesTotal;
		this.commissionPercentage = commissionPercentage;
	}
	
	public double getAnnualSalary(){
		return this.salesTotal * this.commissionPercentage + hourlyRate * numberHoursPerWeek * 52;
	}
}
