//Same goes for this code, credits to Varun M for this, couldn't without him
class commaPunctuation {
    static String add_commas(String num){
        int len=num.length();
        int ctr= len /3;
        StringBuilder res= new StringBuilder();
        for(int i=0;i<ctr;i++){
            String s=num.substring(len-3);
            num=num.substring(0,len-3);
            if(res.isEmpty())
                res = new StringBuilder(s);
            else
                res.insert(0, s + ",");
            len=len-3;
        }
        if (!num.isEmpty())
            res.insert(0, num + ",");
        return res.toString();
    }
    public static void main(String []args){
        String s="123456";
        System.out.println(add_commas(s));

    }
}

