class Students {
    String name;
    int id;
    Students(String name, int id){
        this.name = name;
        this.id = id;
    }
    public static void main(String[] args){
        result r1 = new result("Jeevan", 2022, 9, 6);
        r1.display();
    }
}
class Exam extends Students{
    int e_grade;
    Exam(String name, int id, int grade) {
        super(name,id);
        e_grade = grade;
    }
}
class Sports extends Exam{
    int s_grade;
    Sports(String name, int id, int grade, int e_grade) {
        super(name,id,e_grade);
        s_grade = grade;
    }

}
class result extends Sports {
    int results;

    result(String name, int id, int grade, int e_grade) {
        super(name,id,grade,e_grade);
        this.results = grade +e_grade;
    }
    void display(){
        System.out.println("The total is " + results);
    };
}