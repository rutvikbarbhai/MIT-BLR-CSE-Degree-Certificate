import java.util.Scanner;
    class Students {
        Scanner sc=new Scanner(System.in);
        int regNum;
        String name;
        String DOJ;
        static int ctr=0;
        int year;
        Students(String s){
            name=s;
            System.out.println("Enter date, month and year: ");
            int date = sc.nextInt();
            int month = sc.nextInt();
            year = sc.nextInt();
            String s0 = Integer.toString(date);
            String s1 = Integer.toString(month);
            String s2 = Integer.toString(year);
            DOJ = (s0+"/"+s1+"/"+s2);
            try {
                regNum = get_reg();
            }
            catch(Exception c){
                System.out.println(c);
            }
        }
        int get_reg(){
            int reg = ((year%100)*100)+ctr;
            ctr++;
            if (reg%100 <1)
                return reg;
            else
                throw new ArithmeticException("Seats filled Exception");
        }
        void display(){
            System.out.println("The reg no is: " + regNum +"\nThe name is "+name+"\nThe date of joining is "+DOJ+"\t");
        }
        public static void main(String[] args){
            Students s1 = new Students("Names");
            Students s2 = new Students("Nane");
            s1.display();
            s2.display();
        }
    }
