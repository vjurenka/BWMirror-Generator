package bwmirror.impl;

import java.util.ArrayList;

/**
 * User: PC
 * Date: 30.4.2014
 * Time: 18:07
 */
public class FieldList<E> extends ArrayList<E> {

    @Override
    public boolean add(E e) {
        if(this.contains(e)){
            return false;
        }
        return super.add(e);
    }
}
