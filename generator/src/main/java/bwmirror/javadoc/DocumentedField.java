package bwmirror.javadoc;

/**
 * User: PC
 * Date: 24. 6. 2014
 * Time: 18:15
 */
public class DocumentedField {

    public DocumentedField(String name) {
        this.name = name;
    }

    String name;

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof DocumentedField)) return false;

        DocumentedField that = (DocumentedField) o;

        if (name != null ? !name.equals(that.name) : that.name != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }
}
