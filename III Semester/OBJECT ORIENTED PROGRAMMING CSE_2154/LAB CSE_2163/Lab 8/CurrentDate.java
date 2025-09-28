import java.util.Scanner;
class CurrentDate {
    static void createDate(){
        try{
            System.out.println("Enter the date in DDMMYYYY format: ");
            Scanner sc = new Scanner(System.in);
            int fullDate = sc.nextInt();
            boolean correctDate;
            int month = (fullDate/10000)%100;
            int date = fullDate/1000000;
            if(month<=12){
                if((month == 1||
                        month == 3||
                        month == 5||
                        month == 7||
                        month == 8||
                        month == 10||
                        month == 12)
                        &&(date <=31)
                        &&(date >0)
                )
                    correctDate = true;
                else if((month == 4||
                        month == 6||
                        month == 9||
                        month == 11)
                        &&(date <=30)
                        &&(date >0)
                    )
                    correctDate = true;
                else if((month == 2)
                        &&(date <=28)
                        &&(date >0)){
                    correctDate = true;
                }
                else {
                    throw new ArithmeticException("Invalid date");
                }
            }
            else{
                throw new ArithmeticException("Invalid Month");
            }
            if (correctDate){
                System.out.println("Valid date");
                System.out.println(java.time.LocalDate.now());
            }
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
    public static void main(String[] args){
        createDate();
    }
}
