package generator;

import java.io.File;
import java.util.List;

/**
 * User: PC
 * Date: 29. 7. 2014
 * Time: 22:41
 */
public class PackageProcessOptions {

    //name of the package to create (bwapi/bwta)
    public String packageName;

    //directory where C headers are located
    public File cHeadersDir;

    //optional - name of class which will hold global functions
    public String globalClassName;

    //optional - list of classes that should be used in import statements in created .java files
    public List<String> additionalImportClasses;

    //optional - directory containing files that should be copied inside the generated api
    public File manualCopyClassesDir;
}
