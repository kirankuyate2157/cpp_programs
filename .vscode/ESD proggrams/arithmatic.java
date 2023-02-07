import java.util.*;

class arithmatic {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("Enter two numbers you want to perform operations on ");
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            System.out.println("Enter the operation do you want to perform : \n 1. +\n2. -\n3. *\n4. /\n 5. % ");
            int op = sc.nextInt();
            int ans = 0;
            if (op == 1) {
                ans = a + b;
            } else if (op == 2) {
                ans = a - b;
            } else if (op == 3) {
                ans = a * b;
            } else if (op == 4) {
                ans = a / b;
            } else if (op == 5) {
                ans = a % b;
            }
            System.out.println("Ans : " + ans);
            System.out.println("Do you want to continue? Y/N");
            char x = sc.next().charAt(0);
            if (x == 'y' || x == 'Y')
                continue;
            break;
        }
    }

}