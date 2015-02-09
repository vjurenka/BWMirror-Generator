package c;

import util.Pair;
import util.Triple;

import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: Vladimir
 * Date: 27.2.2014
 * Time: 10:49
 */
public interface Method extends Field{

    public List<Param> getParams();

    public Method clone();

    public boolean isStatic();
}
