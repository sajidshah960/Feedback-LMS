#include <iostream>
#include <cctype>
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <string>
using namespace::std;
void display()
      {
            for (int i=0;i<30;i++){cout<<" ";}
      cout<<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|"<<endl;
      for (int i=0;i<30;i++){cout<<" ";}
      cout<<"|******************************************************************|"<<endl;
      for (int i=0;i<30;i++){cout<<" ";}
      cout<<"|***************<iC A S T      U N I V E R S I T Y >***************|"<<endl;
      for (int i=0;i<30;i++){cout<<" ";}
      cout<<"|******************************************************************|"<<endl;
      for (int i=0;i<30;i++){cout<<" ";}
      cout<<"|******WELCOME TO iCAST UNIVERSITY FEEDBACK MANAGEMNET SYSTEM******|"<<endl;
      for (int i=0;i<30;i++){cout<<" ";}
      cout<<"|******************************************************************|"<<endl;
      for (int i=0;i<30;i++){cout<<" ";}
      cout<<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|"<<endl; 
      }
void main_menu()
{
      cout<<"\n1- Add/Drop students"<<endl;
      cout<<"2- Add ,Delete & Edit Feedback Questions"<<endl;
      cout<<"3- To View Student Feedback"<<endl;
      cout<<"4- Percentage Against Each Feedback\n5- To Check How many have Given Feedback\n6- Add a Course\n";
      cout<<"7- Search any KeyWord or Sentence or List of Student\n8- Exit\n";
}
void student_menu()
{
      cout<<"\n1- Give Feedback\n2- View Your Courses\n3- Exit\n\n";
}
void del(char filename[])
{
      int i=0;
      while (filename[i]!='\0')
      {i++;}
      filename[i]='.';filename[i+1]='t';filename[i+2]='x';filename[i+3]='t';
      if (remove(filename)==0)
      {cout<<"Done Modifiaction!"<<endl;}
}
void editstudentdata()
{
      cout<<"\nWhat You want to Change?\n\n1- Name\n2- Password\n3- Back to Previous Menu\n\n";
}

void add_drop()
{
      cout<<"\n1- Add a Student\n2- Edit in a Student Data\n3- Delete a Student Data\n4- Back To Main Menu\n\n";
}
void courses(string filename)
{
      fstream courses;courses.open(filename.c_str(),ios::in);
      string course="";int i=1;
      char c;
      cout<<endl;
      while (!courses.eof())
      {
            courses.get(c);
            if (c=='\n'&& !courses.eof())
            {if(course!="")
                  {cout<<i<<"- "<<course<<endl;i++;course="";}
            }
            else{
            course+=c;}
      }
      courses.close();
}
void course(string filename,int j)
{
      fstream courses;courses.open("courses.txt",ios::in);fstream file;
      string course="";int i=0;
      char c;filename+=".txt";
      while (!courses.eof())
      {
            courses.get(c);   
            if (c=='\n' && !courses.eof())
            {i++;
                  if (i==j)
                  {
                        file.open(filename.c_str(),ios::app);
                        file<<course<<endl;
                  }
                  else {course="";}
            }
            else{course+=c;}
      }
      courses.close();
      file.close();
}
void view_question(int i)
{
      fstream question;question.open("Questions.txt",ios::in);
      string ques="";char c;int j=0;
      while (!question.eof())
      {
            question.get(c);
            if (c!='\n')
            {ques+=c;}
            if (c=='\n' && ques!="")
            {j++;if (j==i)
            {cout<<j<<"- "<<ques<<endl;}
            else{ques="";}}
      }
}
void add_question(string question)
{
      fstream add;
      add.open("Questions.txt",ios::app);
      add<<question<<endl;
      add.close();
}
void options()
{
      cout<<"1. Strongly Agree 2. Agree 3. Neutral 4. Disagree 5. Strongly Disagree"<<endl;
}
void get_option(char i)
{
      switch(i)
      {
            case 49:{cout<<"Answer=Strongly Agree\n"<<endl;break;}
            case 50:{cout<<"Answer=Agree\n"<<endl;break;}
            case 51:{cout<<"Answer=Neutral\n"<<endl;break;}
            case 52:{cout<<"Answer=DisAgree\n"<<endl;break;}
            case 53:{cout<<"Answer=Strongly DisAgree\n"<<endl;break;}
      }
}
void delete_question(int j)
{
      fstream file;
      file.open("Questions.txt",ios::in);
      fstream updatedata;
      updatedata.open("update.txt",ios::out);
      char character;
      string question="";int i=0;
      while (!file.eof())
      {     
            file.get(character); 
            if (character=='\n' && !file.eof())
            {
                  i++;
                  if (i!=j)
                  {
                        updatedata<<question<<endl;question="";}
                  else
                  {question="";}
            }
            else{question+=character;}
      }
      file.close();
      updatedata.close();
      fstream file1;file1.open("Questions.txt",ios::out);
      fstream updatedata1;updatedata1.open("update.txt",ios::in);
      char c;
      while (!updatedata1.eof())
      {
            updatedata1.get(c);
            file1<<c;
      }char filename1[20]="update";
      del(filename1);
      file1.close();
}
void update_studentfile(string ID)
{
      string filename="student_IDs.txt";
      fstream file;
      file.open(filename.c_str(),ios::in);
      fstream updatedata;
      updatedata.open("update.txt",ios::out);
      char character;
      string rollnumber="",name="",password="";int space=0;
      while (!file.eof())
      {     
            file.get(character);//cout<<character;
            if (character==' ')
            {space++;}
            if (character!=' ' && space==0)
            {rollnumber+=character;}
            if (character!=' ' && space==1 || space==2)
            {name+=character;}
            if (character!=' ' && space==3)
            {password+=character;}  
            if (character=='\n' && !file.eof())
            {
                  if (rollnumber==ID)
                  {space=0;rollnumber="",name="",password="";}
                  else{updatedata<<rollnumber<<' '<<name<<' '<<password<<endl;
                  space=0;rollnumber="",name="",password="";}
                  
            }
      }
      file.close();
      updatedata.close();
      fstream file1;file1.open(filename.c_str(),ios::out);
      fstream updatedata1;updatedata1.open("update.txt",ios::in);
      char c;
      while (!updatedata1.eof())
      {
            updatedata1.get(c);
            file1<<c;
      }char filename1[20]="update";
      del(filename1);
      file1.close();
}
