package bwmirror.api;

import bwmirror.c.CDeclaration;
import bwmirror.generator.Generator;
import bwmirror.generator.MirrorContext;
import bwmirror.generator.PackageProcessOptions;

import java.util.List;

/**
 * User: PC
 * Date: 19. 4. 2015
 * Time: 16:06
 */
public class DefaultEventListener implements GeneratorEventListener {
    @Override
    public void onPackageProcessingStart(PackageProcessOptions packageProcessOptions, MirrorContext mirrorContext, Generator generator, List<CDeclaration> cDeclarationList) {

    }

    @Override
    public void onCDeclarationRead(PackageProcessOptions packageProcessOptions, CDeclaration cDeclaration) {
    }

    @Override
    public void onPackageProcessingEnd(PackageProcessOptions packageProcessOptions) {

    }

    @Override
    public void beforeManual() {

    }

    @Override
    public void afterManual() {

    }

    @Override
    public void beforeCompile() {

    }

    @Override
    public void afterCompile() {

    }

    @Override
    public void beforeHeaders() {

    }

    @Override
    public void afterHeaders() {

    }
}
