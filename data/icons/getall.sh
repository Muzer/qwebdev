icons="actions/document-new.png actions/document-open.png actions/document-save.png actions/document-save-as.png actions/document-save-all.png actions/document-close.png devices/video-display.png mimetypes/text-plain.png mimetypes/text-html.png actions/application-exit.png actions/run-build-configure.png actions/help-about.png actions/help-contents.png"
oldPath=`pwd`
cd /usr/share/icons/oxygen/16x16/
cp $icons $oldPath/16x16
cd /usr/share/icons/oxygen/22x22/
cp /usr/share/icons/oxygen/22x22/$icons $oldPath/22x22
cd $oldPath
