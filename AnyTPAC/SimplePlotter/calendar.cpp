#include "calendar.h"
#include <QtGui>

#define SIZE_X 230
#define SIZE_Y 225

#define ROW_YEARS 3
#define COL_YEARS 4
#define SIZE_CELL_YEARS_X 56
#define SIZE_CELL_YEARS_Y 60

#define ROW_MONTH 3
#define COL_MONTH 4
#define SIZE_CELL_MONTH_X 56
#define SIZE_CELL_MONTH_Y 60

#define ROW_DAY 7
#define COL_DAY 7
#define SIZE_CELL_DAYNAME_X 14
#define SIZE_CELL_DAY_X 32
#define SIZE_CELL_DAY_Y 28


Calendar::Calendar(QWidget *parent) :
 QDialog(parent, Qt::Popup)
{
    move(mapFromParent(parent->pos()));
    int tmpPosX=parent->pos().x();
    int tmpPosY=parent->pos().y();
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    if(parent->pos().x()+SIZE_X>width)
      {
        tmpPosX=width-SIZE_X;
         move(tmpPosX,tmpPosY);

      }
    if(parent->pos().y()+SIZE_Y>height)
      {
        tmpPosY=height-SIZE_Y;
        move(tmpPosX,tmpPosY);
      }

    setSizeGripEnabled(false);
    resize(SIZE_X,SIZE_Y);
    widget = new QWidget(this);
    widget->setObjectName(QString::fromUtf8("widgetDialog"));
    widget->setGeometry(QRect(0,0, SIZE_X, SIZE_Y));
    widget->setWindowFlags(Qt::FramelessWindowHint);
    QPalette pal = palette();
    // set black background
    pal.setColor(QPalette::Background, Qt::lightGray);
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);


    verticalLayout = new QVBoxLayout(widget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    pushYearAndMonth =new QPushButton(widget);
    pushYearAndMonth->setObjectName(QString::fromUtf8("pushYearAndMonth"));
    pushYearAndMonth->setContentsMargins(0, 0, 0, 0);
    pushYearAndMonth->setFixedWidth(100);
    connect(pushYearAndMonth,SIGNAL(clicked()),this,SLOT(on_clicked_pushYearAndMonth()));

    arrowDOWN =new QPushButton(widget);
    arrowDOWN->setObjectName(QString::fromUtf8("arrowDOWN"));
    arrowDOWN->setContentsMargins(0, 0, 0, 0);
    arrowDOWN->setText("down");
    arrowDOWN->setFixedWidth(50);
    connect(arrowDOWN,SIGNAL(clicked()),this,SLOT(on_clicked_arrowDOWN()));


    arrowUP =new QPushButton(widget);
    arrowUP->setObjectName(QString::fromUtf8("arrowUP"));
    arrowUP->setContentsMargins(0, 0, 0, 0);
    arrowUP->setText("Up");
    arrowUP->setFixedWidth(50);
    connect(arrowUP,SIGNAL(clicked()),this,SLOT(on_clicked_arrowUP()));

    horizontalLayout->addWidget (pushYearAndMonth,0,Qt::AlignLeft);
    horizontalLayout->addWidget (arrowUP,0,Qt::AlignRight);
    horizontalLayout->addWidget (arrowDOWN,0,Qt::AlignRight);

    separatorLine = new QFrame(widget);
    separatorLine->setFrameShape(QFrame::HLine); // Horizontal line
    separatorLine->setFrameShadow(QFrame::Sunken);
    separatorLine->setLineWidth(1);

    tableWidgetYear = new QTableWidget(widget);
    tableWidgetYear->setObjectName(QString::fromUtf8("TableWidgetYear"));
    tableWidgetYear->setContentsMargins(0, 0, 0, 0);

    tableWidgetMonth= new QTableWidget(widget);
    tableWidgetMonth->setObjectName(QString::fromUtf8("TableWidgetMonth"));
    tableWidgetMonth->setContentsMargins(0, 0, 0, 0);



    tableWidgetDay= new QTableWidget(widget);
    tableWidgetDay->setObjectName(QString::fromUtf8("TableWidgetDay"));
    tableWidgetDay->setContentsMargins(0, 0, 0, 0);

    verticalLayout->addLayout (horizontalLayout);
    verticalLayout->addWidget (separatorLine);
    verticalLayout->addWidget (tableWidgetYear);
    verticalLayout->addWidget (tableWidgetMonth);
    verticalLayout->addWidget (tableWidgetDay);

    selectedYear=0;
    selectedMonth=0;
    selectedYear=0;

    setTableYears();
    setTableMonth();
    setTableDay ();

    tableWidgetYear->setVisible (false);
    tableWidgetMonth->setVisible (false);
    tableWidgetDay->setVisible (true);
}

void Calendar::setYear(){

    QPushButton *pB= (QPushButton*)(sender());
    selectedYear=pB->text ().toInt ();
    pushYearAndMonth->setText(pB->text ());
}

void Calendar::setMonth(){

    QPushButton *pB= (QPushButton*)(sender());
    selectedMonth=QDate::fromString( pB->text (),"MMM").month();
    setDayName(selectedYear,selectedMonth);
    tableWidgetYear->setVisible (false);
    tableWidgetMonth->setVisible (true);
    pushYearAndMonth->setText (QDate::longMonthName (selectedMonth)+" "+QString::number (selectedYear));

}

void Calendar::setDay(){

    QPushButton *pB= (QPushButton*)(sender());
    selectedDay=pB->text ().toInt ();
    accept();
}

QDate Calendar::getDate(){

    return QDate(selectedYear, selectedMonth, selectedDay);
}

void Calendar::setDate(QDate currentDate){
    selectedYear=currentDate.year();
    selectedMonth=currentDate.month();
    selectedDay=currentDate.day();

    pushYearAndMonth->setText (QDate::longMonthName (selectedMonth)+" "+QString::number (selectedYear));
    setDayName(selectedYear,selectedMonth);
}

void Calendar::on_clicked_arrowUP(){
    if(tableWidgetDay->isVisible()){
         selectedMonth++;
         if(selectedMonth==13){
             selectedMonth=1;
             selectedYear++;
         }
         setDayName(selectedYear,selectedMonth);
         pushYearAndMonth->setText (QDate::longMonthName (selectedMonth)+" "+QString::number (selectedYear));
    }
    else if(tableWidgetMonth->isVisible()){
         selectedYear++;
         setMonthName();
         pushYearAndMonth->setText (QString::number (selectedYear));
    }
    else if( tableWidgetYear->isVisible()){
       selectedYear= selectedYear+12;
       setYearName();
       pushYearAndMonth->setText (QString::number (selectedYear-11)+" - "+QString::number (selectedYear));
    }

}

void Calendar::on_clicked_arrowDOWN(){
    if(tableWidgetDay->isVisible()){
         selectedMonth--;
         if(selectedMonth==0){
             selectedMonth=12;
             selectedYear--;
         }
         setDayName(selectedYear,selectedMonth);
         pushYearAndMonth->setText (QDate::longMonthName (selectedMonth)+" "+QString::number (selectedYear));
    }
    else if(tableWidgetMonth->isVisible()){
         selectedYear--;
         setMonthName();
         pushYearAndMonth->setText (QString::number (selectedYear));
    }
    else if( tableWidgetYear->isVisible()){
       selectedYear= selectedYear-12;
       setYearName();
       pushYearAndMonth->setText (QString::number (selectedYear-11)+" - "+QString::number (selectedYear));
    }
}

void Calendar::setTableYears(){

    tableWidgetYear->setRowCount(ROW_YEARS);

    tableWidgetYear->setColumnCount(COL_YEARS);

    tableWidgetYear->verticalHeader()->setVisible(false);

    tableWidgetYear->horizontalHeader()->setVisible(false);

    tableWidgetYear->setSelectionMode( QAbstractItemView::SingleSelection );

    tableWidgetYear->setShowGrid(false);

    for(int i=0;i<ROW_YEARS;i++)
    {
        tableWidgetYear->setRowHeight(i,SIZE_CELL_YEARS_Y);

    }
    for(int i=0;i<COL_YEARS;i++)
    {
        tableWidgetYear->setColumnWidth(i,SIZE_CELL_YEARS_X);
    }

    for(int i=0;i<ROW_YEARS;i++)
    {
         for(int j=0;j<COL_YEARS;j++){
             QPushButton *cellButton=new QPushButton(tableWidgetYear);
             cellButton->setObjectName(QString::fromUtf8("YearButton(%1,%2)").arg (i).arg (j));
             tableWidgetYear->setCellWidget (i,j,cellButton);
             connect(cellButton,SIGNAL(clicked()),this,SLOT(setYear()));
         }
    }
    tableWidgetYear->setVisible (true);
   setYearName();
}


void Calendar::setYearName(){
    int currentYear;

    if(selectedYear==0){
        currentYear= (QDate::currentDate ().year())-(ROW_YEARS*COL_YEARS)+1;
    }
    else{
        currentYear=selectedYear-(ROW_YEARS*COL_YEARS)+1;
    }
    for(int i=0;i<ROW_YEARS;i++)
    {
         for(int j=0;j<COL_YEARS;j++){

            QPushButton *pB;
            pB=(QPushButton*) tableWidgetYear->cellWidget (i,j);
            pB->setText (QString::number (currentYear++));
            pB->setStyleSheet("Text-align:center");
            connect(pB,SIGNAL(clicked()),this,SLOT(showMonthTable()));
         }
    }
}

void Calendar::setTableMonth(){

    tableWidgetMonth->setVisible (false);

    tableWidgetMonth->setRowCount(ROW_MONTH);

    tableWidgetMonth->setColumnCount(COL_MONTH);

    tableWidgetMonth->verticalHeader()->setVisible(false);

    tableWidgetMonth->horizontalHeader()->setVisible(false);

    tableWidgetMonth->setSelectionMode( QAbstractItemView::SingleSelection );

    tableWidgetMonth->setShowGrid(false);

    for(int i=0;i<ROW_MONTH;i++)
    {
        tableWidgetMonth->setRowHeight(i,SIZE_CELL_MONTH_Y);

    }
    for(int i=0;i<COL_MONTH;i++)
    {
        tableWidgetMonth->setColumnWidth(i,SIZE_CELL_MONTH_X);
    }

    for(int i=0;i<ROW_MONTH;i++)
    {
         for(int j=0;j<COL_MONTH;j++){
             QPushButton *cellButton=new QPushButton(tableWidgetMonth);
             cellButton->setObjectName(QString::fromUtf8("MonthButton(%1,%2)").arg (i).arg (j));
             tableWidgetMonth->setCellWidget (i,j,cellButton);
             connect(cellButton,SIGNAL(clicked()),this,SLOT(setMonth()));
         }
    }
    setMonthName();
}


void Calendar::setMonthName(){
int listMonthNumber=1;

    for(int i=0;i<ROW_MONTH;i++)
    {
         for(int j=0;j<COL_MONTH;j++){

            QPushButton *pB;
            pB=(QPushButton*) tableWidgetMonth->cellWidget (i,j);
            pB->setText (QDate::shortMonthName (listMonthNumber++));
            pB->setStyleSheet("Text-align:center");
            connect(pB,SIGNAL(clicked()),this,SLOT(showDayTable()));
         }
    }
}

void Calendar::showMonthTable(){

    tableWidgetYear->setVisible (false);
    tableWidgetMonth->setVisible (true);
}
void Calendar::showDayTable(){
    tableWidgetMonth->setVisible (false);
    tableWidgetDay->setVisible (true);
}

void Calendar::setTableDay(){

    tableWidgetDay->setRowCount(ROW_DAY);

    tableWidgetDay->setColumnCount(COL_DAY);

    tableWidgetDay->verticalHeader()->setVisible(false);

    tableWidgetDay->horizontalHeader()->setVisible(false);

    tableWidgetDay->setSelectionMode( QAbstractItemView::SingleSelection );

    tableWidgetDay->setShowGrid(false);

    for(int i=0;i<ROW_DAY;i++)
    {
        if(i==0){
            tableWidgetDay->setRowHeight(i,SIZE_CELL_DAYNAME_X);
        }else {
            tableWidgetDay->setRowHeight(i,SIZE_CELL_DAY_Y);
        }
    }
    for(int i=0;i<COL_DAY;i++)
    {
        tableWidgetDay->setColumnWidth(i,SIZE_CELL_DAY_X);
    }

    int counter=0;
    for(int i=0;i<ROW_DAY;i++)
    {
        for(int j=0;j<COL_DAY;j++){
            if(counter>6){

                QPushButton *cellButton=new QPushButton(tableWidgetDay);
                cellButton->setObjectName(QString::fromUtf8("DayButton(%1,%2)").arg (i).arg (j));
                // cellButton->setFlat(true);
                tableWidgetDay->setCellWidget (i,j,cellButton);
                connect(cellButton,SIGNAL(clicked()),this,SLOT(setDay()));

            }else{
                counter++;
            }
        }
    }
}

void Calendar::setDayName(int year,int month){
    int listDayNumber=1;
    QDate date;

    for(int i=0;i<ROW_DAY;i++)
    {
        for(int j=0;j<COL_DAY;j++){

            if(i==0){
                //Days Names
                QTableWidgetItem *item=new QTableWidgetItem(QDate::shortDayName (j+1));
                item->setTextAlignment (Qt::AlignHCenter);
                if(j==6){
                    item->setTextColor(QColor(Qt::red));
                }
                tableWidgetDay->setItem(i,j,item);
            }
            else{

                date.setDate (year,month,listDayNumber);

                if( date.isValid ()){

                    if(listDayNumber==1){
                        for(int k=0;k<date.dayOfWeek ();k++){
                            QPushButton *pB;
                            pB=(QPushButton*) tableWidgetDay->cellWidget (i,k);
                            pB->setEnabled (false);
                            pB->setText(" ");
                        }
                    }
                    QPushButton *pB;
                    pB=(QPushButton*) tableWidgetDay->cellWidget (i,date.dayOfWeek ()-1);
                    pB->setStyleSheet("Text-align:center");
                    pB->setVisible (true);
                    pB->setEnabled (true);
                    pB->setText (QString::number (listDayNumber));
                    if(QDate::currentDate().day()==listDayNumber){
                        tableWidgetDay->setCurrentCell(i,j);
                    }

                    listDayNumber++;
                    if(date.dayOfWeek ()==7)
                        break;

                }else{
                    QPushButton *pB;
                    pB=(QPushButton*) tableWidgetDay->cellWidget (i,j);
                    pB->setEnabled (false);
                    pB->setText(" ");
                }

            }
        }
    }
}


void Calendar::on_clicked_pushYearAndMonth(){
    if(tableWidgetDay->isVisible ()){

        tableWidgetDay->setVisible (false);
        tableWidgetMonth->setVisible (true);
        pushYearAndMonth->setText (QString::number (selectedYear));

    }
    else if(tableWidgetMonth->isVisible ()){

        tableWidgetMonth->setVisible (false);
        tableWidgetYear->setVisible (true);
        pushYearAndMonth->setText (QString::number (selectedYear-11)+" - "+QString::number (selectedYear));
    }
}













