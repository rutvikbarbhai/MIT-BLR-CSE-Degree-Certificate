import java.util.Scanner;

class STUDENT{
    String sname;
    int[] marks_array = new int[5];
    int total;
    float avg;
    STUDENT(String name, int[] a){
        int i;
        this.sname = name;
        for (i = 0;  i<5; i++){
            this.marks_array[i] = a[i];
        }
    }
    STUDENT(String name) {
        this.sname = name;
    }
    void compute(){
        int i, sum =0;
        float avg;
        for (i = 0;  i<5; i++){
            sum = marks_array[i]+ sum;
        }
        this.total= sum;
        avg = (float)sum/5;
        this.avg = avg;
    }

    void display(){
        int i;
        System.out.println("The name is : " + sname);
        System.out.println("The subject marks are: ");
        for(i = 0; i < 5; i++)
            System.out.print("\t" + marks_array[i]);
        System.out.println("\nThe Total is: " + total);
        System.out.println("The average is: " + avg);
    }

    public static void main(String[] args){
        java.util.Scanner obj = new java.util.Scanner(System.in);
        int[] a = new int[5];
        String name;
        int i, control;
        System.out.println("Enter the name: ");
        name = obj.nextLine();
        System.out.println("Enter the marks: ");
        for(i = 0; i< 5; i++)
            a[i] = obj.nextInt();
        STUDENT Complex = new STUDENT(name, a);
        System.out.println("Enter 1 for Science Student, Enter 2 for Arts Student");
        control = obj.nextInt();
        if (control == 1){
            int pMarks;
            System.out.println("Enter the practical marks: ");
            pMarks = obj.nextInt();
            ScienceStudent SStud = new ScienceStudent(name, pMarks);
            SStud.compute();
            SStud.display();
            SStud.displayPracticalMarks();
        }
        else if(control == 2){
            String subj;
            System.out.println("Enter the name of the elective subject: ");
            Scanner sc = new Scanner(System.in);
            subj = sc.nextLine();
            ArtsStudent AStud = new ArtsStudent(name, a, subj);
            AStud.compute();
            AStud.display();
        }
        else
            System.out.println("Invalid output, rerun the program");
    }
}

class ScienceStudent extends STUDENT{
    private final int practicalMarks;
    ScienceStudent(String name, int pMarks){
        super(name);
        practicalMarks = pMarks;
    }
    void displayPracticalMarks(){
        System.out.println("The practical mark of the student in a different method is" + practicalMarks);
    }
    void compute(){
        super.compute();
        total = total + practicalMarks;
        avg = (float) total /6;
    }
    void display(){
        super.display();
        System.out.println("The practical mark is " + practicalMarks);
    }
}
class ArtsStudent extends STUDENT{
    String electiveSubject;
    ArtsStudent(String name, int [] a, String sub){
        super(name, a);
        electiveSubject = sub;
    }
    void compute(){
        super.compute();
    }
    void display(){
        super.display();
        System.out.println("The elective subject is " + electiveSubject);
    }
}