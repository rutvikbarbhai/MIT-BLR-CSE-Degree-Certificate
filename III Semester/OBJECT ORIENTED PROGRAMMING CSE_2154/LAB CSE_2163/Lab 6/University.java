class Person{
    private String name;
    private long birthDate;
    Person(String name, long birthdate){
        this.name = name;
        this.birthDate = birthdate;
    }
    void display(){
        System.out.println("The name is " + name + " and the birthday is " + birthDate);
    }
}
class collegeGraduate extends Person{
    private double GPA;
    private int year;
    collegeGraduate(String name, int birthdate, double gpa, int year){
        super(name,birthdate);
        this.GPA = gpa;
        this.year = year;
    }
    void display(){
        super.display();
        System.out.println("The GPA is " + GPA + " and the year of graduating is " +  year);
    }
}
class University{
    public static void main(String[] args){
        Person p1 = new Person("Jeevan", 3122004);
        collegeGraduate c1 = new collegeGraduate("Shaju", 4041991, 6.9, 1993);
        p1.display();
        c1.display();
    }
}