#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>


void student_entry()
{
    clrscr();
    gotoxy(33,1);
    cout<<"STUDENTS";
    gotoxy(1,3);
    cout<<"roll";
    gotoxy(7,3);
    cout<<"name";
    gotoxy(21,3);
    cout<<"father";
    gotoxy(36,3);
    cout<<"mother";
    gotoxy(51,3);
    cout<<"dob";
    gotoxy(61,3);
    cout<<"gndr";
    gotoxy(67,3);
    cout<<"school";
}

void entry_school()
{
    clrscr();
    gotoxy(33,1);
    cout<<"SCHOOLS";
    gotoxy(1,3);
    cout<<"scode";
    gotoxy(7,3);
    cout<<"ccode";
    gotoxy(13,3);
    cout<<"school";
    gotoxy(48,3);
    cout<<"center";
}


class code
{
private:
    int scode,ccode;
    char school[50];

    void check()
    {
        fstream infile;
        infile.open("school",ios::binary|ios::in);
        code obj;
        while(infile.read((char*)&obj,sizeof(obj)))
        {
            if(scode==obj.ret_scode())
            {
                gotoxy(1,21);
                cout<<"this school code already exists ";
                gotoxy(19,4);
                cout<<"      ";
                gotoxy(19,4);
                cin>>scode;
                check();
            }
        }
        infile.close();
    }

public:
    void getdata(int j=0)
    {
        clrscr();
        cout<<"enter the following data "<<endl<<endl<<endl;
        cout<<"enter school code "<<endl<<endl;
        cout<<"enter center code "<<endl<<endl;
        cout<<"enter school "<<endl<<endl;
        if(j==1)
        {
            gotoxy(19,4);
            cout<<scode;
        }
        else
        {
            gotoxy(19,4);
            cin>>scode;
            check();
            gotoxy(1,21);
            cout<<"                                                      ";
        }
        gotoxy(19,6);
        cin>>ccode;
        gotoxy(19,8);
        gets(school);
        gotoxy(1,12);
    }

    char center[50];

    int ret_scode()
    {
        return scode;
    }
    int ret_ccode()
    {
        return ccode;
    }
    char* ret_school()
    {
        return school;
    }
    char* ret_center()
    {
        return center;
    }

    void display(int i)
    {
        gotoxy(2,i);
        cout<<scode;
        gotoxy(8,i);
        cout<<ccode;
        gotoxy(13,i);
        cout<<school;
        gotoxy(48,i);
        cout<<center;
    }

    void display2()
    {
        clrscr();
        cout<<"school code "<<scode<<endl<<endl;
        cout<<"school name "<<school<<endl<<endl;
        cout<<"center code "<<ccode<<endl<<endl;
        cout<<"center name "<<center<<endl<<endl;
    }
};

class data
{
private:

    long rolno;
    char name[25],fname[25],mname[25];
    int date,month,year;
    char school[50],center[50],gender;
    int scode,ccode;
    int eng,math,phy,chem,comp;
    char geng[3],gmath[3],gphy[3],gchem[3],gcomp[3];

    void assign_codes(int sch,int help=0)
    {
        fstream codes;
        code cobj;
        int flag=0;
        codes.open("school",ios::binary|ios::in);
        while(codes.read((char*)&cobj,sizeof(cobj)))
        {
            if(sch==cobj.ret_scode())
            {
                ccode=cobj.ret_ccode();
                strcpy(school,cobj.ret_school());
                strcpy(center,cobj.ret_center());
                flag=1;
            }
        }
        if(flag==0&&help==0)
        {
            cout<<endl<<"the school with school code "<<scode<<" does not exist ";
            cout<<"enter the correct school code ";
            cin>>scode;
            assign_codes(scode);
        }
        if(flag==0&&help==1)
        {
            ccode=0;
            strcpy(school,"N/A");
            strcpy(center,"N/A");
        }

        codes.close();
    }

    void check()
    {
        fstream infile;
        infile.open("stu_data",ios::binary|ios::in);
        data obj;
        while(infile.read((char*)&obj,sizeof(obj)))
        {
            if(rolno==obj.ret_roll())
            {
                gotoxy(1,23);
                cout<<"this roll number already exists ";
                gotoxy(20,3);
                cout<<"      ";
                gotoxy(20,3);
                cin>>rolno;
                check();
            }
        }
        infile.close();
    }

    char* grade(int marks)
    {
        float per;
        per = marks;
        char grade[3];
        if(per>=91&&per<=100)
            strcpy(grade,"A1");
        if(per>=81&&per<=90)
            strcpy(grade,"A2");
        if(per>=71&&per<=80)
            strcpy(grade,"B1");
        if(per>=61&&per<=70)
            strcpy(grade,"B2");
        if(per>=51&&per<=60)
            strcpy(grade,"C1");
        if(per>=41&&per<=50)
            strcpy(grade,"C2");
        if(per>=33&&per<=40)
            strcpy(grade,"D");
        if(per>=21&&per<=32)
            strcpy(grade,"E1");
        if(per<21)
            strcpy(grade,"E2");
        return grade;
    }

    void gradecalc()
    {
        strcpy(geng,grade(eng));
        strcpy(gphy,grade(phy));
        strcpy(gchem,grade(chem));
        strcpy(gmath,grade(math));
        strcpy(gcomp,grade(comp));
    }


public:

    data(int i=0)
    {
        if(i==0)
        {
            eng=math=phy=chem=comp=0;
            strcpy(geng,"NA");
            strcpy(gphy,"NA");
            strcpy(gchem,"NA");
            strcpy(gmath,"NA");
            strcpy(gcomp,"NA");
            gender='u';
        }
    }

    void getdata(int i,int j=1)
    {
        data(i);
        clrscr();
        cout<<"enter the following data "<<endl<<endl;
        cout<<"roll no"<<endl<<endl;
        cout<<"name"<<endl<<endl;
        cout<<"father's name"<<endl<<endl;
        cout<<"mother's name"<<endl<<endl;
        cout<<"date of birth"<<endl<<endl;
        cout<<"date"<<endl<<endl;
        cout<<"month"<<endl<<endl;
        cout<<"year"<<endl<<endl;
        cout<<"gender"<<endl<<endl;
        cout<<"school code"<<endl<<endl;
        gotoxy(20,3);

        if(j==2)
        {
            cout<<rolno;
        }
        else
        {
            cin>>rolno;
            check();
            gotoxy(1,23);
            cout<<"                                           ";
        }

        gotoxy(20,5);
        gets(name);
        gotoxy(20,7);
        gets(fname);
        gotoxy(20,9);
        gets(mname);
        gotoxy(20,13);
        cin>>date;
        gotoxy(20,15);
        cin>>month;
        gotoxy(20,17);
        cin>>year;
        gotoxy(20,19);
        cin>>gender;
        gotoxy(20,21);
        cin>>scode;
        assign_codes(scode);
    }

    void assign_again()
    {
        assign_codes(scode,1);
    }

    void getmarks()
    {
        clrscr();
        cout<<"enter the following data "<<endl<<endl;
        cout<<"marks in english "<<endl<<endl;
        cout<<"marks in physics "<<endl<<endl;
        cout<<"marks in chemistry "<<endl<<endl;
        cout<<"marks in mathematics "<<endl<<endl;
        cout<<"marks in computer ";
        gotoxy(23,3);
        cin>>math;
        gotoxy(23,5);
        cin>>chem;
        gotoxy(23,7);
        cin>>phy;
        gotoxy(23,9);
        cin>>eng;
        gotoxy(23,11);
        cin>>comp;
        gradecalc();
    }

    int ret_roll()
    {
        return rolno;
    }

    int ret_ccode()
    {
        return ccode;
    }

    int ret_scode()
    {
        return scode;
    }

    int ret_eng()
    {
        return eng;
    }

    int ret_phy()
    {
        return phy;
    }

    int ret_chem()
    {
        return chem;
    }

    int ret_math()
    {
        return math;
    }

    int ret_comp()
    {
        return comp;
    }

    void display() //whole data
    {
        cout<<endl<<"roll number   : "<<rolno<<endl;
        cout<<"name          : "<<name<<endl;
        cout<<"father's name : "<<fname<<endl;
        cout<<"mother's name : "<<mname<<endl;
        cout<<"date of birth : "<<date<<" "<<month<<" "<<year<<endl;
        cout<<"gender        : "<<gender<<endl;
        cout<<"school code   : "<<scode<<endl;
        cout<<"school        : "<<school<<endl;
        cout<<"center code   : "<<ccode<<endl;
        cout<<"center        : "<<center<<endl<<endl;
        cout<<"marks in eng  "<<eng<<", grade in eng  "<<geng<<endl;
        cout<<"marks in phy  "<<phy<<", grade in phy  "<<gphy<<endl;
        cout<<"marks in chem "<<chem<<", grade in chem "<<gchem<<endl;
        cout<<"marks in math "<<math<<", grade in math "<<gmath<<endl;
        cout<<"marks in comp "<<comp<<", grade in comp "<<gcomp<<endl;
    }

    void display2(int i)//data of all student
    {
        gotoxy(1,i);
        cout<<rolno;
        gotoxy(6,i);
        cout<<name;
        gotoxy(21,i);
        cout<<fname;
        gotoxy(36,i);
        cout<<mname;
        gotoxy(51,i);
        cout<<date<<" "<<month<<" "<<year;
        gotoxy(63,i);
        cout<<gender;
        gotoxy(67,i);
        cout<<school;
    }

    void display3()//data of a particular student
    {
        cout<<"roll number "<<rolno<<endl;
        cout<<"name "<<name<<endl;
        cout<<"father "<<fname<<endl;
        cout<<"mother "<<mname<<endl;
        cout<<"date of birth "<<date<<" "<<month<<" "<<year<<endl;
        cout<<"gender "<<gender<<endl;
        cout<<"school "<<school<<endl;
    }

    void display4(int i)//result of a school
    {
        gotoxy(1,i);
        cout<<rolno;
        gotoxy(8,i);
        cout<<name;
        gotoxy(28,i);
        cout<<eng;
        gotoxy(32,i);
        cout<<geng;
        gotoxy(37,i);
        cout<<phy;
        gotoxy(41,i);
        cout<<gphy;
        gotoxy(45,i);
        cout<<chem;
        gotoxy(50,i);
        cout<<gchem;
        gotoxy(54,i);
        cout<<comp;
        gotoxy(60,i);
        cout<<gcomp;
        gotoxy(64,i);
        cout<<math;
        gotoxy(69,i);
        cout<<gmath;
    }

};

void result_entry()
{
    clrscr();
    gotoxy(1,5);
    cout<<"roll";
    gotoxy(8,5);
    cout<<"name";
    gotoxy(28,5);
    cout<<"eng";
    gotoxy(32,5);
    cout<<"grd";
    gotoxy(37,5);
    cout<<"phy";
    gotoxy(41,5);
    cout<<"grd";
    gotoxy(45,5);
    cout<<"chem";
    gotoxy(50,5);
    cout<<"grd";
    gotoxy(54,5);
    cout<<"comp";
    gotoxy(60,5);
    cout<<"grd";
    gotoxy(64,5);
    cout<<"math";
    gotoxy(69,5);
    cout<<"grd";
}

void main()
{
    data student,student2;
    code obj,obj2;
    fstream file,schoolfile;

    int choice,roll,check,scode,i,del=2,count;
    char start='y';

    while(start=='y'||start=='Y')
    {
        clrscr();
        file.open("stu_data",ios::binary|ios::in|ios::app);
        schoolfile.open("school",ios::binary|ios::app|ios::in);

        gotoxy(15,1);
        cout<<"enter choice "<<endl<<endl<<endl<<endl;
        cout<<"0: exit"<<endl<<endl;
        cout<<"1: data of a student (view)"<<endl<<endl;
        cout<<"2: data, marks of a student (enter, remove, alter)"<<endl<<endl;
        cout<<"3: data of school (add, view, alter, remove) "<<endl<<endl;
        cout<<"4: display result"<<endl<<endl;

        cin>>choice;

        if(choice==0)
        {
            start='n';
        }

        if(choice==1)//initial choice for data of student
        {
            clrscr();
            gotoxy(15,1);
            cout<<"enter choice "<<endl<<endl;
            cout<<"0: return to the main menu "<<endl<<endl;
            cout<<"1: view data of all students "<<endl<<endl;
            cout<<"2: of a particular student "<<endl<<endl;
            cout<<"3: of students of a particular school "<<endl<<endl;
            cout<<"4: of students of a partucular center "<<endl<<endl;
            cin>>choice;

            if(choice==1)//sub part of data of student(display the whole data)
            {
                student_entry();
                i=5;
                while(file.read((char*)&student,sizeof(student)))
                {
                    student.display2(i);
                    ++i;
                }
            }

            if(choice==2)//sub part of data of student(of a particular student)
            {
                clrscr();
                cout<<"enter the roll number to be searched ";
                cin>>roll;
                cout<<endl<<endl;
                while(file.read((char*)&student,sizeof(student)))
                {
                    check=student.ret_roll();
                    if(check==roll)
                        student.display3();
                }
            }

            if(choice==3)//sub part of data of student(display the whole data of a school)
            {
                clrscr();
                cout<<"enter the school code ";
                cin>>scode;
                student_entry();
                i=5;
                while(file.read((char*)&student,sizeof(student)))
                {
                    if(scode==student.ret_scode())
                    {
                        student.display2(i);
                        ++i;
                    }
                }
            }

            if(choice==4)//sub part of data of student(display the whole data of a center)
            {
                clrscr();
                cout<<"enter the school code of the center ";
                cin>>scode;
                student_entry();
                i=5;
                while(file.read((char*)&student,sizeof(student)))
                {
                    if(scode==student.ret_ccode())
                    {
                        student.display2(i);
                        ++i;
                    }
                }
            }


            getch();
            choice=0;
        }//for intial choice=1

        if(choice==2)//intial for entering students data
        {
            char ch='y';
            clrscr();
            gotoxy(15,1);
            cout<<"enter choice "<<endl<<endl;
            cout<<"0 : return ot the main menu "<<endl<<endl;
            cout<<"1 : entering students data "<<endl<<endl;
            cout<<"2 : enter or alter marks of a student "<<endl<<endl;
            cout<<"3 : alter data of a student "<<endl<<endl;
            cout<<"4 : to delete a record "<<endl<<endl;
            cin>>choice;

            if(choice==1)//entering new data of a student
            {
                fstream file2;
                file2.open("temp",ios::binary|ios::out);
                ch='y';
                while(ch=='y'||ch=='Y')
                {
                    student.getdata(0,1);
                    file.write((char*)&student,sizeof(student));
                    cout<<"do you want to enter more data (y or n)";
                    cin>>ch;
                }

                int roll1[100];
                count=0;
                file.close();
                file.open("stu_data",ios::binary|ios::in|ios::app);
                while(file.read((char*)&student,sizeof(student)))
                {
                    roll1[count]=student.ret_roll();
                    ++count;
                }

                int i,j,help;
                for(i=0; i<count; ++i)
                {
                    for(j=i; j<count; ++j)
                    {
                        if(roll1[i]>roll1[j])
                        {
                            help=roll1[i];
                            roll1[i]=roll1[j];
                            roll1[j]=help;
                        }
                    }
                }

                file.close();
                file.open("stu_data",ios::binary|ios::in|ios::app);

                for(i=0; i<count; ++i)
                {
                    file.seekg(0,ios::beg);
                    while(file.read((char*)&student,sizeof(student)))
                    {
                        if(roll1[i]==student.ret_roll())
                        {
                            file2.write((char*)&student,sizeof(student));
                            break;
                        }
                    }
                }
                file2.close();
                file.close();
                remove("stu_data");
                rename("temp","stu_data");
            }

            if(choice==2)//enter or alter marks of a student
            {
                clrscr();
                cout<<"enter the roll number of the student ";
                cin>>roll;
                fstream outfile;
                outfile.open("temp",ios::binary|ios::out);
                while(file.read((char*)&student,sizeof(student)))
                {
                    check=student.ret_roll();
                    if(check==roll)
                        student.getmarks();
                    outfile.write((char*)&student,sizeof(student));
                }
                outfile.close();
                remove("stu_data");
                rename("temp","stu_data");
            }
            if(choice==3)//alter data of a student
            {
                clrscr();
                cout<<"enter the roll number of the student ";
                cin>>roll;
                fstream outfile;
                outfile.open("temp3",ios::binary|ios::out);
                while(file.read((char*)&student,sizeof(student)))
                {
                    check=student.ret_roll();
                    if(check==roll)
                        student.getdata(1,2);//donot have to change marks and roll number;
                    outfile.write((char*)&student,sizeof(student));
                }
                outfile.close();
                remove("stu_data");
                rename("temp3","stu_data");
            }

            if(choice==4)
            {
                clrscr();
                cout<<"enter the roll numeber of the student ";
                cin>>roll;
                cout<<endl<<endl<<endl;
                fstream newfile;
                newfile.open("temp",ios::binary|ios::out);
                while(file.read((char*)&student,sizeof(student)))
                {
                    check=student.ret_roll();
                    if(check==roll)
                    {
                        student.display3();
                        cout<<endl<<endl<<"the data in the record is the above "<<endl;
                        cout<<"are you sure you want to delete it (1: yes , 2: no) ";
                        cin>>del;
                    }
                    if(del==2)
                    {
                        newfile.write((char*)&student,sizeof(student));
                    }
                    del=2;
                }
                newfile.close();
                remove("stu_data");
                rename("temp","stu_data");
            }


            choice=0;
        }//intial choice 2

        if(choice==3)//initial choice for schools
        {
            char ch2='y';
            clrscr();
            gotoxy(15,1);
            cout<<"enter choice "<<endl<<endl;
            cout<<"0: return to the main menu "<<endl<<endl;
            cout<<"1: enter data "<<endl<<endl;
            cout<<"2: view all schools "<<endl<<endl;
            cout<<"3: view a particular school "<<endl<<endl;
            cout<<"4: delete a school "<<endl<<endl;
            cout<<"5: alter the data of a school "<<endl<<endl;
            cin>>choice;

            if(choice==1)//enter data of school
            {
                fstream newfile,file2;
                newfile.open("temp2",ios::binary|ios::out);
                file2.open("temp3",ios::binary|ios::out);
                ch2='y';
                while(ch2=='y'||ch2=='Y')
                {
                    clrscr();
                    obj.getdata();
                    schoolfile.write((char*)&obj,sizeof(obj));
                    cout<<"do you want to enter more data (y or n)";
                    cin>>ch2;
                }
                int roll2[100];
                count=0;
                schoolfile.close();
                schoolfile.open("school",ios::binary|ios::in|ios::app);
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    roll2[count]=obj.ret_scode();
                    ++count;
                }

                int i,j,help;
                for(i=0; i<count; ++i)
                {
                    for(j=i; j<count; ++j)
                    {
                        if(roll2[i]>roll2[j])
                        {
                            help=roll2[i];
                            roll2[i]=roll2[j];
                            roll2[j]=help;
                        }
                    }
                }

                schoolfile.close();
                schoolfile.open("school",ios::binary|ios::in|ios::app);

                for(i=0; i<count; ++i)
                {
                    schoolfile.seekg(0,ios::beg);
                    while(schoolfile.read((char*)&obj,sizeof(obj)))
                    {
                        if(roll2[i]==obj.ret_scode())
                        {
                            file2.write((char*)&obj,sizeof(obj));
                            break;
                        }
                    }
                }
                file2.close();
                schoolfile.close();
                remove("school");
                rename("temp3","school");


                schoolfile.open("school",ios::binary|ios::in|ios::app);
                int flag=0;
                schoolfile.seekg(0,ios::beg);
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    help=schoolfile.tellg();
                    schoolfile.seekg(0,ios::beg);
                    while(schoolfile.read((char*)&obj2,sizeof(obj2)))
                    {
                        if(obj2.ret_scode()==obj.ret_ccode())
                        {
                            strcpy(obj.center,obj2.ret_school());
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        strcpy(obj.center,"N/A");
                        schoolfile.close();
                        schoolfile.open("school",ios::binary|ios::in|ios::app);
                    }
                    flag=0;
                    newfile.write((char*)&obj,sizeof(obj));
                    schoolfile.seekg(help,ios::beg);
                }
                getch();
                newfile.close();
                schoolfile.close();
                remove("school");
                rename("temp2","school");

                newfile.open("temp7",ios::binary|ios::out);
                while(file.read((char*)&student,sizeof(student)))
                {
                    student.assign_again();
                    newfile.write((char*)&student,sizeof(student));
                }
                file.close();
                newfile.close();
                remove("stu_data");
                rename("temp7","stu_data");
            }

            if(choice==2)//view all schools
            {
                entry_school();
                i=5;
                schoolfile.seekg(0,ios::beg);
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    obj.display(i);
                    ++i;
                }
                schoolfile.close();
                getch();
            }

            if(choice==3)
            {
                clrscr();
                cout<<"enter the school code ";
                cin>>scode;
                cout<<endl<<endl<<endl;
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    if(obj.ret_scode()==scode)
                        obj.display2();
                }
                getch();
            }


            if(choice==4)
            {
                clrscr();
                cout<<"enter the school code ";
                cin>>scode;
                cout<<endl<<endl<<endl;
                fstream newfile;
                newfile.open("temp",ios::binary|ios::out);
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    check=obj.ret_scode();
                    if(check==scode)
                    {
                        obj.display2();
                        cout<<endl<<endl<<"the data in the record is the above "<<endl;
                        cout<<"are you sure you want to delete it (1: yes , 2: no) ";
                        cin>>del;
                    }
                    if(del==2)
                    {
                        newfile.write((char*)&obj,sizeof(obj));
                    }
                    del=2;
                }
                schoolfile.close();
                newfile.close();
                remove("school");
                rename("temp","school");

                schoolfile.open("school",ios::binary|ios::in|ios::app);
                newfile.open("temp8",ios::binary|ios::out);
                int flag=0,help;
                schoolfile.seekg(0,ios::beg);
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    help=schoolfile.tellg();
                    schoolfile.seekg(0,ios::beg);
                    while(schoolfile.read((char*)&obj2,sizeof(obj2)))
                    {
                        if(obj2.ret_scode()==obj.ret_ccode())
                        {
                            strcpy(obj.center,obj2.ret_school());
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        strcpy(obj.center,"N/A");
                        schoolfile.close();
                        schoolfile.open("school",ios::binary|ios::in|ios::app);
                    }
                    flag=0;
                    newfile.write((char*)&obj,sizeof(obj));
                    schoolfile.seekg(help,ios::beg);
                }
                getch();
                newfile.close();
                schoolfile.close();
                remove("school");
                rename("temp8","school");


                newfile.open("temp7",ios::binary|ios::out);
                while(file.read((char*)&student,sizeof(student)))
                {
                    student.assign_again();
                    newfile.write((char*)&student,sizeof(student));
                }
                file.close();
                newfile.close();
                remove("stu_data");
                rename("temp7","stu_data");
            }

            if(choice==5)
            {
                clrscr();
                cout<<"enter the school code ";
                cin>>scode;
                fstream newfile;
                newfile.open("temp6",ios::binary|ios::out);
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    check=obj.ret_scode();
                    if(check==scode)
                    {
                        obj.getdata(1);
                    }
                    newfile.write((char*)&obj,sizeof(obj));
                }

                newfile.close();
                schoolfile.close();
                remove("school");
                rename("temp6","school");
                int help,flag=0;
                schoolfile.open("school",ios::binary|ios::in|ios::app);
                newfile.open("temp7",ios::binary|ios::out);
                schoolfile.seekg(0,ios::beg);
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    help=schoolfile.tellg();
                    schoolfile.seekg(0,ios::beg);
                    while(schoolfile.read((char*)&obj2,sizeof(obj2)))
                    {
                        if(obj2.ret_scode()==obj.ret_ccode())
                        {
                            strcpy(obj.center,obj2.ret_school());
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        strcpy(obj.center,"N/A");
                        schoolfile.close();
                        schoolfile.open("school",ios::binary|ios::in|ios::app);
                    }
                    flag=0;
                    newfile.write((char*)&obj,sizeof(obj));
                    schoolfile.seekg(help,ios::beg);
                }
                getch();
                newfile.close();
                schoolfile.close();
                remove("school");
                rename("temp7","school");

                newfile.open("temp7",ios::binary|ios::out);
                while(file.read((char*)&student,sizeof(student)))
                {
                    student.assign_again();
                    newfile.write((char*)&student,sizeof(student));
                }
                file.close();
                newfile.close();
                remove("stu_data");
                rename("temp7","stu_data");
            }


            choice=0;
        }//intial choice 3


        if(choice==4)//initial choice for results
        {
            clrscr();
            gotoxy(15,1);
            cout<<"enter choice "<<endl<<endl;
            cout<<endl<<"0: return to main menu "<<endl;
            cout<<endl<<"1: result of a particular child "<<endl;
            cout<<endl<<"2: result of a school "<<endl;
            cout<<endl<<"3: view highest and average marks "<<endl;
            cin>>choice;

            if(choice==1)//result of a particular student
            {
                clrscr();
                cout<<"enter the roll number to be searched ";
                cin>>roll;
                while(file.read((char*)&student,sizeof(student)))
                {
                    check=student.ret_roll();
                    if(check==roll)
                        student.display();
                }
            }

            if(choice==2)//result of a school
            {
                clrscr();
                cout<<"enter the school code ";
                cin>>scode;
                schoolfile.seekg(0,ios::beg);
                result_entry();
                while(schoolfile.read((char*)&obj,sizeof(obj)))
                {
                    if(scode==obj.ret_scode())
                    {
                        gotoxy(15,1);
                        cout<<"school code "<<scode<<"    school "<<obj.ret_school();
                    }
                }
                i=7;
                while(file.read((char*)&student,sizeof(student)))
                {
                    check=student.ret_scode();
                    if(check==scode)
                    {
                        student.display4(i);
                        ++i;
                    }
                }
            }

            if(choice==3)
            {
                clrscr();
                int heng=0,hphy=0,hchem=0,hmath=0,hcomp=0,n=1;
                float aeng=0.0,amath=0.0,aphy=0.0,achem=0.0,acomp=0.0;
                while(file.read((char*)&student,sizeof(student)))
                {
                    if(student.ret_eng()>heng)
                        heng=student.ret_eng();
                    if(student.ret_phy()>hphy)
                        hphy=student.ret_phy();
                    if(student.ret_chem()>hchem)
                        hchem=student.ret_chem();
                    if(student.ret_math()>hmath)
                        hmath=student.ret_math();
                    if(student.ret_comp()>hcomp)
                        hcomp=student.ret_comp();
                    aeng=(aeng*(n-1)+student.ret_eng())/n;
                    aphy=(aphy*(n-1)+student.ret_phy())/n;
                    achem=(achem*(n-1)+student.ret_chem())/n;
                    amath=(amath*(n-1)+student.ret_math())/n;
                    acomp=(acomp*(n-1)+student.ret_comp())/n;
                    ++n;
                }
                cout<<endl<<"         THE HIGHEST AND AVERAGE MARKS ARE ";
                cout<<endl<<endl<<endl;
                cout<<"the highest marks in english are     : "<<heng<<endl<<endl;
                cout<<"the highest marks in physics are     : "<<hphy<<endl<<endl;
                cout<<"the highest marks in chemistry are   : "<<hchem<<endl<<endl;
                cout<<"the highest marks in mathematics are : "<<hmath<<endl<<endl;
                cout<<"the highest marks in computer are    : "<<hcomp<<endl<<endl;
                cout<<"average in english     : "<<aeng<<endl<<endl;
                cout<<"average in physics     : "<<aphy<<endl<<endl;
                cout<<"average in chemistry   : "<<achem<<endl<<endl;
                cout<<"average in mathematics : "<<amath<<endl<<endl;
                cout<<"average in computer    : "<<acomp<<endl<<endl;
            }

            getch();
            choice=0;
        }//for initial choice 4

        file.close();
        schoolfile.close();
    }//the while of the start
    clrscr();
    cout<<"this programme has been programmed by :"<<endl;
    cout<<endl<<endl;
    cout<<"SATYAM AGGARWAL and RUPINDER SINGH"<<endl;
    cout<<"12 A"<<endl;
    cout<<"MATA JAI KAUR PUBLIC SCHOOL "<<endl;
    cout<<"2011 - 2012 "<<endl;
    cout<<endl<<endl<<endl<<"press any key to terminate ";
    getch();
}
