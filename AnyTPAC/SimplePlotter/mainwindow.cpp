#include "mainwindow.h"
#include "ui_mainwindow.h"
#ifdef Q_WS_QWS
#include "alphanumpad.h"
#include "numpad.h"
#include "timepopup.h"
#endif

const QString trendsTPACDirectory ="/local/flash/data/customtrend";
const QString trendsPCDirectory ="C:/sandbox/plotter/trunk/SimplePlotter/trends";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // build on target
#ifdef Q_WS_QWS
  QMainWindow::showFullScreen();
  QWSServer::setCursorVisible( false );
#endif



    QValidator *validatorDeltaLine = new QIntValidator(1, 10000, this);
    ui->deltaLineEdit->setValidator (validatorDeltaLine);

    QString IpRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegExp IpRegex ("^" + IpRange
                     + "(\\." + IpRange + ")"
                     + "(\\." + IpRange + ")"
                     + "(\\." + IpRange + ")$");
    QRegExpValidator *ipValidator = new QRegExpValidator(IpRegex, this);

    ui->ipLineEdit->setValidator (ipValidator);

    ui->ipLineEdit->setText ("192.168.5.165");

    ui->getValuesPushButton->setEnabled (false);

    //on_radioDay_toggled(true);

    mectPtr=new mectComm();


    ui->radioDay->setChecked (true);
    ui->deltaLineEdit->setText ("200");


    pb=new QProgressBar(ui->customPlot);
    pb->setVisible (false);

#ifdef Q_WS_QWS
  ui->fromDateTimeEdit->setCalendarPopup (true);
  ui->toDateTimeEdit->setCalendarPopup (true);
#endif


    qCustomPlotSetUp();

    connect(mectPtr,SIGNAL(variablesReady()),this,SLOT(fillList()));
    connect(mectPtr,SIGNAL(dataReady()),this,SLOT(getValue()));
    connect(mectPtr,SIGNAL(errorSignal(QString)),this,SLOT(errorManager(QString)));
    connect(ui->customPlot, SIGNAL(legendClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)),
             this, SLOT(legendClick(QCPLegend*,QCPAbstractLegendItem*)));


}

MainWindow::~MainWindow()
{
    delete ui;
    //delete mectPtr;

}

void MainWindow::on_getVarPushButton_clicked()
{
    if(!ui->ipLineEdit->text ().isEmpty ())  {

        ui->varListWidget->clear ();

        ui->getValuesPushButton->setEnabled (false);

        if(mectPtr->openConnection (ui->ipLineEdit->text ())){

            if(mectPtr->requestVariableList (ui->ipLineEdit->text ())){

                ui->getVarPushButton->setEnabled (false);
                ui->ipLineEdit->setEnabled (false);

            }
        }
    }else{
         QMessageBox::critical (this," Error ","There is no IP ");
    }
}

void MainWindow::on_getTrendPushButton_clicked()
{
    if(!ui->ipLineEdit->text ().isEmpty ())  {

        ui->varListWidget->clear ();
        trendList.clear();

#ifdef Q_WS_QWS
        QDir trendsDirectory(trendsTPACDirectory);
#else
        QDir trendsDirectory(trendsPCDirectory);
#endif
        if(trendsDirectory.exists()){

            trendList=trendsDirectory.entryList(QStringList() << "*.csv" << "*.CSV",QDir::Files);
            fillTrendList();

        }else{

            QMessageBox::critical (this," Error ","Directory doesn't exist: "+ trendsDirectory.path());
        }
    }else{
        QMessageBox::critical (this," Error ","There is no IP ");
    }
}

void MainWindow::fillTrendList()
{
    ui->getVarPushButton->setEnabled (true);
    ui->ipLineEdit->setEnabled (true);

    if( trendList.count () ){

        trendList.sort ();
        trendList.removeDuplicates ();

        ui->varListWidget->addItems (trendList);
        ui->varListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        for(int i = 0; i < ui->varListWidget->count(); ++i)  {
            QListWidgetItem* item = 0;
            item = ui->varListWidget->item(i);
           //item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            //item->setCheckState(Qt::Unchecked);
        }

    ui->getValuesPushButton->setEnabled (true);
    ui->getValuesPushButton->setText("Plot Trend");
    }else{

        QMessageBox::critical (this," Trend List ","No Trends on target");
    }
}

void MainWindow::fillList()
{
    ui->getVarPushButton->setEnabled (true);
    ui->ipLineEdit->setEnabled (true);

    QStringList varList;

    mectPtr->getVariableList (varList);


    if( varList.count () ){

        varList.sort ();
        varList.removeDuplicates ();

        ui->varListWidget->addItems (varList);
        ui->varListWidget->setSelectionMode(QAbstractItemView::NoSelection);

        for(int i = 0; i < ui->varListWidget->count(); ++i)  {
            QListWidgetItem* item = 0;
            item = ui->varListWidget->item(i);

            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            item->setCheckState(Qt::Unchecked);
        }

    ui->getValuesPushButton->setEnabled (true);
    ui->getValuesPushButton->setText("Plot Values");
    }else{

        QMessageBox::critical (this," Variable List ","No Logged variables on target");
    }
}


void MainWindow::on_getValuesPushButton_clicked()
{
    ui->getValuesPushButton->setEnabled(false);

    if(ui->getValuesPushButton->text()=="Plot Values") {
        if(ui->varListWidget->count() > 0){
            QList <QListWidgetItem*> items;

            variableList.clear ();

            for(int i=0;i<ui->varListWidget->count ();i++){

                items.append (ui->varListWidget->item (i));
            }

            for(int i=0;i<items.count();i++){

                if (items.at(i)->checkState() == Qt::Checked){
                    variableList.append (items.at (i)->text ());
                }
            }

            progressBar(0);
            if (! mectPtr->requestValueList (ui->ipLineEdit->text (),ui->fromDateTimeEdit->dateTime (),ui->toDateTimeEdit->dateTime ()
                                             ,ui->deltaLineEdit->text (),variableList)) {
                progressBar(100);
                ui->getValuesPushButton->setEnabled(true);
            }
        }
        else {
            ui->getValuesPushButton->setEnabled(true);
        }
    }

    else if(ui->getValuesPushButton->text()=="Plot Trend"){

        if(ui->varListWidget->count() >0){
            QList <QListWidgetItem*> items;
            QString itemTrendText;

            for(int i=0;i<ui->varListWidget->count ();i++){

                items.append (ui->varListWidget->item (i));
            }

            for(int i=0;i<items.count();i++){

                if (items.at(i)->isSelected()){
                    itemTrendText=items.at (i)->text ();
                    break;
                }
            }
            if(!itemTrendText.isEmpty()){
#ifdef Q_WS_QWS
                QString filePath("/local/flash/data/customtrend/");
#else
                QString filePath("C:/sandbox/plotter/trunk/SimplePlotter/trends/");
#endif

                QFile file(filePath+itemTrendText);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
                    QMessageBox::critical (this," Trends List ","Can't Open the file: "+itemTrendText);
                    ui->getValuesPushButton->setEnabled(true);
                    return;
                }

                QStringList trendData;
                QString tmp;
                variableList.clear();
                QTextStream in(&file);
                int trendIndex=0;
                while (!in.atEnd()) {
                    QString line = in.readLine();
                    if(trendIndex!=0){
                        trendData=line.split(";",QString::SkipEmptyParts);
                        tmp=trendData.at(1);
                        tmp.replace(" ","");
                        trendData.replace(1,tmp);
                       // tmp=trendData.at(2);
                       // trendData.replace(2,"#"+tmp);
                        variableList.append(tmp);
                    }
                    trendIndex++;
             }
            if(!variableList.isEmpty()){
                progressBar(0);
                if (! mectPtr->requestValueList (ui->ipLineEdit->text (),ui->fromDateTimeEdit->dateTime (),ui->toDateTimeEdit->dateTime ()
                                                 ,ui->deltaLineEdit->text (),variableList)) {
                    progressBar(100);
                    ui->getValuesPushButton->setEnabled(true);
                   }

            }else{
                QMessageBox::critical (this," Trends List ","File: "+itemTrendText +" is Empty");
                ui->getValuesPushButton->setEnabled(true);
            }
            }else{
                QMessageBox::critical (this," Trends List ","No trend selected ");
                ui->getValuesPushButton->setEnabled(true);
            }
        }else {
            QMessageBox::critical (this," Trends List ","There are no Trends ");
            ui->getValuesPushButton->setEnabled(true);
        }
    }
}

void MainWindow::getValue()
{
    QList <QList <varPoint> > valueList;

    if (mectPtr->getValueVector (variableList, valueList)) {
        ui->customPlot->clearGraphs();
        for(int i=0;i<variableList.count();i++)
            plotData(valueList.at(i), variableList.at(i));
    }
    progressBar(100);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
    ui->getValuesPushButton->setEnabled(true);
}

void MainWindow::qCustomPlotSetUp(){

    //X,Y Axis
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(-2, 50);
    ui->customPlot->xAxis->setRange (1,QDateTime::currentDateTime ().toTime_t ());

    //actions over the plot
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    //data ticker
   QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);

    dateTicker->setDateTimeFormat("yyyy-MM-dd\nHH:mm:ss");

    ui->customPlot->xAxis->setTicker(dateTicker);


    ui->customPlot->xAxis->ticker ()->setTickCount (4);
    ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family (),7.5));

    ui->customPlot->xAxis->setLabelColor (Qt::white);
    ui->customPlot->yAxis->setLabelColor (Qt::white);

    ui->customPlot->axisRect()->setBackground(QBrush(QColor(Qt::black)));
    ui->customPlot->setBackground(QBrush(QColor(Qt::black)));
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);

    ui->customPlot->setInteraction(QCP::iSelectLegend);
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setSelectableParts(QCPLegend::spItems);
    ui->customPlot->legend->setSelectedBorderPen(QPen(QColor(Qt::yellow)));
    #ifdef Q_WS_QWS
    ui->customPlot->legend->setVisible(false);
    #endif

    //fill color List
    colorList.append ("#ff0000");
    colorList.append ("#8A2BE2");
    colorList.append ("#7800d1");
    colorList.append ("#008000");
    colorList.append ("#35c4db");
    colorList.append ("#d17800");
    colorList.append ("#800040");
    colorList.append ("#d9593b");
    colorList.append ("#ffffff");
    colorList.append ("#002344");
    colorList.append ("#0000FF");
    colorList.append ("#696969");
    colorList.append ("#FFD700");
}



void MainWindow::plotData(QList <varPoint> valuesList , QString variableName){

    //set data
    QVector<QCPGraphData> dataPoint(valuesList.count ());

    for (int i=0; i<valuesList.count (); ++i)
    {
        dataPoint[i].key = valuesList.at (i).X.toTime_t();
        dataPoint[i].value = valuesList.at (i).Y;
    }

    QCPGraph *mainGraphLog;
    mainGraphLog = ui->customPlot->addGraph(0,0);
    //plot MainData
    mainGraphLog->data()->set(dataPoint);
     mainGraphLog->setName(variableName);

    QColor colorPen(colorList.at (qrand() % colorList.count ()));

    mainGraphLog->setPen(QPen(colorPen,2));

    //data ticker
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);

    dateTicker->setTickOrigin (dataPoint[0].key);

    dateTicker->setDateTimeFormat("yyyy-MM-dd\nHH:mm:ss");

    ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family (),7.5));

    ui->customPlot->xAxis->setTicker(dateTicker);

    ui->customPlot->xAxis->ticker ()->setTickCount (4);

    ui->customPlot->xAxis->ticker ()->setTickStepStrategy (QCPAxisTickerDateTime::tssMeetTickCount);

    mainGraphLog->rescaleKeyAxis(true);

    mainGraphLog->rescaleValueAxis();

}
void MainWindow::legendClick(QCPLegend *legend, QCPAbstractLegendItem *item){
  if (item)
  {

      item->setSelected(true);
      for(int i=0;i<legend->selectedItems().count();i++){
          if(legend->selectedItems().at(i)->selected()){
              qDebug()<<"selected N°:"<<i;
          }
      }



  }
}



void MainWindow::errorManager(QString errorCode){

    QMessageBox::critical (this," Error ",errorCode);

}

void MainWindow::on_radioDay_toggled(bool checked)
{

int plotPixNumber= ui->customPlot->geometry().width();
    if(checked){
        QDateTime startDay(QDate::currentDate ());

        ui->fromDateTimeEdit->setDateTime (startDay);

        ui->toDateTimeEdit->setDateTime (QDateTime::currentDateTime ());

        int delta=(ui->toDateTimeEdit->dateTime ().toTime_t () - ui->fromDateTimeEdit->dateTime ().toTime_t ())/plotPixNumber;

        ui->deltaLineEdit->setText (QString::number (delta));

    }
}



void MainWindow::on_radioWeek_toggled(bool checked)
{
    int plotPixNumber= ui->customPlot->geometry().width();
    if(checked){

        QDate currentDate=QDate::currentDate ();
        int currentWeekDay=currentDate.dayOfWeek ()*-1;

        currentDate=currentDate.addDays(currentWeekDay+1);

        QTime  start(0,0,0);
        QDateTime startWeek(currentDate,start);

        ui->fromDateTimeEdit->setDateTime (startWeek);
        ui->toDateTimeEdit->setDateTime (QDateTime::currentDateTime ());

        int delta=(ui->toDateTimeEdit->dateTime ().toTime_t () - ui->fromDateTimeEdit->dateTime ().toTime_t ())/plotPixNumber;

        ui->deltaLineEdit->setText (QString::number (delta));

    }

}

void MainWindow::on_radioMonth_toggled(bool checked)
{
int plotPixNumber= ui->customPlot->geometry().width();
    if(checked){
        QDate today=QDate::currentDate ();
        today=QDate(today.year (),today.month (),1);

        QTime  start(0,0,0);
        QDateTime startMonth(today,start);

        ui->fromDateTimeEdit->setDateTime (startMonth);
        ui->toDateTimeEdit->setDateTime (QDateTime::currentDateTime ());

        int delta=(ui->toDateTimeEdit->dateTime ().toTime_t () - ui->fromDateTimeEdit->dateTime ().toTime_t ())/plotPixNumber;

        ui->deltaLineEdit->setText (QString::number (delta));
    }

}

void MainWindow::on_radioYear_toggled(bool checked)
{
    int plotPixNumber= ui->customPlot->geometry().width();
    if(checked){
        QDate today=QDate::currentDate ();
        today=QDate(today.year (),1,1);

        QTime  start(0,0,0);
        QDateTime startYear(today,start);

        ui->fromDateTimeEdit->setDateTime (startYear);
        ui->toDateTimeEdit->setDateTime (QDateTime::currentDateTime ());

        int delta=(ui->toDateTimeEdit->dateTime ().toTime_t () - ui->fromDateTimeEdit->dateTime ().toTime_t ())/plotPixNumber;

        ui->deltaLineEdit->setText (QString::number (delta));

    }
}

void MainWindow::progressBar(int progress)
{
    if(progress==0){
       pb->setValue (0);
       pb->setRange (0,0);
       pb->setVisible (true);

    }
    else if(progress==100){
        pb->setValue (progress);
        pb->setRange (0,100);
        pb->setVisible (false);
    }
    else{
        pb->setValue (progress);
        pb->setRange (0,100);
        pb->setVisible (true);
    }
    QCoreApplication::processEvents();
}
void MainWindow::on_zoomInButton_toggled(bool checked)
{
    if(checked){
        ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal);

        ui->customPlot->axisRect()->setRangeZoomAxes(ui->customPlot->xAxis, ui->customPlot->yAxis);

        ui->customPlot->setSelectionRectMode(QCP::srmZoom);

        QCPSelectionRect *rect=new QCPSelectionRect(ui->customPlot);

        QColor rectColor = palette().light().color();
        rectColor.setAlpha(125);
        rect->setBrush(rectColor);

        QPen rectPen(Qt::blue, 2, Qt::DashDotLine, Qt::RoundCap);

        rect->setPen(rectPen);

        ui->customPlot->setSelectionRect(rect);
    }
    else{
        ui->customPlot->setSelectionRectMode(QCP::srmNone);
    }
}

void MainWindow::on_resetZoomButton_clicked()
{
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
    ui->customPlot->setSelectionRectMode(QCP::srmNone);
}

void MainWindow::on_alphapadButton_clicked()
{
#ifdef Q_WS_QWS

  char value[100] = "set Ip";
    alphanumpad * dk;

    dk = new alphanumpad(value, value);
    dk->showFullScreen();

    if (dk->exec() == QDialog::Accepted && strlen(value) != 0)
    {
        ui->ipLineEdit->clear ();
        ui->ipLineEdit->setText (value);
    }
#endif
}

void MainWindow::on_numpadButton_clicked()
{
#ifdef Q_WS_QWS

    float value, min = 1, max = 0;
    numpad * dk;
    dk = new numpad(&value, 200, 3, min, max);
    dk->showFullScreen();

    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (value < min || value > max))
        {
            QMessageBox::critical(this,trUtf8("Invalid data"), trUtf8("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(value).arg(min).arg(max));
        }
        else
        {
            ui->deltaLineEdit->clear ();
            ui->deltaLineEdit->setText (QString::number((int) value));
        }
    }
#endif
}

void MainWindow::on_fromDateTimeEdit_editingFinished()
{
#ifdef Q_WS_QWS

   /* TimePopup *timepop=new TimePopup(this->ui->fromDateTimeEdit);
    timepop->setTime (ui->fromDateTimeEdit->time());

   if(timepop->exec() == QDialog::Accepted)
     {
        ui->fromDateTimeEdit->setTime(timepop->getTime());
     }

   if(timepop!=NULL)
     {
       delete (timepop);
     }*/


#endif
}
