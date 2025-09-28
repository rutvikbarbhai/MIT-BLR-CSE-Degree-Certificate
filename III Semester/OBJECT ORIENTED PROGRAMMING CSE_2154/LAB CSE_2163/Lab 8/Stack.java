import java.util.Scanner;
public class Stack {
    int[] arr = new int[3];
    int top;
    static int maxsize = 3;
    void push(){
        if (top == maxsize)
            throw new ArithmeticException("Stack Overflow!");
        else{
            System.out.println("Enter the number to insert: ");
            Scanner ob = new Scanner(System.in);
            arr[top]= ob.nextInt();
            top++;
        }
    }
    int pop(){
        int a = 0;
        if (top == 0)
            throw new ArithmeticException("Stack Underflow!");
        else{
            a = arr[top -1];
            arr[top-1] = 0;
            top--;
        }
        return a;
    }
    void display(){
        int i;
        if (top == 0)
            throw new ArithmeticException("Empty Stack!");
        else{
            System.out.println("The elements are: ");
            for(i = 0; i < top; i++) {
                System.out.print("\t" + arr[i]);
            }
        }
    }
    public static void main(String[] args){
        int n = 1, control;
        Scanner obj = new Scanner(System.in);
        Stack stk = new Stack();
        stk.top = 0;
        System.out.println("1 for Push, 2 for pop, 3 for display, 4 to exit");
        while(n != 0){
            System.out.println("Enter the wanted menu option: ");
            control = obj.nextInt();
            switch(control){
                case 1:
                    try {
                        stk.push();
                    }
                    catch (Exception e){
                        System.out.println(e);
                    }
                    break;

                case 2:
                    try {
                        stk.pop();
                    }
                    catch (Exception e){
                        System.out.println(e);
                    };
                    break;

                case 3:
                    try {
                        stk.display();
                    }
                    catch (Exception e){
                        System.out.println(e);
                    }
                    break;

                case 4:
                    n = 0;
                    break;

                default:
                    System.out.println("Enter a valid input");
            }
        }
    }
}
