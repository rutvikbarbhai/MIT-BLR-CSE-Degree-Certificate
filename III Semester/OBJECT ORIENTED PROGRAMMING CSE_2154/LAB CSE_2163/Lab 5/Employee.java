class Employee {
    String Ename;
    String mail;
    void capitalizeString() {
        char[] chars = this.Ename.toLowerCase().toCharArray();
        boolean isLetter = false;
        for (int i = 0; i < chars.length; i++) {
            if(Character.isLetter(chars[i])) {
                if(!isLetter) {
                    chars[i] = Character.toUpperCase(chars[i]);
                }
                isLetter = true;
            }
            else {
                isLetter = false;
            }
        }
        this.Ename = String.valueOf(chars);
    }
    void generateEmail(){
        char[] chars = this.Ename.toLowerCase().toCharArray();
        char[] letters = new char[15];
        int i,  k = 1;
        boolean isSpace = false ;
        letters[0] = chars[0];
        for (i = 1; i < chars.length; i++){
            if(Character.isLetter(chars[i])) {
                if (isSpace) {
                    letters[k] = chars[i];
                    k++;
                }
            }
            else{
                isSpace = true;
            }
        }
        char[] email = new char[k];
        for( i = 0; i < k; i++){
            email [i] = letters[i];
        }
        this.mail = String.valueOf(email) + "@email.com";
    }
    public static void main(String[] args) {
        Employee a = new Employee();
        a.Ename = "jeevan sHaJu JOHN";
        a.generateEmail();
        a.capitalizeString();
        System.out.println(a.Ename);
        System.out.println(a.mail);
    }
}