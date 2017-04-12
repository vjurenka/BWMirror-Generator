package bwmirror.api;

import bwmirror.c.CDeclaration;
import bwmirror.generator.Generator;
import bwmirror.generator.MirrorContext;
import bwmirror.generator.PackageProcessOptions;

import java.util.List;

/**
 * User: PC
 * Date: 19. 4. 2015
 * Time: 16:00
 */
public interface GeneratorEventListener {


    public void onPackageProcessingStart(PackageProcessOptions packageProcessOptions, MirrorContext mirrorContext, Generator generator, List<CDeclaration> cDeclarationList);

    public void onCDeclarationRead(PackageProcessOptions packageProcessOptions, CDeclaration cDeclaration);

    public void onPackageProcessingEnd(PackageProcessOptions packageProcessOptions);

    public void beforeManual();

    public void afterManual();

    public void beforeCompile();

    public void afterCompile();

    public void beforeHeaders();

    public void afterHeaders();



}
