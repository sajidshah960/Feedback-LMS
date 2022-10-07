#include "header.h"
int main()
{
      display();
      char portal;
      start_portal:
      cout<<"\n1-  Login As Admin\n2-  Login As Student\n3-  Exit\n";
      cout<<"Enter Login Portal :";cin>>portal;
      switch(portal){//////////////////////////////main portal menu////////////////////////////
      case 49:
      {/////////////////////////////////main portal 1///////////////admin////////////////////
      string save_login="sajid";
      string save_password="12345";
      string password;
      cin.ignore();
      string login;
      again_login:
      cout<<"Admin Login :";getline(cin,login);
      if (login==save_login)
      {again_password:
            cout<<"Enter Password :";getline(cin,password);
      if (password==save_password)
      {
            cout<<"\nAccess Granted"<<endl<<endl;
      main_admin:
      main_menu();
      char admin_choice;cout<<"Enter Your Choice :";cin>>admin_choice;
      switch(admin_choice){
            case 49:
            {/////////////////////////////////
                  main_add:
                  add_drop();
                  char addrop;cout<<"Enter Your Choice :";cin>>addrop;
                  switch(addrop){
                        case 49:
                        {
                        add_more_student://add a student//
                        cin.ignore();
                        string studentID;cout<<"Enter Student ID: ";getline(cin,studentID);
                        fstream write;
                        write.open("student_IDs.txt",ios::app);//////////
                        write<<studentID;
                        string name;cout<<"Enter Student Name: ";getline(cin,name);
                        string stupassword;cout<<"Enter His/Her Login Password: ";getline(cin,stupassword);
                        int bol=0;
                        write<<" "<<name<<" "<<stupassword<<endl;
                        fstream addstudent;
                        string studentID_copy=studentID;
                        studentID+=".txt";
                        addstudent.open(studentID.c_str(),ios::out);//////
                        add_more_course:
                        courses("courses.txt");
                        cout<<"Select course to Allote student: ";int add_course;cin>>add_course;
                        course(studentID_copy,add_course);
                        cout<<"Want to add more courses?(y for YES/anykey for no) :";cin>>addrop;
                        if (addrop=='y')
                        {goto add_more_course;}
                        cin.ignore();
                        cout<<"Do You Want To Add More Students: ";char addmore;cin>>addmore;
                        if (addmore=='y')
                        {goto add_more_student;}
                        else {write.close();
                        addstudent.close();
                        goto main_admin;}
                        break;}
                        case 50:
                        {//////////////////edit student data///////////
                         string filename="student_IDs.txt";string name1,password1;
                         edit:
                         string edit_ID;cout<<"Enter ID: ";cin>>edit_ID;
                         editstudentdata();char edit_choice;
                         cout<<"Enter Your Choice: ";cin>>edit_choice;
                         switch(edit_choice)
                         {
                               case 49:
                               {cout<<"Enter Edited Name: ";cin.ignore();
                               getline(cin,name1);break;}
                               case 50:
                               {cout<<"Enter Edited Password: ";cin>>password1;
                               break;}
                               case 51:
                               { goto main_admin;
                               break;}
                               default:
                               {cout<<"Invalid Choice\nDo You Want to Continue (y for YES/anykey For Exit): ";cin>>edit_choice;
                               if (edit_choice=='y')  {goto edit;}
                               else {goto exit;}}
                         }
                        fstream file;
                        file.open(filename.c_str(),ios::in);
                        fstream updatedata;
                        updatedata.open("update.txt",ios::out);
                        char character;
                        string rollnumber="",name="",password="";int space=0;
                        while (!file.eof())
                        {     
                              file.get(character);
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
                                    if (rollnumber==edit_ID && edit_choice==49)
                                    {space=0;rollnumber="",
                                    updatedata<<edit_ID<<' '<<name1<<' '<<password<<endl;
                                    name="";
                                    password="";}
                                    if (rollnumber==edit_ID && edit_choice==50)
                                    {space=0;rollnumber="",
                                    updatedata<<edit_ID<<' '<<name<<' '<<password1<<endl;
                                    name="";
                                    password="";
                                    }
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
                              {updatedata1.get(c);
                              file1<<c;}
                              char filename1[20]="update";
                              del(filename1);
                              file1.close();
                        break;}
                        case 51:
                        {/////////delete student data//////////////////////
                        char ID[20];
                        cout<<"Enter Student ID: ";cin>>ID;
                        string IDs=ID;
                        update_studentfile(IDs);
                        int k=0;   
                        del(ID);
                        break;}
                        case 52:
                        {goto main_admin;
                        break;}
                        default:
                        {
                        cout<<"Invalid choice"<<endl;
                        cout<<"\nDo You want to Continue (y for yes/ anykey to Exit): ";cin>>addrop;
                        if (addrop=='y')  { goto main_add;}
                        else   {cout<<"exit"<<endl;}
                        break;}
                              }////switch end of add drop and edit student///////
            break;}
            case 50:
            {question_menu:
            cout<<"1- To Add Feedback Question\n2- To Delete Feedback Question\n3- To Edit Feedback Question\n4- Back to Main Menu\n\n";
            string question;
                  char question_choice;cout<<"Enter Your Choice: ";cin>>question_choice;
                  switch(question_choice)
                  {
                        case 49://////////add feedback question//////////////////////////////////
                        {add_more_question:
                        cout<<"Enter Feedback Question: ";cin.ignore();getline(cin,question);
                        add_question(question);
                        cout<<"Want To Add more Questions? (y for YES/anykey for Back Main): ";cin>>question_choice;
                        if (question_choice=='y') {goto add_more_question;} else{goto question_menu;}
                              break;}
                        case 50:
                        {//////////////////////////////delete feed back question////////////////////////////
                        courses("Questions.txt");int question_select;
                        cout<<"Select Question You Want To Delete: ";cin>>question_select;
                        delete_question(question_select);
                        break;}
                        case 51://///////edit questions////////////////////////////////////
                        {courses("Questions.txt");
                        int question_select;
                        cout<<"Select Question You Want To Edit: ";cin>>question_select;
                        delete_question(question_select);
                        cout<<"Enter Edited Feedback Question: ";cin.ignore();getline(cin,question);
                        add_question(question);
                        courses("Questions.txt");
                        break;}
                        case 52:
                        {goto main_admin;break;}
                        default:
                        {cout<<"Invalid Choice\nDo You Want to Enter Again: (y for YES/anykey for Exit)";cin>>question_choice;
                        if (question_choice=='y')     {goto question_menu;}
                        else   {goto exit;}
                        break;}
                  }
            break;}
            case 51:
            {///////////to view feed back////////////////////////////
				view_again:
			string copy_ID;string view_ID;
            cout<<"Enter Student ID: ";cin>>view_ID;copy_ID=view_ID;view_ID+=".txt";
            courses(view_ID);
            cout<<"Select Course for Feedback View: ";int select_feedback_course;cin>>select_feedback_course;
            fstream feedback;feedback.open(view_ID.c_str(),ios::in);
            char feedback_character;
            string course_file;int j=0;int space=0;
            while (!feedback.eof())
            {
                  feedback.get(feedback_character);
                  if (feedback_character!=' ' && space==0)
                  {course_file+=feedback_character;}
                  if (feedback_character==' ')
                  {space++;}
                  if (feedback_character=='\n')
                  {space=0;j++;     
                  if (select_feedback_course==j)
                  {goto outside1;}
                  else {course_file="";}}
            }feedback.close();
            outside1:
            string course_copy=course_file;
            course_file+=".txt";
            fstream feedback_course;
            feedback_course.open(course_file.c_str(),ios::in);
            fstream feedback_question;
            feedback_question.open("Questions.txt",ios::in);
            space=0;char feedback_ch;
            string IDcheck="";j=0;
            while (!feedback_course.eof())
            {
                  feedback_course.get(feedback_ch);
                  if (feedback_ch!=' ')
                  {if (space==0)
                  {IDcheck+=feedback_ch;}}
                  if (feedback_ch==' '){space++;}
                  if (feedback_ch!=' '&&IDcheck==copy_ID && space==1)
                  {
                        j++;
                        view_question(j);
                        get_option(feedback_ch);
                  }
                  if (feedback_ch=='\n')
                  {IDcheck="";j=0;space=0;}
            }
            feedback.close();
            feedback_question.close();
			char c_again_view; cout << "Do Want to View More Feedbacks (y for YES/ anykey for EXIT): "; cin >> c_again_view;
			if (c_again_view == 'y')
			{
				goto view_again;
			}
			else {
				goto exit;
			}
            break;}
            case 52:
            {////////percentage against each feedback///////////////
            courses("courses.txt");
            cout<<"Select Course for Feedback View: ";int select_feedback_course;cin>>select_feedback_course;
            fstream feedback;feedback.open("courses.txt",ios::in);//////////////////////////////////////////////////////
            char feedback_character;
            string course_file;int j=0;int space=0;
            while (!feedback.eof())
            {
                  feedback.get(feedback_character);
                  if (feedback_character!=' ' && space==0)
                  {course_file+=feedback_character;}
                  if (feedback_character==' ')
                  {space++;}
                  if (feedback_character=='\n')
                  {space=0;j++;     
                  if (select_feedback_course==j)
                  {goto outside2;}
                  else {course_file="";}}
            }feedback.close();
            outside2:
            course_file+="_percentage.txt";
            fstream percentage;percentage.open(course_file.c_str(),ios::in);int feedback_percentage;
            percentage>>feedback_percentage;
            cout<<"Feedback Percentage Corresponding to Course: "<<feedback_percentage<<" %"<<endl;
            break;}
            case 53:
            {///////////////////////to check number of feed backs//////////
            courses("courses.txt");
            cout<<"Select Course for Feedback Views: ";int select_feedback_course;cin>>select_feedback_course;
            fstream feedback;feedback.open("courses.txt",ios::in);//////////////////////////////////////////////////////
            char feedback_character;
            string course_file;int j=0;int space=0;
            while (!feedback.eof())
            {
                  feedback.get(feedback_character);
                  if (feedback_character!=' ' && space==0)
                  {course_file+=feedback_character;}
                  if (feedback_character==' ')
                  {space++;}
                  if (feedback_character=='\n')
                  {space=0;j++;     
                  if (select_feedback_course==j)
                  {goto outside3;}
                  else {course_file="";}}
            }feedback.close();
            outside3:
            course_file+="_percentage.txt";
            fstream percentage;percentage.open(course_file.c_str(),ios::in);int feedback_count;
            percentage>>feedback_count;
            percentage>>feedback_count;
            cout<<"The number of Student Who have Given the Feedback = "<<feedback_count<<" Students"<<endl;
            break;}
            case 54:
            {///////////////////////add a course///////////////

            fstream add_course;
            add_course.open("courses.txt",ios::app);
            string course;cout<<"Enter Course Name: ";cin.ignore();getline(cin,course);
            add_course<<course<<endl;
            int i=0;
            while (course[i]!='\0')
            {i++;}
            string add_course_file="";int space=0;int j=0;
            while (j<i)
            {
                  if (space==0)
                  {
                  add_course_file+=course[j];
                  if (course[j]==' ')
                  {space++;}
                  } j++;
            }
            string copy_add_course_file=add_course_file;
            add_course_file+=".txt";
            fstream course_file1;course_file1.open(add_course_file.c_str(),ios::out);
            fstream course_file2;copy_add_course_file+="_percentage.txt";
            course_file2.open(copy_add_course_file.c_str(),ios::out);
            i=100;j=0;
            course_file2<<i<<endl<<j<<endl;
            add_course.close();course_file1.close();course_file2.close();
            break;}
            case 55:
            {/////////////////////to search anykey wordd/////////////////////////
            search_again:
            cout<<"\n1- Search Any Keywords in comments\n2- Search Any sentence in Feedbacks\n3- Back To Main Menu\n\n";
            cout<<"Enter your Choice: ";char search_choice;cin>>search_choice;
            switch(search_choice)
            {
                  case 49:
                  {////////to search any keyword///////
                  cout<<"code for Search keyword"<<endl;
                        break;}
                  case 50:
                  {//////////to search any sentance//////////
                  cout<<"Code To search Sentence"<<endl;
                        break;}
                  case 51:
                  {goto main_admin;}
                        break;
                  default:
                  {cout<<"Invalid Choice\nDo You Want Enter Again: (y for YES/anykey for Exit )";cin>>search_choice;
                  if (search_choice=='y') {goto search_again;}
                  else {goto exit;}
                  break;}
            }
            break;}
            case 56:
            {/////////////////////////////exit//////////////////////////
            goto exit;
            break;}
            default:
            {cout<<"Invalid Choice\nDo You want To Enter Again: (y for YES/anykey for Exit)";cin>>admin_choice;
            if (admin_choice=='y') {goto main_admin;}
            else {goto exit;}
                  break;}
                              }//////////admin switch endddd///////////////
            }
            else {cout<<"Wrong Password"<<endl;goto again_password;}
            }
      else {cout<<"Invalid login."<<endl;goto again_login;}
      break;}        
      case 50:
      {////////////////////////////////////////student portal////////////////////////////////////////////////////////////
      string ID;cout<<"Enter Your ID: ";cin>>ID;
	  string ID_copy = ID;
	  ID_copy += ".txt";
      fstream student_IDcheck;
      student_IDcheck.open("student_IDs.txt",ios::in);
      char As_Student;
      string IDcheck="";
      string password;
      string name="";
      string passwordcheck="";
      int space=0;
      while (!student_IDcheck.eof())
      {     
            student_IDcheck.get(As_Student);//cout<<As_Student;
            if (As_Student==' ')
            {space++;}
            if (As_Student!=' ' &&  As_Student!='\n'&& space==0)
            {IDcheck+=As_Student;}
            if (As_Student!=' ' && As_Student!='\n'&& space==1 || space==2)
            {name+=As_Student;}
            if (As_Student!=' ' && As_Student!='\n'&& space==3)
            {passwordcheck+=As_Student;}
            if (As_Student=='\n')
            {
                  if (ID==IDcheck)
                  {
                        student_password:  
                        cout<<"Enter Password: ";cin>>password;
                        if (password==passwordcheck)
                              {cout<<"\nYour ID # "<<ID<<"\nName= "<<name<<"\n";goto start_student;student_IDcheck.close();}
                        else  {cout<<"Wrong Password\n\n";goto student_password;}
                  }
                  else  {space=0;IDcheck="",name="",passwordcheck="";}
            }      
      }
      cout<<"\nYou Are Not Registered\nPlease concern with Acedemic Officer\n\n";student_IDcheck.close();goto end;
	  start_student:
      student_menu();
      char student_choice;cout<<"Enter Your Choice :";cin>>student_choice;
      switch(student_choice) {
            case 49:
            {/////////give feed back//////////////////////////
                  string ID_copy=ID;
                  ID_copy+=".txt";
                  courses(ID_copy);
                  int course_select;
                  cout<<"Select feedback for Feedback: ";cin>>course_select;
                  fstream feedback;feedback.open(ID_copy.c_str(),ios::in);
                  int j=0;char c;int space=0;string course_file="";
            while (!feedback.eof())
            {
                  feedback.get(c);
                  if (c!=' ' && space==0)
                  {course_file+=c;}
                  if (c==' ')
                  {space++;}
                  if (c=='\n')
                  {space=0;j++;
                  if (course_select==j)
                  {goto outside;}
                  else {course_file="";}}
            }feedback.close();
            outside:
            string course_copy=course_file;
            course_file+=".txt";
            fstream write;write.open(course_file.c_str(),ios::app);
            write<<ID_copy<<" ";
            //view_question(course_select);
            fstream ques;ques.open("Questions.txt",ios::in);char ch;
            string question="";int question_number=0;int student_answer;int percentage=100;string comments;
            while (!ques.eof())
            {
                  ques.get(ch);
				  if (!ques.eof() && ch == '\n')
				  {
					  if (question != "")
					  {
						  question_number++; cout << question_number << "- " << question << endl; options(); question = "";
					  option:
						  cout << "Enter Your Option: "; cin >> student_answer; write << student_answer; cout << endl;
						  switch (student_answer)
						  {
						  case 1:
						  {percentage = (100 + percentage) / 2; break; }
						  case 2:
						  {percentage = (80 + percentage) / 2; }
						  case 3:
						  {percentage = (50 + percentage) / 2; break; }
						  case 4:
						  {percentage = (30 + percentage) / 2; break; }
						  case 5:
						  {percentage = (10 + percentage) / 2; break; }
						  default:
						  {cout << "\nInvalid Choice\nEnter Again."; goto option; break; }
						  }
					  }
				  }
                  else
                  {question+=ch;}
            }
            cin.ignore();cout<<"\nEnter Your Comments: ";getline(cin,comments);write<<" "<<comments<<endl;
            course_copy+="_percentage.txt";
            fstream course_percentage;int previous_percentag;int number_feedbacks;
            course_percentage.open(course_copy.c_str(),ios::in);
            while (!course_percentage.eof())
            {
                  course_percentage>>previous_percentag;
                  course_percentage>>number_feedbacks;
            }
            percentage=(percentage+previous_percentag)/2;
            number_feedbacks+=1;
            course_percentage.close();
            fstream new_percentage;new_percentage.open(course_copy.c_str(),ios::out);
            new_percentage<<percentage<<endl;
            new_percentage<<number_feedbacks<<endl;
            new_percentage.close();
            cout<<"Want to Go Back Menu (y for YES/anykey for Exit) :";cin>>student_choice;
            if (student_choice=='y')  {goto start_student;}
            else {goto exit;}
            break;}
            case 50:
            {////////view coursessssssssssss//////////////////////////////
            courses(ID_copy);
                  cout<<"Want to Go Back Menu(y for YES/anykey for EXIT)";cin>>student_choice;
                  if (student_choice=='y')      {goto start_student;}
                  else {goto exit;}
            break;}
            /*case 51:
            {
                  enter_password:
                  cout<<"Enter Current Password: ";cin>>password;
                  if (password==passwordcheck)
                  {
                        cout<<"code for edit pass";
                  }
                  else {cout<<"\nWrong Password\nDo You want to Enter Again (y for yes/anykey for back menu): ";cin>>student_choice;
                        if (student_choice=='y'){goto enter_password;}
                        else {goto start_student;}
                        }
            break;}*/
            case 51:
            {/////////////////student exit///////////////////////
                  cout<<"Program Exit!"<<endl;goto end;
            break;}
            default:
            {
                  cout<<"Invalid Choice\n\nDo you want to Enter Again(y for yes/anykey for Exit)";
                  cin>>student_choice;
                  if (student_choice=='y')
                  {goto start_student;}
                  else{goto exit;}
            break;}
                              }
      break;}
      ////////////////////////////////////////////////////exit mode/////////////////////////////////////////////
      case 51:
      {
            exit:
            cout<<"Program Exited"<<endl;goto end;
      break;}
      default:
      {
            cout<<"Invalid Choice"<<endl<<"Do You Want To Continue (y for YES /anykey for Exit):";cin>>portal;
            if (portal=='y')
            {goto start_portal;}
            else {goto end;}
      break;}
      }
  end:
	  system("pause");
      return 0;
}
