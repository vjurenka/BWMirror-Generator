package bwapi;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Enumeration;
import java.util.regex.Pattern;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipFile;

/**
 * Get a list of all resources that exist on the classpath that match
 * a given java.util.regex.Pattern.
 *
 * All elements listed in the system property "java.class.path" will be searched
 * and whether it is a JAR file or directory will be handled automatically.
 *
 * Resources that are listed with this class can be loaded using a ClassLoader.
 * e.g. Thread.currentThread().getContextClassLoader().getResourceAsStream(...)
 */
public class ResourceList {

    /**
     * Returns a list of all resources within the classpath matching the given pattern.
     *
     * NOTE: If your pattern includes paths, you should use forward slashes between
     * directory and filenames instead of backslashes, even when running on Windows.
     * Internally, paths will be converted to forward slashes before the pattern is
     * matched for consistency reasons.
     *
     * @param pattern the pattern to match
     * @return the resources in the order they are found
     */
    public static Collection<String> getResources(final Pattern pattern) {
        final ArrayList<String> retval = new ArrayList<>();
        final String classPath = System.getProperty("java.class.path", ".");
        final String[] classPathElements = classPath.split(File.pathSeparator);
        for (final String element : classPathElements) {
            retval.addAll(getResources(element, pattern));
        }
        return retval;
    }

    private static Collection<String> getResources(final String element,
                                                   final Pattern pattern) {
        final ArrayList<String> retval = new ArrayList<>();
        final File file = new File(element);
        if (file.isDirectory()) {
            String baseDirectory;
            try {
                baseDirectory = file.getCanonicalPath() + File.separator;
            } catch (final IOException e) {
                throw new java.lang.Error(e);
            }
            retval.addAll(getResourcesFromDirectory(file, baseDirectory, pattern));
        } else {
            retval.addAll(getResourcesFromJarFile(file, pattern));
        }
        return retval;
    }

    private static Collection<String> getResourcesFromJarFile(final File file, final Pattern pattern) {
        final ArrayList<String> retval = new ArrayList<>();
        ZipFile zf;
        try {
            zf = new ZipFile(file);
        } catch (final ZipException e) {
            throw new java.lang.Error(e);
        } catch (final IOException e) {
            throw new java.lang.Error(e);
        }
        final Enumeration e = zf.entries();
        while (e.hasMoreElements()) {
            final ZipEntry ze = (ZipEntry) e.nextElement();
            final String fileName = ze.getName();
            final boolean accept = pattern.matcher(fileName).matches();
            if (accept) {
                retval.add(fileName);
            }
        }
        try {
            zf.close();
        } catch (final IOException e1) {
            throw new java.lang.Error(e1);
        }
        return retval;
    }

    private static Collection<String> getResourcesFromDirectory(final File directory, final String baseDirectory, final Pattern pattern) {
        final ArrayList<String> retval = new ArrayList<>();
        final File[] fileList = directory.listFiles();
        for (final File file : fileList) {
            if (file.isDirectory()) {
                retval.addAll(getResourcesFromDirectory(file, baseDirectory, pattern));
            } else {
                try {
                    // the below call to file.getCanonicalPath will return an absolute path.
                    // since JAR file paths will all be relative, we trim off the absolute path's
                    // base directory prefix before doing the regex match.
                    //
                    // also convert the remaining sub-path to use forward slashes. this is a convenience thing
                    // as the _ONLY_ time a path being matched in this entire class will have backslashes
                    // is in this method (when checking local directories only) and ONLY on Windows.
                    // checking JAR file paths (getResourcesFromJarFile) will have forward slashes, even
                    // on Windows...
                    // so let's just force forward slashes everywhere to be consistent, shall we?
                    final String fileName = file.getCanonicalPath().substring(baseDirectory.length()).replaceAll("\\\\", "/");
                    final boolean accept = pattern.matcher(fileName).matches();
                    if (accept) {
                        // also note that we are adding the slash-converted sub-path to the list of files, NOT
                        // the absolute path initially obtained! this is so that this path can be passed
                        // directly into a call to getResourceAsStream() or similar
                        retval.add(fileName);
                    }
                } catch (final IOException e) {
                    throw new java.lang.Error(e);
                }
            }
        }
        return retval;
    }

    /**
     * list the resources that match args[0]
     *
     * @param args args[0] is the pattern to match, or list all resources if
     *             there are no args
     */
    public static void main(final String[] args) {
        Pattern pattern;
        if (args.length < 1) {
            pattern = Pattern.compile(".*");
        } else {
            pattern = Pattern.compile(args[0]);
        }
        final Collection<String> list = ResourceList.getResources(pattern);
        for (final String name : list) {
            System.out.println(name);
        }
    }
}
