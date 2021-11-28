/*
P1. Stack Construction
https://open.kattis.com/problems/stack
*/

import java.util.*;

public class Road 
{
    public static void main(String [] args) {

    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    input.nextLine();

    for (int i=0; i<n; i+=1) 
    {
        String str = input.nextLine();
        int count = 0;

        ArrayList<Character> stack = new ArrayList<>();
        int top = -1;

        for (int pos=0; pos<str.length(); pos+=1) 
        {
            if (top >= 0  && stack.get(top) == str.charAt(pos)) {
                count += 1;
        }
        else 
        {
            top += 1;
            stack.add(str.charAt(pos));
            count += 2;
        }

        int sp = top;
        int cp = pos+1;
        boolean match = false;
        while (cp < str.length()) 
        {
            if (stack.get(sp) == str.charAt(cp)) 
            {
                sp -= 1;
                if (sp < 0) 
                {
                    match = true;
                    break;
                }
            }
            cp += 1;
        }

        if (!match) 
        {
            stack.remove(top);
            top -= 1;
            count += 1;
        }
        }
        System.out.printf("%d%n",count);
    }

    }

}