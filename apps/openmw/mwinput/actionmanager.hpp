#ifndef MWINPUT_ACTIONMANAGER_H
#define MWINPUT_ACTIONMANAGER_H

#include <osg/ref_ptr>
#include <osgViewer/ViewerEventHandlers>

namespace osgViewer
{
    class Viewer;
    class ScreenCaptureHandler;
}

namespace MWInput
{
    class BindingsManager;

    class ActionManager
    {
    public:
        ActionManager(BindingsManager* bindingsManager,
            osgViewer::ScreenCaptureHandler::CaptureOperation* screenCaptureOperation,
            osg::ref_ptr<osgViewer::Viewer> viewer, osg::ref_ptr<osgViewer::ScreenCaptureHandler> screenCaptureHandler);

        void update(float dt);

        void executeAction(int action);

        bool checkAllowedToUseItems() const;

        void toggleMainMenu();
        void toggleInventory();
        void toggleConsole();
        void screenshot();
        void toggleJournal();
        void activate();
        void rest();
        void quickLoad();
        void quickSave();

        void quickKey(int index);
        void showQuickKeysMenu();

        void resetIdleTime();
        float getIdleTime() const { return mTimeIdle; }

        bool isSneaking() const;

    private:
        void handleGuiArrowKey(int action);

        BindingsManager* mBindingsManager;
        osg::ref_ptr<osgViewer::Viewer> mViewer;
        osg::ref_ptr<osgViewer::ScreenCaptureHandler> mScreenCaptureHandler;
        osgViewer::ScreenCaptureHandler::CaptureOperation* mScreenCaptureOperation;

        float mTimeIdle;
    };
}
#endif
