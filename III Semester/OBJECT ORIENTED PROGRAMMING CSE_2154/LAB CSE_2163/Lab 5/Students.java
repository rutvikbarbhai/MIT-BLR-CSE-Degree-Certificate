//Full credits to Varun M for this code, couldn't without him
import java.util.*;
class Students {
    Scanner sc=new Scanner(System.in);
    int regNum;
    String name;
    String DOJ;
    short sem;
    double gpa,cgpa;
    static int ctr=1;
    Students(String s, int ns, double g, double c){
        name=s;
        sem=(short)ns;
        gpa=g;
        cgpa=c;
        System.out.println("Enter date, month and year: ");
        int date=sc.nextInt();
        int month=sc.nextInt();
        int year=sc.nextInt();
        String s0=Integer.toString(date);
        String s1=Integer.toString(month);
        String s2=Integer.toString(year);
        DOJ=(s0+"/"+s1+"/"+s2);
        regNum =get_reg(ctr,year);
        ctr++;
    }
    static int get_reg(int n,int year){
        String s=Integer.toString(year);
        String s1=Integer.toString(n);
        s=s.substring(1);
        s+=s1;
        return Integer.parseInt(s);
    }

    public static void main(String []args){
        Scanner sc1=new Scanner(System.in);
        Students[] s1=new Students[5];

        for(int i=0;i<5;i++){
            System.out.println("Enter student details: ");
            String n=sc1.nextLine();
            int sem=sc1.nextInt();
            double gpa=sc1.nextDouble();
            double cgpa=sc1.nextDouble();
            sc1.nextLine();
            s1[i]=new Students(n,sem,gpa,cgpa);
        }
        s1=sort_sem(s1);
        System.out.println("Student records");
        System.out.println("Reg num\tName\tDate of joining\tSemester GPA\tCGPA");
        for(int j=0;j<5;j++){
            s1[j].display();
        }

        s1=sort_name(s1);
        System.out.println("Student records");
        System.out.println("Reg num\tName\tDate of joining\tSemester GPA\tCGPA");
        for(int j=0;j<5;j++){
            s1[j].display();
        }

        System.out.println("Enter character: ");
        char c=sc1.next().charAt(0);
        System.out.println("Student names starting with particular char");
        for(int j=0;j<5;j++){
            String res=s1[j].findChar(c);
            System.out.println(res);
        }
        Scanner sc2=new Scanner(System.in);
        String s10;
        System.out.println("Enter substring: ");
        s10=sc2.nextLine();
        System.out.println("Student names containing substring");
        for(int j=0;j<5;j++){
            String res1=s1[j].findSubstr(s10);
            System.out.println(res1);
        }
        System.out.println("Abbreviated names: ");
        for(int i=0;i<5;i++){
            System.out.println(abbreviate(s1[i].name));
        }

    }
    static String abbreviate(String s){
        String s1=s.substring(0,1);
        int index=s.indexOf(" ");
        s=s1+"."+s.substring(index);
        return s;
    }

    String findSubstr(String s){
        if(this.name.contains(s))
            return this.name;
        return "";
    }
    String findChar(char c){

        String s=Character.toString(c);
        if(this.name.contains(s))
            return this.name;

        return "";
    }

    void display(){
        System.out.println(regNum +"\t"+name+"\t"+DOJ+"\t"+sem+"\t "+gpa+"\t"+cgpa);
    }

    static Students[] sort_sem(Students[] s1){

        Students rnd;

        for(int i=0;i<5;i++){
            for(int j=i+1-i;j<5;j++){
                if(s1[j].sem<s1[i].sem){
                    rnd=s1[i];
                    s1[i]=s1[j];
                    s1[j]=rnd;
                }
                else if(s1[j].sem==s1[i].sem){
                    if(s1[j].cgpa<s1[i].cgpa){
                        rnd=s1[i];
                        s1[i]=s1[j];
                        s1[j]=rnd;
                        continue;
                    }
                    rnd=s1[j];
                    s1[j]=s1[j+1];
                    s1[j+1]=rnd;
                }
            }
        }
        return s1;
    }


    static Students[] sort_name(Students[] s){

        Students rnd;
        int temp;

        for(int i=0;i<5;i++){
            for(int j=0;j<5-i;j++){
                if(i==j)
                    continue;
                temp=s[i].name.compareTo(s[j].name);
                if(temp>0){
                    rnd=s[i];
                    s[i]=s[j];
                    s[j]=rnd;
                }
            }
        }
        return s;
    }

}