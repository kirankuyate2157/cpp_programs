public class testj {
    public static void main(String[] args) {
        int pro = 1;
        int n = Integer.parseInt(args[0]);

        for (int i = 1; i <= n; i++) {
            pro *= i;
        }
        System.out.println("pro=" + pro);
    }
}