package bwmirror.util;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 16:52
 */
public class Triple<K,V,D> {

    public K first;

    public V second;

    public D third;

    public Triple() {
    }

    public Triple(K first, V second) {
        this.first = first;
        this.second = second;
    }

    public Triple(K first, V second, D third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
}
