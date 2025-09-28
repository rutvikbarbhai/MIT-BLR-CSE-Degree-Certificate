import java.util.Random;
interface Series{
    int getNext();
    void reset();
    void setStart(int a);
}

class byTwos implements Series{

    static int size = 20;
    static int[] arr = new int[size];
    static void generateSeries(){
        Random rNum = new Random();
        int i;
        int num = rNum.nextInt(100);
        for( i = 0; i < size; i++){
            arr[i] = (i*2) + num;
        }
    }

    public int getNext() {
        return arr[size-1] +2;
    }

    public void reset() {
        System.out.println("A new series is being generated");
        generateSeries();
    }

    public void setStart(int a) {
        int i;
        for( i = 0; i < size; i++){
            arr[i] = (i*2) + a;
        }
    }

    static void display(){
        int i;
        System.out.println("The series of numbers is ");
        for( i = 0; i < size; i++){
            System.out.print(arr[i]+ "    ");
        }
        System.out.println();
    }
}
public class qn3 {
    public static void main(String[] args) {
        byTwos sr1 = new byTwos();
        byTwos.generateSeries();
        byTwos.display();
        System.out.println("The next number in the series is " + sr1.getNext());
        sr1.reset();
        byTwos.display();
        sr1.setStart(6);
        byTwos.display();
    }
}