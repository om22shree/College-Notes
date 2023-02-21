public class Job {
    Integer id;
    Integer m1;
    Integer m2;

    public Job(Integer id, Integer m1, Integer m2) {
        this.id = id;
        this.m1 = m1;
        this.m2 = m2;
    }

    @Override
    public String toString() {
        return "{id: " + this.id + ", M1: " + this.m1 + ", M2: " + this.m2 + "}";
    }
}