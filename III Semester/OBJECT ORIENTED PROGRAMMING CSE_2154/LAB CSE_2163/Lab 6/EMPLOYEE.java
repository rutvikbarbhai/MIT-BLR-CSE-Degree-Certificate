import java.util.Scanner;
public class EMPLOYEE {
    float Net_Sal;

    public static void main(String[] args){
        int control;
        Scanner obj = new Scanner(System.in);

        System.out.println("Enter 1 for Part time Employee, Enter 2 for Full time Employee");
        control = obj.nextInt();
        if (control == 1){
            int basic;
            System.out.println("Enter the hours worked: ");
            basic = obj.nextInt();
            PartTimeEmp pEmp = new PartTimeEmp(basic);
            pEmp.calculateSalary();
            pEmp.display();
        }
        else if(control == 2){
            int sal;
            System.out.println("Enter the Salary: ");
            sal = obj.nextInt();
            FullTimeEmp FTE = new FullTimeEmp(sal);
            FTE.bonus = 3445;
            FTE.deductions = 432;
            FTE.calculateSalary();
            FTE.display();
        }
        else
            System.out.println("Invalid output, rerun the program");
    }
}
class FullTimeEmp extends EMPLOYEE{
    int Basic;
    double bonus = 0;
    double deductions = 0;
    FullTimeEmp(int basic){
        this.Basic = basic;
    }

    void calculateSalary(){
        Net_Sal = (float) (Basic + bonus - deductions);
    }
    void display(){
        System.out.println("The net Salary is " + Net_Sal);
    }
}
class PartTimeEmp extends EMPLOYEE{
    int hoursWorked;
    static final double hourlyRate = 850.5;
    PartTimeEmp(int hw){

        hoursWorked = hw;
    }
    void calculateSalary(){
        this.Net_Sal = (float)(hoursWorked * hourlyRate);
    }
    void display(){
        System.out.println("The hourly rate is " + hourlyRate);
        System.out.println("The hours worked is " + hoursWorked);
        System.out.println("The net Salary is " + Net_Sal);
    }
}