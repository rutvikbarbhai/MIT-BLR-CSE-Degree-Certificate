import java.util.ArrayList;
import java.util.List;

class STUDENT {
    String Sname;
    String initials;
    STUDENT(String a){
        Sname = a;
    }

    void extractInitials() {
        char[] chars = this.Sname.toCharArray();
        int i, k = 0;
        boolean firstLetter = true;
        char[] letters = new char[chars.length];
        for (i = 0; i < chars.length; i++) {
            if (Character.isLetter(chars[i])) {
                if (firstLetter) {
                    firstLetter = false;
                    letters[k] = chars[i];
                    k++;
                }
            } else
                firstLetter = true;
        }
        char[] init = new char[k];
        for (i = 0; i < k; i++) {
            init[i] = letters[i];
        }
        this.initials = String.valueOf(init);
    }
    String removeWhiteSpaces(){
        String s1 = Sname;
        s1 = s1.replaceAll("\\s", "");
        return s1;
    }
    boolean checkForSubstring(String subString){
        return Sname.contains(subString);
    }
    static void sortName(List<STUDENT> students) {
        students.sort((s1, s2) -> s1.getName().compareToIgnoreCase(s2.getName()));
    }

    String getName() {
        return Sname;
    }

    public static void main(String[] args){
        STUDENT s1 = new STUDENT("Jeevan Shaju John");
        ArrayList<STUDENT> students = new ArrayList<>();
        students.add(new STUDENT("Hello"));
        students.add(new STUDENT("Howdy"));
        students.add(new STUDENT("Hi"));
        s1.extractInitials();
        System.out.println(s1.initials);
        System.out.println(s1.removeWhiteSpaces());
        System.out.println(s1.checkForSubstring("van"));
        sortName(students);
        for (STUDENT student : students) {
            System.out.println(student.getName());
        }
    }
}