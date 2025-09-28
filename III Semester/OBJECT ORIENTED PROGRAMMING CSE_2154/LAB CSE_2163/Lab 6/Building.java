class Building{
    public int squareFootage;
    public int stories;
    public Building(int sF, int st){
        squareFootage = sF;
        stories = st;
    }
    public void display(){
        System.out.println("\nThe Square footage is: " + squareFootage + "\nThe number of stories is: " + stories);
    }
    public static void main(String[] args){
        Building b1 = new Building(7000, 12);
        House h1 = new House(4000, 5, 3, 3);
        School s1 = new School(12000, 8,  40, "Elementary");
        b1.display();
        h1.display();
        s1.display();
    }
}

class House extends Building{
    public int noOfBeds;
    public int noOfBathrooms;
    public House(int sF, int st, int noBe, int noBa){
        super(sF, st);
        noOfBeds = noBe;
        noOfBathrooms = noBa;
    }
    public void display(){
        super.display();
        System.out.println("The number of beds is: " + noOfBeds + "\nThe number of bathrooms is: " + noOfBathrooms);
    }
}

class School extends Building{
    public int noOfClassrooms;
    public String gradeLevel;
    public School(int sF, int st, int noC, String gL){
        super(sF,st);
        noOfClassrooms = noC;
        gradeLevel = gL;
    }
    public void display(){
        super.display();
        System.out.println("The number of classrooms is: " + noOfClassrooms + "\nThe grade level is: " + gradeLevel);
    }
}