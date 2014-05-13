import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;


public class Main {
    public static void main(String args[]) throws IOException {
    	Scanner in = new Scanner (new BufferedInputStream(System.in));
        int num=in.nextInt();
        String str="x";
       
        double small_diff=-1.0;
        int index=0;
        in.nextLine();
        for(int i=1;i<=num;i++){
        	str=in.nextLine();
        	double diff=0.0;
        	if(str.indexOf("+")!=-1)
        	{
        		String[] x=str.split("\\+");
        		diff=Math.abs(9-(Double.valueOf(x[0].trim())+Double.valueOf(x[1].trim())));
        	}else if(str.indexOf("-")!=-1){
        		str=str.replaceFirst("-", "+");
        		String[] x=str.split("\\+");
        		diff=Math.abs(9-(Double.valueOf(x[0].trim())-Double.valueOf(x[1].trim())));
        	}else if(str.indexOf("*")!=-1)
        	{
        		String[] x=str.split("\\*");
        		diff=Math.abs(9-(Double.valueOf(x[0].trim())*Double.valueOf(x[1].trim())));
        	}else if(str.indexOf("/")!=-1)
        	{
        		String[] x=str.split("/");
        		diff=Math.abs(9-(Double.valueOf(x[0].trim())/Double.valueOf(x[1].trim())));
        	}else{
        		System.out.println("++");
        	}
        	
        	if (small_diff==-1){
        		small_diff=diff;
        		index=i;
        	}else if(small_diff>diff){
        		small_diff=diff;
        		index=i;
        	}

        }
        System.out.println(index);
       
    }
}