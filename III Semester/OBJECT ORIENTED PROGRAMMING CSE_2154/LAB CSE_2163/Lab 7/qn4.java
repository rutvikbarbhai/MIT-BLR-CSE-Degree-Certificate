import java.util.Scanner;
class Student {
    int id;
    int[] marks;

    void getNumber() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter id: ");
        id = sc.nextInt();
    }

    int putNumber() {
        System.out.println("The id is: " + id);
        return id;
    }

    void setMarks() {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            marks[i] = sc.nextInt();
        }
    }

    int[] putMarks() {
        System.out.println("The marks are: ");
        for (int i = 0; i < 5; i++) {
            System.out.print("\t" + marks[i]);
        }
        return marks;
    }
}
interface Sports {
    void Grade();
    int getMark();
}
class Result implements Sports {
    int smark;

    public void Grade() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the sports mark: ");
        smark = sc.nextInt();
    }
    public int getMark(){
        return smark;
    }
}
class qn4{
    public static void main(String[] args){
        Student s1 = new Student();
        s1.getNumber();
        s1.putNumber();
        s1.setMarks();
        s1.putMarks();
        Sports s2 = new Result();
        s2.Grade();
        int SubTotal = 0, i;
        for (i = 0; i < 5; i++){
            SubTotal = SubTotal + s1.marks[i];
        }
        int result = SubTotal + s2.getMark();
        System.out.println("The result is: " + result);
    }
}