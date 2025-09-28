abstract class Figure {
    abstract void area(int length1, int length2);
    public static void main(String[] args){
        Rectangle R = new Rectangle();
        Square S = new Square();
        Triangle T = new Triangle();
        Figure A;
        A = R;
        //Entering length and breadth
        A.area(4,5);
        A = S;
        //Entering side and waste value after
        A.area(6,0);
        A = T;
        //Entering height and length
        A.area(7,8);

    }
}
class Rectangle extends Figure{
    void area(int length, int breadth){
        int area = length*breadth;
        System.out.println("The area of rectangle is " + area);
    }
}
class Square extends Figure{
    void area(int side, int x){
        int area = side*side;
        System.out.println("The area of square is " + area);
    }
}
class Triangle extends Figure{
    void area(int height, int length){
        int area = (length * height)/2;
        System.out.println("The area of triangle is " + area);
    }
}
