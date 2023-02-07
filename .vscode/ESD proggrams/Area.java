import java.util.*;

public class Area {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int op = 0;
        System.out.println("1. Area of circle \n2. Area of ractangle : ");
        op = sc.nextInt();
        if (op == 2) {

            int l, w;
            System.out.println("enter the length of object : ");
            l = sc.nextInt();
            System.out.println("enter the width of object : ");
            w = sc.nextInt();
            System.out.println("Area of Reactangle Object would be : " + l * w + "\n\n");
        } else if (op == 1) {
            System.out.println("enter the Radius of circle : ");
            Float r = sc.nextFloat();
            System.out.println("Area of the Circle would be : " + (3.14 * r * r) + "\n\n");
        } else {
            System.out.println("You haven`t choosed ! ok ");
        }
    }
}
