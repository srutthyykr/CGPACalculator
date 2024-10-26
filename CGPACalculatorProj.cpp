#include<iostream>
#include<fstream>
using namespace std;

float cgpacalci(int n,int credits[],int grades[])
{
int totacredits=0;
int gradepoint=0;

for(int i=0;i<n;i++)
{
totacredits=credits[i]+totacredits;
}

for(int i=0;i<n;i++)
{
gradepoint=gradepoint+(grades[i]*credits[i]);
}

float total=gradepoint/totacredits;

return total;
}
int main()
{
int n;
int credits[n];
int grades[n];
cout<<"enter number of subjects";
cin>>n;

for(int i=0;i<n;i++)
{
cout<<"enter credits";
cin>>credits[i];
}
for(int i=0;i<n;i++)
{
cout<<"enter gardes";
cin>>grades[i];
}

float cgpa=cgpacalci(n,credits,grades);

cout<<cgpa;

ofstream outputfile("cgpa.txt");

if(outputfile.is_open())
{
for(int i=0;i<n;i++)
{
outputfile<<"course"<<i+1<<" :"<<"credits"<<credits[i]<<" ,"<<"grades"<<grades[i]<<endl;
}

outputfile<<"total cgpa"<<" "<<cgpa;

outputfile.close();
}
else
{
cerr<<"error opening the file";
}




return 0;
}