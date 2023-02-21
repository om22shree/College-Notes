import java.util.*;

public class Solve2 {
    public static void main(String[] args) {
        Scanner sr = new Scanner(System.in);
        // Initialization of arrays :-
        List<Integer> m1 = new ArrayList<Integer>();
        List<Integer> m2 = new ArrayList<Integer>();
        List<Integer> tot = new ArrayList<Integer>();
        List<Job> j = new ArrayList<Job>();

        // Data entry to the array :-
        System.out.print("Enter the total number of jobs: ");
        Integer n = sr.nextInt(); // Total number of jobs;
        
        // Reading data of individual tasks :-
        for (int i = 0; i < n; i++) {
            System.out.print("Enter details of job-" + (i + 1) + ": ");
            Integer x1 = sr.nextInt();
            Integer x2 = sr.nextInt();
            j.add(new Job(i, x1, x2));
            m1.add(x1);
            m2.add(x2);
            tot.add(x1 + x2);
        }

        // Iterate over the jobs :-
        for (Object ele : j)
            System.out.println(ele);

        // Johnson 2 machine Algorithm :-
        // Lets handle sequencing first.
        List<Job> qj = new ArrayList<Job>(n); // Job sequence array;
        // Find the minimum element: if in m1 add to the front..if in m2 add to the end.
        // Integer fr = 0, br = n-1;
        // while (m1.size() >= 1) {
        //     Integer min1 = Collections.min(m1);
        //     Integer min2 = Collections.min(m2);
        //     if (min1 < min2) {
        //         Integer jx = m1.indexOf(min1);
        //         qj.add(fr, j.get(jx));
        //         m1.remove(jx);
        //         m2.remove(jx);
        //         fr += 1;
        //     }
        //     else if (min2 < min1) {
        //         Integer jx = m2.indexOf(min2);
        //         qj.add(br, j.get(jx));
        //         m1.remove(jx);
        //         m2.remove(jx);
        //         br -= 1;
        //     }
        //     else {
        //         Integer jx1 = m1.indexOf(min1);
        //         Integer jx2 = m2.indexOf(min2);
        //         qj.add(fr, j.get(jx1));
        //         qj.add(br, j.get(jx2));
        //         fr += 1;
        //         br -= 1;
        //     }
        // }

        // // Iterate over the sequence :-
        // for (Object ele : qj)
        //     System.out.println(ele);
        
        sr.close();
    }
}
