#include<iostream>
#include <algorithm> 
#include <queue>
#include<iomanip>
#include<climits>
#include<conio.h>


using namespace std;
struct process
{
  int pid;  
  int at;       //Arrival Time
  int bt;       //CPU Burst time 
  int ct,wt,tat,rt,start_time;   // Completion, waiting, turnaround, response time
  int ct1,wt1,tat1,rt1,start_time1;
  int ct2,wt2,tat2,rt2,start_time2;
  int ct3,wt3,tat3,rt3,start_time3;




}
ps[100];       //Array of structure to store the info of each process.   

bool compare1(process p1, process p2) 
{ 
    return p1.at < p2.at;
}

bool compare2(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}



int main()
{
    int n,index;
    bool is_completed[100]={false},is_first_process=true;
    bool is_completed1[100]={false},is_first_process1=true;
    bool visited[100]={false};
    bool visited1[100]={false};
    int current_time = 0;
    int current_time1 = 0;
     int current_time2 = 0;
    int completed = 0 , 
	completed1=0 , completed2=0;
	   float att2;
	   float awt2;
    float sum_tat=0,sum_wt=0,sum_rt=0,sum_tat1=0,sum_wt1=0,sum_rt1=0,sum_tat2=0,sum_wt2=0,sum_rt2=0,total_idle_time=0,
	total_idle_time1=0,total_idle_time2=0,length_cycle,length_cycle1,length_cycle2,prev=0,prev2=0;
    float cpu_utilization;
    int max_completion_time,min_arrival_time,max_completion_time1,min_arrival_time1,max_completion_time2,min_arrival_time2;
    float Avg_turn_arround1;
    float Avg_waiting_time1;
    float Avg_response_time1;
    float Avg_turn_arround2;
    float Avg_waiting_time2;
    float Avg_response_time2;
     float Avg_turn_arround3;
    float Avg_waiting_time3;
    float Avg_response_time3;
    float   Avg_turnaround_time4;
     float Avg_waiting_time4;
        float Avg_response_time4;


    int total_turnaround_time;
    int  total_waiting_time;
    int total_response_time;
    int bt_remaining[100];
 
int ct4[50]={0}, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[50]={0}, tt4, wt4;
float att, awt;
 
 
    int tq=0;
    
     int smallest,count=0,time;
     double avg=0,tt=0,end;
        int x[10];
    	system("cls");


	printf("\n\n\n\n\n\n\n\n\n**************************************************************");
	printf("\n\t\t------Find Efficient Algorithm For Processes---");
	printf("\n\t\t****************************************************************");
	int Sleep(2000);
getch();
    system("cls");
	
    cout<<"Enter total number of processes: ";
    cin>>n;

    cout << setprecision(2) << fixed;
    
   
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process" <<" "<<i<<" "<<"Arrival Time: ";
        cin >> ps[i].at;
        ps[i].pid=i;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process" <<" "<<i<<" "<<"Burst Time: ";
        cin >> ps[i].bt;
    }
    
 cout<<"\nEnter time quantum:";
    cin>>tq;
    system("CLS");
    ///////////////////////////////////FCFS///////////////////////////////////////////////
     sort(ps,ps+n, compare1);

    //calculation
    for(int i=0;i<n;i++)
    {
      ps[i].start_time = (i==0) ? ps[i].at : max(ps[i].at, ps[i-1].ct);  
      ps[i].ct =  ps[i].start_time + ps[i].bt;
      ps[i].tat = ps[i].ct-ps[i].at;       
      ps[i].wt = ps[i].tat-ps[i].bt;
      ps[i].rt=ps[i].wt;
      
        
        
      sum_tat += ps[i].tat;
      sum_wt += ps[i].wt;
      sum_rt += ps[i].rt;
      
      total_idle_time += (i==0) ? 0 : (ps[i].start_time -  ps[i-1].ct);
    }
    length_cycle = ps[n-1].ct - ps[0].start_time;
    //sort so that process ID in output comes in Original order (just for interactivity)
    sort(ps,ps+n, compare2);
    
    //Output
//    cout<<"\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n";
//    for(int i=0;i<n;i++)
//     cout<<i<<"\t\t"<<ps[i].at<<"\t"<<ps[i].bt<<"\t\t"<<ps[i].ct<<"\t"<<ps[i].tat<<"\t"<<ps[i].wt<<"\t"<<ps[i].rt<<endl;
//    cout<<endl;
    
    
    Avg_turn_arround1= sum_tat/n;
    Avg_waiting_time1=sum_wt/n;
    Avg_response_time1=sum_rt/n;  
    cout<<"\nFCFS AVERAGE TURN ARROUND TIME = "<<Avg_turn_arround1<<endl;
       

   
   
   ///////////////////////////////////////sjf///////////////////////////////////////
    
    while(completed1!=n)
    {
        //find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(ps[i].at <= current_time1 && is_completed[i] == false) {
                if(ps[i].bt < minimum) {
                    minimum = ps[i].bt;
                    min_index = i;
                }
                if(ps[i].bt== minimum) {
                    if(ps[i].at < ps[min_index].at) {
                        minimum= ps[i].bt;
                        min_index = i;
                    }
                }
            }
        }

        if(min_index==-1)
        {
            current_time1++;
        }
        else
        {
        ps[min_index].start_time1 = current_time1;
        ps[min_index].ct1 = ps[min_index].start_time1 + ps[min_index].bt;
        ps[min_index].tat1 = ps[min_index].ct1 - ps[min_index].at;
        ps[min_index].wt1 = ps[min_index].tat1 - ps[min_index].bt;
        ps[min_index].rt1 = ps[min_index].wt1;
        // ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;
                
        sum_tat1 +=ps[min_index].tat1;
        sum_wt1 += ps[min_index].wt1;
        sum_rt1 += ps[min_index].rt1;
        total_idle_time += (is_first_process==true) ? 0 : (ps[min_index].start_time1 -  prev);
        
        completed1++;
        is_completed[min_index]=true;
        current_time1 = ps[min_index].ct1;
        prev= current_time1;
        is_first_process = false;  
        }
    }
    
    //Calculate Length of Process completion cycle
    max_completion_time1 = INT_MIN;
    min_arrival_time1 = INT_MAX;
    for(int i=0;i<n;i++)
    {
        max_completion_time1 = max(max_completion_time1,ps[i].ct1);
        min_arrival_time1 = min(min_arrival_time1,ps[i].at);
    }
    length_cycle = max_completion_time1 - min_arrival_time1;

     //Output
//    cout<<"\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n";
//    for(int i=0;i<n;i++)
//     cout<<i<<"\t\t"<<ps[i].at<<"\t"<<ps[i].bt<<"\t\t"<<ps[i].ct1<<"\t"<<ps[i].tat1<<"\t"<<ps[i].wt1<<"\t"<<ps[i].rt1<<endl;
//    cout<<endl;  
    
    cpu_utilization = (float)(length_cycle1 - total_idle_time1)/ length_cycle1;
    Avg_turn_arround2= sum_tat1/n;
    Avg_waiting_time2=sum_wt1/n;
    Avg_response_time2=sum_rt1/n; 
    cout<<"\nSJF AVERAGE TURN ARROUND TIME = "<< (float)sum_tat1/n<<endl;
//    cout<<"\nAverage Waiting Time1= "<<(float)sum_wt1/n<<endl;
//    cout<<"\nAverage Response Time1= "<<(float)sum_rt1/n;    
	  
	  
	  ////////////////////////////////////////////srtf////////////////////////////////////////
	  
	    for(int i=0; i<n; i++)
        x[i]=ps[i].bt;

    ps[9].bt=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(int i=0; i<n; i++)
        {
            if(ps[i].at<=time && ps[i].bt<ps[smallest].bt && ps[i].bt>0 )
                smallest=i;
        }
        ps[smallest].bt--;

        if(ps[smallest].bt==0)
        {
            count++;
            end=time+1;
            ps[smallest].ct2 = end;
            ps[smallest].wt2 = end - ps[smallest].at - x[smallest];
            ps[smallest].tat2 = end - ps[smallest].at;
        }
    }
//    cout<<"Process"<<"\t"<< "Arrival-time"<<"\t"<<"Burst-time" <<"\t"<<"completion-time" <<"\t"<<"turnaround-time"<< "\t"<<"waiting-time"<<endl;
    for(int i=0; i<n; i++)
    {
//        cout<<"p"<<i+1<<"\t\t"<<ps[i].at<<"\t\t"<<x[i]<<"\t\t"<<ps[i].ct2<<"\t\t"<<ps[i].tat2<<"\t\t"<<ps[i].wt2<<endl;
        avg = avg + ps[i].wt2;
        tt = tt + ps[i].tat2;
    }
    Avg_turn_arround3=tt/n;
//    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"\nSRTF AVERAGE TURN AROUND TIME ="<<Avg_turn_arround3<<endl;

////////////////////////////////////////////////round robin////////////////////////////////////////////
if(tq>0)
{

 for(int i=0; i<n; i++)
        btm[i]=x[i];
do{
if(flg==0){
st=ps[0].at;
//---ReduceBT
if(btm[0]<=tq){
tm=st+btm[0];
btm[0]=0;
for(int x=pnt+1;x<n;x++){
if(ps[x].at<=tm){
rqi[noe]=x+1;
noe++;}
}
}
else{
btm[0]=btm[0]-tq;
tm=st+tq;
for(int x=pnt+1;x<n;x++){
if(ps[x].at<=tm){
rqi[noe]=x+1;
noe++;}
}
rqi[noe]=pnt+1;
noe++;
}
}//if
else{
pnt=rqi[0]-1;
st=tm;
//---DeleteQue
for(int x=0;x<noe && noe!=1;x++){
rqi[x]=rqi[x+1];}
noe--;
//---ReduceBT
if(btm[pnt]<=tq){
tm=st+btm[pnt];
btm[pnt]=0;
for(int x=pnt+1;x<n;x++){
//---CheckQue
int fl=0;
for(int y=0;y<noe;y++){
if(rqi[y]==x+1){
fl++;}}
if(ps[x].at<=tm && fl==0 && ps[x].bt!=0){
rqi[noe]=x+1;
noe++;}
}
}
else{
btm[pnt]=btm[pnt]-tq;
tm=st+tq;
for(int x=pnt+1;x<n;x++){
//---CheckQue
int fl=0;
for(int y=0;y<noe;y++){
if(rqi[y]==x+1){
	
fl++;}}
if(ps[x].at<=tm && fl==0 && btm[x]!=0){
rqi[noe]=x+1;
noe++;}
}
rqi[noe]=pnt+1;
noe++;
}
}//else
//AssignCTvalue
if(btm[pnt]==0){
ct4[pnt]=tm;
}//if
flg++;
//cout<<"]-P"<<pnt+1<<"-["<<tm;
}while(noe!=0);
//cout<<"\n\nPROCESS\t AT\t BT\t CT\t TT\t WT\n";
for(int i=0;i<n;i++){
tt4=ct4[i]-ps[i].at;
wt4=tt4-x[i];
//cout<<"P"<<i+1<<" \t "<<ps[i].at<<" \t "<<x[i]<<" \t "<<ct4[i]<<" \t "<<tt4<<" \t "<<wt4<<"\n";
awt=awt+wt4;
att=att+tt4;
}//for
cout<<"\nROUND ROBIN AVERAGE TURN AROUND TIME ="<<att/n<<endl;
//cout<<"\nAverage waiting time ="<<awt/5;
att2=att/n;
 awt2=awt/n;



        if(Avg_turn_arround1<= Avg_turn_arround2 && Avg_turn_arround1<= Avg_turn_arround3 && Avg_turn_arround1<=att2)
    {
    	cout<<"\n//////////////////////////////////////FCFS is fastest/////////////////////////////////////////////"<<endl;
   int i;
 
    puts("\n+------+--------------+------------+-----------------+---------------+---------------+----------------+");
    puts("| PID  | Arrival Time | Burst Time | Completion Time |Turnaround Time | Waiting Time  | Response Time |");
    puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
 
    for(i=0; i<n; i++) {
        printf("|  %2d  |     %2d       |      %2d    |       %2d        |      %2d        |   %2d          |   %2d          |\n"
               , ps[i].pid, ps[i].at,x[i], ps[i].ct, ps[i].tat, ps[i].wt , ps[i].rt);
        puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
    }
        cout<<"\n FCFS Average Turn Around time = "<< Avg_turn_arround1<<endl;
         cout<<"\n FCFSAverage waiting time = "<< Avg_waiting_time1<<endl;
    cout<<"\n FCFSAverage response time = "<< Avg_response_time1<<endl;

	}
        if(Avg_turn_arround2<= Avg_turn_arround1 && Avg_turn_arround2<= Avg_turn_arround3 && Avg_turn_arround2<=att2)
{
		cout<<"\n//////////////////////////////////////SJF is fastest/////////////////////////////////////////////"<<endl;
		    
     
    int i;
 
    puts("\n+------+--------------+------------+-----------------+---------------+---------------+----------------+");
    puts("| PID  | Arrival Time | Burst Time | Completion Time |Turnaround Time | Waiting Time  | Response Time |");
    puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
 
    for(i=0; i<n; i++) {
        printf("|  %2d  |     %2d       |     %2d     |     %2d          |      %2d        |   %2d          |   %2d          |\n"
               , ps[i].pid, ps[i].at, x[i], ps[i].ct1, ps[i].tat1, ps[i].wt1 , ps[i].rt1);
        puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
    }
cout<<"\n SJF Average Turn Around time = "<< Avg_turn_arround2<<endl;
       cout<<"\n SJF Average waiting time = "<<Avg_waiting_time2<<endl;
    cout<<"\n SJF Average response time = "<< Avg_response_time2<<endl;
	}
        if(Avg_turn_arround3<= Avg_turn_arround1 && Avg_turn_arround3<= Avg_turn_arround2 && Avg_turn_arround3<=att2)
{
		cout<<"\n//////////////////////////////////////SRTF is fastest/////////////////////////////////////////////"<<endl;
		    
     
    int i;
 
    puts("\n+------+--------------+------------+-----------------+---------------+----------------+");
    puts("| PID  | Arrival Time | Burst Time | Completion Time |Turnaround Time | Waiting Time  |");
    puts("+------+--------------+------------+-----------------+----------------+---------------+");
 
    for(i=0; i<n; i++) {
        printf("|  %2d  |     %2d       |     %2d     |     %2d          |      %2d        |   %2d          |\n"
               , ps[i].pid, ps[i].at, x[i], ps[i].ct2, ps[i].tat2, ps[i].wt2 );
        puts("+------+--------------+------------+-----------------+----------------+---------------+");
    }
cout<<"\n SRTF Average Turn Around time = "<< Avg_turn_arround3<<endl;
       cout<<"\n SRTF Average waiting time = "<<avg/n<<endl;
	}
	
	      if(att2 <= Avg_turn_arround1 && att2 <= Avg_turn_arround2 && att2 <=Avg_turn_arround3)
{
		cout<<"\n//////////////////////////////////////ROUND ROBIN is fastest/////////////////////////////////////////////"<<endl;
		    
     
    int i;
 
    puts("\n+------+--------------+------------+-----------------+---------------+----------------+");
    puts("| PID  | Arrival Time | Burst Time | Completion Time |Turnaround Time | Waiting Time  |");
    puts("+------+--------------+------------+-----------------+----------------+---------------+");
 
    for(i=0; i<n; i++) {
    	tt4=ct4[i]-ps[i].at;
wt4=tt4-x[i];
        printf("|  %2d  |     %2d       |     %2d     |     %2d          |      %2d        |   %2d          |\n"
               , i+1, ps[i].at, x[i], ct4[i], tt4, wt4 );
        puts("+------+--------------+------------+-----------------+----------------+---------------+");
    }
cout<<"\nRound Robin Average Turn Around time = "<< att2<<endl;
       cout<<"\nRound Robin Average waiting time = "<<awt2<<endl;
	}
}
else{
	
    if(Avg_turn_arround1 <= Avg_turn_arround2 && Avg_turn_arround1<=Avg_turn_arround3)
    {
    	cout<<"\n//////////////////////////////////////FCFS is fastest/////////////////////////////////////////////"<<endl;
   int i;
 
    puts("\n+------+--------------+------------+-----------------+---------------+---------------+----------------+");
    puts("| PID  | Arrival Time | Burst Time | Completion Time |Turnaround Time | Waiting Time  | Response Time |");
    puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
 
    for(i=0; i<n; i++) {
        printf("|  %2d  |     %2d       |      %2d    |       %2d        |      %2d        |   %2d          |   %2d          |\n"
               , ps[i].pid, ps[i].at,x[i], ps[i].ct, ps[i].tat, ps[i].wt , ps[i].rt);
        puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
    }
        cout<<"\nAverage Turn Around time = "<< Avg_turn_arround1<<endl;
         cout<<"Average waiting time = "<< Avg_waiting_time1<<endl;
    cout<<"Average response time = "<< Avg_response_time1<<endl;

	}
    if(Avg_turn_arround2 <= Avg_turn_arround1 && Avg_turn_arround2<=Avg_turn_arround3)
{
		cout<<"\n//////////////////////////////////////SJF is fastest/////////////////////////////////////////////"<<endl;
		    
     
    int i;
 
    puts("\n+------+--------------+------------+-----------------+---------------+---------------+----------------+");
    puts("| PID  | Arrival Time | Burst Time | Completion Time |Turnaround Time | Waiting Time  | Response Time |");
    puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
 
    for(i=0; i<n; i++) {
        printf("|  %2d  |     %2d       |     %2d     |     %2d          |      %2d        |   %2d          |   %2d          |\n"
               , ps[i].pid, ps[i].at, x[i], ps[i].ct1, ps[i].tat1, ps[i].wt1 , ps[i].rt1);
        puts("+------+--------------+------------+-----------------+----------------+---------------+---------------+");
    }
cout<<"\nAverage Turn Around time = "<< Avg_turn_arround2<<endl;
       cout<<"\nAverage waiting time = "<<Avg_waiting_time2<<endl;
    cout<<"\nAverage response time = "<< Avg_response_time2<<endl;
	}
        if(Avg_turn_arround3 <= Avg_turn_arround1 && Avg_turn_arround3 <= Avg_turn_arround3)
{
		cout<<"\n//////////////////////////////////////SRTF is fastest/////////////////////////////////////////////"<<endl;
		    
     
    int i;
 
    puts("\n+------+--------------+------------+-----------------+---------------+----------------+");
    puts("| PID  | Arrival Time | Burst Time | Completion Time |Turnaround Time | Waiting Time  |");
    puts("+------+--------------+------------+-----------------+----------------+---------------+");
 
    for(i=0; i<n; i++) {
        printf("|  %2d  |     %2d       |     %2d     |     %2d          |      %2d        |   %2d          |\n"
               , ps[i].pid, ps[i].at, x[i], ps[i].ct2, ps[i].tat2, ps[i].wt2 );
        puts("+------+--------------+------------+-----------------+----------------+---------------+");
    }
cout<<"\nAverage Turn Around time = "<< Avg_turn_arround3<<endl;
       cout<<"\nAverage waiting time = "<<avg/n<<endl;
	}
}
    return 0;
}

