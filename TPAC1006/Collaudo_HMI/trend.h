/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef TREND_H
#define TREND_H

#include "pagebrowser.h"
#include "trend_other.h"
#include "main.h"

#include <QMouseEvent>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_marker.h>

#undef MARKER
#define VALUE_TIME_SCALE

namespace Ui {
class trend;
}

class InterruptedCurve : public QwtPlotCurve
{
protected:
    virtual void drawCurve( QPainter *p, int style, const QwtScaleMap &xMap, const QwtScaleMap &yMap, const QRectF &canvasRect, int from, int to ) const;
};

class TimeScaleDraw: public QwtScaleDraw
{
public:
    TimeScaleDraw(const QTime &base):
        baseTime(base)
    {
    }
    virtual QwtText label(double v) const
    {
        QTime upTime = baseTime.addSecs((int)v);
        //fprintf(stderr, "%s + %f = %s\n", baseTime.toString().toAscii().data(), v, upTime.toString().toAscii().data());
        return upTime.toString();
        //return QString("%1").arg(v);
    }
    void setBaseTime(const QTime &base)
    {
        baseTime = base;
    }
private:
    QTime baseTime;
};
#ifdef VALUE_TIME_SCALE
class NormalScaleDraw: public QwtScaleDraw
{
public:
    NormalScaleDraw(const int &decimals = 0)
    {
        setDecimalNb(decimals);
    }
    virtual QwtText label(double v) const
    {
        //fprintf(stderr, "%s + %f = %s\n", baseTime.toString().toAscii().data(), v, upTime.toString().toAscii().data());
        return QString().setNum(v,'f',decimalNb);
    }
    void setDecimalNb(const int &decimals)
    {
        decimalNb = decimals;
    }
    int getDecimalNb()
    {
        return decimalNb;
    }
private:
    int decimalNb;
};
#endif
class trend : public page
{
    Q_OBJECT
    
public:
    explicit trend(QWidget *parent = 0);
    ~trend();
    virtual void reload(void);
    virtual void updateData();
    bool printGraph();
    bool setOnline(bool status);
    bool getOnline();
    void setPan();
    bool setRange();
    bool bringFront(int pen);
    void enableZoomMode(bool);
    void disableUpdate();
    
private slots:
    void refreshEvent(trend_msg_t item_trend);
    void moved(const QPoint &pos);
    void selected(const QPolygon &pol);
    void on_pushButtonPen_clicked();
    void on_pushButtonSelect_clicked();
    void on_pushButtonZoom_toggled(bool checked);
    void on_pushButton_clicked();
    void on_pushButtonRight_clicked();
    void on_pushButtonLeft_clicked();
    void on_pushButtonUp_clicked();
    void on_pushButtonDown_clicked();
    void on_pushButtonPenColor_clicked();
    
    void on_pushButtonOnline_clicked();

private:
    bool LoadTrend(const char * filename, QString * ErrorMsg = NULL);
    bool loadFromFile(QDateTime Ti);
    bool Load(QDateTime begin, QDateTime end, int skip = 0);
    bool Load(const char * filename, QDateTime * begin = NULL, QDateTime * end = NULL, int skip = 0);
    bool loadWindow(QDateTime Ti, QDateTime Tmax, double ymin = 0, double ymax = 0, int pen = actualPen);
    bool showWindow(QDateTime Tmin, QDateTime Tmax, double ymin = 0, double ymax = 0, int pen = actualPen);
    void loadOrientedWindow();
    void incrementTime(int direction);
    void incrementValue(int direction);
    void initValue();
    void createElem();
private:
    Ui::trend *ui;
    
    QwtPlotPicker *d_picker;
    QwtPlot * d_qwtplot;
    QwtPlotGrid *grid;
    QwtScaleDraw * timescaledraw;
#ifdef MARKER
    QwtPlotMarker *d_marker;
#endif
    int timeAxisId;
    int valueAxisId;
    
    bool _zoom;
    bool force_back;
    bool reloading;
    
    trend_other * popup;
    
    /* period of the loaded data */
    int TrendPeriodSec;
    
    /* first time sample of loaded data */
    QDateTime TzeroLoaded;
    /* windows size in seconds of loaded data */
    int LoadedWindowSec;
    
    /* first time sample of visible data  at the begin */
    QDateTime Tzero;
    /* windows size in seconds of visible data at the begin */
    int VisibleWindowSec;
    bool loading;
    
    bool first_time;
    bool overloadActualTzero;
    
    bool _load_window_busy;
    TimeScaleDraw * timeScale;
#ifdef VALUE_TIME_SCALE
    NormalScaleDraw * valueScale[PEN_NB];
#endif
    int LogPeriodSec;
    int sample_to_skip;
    QString errormsg;

};

#endif // TREND_H


