#ifndef Z3D_CAMERAACQUISITION___ZCAMERASELECTORWIDGET_H
#define Z3D_CAMERAACQUISITION___ZCAMERASELECTORWIDGET_H

#include "zcameraacquisition_global.h"
#include "zcamerainterface.h"

#include <QWidget>

namespace Ui
{
class ZCameraSelectorWidget;
}

namespace Z3D
{

class ZCameraInfo;
class ZCameraPluginInterface;


class Z3D_CAMERAACQUISITION_SHARED_EXPORT ZCameraSelectorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ZCameraSelectorWidget(QWidget *parent = 0);
    ~ZCameraSelectorWidget();

    static Z3D::ZCameraInterface::Ptr getCamera();

    Z3D::ZCameraInterface::Ptr getSelectedCamera() const;

signals:
    void cameraSelected(Z3D::ZCameraInterface::Ptr camera);

private slots:
    void on_pluginsComboBox_currentIndexChanged(int index);

    void on_cameraListWidget_currentRowChanged(int currentRow);

    void on_continueButton_clicked();

private:
    Ui::ZCameraSelectorWidget *ui;

    QList<Z3D::ZCameraPluginInterface *> m_pluginList;

    QList<Z3D::ZCameraInfo *> m_currentCameraList;

    Z3D::ZCameraInterface::Ptr m_selectedCamera;
};

} // namespace Z3D

#endif // Z3D_CAMERAACQUISITION___ZCAMERASELECTORWIDGET_H